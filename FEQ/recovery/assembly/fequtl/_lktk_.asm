; _lktk_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x77880
00477880  55                       push      ebp
00477881  8bec                     mov       ebp, esp
00477883  b844000000               mov       eax, 0x44
00477888  e873170700               call      0x4e9000 ; __alloca_probe
0047788d  53                       push      ebx
0047788e  56                       push      esi
0047788f  57                       push      edi
00477890  8b4508                   mov       eax, dword ptr [ebp + 8]
00477893  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00477896  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00477899  8945dc                   mov       dword ptr [ebp - 0x24], eax
0047789c  894dd8                   mov       dword ptr [ebp - 0x28], ecx
0047789f  8955d4                   mov       dword ptr [ebp - 0x2c], edx
004778a2  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
004778a5  d900                     fld       dword ptr [eax]
004778a7  8b75dc                   mov       esi, dword ptr [ebp - 0x24]
004778aa  8b16                     mov       edx, dword ptr [esi]
004778ac  8b3c95c0e5f400           mov       edi, dword ptr [edx*4 + 0xf4e5c0]
004778b3  8d4220                   lea       eax, [edx + 0x20]
004778b6  8b0c95cce5f400           mov       ecx, dword ptr [edx*4 + 0xf4e5cc]
004778bd  8b3495c8e5f400           mov       esi, dword ptr [edx*4 + 0xf4e5c8]
004778c4  8b1cb5445b5700           mov       ebx, dword ptr [esi*4 + 0x575b44]
004778cb  833cb56c1c5a0000         cmp       dword ptr [esi*4 + 0x5a1c6c], 0
004778d3  8945d0                   mov       dword ptr [ebp - 0x30], eax
004778d6  897dcc                   mov       dword ptr [ebp - 0x34], edi
004778d9  7529                     jne       0x477904
004778db  ddd8                     fstp      st(0)
004778dd  8d0495c4e5f400           lea       eax, [edx*4 + 0xf4e5c4]
004778e4  50                       push      eax
004778e5  68701c5a00               push      0x5a1c70
004778ea  686095b700               push      0xb79560
004778ef  e88c4cfdff               call      0x44c580 ; _xstype_
004778f4  83c40c                   add       esp, 0xc
004778f7  68941b5a00               push      0x5a1b94
004778fc  e83fbb0200               call      0x4a3440 ; _jwe_xstp
00477901  83c404                   add       esp, 4
00477904  d8148dc0e5f400           fcom      dword ptr [ecx*4 + 0xf4e5c0]
0047790b  dfe0                     fnstsw    ax
0047790d  9e                       sahf
0047790e  0f8ac6000000             jp        0x4779da
00477914  0f82c0000000             jb        0x4779da
0047791a  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
0047791d  d81485c0e5f400           fcom      dword ptr [eax*4 + 0xf4e5c0]
00477924  dfe0                     fnstsw    ax
00477926  9e                       sahf
00477927  0f8a8e000000             jp        0x4779bb
0047792d  0f8688000000             jbe       0x4779bb
00477933  db7de0                   fstp      xword ptr [ebp - 0x20]
00477936  8d0495c4e5f400           lea       eax, [edx*4 + 0xf4e5c4]
0047793d  50                       push      eax
0047793e  6a10                     push      0x10
00477940  68501c5a00               push      0x5a1c50
00477945  e846faffff               call      0x477390 ; _get_tabid_
0047794a  83c40c                   add       esp, 0xc
0047794d  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00477950  8b30                     mov       esi, dword ptr [eax]
00477952  8b34b5d0e5f400           mov       esi, dword ptr [esi*4 + 0xf4e5d0]
00477959  8b3d4095b700             mov       edi, dword ptr [0xb79540] ; _xscom_
0047795f  8b054495b700             mov       eax, dword ptr [0xb79544]
00477965  8975c8                   mov       dword ptr [ebp - 0x38], esi
00477968  8d35f01b5a00             lea       esi, [0x5a1bf0] ; bits=09020000, f32=7.300764999132297e-43
0047796e  897dc4                   mov       dword ptr [ebp - 0x3c], edi
00477971  8b7dc8                   mov       edi, dword ptr [ebp - 0x38]
00477974  897dfc                   mov       dword ptr [ebp - 4], edi
00477977  8d7dfc                   lea       edi, [ebp - 4]
0047797a  897e34                   mov       dword ptr [esi + 0x34], edi
0047797d  8b7dc4                   mov       edi, dword ptr [ebp - 0x3c]
00477980  897df0                   mov       dword ptr [ebp - 0x10], edi
00477983  8945f4                   mov       dword ptr [ebp - 0xc], eax
00477986  8d45f0                   lea       eax, [ebp - 0x10]
00477989  894640                   mov       dword ptr [esi + 0x40], eax
0047798c  db6de0                   fld       xword ptr [ebp - 0x20]
0047798f  d95dec                   fstp      dword ptr [ebp - 0x14]
00477992  8d45ec                   lea       eax, [ebp - 0x14]
00477995  89464c                   mov       dword ptr [esi + 0x4c], eax
00477998  56                       push      esi
00477999  e852ac0200               call      0x4a25f0 ; _jwe_isfm
0047799e  83c404                   add       esp, 4
004779a1  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
004779a4  89c6                     mov       esi, eax
004779a6  29de                     sub       esi, ebx
004779a8  89f1                     mov       ecx, esi
004779aa  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
004779b1  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
004779b4  d910                     fst       dword ptr [eax]
004779b6  e9d0000000               jmp       0x477a8b
004779bb  8d140b                   lea       edx, [ebx + ecx]
004779be  d81495c0e5f400           fcom      dword ptr [edx*4 + 0xf4e5c0]
004779c5  dfe0                     fnstsw    ax
004779c7  9e                       sahf
004779c8  0f8abd000000             jp        0x477a8b
004779ce  0f86b7000000             jbe       0x477a8b
004779d4  01d9                     add       ecx, ebx
004779d6  01da                     add       edx, ebx
004779d8  ebe4                     jmp       0x4779be
004779da  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
004779dd  d81485c0e5f400           fcom      dword ptr [eax*4 + 0xf4e5c0]
004779e4  dfe0                     fnstsw    ax
004779e6  9e                       sahf
004779e7  0f8a8a000000             jp        0x477a77
004779ed  0f8384000000             jae       0x477a77
004779f3  db7de0                   fstp      xword ptr [ebp - 0x20]
004779f6  8d0495c4e5f400           lea       eax, [edx*4 + 0xf4e5c4]
004779fd  50                       push      eax
004779fe  6a10                     push      0x10
00477a00  68601c5a00               push      0x5a1c60
00477a05  e886f9ffff               call      0x477390 ; _get_tabid_
00477a0a  83c40c                   add       esp, 0xc
00477a0d  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00477a10  8b30                     mov       esi, dword ptr [eax]
00477a12  8b34b5d0e5f400           mov       esi, dword ptr [esi*4 + 0xf4e5d0]
00477a19  8b3d4095b700             mov       edi, dword ptr [0xb79540] ; _xscom_
00477a1f  8b054495b700             mov       eax, dword ptr [0xb79544]
00477a25  8975c0                   mov       dword ptr [ebp - 0x40], esi
00477a28  8d35a01b5a00             lea       esi, [0x5a1ba0] ; bits=09020000, f32=7.300764999132297e-43
00477a2e  897dbc                   mov       dword ptr [ebp - 0x44], edi
00477a31  8b7dc0                   mov       edi, dword ptr [ebp - 0x40]
00477a34  897dfc                   mov       dword ptr [ebp - 4], edi
00477a37  8d7dfc                   lea       edi, [ebp - 4]
00477a3a  897e34                   mov       dword ptr [esi + 0x34], edi
00477a3d  8b7dbc                   mov       edi, dword ptr [ebp - 0x44]
00477a40  897df0                   mov       dword ptr [ebp - 0x10], edi
00477a43  8945f4                   mov       dword ptr [ebp - 0xc], eax
00477a46  8d45f0                   lea       eax, [ebp - 0x10]
00477a49  894640                   mov       dword ptr [esi + 0x40], eax
00477a4c  db6de0                   fld       xword ptr [ebp - 0x20]
00477a4f  d95dec                   fstp      dword ptr [ebp - 0x14]
00477a52  8d45ec                   lea       eax, [ebp - 0x14]
00477a55  89464c                   mov       dword ptr [esi + 0x4c], eax
00477a58  56                       push      esi
00477a59  e892ab0200               call      0x4a25f0 ; _jwe_isfm
00477a5e  83c404                   add       esp, 4
00477a61  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
00477a64  89c1                     mov       ecx, eax
00477a66  8d3403                   lea       esi, [ebx + eax]
00477a69  d904b5c0e5f400           fld       dword ptr [esi*4 + 0xf4e5c0]
00477a70  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00477a73  d910                     fst       dword ptr [eax]
00477a75  eb14                     jmp       0x477a8b
00477a77  29d9                     sub       ecx, ebx
00477a79  d8148dc0e5f400           fcom      dword ptr [ecx*4 + 0xf4e5c0]
00477a80  dfe0                     fnstsw    ax
00477a82  9e                       sahf
00477a83  0f8a02000000             jp        0x477a8b
00477a89  72ec                     jb        0x477a77
00477a8b  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00477a8e  8b10                     mov       edx, dword ptr [eax]
00477a90  890c95cce5f400           mov       dword ptr [edx*4 + 0xf4e5cc], ecx
00477a97  89d8                     mov       eax, ebx
00477a99  01c8                     add       eax, ecx
00477a9b  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
00477aa2  d8248dc0e5f400           fsub      dword ptr [ecx*4 + 0xf4e5c0]
00477aa9  d90485cce5f400           fld       dword ptr [eax*4 + 0xf4e5cc]
00477ab0  d8248dcce5f400           fsub      dword ptr [ecx*4 + 0xf4e5cc]
00477ab7  def1                     fdivrp    st(1)
00477ab9  d9c9                     fxch      st(1)
00477abb  d8248dc0e5f400           fsub      dword ptr [ecx*4 + 0xf4e5c0]
00477ac2  dec9                     fmulp     st(1)
00477ac4  d8048dcce5f400           fadd      dword ptr [ecx*4 + 0xf4e5cc]
00477acb  8b45d4                   mov       eax, dword ptr [ebp - 0x2c]
00477ace  d8c8                     fmul      st(0)
00477ad0  d918                     fstp      dword ptr [eax]
00477ad2  b800000000               mov       eax, 0
00477ad7  5f                       pop       edi
00477ad8  5e                       pop       esi
00477ad9  5b                       pop       ebx
00477ada  8be5                     mov       esp, ebp
00477adc  5d                       pop       ebp
00477add  c3                       ret
00477ade  8bff                     mov       edi, edi
