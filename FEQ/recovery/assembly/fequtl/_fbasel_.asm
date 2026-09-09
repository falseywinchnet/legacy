; _fbasel_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x96250
00496250  55                       push      ebp
00496251  8bec                     mov       ebp, esp
00496253  b83c030000               mov       eax, 0x33c
00496258  e8a32d0500               call      0x4e9000 ; __alloca_probe
0049625d  53                       push      ebx
0049625e  56                       push      esi
0049625f  57                       push      edi
00496260  8b4508                   mov       eax, dword ptr [ebp + 8]
00496263  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00496266  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00496269  89852cfdffff             mov       dword ptr [ebp - 0x2d4], eax
0049626f  898d28fdffff             mov       dword ptr [ebp - 0x2d8], ecx
00496275  899524fdffff             mov       dword ptr [ebp - 0x2dc], edx
0049627b  8b4540                   mov       eax, dword ptr [ebp + 0x40]
0049627e  8d30                     lea       esi, [eax]
00496280  8d3d6c955b00             lea       edi, [0x5b956c] ; bits=4e455742, f32=53.81768035888672
00496286  b907000000               mov       ecx, 7
0049628b  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0049628d  898520fdffff             mov       dword ptr [ebp - 0x2e0], eax
00496293  7534                     jne       0x4962c9
00496295  b801000000               mov       eax, 1
0049629a  8b8d20fdffff             mov       ecx, dword ptr [ebp - 0x2e0]
004962a0  8d5107                   lea       edx, [ecx + 7]
004962a3  803a58                   cmp       byte ptr [edx], 0x58
004962a6  89851cfdffff             mov       dword ptr [ebp - 0x2e4], eax
004962ac  750e                     jne       0x4962bc
004962ae  8b851cfdffff             mov       eax, dword ptr [ebp - 0x2e4]
004962b4  898518fdffff             mov       dword ptr [ebp - 0x2e8], eax
004962ba  eb1e                     jmp       0x4962da
004962bc  b800000000               mov       eax, 0
004962c1  898518fdffff             mov       dword ptr [ebp - 0x2e8], eax
004962c7  eb11                     jmp       0x4962da
004962c9  b800000000               mov       eax, 0
004962ce  898518fdffff             mov       dword ptr [ebp - 0x2e8], eax
004962d4  89851cfdffff             mov       dword ptr [ebp - 0x2e4], eax
004962da  8b455c                   mov       eax, dword ptr [ebp + 0x5c]
004962dd  c70000000000             mov       dword ptr [eax], 0
004962e3  c7400400000000           mov       dword ptr [eax + 4], 0
004962ea  8b4560                   mov       eax, dword ptr [ebp + 0x60]
004962ed  c70000000000             mov       dword ptr [eax], 0
004962f3  c7400400000000           mov       dword ptr [eax + 4], 0
004962fa  8b4564                   mov       eax, dword ptr [ebp + 0x64]
004962fd  c70000000000             mov       dword ptr [eax], 0
00496303  c7400400000000           mov       dword ptr [eax + 4], 0
0049630a  8b4568                   mov       eax, dword ptr [ebp + 0x68]
0049630d  c70000000000             mov       dword ptr [eax], 0
00496313  c7400400000000           mov       dword ptr [eax + 4], 0
0049631a  8b456c                   mov       eax, dword ptr [ebp + 0x6c]
0049631d  c70000000000             mov       dword ptr [eax], 0
00496323  c7400400000000           mov       dword ptr [eax + 4], 0
0049632a  8b4570                   mov       eax, dword ptr [ebp + 0x70]
0049632d  c70000000000             mov       dword ptr [eax], 0
00496333  c7400400000000           mov       dword ptr [eax + 4], 0
0049633a  8b4574                   mov       eax, dword ptr [ebp + 0x74]
0049633d  c70000000000             mov       dword ptr [eax], 0
00496343  c7400400000000           mov       dword ptr [eax + 4], 0
0049634a  8b4578                   mov       eax, dword ptr [ebp + 0x78]
0049634d  c70000000000             mov       dword ptr [eax], 0
00496353  c7400400000000           mov       dword ptr [eax + 4], 0
0049635a  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0049635d  8b08                     mov       ecx, dword ptr [eax]
0049635f  89c8                     mov       eax, ecx
00496361  3d00000000               cmp       eax, 0
00496366  898514fdffff             mov       dword ptr [ebp - 0x2ec], eax
0049636c  898d10fdffff             mov       dword ptr [ebp - 0x2f0], ecx
00496372  0f8ec0010000             jle       0x496538
00496378  b801000000               mov       eax, 1
0049637d  83bd14fdffff02           cmp       dword ptr [ebp - 0x2ec], 2
00496384  89850cfdffff             mov       dword ptr [ebp - 0x2f4], eax
0049638a  0f8c18010000             jl        0x4964a8
00496390  8b8d0cfdffff             mov       ecx, dword ptr [ebp - 0x2f4]
00496396  8b4548                   mov       eax, dword ptr [ebp + 0x48]
00496399  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
004963a1  8b4550                   mov       eax, dword ptr [ebp + 0x50]
004963a4  c744c8f800000000         mov       dword ptr [eax + ecx*8 - 8], 0
004963ac  c744c8fc00000000         mov       dword ptr [eax + ecx*8 - 4], 0
004963b4  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
004963b7  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
004963bf  8b4554                   mov       eax, dword ptr [ebp + 0x54]
004963c2  c744c8f800000000         mov       dword ptr [eax + ecx*8 - 8], 0
004963ca  c744c8fc00000000         mov       dword ptr [eax + ecx*8 - 4], 0
004963d2  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004963d5  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
004963dd  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
004963e0  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
004963e8  8b8580000000             mov       eax, dword ptr [ebp + 0x80]
004963ee  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
004963f6  8b8584000000             mov       eax, dword ptr [ebp + 0x84]
004963fc  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
00496404  8b8588000000             mov       eax, dword ptr [ebp + 0x88]
0049640a  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
00496412  8b4548                   mov       eax, dword ptr [ebp + 0x48]
00496415  c7048800000000           mov       dword ptr [eax + ecx*4], 0
0049641c  8b4550                   mov       eax, dword ptr [ebp + 0x50]
0049641f  c704c800000000           mov       dword ptr [eax + ecx*8], 0
00496426  c744c80400000000         mov       dword ptr [eax + ecx*8 + 4], 0
0049642e  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
00496431  c7048800000000           mov       dword ptr [eax + ecx*4], 0
00496438  8b4554                   mov       eax, dword ptr [ebp + 0x54]
0049643b  c704c800000000           mov       dword ptr [eax + ecx*8], 0
00496442  c744c80400000000         mov       dword ptr [eax + ecx*8 + 4], 0
0049644a  8b4558                   mov       eax, dword ptr [ebp + 0x58]
0049644d  c7048800000000           mov       dword ptr [eax + ecx*4], 0
00496454  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
00496457  c7048800000000           mov       dword ptr [eax + ecx*4], 0
0049645e  8b8580000000             mov       eax, dword ptr [ebp + 0x80]
00496464  c7048800000000           mov       dword ptr [eax + ecx*4], 0
0049646b  8b8584000000             mov       eax, dword ptr [ebp + 0x84]
00496471  c7048800000000           mov       dword ptr [eax + ecx*4], 0
00496478  8b8588000000             mov       eax, dword ptr [ebp + 0x88]
0049647e  c7048800000000           mov       dword ptr [eax + ecx*4], 0
00496485  83c102                   add       ecx, 2
00496488  8b8514fdffff             mov       eax, dword ptr [ebp - 0x2ec]
0049648e  83e802                   sub       eax, 2
00496491  3d02000000               cmp       eax, 2
00496496  898514fdffff             mov       dword ptr [ebp - 0x2ec], eax
0049649c  898d0cfdffff             mov       dword ptr [ebp - 0x2f4], ecx
004964a2  0f8de8feffff             jge       0x496390
004964a8  8b8514fdffff             mov       eax, dword ptr [ebp - 0x2ec]
004964ae  85c0                     test      eax, eax
004964b0  0f8482000000             je        0x496538
004964b6  8b8d0cfdffff             mov       ecx, dword ptr [ebp - 0x2f4]
004964bc  8b4548                   mov       eax, dword ptr [ebp + 0x48]
004964bf  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
004964c7  8b4550                   mov       eax, dword ptr [ebp + 0x50]
004964ca  c744c8f800000000         mov       dword ptr [eax + ecx*8 - 8], 0
004964d2  c744c8fc00000000         mov       dword ptr [eax + ecx*8 - 4], 0
004964da  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
004964dd  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
004964e5  8b4554                   mov       eax, dword ptr [ebp + 0x54]
004964e8  c744c8f800000000         mov       dword ptr [eax + ecx*8 - 8], 0
004964f0  c744c8fc00000000         mov       dword ptr [eax + ecx*8 - 4], 0
004964f8  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004964fb  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
00496503  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
00496506  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
0049650e  8b8580000000             mov       eax, dword ptr [ebp + 0x80]
00496514  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
0049651c  8b8584000000             mov       eax, dword ptr [ebp + 0x84]
00496522  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
0049652a  8b8588000000             mov       eax, dword ptr [ebp + 0x88]
00496530  c74488fc00000000         mov       dword ptr [eax + ecx*4 - 4], 0
00496538  b800000000               mov       eax, 0
0049653d  898508fdffff             mov       dword ptr [ebp - 0x2f8], eax
00496543  898504fdffff             mov       dword ptr [ebp - 0x2fc], eax
00496549  8b8524fdffff             mov       eax, dword ptr [ebp - 0x2dc]
0049654f  8b08                     mov       ecx, dword ptr [eax]
00496551  83c1ff                   add       ecx, -1
00496554  83f900                   cmp       ecx, 0
00496557  898d00fdffff             mov       dword ptr [ebp - 0x300], ecx
0049655d  0f8e23030000             jle       0x496886
00496563  b802000000               mov       eax, 2
00496568  8b8d28fdffff             mov       ecx, dword ptr [ebp - 0x2d8]
0049656e  d901                     fld       dword ptr [ecx]
00496570  89850cfdffff             mov       dword ptr [ebp - 0x2f4], eax
00496576  8b8d0cfdffff             mov       ecx, dword ptr [ebp - 0x2f4]
0049657c  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0049657f  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
00496583  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
00496587  d9ca                     fxch      st(2)
00496589  d85488f8                 fcom      dword ptr [eax + ecx*4 - 8]
0049658d  d9c9                     fxch      st(1)
0049658f  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00496592  d9c9                     fxch      st(1)
00496594  dfe0                     fnstsw    ax
00496596  9e                       sahf
00496597  0f8a17000000             jp        0x4965b4
0049659d  7315                     jae       0x4965b4
0049659f  d9c9                     fxch      st(1)
004965a1  d8d1                     fcom      st(1)
004965a3  d9c9                     fxch      st(1)
004965a5  dfe0                     fnstsw    ax
004965a7  9e                       sahf
004965a8  0f8a06000000             jp        0x4965b4
004965ae  0f82bb020000             jb        0x49686f
004965b4  8b8d0cfdffff             mov       ecx, dword ptr [ebp - 0x2f4]
004965ba  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004965bd  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
004965c1  db7db8                   fstp      xword ptr [ebp - 0x48]
004965c4  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
004965c8  db7dac                   fstp      xword ptr [ebp - 0x54]
004965cb  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004965ce  8b5c88f8                 mov       ebx, dword ptr [eax + ecx*4 - 8]
004965d2  8b8504fdffff             mov       eax, dword ptr [ebp - 0x2fc]
004965d8  85c0                     test      eax, eax
004965da  750c                     jne       0x4965e8
004965dc  8b850cfdffff             mov       eax, dword ptr [ebp - 0x2f4]
004965e2  898504fdffff             mov       dword ptr [ebp - 0x2fc], eax
004965e8  8b850cfdffff             mov       eax, dword ptr [ebp - 0x2f4]
004965ee  898508fdffff             mov       dword ptr [ebp - 0x2f8], eax
004965f4  db6dc4                   fld       xword ptr [ebp - 0x3c]
004965f7  d9ca                     fxch      st(2)
004965f9  d8d2                     fcom      st(2)
004965fb  ddda                     fstp      st(2)
004965fd  dfe0                     fnstsw    ax
004965ff  9e                       sahf
00496600  0f8a17000000             jp        0x49661d
00496606  7215                     jb        0x49661d
00496608  d9c9                     fxch      st(1)
0049660a  d8d1                     fcom      st(1)
0049660c  d9c9                     fxch      st(1)
0049660e  dfe0                     fnstsw    ax
00496610  9e                       sahf
00496611  0f8a06000000             jp        0x49661d
00496617  0f83e2000000             jae       0x4966ff
0049661d  db6dc4                   fld       xword ptr [ebp - 0x3c]
00496620  d8ea                     fsubr     st(2)
00496622  db6dac                   fld       xword ptr [ebp - 0x54]
00496625  db6db8                   fld       xword ptr [ebp - 0x48]
00496628  dee9                     fsubp     st(1)
0049662a  d8c9                     fmul      st(1)
0049662c  db6dc4                   fld       xword ptr [ebp - 0x3c]
0049662f  d8eb                     fsubr     st(3)
00496631  def9                     fdivp     st(1)
00496633  db6db8                   fld       xword ptr [ebp - 0x48]
00496636  dec1                     faddp     st(1)
00496638  db7da0                   fstp      xword ptr [ebp - 0x60]
0049663b  db6dc4                   fld       xword ptr [ebp - 0x3c]
0049663e  d8da                     fcomp     st(2)
00496640  db7d94                   fstp      xword ptr [ebp - 0x6c]
00496643  dfe0                     fnstsw    ax
00496645  9e                       sahf
00496646  0f8a3c000000             jp        0x496688
0049664c  773a                     ja        0x496688
0049664e  ddd8                     fstp      st(0)
00496650  db6da0                   fld       xword ptr [ebp - 0x60]
00496653  db6db8                   fld       xword ptr [ebp - 0x48]
00496656  dee9                     fsubp     st(1)
00496658  db6d94                   fld       xword ptr [ebp - 0x6c]
0049665b  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
0049665e  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
00496662  db6d94                   fld       xword ptr [ebp - 0x6c]
00496665  d9c9                     fxch      st(1)
00496667  d8d1                     fcom      st(1)
00496669  ddd9                     fstp      st(1)
0049666b  db7d88                   fstp      xword ptr [ebp - 0x78]
0049666e  dfe0                     fnstsw    ax
00496670  66a90041                 test      ax, 0x4100
00496674  7406                     je        0x49667c
00496676  db6d94                   fld       xword ptr [ebp - 0x6c]
00496679  db7d88                   fstp      xword ptr [ebp - 0x78]
0049667c  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
0049667f  db6d88                   fld       xword ptr [ebp - 0x78]
00496682  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
00496686  eb38                     jmp       0x4966c0
00496688  db6dac                   fld       xword ptr [ebp - 0x54]
0049668b  db6da0                   fld       xword ptr [ebp - 0x60]
0049668e  dee9                     fsubp     st(1)
00496690  d9c9                     fxch      st(1)
00496692  d8ea                     fsubr     st(2)
00496694  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
00496697  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
0049669b  d8d1                     fcom      st(1)
0049669d  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
004966a3  dfe0                     fnstsw    ax
004966a5  66a90041                 test      ax, 0x4100
004966a9  7408                     je        0x4966b3
004966ab  d9c0                     fld       st(0)
004966ad  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
004966b3  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
004966b6  dbad7cffffff             fld       xword ptr [ebp - 0x84]
004966bc  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
004966c0  8b4548                   mov       eax, dword ptr [ebp + 0x48]
004966c3  d9c1                     fld       st(1)
004966c5  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
004966c9  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
004966cd  d9c1                     fld       st(1)
004966cf  d9c1                     fld       st(1)
004966d1  dcc9                     fmul      st(1), st(0)
004966d3  8d0518945b00             lea       eax, [0x5b9418] ; bits=00000000, f32=0.0
004966d9  d9c9                     fxch      st(1)
004966db  dc08                     fmul      qword ptr [eax]
004966dd  8b4d50                   mov       ecx, dword ptr [ebp + 0x50]
004966e0  d9c0                     fld       st(0)
004966e2  dc44d9f8                 fadd      qword ptr [ecx + ebx*8 - 8]
004966e6  dd5cd9f8                 fstp      qword ptr [ecx + ebx*8 - 8]
004966ea  dec9                     fmulp     st(1)
004966ec  dc4898                   fmul      qword ptr [eax - 0x68]
004966ef  8b4554                   mov       eax, dword ptr [ebp + 0x54]
004966f2  dc44d8f8                 fadd      qword ptr [eax + ebx*8 - 8]
004966f6  dd5cd8f8                 fstp      qword ptr [eax + ebx*8 - 8]
004966fa  e9fe000000               jmp       0x4967fd
004966ff  db6dac                   fld       xword ptr [ebp - 0x54]
00496702  db6db8                   fld       xword ptr [ebp - 0x48]
00496705  dee9                     fsubp     st(1)
00496707  db6dc4                   fld       xword ptr [ebp - 0x3c]
0049670a  d8ea                     fsubr     st(2)
0049670c  db6dc4                   fld       xword ptr [ebp - 0x3c]
0049670f  d8ec                     fsubr     st(4)
00496711  d9cb                     fxch      st(3)
00496713  d8ec                     fsubr     st(4)
00496715  dbbd70ffffff             fstp      xword ptr [ebp - 0x90]
0049671b  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
0049671e  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
00496722  d8d3                     fcom      st(3)
00496724  dbbd64ffffff             fstp      xword ptr [ebp - 0x9c]
0049672a  d9ca                     fxch      st(2)
0049672c  dbbd58ffffff             fstp      xword ptr [ebp - 0xa8]
00496732  d9c9                     fxch      st(1)
00496734  dfe0                     fnstsw    ax
00496736  66a90041                 test      ax, 0x4100
0049673a  740c                     je        0x496748
0049673c  dbad58ffffff             fld       xword ptr [ebp - 0xa8]
00496742  dbbd64ffffff             fstp      xword ptr [ebp - 0x9c]
00496748  dbad64ffffff             fld       xword ptr [ebp - 0x9c]
0049674e  dbad70ffffff             fld       xword ptr [ebp - 0x90]
00496754  d9c9                     fxch      st(1)
00496756  ded9                     fcompp
00496758  dbad64ffffff             fld       xword ptr [ebp - 0x9c]
0049675e  dbbd4cffffff             fstp      xword ptr [ebp - 0xb4]
00496764  dfe0                     fnstsw    ax
00496766  66a90041                 test      ax, 0x4100
0049676a  740c                     je        0x496778
0049676c  dbad70ffffff             fld       xword ptr [ebp - 0x90]
00496772  dbbd4cffffff             fstp      xword ptr [ebp - 0xb4]
00496778  d9ca                     fxch      st(2)
0049677a  dbbd40ffffff             fstp      xword ptr [ebp - 0xc0]
00496780  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
00496783  dbad4cffffff             fld       xword ptr [ebp - 0xb4]
00496789  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
0049678d  8b4548                   mov       eax, dword ptr [ebp + 0x48]
00496790  d9c0                     fld       st(0)
00496792  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
00496796  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
0049679a  dbad70ffffff             fld       xword ptr [ebp - 0x90]
004967a0  dbad58ffffff             fld       xword ptr [ebp - 0xa8]
004967a6  dec1                     faddp     st(1)
004967a8  d9c1                     fld       st(1)
004967aa  dcc9                     fmul      st(1), st(0)
004967ac  8d0518945b00             lea       eax, [0x5b9418] ; bits=00000000, f32=0.0
004967b2  dd00                     fld       qword ptr [eax]
004967b4  d9ca                     fxch      st(2)
004967b6  dc08                     fmul      qword ptr [eax]
004967b8  8b4d50                   mov       ecx, dword ptr [ebp + 0x50]
004967bb  dc44d9f8                 fadd      qword ptr [ecx + ebx*8 - 8]
004967bf  dd5cd9f8                 fstp      qword ptr [ecx + ebx*8 - 8]
004967c3  dbad70ffffff             fld       xword ptr [ebp - 0x90]
004967c9  dbad58ffffff             fld       xword ptr [ebp - 0xa8]
004967cf  dec9                     fmulp     st(1)
004967d1  dbad70ffffff             fld       xword ptr [ebp - 0x90]
004967d7  dbad58ffffff             fld       xword ptr [ebp - 0xa8]
004967dd  dee9                     fsubp     st(1)
004967df  d8c8                     fmul      st(0)
004967e1  d8486c                   fmul      dword ptr [eax + 0x6c]
004967e4  dec1                     faddp     st(1)
004967e6  dec9                     fmulp     st(1)
004967e8  dec9                     fmulp     st(1)
004967ea  8b4554                   mov       eax, dword ptr [ebp + 0x54]
004967ed  dc44d8f8                 fadd      qword ptr [eax + ebx*8 - 8]
004967f1  dd5cd8f8                 fstp      qword ptr [eax + ebx*8 - 8]
004967f5  dbad40ffffff             fld       xword ptr [ebp - 0xc0]
004967fb  d9ca                     fxch      st(2)
004967fd  d9c9                     fxch      st(1)
004967ff  d8c8                     fmul      st(0)
00496801  d9c9                     fxch      st(1)
00496803  d8c8                     fmul      st(0)
00496805  dec1                     faddp     st(1)
00496807  d9fa                     fsqrt
00496809  d95dfc                   fstp      dword ptr [ebp - 4]
0049680c  d945fc                   fld       dword ptr [ebp - 4]
0049680f  dbbd34ffffff             fstp      xword ptr [ebp - 0xcc]
00496815  8b8d0cfdffff             mov       ecx, dword ptr [ebp - 0x2f4]
0049681b  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0049681e  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
00496822  d81540945b00             fcom      dword ptr [0x5b9440] ; bits=00000000, f32=0.0
00496828  dbbd28ffffff             fstp      xword ptr [ebp - 0xd8]
0049682e  dfe0                     fnstsw    ax
00496830  9e                       sahf
00496831  0f8a13000000             jp        0x49684a
00496837  7611                     jbe       0x49684a
00496839  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
0049683c  dbad34ffffff             fld       xword ptr [ebp - 0xcc]
00496842  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
00496846  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
0049684a  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0049684d  837c98fc00               cmp       dword ptr [eax + ebx*4 - 4], 0
00496852  751d                     jne       0x496871
00496854  dbad28ffffff             fld       xword ptr [ebp - 0xd8]
0049685a  dbad34ffffff             fld       xword ptr [ebp - 0xcc]
00496860  dec9                     fmulp     st(1)
00496862  8b4558                   mov       eax, dword ptr [ebp + 0x58]
00496865  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
00496869  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
0049686d  eb02                     jmp       0x496871
0049686f  ddd8                     fstp      st(0)
00496871  ff850cfdffff             inc       dword ptr [ebp - 0x2f4]
00496877  83ad00fdffff01           sub       dword ptr [ebp - 0x300], 1
0049687e  0f85f2fcffff             jne       0x496576
00496884  ddd8                     fstp      st(0)
00496886  8b8510fdffff             mov       eax, dword ptr [ebp - 0x2f0]
0049688c  8985fcfcffff             mov       dword ptr [ebp - 0x304], eax
00496892  3d00000000               cmp       eax, 0
00496897  0f8e87010000             jle       0x496a24
0049689d  bb01000000               mov       ebx, 1
004968a2  b809000000               mov       eax, 9
004968a7  8985f8fcffff             mov       dword ptr [ebp - 0x308], eax
004968ad  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004968b0  8b4c98fc                 mov       ecx, dword ptr [eax + ebx*4 - 4]
004968b4  83f901                   cmp       ecx, 1
004968b7  898df4fcffff             mov       dword ptr [ebp - 0x30c], ecx
004968bd  0f85d8000000             jne       0x49699b
004968c3  8b4548                   mov       eax, dword ptr [ebp + 0x48]
004968c6  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
004968ca  d81540945b00             fcom      dword ptr [0x5b9440] ; bits=00000000, f32=0.0
004968d0  dfe0                     fnstsw    ax
004968d2  9e                       sahf
004968d3  0f8a11000000             jp        0x4968ea
004968d9  760f                     jbe       0x4968ea
004968db  8b4550                   mov       eax, dword ptr [ebp + 0x50]
004968de  dc7cd8f8                 fdivr     qword ptr [eax + ebx*8 - 8]
004968e2  d91da0995b00             fstp      dword ptr [0x5b99a0] ; bits=00000000, f32=0.0
004968e8  eb7d                     jmp       0x496967
004968ea  ddd8                     fstp      st(0)
004968ec  8b4550                   mov       eax, dword ptr [ebp + 0x50]
004968ef  dd44d8f8                 fld       qword ptr [eax + ebx*8 - 8]
004968f3  dc1d30945b00             fcomp     qword ptr [0x5b9430] ; bits=0000000000000000, f64=0.0
004968f9  dfe0                     fnstsw    ax
004968fb  9e                       sahf
004968fc  0f8a5b000000             jp        0x49695d
00496902  7659                     jbe       0x49695d
00496904  6808995b00               push      0x5b9908
00496909  e872c50000               call      0x4a2e80 ; _jwe_ilst
0049690e  83c404                   add       esp, 4
00496911  8b4548                   mov       eax, dword ptr [ebp + 0x48]
00496914  8b4498fc                 mov       eax, dword ptr [eax + ebx*4 - 4]
00496918  8b4d50                   mov       ecx, dword ptr [ebp + 0x50]
0049691b  8b54d9f8                 mov       edx, dword ptr [ecx + ebx*8 - 8]
0049691f  8b4cd9fc                 mov       ecx, dword ptr [ecx + ebx*8 - 4]
00496923  8d35a0985b00             lea       esi, [0x5b98a0] ; bits=09820000, f32=4.664782457890884e-41
00496929  895df8                   mov       dword ptr [ebp - 8], ebx
0049692c  8d7df8                   lea       edi, [ebp - 8]
0049692f  897e34                   mov       dword ptr [esi + 0x34], edi
00496932  8945fc                   mov       dword ptr [ebp - 4], eax
00496935  8d45fc                   lea       eax, [ebp - 4]
00496938  89464c                   mov       dword ptr [esi + 0x4c], eax
0049693b  8955f0                   mov       dword ptr [ebp - 0x10], edx
0049693e  894df4                   mov       dword ptr [ebp - 0xc], ecx
00496941  8d45f0                   lea       eax, [ebp - 0x10]
00496944  894664                   mov       dword ptr [esi + 0x64], eax
00496947  56                       push      esi
00496948  e833c50000               call      0x4a2e80 ; _jwe_ilst
0049694d  83c404                   add       esp, 4
00496950  6858965b00               push      0x5b9658
00496955  e8e6ca0000               call      0x4a3440 ; _jwe_xstp
0049695a  83c404                   add       esp, 4
0049695d  c705a0995b0000000000     mov       dword ptr [0x5b99a0], 0 ; bits=00000000, f32=0.0
00496967  8b8df8fcffff             mov       ecx, dword ptr [ebp - 0x308]
0049696d  8b4530                   mov       eax, dword ptr [ebp + 0x30]
00496970  8d4488dc                 lea       eax, [eax + ecx*4 - 0x24]
00496974  50                       push      eax
00496975  8b4534                   mov       eax, dword ptr [ebp + 0x34]
00496978  8d4488dc                 lea       eax, [eax + ecx*4 - 0x24]
0049697c  50                       push      eax
0049697d  8b4538                   mov       eax, dword ptr [ebp + 0x38]
00496980  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
00496984  50                       push      eax
00496985  68a0995b00               push      0x5b99a0
0049698a  e811cbffff               call      0x4934a0 ; _fndydn_
0049698f  83c410                   add       esp, 0x10
00496992  8b4544                   mov       eax, dword ptr [ebp + 0x44]
00496995  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
00496999  eb74                     jmp       0x496a0f
0049699b  83bdf4fcffff02           cmp       dword ptr [ebp - 0x30c], 2
004969a2  7541                     jne       0x4969e5
004969a4  8b457c                   mov       eax, dword ptr [ebp + 0x7c]
004969a7  8b4498fc                 mov       eax, dword ptr [eax + ebx*4 - 4]
004969ab  8905a0995b00             mov       dword ptr [0x5b99a0], eax ; bits=00000000, f32=0.0
004969b1  8b8df8fcffff             mov       ecx, dword ptr [ebp - 0x308]
004969b7  8b4530                   mov       eax, dword ptr [ebp + 0x30]
004969ba  8d4488dc                 lea       eax, [eax + ecx*4 - 0x24]
004969be  50                       push      eax
004969bf  8b4534                   mov       eax, dword ptr [ebp + 0x34]
004969c2  8d4488dc                 lea       eax, [eax + ecx*4 - 0x24]
004969c6  50                       push      eax
004969c7  8b4538                   mov       eax, dword ptr [ebp + 0x38]
004969ca  8d4498fc                 lea       eax, [eax + ebx*4 - 4]
004969ce  50                       push      eax
004969cf  68a0995b00               push      0x5b99a0
004969d4  e8c7caffff               call      0x4934a0 ; _fndydn_
004969d9  83c410                   add       esp, 0x10
004969dc  8b4544                   mov       eax, dword ptr [ebp + 0x44]
004969df  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
004969e3  eb2a                     jmp       0x496a0f
004969e5  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
004969e8  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
004969ec  d81540945b00             fcom      dword ptr [0x5b9440] ; bits=00000000, f32=0.0
004969f2  dfe0                     fnstsw    ax
004969f4  9e                       sahf
004969f5  0f8a12000000             jp        0x496a0d
004969fb  7610                     jbe       0x496a0d
004969fd  8b4558                   mov       eax, dword ptr [ebp + 0x58]
00496a00  d87c98fc                 fdivr     dword ptr [eax + ebx*4 - 4]
00496a04  8b4544                   mov       eax, dword ptr [ebp + 0x44]
00496a07  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
00496a0b  eb02                     jmp       0x496a0f
00496a0d  ddd8                     fstp      st(0)
00496a0f  43                       inc       ebx
00496a10  8385f8fcffff09           add       dword ptr [ebp - 0x308], 9
00496a17  83adfcfcffff01           sub       dword ptr [ebp - 0x304], 1
00496a1e  0f8589feffff             jne       0x4968ad
00496a24  83bd04fdffff02           cmp       dword ptr [ebp - 0x2fc], 2
00496a2b  7d0b                     jge       0x496a38
00496a2d  b802000000               mov       eax, 2
00496a32  898504fdffff             mov       dword ptr [ebp - 0x2fc], eax
00496a38  8b8504fdffff             mov       eax, dword ptr [ebp - 0x2fc]
00496a3e  8985f0fcffff             mov       dword ptr [ebp - 0x310], eax
00496a44  8b8d08fdffff             mov       ecx, dword ptr [ebp - 0x2f8]
00496a4a  29c1                     sub       ecx, eax
00496a4c  41                       inc       ecx
00496a4d  83f900                   cmp       ecx, 0
00496a50  898decfcffff             mov       dword ptr [ebp - 0x314], ecx
00496a56  0f8e3b0f0000             jle       0x497997
00496a5c  8b85f0fcffff             mov       eax, dword ptr [ebp - 0x310]
00496a62  89850cfdffff             mov       dword ptr [ebp - 0x2f4], eax
00496a68  8b8528fdffff             mov       eax, dword ptr [ebp - 0x2d8]
00496a6e  d900                     fld       dword ptr [eax]
00496a70  dbbd1cffffff             fstp      xword ptr [ebp - 0xe4]
00496a76  8b8d0cfdffff             mov       ecx, dword ptr [ebp - 0x2f4]
00496a7c  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00496a7f  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
00496a83  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
00496a87  dbbd10ffffff             fstp      xword ptr [ebp - 0xf0]
00496a8d  dbad1cffffff             fld       xword ptr [ebp - 0xe4]
00496a93  d8d9                     fcomp     st(1)
00496a95  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00496a98  dfe0                     fnstsw    ax
00496a9a  9e                       sahf
00496a9b  0f8a21000000             jp        0x496ac2
00496aa1  731f                     jae       0x496ac2
00496aa3  dbad1cffffff             fld       xword ptr [ebp - 0xe4]
00496aa9  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00496aaf  d9c9                     fxch      st(1)
00496ab1  ded9                     fcompp
00496ab3  dfe0                     fnstsw    ax
00496ab5  9e                       sahf
00496ab6  0f8a06000000             jp        0x496ac2
00496abc  0f82c20e0000             jb        0x497984
00496ac2  8b8d0cfdffff             mov       ecx, dword ptr [ebp - 0x2f4]
00496ac8  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00496acb  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
00496acf  db7db8                   fstp      xword ptr [ebp - 0x48]
00496ad2  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
00496ad6  db7dac                   fstp      xword ptr [ebp - 0x54]
00496ad9  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
00496adc  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
00496ae0  dbbd04ffffff             fstp      xword ptr [ebp - 0xfc]
00496ae6  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
00496aea  dbbdf8feffff             fstp      xword ptr [ebp - 0x108]
00496af0  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00496af3  8b5c88f8                 mov       ebx, dword ptr [eax + ecx*4 - 8]
00496af7  8b8528fdffff             mov       eax, dword ptr [ebp - 0x2d8]
00496afd  d900                     fld       dword ptr [eax]
00496aff  db6dc4                   fld       xword ptr [ebp - 0x3c]
00496b02  d9c9                     fxch      st(1)
00496b04  d8d1                     fcom      st(1)
00496b06  ddd9                     fstp      st(1)
00496b08  dbbdecfeffff             fstp      xword ptr [ebp - 0x114]
00496b0e  dfe0                     fnstsw    ax
00496b10  9e                       sahf
00496b11  0f8a21000000             jp        0x496b38
00496b17  721f                     jb        0x496b38
00496b19  dbadecfeffff             fld       xword ptr [ebp - 0x114]
00496b1f  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00496b25  d9c9                     fxch      st(1)
00496b27  ded9                     fcompp
00496b29  dfe0                     fnstsw    ax
00496b2b  9e                       sahf
00496b2c  0f8a06000000             jp        0x496b38
00496b32  0f8340010000             jae       0x496c78
00496b38  dbadecfeffff             fld       xword ptr [ebp - 0x114]
00496b3e  db6dc4                   fld       xword ptr [ebp - 0x3c]
00496b41  dee9                     fsubp     st(1)
00496b43  db6dac                   fld       xword ptr [ebp - 0x54]
00496b46  db6db8                   fld       xword ptr [ebp - 0x48]
00496b49  dee9                     fsubp     st(1)
00496b4b  dcc9                     fmul      st(1), st(0)
00496b4d  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00496b53  db6dc4                   fld       xword ptr [ebp - 0x3c]
00496b56  dee9                     fsubp     st(1)
00496b58  defa                     fdivp     st(2)
00496b5a  db6db8                   fld       xword ptr [ebp - 0x48]
00496b5d  dec2                     faddp     st(2)
00496b5f  d9c9                     fxch      st(1)
00496b61  db7da0                   fstp      xword ptr [ebp - 0x60]
00496b64  8b852cfdffff             mov       eax, dword ptr [ebp - 0x2d4]
00496b6a  dbbde0feffff             fstp      xword ptr [ebp - 0x120]
00496b70  833801                   cmp       dword ptr [eax], 1
00496b73  754f                     jne       0x496bc4
00496b75  db6dac                   fld       xword ptr [ebp - 0x54]
00496b78  db6db8                   fld       xword ptr [ebp - 0x48]
00496b7b  d9c9                     fxch      st(1)
00496b7d  ded9                     fcompp
00496b7f  dfe0                     fnstsw    ax
00496b81  9e                       sahf
00496b82  0f8a32000000             jp        0x496bba
00496b88  7630                     jbe       0x496bba
00496b8a  db6da0                   fld       xword ptr [ebp - 0x60]
00496b8d  db6db8                   fld       xword ptr [ebp - 0x48]
00496b90  dee9                     fsubp     st(1)
00496b92  dbadf8feffff             fld       xword ptr [ebp - 0x108]
00496b98  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
00496b9e  dee9                     fsubp     st(1)
00496ba0  dec9                     fmulp     st(1)
00496ba2  dbade0feffff             fld       xword ptr [ebp - 0x120]
00496ba8  def9                     fdivp     st(1)
00496baa  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
00496bb0  dec1                     faddp     st(1)
00496bb2  dbbdd4feffff             fstp      xword ptr [ebp - 0x12c]
00496bb8  eb16                     jmp       0x496bd0
00496bba  d9e8                     fld1
00496bbc  dbbdd4feffff             fstp      xword ptr [ebp - 0x12c]
00496bc2  eb0c                     jmp       0x496bd0
00496bc4  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
00496bca  dbbdd4feffff             fstp      xword ptr [ebp - 0x12c]
00496bd0  db6dc4                   fld       xword ptr [ebp - 0x3c]
00496bd3  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00496bd9  d9c9                     fxch      st(1)
00496bdb  ded9                     fcompp
00496bdd  dfe0                     fnstsw    ax
00496bdf  9e                       sahf
00496be0  0f8a49000000             jp        0x496c2f
00496be6  7747                     ja        0x496c2f
00496be8  db6da0                   fld       xword ptr [ebp - 0x60]
00496beb  db6db8                   fld       xword ptr [ebp - 0x48]
00496bee  dee9                     fsubp     st(1)
00496bf0  dbbdc8feffff             fstp      xword ptr [ebp - 0x138]
00496bf6  db6da0                   fld       xword ptr [ebp - 0x60]
00496bf9  db7dac                   fstp      xword ptr [ebp - 0x54]
00496bfc  dbadd4feffff             fld       xword ptr [ebp - 0x12c]
00496c02  dbbdf8feffff             fstp      xword ptr [ebp - 0x108]
00496c08  dbadecfeffff             fld       xword ptr [ebp - 0x114]
00496c0e  dbbd10ffffff             fstp      xword ptr [ebp - 0xf0]
00496c14  8b8528fdffff             mov       eax, dword ptr [ebp - 0x2d8]
00496c1a  db6dc4                   fld       xword ptr [ebp - 0x3c]
00496c1d  d828                     fsubr     dword ptr [eax]
00496c1f  d9ee                     fldz
00496c21  dbbdbcfeffff             fstp      xword ptr [ebp - 0x144]
00496c27  d91da4995b00             fstp      dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
00496c2d  eb7c                     jmp       0x496cab
00496c2f  db6dac                   fld       xword ptr [ebp - 0x54]
00496c32  db6da0                   fld       xword ptr [ebp - 0x60]
00496c35  dee9                     fsubp     st(1)
00496c37  dbbdc8feffff             fstp      xword ptr [ebp - 0x138]
00496c3d  db6da0                   fld       xword ptr [ebp - 0x60]
00496c40  db7db8                   fstp      xword ptr [ebp - 0x48]
00496c43  dbadd4feffff             fld       xword ptr [ebp - 0x12c]
00496c49  dbbd04ffffff             fstp      xword ptr [ebp - 0xfc]
00496c4f  dbadecfeffff             fld       xword ptr [ebp - 0x114]
00496c55  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00496c58  8b8528fdffff             mov       eax, dword ptr [ebp - 0x2d8]
00496c5e  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00496c64  d828                     fsubr     dword ptr [eax]
00496c66  c705a4995b0000000000     mov       dword ptr [0x5b99a4], 0 ; bits=00000000, f32=0.0
00496c70  dbbdbcfeffff             fstp      xword ptr [ebp - 0x144]
00496c76  eb33                     jmp       0x496cab
00496c78  db6dac                   fld       xword ptr [ebp - 0x54]
00496c7b  db6db8                   fld       xword ptr [ebp - 0x48]
00496c7e  dee9                     fsubp     st(1)
00496c80  dbbdc8feffff             fstp      xword ptr [ebp - 0x138]
00496c86  dbadecfeffff             fld       xword ptr [ebp - 0x114]
00496c8c  db6dc4                   fld       xword ptr [ebp - 0x3c]
00496c8f  dee9                     fsubp     st(1)
00496c91  d91da4995b00             fstp      dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
00496c97  dbadecfeffff             fld       xword ptr [ebp - 0x114]
00496c9d  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00496ca3  dee9                     fsubp     st(1)
00496ca5  dbbdbcfeffff             fstp      xword ptr [ebp - 0x144]
00496cab  8b852cfdffff             mov       eax, dword ptr [ebp - 0x2d4]
00496cb1  8b08                     mov       ecx, dword ptr [eax]
00496cb3  83f901                   cmp       ecx, 1
00496cb6  898de8fcffff             mov       dword ptr [ebp - 0x318], ecx
00496cbc  0f850d080000             jne       0x4974cf
00496cc2  dbadc8feffff             fld       xword ptr [ebp - 0x138]
00496cc8  d81d40945b00             fcomp     dword ptr [0x5b9440] ; bits=00000000, f32=0.0
00496cce  dfe0                     fnstsw    ax
00496cd0  9e                       sahf
00496cd1  0f8a11080000             jp        0x4974e8
00496cd7  0f860b080000             jbe       0x4974e8
00496cdd  dbadbcfeffff             fld       xword ptr [ebp - 0x144]
00496ce3  d81da4995b00             fcomp     dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
00496ce9  dbadbcfeffff             fld       xword ptr [ebp - 0x144]
00496cef  dbbdb0feffff             fstp      xword ptr [ebp - 0x150]
00496cf5  dfe0                     fnstsw    ax
00496cf7  66a90041                 test      ax, 0x4100
00496cfb  740c                     je        0x496d09
00496cfd  d905a4995b00             fld       dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
00496d03  dbbdb0feffff             fstp      xword ptr [ebp - 0x150]
00496d09  dbadb0feffff             fld       xword ptr [ebp - 0x150]
00496d0f  d81d40945b00             fcomp     dword ptr [0x5b9440] ; bits=00000000, f32=0.0
00496d15  dfe0                     fnstsw    ax
00496d17  9e                       sahf
00496d18  0f8aca070000             jp        0x4974e8
00496d1e  0f86c4070000             jbe       0x4974e8
00496d24  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00496d2a  db6dc4                   fld       xword ptr [ebp - 0x3c]
00496d2d  dee9                     fsubp     st(1)
00496d2f  dbadc8feffff             fld       xword ptr [ebp - 0x138]
00496d35  def9                     fdivp     st(1)
00496d37  dd9da8feffff             fstp      qword ptr [ebp - 0x158]
00496d3d  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00496d40  837c98fc00               cmp       dword ptr [eax + ebx*4 - 4], 0
00496d45  0f8ef3000000             jle       0x496e3e
00496d4b  dd85a8feffff             fld       qword ptr [ebp - 0x158]
00496d51  dc8da8feffff             fmul      qword ptr [ebp - 0x158]
00496d57  dc0510945b00             fadd      qword ptr [0x5b9410] ; bits=000000000000f03f, f64=1.0
00496d5d  dd95a0feffff             fst       qword ptr [ebp - 0x160]
00496d63  dd5df0                   fstp      qword ptr [ebp - 0x10]
00496d66  8d0518945b00             lea       eax, [0x5b9418] ; bits=00000000, f32=0.0
00496d6c  8985e4fcffff             mov       dword ptr [ebp - 0x31c], eax
00496d72  8d48d0                   lea       ecx, [eax - 0x30]
00496d75  51                       push      ecx
00496d76  8d4df0                   lea       ecx, [ebp - 0x10]
00496d79  51                       push      ecx
00496d7a  e801a40000               call      0x4a1180 ; _g_adxd
00496d7f  83c408                   add       esp, 8
00496d82  8b4544                   mov       eax, dword ptr [ebp + 0x44]
00496d85  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
00496d89  dec9                     fmulp     st(1)
00496d8b  8b4d3c                   mov       ecx, dword ptr [ebp + 0x3c]
00496d8e  d901                     fld       dword ptr [ecx]
00496d90  def1                     fdivrp    st(1)
00496d92  dd9d98feffff             fstp      qword ptr [ebp - 0x168]
00496d98  83bd18fdffff01           cmp       dword ptr [ebp - 0x2e8], 1
00496d9f  8985e0fcffff             mov       dword ptr [ebp - 0x320], eax
00496da5  898ddcfcffff             mov       dword ptr [ebp - 0x324], ecx
00496dab  0f8587010000             jne       0x496f38
00496db1  dd85a0feffff             fld       qword ptr [ebp - 0x160]
00496db7  8b85e4fcffff             mov       eax, dword ptr [ebp - 0x31c]
00496dbd  dd5df0                   fstp      qword ptr [ebp - 0x10]
00496dc0  8d48a0                   lea       ecx, [eax - 0x60]
00496dc3  51                       push      ecx
00496dc4  8d4df0                   lea       ecx, [ebp - 0x10]
00496dc7  51                       push      ecx
00496dc8  e8b3a30000               call      0x4a1180 ; _g_adxd
00496dcd  83c408                   add       esp, 8
00496dd0  8b85e0fcffff             mov       eax, dword ptr [ebp - 0x320]
00496dd6  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
00496dda  8b85dcfcffff             mov       eax, dword ptr [ebp - 0x324]
00496de0  dec9                     fmulp     st(1)
00496de2  d900                     fld       dword ptr [eax]
00496de4  def1                     fdivrp    st(1)
00496de6  d90530bcf400             fld       dword ptr [0xf4bc30] ; _grvcom_
00496dec  8b85e4fcffff             mov       eax, dword ptr [ebp - 0x31c]
00496df2  d9c0                     fld       st(0)
00496df4  d8484c                   fmul      dword ptr [eax + 0x4c]
00496df7  d9c2                     fld       st(2)
00496df9  d8c8                     fmul      st(0)
00496dfb  dd40f0                   fld       qword ptr [eax - 0x10]
00496dfe  d9c1                     fld       st(1)
00496e00  dc48f0                   fmul      qword ptr [eax - 0x10]
00496e03  defb                     fdivp     st(3)
00496e05  d9ca                     fxch      st(2)
00496e07  dd1d60995b00             fstp      qword ptr [0x5b9960] ; bits=0000000000000000, f64=0.0
00496e0d  d9c2                     fld       st(2)
00496e0f  d9fa                     fsqrt
00496e11  d95dfc                   fstp      dword ptr [ebp - 4]
00496e14  d9c2                     fld       st(2)
00496e16  d84dfc                   fmul      dword ptr [ebp - 4]
00496e19  d84850                   fmul      dword ptr [eax + 0x50]
00496e1c  d9cc                     fxch      st(4)
00496e1e  d8c9                     fmul      st(1)
00496e20  deca                     fmulp     st(2)
00496e22  d9cb                     fxch      st(3)
00496e24  def1                     fdivrp    st(1)
00496e26  d9e0                     fchs
00496e28  dd1d68995b00             fstp      qword ptr [0x5b9968] ; bits=0000000000000000, f64=0.0
00496e2e  d84858                   fmul      dword ptr [eax + 0x58]
00496e31  def1                     fdivrp    st(1)
00496e33  dd1d70995b00             fstp      qword ptr [0x5b9970] ; bits=0000000000000000, f64=0.0
00496e39  e9fa000000               jmp       0x496f38
00496e3e  dd85a8feffff             fld       qword ptr [ebp - 0x158]
00496e44  dc8da8feffff             fmul      qword ptr [ebp - 0x158]
00496e4a  dc0510945b00             fadd      qword ptr [0x5b9410] ; bits=000000000000f03f, f64=1.0
00496e50  dd9590feffff             fst       qword ptr [ebp - 0x170]
00496e56  dd5df0                   fstp      qword ptr [ebp - 0x10]
00496e59  8d0518945b00             lea       eax, [0x5b9418] ; bits=00000000, f32=0.0
00496e5f  8985ccfcffff             mov       dword ptr [ebp - 0x334], eax
00496e65  8d48d0                   lea       ecx, [eax - 0x30]
00496e68  51                       push      ecx
00496e69  8d4df0                   lea       ecx, [ebp - 0x10]
00496e6c  51                       push      ecx
00496e6d  e80ea30000               call      0x4a1180 ; _g_adxd
00496e72  83c408                   add       esp, 8
00496e75  8b8d0cfdffff             mov       ecx, dword ptr [ebp - 0x2f4]
00496e7b  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00496e7e  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
00496e82  dec9                     fmulp     st(1)
00496e84  8b553c                   mov       edx, dword ptr [ebp + 0x3c]
00496e87  d902                     fld       dword ptr [edx]
00496e89  def1                     fdivrp    st(1)
00496e8b  dd9d98feffff             fstp      qword ptr [ebp - 0x168]
00496e91  83bd18fdffff01           cmp       dword ptr [ebp - 0x2e8], 1
00496e98  8985c8fcffff             mov       dword ptr [ebp - 0x338], eax
00496e9e  8995c4fcffff             mov       dword ptr [ebp - 0x33c], edx
00496ea4  0f858e000000             jne       0x496f38
00496eaa  dd8590feffff             fld       qword ptr [ebp - 0x170]
00496eb0  8b85ccfcffff             mov       eax, dword ptr [ebp - 0x334]
00496eb6  dd5df0                   fstp      qword ptr [ebp - 0x10]
00496eb9  8d48a0                   lea       ecx, [eax - 0x60]
00496ebc  51                       push      ecx
00496ebd  8d4df0                   lea       ecx, [ebp - 0x10]
00496ec0  51                       push      ecx
00496ec1  e8baa20000               call      0x4a1180 ; _g_adxd
00496ec6  83c408                   add       esp, 8
00496ec9  8b8dc8fcffff             mov       ecx, dword ptr [ebp - 0x338]
00496ecf  8b850cfdffff             mov       eax, dword ptr [ebp - 0x2f4]
00496ed5  d94481f8                 fld       dword ptr [ecx + eax*4 - 8]
00496ed9  8b8dc4fcffff             mov       ecx, dword ptr [ebp - 0x33c]
00496edf  dec9                     fmulp     st(1)
00496ee1  d901                     fld       dword ptr [ecx]
00496ee3  def1                     fdivrp    st(1)
00496ee5  d90530bcf400             fld       dword ptr [0xf4bc30] ; _grvcom_
00496eeb  8b8dccfcffff             mov       ecx, dword ptr [ebp - 0x334]
00496ef1  d9c0                     fld       st(0)
00496ef3  d8494c                   fmul      dword ptr [ecx + 0x4c]
00496ef6  d9c2                     fld       st(2)
00496ef8  d8c8                     fmul      st(0)
00496efa  dd41f0                   fld       qword ptr [ecx - 0x10]
00496efd  d9c1                     fld       st(1)
00496eff  dc49f0                   fmul      qword ptr [ecx - 0x10]
00496f02  defb                     fdivp     st(3)
00496f04  d9ca                     fxch      st(2)
00496f06  dd1d60995b00             fstp      qword ptr [0x5b9960] ; bits=0000000000000000, f64=0.0
00496f0c  d9c2                     fld       st(2)
00496f0e  d9fa                     fsqrt
00496f10  d95dfc                   fstp      dword ptr [ebp - 4]
00496f13  d9c2                     fld       st(2)
00496f15  d84dfc                   fmul      dword ptr [ebp - 4]
00496f18  d84950                   fmul      dword ptr [ecx + 0x50]
00496f1b  d9cc                     fxch      st(4)
00496f1d  d8c9                     fmul      st(1)
00496f1f  deca                     fmulp     st(2)
00496f21  d9cb                     fxch      st(3)
00496f23  def1                     fdivrp    st(1)
00496f25  d9e0                     fchs
00496f27  dd1d68995b00             fstp      qword ptr [0x5b9968] ; bits=0000000000000000, f64=0.0
00496f2d  d84958                   fmul      dword ptr [ecx + 0x58]
00496f30  def1                     fdivrp    st(1)
00496f32  dd1d70995b00             fstp      qword ptr [0x5b9970] ; bits=0000000000000000, f64=0.0
00496f38  db6dac                   fld       xword ptr [ebp - 0x54]
00496f3b  db6db8                   fld       xword ptr [ebp - 0x48]
00496f3e  dee9                     fsubp     st(1)
00496f40  d905a4995b00             fld       dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
00496f46  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
00496f4c  d80da4995b00             fmul      dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
00496f52  dbadbcfeffff             fld       xword ptr [ebp - 0x144]
00496f58  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
00496f5e  dec9                     fmulp     st(1)
00496f60  dbadf8feffff             fld       xword ptr [ebp - 0x108]
00496f66  d80da4995b00             fmul      dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
00496f6c  dec1                     faddp     st(1)
00496f6e  8d0518945b00             lea       eax, [0x5b9418] ; bits=00000000, f32=0.0
00496f74  d84864                   fmul      dword ptr [eax + 0x64]
00496f77  dec1                     faddp     st(1)
00496f79  dbadbcfeffff             fld       xword ptr [ebp - 0x144]
00496f7f  dbadf8feffff             fld       xword ptr [ebp - 0x108]
00496f85  dec9                     fmulp     st(1)
00496f87  dec1                     faddp     st(1)
00496f89  deca                     fmulp     st(2)
00496f8b  d9c9                     fxch      st(1)
00496f8d  d8486c                   fmul      dword ptr [eax + 0x6c]
00496f90  8b4d74                   mov       ecx, dword ptr [ebp + 0x74]
00496f93  dc01                     fadd      qword ptr [ecx]
00496f95  dd19                     fstp      qword ptr [ecx]
00496f97  dbadf8feffff             fld       xword ptr [ebp - 0x108]
00496f9d  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
00496fa3  dee9                     fsubp     st(1)
00496fa5  dbadc8feffff             fld       xword ptr [ebp - 0x138]
00496fab  def9                     fdivp     st(1)
00496fad  dd9d88feffff             fstp      qword ptr [ebp - 0x178]
00496fb3  db6db8                   fld       xword ptr [ebp - 0x48]
00496fb6  db6dac                   fld       xword ptr [ebp - 0x54]
00496fb9  d8c1                     fadd      st(1)
00496fbb  dd00                     fld       qword ptr [eax]
00496fbd  d9c9                     fxch      st(1)
00496fbf  dc08                     fmul      qword ptr [eax]
00496fc1  d95dfc                   fstp      dword ptr [ebp - 4]
00496fc4  d945fc                   fld       dword ptr [ebp - 4]
00496fc7  dbbd7cfeffff             fstp      xword ptr [ebp - 0x184]
00496fcd  dbadc8feffff             fld       xword ptr [ebp - 0x138]
00496fd3  dec9                     fmulp     st(1)
00496fd5  d95dfc                   fstp      dword ptr [ebp - 4]
00496fd8  d945fc                   fld       dword ptr [ebp - 4]
00496fdb  dbbd70feffff             fstp      xword ptr [ebp - 0x190]
00496fe1  dd9d68feffff             fstp      qword ptr [ebp - 0x198]
00496fe7  dbbd5cfeffff             fstp      xword ptr [ebp - 0x1a4]
00496fed  8b0590c9e400             mov       eax, dword ptr [0xe4c990]
00496ff3  3d00000000               cmp       eax, 0
00496ff8  8985d8fcffff             mov       dword ptr [ebp - 0x328], eax
00496ffe  0f8ee4040000             jle       0x4974e8
00497004  b801000000               mov       eax, 1
00497009  dbad70feffff             fld       xword ptr [ebp - 0x190]
0049700f  dd9d50feffff             fstp      qword ptr [ebp - 0x1b0]
00497015  dbad7cfeffff             fld       xword ptr [ebp - 0x184]
0049701b  dd9d48feffff             fstp      qword ptr [ebp - 0x1b8]
00497021  dd8568feffff             fld       qword ptr [ebp - 0x198]
00497027  dd9d40feffff             fstp      qword ptr [ebp - 0x1c0]
0049702d  dbad5cfeffff             fld       xword ptr [ebp - 0x1a4]
00497033  dd9d38feffff             fstp      qword ptr [ebp - 0x1c8]
00497039  dbadc8feffff             fld       xword ptr [ebp - 0x138]
0049703f  d9e1                     fabs
00497041  dbbd2cfeffff             fstp      xword ptr [ebp - 0x1d4]
00497047  8985d4fcffff             mov       dword ptr [ebp - 0x32c], eax
0049704d  8b85d4fcffff             mov       eax, dword ptr [ebp - 0x32c]
00497053  dd8550feffff             fld       qword ptr [ebp - 0x1b0]
00497059  dc0cc538c8e400           fmul      qword ptr [eax*8 + 0xe4c838]
00497060  dd9d20feffff             fstp      qword ptr [ebp - 0x1e0]
00497066  dd8550feffff             fld       qword ptr [ebp - 0x1b0]
0049706c  dc0cc5e0c8e400           fmul      qword ptr [eax*8 + 0xe4c8e0]
00497073  dc8548feffff             fadd      qword ptr [ebp - 0x1b8]
00497079  d9c0                     fld       st(0)
0049707b  dca540feffff             fsub      qword ptr [ebp - 0x1c0]
00497081  d9c0                     fld       st(0)
00497083  dc8da8feffff             fmul      qword ptr [ebp - 0x158]
00497089  dcad38feffff             fsubr     qword ptr [ebp - 0x1c8]
0049708f  dd1588995b00             fst       qword ptr [0x5b9988] ; bits=0000000000000000, f64=0.0
00497095  dc1d30945b00             fcomp     qword ptr [0x5b9430] ; bits=0000000000000000, f64=0.0
0049709b  dd9d18feffff             fstp      qword ptr [ebp - 0x1e8]
004970a1  dd9d10feffff             fstp      qword ptr [ebp - 0x1f0]
004970a7  dfe0                     fnstsw    ax
004970a9  9e                       sahf
004970aa  0f8a89010000             jp        0x497239
004970b0  0f8383010000             jae       0x497239
004970b6  dbad2cfeffff             fld       xword ptr [ebp - 0x1d4]
004970bc  d81d74945b00             fcomp     dword ptr [0x5b9474] ; bits=cdcccc3d, f32=0.10000000149011612
004970c2  dfe0                     fnstsw    ax
004970c4  9e                       sahf
004970c5  0f8a1b000000             jp        0x4970e6
004970cb  7319                     jae       0x4970e6
004970cd  c70588995b0000000000     mov       dword ptr [0x5b9988], 0 ; bits=00000000, f32=0.0
004970d7  c7058c995b0000000000     mov       dword ptr [0x5b998c], 0 ; bits=00000000, f32=0.0
004970e1  e953010000               jmp       0x497239
004970e6  8b0588995b00             mov       eax, dword ptr [0x5b9988] ; bits=00000000, f32=0.0
004970ec  8b0d8c995b00             mov       ecx, dword ptr [0x5b998c] ; bits=00000000, f32=0.0
004970f2  8d155c985b00             lea       edx, [0x5b985c] ; bits=09820000, f32=4.664782457890884e-41
004970f8  8945f0                   mov       dword ptr [ebp - 0x10], eax
004970fb  894df4                   mov       dword ptr [ebp - 0xc], ecx
004970fe  8d45f0                   lea       eax, [ebp - 0x10]
00497101  894234                   mov       dword ptr [edx + 0x34], eax
00497104  52                       push      edx
00497105  e876bd0000               call      0x4a2e80 ; _jwe_ilst
0049710a  83c404                   add       esp, 4
0049710d  8b8dd4fcffff             mov       ecx, dword ptr [ebp - 0x32c]
00497113  8b0590c9e400             mov       eax, dword ptr [0xe4c990]
00497119  8b14cde0c8e400           mov       edx, dword ptr [ecx*8 + 0xe4c8e0]
00497120  8b1ccde4c8e400           mov       ebx, dword ptr [ecx*8 + 0xe4c8e4]
00497127  8d35f4975b00             lea       esi, [0x5b97f4] ; bits=09820000, f32=4.664782457890884e-41
0049712d  8945f8                   mov       dword ptr [ebp - 8], eax
00497130  8d45f8                   lea       eax, [ebp - 8]
00497133  894634                   mov       dword ptr [esi + 0x34], eax
00497136  894dec                   mov       dword ptr [ebp - 0x14], ecx
00497139  8d45ec                   lea       eax, [ebp - 0x14]
0049713c  89464c                   mov       dword ptr [esi + 0x4c], eax
0049713f  8955f0                   mov       dword ptr [ebp - 0x10], edx
00497142  895df4                   mov       dword ptr [ebp - 0xc], ebx
00497145  8d45f0                   lea       eax, [ebp - 0x10]
00497148  894664                   mov       dword ptr [esi + 0x64], eax
0049714b  56                       push      esi
0049714c  e82fbd0000               call      0x4a2e80 ; _jwe_ilst
00497151  83c404                   add       esp, 4
00497154  8d05a4975b00             lea       eax, [0x5b97a4] ; bits=09820000, f32=4.664782457890884e-41
0049715a  db6dac                   fld       xword ptr [ebp - 0x54]
0049715d  d95dfc                   fstp      dword ptr [ebp - 4]
00497160  8d4dfc                   lea       ecx, [ebp - 4]
00497163  894834                   mov       dword ptr [eax + 0x34], ecx
00497166  db6db8                   fld       xword ptr [ebp - 0x48]
00497169  d95de8                   fstp      dword ptr [ebp - 0x18]
0049716c  8d4de8                   lea       ecx, [ebp - 0x18]
0049716f  89484c                   mov       dword ptr [eax + 0x4c], ecx
00497172  50                       push      eax
00497173  e808bd0000               call      0x4a2e80 ; _jwe_ilst
00497178  83c404                   add       esp, 4
0049717b  8d0554975b00             lea       eax, [0x5b9754] ; bits=09820000, f32=4.664782457890884e-41
00497181  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00497187  d95dfc                   fstp      dword ptr [ebp - 4]
0049718a  8d4dfc                   lea       ecx, [ebp - 4]
0049718d  894834                   mov       dword ptr [eax + 0x34], ecx
00497190  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497193  d95de8                   fstp      dword ptr [ebp - 0x18]
00497196  8d4de8                   lea       ecx, [ebp - 0x18]
00497199  89484c                   mov       dword ptr [eax + 0x4c], ecx
0049719c  50                       push      eax
0049719d  e8debc0000               call      0x4a2e80 ; _jwe_ilst
004971a2  83c404                   add       esp, 4
004971a5  8b05a4995b00             mov       eax, dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
004971ab  8d0d04975b00             lea       ecx, [0x5b9704] ; bits=09820000, f32=4.664782457890884e-41
004971b1  dd8510feffff             fld       qword ptr [ebp - 0x1f0]
004971b7  dd5df0                   fstp      qword ptr [ebp - 0x10]
004971ba  8d55f0                   lea       edx, [ebp - 0x10]
004971bd  895134                   mov       dword ptr [ecx + 0x34], edx
004971c0  8945fc                   mov       dword ptr [ebp - 4], eax
004971c3  8d45fc                   lea       eax, [ebp - 4]
004971c6  89414c                   mov       dword ptr [ecx + 0x4c], eax
004971c9  51                       push      ecx
004971ca  e8b1bc0000               call      0x4a2e80 ; _jwe_ilst
004971cf  83c404                   add       esp, 4
004971d2  8d05b4965b00             lea       eax, [0x5b96b4] ; bits=09820000, f32=4.664782457890884e-41
004971d8  dd85a8feffff             fld       qword ptr [ebp - 0x158]
004971de  dd5df0                   fstp      qword ptr [ebp - 0x10]
004971e1  8d4df0                   lea       ecx, [ebp - 0x10]
004971e4  894834                   mov       dword ptr [eax + 0x34], ecx
004971e7  dbad7cfeffff             fld       xword ptr [ebp - 0x184]
004971ed  d95dfc                   fstp      dword ptr [ebp - 4]
004971f0  8d4dfc                   lea       ecx, [ebp - 4]
004971f3  89484c                   mov       dword ptr [eax + 0x4c], ecx
004971f6  50                       push      eax
004971f7  e884bc0000               call      0x4a2e80 ; _jwe_ilst
004971fc  83c404                   add       esp, 4
004971ff  8d0564965b00             lea       eax, [0x5b9664] ; bits=09820000, f32=4.664782457890884e-41
00497205  dbadc8feffff             fld       xword ptr [ebp - 0x138]
0049720b  d95dfc                   fstp      dword ptr [ebp - 4]
0049720e  8d4dfc                   lea       ecx, [ebp - 4]
00497211  894834                   mov       dword ptr [eax + 0x34], ecx
00497214  dbad70feffff             fld       xword ptr [ebp - 0x190]
0049721a  d95de8                   fstp      dword ptr [ebp - 0x18]
0049721d  8d4de8                   lea       ecx, [ebp - 0x18]
00497220  89484c                   mov       dword ptr [eax + 0x4c], ecx
00497223  50                       push      eax
00497224  e857bc0000               call      0x4a2e80 ; _jwe_ilst
00497229  83c404                   add       esp, 4
0049722c  684c965b00               push      0x5b964c
00497231  e80ac20000               call      0x4a3440 ; _jwe_xstp
00497236  83c404                   add       esp, 4
00497239  dd8588feffff             fld       qword ptr [ebp - 0x178]
0049723f  dc8d18feffff             fmul      qword ptr [ebp - 0x1e8]
00497245  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
0049724b  dec1                     faddp     st(1)
0049724d  dd9508feffff             fst       qword ptr [ebp - 0x1f8]
00497253  d9fa                     fsqrt
00497255  dd9d00feffff             fstp      qword ptr [ebp - 0x200]
0049725b  68c0935b00               push      0x5b93c0
00497260  6888995b00               push      0x5b9988
00497265  e8169f0000               call      0x4a1180 ; _g_adxd
0049726a  83c408                   add       esp, 8
0049726d  dc8d98feffff             fmul      qword ptr [ebp - 0x168]
00497273  d9c0                     fld       st(0)
00497275  dcb500feffff             fdiv      qword ptr [ebp - 0x200]
0049727b  dd8508feffff             fld       qword ptr [ebp - 0x1f8]
00497281  dc8d20feffff             fmul      qword ptr [ebp - 0x1e0]
00497287  d8c9                     fmul      st(1)
00497289  8b4578                   mov       eax, dword ptr [ebp + 0x78]
0049728c  dc00                     fadd      qword ptr [eax]
0049728e  dd18                     fstp      qword ptr [eax]
00497290  d9c0                     fld       st(0)
00497292  dc8d20feffff             fmul      qword ptr [ebp - 0x1e0]
00497298  8b455c                   mov       eax, dword ptr [ebp + 0x5c]
0049729b  d9c0                     fld       st(0)
0049729d  dc00                     fadd      qword ptr [eax]
0049729f  dd18                     fstp      qword ptr [eax]
004972a1  8b8584000000             mov       eax, dword ptr [ebp + 0x84]
004972a7  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
004972ab  dec1                     faddp     st(1)
004972ad  d95dfc                   fstp      dword ptr [ebp - 4]
004972b0  8b4dfc                   mov       ecx, dword ptr [ebp - 4]
004972b3  894c98fc                 mov       dword ptr [eax + ebx*4 - 4], ecx
004972b7  d9c9                     fxch      st(1)
004972b9  dc8d20feffff             fmul      qword ptr [ebp - 0x1e0]
004972bf  8b8588000000             mov       eax, dword ptr [ebp + 0x88]
004972c5  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
004972c9  dec1                     faddp     st(1)
004972cb  d95dfc                   fstp      dword ptr [ebp - 4]
004972ce  8b4dfc                   mov       ecx, dword ptr [ebp - 4]
004972d1  894c98fc                 mov       dword ptr [eax + ebx*4 - 4], ecx
004972d5  83bd1cfdffff01           cmp       dword ptr [ebp - 0x2e4], 1
004972dc  0f85d6010000             jne       0x4974b8
004972e2  dd0588995b00             fld       qword ptr [0x5b9988] ; bits=0000000000000000, f64=0.0
004972e8  dc1530945b00             fcom      qword ptr [0x5b9430] ; bits=0000000000000000, f64=0.0
004972ee  dd9df8fdffff             fstp      qword ptr [ebp - 0x208]
004972f4  dfe0                     fnstsw    ax
004972f6  9e                       sahf
004972f7  0f8a14000000             jp        0x497311
004972fd  7612                     jbe       0x497311
004972ff  d9c0                     fld       st(0)
00497301  dcb5f8fdffff             fdiv      qword ptr [ebp - 0x208]
00497307  d95dfc                   fstp      dword ptr [ebp - 4]
0049730a  d945fc                   fld       dword ptr [ebp - 4]
0049730d  d9c9                     fxch      st(1)
0049730f  eb04                     jmp       0x497315
00497311  d9ee                     fldz
00497313  d9c9                     fxch      st(1)
00497315  8b8518fdffff             mov       eax, dword ptr [ebp - 0x2e8]
0049731b  85c0                     test      eax, eax
0049731d  7417                     je        0x497336
0049731f  dd0588995b00             fld       qword ptr [0x5b9988] ; bits=0000000000000000, f64=0.0
00497325  d9ee                     fldz
00497327  d9c9                     fxch      st(1)
00497329  dae9                     fucompp
0049732b  dfe0                     fnstsw    ax
0049732d  9e                       sahf
0049732e  0f8a25000000             jp        0x497359
00497334  7523                     jne       0x497359
00497336  d9c1                     fld       st(1)
00497338  dcc9                     fmul      st(1), st(0)
0049733a  d9c0                     fld       st(0)
0049733c  d8ca                     fmul      st(2)
0049733e  dd9df0fdffff             fstp      qword ptr [ebp - 0x210]
00497344  d9c2                     fld       st(2)
00497346  d8c8                     fmul      st(0)
00497348  dcc9                     fmul      st(1), st(0)
0049734a  d9ca                     fxch      st(2)
0049734c  dd9de8fdffff             fstp      qword ptr [ebp - 0x218]
00497352  d9c9                     fxch      st(1)
00497354  e90c010000               jmp       0x497465
00497359  db7dd0                   fstp      xword ptr [ebp - 0x30]
0049735c  db7ddc                   fstp      xword ptr [ebp - 0x24]
0049735f  8d3518945b00             lea       esi, [0x5b9418] ; bits=00000000, f32=0.0
00497365  8d46b0                   lea       eax, [esi - 0x50]
00497368  50                       push      eax
00497369  6888995b00               push      0x5b9988
0049736e  e80d9e0000               call      0x4a1180 ; _g_adxd
00497373  dd9de0fdffff             fstp      qword ptr [ebp - 0x220]
00497379  83c408                   add       esp, 8
0049737c  dd85e0fdffff             fld       qword ptr [ebp - 0x220]
00497382  dc3d60995b00             fdivr     qword ptr [0x5b9960] ; bits=0000000000000000, f64=0.0
00497388  dc0510945b00             fadd      qword ptr [0x5b9410] ; bits=000000000000f03f, f64=1.0
0049738e  dd0588995b00             fld       qword ptr [0x5b9988] ; bits=0000000000000000, f64=0.0
00497394  d9fa                     fsqrt
00497396  dd95d8fdffff             fst       qword ptr [ebp - 0x228]
0049739c  dc3d68995b00             fdivr     qword ptr [0x5b9968] ; bits=0000000000000000, f64=0.0
004973a2  dec1                     faddp     st(1)
004973a4  dd9dd0fdffff             fstp      qword ptr [ebp - 0x230]
004973aa  8d46b8                   lea       eax, [esi - 0x48]
004973ad  50                       push      eax
004973ae  6888995b00               push      0x5b9988
004973b3  e8c89d0000               call      0x4a1180 ; _g_adxd
004973b8  83c408                   add       esp, 8
004973bb  dc4e08                   fmul      qword ptr [esi + 8]
004973be  d9c0                     fld       st(0)
004973c0  dc3d60995b00             fdivr     qword ptr [0x5b9960] ; bits=0000000000000000, f64=0.0
004973c6  d9e0                     fchs
004973c8  dd85d8fdffff             fld       qword ptr [ebp - 0x228]
004973ce  dc0d88995b00             fmul      qword ptr [0x5b9988] ; bits=0000000000000000, f64=0.0
004973d4  d8c0                     fadd      st(0)
004973d6  dc3d60995b00             fdivr     qword ptr [0x5b9960] ; bits=0000000000000000, f64=0.0
004973dc  dee9                     fsubp     st(1)
004973de  dd85e0fdffff             fld       qword ptr [ebp - 0x220]
004973e4  dc3d70995b00             fdivr     qword ptr [0x5b9970] ; bits=0000000000000000, f64=0.0
004973ea  dc0510945b00             fadd      qword ptr [0x5b9410] ; bits=000000000000f03f, f64=1.0
004973f0  d9ca                     fxch      st(2)
004973f2  dc3d70995b00             fdivr     qword ptr [0x5b9970] ; bits=0000000000000000, f64=0.0
004973f8  d9e0                     fchs
004973fa  db6ddc                   fld       xword ptr [ebp - 0x24]
004973fd  db6dd0                   fld       xword ptr [ebp - 0x30]
00497400  d8c9                     fmul      st(1)
00497402  dd9de8fdffff             fstp      qword ptr [ebp - 0x218]
00497408  d9c0                     fld       st(0)
0049740a  dc8de8fdffff             fmul      qword ptr [ebp - 0x218]
00497410  dd9df0fdffff             fstp      qword ptr [ebp - 0x210]
00497416  db6ddc                   fld       xword ptr [ebp - 0x24]
00497419  db6ddc                   fld       xword ptr [ebp - 0x24]
0049741c  dec9                     fmulp     st(1)
0049741e  dcc9                     fmul      st(1), st(0)
00497420  d9ca                     fxch      st(2)
00497422  dc8de8fdffff             fmul      qword ptr [ebp - 0x218]
00497428  d9ca                     fxch      st(2)
0049742a  d8cc                     fmul      st(4)
0049742c  dec2                     faddp     st(2)
0049742e  d9ca                     fxch      st(2)
00497430  dc8df0fdffff             fmul      qword ptr [ebp - 0x210]
00497436  d9ca                     fxch      st(2)
00497438  dc8dd0fdffff             fmul      qword ptr [ebp - 0x230]
0049743e  dec2                     faddp     st(2)
00497440  d9ca                     fxch      st(2)
00497442  dc8de8fdffff             fmul      qword ptr [ebp - 0x218]
00497448  dd9de8fdffff             fstp      qword ptr [ebp - 0x218]
0049744e  dd85d0fdffff             fld       qword ptr [ebp - 0x230]
00497454  dc8df0fdffff             fmul      qword ptr [ebp - 0x210]
0049745a  dd9df0fdffff             fstp      qword ptr [ebp - 0x210]
00497460  db6ddc                   fld       xword ptr [ebp - 0x24]
00497463  d9ca                     fxch      st(2)
00497465  d9ca                     fxch      st(2)
00497467  dc8d20feffff             fmul      qword ptr [ebp - 0x1e0]
0049746d  8b4568                   mov       eax, dword ptr [ebp + 0x68]
00497470  dc00                     fadd      qword ptr [eax]
00497472  dd18                     fstp      qword ptr [eax]
00497474  dd85e8fdffff             fld       qword ptr [ebp - 0x218]
0049747a  dc8d20feffff             fmul      qword ptr [ebp - 0x1e0]
00497480  8b4560                   mov       eax, dword ptr [ebp + 0x60]
00497483  dc00                     fadd      qword ptr [eax]
00497485  dd18                     fstp      qword ptr [eax]
00497487  dd85f0fdffff             fld       qword ptr [ebp - 0x210]
0049748d  dc8d20feffff             fmul      qword ptr [ebp - 0x1e0]
00497493  8b4564                   mov       eax, dword ptr [ebp + 0x64]
00497496  dc00                     fadd      qword ptr [eax]
00497498  dd18                     fstp      qword ptr [eax]
0049749a  d9c9                     fxch      st(1)
0049749c  dc8d20feffff             fmul      qword ptr [ebp - 0x1e0]
004974a2  8b456c                   mov       eax, dword ptr [ebp + 0x6c]
004974a5  dc00                     fadd      qword ptr [eax]
004974a7  dd18                     fstp      qword ptr [eax]
004974a9  dc8d20feffff             fmul      qword ptr [ebp - 0x1e0]
004974af  8b4570                   mov       eax, dword ptr [ebp + 0x70]
004974b2  dc00                     fadd      qword ptr [eax]
004974b4  dd18                     fstp      qword ptr [eax]
004974b6  eb02                     jmp       0x4974ba
004974b8  ddd8                     fstp      st(0)
004974ba  ff85d4fcffff             inc       dword ptr [ebp - 0x32c]
004974c0  83add8fcffff01           sub       dword ptr [ebp - 0x328], 1
004974c7  0f8580fbffff             jne       0x49704d
004974cd  eb19                     jmp       0x4974e8
004974cf  83bde8fcffff02           cmp       dword ptr [ebp - 0x318], 2
004974d6  7510                     jne       0x4974e8
004974d8  8b8580000000             mov       eax, dword ptr [ebp + 0x80]
004974de  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
004974e4  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
004974e8  8b4540                   mov       eax, dword ptr [ebp + 0x40]
004974eb  8d30                     lea       esi, [eax]
004974ed  8d3d6c955b00             lea       edi, [0x5b956c] ; bits=4e455742, f32=53.81768035888672
004974f3  b907000000               mov       ecx, 7
004974f8  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
004974fa  0f8584040000             jne       0x497984
00497500  83bde8fcffff01           cmp       dword ptr [ebp - 0x318], 1
00497507  0f8477040000             je        0x497984
0049750d  db6dac                   fld       xword ptr [ebp - 0x54]
00497510  db6db8                   fld       xword ptr [ebp - 0x48]
00497513  dee9                     fsubp     st(1)
00497515  d81540945b00             fcom      dword ptr [0x5b9440] ; bits=00000000, f32=0.0
0049751b  dbbdc8feffff             fstp      xword ptr [ebp - 0x138]
00497521  dfe0                     fnstsw    ax
00497523  9e                       sahf
00497524  0f8a5a040000             jp        0x497984
0049752a  0f8654040000             jbe       0x497984
00497530  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00497536  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497539  dee9                     fsubp     st(1)
0049753b  dbadc8feffff             fld       xword ptr [ebp - 0x138]
00497541  def9                     fdivp     st(1)
00497543  dd9da8feffff             fstp      qword ptr [ebp - 0x158]
00497549  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0049754c  837c98fc00               cmp       dword ptr [eax + ebx*4 - 4], 0
00497551  7e3e                     jle       0x497591
00497553  dd85a8feffff             fld       qword ptr [ebp - 0x158]
00497559  dc8da8feffff             fmul      qword ptr [ebp - 0x158]
0049755f  dc0510945b00             fadd      qword ptr [0x5b9410] ; bits=000000000000f03f, f64=1.0
00497565  dd5df0                   fstp      qword ptr [ebp - 0x10]
00497568  68e8935b00               push      0x5b93e8
0049756d  8d45f0                   lea       eax, [ebp - 0x10]
00497570  50                       push      eax
00497571  e80a9c0000               call      0x4a1180 ; _g_adxd
00497576  83c408                   add       esp, 8
00497579  8b4544                   mov       eax, dword ptr [ebp + 0x44]
0049757c  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
00497580  dec9                     fmulp     st(1)
00497582  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
00497585  d900                     fld       dword ptr [eax]
00497587  def1                     fdivrp    st(1)
00497589  dd9d98feffff             fstp      qword ptr [ebp - 0x168]
0049758f  eb42                     jmp       0x4975d3
00497591  dd85a8feffff             fld       qword ptr [ebp - 0x158]
00497597  dc8da8feffff             fmul      qword ptr [ebp - 0x158]
0049759d  dc0510945b00             fadd      qword ptr [0x5b9410] ; bits=000000000000f03f, f64=1.0
004975a3  dd5df0                   fstp      qword ptr [ebp - 0x10]
004975a6  68e8935b00               push      0x5b93e8
004975ab  8d45f0                   lea       eax, [ebp - 0x10]
004975ae  50                       push      eax
004975af  e8cc9b0000               call      0x4a1180 ; _g_adxd
004975b4  83c408                   add       esp, 8
004975b7  8b8d0cfdffff             mov       ecx, dword ptr [ebp - 0x2f4]
004975bd  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004975c0  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
004975c4  dec9                     fmulp     st(1)
004975c6  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
004975c9  d900                     fld       dword ptr [eax]
004975cb  def1                     fdivrp    st(1)
004975cd  dd9d98feffff             fstp      qword ptr [ebp - 0x168]
004975d3  83bde8fcffff02           cmp       dword ptr [ebp - 0x318], 2
004975da  751c                     jne       0x4975f8
004975dc  dd8598feffff             fld       qword ptr [ebp - 0x168]
004975e2  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
004975e8  d9fa                     fsqrt
004975ea  d95dfc                   fstp      dword ptr [ebp - 4]
004975ed  d945fc                   fld       dword ptr [ebp - 4]
004975f0  def9                     fdivp     st(1)
004975f2  dd9d98feffff             fstp      qword ptr [ebp - 0x168]
004975f8  dd85a8feffff             fld       qword ptr [ebp - 0x158]
004975fe  d9e1                     fabs
00497600  8d0518945b00             lea       eax, [0x5b9418] ; bits=00000000, f32=0.0
00497606  dc58c0                   fcomp     qword ptr [eax - 0x40]
00497609  8985d0fcffff             mov       dword ptr [ebp - 0x330], eax
0049760f  dfe0                     fnstsw    ax
00497611  9e                       sahf
00497612  0f8a17020000             jp        0x49782f
00497618  0f8611020000             jbe       0x49782f
0049761e  8b85d0fcffff             mov       eax, dword ptr [ebp - 0x330]
00497624  dd8598feffff             fld       qword ptr [ebp - 0x168]
0049762a  dc4808                   fmul      qword ptr [eax + 8]
0049762d  dd9dc8fdffff             fstp      qword ptr [ebp - 0x238]
00497633  dbadbcfeffff             fld       xword ptr [ebp - 0x144]
00497639  dd95c0fdffff             fst       qword ptr [ebp - 0x240]
0049763f  dd5df0                   fstp      qword ptr [ebp - 0x10]
00497642  8d5880                   lea       ebx, [eax - 0x80]
00497645  53                       push      ebx
00497646  8d4df0                   lea       ecx, [ebp - 0x10]
00497649  51                       push      ecx
0049764a  e8319b0000               call      0x4a1180 ; _g_adxd
0049764f  dd9db8fdffff             fstp      qword ptr [ebp - 0x248]
00497655  83c408                   add       esp, 8
00497658  d905a4995b00             fld       dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
0049765e  dd95b0fdffff             fst       qword ptr [ebp - 0x250]
00497664  dd5df0                   fstp      qword ptr [ebp - 0x10]
00497667  53                       push      ebx
00497668  8d45f0                   lea       eax, [ebp - 0x10]
0049766b  50                       push      eax
0049766c  e80f9b0000               call      0x4a1180 ; _g_adxd
00497671  83c408                   add       esp, 8
00497674  dcadb8fdffff             fsubr     qword ptr [ebp - 0x248]
0049767a  dc8dc8fdffff             fmul      qword ptr [ebp - 0x238]
00497680  8b85d0fcffff             mov       eax, dword ptr [ebp - 0x330]
00497686  dd85a8feffff             fld       qword ptr [ebp - 0x158]
0049768c  dc48e0                   fmul      qword ptr [eax - 0x20]
0049768f  def9                     fdivp     st(1)
00497691  8b4d5c                   mov       ecx, dword ptr [ebp + 0x5c]
00497694  dc29                     fsubr     qword ptr [ecx]
00497696  dd19                     fstp      qword ptr [ecx]
00497698  dd8598feffff             fld       qword ptr [ebp - 0x168]
0049769e  dc8d98feffff             fmul      qword ptr [ebp - 0x168]
004976a4  dd9da8fdffff             fstp      qword ptr [ebp - 0x258]
004976aa  dd85c0fdffff             fld       qword ptr [ebp - 0x240]
004976b0  dd5df0                   fstp      qword ptr [ebp - 0x10]
004976b3  8d5888                   lea       ebx, [eax - 0x78]
004976b6  53                       push      ebx
004976b7  8d4df0                   lea       ecx, [ebp - 0x10]
004976ba  51                       push      ecx
004976bb  e8c09a0000               call      0x4a1180 ; _g_adxd
004976c0  dd9da0fdffff             fstp      qword ptr [ebp - 0x260]
004976c6  83c408                   add       esp, 8
004976c9  dd85b0fdffff             fld       qword ptr [ebp - 0x250]
004976cf  dd5df0                   fstp      qword ptr [ebp - 0x10]
004976d2  53                       push      ebx
004976d3  8d45f0                   lea       eax, [ebp - 0x10]
004976d6  50                       push      eax
004976d7  e8a49a0000               call      0x4a1180 ; _g_adxd
004976dc  83c408                   add       esp, 8
004976df  dcada0fdffff             fsubr     qword ptr [ebp - 0x260]
004976e5  8b85d0fcffff             mov       eax, dword ptr [ebp - 0x330]
004976eb  dc48c8                   fmul      qword ptr [eax - 0x38]
004976ee  dc8da8fdffff             fmul      qword ptr [ebp - 0x258]
004976f4  dcb5a8feffff             fdiv      qword ptr [ebp - 0x158]
004976fa  8b4d60                   mov       ecx, dword ptr [ebp + 0x60]
004976fd  dc29                     fsubr     qword ptr [ecx]
004976ff  dd19                     fstp      qword ptr [ecx]
00497701  dd8598feffff             fld       qword ptr [ebp - 0x168]
00497707  dc8da8fdffff             fmul      qword ptr [ebp - 0x258]
0049770d  dd9d98fdffff             fstp      qword ptr [ebp - 0x268]
00497713  dd85c0fdffff             fld       qword ptr [ebp - 0x240]
00497719  dc8dc0fdffff             fmul      qword ptr [ebp - 0x240]
0049771f  dd9590fdffff             fst       qword ptr [ebp - 0x270]
00497725  dc8d90fdffff             fmul      qword ptr [ebp - 0x270]
0049772b  dd85b0fdffff             fld       qword ptr [ebp - 0x250]
00497731  dc8db0fdffff             fmul      qword ptr [ebp - 0x250]
00497737  dd9588fdffff             fst       qword ptr [ebp - 0x278]
0049773d  dc8d88fdffff             fmul      qword ptr [ebp - 0x278]
00497743  dee9                     fsubp     st(1)
00497745  dc48d8                   fmul      qword ptr [eax - 0x28]
00497748  dc8d98fdffff             fmul      qword ptr [ebp - 0x268]
0049774e  dcb5a8feffff             fdiv      qword ptr [ebp - 0x158]
00497754  8b4d64                   mov       ecx, dword ptr [ebp + 0x64]
00497757  dc29                     fsubr     qword ptr [ecx]
00497759  dd19                     fstp      qword ptr [ecx]
0049775b  dd85c0fdffff             fld       qword ptr [ebp - 0x240]
00497761  dd5df0                   fstp      qword ptr [ebp - 0x10]
00497764  8d5820                   lea       ebx, [eax + 0x20]
00497767  53                       push      ebx
00497768  8d4df0                   lea       ecx, [ebp - 0x10]
0049776b  51                       push      ecx
0049776c  e80f9a0000               call      0x4a1180 ; _g_adxd
00497771  dd9d80fdffff             fstp      qword ptr [ebp - 0x280]
00497777  83c408                   add       esp, 8
0049777a  dd85b0fdffff             fld       qword ptr [ebp - 0x250]
00497780  dd5df0                   fstp      qword ptr [ebp - 0x10]
00497783  53                       push      ebx
00497784  8d45f0                   lea       eax, [ebp - 0x10]
00497787  50                       push      eax
00497788  e8f3990000               call      0x4a1180 ; _g_adxd
0049778d  83c408                   add       esp, 8
00497790  dcad80fdffff             fsubr     qword ptr [ebp - 0x280]
00497796  dc8d98feffff             fmul      qword ptr [ebp - 0x168]
0049779c  dcb5a8feffff             fdiv      qword ptr [ebp - 0x158]
004977a2  8b4568                   mov       eax, dword ptr [ebp + 0x68]
004977a5  dc28                     fsubr     qword ptr [eax]
004977a7  dd18                     fstp      qword ptr [eax]
004977a9  dd85c0fdffff             fld       qword ptr [ebp - 0x240]
004977af  8b85d0fcffff             mov       eax, dword ptr [ebp - 0x330]
004977b5  dd5df0                   fstp      qword ptr [ebp - 0x10]
004977b8  8d5890                   lea       ebx, [eax - 0x70]
004977bb  53                       push      ebx
004977bc  8d45f0                   lea       eax, [ebp - 0x10]
004977bf  50                       push      eax
004977c0  e8bb990000               call      0x4a1180 ; _g_adxd
004977c5  dd9d78fdffff             fstp      qword ptr [ebp - 0x288]
004977cb  83c408                   add       esp, 8
004977ce  dd85b0fdffff             fld       qword ptr [ebp - 0x250]
004977d4  dd5df0                   fstp      qword ptr [ebp - 0x10]
004977d7  53                       push      ebx
004977d8  8d45f0                   lea       eax, [ebp - 0x10]
004977db  50                       push      eax
004977dc  e89f990000               call      0x4a1180 ; _g_adxd
004977e1  83c408                   add       esp, 8
004977e4  dcad78fdffff             fsubr     qword ptr [ebp - 0x288]
004977ea  dc8da8fdffff             fmul      qword ptr [ebp - 0x258]
004977f0  dcb5a8feffff             fdiv      qword ptr [ebp - 0x158]
004977f6  8b456c                   mov       eax, dword ptr [ebp + 0x6c]
004977f9  dc28                     fsubr     qword ptr [eax]
004977fb  dd18                     fstp      qword ptr [eax]
004977fd  dd85c0fdffff             fld       qword ptr [ebp - 0x240]
00497803  dc8d90fdffff             fmul      qword ptr [ebp - 0x270]
00497809  dd85b0fdffff             fld       qword ptr [ebp - 0x250]
0049780f  dc8d88fdffff             fmul      qword ptr [ebp - 0x278]
00497815  dee9                     fsubp     st(1)
00497817  dc8d98fdffff             fmul      qword ptr [ebp - 0x268]
0049781d  dcb5a8feffff             fdiv      qword ptr [ebp - 0x158]
00497823  8b4570                   mov       eax, dword ptr [ebp + 0x70]
00497826  dc28                     fsubr     qword ptr [eax]
00497828  dd18                     fstp      qword ptr [eax]
0049782a  e955010000               jmp       0x497984
0049782f  dbadc8feffff             fld       xword ptr [ebp - 0x138]
00497835  dd9d70fdffff             fstp      qword ptr [ebp - 0x290]
0049783b  dd8598feffff             fld       qword ptr [ebp - 0x168]
00497841  dc8d70fdffff             fmul      qword ptr [ebp - 0x290]
00497847  dd9d68fdffff             fstp      qword ptr [ebp - 0x298]
0049784d  8b85d0fcffff             mov       eax, dword ptr [ebp - 0x330]
00497853  89c1                     mov       ecx, eax
00497855  8d4934                   lea       ecx, [ecx + 0x34]
00497858  51                       push      ecx
00497859  68a4995b00               push      0x5b99a4
0049785e  e84d8f0000               call      0x4a07b0 ; _g_arxr
00497863  83c408                   add       esp, 8
00497866  dc8d68fdffff             fmul      qword ptr [ebp - 0x298]
0049786c  8b455c                   mov       eax, dword ptr [ebp + 0x5c]
0049786f  dc00                     fadd      qword ptr [eax]
00497871  dd18                     fstp      qword ptr [eax]
00497873  dd8598feffff             fld       qword ptr [ebp - 0x168]
00497879  dc8d98feffff             fmul      qword ptr [ebp - 0x168]
0049787f  dd9560fdffff             fst       qword ptr [ebp - 0x2a0]
00497885  dc8d70fdffff             fmul      qword ptr [ebp - 0x290]
0049788b  dd9d58fdffff             fstp      qword ptr [ebp - 0x2a8]
00497891  8b85d0fcffff             mov       eax, dword ptr [ebp - 0x330]
00497897  89c1                     mov       ecx, eax
00497899  8d4938                   lea       ecx, [ecx + 0x38]
0049789c  51                       push      ecx
0049789d  68a4995b00               push      0x5b99a4
004978a2  e8098f0000               call      0x4a07b0 ; _g_arxr
004978a7  83c408                   add       esp, 8
004978aa  dc8d58fdffff             fmul      qword ptr [ebp - 0x2a8]
004978b0  8b4560                   mov       eax, dword ptr [ebp + 0x60]
004978b3  dc00                     fadd      qword ptr [eax]
004978b5  dd18                     fstp      qword ptr [eax]
004978b7  dd8598feffff             fld       qword ptr [ebp - 0x168]
004978bd  dc8d60fdffff             fmul      qword ptr [ebp - 0x2a0]
004978c3  dc8d70fdffff             fmul      qword ptr [ebp - 0x290]
004978c9  dd9d50fdffff             fstp      qword ptr [ebp - 0x2b0]
004978cf  d905a4995b00             fld       dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
004978d5  d9c0                     fld       st(0)
004978d7  d80da4995b00             fmul      dword ptr [0x5b99a4] ; bits=00000000, f32=0.0
004978dd  dbbd44fdffff             fstp      xword ptr [ebp - 0x2bc]
004978e3  dbad44fdffff             fld       xword ptr [ebp - 0x2bc]
004978e9  dec9                     fmulp     st(1)
004978eb  dc8d50fdffff             fmul      qword ptr [ebp - 0x2b0]
004978f1  8b4564                   mov       eax, dword ptr [ebp + 0x64]
004978f4  dc00                     fadd      qword ptr [eax]
004978f6  dd18                     fstp      qword ptr [eax]
004978f8  8b85d0fcffff             mov       eax, dword ptr [ebp - 0x330]
004978fe  89c1                     mov       ecx, eax
00497900  dd8568fdffff             fld       qword ptr [ebp - 0x298]
00497906  dc4920                   fmul      qword ptr [ecx + 0x20]
00497909  dd9d38fdffff             fstp      qword ptr [ebp - 0x2c8]
0049790f  89c1                     mov       ecx, eax
00497911  8d4948                   lea       ecx, [ecx + 0x48]
00497914  51                       push      ecx
00497915  68a4995b00               push      0x5b99a4
0049791a  e8918e0000               call      0x4a07b0 ; _g_arxr
0049791f  83c408                   add       esp, 8
00497922  dc8d38fdffff             fmul      qword ptr [ebp - 0x2c8]
00497928  8b4568                   mov       eax, dword ptr [ebp + 0x68]
0049792b  dc00                     fadd      qword ptr [eax]
0049792d  dd18                     fstp      qword ptr [eax]
0049792f  8b85d0fcffff             mov       eax, dword ptr [ebp - 0x330]
00497935  89c1                     mov       ecx, eax
00497937  dd8558fdffff             fld       qword ptr [ebp - 0x2a8]
0049793d  dc4990                   fmul      qword ptr [ecx - 0x70]
00497940  dd9d30fdffff             fstp      qword ptr [ebp - 0x2d0]
00497946  89c1                     mov       ecx, eax
00497948  8d4930                   lea       ecx, [ecx + 0x30]
0049794b  51                       push      ecx
0049794c  68a4995b00               push      0x5b99a4
00497951  e85a8e0000               call      0x4a07b0 ; _g_arxr
00497956  83c408                   add       esp, 8
00497959  dc8d30fdffff             fmul      qword ptr [ebp - 0x2d0]
0049795f  8b456c                   mov       eax, dword ptr [ebp + 0x6c]
00497962  dc00                     fadd      qword ptr [eax]
00497964  dd18                     fstp      qword ptr [eax]
00497966  8b85d0fcffff             mov       eax, dword ptr [ebp - 0x330]
0049796c  dd8550fdffff             fld       qword ptr [ebp - 0x2b0]
00497972  dc4808                   fmul      qword ptr [eax + 8]
00497975  dbad44fdffff             fld       xword ptr [ebp - 0x2bc]
0049797b  dec9                     fmulp     st(1)
0049797d  8b4570                   mov       eax, dword ptr [ebp + 0x70]
00497980  dc00                     fadd      qword ptr [eax]
00497982  dd18                     fstp      qword ptr [eax]
00497984  ff850cfdffff             inc       dword ptr [ebp - 0x2f4]
0049798a  83adecfcffff01           sub       dword ptr [ebp - 0x314], 1
00497991  0f85dff0ffff             jne       0x496a76
00497997  8b852cfdffff             mov       eax, dword ptr [ebp - 0x2d4]
0049799d  833801                   cmp       dword ptr [eax], 1
004979a0  752d                     jne       0x4979cf
004979a2  83bd1cfdffff01           cmp       dword ptr [ebp - 0x2e4], 1
004979a9  7524                     jne       0x4979cf
004979ab  8b4568                   mov       eax, dword ptr [ebp + 0x68]
004979ae  8d0d18945b00             lea       ecx, [0x5b9418] ; bits=00000000, f32=0.0
004979b4  dd4120                   fld       qword ptr [ecx + 0x20]
004979b7  dc08                     fmul      qword ptr [eax]
004979b9  dd18                     fstp      qword ptr [eax]
004979bb  8b456c                   mov       eax, dword ptr [ebp + 0x6c]
004979be  dd4190                   fld       qword ptr [ecx - 0x70]
004979c1  dc08                     fmul      qword ptr [eax]
004979c3  dd18                     fstp      qword ptr [eax]
004979c5  8b4570                   mov       eax, dword ptr [ebp + 0x70]
004979c8  dd4108                   fld       qword ptr [ecx + 8]
004979cb  dc08                     fmul      qword ptr [eax]
004979cd  dd18                     fstp      qword ptr [eax]
004979cf  b800000000               mov       eax, 0
004979d4  5f                       pop       edi
004979d5  5e                       pop       esi
004979d6  5b                       pop       ebx
004979d7  8be5                     mov       esp, ebp
004979d9  5d                       pop       ebp
004979da  c3                       ret
004979db  0500000000               add       eax, 0
