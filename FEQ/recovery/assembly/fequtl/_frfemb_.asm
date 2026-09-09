; _frfemb_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x30000
00430000  55                       push      ebp
00430001  8bec                     mov       ebp, esp
00430003  b80c010000               mov       eax, 0x10c
00430008  e8f38f0b00               call      0x4e9000 ; __alloca_probe
0043000d  53                       push      ebx
0043000e  56                       push      esi
0043000f  57                       push      edi
00430010  8b5508                   mov       edx, dword ptr [ebp + 8]
00430013  8b5d0c                   mov       ebx, dword ptr [ebp + 0xc]
00430016  8b4510                   mov       eax, dword ptr [ebp + 0x10]
00430019  898518ffffff             mov       dword ptr [ebp - 0xe8], eax
0043001f  d903                     fld       dword ptr [ebx]
00430021  d802                     fadd      dword ptr [edx]
00430023  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
00430026  d910                     fst       dword ptr [eax]
00430028  d9ee                     fldz
0043002a  d9c0                     fld       st(0)
0043002c  d9c1                     fld       st(1)
0043002e  d9cb                     fxch      st(3)
00430030  db7dcc                   fstp      xword ptr [ebp - 0x34]
00430033  d9c9                     fxch      st(1)
00430035  dd5dc0                   fstp      qword ptr [ebp - 0x40]
00430038  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0043003b  8b08                     mov       ecx, dword ptr [eax]
0043003d  49                       dec       ecx
0043003e  83f900                   cmp       ecx, 0
00430041  898d14ffffff             mov       dword ptr [ebp - 0xec], ecx
00430047  0f8e31080000             jle       0x43087e
0043004d  bb01000000               mov       ebx, 1
00430052  db6dcc                   fld       xword ptr [ebp - 0x34]
00430055  d9ca                     fxch      st(2)
00430057  d9c9                     fxch      st(1)
00430059  b802000000               mov       eax, 2
0043005e  b908000000               mov       ecx, 8
00430063  898510ffffff             mov       dword ptr [ebp - 0xf0], eax
00430069  898d0cffffff             mov       dword ptr [ebp - 0xf4], ecx
0043006f  89da                     mov       edx, ebx
00430071  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00430074  d9ca                     fxch      st(2)
00430076  d85498fc                 fcom      dword ptr [eax + ebx*4 - 4]
0043007a  d9ca                     fxch      st(2)
0043007c  898508ffffff             mov       dword ptr [ebp - 0xf8], eax
00430082  dfe0                     fnstsw    ax
00430084  9e                       sahf
00430085  0f8ab0000000             jp        0x43013b
0043008b  0f86aa000000             jbe       0x43013b
00430091  8b8508ffffff             mov       eax, dword ptr [ebp - 0xf8]
00430097  8b8d10ffffff             mov       ecx, dword ptr [ebp - 0xf0]
0043009d  d9ca                     fxch      st(2)
0043009f  d85488fc                 fcom      dword ptr [eax + ecx*4 - 4]
004300a3  d9ca                     fxch      st(2)
004300a5  dfe0                     fnstsw    ax
004300a7  9e                       sahf
004300a8  0f8a8d000000             jp        0x43013b
004300ae  0f8687000000             jbe       0x43013b
004300b4  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004300b7  8b4c90fc                 mov       ecx, dword ptr [eax + edx*4 - 4]
004300bb  8b7550                   mov       esi, dword ptr [ebp + 0x50]
004300be  894c9efc                 mov       dword ptr [esi + ebx*4 - 4], ecx
004300c2  8b8d10ffffff             mov       ecx, dword ptr [ebp - 0xf0]
004300c8  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
004300cc  8b7554                   mov       esi, dword ptr [ebp + 0x54]
004300cf  89449efc                 mov       dword ptr [esi + ebx*4 - 4], eax
004300d3  8b8508ffffff             mov       eax, dword ptr [ebp - 0xf8]
004300d9  89c6                     mov       esi, eax
004300db  d9c2                     fld       st(2)
004300dd  d86496fc                 fsub      dword ptr [esi + edx*4 - 4]
004300e1  8b7558                   mov       esi, dword ptr [ebp + 0x58]
004300e4  d95c9efc                 fstp      dword ptr [esi + ebx*4 - 4]
004300e8  8b754c                   mov       esi, dword ptr [ebp + 0x4c]
004300eb  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
004300ef  d82e                     fsubr     dword ptr [esi]
004300f1  8b4560                   mov       eax, dword ptr [ebp + 0x60]
004300f4  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
004300f8  8b4530                   mov       eax, dword ptr [ebp + 0x30]
004300fb  8b7490fc                 mov       esi, dword ptr [eax + edx*4 - 4]
004300ff  8bbd88000000             mov       edi, dword ptr [ebp + 0x88]
00430105  89749ffc                 mov       dword ptr [edi + ebx*4 - 4], esi
00430109  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
0043010d  8bb590000000             mov       esi, dword ptr [ebp + 0x90]
00430113  89449efc                 mov       dword ptr [esi + ebx*4 - 4], eax
00430117  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
0043011a  8b7490fc                 mov       esi, dword ptr [eax + edx*4 - 4]
0043011e  8bbd94000000             mov       edi, dword ptr [ebp + 0x94]
00430124  89749ffc                 mov       dword ptr [edi + ebx*4 - 4], esi
00430128  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
0043012c  8bb59c000000             mov       esi, dword ptr [ebp + 0x9c]
00430132  89449efc                 mov       dword ptr [esi + ebx*4 - 4], eax
00430136  e947020000               jmp       0x430382
0043013b  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0043013e  d94490fc                 fld       dword ptr [eax + edx*4 - 4]
00430142  d9cb                     fxch      st(3)
00430144  d85490fc                 fcom      dword ptr [eax + edx*4 - 4]
00430148  d9cb                     fxch      st(3)
0043014a  d9ca                     fxch      st(2)
0043014c  d9c9                     fxch      st(1)
0043014e  898504ffffff             mov       dword ptr [ebp - 0xfc], eax
00430154  dfe0                     fnstsw    ax
00430156  9e                       sahf
00430157  0f8a06010000             jp        0x430263
0043015d  0f8600010000             jbe       0x430263
00430163  8b8504ffffff             mov       eax, dword ptr [ebp - 0xfc]
00430169  8b8d10ffffff             mov       ecx, dword ptr [ebp - 0xf0]
0043016f  d9cb                     fxch      st(3)
00430171  d85488fc                 fcom      dword ptr [eax + ecx*4 - 4]
00430175  d9cb                     fxch      st(3)
00430177  dfe0                     fnstsw    ax
00430179  9e                       sahf
0043017a  0f8ae3000000             jp        0x430263
00430180  0f87dd000000             ja        0x430263
00430186  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00430189  8b4c90fc                 mov       ecx, dword ptr [eax + edx*4 - 4]
0043018d  8b7550                   mov       esi, dword ptr [ebp + 0x50]
00430190  894c9efc                 mov       dword ptr [esi + ebx*4 - 4], ecx
00430194  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
00430197  8b7491fc                 mov       esi, dword ptr [ecx + edx*4 - 4]
0043019b  8bbd94000000             mov       edi, dword ptr [ebp + 0x94]
004301a1  89749ffc                 mov       dword ptr [edi + ebx*4 - 4], esi
004301a5  8b7530                   mov       esi, dword ptr [ebp + 0x30]
004301a8  8b7c96fc                 mov       edi, dword ptr [esi + edx*4 - 4]
004301ac  898500ffffff             mov       dword ptr [ebp - 0x100], eax
004301b2  8b8588000000             mov       eax, dword ptr [ebp + 0x88]
004301b8  897c98fc                 mov       dword ptr [eax + ebx*4 - 4], edi
004301bc  d9ca                     fxch      st(2)
004301be  d8eb                     fsubr     st(3)
004301c0  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004301c3  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
004301c7  8b8500ffffff             mov       eax, dword ptr [ebp - 0x100]
004301cd  d94490fc                 fld       dword ptr [eax + edx*4 - 4]
004301d1  8bbd10ffffff             mov       edi, dword ptr [ebp - 0xf0]
004301d7  d9c0                     fld       st(0)
004301d9  d86cb8fc                 fsubr     dword ptr [eax + edi*4 - 4]
004301dd  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
004301e0  898dfcfeffff             mov       dword ptr [ebp - 0x104], ecx
004301e6  8b8d04ffffff             mov       ecx, dword ptr [ebp - 0xfc]
004301ec  89b5f8feffff             mov       dword ptr [ebp - 0x108], esi
004301f2  89ce                     mov       esi, ecx
004301f4  d94496fc                 fld       dword ptr [esi + edx*4 - 4]
004301f8  d828                     fsubr     dword ptr [eax]
004301fa  d8c9                     fmul      st(1)
004301fc  89c8                     mov       eax, ecx
004301fe  d94491fc                 fld       dword ptr [ecx + edx*4 - 4]
00430202  d86cb8fc                 fsubr     dword ptr [eax + edi*4 - 4]
00430206  def9                     fdivp     st(1)
00430208  d8c2                     fadd      st(2)
0043020a  8b4554                   mov       eax, dword ptr [ebp + 0x54]
0043020d  d95498fc                 fst       dword ptr [eax + ebx*4 - 4]
00430211  dee2                     fsubrp    st(2)
00430213  8b85fcfeffff             mov       eax, dword ptr [ebp - 0x104]
00430219  def9                     fdivp     st(1)
0043021b  d94490fc                 fld       dword ptr [eax + edx*4 - 4]
0043021f  d9c0                     fld       st(0)
00430221  d86cb8fc                 fsubr     dword ptr [eax + edi*4 - 4]
00430225  d8ca                     fmul      st(2)
00430227  dec1                     faddp     st(1)
00430229  8b859c000000             mov       eax, dword ptr [ebp + 0x9c]
0043022f  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
00430233  8b85f8feffff             mov       eax, dword ptr [ebp - 0x108]
00430239  d94490fc                 fld       dword ptr [eax + edx*4 - 4]
0043023d  d9c0                     fld       st(0)
0043023f  d86cb8fc                 fsubr     dword ptr [eax + edi*4 - 4]
00430243  deca                     fmulp     st(2)
00430245  dec1                     faddp     st(1)
00430247  8b8590000000             mov       eax, dword ptr [ebp + 0x90]
0043024d  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
00430251  8b4560                   mov       eax, dword ptr [ebp + 0x60]
00430254  c74498fc00000000         mov       dword ptr [eax + ebx*4 - 4], 0
0043025c  d9c9                     fxch      st(1)
0043025e  e91f010000               jmp       0x430382
00430263  d9cb                     fxch      st(3)
00430265  d8d2                     fcom      st(2)
00430267  ddda                     fstp      st(2)
00430269  d9c9                     fxch      st(1)
0043026b  d9ca                     fxch      st(2)
0043026d  dfe0                     fnstsw    ax
0043026f  9e                       sahf
00430270  0f8af1000000             jp        0x430367
00430276  0f87eb000000             ja        0x430367
0043027c  8b8d10ffffff             mov       ecx, dword ptr [ebp - 0xf0]
00430282  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00430285  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
00430289  d9cb                     fxch      st(3)
0043028b  d85488fc                 fcom      dword ptr [eax + ecx*4 - 4]
0043028f  d9cb                     fxch      st(3)
00430291  db7db4                   fstp      xword ptr [ebp - 0x4c]
00430294  8985f4feffff             mov       dword ptr [ebp - 0x10c], eax
0043029a  dfe0                     fnstsw    ax
0043029c  9e                       sahf
0043029d  0f8ac4000000             jp        0x430367
004302a3  0f86be000000             jbe       0x430367
004302a9  db6db4                   fld       xword ptr [ebp - 0x4c]
004302ac  d8eb                     fsubr     st(3)
004302ae  8b8d10ffffff             mov       ecx, dword ptr [ebp - 0xf0]
004302b4  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004302b7  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
004302bb  d9c0                     fld       st(0)
004302bd  d86c90fc                 fsubr     dword ptr [eax + edx*4 - 4]
004302c1  dcca                     fmul      st(2), st(0)
004302c3  db6db4                   fld       xword ptr [ebp - 0x4c]
004302c6  8b85f4feffff             mov       eax, dword ptr [ebp - 0x10c]
004302cc  d86c90fc                 fsubr     dword ptr [eax + edx*4 - 4]
004302d0  defb                     fdivp     st(3)
004302d2  d9ca                     fxch      st(2)
004302d4  d8c1                     fadd      st(1)
004302d6  8b4550                   mov       eax, dword ptr [ebp + 0x50]
004302d9  d95498fc                 fst       dword ptr [eax + ebx*4 - 4]
004302dd  dee1                     fsubrp    st(1)
004302df  def1                     fdivrp    st(1)
004302e1  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
004302e4  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
004302e8  d9c0                     fld       st(0)
004302ea  d86c90fc                 fsubr     dword ptr [eax + edx*4 - 4]
004302ee  d8ca                     fmul      st(2)
004302f0  dec1                     faddp     st(1)
004302f2  8b8594000000             mov       eax, dword ptr [ebp + 0x94]
004302f8  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
004302fc  8b4530                   mov       eax, dword ptr [ebp + 0x30]
004302ff  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
00430303  d9c0                     fld       st(0)
00430305  d86c90fc                 fsubr     dword ptr [eax + edx*4 - 4]
00430309  deca                     fmulp     st(2)
0043030b  dec1                     faddp     st(1)
0043030d  8b8588000000             mov       eax, dword ptr [ebp + 0x88]
00430313  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
00430317  8b4558                   mov       eax, dword ptr [ebp + 0x58]
0043031a  c74498fc00000000         mov       dword ptr [eax + ebx*4 - 4], 0
00430322  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00430325  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
00430329  8b7554                   mov       esi, dword ptr [ebp + 0x54]
0043032c  89449efc                 mov       dword ptr [esi + ebx*4 - 4], eax
00430330  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
00430333  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
00430337  8bb59c000000             mov       esi, dword ptr [ebp + 0x9c]
0043033d  89449efc                 mov       dword ptr [esi + ebx*4 - 4], eax
00430341  8b4530                   mov       eax, dword ptr [ebp + 0x30]
00430344  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
00430348  8bb590000000             mov       esi, dword ptr [ebp + 0x90]
0043034e  89449efc                 mov       dword ptr [esi + ebx*4 - 4], eax
00430352  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
00430355  8b7528                   mov       esi, dword ptr [ebp + 0x28]
00430358  d9448efc                 fld       dword ptr [esi + ecx*4 - 4]
0043035c  d828                     fsubr     dword ptr [eax]
0043035e  8b4560                   mov       eax, dword ptr [ebp + 0x60]
00430361  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
00430365  eb1b                     jmp       0x430382
00430367  8b4558                   mov       eax, dword ptr [ebp + 0x58]
0043036a  c74498fc000080bf         mov       dword ptr [eax + ebx*4 - 4], 0xbf800000
00430372  8b4560                   mov       eax, dword ptr [ebp + 0x60]
00430375  c74498fc000080bf         mov       dword ptr [eax + ebx*4 - 4], 0xbf800000
0043037d  e9dd040000               jmp       0x43085f
00430382  dd9d60ffffff             fstp      qword ptr [ebp - 0xa0]
00430388  dd9d58ffffff             fstp      qword ptr [ebp - 0xa8]
0043038e  dbbd4cffffff             fstp      xword ptr [ebp - 0xb4]
00430394  8b4560                   mov       eax, dword ptr [ebp + 0x60]
00430397  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
0043039b  8b4d58                   mov       ecx, dword ptr [ebp + 0x58]
0043039e  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
004303a2  d9c0                     fld       st(0)
004303a4  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
004303a8  8d15d0d05600             lea       edx, [0x56d0d0] ; bits=31110000, f32=6.16711454149352e-42
004303ae  d94298                   fld       dword ptr [edx - 0x68]
004303b1  d9c9                     fxch      st(1)
004303b3  d84a98                   fmul      dword ptr [edx - 0x68]
004303b6  8b455c                   mov       eax, dword ptr [ebp + 0x5c]
004303b9  d95498fc                 fst       dword ptr [eax + ebx*4 - 4]
004303bd  8b859c000000             mov       eax, dword ptr [ebp + 0x9c]
004303c3  8b8d94000000             mov       ecx, dword ptr [ebp + 0x94]
004303c9  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
004303cd  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
004303d1  d8ca                     fmul      st(2)
004303d3  8b8598000000             mov       eax, dword ptr [ebp + 0x98]
004303d9  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
004303dd  8b8588000000             mov       eax, dword ptr [ebp + 0x88]
004303e3  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
004303e7  8b8d90000000             mov       ecx, dword ptr [ebp + 0x90]
004303ed  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
004303f1  d9c0                     fld       st(0)
004303f3  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
004303f7  decc                     fmulp     st(4)
004303f9  8b858c000000             mov       eax, dword ptr [ebp + 0x8c]
004303ff  d9cb                     fxch      st(3)
00430401  d95498fc                 fst       dword ptr [eax + ebx*4 - 4]
00430405  d9cc                     fxch      st(4)
00430407  db7da8                   fstp      xword ptr [ebp - 0x58]
0043040a  db7d9c                   fstp      xword ptr [ebp - 0x64]
0043040d  db7d90                   fstp      xword ptr [ebp - 0x70]
00430410  d9c9                     fxch      st(1)
00430412  db7d84                   fstp      xword ptr [ebp - 0x7c]
00430415  d9c9                     fxch      st(1)
00430417  dbbd78ffffff             fstp      xword ptr [ebp - 0x88]
0043041d  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
00430423  dbad4cffffff             fld       xword ptr [ebp - 0xb4]
00430429  dd8558ffffff             fld       qword ptr [ebp - 0xa8]
0043042f  dd8560ffffff             fld       qword ptr [ebp - 0xa0]
00430435  8b8d0cffffff             mov       ecx, dword ptr [ebp - 0xf4]
0043043b  8b4534                   mov       eax, dword ptr [ebp + 0x34]
0043043e  8d7408f8                 lea       esi, [eax + ecx - 8]
00430442  8d7a70                   lea       edi, [edx + 0x70]
00430445  b808000000               mov       eax, 8
0043044a  89c1                     mov       ecx, eax
0043044c  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0043044e  7521                     jne       0x430471
00430450  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00430453  8b00                     mov       eax, dword ptr [eax]
00430455  894278                   mov       dword ptr [edx + 0x78], eax
00430458  8b8518ffffff             mov       eax, dword ptr [ebp - 0xe8]
0043045e  8b08                     mov       ecx, dword ptr [eax]
00430460  894a7c                   mov       dword ptr [edx + 0x7c], ecx
00430463  8b0d20b2e900             mov       ecx, dword ptr [0xe9b220] ; _subcom_
00430469  890d68d15600             mov       dword ptr [0x56d168], ecx ; bits=00000000, f32=0.0
0043046f  eb20                     jmp       0x430491
00430471  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00430474  8b00                     mov       eax, dword ptr [eax]
00430476  89d1                     mov       ecx, edx
00430478  894178                   mov       dword ptr [ecx + 0x78], eax
0043047b  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0043047e  8b00                     mov       eax, dword ptr [eax]
00430480  89d1                     mov       ecx, edx
00430482  89417c                   mov       dword ptr [ecx + 0x7c], eax
00430485  8b0524b2e900             mov       eax, dword ptr [0xe9b224]
0043048b  890568d15600             mov       dword ptr [0x56d168], eax ; bits=00000000, f32=0.0
00430491  db6da8                   fld       xword ptr [ebp - 0x58]
00430494  d81d5cd05600             fcomp     dword ptr [0x56d05c] ; bits=00000000, f32=0.0
0043049a  dfe0                     fnstsw    ax
0043049c  9e                       sahf
0043049d  0f8a28000000             jp        0x4304cb
004304a3  7726                     ja        0x4304cb
004304a5  8b4564                   mov       eax, dword ptr [ebp + 0x64]
004304a8  c74498fc00000000         mov       dword ptr [eax + ebx*4 - 4], 0
004304b0  8b4570                   mov       eax, dword ptr [ebp + 0x70]
004304b3  c74498fc00000000         mov       dword ptr [eax + ebx*4 - 4], 0
004304bb  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
004304be  c74498fc0000803f         mov       dword ptr [eax + ebx*4 - 4], 0x3f800000
004304c6  e98e000000               jmp       0x430559
004304cb  db7dd8                   fstp      xword ptr [ebp - 0x28]
004304ce  db7de4                   fstp      xword ptr [ebp - 0x1c]
004304d1  db7df0                   fstp      xword ptr [ebp - 0x10]
004304d4  db6df0                   fld       xword ptr [ebp - 0x10]
004304d7  db6d9c                   fld       xword ptr [ebp - 0x64]
004304da  dee9                     fsubp     st(1)
004304dc  d91d50d15600             fstp      dword ptr [0x56d150] ; bits=00000000, f32=0.0
004304e2  8b85a0000000             mov       eax, dword ptr [ebp + 0xa0]
004304e8  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004304ec  50                       push      eax
004304ed  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
004304f0  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004304f4  50                       push      eax
004304f5  8b4570                   mov       eax, dword ptr [ebp + 0x70]
004304f8  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004304fc  50                       push      eax
004304fd  8b4564                   mov       eax, dword ptr [ebp + 0x64]
00430500  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
00430504  50                       push      eax
00430505  8b4548                   mov       eax, dword ptr [ebp + 0x48]
00430508  8d00                     lea       eax, [eax]
0043050a  50                       push      eax
0043050b  8b4544                   mov       eax, dword ptr [ebp + 0x44]
0043050e  8d00                     lea       eax, [eax]
00430510  50                       push      eax
00430511  6850d15600               push      0x56d150
00430516  8b4558                   mov       eax, dword ptr [ebp + 0x58]
00430519  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
0043051d  50                       push      eax
0043051e  8b8594000000             mov       eax, dword ptr [ebp + 0x94]
00430524  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
00430528  50                       push      eax
00430529  6868d15600               push      0x56d168
0043052e  8b4540                   mov       eax, dword ptr [ebp + 0x40]
00430531  8d00                     lea       eax, [eax]
00430533  50                       push      eax
00430534  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
00430537  8d00                     lea       eax, [eax]
00430539  50                       push      eax
0043053a  8d05d0d05600             lea       eax, [0x56d0d0] ; bits=31110000, f32=6.16711454149352e-42
00430540  8d487c                   lea       ecx, [eax + 0x7c]
00430543  51                       push      ecx
00430544  8d4078                   lea       eax, [eax + 0x78]
00430547  50                       push      eax
00430548  e8e3ecffff               call      0x42f230 ; _ftothq_
0043054d  db6df0                   fld       xword ptr [ebp - 0x10]
00430550  db6de4                   fld       xword ptr [ebp - 0x1c]
00430553  db6dd8                   fld       xword ptr [ebp - 0x28]
00430556  83c438                   add       esp, 0x38
00430559  db6d90                   fld       xword ptr [ebp - 0x70]
0043055c  d81d5cd05600             fcomp     dword ptr [0x56d05c] ; bits=00000000, f32=0.0
00430562  dfe0                     fnstsw    ax
00430564  9e                       sahf
00430565  0f8a2b000000             jp        0x430596
0043056b  7729                     ja        0x430596
0043056d  8b4568                   mov       eax, dword ptr [ebp + 0x68]
00430570  c74498fc00000000         mov       dword ptr [eax + ebx*4 - 4], 0
00430578  8b4574                   mov       eax, dword ptr [ebp + 0x74]
0043057b  c74498fc00000000         mov       dword ptr [eax + ebx*4 - 4], 0
00430583  8b8580000000             mov       eax, dword ptr [ebp + 0x80]
00430589  c74498fc0000803f         mov       dword ptr [eax + ebx*4 - 4], 0x3f800000
00430591  e991000000               jmp       0x430627
00430596  db7dd8                   fstp      xword ptr [ebp - 0x28]
00430599  db7de4                   fstp      xword ptr [ebp - 0x1c]
0043059c  db7df0                   fstp      xword ptr [ebp - 0x10]
0043059f  db6df0                   fld       xword ptr [ebp - 0x10]
004305a2  db6d84                   fld       xword ptr [ebp - 0x7c]
004305a5  dee9                     fsubp     st(1)
004305a7  d91d50d15600             fstp      dword ptr [0x56d150] ; bits=00000000, f32=0.0
004305ad  8b85a4000000             mov       eax, dword ptr [ebp + 0xa4]
004305b3  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004305b7  50                       push      eax
004305b8  8b8580000000             mov       eax, dword ptr [ebp + 0x80]
004305be  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004305c2  50                       push      eax
004305c3  8b4574                   mov       eax, dword ptr [ebp + 0x74]
004305c6  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004305ca  50                       push      eax
004305cb  8b4568                   mov       eax, dword ptr [ebp + 0x68]
004305ce  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004305d2  50                       push      eax
004305d3  8b4548                   mov       eax, dword ptr [ebp + 0x48]
004305d6  8d00                     lea       eax, [eax]
004305d8  50                       push      eax
004305d9  8b4544                   mov       eax, dword ptr [ebp + 0x44]
004305dc  8d00                     lea       eax, [eax]
004305de  50                       push      eax
004305df  6850d15600               push      0x56d150
004305e4  8b455c                   mov       eax, dword ptr [ebp + 0x5c]
004305e7  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004305eb  50                       push      eax
004305ec  8b8598000000             mov       eax, dword ptr [ebp + 0x98]
004305f2  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004305f6  50                       push      eax
004305f7  6868d15600               push      0x56d168
004305fc  8b4540                   mov       eax, dword ptr [ebp + 0x40]
004305ff  8d00                     lea       eax, [eax]
00430601  50                       push      eax
00430602  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
00430605  8d00                     lea       eax, [eax]
00430607  50                       push      eax
00430608  8d05d0d05600             lea       eax, [0x56d0d0] ; bits=31110000, f32=6.16711454149352e-42
0043060e  8d487c                   lea       ecx, [eax + 0x7c]
00430611  51                       push      ecx
00430612  8d4078                   lea       eax, [eax + 0x78]
00430615  50                       push      eax
00430616  e815ecffff               call      0x42f230 ; _ftothq_
0043061b  db6df0                   fld       xword ptr [ebp - 0x10]
0043061e  db6de4                   fld       xword ptr [ebp - 0x1c]
00430621  db6dd8                   fld       xword ptr [ebp - 0x28]
00430624  83c438                   add       esp, 0x38
00430627  dbad78ffffff             fld       xword ptr [ebp - 0x88]
0043062d  d81d5cd05600             fcomp     dword ptr [0x56d05c] ; bits=00000000, f32=0.0
00430633  dfe0                     fnstsw    ax
00430635  9e                       sahf
00430636  0f8a2b000000             jp        0x430667
0043063c  7729                     ja        0x430667
0043063e  8b456c                   mov       eax, dword ptr [ebp + 0x6c]
00430641  c74498fc00000000         mov       dword ptr [eax + ebx*4 - 4], 0
00430649  8b4578                   mov       eax, dword ptr [ebp + 0x78]
0043064c  c74498fc00000000         mov       dword ptr [eax + ebx*4 - 4], 0
00430654  8b8584000000             mov       eax, dword ptr [ebp + 0x84]
0043065a  c74498fc0000803f         mov       dword ptr [eax + ebx*4 - 4], 0x3f800000
00430662  e994000000               jmp       0x4306fb
00430667  db7dd8                   fstp      xword ptr [ebp - 0x28]
0043066a  db7de4                   fstp      xword ptr [ebp - 0x1c]
0043066d  db7df0                   fstp      xword ptr [ebp - 0x10]
00430670  db6df0                   fld       xword ptr [ebp - 0x10]
00430673  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00430679  dee9                     fsubp     st(1)
0043067b  d91d50d15600             fstp      dword ptr [0x56d150] ; bits=00000000, f32=0.0
00430681  8b85a8000000             mov       eax, dword ptr [ebp + 0xa8]
00430687  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
0043068b  50                       push      eax
0043068c  8b8584000000             mov       eax, dword ptr [ebp + 0x84]
00430692  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
00430696  50                       push      eax
00430697  8b4578                   mov       eax, dword ptr [ebp + 0x78]
0043069a  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
0043069e  50                       push      eax
0043069f  8b456c                   mov       eax, dword ptr [ebp + 0x6c]
004306a2  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004306a6  50                       push      eax
004306a7  8b4548                   mov       eax, dword ptr [ebp + 0x48]
004306aa  8d00                     lea       eax, [eax]
004306ac  50                       push      eax
004306ad  8b4544                   mov       eax, dword ptr [ebp + 0x44]
004306b0  8d00                     lea       eax, [eax]
004306b2  50                       push      eax
004306b3  6850d15600               push      0x56d150
004306b8  8b4560                   mov       eax, dword ptr [ebp + 0x60]
004306bb  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004306bf  50                       push      eax
004306c0  8b859c000000             mov       eax, dword ptr [ebp + 0x9c]
004306c6  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004306ca  50                       push      eax
004306cb  6868d15600               push      0x56d168
004306d0  8b4540                   mov       eax, dword ptr [ebp + 0x40]
004306d3  8d00                     lea       eax, [eax]
004306d5  50                       push      eax
004306d6  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
004306d9  8d00                     lea       eax, [eax]
004306db  50                       push      eax
004306dc  8d05d0d05600             lea       eax, [0x56d0d0] ; bits=31110000, f32=6.16711454149352e-42
004306e2  8d487c                   lea       ecx, [eax + 0x7c]
004306e5  51                       push      ecx
004306e6  8d4078                   lea       eax, [eax + 0x78]
004306e9  50                       push      eax
004306ea  e841ebffff               call      0x42f230 ; _ftothq_
004306ef  db6df0                   fld       xword ptr [ebp - 0x10]
004306f2  db6de4                   fld       xword ptr [ebp - 0x1c]
004306f5  db6dd8                   fld       xword ptr [ebp - 0x28]
004306f8  83c438                   add       esp, 0x38
004306fb  d9ca                     fxch      st(2)
004306fd  dbbd1cffffff             fstp      xword ptr [ebp - 0xe4]
00430703  dd9d28ffffff             fstp      qword ptr [ebp - 0xd8]
00430709  dd9d58ffffff             fstp      qword ptr [ebp - 0xa8]
0043070f  dd45c0                   fld       qword ptr [ebp - 0x40]
00430712  dd9d60ffffff             fstp      qword ptr [ebp - 0xa0]
00430718  8b4554                   mov       eax, dword ptr [ebp + 0x54]
0043071b  8b4d50                   mov       ecx, dword ptr [ebp + 0x50]
0043071e  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
00430722  d86c98fc                 fsubr     dword ptr [eax + ebx*4 - 4]
00430726  d9e1                     fabs
00430728  dbbd34ffffff             fstp      xword ptr [ebp - 0xcc]
0043072e  8b4568                   mov       eax, dword ptr [ebp + 0x68]
00430731  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
00430735  dbbd40ffffff             fstp      xword ptr [ebp - 0xc0]
0043073b  8d0dd0d05600             lea       ecx, [0x56d0d0] ; bits=31110000, f32=6.16711454149352e-42
00430741  d9419c                   fld       dword ptr [ecx - 0x64]
00430744  d9c0                     fld       st(0)
00430746  d84c98fc                 fmul      dword ptr [eax + ebx*4 - 4]
0043074a  8b5564                   mov       edx, dword ptr [ebp + 0x64]
0043074d  d9449afc                 fld       dword ptr [edx + ebx*4 - 4]
00430751  d9c1                     fld       st(1)
00430753  d8449afc                 fadd      dword ptr [edx + ebx*4 - 4]
00430757  8b756c                   mov       esi, dword ptr [ebp + 0x6c]
0043075a  d9449efc                 fld       dword ptr [esi + ebx*4 - 4]
0043075e  d9c9                     fxch      st(1)
00430760  d8449efc                 fadd      dword ptr [esi + ebx*4 - 4]
00430764  dbad34ffffff             fld       xword ptr [ebp - 0xcc]
0043076a  dec9                     fmulp     st(1)
0043076c  d84988                   fmul      dword ptr [ecx - 0x78]
0043076f  dbbd4cffffff             fstp      xword ptr [ebp - 0xb4]
00430775  d9c1                     fld       st(1)
00430777  d84c9afc                 fmul      dword ptr [edx + ebx*4 - 4]
0043077b  8b557c                   mov       edx, dword ptr [ebp + 0x7c]
0043077e  d8749afc                 fdiv      dword ptr [edx + ebx*4 - 4]
00430782  dbad40ffffff             fld       xword ptr [ebp - 0xc0]
00430788  d84c98fc                 fmul      dword ptr [eax + ebx*4 - 4]
0043078c  decd                     fmulp     st(5)
0043078e  8b8580000000             mov       eax, dword ptr [ebp + 0x80]
00430794  d9cc                     fxch      st(4)
00430796  d87498fc                 fdiv      dword ptr [eax + ebx*4 - 4]
0043079a  dec4                     faddp     st(4)
0043079c  d9c0                     fld       st(0)
0043079e  d84c9efc                 fmul      dword ptr [esi + ebx*4 - 4]
004307a2  8bb584000000             mov       esi, dword ptr [ebp + 0x84]
004307a8  d8749efc                 fdiv      dword ptr [esi + ebx*4 - 4]
004307ac  dec4                     faddp     st(4)
004307ae  dbad34ffffff             fld       xword ptr [ebp - 0xcc]
004307b4  decc                     fmulp     st(4)
004307b6  d9cb                     fxch      st(3)
004307b8  d84988                   fmul      dword ptr [ecx - 0x78]
004307bb  d9c1                     fld       st(1)
004307bd  d8749afc                 fdiv      dword ptr [edx + ebx*4 - 4]
004307c1  d8c8                     fmul      st(0)
004307c3  d83534bcf400             fdiv      dword ptr [0xf4bc34]
004307c9  8b7d4c                   mov       edi, dword ptr [ebp + 0x4c]
004307cc  d907                     fld       dword ptr [edi]
004307ce  d9c0                     fld       st(0)
004307d0  d8449afc                 fadd      dword ptr [edx + ebx*4 - 4]
004307d4  8b5558                   mov       edx, dword ptr [ebp + 0x58]
004307d7  d8649afc                 fsub      dword ptr [edx + ebx*4 - 4]
004307db  dec2                     faddp     st(2)
004307dd  d9cb                     fxch      st(3)
004307df  dec9                     fmulp     st(1)
004307e1  dbad40ffffff             fld       xword ptr [ebp - 0xc0]
004307e7  d87498fc                 fdiv      dword ptr [eax + ebx*4 - 4]
004307eb  d8c8                     fmul      st(0)
004307ed  d83534bcf400             fdiv      dword ptr [0xf4bc34]
004307f3  d9c3                     fld       st(3)
004307f5  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
004307f9  8b455c                   mov       eax, dword ptr [ebp + 0x5c]
004307fc  d86498fc                 fsub      dword ptr [eax + ebx*4 - 4]
00430800  dec1                     faddp     st(1)
00430802  decc                     fmulp     st(4)
00430804  dec3                     faddp     st(3)
00430806  d9c3                     fld       st(3)
00430808  d8749efc                 fdiv      dword ptr [esi + ebx*4 - 4]
0043080c  d8c8                     fmul      st(0)
0043080e  d83534bcf400             fdiv      dword ptr [0xf4bc34]
00430814  d9ca                     fxch      st(2)
00430816  d8449efc                 fadd      dword ptr [esi + ebx*4 - 4]
0043081a  8b4560                   mov       eax, dword ptr [ebp + 0x60]
0043081d  d86498fc                 fsub      dword ptr [eax + ebx*4 - 4]
00430821  dec2                     faddp     st(2)
00430823  d9cb                     fxch      st(3)
00430825  dec9                     fmulp     st(1)
00430827  dec1                     faddp     st(1)
00430829  dbad34ffffff             fld       xword ptr [ebp - 0xcc]
0043082f  dec9                     fmulp     st(1)
00430831  d84988                   fmul      dword ptr [ecx - 0x78]
00430834  dbad4cffffff             fld       xword ptr [ebp - 0xb4]
0043083a  dc8560ffffff             fadd      qword ptr [ebp - 0xa0]
00430840  d9ca                     fxch      st(2)
00430842  dc8558ffffff             fadd      qword ptr [ebp - 0xa8]
00430848  d9c9                     fxch      st(1)
0043084a  dc8528ffffff             fadd      qword ptr [ebp - 0xd8]
00430850  d9ca                     fxch      st(2)
00430852  dd5dc0                   fstp      qword ptr [ebp - 0x40]
00430855  dbad1cffffff             fld       xword ptr [ebp - 0xe4]
0043085b  d9ca                     fxch      st(2)
0043085d  d9c9                     fxch      st(1)
0043085f  43                       inc       ebx
00430860  83850cffffff08           add       dword ptr [ebp - 0xf4], 8
00430867  ff8510ffffff             inc       dword ptr [ebp - 0xf0]
0043086d  83ad14ffffff01           sub       dword ptr [ebp - 0xec], 1
00430874  0f85f5f7ffff             jne       0x43006f
0043087a  ddda                     fstp      st(2)
0043087c  d9c9                     fxch      st(1)
0043087e  dd45c0                   fld       qword ptr [ebp - 0x40]
00430881  d95dfc                   fstp      dword ptr [ebp - 4]
00430884  8b45fc                   mov       eax, dword ptr [ebp - 4]
00430887  8b8dac000000             mov       ecx, dword ptr [ebp + 0xac]
0043088d  8901                     mov       dword ptr [ecx], eax
0043088f  8b4538                   mov       eax, dword ptr [ebp + 0x38]
00430892  d900                     fld       dword ptr [eax]
00430894  dec9                     fmulp     st(1)
00430896  d95dfc                   fstp      dword ptr [ebp - 4]
00430899  8b45fc                   mov       eax, dword ptr [ebp - 4]
0043089c  8b8db0000000             mov       ecx, dword ptr [ebp + 0xb0]
004308a2  8901                     mov       dword ptr [ecx], eax
004308a4  d95dfc                   fstp      dword ptr [ebp - 4]
004308a7  8b45fc                   mov       eax, dword ptr [ebp - 4]
004308aa  8b8db4000000             mov       ecx, dword ptr [ebp + 0xb4]
004308b0  8901                     mov       dword ptr [ecx], eax
004308b2  b800000000               mov       eax, 0
004308b7  5f                       pop       edi
004308b8  5e                       pop       esi
004308b9  5b                       pop       ebx
004308ba  8be5                     mov       esp, ebp
004308bc  5d                       pop       ebp
004308bd  c3                       ret
004308be  8bff                     mov       edi, edi
