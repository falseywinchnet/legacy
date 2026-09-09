; _interp_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x34500
00434500  81ec94020000             sub       esp, 0x294
00434506  55                       push      ebp
00434507  53                       push      ebx
00434508  56                       push      esi
00434509  57                       push      edi
0043450a  8b8424a8020000           mov       eax, dword ptr [esp + 0x2a8]
00434511  8b8c24ac020000           mov       ecx, dword ptr [esp + 0x2ac]
00434518  8b9424b0020000           mov       edx, dword ptr [esp + 0x2b0]
0043451f  89842484000000           mov       dword ptr [esp + 0x84], eax
00434526  898c2480000000           mov       dword ptr [esp + 0x80], ecx
0043452d  8954247c                 mov       dword ptr [esp + 0x7c], edx
00434531  8b842480000000           mov       eax, dword ptr [esp + 0x80]
00434538  8b08                     mov       ecx, dword ptr [eax]
0043453a  8b2c8d682e0302           mov       ebp, dword ptr [ecx*4 + 0x2032e68]
00434541  83fd1e                   cmp       ebp, 0x1e
00434544  7c10                     jl        0x434556
00434546  83fd23                   cmp       ebp, 0x23
00434549  7f0b                     jg        0x434556
0043454b  b80a000000               mov       eax, 0xa
00434550  89442474                 mov       dword ptr [esp + 0x74], eax
00434554  eb09                     jmp       0x43455f
00434556  b800000000               mov       eax, 0
0043455b  89442474                 mov       dword ptr [esp + 0x74], eax
0043455f  8b44247c                 mov       eax, dword ptr [esp + 0x7c]
00434563  8b08                     mov       ecx, dword ptr [eax]
00434565  8b148d682e0302           mov       edx, dword ptr [ecx*4 + 0x2032e68]
0043456c  83fa1e                   cmp       edx, 0x1e
0043456f  89542470                 mov       dword ptr [esp + 0x70], edx
00434573  7c12                     jl        0x434587
00434575  837c247023               cmp       dword ptr [esp + 0x70], 0x23
0043457a  7f0b                     jg        0x434587
0043457c  b80a000000               mov       eax, 0xa
00434581  8944246c                 mov       dword ptr [esp + 0x6c], eax
00434585  eb09                     jmp       0x434590
00434587  b800000000               mov       eax, 0
0043458c  8944246c                 mov       dword ptr [esp + 0x6c], eax
00434590  8b842480000000           mov       eax, dword ptr [esp + 0x80]
00434597  8d08                     lea       ecx, [eax]
00434599  51                       push      ecx
0043459a  e851ffffff               call      0x4344f0 ; _get_slot_depth_
0043459f  dbbc2458020000           fstp      xword ptr [esp + 0x258]
004345a6  83c404                   add       esp, 4
004345a9  8b44247c                 mov       eax, dword ptr [esp + 0x7c]
004345ad  8d08                     lea       ecx, [eax]
004345af  51                       push      ecx
004345b0  e83bffffff               call      0x4344f0 ; _get_slot_depth_
004345b5  dbbc244c020000           fstp      xword ptr [esp + 0x24c]
004345bc  83c404                   add       esp, 4
004345bf  8b842480000000           mov       eax, dword ptr [esp + 0x80]
004345c6  8b08                     mov       ecx, dword ptr [eax]
004345c8  83c108                   add       ecx, 8
004345cb  898c24a0020000           mov       dword ptr [esp + 0x2a0], ecx
004345d2  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
004345d9  51                       push      ecx
004345da  e831bfffff               call      0x430510 ; _get_dp_from_ft_
004345df  dd9c2440020000           fstp      qword ptr [esp + 0x240]
004345e6  83c404                   add       esp, 4
004345e9  8b842480000000           mov       eax, dword ptr [esp + 0x80]
004345f0  8b08                     mov       ecx, dword ptr [eax]
004345f2  83c10a                   add       ecx, 0xa
004345f5  898c24a0020000           mov       dword ptr [esp + 0x2a0], ecx
004345fc  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
00434603  51                       push      ecx
00434604  e807bfffff               call      0x430510 ; _get_dp_from_ft_
00434609  dd9c2438020000           fstp      qword ptr [esp + 0x238]
00434610  83c404                   add       esp, 4
00434613  8b44247c                 mov       eax, dword ptr [esp + 0x7c]
00434617  8b08                     mov       ecx, dword ptr [eax]
00434619  83c108                   add       ecx, 8
0043461c  898c24a0020000           mov       dword ptr [esp + 0x2a0], ecx
00434623  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
0043462a  51                       push      ecx
0043462b  e8e0beffff               call      0x430510 ; _get_dp_from_ft_
00434630  dd9c2430020000           fstp      qword ptr [esp + 0x230]
00434637  83c404                   add       esp, 4
0043463a  8b44247c                 mov       eax, dword ptr [esp + 0x7c]
0043463e  8b08                     mov       ecx, dword ptr [eax]
00434640  83c10a                   add       ecx, 0xa
00434643  898c24a0020000           mov       dword ptr [esp + 0x2a0], ecx
0043464a  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
00434651  51                       push      ecx
00434652  e8b9beffff               call      0x430510 ; _get_dp_from_ft_
00434657  dd9c2428020000           fstp      qword ptr [esp + 0x228]
0043465e  83c404                   add       esp, 4
00434661  89e8                     mov       eax, ebp
00434663  2b442474                 sub       eax, dword ptr [esp + 0x74]
00434667  3d14000000               cmp       eax, 0x14
0043466c  89442468                 mov       dword ptr [esp + 0x68], eax
00434670  7c07                     jl        0x434679
00434672  837c246819               cmp       dword ptr [esp + 0x68], 0x19
00434677  7e47                     jle       0x4346c0
00434679  8b842484000000           mov       eax, dword ptr [esp + 0x84]
00434680  8b08                     mov       ecx, dword ptr [eax]
00434682  8d05d8e95200             lea       eax, [0x52e9d8] ; bits=09020000, f32=7.300764999132297e-43
00434688  898c24a0020000           mov       dword ptr [esp + 0x2a0], ecx
0043468f  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
00434696  894808                   mov       dword ptr [eax + 8], ecx
00434699  89ac249c020000           mov       dword ptr [esp + 0x29c], ebp
004346a0  8d8c249c020000           lea       ecx, [esp + 0x29c]
004346a7  894828                   mov       dword ptr [eax + 0x28], ecx
004346aa  50                       push      eax
004346ab  e810850800               call      0x4bcbc0 ; _jwe_isfm
004346b0  83c404                   add       esp, 4
004346b3  6844e95200               push      0x52e944
004346b8  e8938d0800               call      0x4bd450 ; _jwe_xstp
004346bd  83c404                   add       esp, 4
004346c0  8b442470                 mov       eax, dword ptr [esp + 0x70]
004346c4  2b44246c                 sub       eax, dword ptr [esp + 0x6c]
004346c8  3d14000000               cmp       eax, 0x14
004346cd  89442464                 mov       dword ptr [esp + 0x64], eax
004346d1  7c07                     jl        0x4346da
004346d3  837c246419               cmp       dword ptr [esp + 0x64], 0x19
004346d8  7e4b                     jle       0x434725
004346da  8b842484000000           mov       eax, dword ptr [esp + 0x84]
004346e1  8b08                     mov       ecx, dword ptr [eax]
004346e3  8d05ace95200             lea       eax, [0x52e9ac] ; bits=09020000, f32=7.300764999132297e-43
004346e9  898c24a0020000           mov       dword ptr [esp + 0x2a0], ecx
004346f0  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
004346f7  894808                   mov       dword ptr [eax + 8], ecx
004346fa  8b4c2470                 mov       ecx, dword ptr [esp + 0x70]
004346fe  898c249c020000           mov       dword ptr [esp + 0x29c], ecx
00434705  8d8c249c020000           lea       ecx, [esp + 0x29c]
0043470c  894828                   mov       dword ptr [eax + 0x28], ecx
0043470f  50                       push      eax
00434710  e8ab840800               call      0x4bcbc0 ; _jwe_isfm
00434715  83c404                   add       esp, 4
00434718  6838e95200               push      0x52e938
0043471d  e82e8d0800               call      0x4bd450 ; _jwe_xstp
00434722  83c404                   add       esp, 4
00434725  89e8                     mov       eax, ebp
00434727  83e813                   sub       eax, 0x13
0043472a  8b4c2474                 mov       ecx, dword ptr [esp + 0x74]
0043472e  29c8                     sub       eax, ecx
00434730  8b542470                 mov       edx, dword ptr [esp + 0x70]
00434734  83ea13                   sub       edx, 0x13
00434737  89d5                     mov       ebp, edx
00434739  2b6c246c                 sub       ebp, dword ptr [esp + 0x6c]
0043473d  8d5c6d00                 lea       ebx, [ebp + ebp*2]
00434741  89da                     mov       edx, ebx
00434743  01da                     add       edx, ebx
00434745  01c2                     add       edx, eax
00434747  89d5                     mov       ebp, edx
00434749  8b04ad70eb5200           mov       eax, dword ptr [ebp*4 + 0x52eb70]
00434750  83f900                   cmp       ecx, 0
00434753  89442460                 mov       dword ptr [esp + 0x60], eax
00434757  7e28                     jle       0x434781
00434759  837c246c00               cmp       dword ptr [esp + 0x6c], 0
0043475e  7e21                     jle       0x434781
00434760  b80a000000               mov       eax, 0xa
00434765  8b4c2460                 mov       ecx, dword ptr [esp + 0x60]
00434769  83c10a                   add       ecx, 0xa
0043476c  8b148d1ccf3b05           mov       edx, dword ptr [ecx*4 + 0x53bcf1c]
00434773  8944245c                 mov       dword ptr [esp + 0x5c], eax
00434777  894c2460                 mov       dword ptr [esp + 0x60], ecx
0043477b  89542458                 mov       dword ptr [esp + 0x58], edx
0043477f  eb18                     jmp       0x434799
00434781  b800000000               mov       eax, 0
00434786  8b4c2460                 mov       ecx, dword ptr [esp + 0x60]
0043478a  8b148d1ccf3b05           mov       edx, dword ptr [ecx*4 + 0x53bcf1c]
00434791  8944245c                 mov       dword ptr [esp + 0x5c], eax
00434795  89542458                 mov       dword ptr [esp + 0x58], edx
00434799  8b842480000000           mov       eax, dword ptr [esp + 0x80]
004347a0  8b08                     mov       ecx, dword ptr [eax]
004347a2  8b54247c                 mov       edx, dword ptr [esp + 0x7c]
004347a6  d9048d782e0302           fld       dword ptr [ecx*4 + 0x2032e78]
004347ad  8b1a                     mov       ebx, dword ptr [edx]
004347af  d9049d782e0302           fld       dword ptr [ebx*4 + 0x2032e78]
004347b6  d8148d782e0302           fcom      dword ptr [ecx*4 + 0x2032e78]
004347bd  dbbc2418020000           fstp      xword ptr [esp + 0x218]
004347c4  dfe0                     fnstsw    ax
004347c6  66a90041                 test      ax, 0x4100
004347ca  7509                     jne       0x4347d5
004347cc  dbbc2418020000           fstp      xword ptr [esp + 0x218]
004347d3  eb02                     jmp       0x4347d7
004347d5  ddd8                     fstp      st(0)
004347d7  8b8424bc020000           mov       eax, dword ptr [esp + 0x2bc]
004347de  8b28                     mov       ebp, dword ptr [eax]
004347e0  0faf6c2458               imul      ebp, dword ptr [esp + 0x58]
004347e5  89e9                     mov       ecx, ebp
004347e7  83c120                   add       ecx, 0x20
004347ea  8b8424c4020000           mov       eax, dword ptr [esp + 0x2c4]
004347f1  8b28                     mov       ebp, dword ptr [eax]
004347f3  0fafe9                   imul      ebp, ecx
004347f6  8b8424ec020000           mov       eax, dword ptr [esp + 0x2ec]
004347fd  8b08                     mov       ecx, dword ptr [eax]
004347ff  01e9                     add       ecx, ebp
00434801  8b9424c8020000           mov       edx, dword ptr [esp + 0x2c8]
00434808  8b12                     mov       edx, dword ptr [edx]
0043480a  39d1                     cmp       ecx, edx
0043480c  89442454                 mov       dword ptr [esp + 0x54], eax
00434810  7c1e                     jl        0x434830
00434812  8b8424e8020000           mov       eax, dword ptr [esp + 0x2e8]
00434819  8d00                     lea       eax, [eax]
0043481b  50                       push      eax
0043481c  8b442458                 mov       eax, dword ptr [esp + 0x58]
00434820  8d08                     lea       ecx, [eax]
00434822  51                       push      ecx
00434823  6864e85200               push      0x52e864
00434828  e8f3130000               call      0x435c20 ; _kil_
0043482d  83c40c                   add       esp, 0xc
00434830  8b8424bc020000           mov       eax, dword ptr [esp + 0x2bc]
00434837  8b28                     mov       ebp, dword ptr [eax]
00434839  0faf6c2458               imul      ebp, dword ptr [esp + 0x58]
0043483e  89e9                     mov       ecx, ebp
00434840  83c120                   add       ecx, 0x20
00434843  894c2450                 mov       dword ptr [esp + 0x50], ecx
00434847  8b8424c4020000           mov       eax, dword ptr [esp + 0x2c4]
0043484e  8b08                     mov       ecx, dword ptr [eax]
00434850  89c8                     mov       eax, ecx
00434852  3d00000000               cmp       eax, 0
00434857  8944244c                 mov       dword ptr [esp + 0x4c], eax
0043485b  894c2448                 mov       dword ptr [esp + 0x48], ecx
0043485f  7e6f                     jle       0x4348d0
00434861  b801000000               mov       eax, 1
00434866  8b8c24ec020000           mov       ecx, dword ptr [esp + 0x2ec]
0043486d  8b29                     mov       ebp, dword ptr [ecx]
0043486f  837c244c02               cmp       dword ptr [esp + 0x4c], 2
00434874  89442444                 mov       dword ptr [esp + 0x44], eax
00434878  7c36                     jl        0x4348b0
0043487a  8d0550ea5a00             lea       eax, [0x5aea50]
00434880  8b542444                 mov       edx, dword ptr [esp + 0x44]
00434884  89ac907cffffff           mov       dword ptr [eax + edx*4 - 0x84], ebp
0043488b  8b5c2450                 mov       ebx, dword ptr [esp + 0x50]
0043488f  01dd                     add       ebp, ebx
00434891  896c9080                 mov       dword ptr [eax + edx*4 - 0x80], ebp
00434895  01dd                     add       ebp, ebx
00434897  8b44244c                 mov       eax, dword ptr [esp + 0x4c]
0043489b  83e802                   sub       eax, 2
0043489e  83c202                   add       edx, 2
004348a1  3d02000000               cmp       eax, 2
004348a6  8944244c                 mov       dword ptr [esp + 0x4c], eax
004348aa  89542444                 mov       dword ptr [esp + 0x44], edx
004348ae  7dca                     jge       0x43487a
004348b0  8b44244c                 mov       eax, dword ptr [esp + 0x4c]
004348b4  85c0                     test      eax, eax
004348b6  740f                     je        0x4348c7
004348b8  8b4c2444                 mov       ecx, dword ptr [esp + 0x44]
004348bc  892c8dcce95a00           mov       dword ptr [ecx*4 + 0x5ae9cc], ebp
004348c3  036c2450                 add       ebp, dword ptr [esp + 0x50]
004348c7  8b8424ec020000           mov       eax, dword ptr [esp + 0x2ec]
004348ce  8928                     mov       dword ptr [eax], ebp
004348d0  8b442448                 mov       eax, dword ptr [esp + 0x48]
004348d4  89c5                     mov       ebp, eax
004348d6  3d00000000               cmp       eax, 0
004348db  0f8e9a010000             jle       0x434a7b
004348e1  b801000000               mov       eax, 1
004348e6  8b8c24b4020000           mov       ecx, dword ptr [esp + 0x2b4]
004348ed  d901                     fld       dword ptr [ecx]
004348ef  89442444                 mov       dword ptr [esp + 0x44], eax
004348f3  8b4c2444                 mov       ecx, dword ptr [esp + 0x44]
004348f7  8b8424cc020000           mov       eax, dword ptr [esp + 0x2cc]
004348fe  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
00434902  dbf1                     fcomi     st(1)
00434904  d9c9                     fxch      st(1)
00434906  0f8a19000000             jp        0x434925
0043490c  7617                     jbe       0x434925
0043490e  8b8424b8020000           mov       eax, dword ptr [esp + 0x2b8]
00434915  d900                     fld       dword ptr [eax]
00434917  dff2                     fcompi    st(2)
00434919  0f8a06000000             jp        0x434925
0043491f  0f873f010000             ja        0x434a64
00434925  8b8424b8020000           mov       eax, dword ptr [esp + 0x2b8]
0043492c  d900                     fld       dword ptr [eax]
0043492e  dbf2                     fcomi     st(2)
00434930  0f8a14000000             jp        0x43494a
00434936  7312                     jae       0x43494a
00434938  d9ca                     fxch      st(2)
0043493a  dbf1                     fcomi     st(1)
0043493c  d9ca                     fxch      st(2)
0043493e  0f8a06000000             jp        0x43494a
00434944  0f821e010000             jb        0x434a68
0043494a  d9c9                     fxch      st(1)
0043494c  dbbc2484020000           fstp      xword ptr [esp + 0x284]
00434953  8b8424e8020000           mov       eax, dword ptr [esp + 0x2e8]
0043495a  c70001000000             mov       dword ptr [eax], 1
00434960  8b842484000000           mov       eax, dword ptr [esp + 0x84]
00434967  8b18                     mov       ebx, dword ptr [eax]
00434969  8b8c24dc020000           mov       ecx, dword ptr [esp + 0x2dc]
00434970  d901                     fld       dword ptr [ecx]
00434972  dbac2484020000           fld       xword ptr [esp + 0x284]
00434979  d831                     fdiv      dword ptr [ecx]
0043497b  dbbc240c020000           fstp      xword ptr [esp + 0x20c]
00434982  dcfa                     fdiv      st(2), st(0)
00434984  d9ca                     fxch      st(2)
00434986  dbbc2400020000           fstp      xword ptr [esp + 0x200]
0043498d  def1                     fdivrp    st(1)
0043498f  8b8c2480000000           mov       ecx, dword ptr [esp + 0x80]
00434996  dbbc24f4010000           fstp      xword ptr [esp + 0x1f4]
0043499d  8d11                     lea       edx, [ecx]
0043499f  52                       push      edx
004349a0  e83bfbffff               call      0x4344e0 ; _gettbn_
004349a5  83c404                   add       esp, 4
004349a8  898424a0020000           mov       dword ptr [esp + 0x2a0], eax
004349af  8d8424a0020000           lea       eax, [esp + 0x2a0]
004349b6  50                       push      eax
004349b7  6a10                     push      0x10
004349b9  68f8ea5200               push      0x52eaf8
004349be  e8ad690600               call      0x49b370 ; _get_tabid_
004349c3  83c40c                   add       esp, 0xc
004349c6  8b44247c                 mov       eax, dword ptr [esp + 0x7c]
004349ca  8d08                     lea       ecx, [eax]
004349cc  51                       push      ecx
004349cd  e80efbffff               call      0x4344e0 ; _gettbn_
004349d2  83c404                   add       esp, 4
004349d5  898424a0020000           mov       dword ptr [esp + 0x2a0], eax
004349dc  8d8424a0020000           lea       eax, [esp + 0x2a0]
004349e3  50                       push      eax
004349e4  6a10                     push      0x10
004349e6  6808eb5200               push      0x52eb08
004349eb  e880690600               call      0x49b370 ; _get_tabid_
004349f0  83c40c                   add       esp, 0xc
004349f3  8d0550e95200             lea       eax, [0x52e950] ; bits=09020000, f32=7.300764999132297e-43
004349f9  899c24a0020000           mov       dword ptr [esp + 0x2a0], ebx
00434a00  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
00434a07  894808                   mov       dword ptr [eax + 8], ecx
00434a0a  dbac240c020000           fld       xword ptr [esp + 0x20c]
00434a11  d99c2498020000           fstp      dword ptr [esp + 0x298]
00434a18  8d8c2498020000           lea       ecx, [esp + 0x298]
00434a1f  894828                   mov       dword ptr [eax + 0x28], ecx
00434a22  dbac2400020000           fld       xword ptr [esp + 0x200]
00434a29  d99c2494020000           fstp      dword ptr [esp + 0x294]
00434a30  8d8c2494020000           lea       ecx, [esp + 0x294]
00434a37  894834                   mov       dword ptr [eax + 0x34], ecx
00434a3a  dbac24f4010000           fld       xword ptr [esp + 0x1f4]
00434a41  d99c2490020000           fstp      dword ptr [esp + 0x290]
00434a48  8d8c2490020000           lea       ecx, [esp + 0x290]
00434a4f  894840                   mov       dword ptr [eax + 0x40], ecx
00434a52  50                       push      eax
00434a53  e868810800               call      0x4bcbc0 ; _jwe_isfm
00434a58  dbac2488020000           fld       xword ptr [esp + 0x288]
00434a5f  83c404                   add       esp, 4
00434a62  eb08                     jmp       0x434a6c
00434a64  ddd9                     fstp      st(1)
00434a66  eb04                     jmp       0x434a6c
00434a68  ddd8                     fstp      st(0)
00434a6a  ddd9                     fstp      st(1)
00434a6c  ff442444                 inc       dword ptr [esp + 0x44]
00434a70  83ed01                   sub       ebp, 1
00434a73  0f857afeffff             jne       0x4348f3
00434a79  ddd8                     fstp      st(0)
00434a7b  8b8424b8020000           mov       eax, dword ptr [esp + 0x2b8]
00434a82  8b8c24b4020000           mov       ecx, dword ptr [esp + 0x2b4]
00434a89  d901                     fld       dword ptr [ecx]
00434a8b  d9c0                     fld       st(0)
00434a8d  d828                     fsubr     dword ptr [eax]
00434a8f  dbbc24e8010000           fstp      xword ptr [esp + 0x1e8]
00434a96  dbbc24dc010000           fstp      xword ptr [esp + 0x1dc]
00434a9d  8b8424c4020000           mov       eax, dword ptr [esp + 0x2c4]
00434aa4  8b08                     mov       ecx, dword ptr [eax]
00434aa6  83f900                   cmp       ecx, 0
00434aa9  894c2438                 mov       dword ptr [esp + 0x38], ecx
00434aad  0f8e30040000             jle       0x434ee3
00434ab3  be01000000               mov       esi, 1
00434ab8  8b442450                 mov       eax, dword ptr [esp + 0x50]
00434abc  2b442458                 sub       eax, dword ptr [esp + 0x58]
00434ac0  89442434                 mov       dword ptr [esp + 0x34], eax
00434ac4  8b8424dc020000           mov       eax, dword ptr [esp + 0x2dc]
00434acb  d9e8                     fld1
00434acd  d9c0                     fld       st(0)
00434acf  d830                     fdiv      dword ptr [eax]
00434ad1  dbbc24d0010000           fstp      xword ptr [esp + 0x1d0]
00434ad8  dbac24dc010000           fld       xword ptr [esp + 0x1dc]
00434adf  dbbc24c4010000           fstp      xword ptr [esp + 0x1c4]
00434ae6  dbac24e8010000           fld       xword ptr [esp + 0x1e8]
00434aed  def9                     fdivp     st(1)
00434aef  dbbc24b8010000           fstp      xword ptr [esp + 0x1b8]
00434af6  dbac2448020000           fld       xword ptr [esp + 0x248]
00434afd  dbac2454020000           fld       xword ptr [esp + 0x254]
00434b04  dee9                     fsubp     st(1)
00434b06  dbbc24ac010000           fstp      xword ptr [esp + 0x1ac]
00434b0d  dd84243c020000           fld       qword ptr [esp + 0x23c]
00434b14  dcac242c020000           fsubr     qword ptr [esp + 0x22c]
00434b1b  dd9c24a4010000           fstp      qword ptr [esp + 0x1a4]
00434b22  dd842434020000           fld       qword ptr [esp + 0x234]
00434b29  dcac2424020000           fsubr     qword ptr [esp + 0x224]
00434b30  dd9c249c010000           fstp      qword ptr [esp + 0x19c]
00434b37  dbac2418020000           fld       xword ptr [esp + 0x218]
00434b3e  dbac2454020000           fld       xword ptr [esp + 0x254]
00434b45  dd84243c020000           fld       qword ptr [esp + 0x23c]
00434b4c  dd842434020000           fld       qword ptr [esp + 0x234]
00434b53  dbbc2460020000           fstp      xword ptr [esp + 0x260]
00434b5a  dbbc246c020000           fstp      xword ptr [esp + 0x26c]
00434b61  dbbc2478020000           fstp      xword ptr [esp + 0x278]
00434b68  dbbc2484020000           fstp      xword ptr [esp + 0x284]
00434b6f  8b1cb5cce95a00           mov       ebx, dword ptr [esi*4 + 0x5ae9cc]
00434b76  8b442434                 mov       eax, dword ptr [esp + 0x34]
00434b7a  8d0c18                   lea       ecx, [eax + ebx]
00434b7d  890c9d602e0302           mov       dword ptr [ebx*4 + 0x2032e60], ecx
00434b84  8bbc24d4020000           mov       edi, dword ptr [esp + 0x2d4]
00434b8b  8b4cb7fc                 mov       ecx, dword ptr [edi + esi*4 - 4]
00434b8f  890c9d642e0302           mov       dword ptr [ebx*4 + 0x2032e64], ecx
00434b96  8b4c2460                 mov       ecx, dword ptr [esp + 0x60]
00434b9a  890c9d682e0302           mov       dword ptr [ebx*4 + 0x2032e68], ecx
00434ba1  8d6b20                   lea       ebp, [ebx + 0x20]
00434ba4  892c9d6c2e0302           mov       dword ptr [ebx*4 + 0x2032e6c], ebp
00434bab  8b8424cc020000           mov       eax, dword ptr [esp + 0x2cc]
00434bb2  dbac24d0010000           fld       xword ptr [esp + 0x1d0]
00434bb9  d84cb0fc                 fmul      dword ptr [eax + esi*4 - 4]
00434bbd  d91c9d702e0302           fstp      dword ptr [ebx*4 + 0x2032e70]
00434bc4  897c2430                 mov       dword ptr [esp + 0x30], edi
00434bc8  8bbc24d0020000           mov       edi, dword ptr [esp + 0x2d0]
00434bcf  8b7cb7fc                 mov       edi, dword ptr [edi + esi*4 - 4]
00434bd3  893c9d742e0302           mov       dword ptr [ebx*4 + 0x2032e74], edi
00434bda  dbac2484020000           fld       xword ptr [esp + 0x284]
00434be1  d91c9d782e0302           fstp      dword ptr [ebx*4 + 0x2032e78]
00434be8  dbac24c4010000           fld       xword ptr [esp + 0x1c4]
00434bef  d86cb0fc                 fsubr     dword ptr [eax + esi*4 - 4]
00434bf3  dbac24b8010000           fld       xword ptr [esp + 0x1b8]
00434bfa  dec9                     fmulp     st(1)
00434bfc  dbac24ac010000           fld       xword ptr [esp + 0x1ac]
00434c03  d8c9                     fmul      st(1)
00434c05  dbac2478020000           fld       xword ptr [esp + 0x278]
00434c0c  dec1                     faddp     st(1)
00434c0e  d91c9d7c2e0302           fstp      dword ptr [ebx*4 + 0x2032e7c]
00434c15  d9c0                     fld       st(0)
00434c17  dc8c24a4010000           fmul      qword ptr [esp + 0x1a4]
00434c1e  dbac246c020000           fld       xword ptr [esp + 0x26c]
00434c25  dec1                     faddp     st(1)
00434c27  dd1d08ea5200             fstp      qword ptr [0x52ea08] ; bits=0000000000000000, f64=0.0
00434c2d  dc8c249c010000           fmul      qword ptr [esp + 0x19c]
00434c34  dbac2460020000           fld       xword ptr [esp + 0x260]
00434c3b  dec1                     faddp     st(1)
00434c3d  dd1d10ea5200             fstp      qword ptr [0x52ea10] ; bits=0000000000000000, f64=0.0
00434c43  8d4308                   lea       eax, [ebx + 8]
00434c46  898424a0020000           mov       dword ptr [esp + 0x2a0], eax
00434c4d  6808ea5200               push      0x52ea08
00434c52  8d8424a4020000           lea       eax, [esp + 0x2a4]
00434c59  50                       push      eax
00434c5a  e871b8ffff               call      0x4304d0 ; _put_dp_in_ft_
00434c5f  83c408                   add       esp, 8
00434c62  8d430a                   lea       eax, [ebx + 0xa]
00434c65  898424a0020000           mov       dword ptr [esp + 0x2a0], eax
00434c6c  6810ea5200               push      0x52ea10
00434c71  8d8424a4020000           lea       eax, [esp + 0x2a4]
00434c78  50                       push      eax
00434c79  e852b8ffff               call      0x4304d0 ; _put_dp_in_ft_
00434c7e  83c408                   add       esp, 8
00434c81  8d430c                   lea       eax, [ebx + 0xc]
00434c84  898424a0020000           mov       dword ptr [esp + 0x2a0], eax
00434c8b  6a10                     push      0x10
00434c8d  6828e95200               push      0x52e928
00434c92  8d8424a8020000           lea       eax, [esp + 0x2a8]
00434c99  50                       push      eax
00434c9a  e811b5ffff               call      0x4301b0 ; _put_string_in_ft_
00434c9f  83c40c                   add       esp, 0xc
00434ca2  8b7c2430                 mov       edi, dword ptr [esp + 0x30]
00434ca6  8d7cb7fc                 lea       edi, [edi + esi*4 - 4]
00434caa  57                       push      edi
00434cab  6a10                     push      0x10
00434cad  6818eb5200               push      0x52eb18
00434cb2  e8b9660600               call      0x49b370 ; _get_tabid_
00434cb7  83c40c                   add       esp, 0xc
00434cba  8d05e8ea5200             lea       eax, [0x52eae8] ; bits=00000000, f32=0.0
00434cc0  8d0d18eb5200             lea       ecx, [0x52eb18] ; bits=00000000, f32=0.0
00434cc6  8a11                     mov       dl, byte ptr [ecx]
00434cc8  8810                     mov       byte ptr [eax], dl
00434cca  8a5101                   mov       dl, byte ptr [ecx + 1]
00434ccd  885001                   mov       byte ptr [eax + 1], dl
00434cd0  8a5102                   mov       dl, byte ptr [ecx + 2]
00434cd3  885002                   mov       byte ptr [eax + 2], dl
00434cd6  8a5103                   mov       dl, byte ptr [ecx + 3]
00434cd9  885003                   mov       byte ptr [eax + 3], dl
00434cdc  8a5104                   mov       dl, byte ptr [ecx + 4]
00434cdf  885004                   mov       byte ptr [eax + 4], dl
00434ce2  8a5105                   mov       dl, byte ptr [ecx + 5]
00434ce5  885005                   mov       byte ptr [eax + 5], dl
00434ce8  8a5106                   mov       dl, byte ptr [ecx + 6]
00434ceb  885006                   mov       byte ptr [eax + 6], dl
00434cee  8a5107                   mov       dl, byte ptr [ecx + 7]
00434cf1  885007                   mov       byte ptr [eax + 7], dl
00434cf4  8a5108                   mov       dl, byte ptr [ecx + 8]
00434cf7  885008                   mov       byte ptr [eax + 8], dl
00434cfa  8a5109                   mov       dl, byte ptr [ecx + 9]
00434cfd  885009                   mov       byte ptr [eax + 9], dl
00434d00  8a510a                   mov       dl, byte ptr [ecx + 0xa]
00434d03  88500a                   mov       byte ptr [eax + 0xa], dl
00434d06  8a510b                   mov       dl, byte ptr [ecx + 0xb]
00434d09  88500b                   mov       byte ptr [eax + 0xb], dl
00434d0c  8a510c                   mov       dl, byte ptr [ecx + 0xc]
00434d0f  88500c                   mov       byte ptr [eax + 0xc], dl
00434d12  8a510d                   mov       dl, byte ptr [ecx + 0xd]
00434d15  88500d                   mov       byte ptr [eax + 0xd], dl
00434d18  8a510e                   mov       dl, byte ptr [ecx + 0xe]
00434d1b  88500e                   mov       byte ptr [eax + 0xe], dl
00434d1e  8a510f                   mov       dl, byte ptr [ecx + 0xf]
00434d21  88500f                   mov       byte ptr [eax + 0xf], dl
00434d24  8d4310                   lea       eax, [ebx + 0x10]
00434d27  898424a0020000           mov       dword ptr [esp + 0x2a0], eax
00434d2e  6a10                     push      0x10
00434d30  68e8ea5200               push      0x52eae8
00434d35  8d8424a8020000           lea       eax, [esp + 0x2a8]
00434d3c  50                       push      eax
00434d3d  e86eb4ffff               call      0x4301b0 ; _put_string_in_ft_
00434d42  dbac2490020000           fld       xword ptr [esp + 0x290]
00434d49  dbac2484020000           fld       xword ptr [esp + 0x284]
00434d50  dbac2478020000           fld       xword ptr [esp + 0x278]
00434d57  dbac246c020000           fld       xword ptr [esp + 0x26c]
00434d5e  83c40c                   add       esp, 0xc
00434d61  c7049db02e030201000000   mov       dword ptr [ebx*4 + 0x2032eb0], 1
00434d6c  8b442460                 mov       eax, dword ptr [esp + 0x60]
00434d70  3d19000000               cmp       eax, 0x19
00434d75  7f0d                     jg        0x434d84
00434d77  c7049db42e030200000000   mov       dword ptr [ebx*4 + 0x2032eb4], 0
00434d82  eb12                     jmp       0x434d96
00434d84  8b442460                 mov       eax, dword ptr [esp + 0x60]
00434d88  8b0c85f4ce3b05           mov       ecx, dword ptr [eax*4 + 0x53bcef4]
00434d8f  890c9db42e0302           mov       dword ptr [ebx*4 + 0x2032eb4], ecx
00434d96  8b842480000000           mov       eax, dword ptr [esp + 0x80]
00434d9d  8b08                     mov       ecx, dword ptr [eax]
00434d9f  8d5116                   lea       edx, [ecx + 0x16]
00434da2  8d7b16                   lea       edi, [ebx + 0x16]
00434da5  8b0495602e0302           mov       eax, dword ptr [edx*4 + 0x2032e60]
00434dac  8904bd602e0302           mov       dword ptr [edi*4 + 0x2032e60], eax
00434db3  8b0495642e0302           mov       eax, dword ptr [edx*4 + 0x2032e64]
00434dba  8904bd642e0302           mov       dword ptr [edi*4 + 0x2032e64], eax
00434dc1  8b0495682e0302           mov       eax, dword ptr [edx*4 + 0x2032e68]
00434dc8  8904bd682e0302           mov       dword ptr [edi*4 + 0x2032e68], eax
00434dcf  8b04956c2e0302           mov       eax, dword ptr [edx*4 + 0x2032e6c]
00434dd6  8904bd6c2e0302           mov       dword ptr [edi*4 + 0x2032e6c], eax
00434ddd  8b0495702e0302           mov       eax, dword ptr [edx*4 + 0x2032e70]
00434de4  8904bd702e0302           mov       dword ptr [edi*4 + 0x2032e70], eax
00434deb  8b0495742e0302           mov       eax, dword ptr [edx*4 + 0x2032e74]
00434df2  8904bd742e0302           mov       dword ptr [edi*4 + 0x2032e74], eax
00434df9  8b0495782e0302           mov       eax, dword ptr [edx*4 + 0x2032e78]
00434e00  8904bd782e0302           mov       dword ptr [edi*4 + 0x2032e78], eax
00434e07  8b14957c2e0302           mov       edx, dword ptr [edx*4 + 0x2032e7c]
00434e0e  8914bd7c2e0302           mov       dword ptr [edi*4 + 0x2032e7c], edx
00434e15  8b048dd82e0302           mov       eax, dword ptr [ecx*4 + 0x2032ed8]
00434e1c  89049dd82e0302           mov       dword ptr [ebx*4 + 0x2032ed8], eax
00434e23  8b0c8ddc2e0302           mov       ecx, dword ptr [ecx*4 + 0x2032edc]
00434e2a  890c9ddc2e0302           mov       dword ptr [ebx*4 + 0x2032edc], ecx
00434e31  8b8424d4020000           mov       eax, dword ptr [esp + 0x2d4]
00434e38  8b44b0fc                 mov       eax, dword ptr [eax + esi*4 - 4]
00434e3c  890518ea5200             mov       dword ptr [0x52ea18], eax ; bits=00000000, f32=0.0
00434e42  833c858ca31c0500         cmp       dword ptr [eax*4 + 0x51ca38c], 0
00434e4a  7454                     je        0x434ea0
00434e4c  dbbc2460020000           fstp      xword ptr [esp + 0x260]
00434e53  dbbc246c020000           fstp      xword ptr [esp + 0x26c]
00434e5a  dbbc2478020000           fstp      xword ptr [esp + 0x278]
00434e61  dbbc2484020000           fstp      xword ptr [esp + 0x284]
00434e68  8b8424e8020000           mov       eax, dword ptr [esp + 0x2e8]
00434e6f  8d00                     lea       eax, [eax]
00434e71  50                       push      eax
00434e72  6818ea5200               push      0x52ea18
00434e77  68f8e85200               push      0x52e8f8
00434e7c  e89f0d0000               call      0x435c20 ; _kil_
00434e81  dbac2490020000           fld       xword ptr [esp + 0x290]
00434e88  dbac2484020000           fld       xword ptr [esp + 0x284]
00434e8f  dbac2478020000           fld       xword ptr [esp + 0x278]
00434e96  dbac246c020000           fld       xword ptr [esp + 0x26c]
00434e9d  83c40c                   add       esp, 0xc
00434ea0  8b8424d4020000           mov       eax, dword ptr [esp + 0x2d4]
00434ea7  8b44b0fc                 mov       eax, dword ptr [eax + esi*4 - 4]
00434eab  891c858ca31c05           mov       dword ptr [eax*4 + 0x51ca38c], ebx
00434eb2  8b8424d8020000           mov       eax, dword ptr [esp + 0x2d8]
00434eb9  8b44b0fc                 mov       eax, dword ptr [eax + esi*4 - 4]
00434ebd  8b8c24f0020000           mov       ecx, dword ptr [esp + 0x2f0]
00434ec4  895c81fc                 mov       dword ptr [ecx + eax*4 - 4], ebx
00434ec8  892cb5cce95a00           mov       dword ptr [esi*4 + 0x5ae9cc], ebp
00434ecf  46                       inc       esi
00434ed0  836c243801               sub       dword ptr [esp + 0x38], 1
00434ed5  0f8578fcffff             jne       0x434b53
00434edb  ddd8                     fstp      st(0)
00434edd  ddd8                     fstp      st(0)
00434edf  ddd8                     fstp      st(0)
00434ee1  ddd8                     fstp      st(0)
00434ee3  8b8424bc020000           mov       eax, dword ptr [esp + 0x2bc]
00434eea  8b08                     mov       ecx, dword ptr [eax]
00434eec  83f900                   cmp       ecx, 0
00434eef  894c2428                 mov       dword ptr [esp + 0x28], ecx
00434ef3  0f8e160d0000             jle       0x435c0f
00434ef9  b801000000               mov       eax, 1
00434efe  8b4c2468                 mov       ecx, dword ptr [esp + 0x68]
00434f02  83e913                   sub       ecx, 0x13
00434f05  894c2424                 mov       dword ptr [esp + 0x24], ecx
00434f09  8b4c2464                 mov       ecx, dword ptr [esp + 0x64]
00434f0d  83e913                   sub       ecx, 0x13
00434f10  894c2420                 mov       dword ptr [esp + 0x20], ecx
00434f14  8b4c2460                 mov       ecx, dword ptr [esp + 0x60]
00434f18  89ca                     mov       edx, ecx
00434f1a  2b54245c                 sub       edx, dword ptr [esp + 0x5c]
00434f1e  89d7                     mov       edi, edx
00434f20  8d51e2                   lea       edx, [ecx - 0x1e]
00434f23  89442444                 mov       dword ptr [esp + 0x44], eax
00434f27  8954241c                 mov       dword ptr [esp + 0x1c], edx
00434f2b  8b4c2444                 mov       ecx, dword ptr [esp + 0x44]
00434f2f  8b8424e0020000           mov       eax, dword ptr [esp + 0x2e0]
00434f36  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
00434f3a  8905acea5200             mov       dword ptr [0x52eaac], eax ; bits=00000000, f32=0.0
00434f40  8b8424e4020000           mov       eax, dword ptr [esp + 0x2e4]
00434f47  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
00434f4b  8905b0ea5200             mov       dword ptr [0x52eab0], eax ; bits=00000000, f32=0.0
00434f51  837c242407               cmp       dword ptr [esp + 0x24], 7
00434f56  730d                     jae       0x434f65
00434f58  8b442424                 mov       eax, dword ptr [esp + 0x24]
00434f5c  8b0c85d4ed5200           mov       ecx, dword ptr [eax*4 + 0x52edd4]
00434f63  ffe1                     jmp       ecx
00434f65  684cea5200               push      0x52ea4c
00434f6a  683cea5200               push      0x52ea3c
00434f6f  6854ea5200               push      0x52ea54
00434f74  687cea5200               push      0x52ea7c
00434f79  686cea5200               push      0x52ea6c
00434f7e  68a4ea5200               push      0x52eaa4
00434f83  6824ea5200               push      0x52ea24
00434f88  68acea5200               push      0x52eaac
00434f8d  8b8424a0000000           mov       eax, dword ptr [esp + 0xa0]
00434f94  8d08                     lea       ecx, [eax]
00434f96  51                       push      ecx
00434f97  e854580000               call      0x43a7f0 ; _xlkt20_
00434f9c  83c424                   add       esp, 0x24
00434f9f  e9a1010000               jmp       0x435145
00434fa4  684cea5200               push      0x52ea4c
00434fa9  683cea5200               push      0x52ea3c
00434fae  6854ea5200               push      0x52ea54
00434fb3  687cea5200               push      0x52ea7c
00434fb8  68b8ea5200               push      0x52eab8
00434fbd  686cea5200               push      0x52ea6c
00434fc2  68a4ea5200               push      0x52eaa4
00434fc7  6824ea5200               push      0x52ea24
00434fcc  68acea5200               push      0x52eaac
00434fd1  8b8424a4000000           mov       eax, dword ptr [esp + 0xa4]
00434fd8  8d08                     lea       ecx, [eax]
00434fda  51                       push      ecx
00434fdb  e8405e0000               call      0x43ae20 ; _xlkt21_
00434fe0  83c428                   add       esp, 0x28
00434fe3  e95d010000               jmp       0x435145
00434fe8  6898ea5200               push      0x52ea98
00434fed  6844ea5200               push      0x52ea44
00434ff2  682cea5200               push      0x52ea2c
00434ff7  684cea5200               push      0x52ea4c
00434ffc  683cea5200               push      0x52ea3c
00435001  6854ea5200               push      0x52ea54
00435006  687cea5200               push      0x52ea7c
0043500b  68b8ea5200               push      0x52eab8
00435010  686cea5200               push      0x52ea6c
00435015  68a4ea5200               push      0x52eaa4
0043501a  6824ea5200               push      0x52ea24
0043501f  68acea5200               push      0x52eaac
00435024  8b8424b0000000           mov       eax, dword ptr [esp + 0xb0]
0043502b  8d08                     lea       ecx, [eax]
0043502d  51                       push      ecx
0043502e  e8ed640000               call      0x43b520 ; _xlkt22_
00435033  83c434                   add       esp, 0x34
00435036  e90a010000               jmp       0x435145
0043503b  6864ea5200               push      0x52ea64
00435040  688cea5200               push      0x52ea8c
00435045  685cea5200               push      0x52ea5c
0043504a  6884ea5200               push      0x52ea84
0043504f  684cea5200               push      0x52ea4c
00435054  683cea5200               push      0x52ea3c
00435059  6854ea5200               push      0x52ea54
0043505e  687cea5200               push      0x52ea7c
00435063  686cea5200               push      0x52ea6c
00435068  68a4ea5200               push      0x52eaa4
0043506d  6824ea5200               push      0x52ea24
00435072  68acea5200               push      0x52eaac
00435077  8b8424b0000000           mov       eax, dword ptr [esp + 0xb0]
0043507e  8d08                     lea       ecx, [eax]
00435080  51                       push      ecx
00435081  e87a6e0000               call      0x43bf00 ; _xlkt23_
00435086  83c434                   add       esp, 0x34
00435089  e9b7000000               jmp       0x435145
0043508e  6864ea5200               push      0x52ea64
00435093  688cea5200               push      0x52ea8c
00435098  685cea5200               push      0x52ea5c
0043509d  6884ea5200               push      0x52ea84
004350a2  684cea5200               push      0x52ea4c
004350a7  683cea5200               push      0x52ea3c
004350ac  6854ea5200               push      0x52ea54
004350b1  687cea5200               push      0x52ea7c
004350b6  68b8ea5200               push      0x52eab8
004350bb  686cea5200               push      0x52ea6c
004350c0  68a4ea5200               push      0x52eaa4
004350c5  6824ea5200               push      0x52ea24
004350ca  68acea5200               push      0x52eaac
004350cf  8b8424b4000000           mov       eax, dword ptr [esp + 0xb4]
004350d6  8d08                     lea       ecx, [eax]
004350d8  51                       push      ecx
004350d9  e822780000               call      0x43c900 ; _xlkt24_
004350de  83c438                   add       esp, 0x38
004350e1  eb62                     jmp       0x435145
004350e3  6864ea5200               push      0x52ea64
004350e8  688cea5200               push      0x52ea8c
004350ed  685cea5200               push      0x52ea5c
004350f2  6884ea5200               push      0x52ea84
004350f7  6898ea5200               push      0x52ea98
004350fc  6844ea5200               push      0x52ea44
00435101  682cea5200               push      0x52ea2c
00435106  684cea5200               push      0x52ea4c
0043510b  683cea5200               push      0x52ea3c
00435110  6854ea5200               push      0x52ea54
00435115  687cea5200               push      0x52ea7c
0043511a  68b8ea5200               push      0x52eab8
0043511f  686cea5200               push      0x52ea6c
00435124  68a4ea5200               push      0x52eaa4
00435129  6824ea5200               push      0x52ea24
0043512e  68acea5200               push      0x52eaac
00435133  8b8424c0000000           mov       eax, dword ptr [esp + 0xc0]
0043513a  8d08                     lea       ecx, [eax]
0043513c  51                       push      ecx
0043513d  e8ae810000               call      0x43d2f0 ; _xlkt25_
00435142  83c444                   add       esp, 0x44
00435145  837c242007               cmp       dword ptr [esp + 0x20], 7
0043514a  730d                     jae       0x435159
0043514c  8b442420                 mov       eax, dword ptr [esp + 0x20]
00435150  8b0c85b8ed5200           mov       ecx, dword ptr [eax*4 + 0x52edb8]
00435157  ffe1                     jmp       ecx
00435159  6850ea5200               push      0x52ea50
0043515e  6840ea5200               push      0x52ea40
00435163  6858ea5200               push      0x52ea58
00435168  6880ea5200               push      0x52ea80
0043516d  6870ea5200               push      0x52ea70
00435172  68a8ea5200               push      0x52eaa8
00435177  6834ea5200               push      0x52ea34
0043517c  68b0ea5200               push      0x52eab0
00435181  8b84249c000000           mov       eax, dword ptr [esp + 0x9c]
00435188  8d08                     lea       ecx, [eax]
0043518a  51                       push      ecx
0043518b  e860560000               call      0x43a7f0 ; _xlkt20_
00435190  83c424                   add       esp, 0x24
00435193  e9a1010000               jmp       0x435339
00435198  6850ea5200               push      0x52ea50
0043519d  6840ea5200               push      0x52ea40
004351a2  6858ea5200               push      0x52ea58
004351a7  6880ea5200               push      0x52ea80
004351ac  68bcea5200               push      0x52eabc
004351b1  6870ea5200               push      0x52ea70
004351b6  68a8ea5200               push      0x52eaa8
004351bb  6834ea5200               push      0x52ea34
004351c0  68b0ea5200               push      0x52eab0
004351c5  8b8424a0000000           mov       eax, dword ptr [esp + 0xa0]
004351cc  8d08                     lea       ecx, [eax]
004351ce  51                       push      ecx
004351cf  e84c5c0000               call      0x43ae20 ; _xlkt21_
004351d4  83c428                   add       esp, 0x28
004351d7  e95d010000               jmp       0x435339
004351dc  689cea5200               push      0x52ea9c
004351e1  6848ea5200               push      0x52ea48
004351e6  6830ea5200               push      0x52ea30
004351eb  6850ea5200               push      0x52ea50
004351f0  6840ea5200               push      0x52ea40
004351f5  6858ea5200               push      0x52ea58
004351fa  6880ea5200               push      0x52ea80
004351ff  68bcea5200               push      0x52eabc
00435204  6870ea5200               push      0x52ea70
00435209  68a8ea5200               push      0x52eaa8
0043520e  6834ea5200               push      0x52ea34
00435213  68b0ea5200               push      0x52eab0
00435218  8b8424ac000000           mov       eax, dword ptr [esp + 0xac]
0043521f  8d08                     lea       ecx, [eax]
00435221  51                       push      ecx
00435222  e8f9620000               call      0x43b520 ; _xlkt22_
00435227  83c434                   add       esp, 0x34
0043522a  e90a010000               jmp       0x435339
0043522f  6868ea5200               push      0x52ea68
00435234  6890ea5200               push      0x52ea90
00435239  6860ea5200               push      0x52ea60
0043523e  6888ea5200               push      0x52ea88
00435243  6850ea5200               push      0x52ea50
00435248  6840ea5200               push      0x52ea40
0043524d  6858ea5200               push      0x52ea58
00435252  6880ea5200               push      0x52ea80
00435257  6870ea5200               push      0x52ea70
0043525c  68a8ea5200               push      0x52eaa8
00435261  6834ea5200               push      0x52ea34
00435266  68b0ea5200               push      0x52eab0
0043526b  8b8424ac000000           mov       eax, dword ptr [esp + 0xac]
00435272  8d08                     lea       ecx, [eax]
00435274  51                       push      ecx
00435275  e8866c0000               call      0x43bf00 ; _xlkt23_
0043527a  83c434                   add       esp, 0x34
0043527d  e9b7000000               jmp       0x435339
00435282  6868ea5200               push      0x52ea68
00435287  6890ea5200               push      0x52ea90
0043528c  6860ea5200               push      0x52ea60
00435291  6888ea5200               push      0x52ea88
00435296  6850ea5200               push      0x52ea50
0043529b  6840ea5200               push      0x52ea40
004352a0  6858ea5200               push      0x52ea58
004352a5  6880ea5200               push      0x52ea80
004352aa  68bcea5200               push      0x52eabc
004352af  6870ea5200               push      0x52ea70
004352b4  68a8ea5200               push      0x52eaa8
004352b9  6834ea5200               push      0x52ea34
004352be  68b0ea5200               push      0x52eab0
004352c3  8b8424b0000000           mov       eax, dword ptr [esp + 0xb0]
004352ca  8d08                     lea       ecx, [eax]
004352cc  51                       push      ecx
004352cd  e82e760000               call      0x43c900 ; _xlkt24_
004352d2  83c438                   add       esp, 0x38
004352d5  eb62                     jmp       0x435339
004352d7  6868ea5200               push      0x52ea68
004352dc  6890ea5200               push      0x52ea90
004352e1  6860ea5200               push      0x52ea60
004352e6  6888ea5200               push      0x52ea88
004352eb  689cea5200               push      0x52ea9c
004352f0  6848ea5200               push      0x52ea48
004352f5  6830ea5200               push      0x52ea30
004352fa  6850ea5200               push      0x52ea50
004352ff  6840ea5200               push      0x52ea40
00435304  6858ea5200               push      0x52ea58
00435309  6880ea5200               push      0x52ea80
0043530e  68bcea5200               push      0x52eabc
00435313  6870ea5200               push      0x52ea70
00435318  68a8ea5200               push      0x52eaa8
0043531d  6834ea5200               push      0x52ea34
00435322  68b0ea5200               push      0x52eab0
00435327  8b8424bc000000           mov       eax, dword ptr [esp + 0xbc]
0043532e  8d08                     lea       ecx, [eax]
00435330  51                       push      ecx
00435331  e8ba7f0000               call      0x43d2f0 ; _xlkt25_
00435336  83c444                   add       esp, 0x44
00435339  d9057cea5200             fld       dword ptr [0x52ea7c] ; bits=00000000, f32=0.0
0043533f  d9fa                     fsqrt
00435341  d91d7cea5200             fstp      dword ptr [0x52ea7c] ; bits=00000000, f32=0.0
00435347  d90580ea5200             fld       dword ptr [0x52ea80] ; bits=00000000, f32=0.0
0043534d  d9fa                     fsqrt
0043534f  d91d80ea5200             fstp      dword ptr [0x52ea80] ; bits=00000000, f32=0.0
00435355  d9057cea5200             fld       dword ptr [0x52ea7c] ; bits=00000000, f32=0.0
0043535b  d9ee                     fldz
0043535d  dff1                     fcompi    st(1)
0043535f  dbbc2490010000           fstp      xword ptr [esp + 0x190]
00435366  0f8a1f000000             jp        0x43538b
0043536c  731d                     jae       0x43538b
0043536e  d90554ea5200             fld       dword ptr [0x52ea54] ; bits=00000000, f32=0.0
00435374  d80d1ce85200             fmul      dword ptr [0x52e81c] ; bits=0000003f, f32=0.5
0043537a  dbac2490010000           fld       xword ptr [esp + 0x190]
00435381  def9                     fdivp     st(1)
00435383  d91d54ea5200             fstp      dword ptr [0x52ea54] ; bits=00000000, f32=0.0
00435389  eb0a                     jmp       0x435395
0043538b  c70554ea520000000000     mov       dword ptr [0x52ea54], 0 ; bits=00000000, f32=0.0
00435395  d90580ea5200             fld       dword ptr [0x52ea80] ; bits=00000000, f32=0.0
0043539b  d9ee                     fldz
0043539d  dff1                     fcompi    st(1)
0043539f  dbbc2484010000           fstp      xword ptr [esp + 0x184]
004353a6  0f8a1f000000             jp        0x4353cb
004353ac  731d                     jae       0x4353cb
004353ae  d90558ea5200             fld       dword ptr [0x52ea58] ; bits=00000000, f32=0.0
004353b4  d80d1ce85200             fmul      dword ptr [0x52e81c] ; bits=0000003f, f32=0.5
004353ba  dbac2484010000           fld       xword ptr [esp + 0x184]
004353c1  def9                     fdivp     st(1)
004353c3  d91d58ea5200             fstp      dword ptr [0x52ea58] ; bits=00000000, f32=0.0
004353c9  eb0a                     jmp       0x4353d5
004353cb  c70558ea520000000000     mov       dword ptr [0x52ea58], 0 ; bits=00000000, f32=0.0
004353d5  8b8424c4020000           mov       eax, dword ptr [esp + 0x2c4]
004353dc  8b28                     mov       ebp, dword ptr [eax]
004353de  83fd00                   cmp       ebp, 0
004353e1  0f8e19080000             jle       0x435c00
004353e7  be01000000               mov       esi, 1
004353ec  8b8424b4020000           mov       eax, dword ptr [esp + 0x2b4]
004353f3  d900                     fld       dword ptr [eax]
004353f5  dbbc2478010000           fstp      xword ptr [esp + 0x178]
004353fc  dbac24e8010000           fld       xword ptr [esp + 0x1e8]
00435403  d83d10e85200             fdivr     dword ptr [0x52e810] ; bits=0000803f, f32=1.0
00435409  dbbc246c010000           fstp      xword ptr [esp + 0x16c]
00435410  d905a4ea5200             fld       dword ptr [0x52eaa4] ; bits=00000000, f32=0.0
00435416  d82da8ea5200             fsubr     dword ptr [0x52eaa8] ; bits=00000000, f32=0.0
0043541c  dbbc2460010000           fstp      xword ptr [esp + 0x160]
00435423  d90524ea5200             fld       dword ptr [0x52ea24] ; bits=00000000, f32=0.0
00435429  d82d34ea5200             fsubr     dword ptr [0x52ea34] ; bits=00000000, f32=0.0
0043542f  dbbc2454010000           fstp      xword ptr [esp + 0x154]
00435436  d9057cea5200             fld       dword ptr [0x52ea7c] ; bits=00000000, f32=0.0
0043543c  d82d80ea5200             fsubr     dword ptr [0x52ea80] ; bits=00000000, f32=0.0
00435442  dbbc2448010000           fstp      xword ptr [esp + 0x148]
00435449  d9053cea5200             fld       dword ptr [0x52ea3c] ; bits=00000000, f32=0.0
0043544f  d82d40ea5200             fsubr     dword ptr [0x52ea40] ; bits=00000000, f32=0.0
00435455  dbbc243c010000           fstp      xword ptr [esp + 0x13c]
0043545c  d905acea5200             fld       dword ptr [0x52eaac] ; bits=00000000, f32=0.0
00435462  d82db0ea5200             fsubr     dword ptr [0x52eab0] ; bits=00000000, f32=0.0
00435468  dbbc2430010000           fstp      xword ptr [esp + 0x130]
0043546f  8b04bd24eb5200           mov       eax, dword ptr [edi*4 + 0x52eb24]
00435476  d905b8ea5200             fld       dword ptr [0x52eab8] ; bits=00000000, f32=0.0
0043547c  d82dbcea5200             fsubr     dword ptr [0x52eabc] ; bits=00000000, f32=0.0
00435482  dbbc2424010000           fstp      xword ptr [esp + 0x124]
00435489  8b0cbd18ec5200           mov       ecx, dword ptr [edi*4 + 0x52ec18]
00435490  d9052cea5200             fld       dword ptr [0x52ea2c] ; bits=00000000, f32=0.0
00435496  d82d30ea5200             fsubr     dword ptr [0x52ea30] ; bits=00000000, f32=0.0
0043549c  dbbc2418010000           fstp      xword ptr [esp + 0x118]
004354a3  d90598ea5200             fld       dword ptr [0x52ea98] ; bits=00000000, f32=0.0
004354a9  d82d9cea5200             fsubr     dword ptr [0x52ea9c] ; bits=00000000, f32=0.0
004354af  dbbc240c010000           fstp      xword ptr [esp + 0x10c]
004354b6  d90584ea5200             fld       dword ptr [0x52ea84] ; bits=00000000, f32=0.0
004354bc  d82d88ea5200             fsubr     dword ptr [0x52ea88] ; bits=00000000, f32=0.0
004354c2  dbbc2400010000           fstp      xword ptr [esp + 0x100]
004354c9  d9058cea5200             fld       dword ptr [0x52ea8c] ; bits=00000000, f32=0.0
004354cf  d82d90ea5200             fsubr     dword ptr [0x52ea90] ; bits=00000000, f32=0.0
004354d5  dbbc24f4000000           fstp      xword ptr [esp + 0xf4]
004354dc  d90554ea5200             fld       dword ptr [0x52ea54] ; bits=00000000, f32=0.0
004354e2  d82d58ea5200             fsubr     dword ptr [0x52ea58] ; bits=00000000, f32=0.0
004354e8  dbbc24e8000000           fstp      xword ptr [esp + 0xe8]
004354ef  d9054cea5200             fld       dword ptr [0x52ea4c] ; bits=00000000, f32=0.0
004354f5  d82d50ea5200             fsubr     dword ptr [0x52ea50] ; bits=00000000, f32=0.0
004354fb  dbbc24dc000000           fstp      xword ptr [esp + 0xdc]
00435502  d90544ea5200             fld       dword ptr [0x52ea44] ; bits=00000000, f32=0.0
00435508  d82d48ea5200             fsubr     dword ptr [0x52ea48] ; bits=00000000, f32=0.0
0043550e  dbbc24d0000000           fstp      xword ptr [esp + 0xd0]
00435515  d9055cea5200             fld       dword ptr [0x52ea5c] ; bits=00000000, f32=0.0
0043551b  d82d60ea5200             fsubr     dword ptr [0x52ea60] ; bits=00000000, f32=0.0
00435521  dbbc24c4000000           fstp      xword ptr [esp + 0xc4]
00435528  d90564ea5200             fld       dword ptr [0x52ea64] ; bits=00000000, f32=0.0
0043552e  d82d68ea5200             fsubr     dword ptr [0x52ea68] ; bits=00000000, f32=0.0
00435534  dbbc24b8000000           fstp      xword ptr [esp + 0xb8]
0043553b  89442414                 mov       dword ptr [esp + 0x14], eax
0043553f  894c2410                 mov       dword ptr [esp + 0x10], ecx
00435543  8b1cb5cce95a00           mov       ebx, dword ptr [esi*4 + 0x5ae9cc]
0043554a  8b8424cc020000           mov       eax, dword ptr [esp + 0x2cc]
00435551  dbac2478010000           fld       xword ptr [esp + 0x178]
00435558  d86cb0fc                 fsubr     dword ptr [eax + esi*4 - 4]
0043555c  dbac246c010000           fld       xword ptr [esp + 0x16c]
00435563  dec9                     fmulp     st(1)
00435565  dbac2460010000           fld       xword ptr [esp + 0x160]
0043556c  d8c9                     fmul      st(1)
0043556e  d805a4ea5200             fadd      dword ptr [0x52eaa4] ; bits=00000000, f32=0.0
00435574  dbac2454010000           fld       xword ptr [esp + 0x154]
0043557b  d8ca                     fmul      st(2)
0043557d  d80524ea5200             fadd      dword ptr [0x52ea24] ; bits=00000000, f32=0.0
00435583  dbac2448010000           fld       xword ptr [esp + 0x148]
0043558a  d8cb                     fmul      st(3)
0043558c  d8057cea5200             fadd      dword ptr [0x52ea7c] ; bits=00000000, f32=0.0
00435592  dbac243c010000           fld       xword ptr [esp + 0x13c]
00435599  d8cc                     fmul      st(4)
0043559b  d8053cea5200             fadd      dword ptr [0x52ea3c] ; bits=00000000, f32=0.0
004355a1  dbac2430010000           fld       xword ptr [esp + 0x130]
004355a8  d8cd                     fmul      st(5)
004355aa  d805acea5200             fadd      dword ptr [0x52eaac] ; bits=00000000, f32=0.0
004355b0  d91c9d602e0302           fstp      dword ptr [ebx*4 + 0x2032e60]
004355b7  d9cb                     fxch      st(3)
004355b9  d91c9d642e0302           fstp      dword ptr [ebx*4 + 0x2032e64]
004355c0  d9c9                     fxch      st(1)
004355c2  d91c9d682e0302           fstp      dword ptr [ebx*4 + 0x2032e68]
004355c9  d91c9d6c2e0302           fstp      dword ptr [ebx*4 + 0x2032e6c]
004355d0  d91c9d702e0302           fstp      dword ptr [ebx*4 + 0x2032e70]
004355d7  dbbc24ac000000           fstp      xword ptr [esp + 0xac]
004355de  837c241401               cmp       dword ptr [esp + 0x14], 1
004355e3  751d                     jne       0x435602
004355e5  dbac2424010000           fld       xword ptr [esp + 0x124]
004355ec  dbac24ac000000           fld       xword ptr [esp + 0xac]
004355f3  dec9                     fmulp     st(1)
004355f5  d805b8ea5200             fadd      dword ptr [0x52eab8] ; bits=00000000, f32=0.0
004355fb  d91c9d742e0302           fstp      dword ptr [ebx*4 + 0x2032e74]
00435602  837c241001               cmp       dword ptr [esp + 0x10], 1
00435607  753c                     jne       0x435645
00435609  dbac2418010000           fld       xword ptr [esp + 0x118]
00435610  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435617  dec9                     fmulp     st(1)
00435619  d8052cea5200             fadd      dword ptr [0x52ea2c] ; bits=00000000, f32=0.0
0043561f  dbac240c010000           fld       xword ptr [esp + 0x10c]
00435626  dbac24ac000000           fld       xword ptr [esp + 0xac]
0043562d  dec9                     fmulp     st(1)
0043562f  d80598ea5200             fadd      dword ptr [0x52ea98] ; bits=00000000, f32=0.0
00435635  d9c9                     fxch      st(1)
00435637  d91c9d782e0302           fstp      dword ptr [ebx*4 + 0x2032e78]
0043563e  d91c9d7c2e0302           fstp      dword ptr [ebx*4 + 0x2032e7c]
00435645  83ff17                   cmp       edi, 0x17
00435648  0f8ca1000000             jl        0x4356ef
0043564e  dbac2400010000           fld       xword ptr [esp + 0x100]
00435655  dbac24ac000000           fld       xword ptr [esp + 0xac]
0043565c  dec9                     fmulp     st(1)
0043565e  d80584ea5200             fadd      dword ptr [0x52ea84] ; bits=00000000, f32=0.0
00435664  dbbc24a0000000           fstp      xword ptr [esp + 0xa0]
0043566b  dbac24f4000000           fld       xword ptr [esp + 0xf4]
00435672  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435679  dec9                     fmulp     st(1)
0043567b  d8058cea5200             fadd      dword ptr [0x52ea8c] ; bits=00000000, f32=0.0
00435681  dbbc2494000000           fstp      xword ptr [esp + 0x94]
00435688  83ff17                   cmp       edi, 0x17
0043568b  751e                     jne       0x4356ab
0043568d  dbac24a0000000           fld       xword ptr [esp + 0xa0]
00435694  d91c9d742e0302           fstp      dword ptr [ebx*4 + 0x2032e74]
0043569b  dbac2494000000           fld       xword ptr [esp + 0x94]
004356a2  d91c9d782e0302           fstp      dword ptr [ebx*4 + 0x2032e78]
004356a9  eb44                     jmp       0x4356ef
004356ab  83ff18                   cmp       edi, 0x18
004356ae  751e                     jne       0x4356ce
004356b0  dbac24a0000000           fld       xword ptr [esp + 0xa0]
004356b7  d91c9d782e0302           fstp      dword ptr [ebx*4 + 0x2032e78]
004356be  dbac2494000000           fld       xword ptr [esp + 0x94]
004356c5  d91c9d7c2e0302           fstp      dword ptr [ebx*4 + 0x2032e7c]
004356cc  eb21                     jmp       0x4356ef
004356ce  83ff19                   cmp       edi, 0x19
004356d1  751c                     jne       0x4356ef
004356d3  dbac24a0000000           fld       xword ptr [esp + 0xa0]
004356da  d91c9d802e0302           fstp      dword ptr [ebx*4 + 0x2032e80]
004356e1  dbac2494000000           fld       xword ptr [esp + 0x94]
004356e8  d91c9d842e0302           fstp      dword ptr [ebx*4 + 0x2032e84]
004356ef  837c24601e               cmp       dword ptr [esp + 0x60], 0x1e
004356f4  0f8cef040000             jl        0x435be9
004356fa  837c241c06               cmp       dword ptr [esp + 0x1c], 6
004356ff  0f83e4040000             jae       0x435be9
00435705  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
00435709  8b0c85a0ed5200           mov       ecx, dword ptr [eax*4 + 0x52eda0]
00435710  ffe1                     jmp       ecx
00435712  dbac24e8000000           fld       xword ptr [esp + 0xe8]
00435719  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435720  dec9                     fmulp     st(1)
00435722  d80554ea5200             fadd      dword ptr [0x52ea54] ; bits=00000000, f32=0.0
00435728  dbac24dc000000           fld       xword ptr [esp + 0xdc]
0043572f  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435736  dec9                     fmulp     st(1)
00435738  d8054cea5200             fadd      dword ptr [0x52ea4c] ; bits=00000000, f32=0.0
0043573e  d9c1                     fld       st(1)
00435740  d9e1                     fabs
00435742  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435748  dff1                     fcompi    st(1)
0043574a  ddd8                     fstp      st(0)
0043574c  d9c9                     fxch      st(1)
0043574e  0f8a06000000             jp        0x43575a
00435754  7604                     jbe       0x43575a
00435756  ddd8                     fstp      st(0)
00435758  d9ee                     fldz
0043575a  d9c1                     fld       st(1)
0043575c  d9e1                     fabs
0043575e  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435764  dff1                     fcompi    st(1)
00435766  ddd8                     fstp      st(0)
00435768  0f8a08000000             jp        0x435776
0043576e  7606                     jbe       0x435776
00435770  ddd9                     fstp      st(1)
00435772  d9ee                     fldz
00435774  d9c9                     fxch      st(1)
00435776  d91c9d742e0302           fstp      dword ptr [ebx*4 + 0x2032e74]
0043577d  d91c9d782e0302           fstp      dword ptr [ebx*4 + 0x2032e78]
00435784  e960040000               jmp       0x435be9
00435789  dbac24e8000000           fld       xword ptr [esp + 0xe8]
00435790  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435797  dec9                     fmulp     st(1)
00435799  d80554ea5200             fadd      dword ptr [0x52ea54] ; bits=00000000, f32=0.0
0043579f  dbac24dc000000           fld       xword ptr [esp + 0xdc]
004357a6  dbac24ac000000           fld       xword ptr [esp + 0xac]
004357ad  dec9                     fmulp     st(1)
004357af  d8054cea5200             fadd      dword ptr [0x52ea4c] ; bits=00000000, f32=0.0
004357b5  d9c1                     fld       st(1)
004357b7  d9e1                     fabs
004357b9  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
004357bf  dff1                     fcompi    st(1)
004357c1  ddd8                     fstp      st(0)
004357c3  d9c9                     fxch      st(1)
004357c5  0f8a06000000             jp        0x4357d1
004357cb  7604                     jbe       0x4357d1
004357cd  ddd8                     fstp      st(0)
004357cf  d9ee                     fldz
004357d1  d9c1                     fld       st(1)
004357d3  d9e1                     fabs
004357d5  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
004357db  dff1                     fcompi    st(1)
004357dd  ddd8                     fstp      st(0)
004357df  0f8a08000000             jp        0x4357ed
004357e5  7606                     jbe       0x4357ed
004357e7  ddd9                     fstp      st(1)
004357e9  d9ee                     fldz
004357eb  d9c9                     fxch      st(1)
004357ed  d91c9d782e0302           fstp      dword ptr [ebx*4 + 0x2032e78]
004357f4  d91c9d7c2e0302           fstp      dword ptr [ebx*4 + 0x2032e7c]
004357fb  e9e9030000               jmp       0x435be9
00435800  dbac24e8000000           fld       xword ptr [esp + 0xe8]
00435807  dbac24ac000000           fld       xword ptr [esp + 0xac]
0043580e  dec9                     fmulp     st(1)
00435810  d80554ea5200             fadd      dword ptr [0x52ea54] ; bits=00000000, f32=0.0
00435816  dbac24dc000000           fld       xword ptr [esp + 0xdc]
0043581d  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435824  dec9                     fmulp     st(1)
00435826  d8054cea5200             fadd      dword ptr [0x52ea4c] ; bits=00000000, f32=0.0
0043582c  dbac24d0000000           fld       xword ptr [esp + 0xd0]
00435833  dbac24ac000000           fld       xword ptr [esp + 0xac]
0043583a  dec9                     fmulp     st(1)
0043583c  d80544ea5200             fadd      dword ptr [0x52ea44] ; bits=00000000, f32=0.0
00435842  dbbc2488000000           fstp      xword ptr [esp + 0x88]
00435849  d9c1                     fld       st(1)
0043584b  d9e1                     fabs
0043584d  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435853  dff1                     fcompi    st(1)
00435855  ddd8                     fstp      st(0)
00435857  d9c9                     fxch      st(1)
00435859  0f8a06000000             jp        0x435865
0043585f  7604                     jbe       0x435865
00435861  ddd8                     fstp      st(0)
00435863  d9ee                     fldz
00435865  d9c1                     fld       st(1)
00435867  d9e1                     fabs
00435869  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
0043586f  dff1                     fcompi    st(1)
00435871  ddd8                     fstp      st(0)
00435873  0f8a08000000             jp        0x435881
00435879  7606                     jbe       0x435881
0043587b  ddd9                     fstp      st(1)
0043587d  d9ee                     fldz
0043587f  d9c9                     fxch      st(1)
00435881  dbac2488000000           fld       xword ptr [esp + 0x88]
00435888  d9e1                     fabs
0043588a  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435890  dff1                     fcompi    st(1)
00435892  ddd8                     fstp      st(0)
00435894  0f8a0b000000             jp        0x4358a5
0043589a  7609                     jbe       0x4358a5
0043589c  d9ee                     fldz
0043589e  dbbc2488000000           fstp      xword ptr [esp + 0x88]
004358a5  d91c9d802e0302           fstp      dword ptr [ebx*4 + 0x2032e80]
004358ac  d91c9d842e0302           fstp      dword ptr [ebx*4 + 0x2032e84]
004358b3  dbac2488000000           fld       xword ptr [esp + 0x88]
004358ba  d91c9d882e0302           fstp      dword ptr [ebx*4 + 0x2032e88]
004358c1  e923030000               jmp       0x435be9
004358c6  dbac24e8000000           fld       xword ptr [esp + 0xe8]
004358cd  dbac24ac000000           fld       xword ptr [esp + 0xac]
004358d4  dec9                     fmulp     st(1)
004358d6  d80554ea5200             fadd      dword ptr [0x52ea54] ; bits=00000000, f32=0.0
004358dc  dbac24dc000000           fld       xword ptr [esp + 0xdc]
004358e3  dbac24ac000000           fld       xword ptr [esp + 0xac]
004358ea  dec9                     fmulp     st(1)
004358ec  d8054cea5200             fadd      dword ptr [0x52ea4c] ; bits=00000000, f32=0.0
004358f2  dbac24c4000000           fld       xword ptr [esp + 0xc4]
004358f9  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435900  dec9                     fmulp     st(1)
00435902  d8055cea5200             fadd      dword ptr [0x52ea5c] ; bits=00000000, f32=0.0
00435908  dbac24b8000000           fld       xword ptr [esp + 0xb8]
0043590f  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435916  dec9                     fmulp     st(1)
00435918  d80564ea5200             fadd      dword ptr [0x52ea64] ; bits=00000000, f32=0.0
0043591e  d9c3                     fld       st(3)
00435920  d9e1                     fabs
00435922  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435928  dff1                     fcompi    st(1)
0043592a  ddd8                     fstp      st(0)
0043592c  d9ca                     fxch      st(2)
0043592e  d9cb                     fxch      st(3)
00435930  d9ca                     fxch      st(2)
00435932  0f8a08000000             jp        0x435940
00435938  7606                     jbe       0x435940
0043593a  ddda                     fstp      st(2)
0043593c  d9ee                     fldz
0043593e  d9ca                     fxch      st(2)
00435940  d9c3                     fld       st(3)
00435942  d9e1                     fabs
00435944  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
0043594a  dff1                     fcompi    st(1)
0043594c  ddd8                     fstp      st(0)
0043594e  0f8a08000000             jp        0x43595c
00435954  7606                     jbe       0x43595c
00435956  dddb                     fstp      st(3)
00435958  d9ee                     fldz
0043595a  d9cb                     fxch      st(3)
0043595c  d9c1                     fld       st(1)
0043595e  d9e1                     fabs
00435960  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435966  dff1                     fcompi    st(1)
00435968  ddd8                     fstp      st(0)
0043596a  0f8a08000000             jp        0x435978
00435970  7606                     jbe       0x435978
00435972  ddd9                     fstp      st(1)
00435974  d9ee                     fldz
00435976  d9c9                     fxch      st(1)
00435978  d9c0                     fld       st(0)
0043597a  d9e1                     fabs
0043597c  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435982  dff1                     fcompi    st(1)
00435984  ddd8                     fstp      st(0)
00435986  0f8a06000000             jp        0x435992
0043598c  7604                     jbe       0x435992
0043598e  ddd8                     fstp      st(0)
00435990  d9ee                     fldz
00435992  d9ca                     fxch      st(2)
00435994  d91c9d7c2e0302           fstp      dword ptr [ebx*4 + 0x2032e7c]
0043599b  d9ca                     fxch      st(2)
0043599d  d91c9d802e0302           fstp      dword ptr [ebx*4 + 0x2032e80]
004359a4  d9c9                     fxch      st(1)
004359a6  d91c9d842e0302           fstp      dword ptr [ebx*4 + 0x2032e84]
004359ad  d91c9d882e0302           fstp      dword ptr [ebx*4 + 0x2032e88]
004359b4  e930020000               jmp       0x435be9
004359b9  dbac24e8000000           fld       xword ptr [esp + 0xe8]
004359c0  dbac24ac000000           fld       xword ptr [esp + 0xac]
004359c7  dec9                     fmulp     st(1)
004359c9  d80554ea5200             fadd      dword ptr [0x52ea54] ; bits=00000000, f32=0.0
004359cf  dbac24dc000000           fld       xword ptr [esp + 0xdc]
004359d6  dbac24ac000000           fld       xword ptr [esp + 0xac]
004359dd  dec9                     fmulp     st(1)
004359df  d8054cea5200             fadd      dword ptr [0x52ea4c] ; bits=00000000, f32=0.0
004359e5  dbac24c4000000           fld       xword ptr [esp + 0xc4]
004359ec  dbac24ac000000           fld       xword ptr [esp + 0xac]
004359f3  dec9                     fmulp     st(1)
004359f5  d8055cea5200             fadd      dword ptr [0x52ea5c] ; bits=00000000, f32=0.0
004359fb  dbac24b8000000           fld       xword ptr [esp + 0xb8]
00435a02  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435a09  dec9                     fmulp     st(1)
00435a0b  d80564ea5200             fadd      dword ptr [0x52ea64] ; bits=00000000, f32=0.0
00435a11  d9c3                     fld       st(3)
00435a13  d9e1                     fabs
00435a15  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435a1b  dff1                     fcompi    st(1)
00435a1d  ddd8                     fstp      st(0)
00435a1f  d9ca                     fxch      st(2)
00435a21  d9cb                     fxch      st(3)
00435a23  d9ca                     fxch      st(2)
00435a25  0f8a08000000             jp        0x435a33
00435a2b  7606                     jbe       0x435a33
00435a2d  ddda                     fstp      st(2)
00435a2f  d9ee                     fldz
00435a31  d9ca                     fxch      st(2)
00435a33  d9c3                     fld       st(3)
00435a35  d9e1                     fabs
00435a37  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435a3d  dff1                     fcompi    st(1)
00435a3f  ddd8                     fstp      st(0)
00435a41  0f8a08000000             jp        0x435a4f
00435a47  7606                     jbe       0x435a4f
00435a49  dddb                     fstp      st(3)
00435a4b  d9ee                     fldz
00435a4d  d9cb                     fxch      st(3)
00435a4f  d9c1                     fld       st(1)
00435a51  d9e1                     fabs
00435a53  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435a59  dff1                     fcompi    st(1)
00435a5b  ddd8                     fstp      st(0)
00435a5d  0f8a08000000             jp        0x435a6b
00435a63  7606                     jbe       0x435a6b
00435a65  ddd9                     fstp      st(1)
00435a67  d9ee                     fldz
00435a69  d9c9                     fxch      st(1)
00435a6b  d9c0                     fld       st(0)
00435a6d  d9e1                     fabs
00435a6f  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435a75  dff1                     fcompi    st(1)
00435a77  ddd8                     fstp      st(0)
00435a79  0f8a06000000             jp        0x435a85
00435a7f  7604                     jbe       0x435a85
00435a81  ddd8                     fstp      st(0)
00435a83  d9ee                     fldz
00435a85  d9ca                     fxch      st(2)
00435a87  d91c9d802e0302           fstp      dword ptr [ebx*4 + 0x2032e80]
00435a8e  d9ca                     fxch      st(2)
00435a90  d91c9d842e0302           fstp      dword ptr [ebx*4 + 0x2032e84]
00435a97  d9c9                     fxch      st(1)
00435a99  d91c9d882e0302           fstp      dword ptr [ebx*4 + 0x2032e88]
00435aa0  d91c9d8c2e0302           fstp      dword ptr [ebx*4 + 0x2032e8c]
00435aa7  e93d010000               jmp       0x435be9
00435aac  dbac24e8000000           fld       xword ptr [esp + 0xe8]
00435ab3  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435aba  dec9                     fmulp     st(1)
00435abc  d80554ea5200             fadd      dword ptr [0x52ea54] ; bits=00000000, f32=0.0
00435ac2  dbac24dc000000           fld       xword ptr [esp + 0xdc]
00435ac9  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435ad0  dec9                     fmulp     st(1)
00435ad2  d8054cea5200             fadd      dword ptr [0x52ea4c] ; bits=00000000, f32=0.0
00435ad8  dbac24d0000000           fld       xword ptr [esp + 0xd0]
00435adf  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435ae6  dec9                     fmulp     st(1)
00435ae8  d80544ea5200             fadd      dword ptr [0x52ea44] ; bits=00000000, f32=0.0
00435aee  dbbc2488000000           fstp      xword ptr [esp + 0x88]
00435af5  dbac24c4000000           fld       xword ptr [esp + 0xc4]
00435afc  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435b03  dec9                     fmulp     st(1)
00435b05  d8055cea5200             fadd      dword ptr [0x52ea5c] ; bits=00000000, f32=0.0
00435b0b  dbac24b8000000           fld       xword ptr [esp + 0xb8]
00435b12  dbac24ac000000           fld       xword ptr [esp + 0xac]
00435b19  dec9                     fmulp     st(1)
00435b1b  d80564ea5200             fadd      dword ptr [0x52ea64] ; bits=00000000, f32=0.0
00435b21  d9c3                     fld       st(3)
00435b23  d9e1                     fabs
00435b25  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435b2b  dff1                     fcompi    st(1)
00435b2d  ddd8                     fstp      st(0)
00435b2f  d9ca                     fxch      st(2)
00435b31  d9cb                     fxch      st(3)
00435b33  d9ca                     fxch      st(2)
00435b35  0f8a08000000             jp        0x435b43
00435b3b  7606                     jbe       0x435b43
00435b3d  ddda                     fstp      st(2)
00435b3f  d9ee                     fldz
00435b41  d9ca                     fxch      st(2)
00435b43  d9c3                     fld       st(3)
00435b45  d9e1                     fabs
00435b47  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435b4d  dff1                     fcompi    st(1)
00435b4f  ddd8                     fstp      st(0)
00435b51  0f8a08000000             jp        0x435b5f
00435b57  7606                     jbe       0x435b5f
00435b59  dddb                     fstp      st(3)
00435b5b  d9ee                     fldz
00435b5d  d9cb                     fxch      st(3)
00435b5f  dbac2488000000           fld       xword ptr [esp + 0x88]
00435b66  d9e1                     fabs
00435b68  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435b6e  dff1                     fcompi    st(1)
00435b70  ddd8                     fstp      st(0)
00435b72  0f8a0b000000             jp        0x435b83
00435b78  7609                     jbe       0x435b83
00435b7a  d9ee                     fldz
00435b7c  dbbc2488000000           fstp      xword ptr [esp + 0x88]
00435b83  d9c1                     fld       st(1)
00435b85  d9e1                     fabs
00435b87  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435b8d  dff1                     fcompi    st(1)
00435b8f  ddd8                     fstp      st(0)
00435b91  0f8a08000000             jp        0x435b9f
00435b97  7606                     jbe       0x435b9f
00435b99  ddd9                     fstp      st(1)
00435b9b  d9ee                     fldz
00435b9d  d9c9                     fxch      st(1)
00435b9f  d9c0                     fld       st(0)
00435ba1  d9e1                     fabs
00435ba3  d90520e85200             fld       dword ptr [0x52e820] ; bits=37d08a30, f32=1.0099999725454722e-09
00435ba9  dff1                     fcompi    st(1)
00435bab  ddd8                     fstp      st(0)
00435bad  0f8a06000000             jp        0x435bb9
00435bb3  7604                     jbe       0x435bb9
00435bb5  ddd8                     fstp      st(0)
00435bb7  d9ee                     fldz
00435bb9  d9ca                     fxch      st(2)
00435bbb  d91c9d882e0302           fstp      dword ptr [ebx*4 + 0x2032e88]
00435bc2  d9ca                     fxch      st(2)
00435bc4  d91c9d8c2e0302           fstp      dword ptr [ebx*4 + 0x2032e8c]
00435bcb  d9c9                     fxch      st(1)
00435bcd  d91c9d902e0302           fstp      dword ptr [ebx*4 + 0x2032e90]
00435bd4  d91c9d942e0302           fstp      dword ptr [ebx*4 + 0x2032e94]
00435bdb  dbac2488000000           fld       xword ptr [esp + 0x88]
00435be2  d91c9d982e0302           fstp      dword ptr [ebx*4 + 0x2032e98]
00435be9  89d8                     mov       eax, ebx
00435beb  03442458                 add       eax, dword ptr [esp + 0x58]
00435bef  8904b5cce95a00           mov       dword ptr [esi*4 + 0x5ae9cc], eax
00435bf6  46                       inc       esi
00435bf7  83ed01                   sub       ebp, 1
00435bfa  0f8543f9ffff             jne       0x435543
00435c00  ff442444                 inc       dword ptr [esp + 0x44]
00435c04  836c242801               sub       dword ptr [esp + 0x28], 1
00435c09  0f851cf3ffff             jne       0x434f2b
00435c0f  b800000000               mov       eax, 0
00435c14  5f                       pop       edi
00435c15  5e                       pop       esi
00435c16  5b                       pop       ebx
00435c17  5d                       pop       ebp
00435c18  81c494020000             add       esp, 0x294
00435c1e  c3                       ret
00435c1f  90                       nop
