; _sber_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x25820
00425820  55                       push      ebp
00425821  8bec                     mov       ebp, esp
00425823  53                       push      ebx
00425824  56                       push      esi
00425825  8b5d08                   mov       ebx, dword ptr [ebp + 8]
00425828  d903                     fld       dword ptr [ebx]
0042582a  d815a8b2e900             fcom      dword ptr [0xe9b2a8]
00425830  dfe0                     fnstsw    ax
00425832  66a90041                 test      ax, 0x4100
00425836  7508                     jne       0x425840
00425838  ddd8                     fstp      st(0)
0042583a  d905a8b2e900             fld       dword ptr [0xe9b2a8]
00425840  8d3500815600             lea       esi, [0x568100] ; bits=e8030000, f32=1.401298464324817e-42
00425846  d95eb4                   fstp      dword ptr [esi - 0x4c]
00425849  8d4690                   lea       eax, [esi - 0x70]
0042584c  50                       push      eax
0042584d  8d4688                   lea       eax, [esi - 0x78]
00425850  50                       push      eax
00425851  8d4694                   lea       eax, [esi - 0x6c]
00425854  50                       push      eax
00425855  8d468c                   lea       eax, [esi - 0x74]
00425858  50                       push      eax
00425859  8d4698                   lea       eax, [esi - 0x68]
0042585c  50                       push      eax
0042585d  8d46a8                   lea       eax, [esi - 0x58]
00425860  50                       push      eax
00425861  8d46a4                   lea       eax, [esi - 0x5c]
00425864  50                       push      eax
00425865  8d469c                   lea       eax, [esi - 0x64]
00425868  50                       push      eax
00425869  8d46ac                   lea       eax, [esi - 0x54]
0042586c  50                       push      eax
0042586d  8d4684                   lea       eax, [esi - 0x7c]
00425870  50                       push      eax
00425871  8d46b4                   lea       eax, [esi - 0x4c]
00425874  50                       push      eax
00425875  6884b2e900               push      0xe9b284
0042587a  e8215d0200               call      0x44b5a0 ; _xlktal_
0042587f  83c430                   add       esp, 0x30
00425882  d94684                   fld       dword ptr [esi - 0x7c]
00425885  d905a0b2e900             fld       dword ptr [0xe9b2a0]
0042588b  d9c9                     fxch      st(1)
0042588d  d815a0b2e900             fcom      dword ptr [0xe9b2a0]
00425893  d9c9                     fxch      st(1)
00425895  dfe0                     fnstsw    ax
00425897  9e                       sahf
00425898  0f8a34000000             jp        0x4258d2
0042589e  7332                     jae       0x4258d2
004258a0  d9c9                     fxch      st(1)
004258a2  d8c8                     fmul      st(0)
004258a4  d83d80805600             fdivr     dword ptr [0x568080] ; bits=0000803f, f32=1.0
004258aa  d9c9                     fxch      st(1)
004258ac  d8c8                     fmul      st(0)
004258ae  d83d80805600             fdivr     dword ptr [0x568080] ; bits=0000803f, f32=1.0
004258b4  dee9                     fsubp     st(1)
004258b6  d80d9cb2e900             fmul      dword ptr [0xe9b29c]
004258bc  d90588b2e900             fld       dword ptr [0xe9b288]
004258c2  d80d88b2e900             fmul      dword ptr [0xe9b288]
004258c8  dec9                     fmulp     st(1)
004258ca  d83534bcf400             fdiv      dword ptr [0xf4bc34]
004258d0  eb30                     jmp       0x425902
004258d2  d8c8                     fmul      st(0)
004258d4  d83d80805600             fdivr     dword ptr [0x568080] ; bits=0000803f, f32=1.0
004258da  d9c1                     fld       st(1)
004258dc  deca                     fmulp     st(2)
004258de  d9c9                     fxch      st(1)
004258e0  d83d80805600             fdivr     dword ptr [0x568080] ; bits=0000803f, f32=1.0
004258e6  dee9                     fsubp     st(1)
004258e8  d80d98b2e900             fmul      dword ptr [0xe9b298]
004258ee  d90588b2e900             fld       dword ptr [0xe9b288]
004258f4  d80d88b2e900             fmul      dword ptr [0xe9b288]
004258fa  dec9                     fmulp     st(1)
004258fc  d83534bcf400             fdiv      dword ptr [0xf4bc34]
00425902  d90588b2e900             fld       dword ptr [0xe9b288]
00425908  8d0500815600             lea       eax, [0x568100] ; bits=e8030000, f32=1.401298464324817e-42
0042590e  d94084                   fld       dword ptr [eax - 0x7c]
00425911  d83d88b2e900             fdivr     dword ptr [0xe9b288]
00425917  d8c8                     fmul      st(0)
00425919  d84888                   fmul      dword ptr [eax - 0x78]
0042591c  d83534bcf400             fdiv      dword ptr [0xf4bc34]
00425922  d803                     fadd      dword ptr [ebx]
00425924  d9c9                     fxch      st(1)
00425926  d8c8                     fmul      st(0)
00425928  d9058cb2e900             fld       dword ptr [0xe9b28c]
0042592e  d848a8                   fmul      dword ptr [eax - 0x58]
00425931  def9                     fdivp     st(1)
00425933  d80594b2e900             fadd      dword ptr [0xe9b294]
00425939  d80d90b2e900             fmul      dword ptr [0xe9b290]
0042593f  d80580b2e900             fadd      dword ptr [0xe9b280] ; _sberc_
00425945  dec2                     faddp     st(2)
00425947  dce1                     fsubr     st(1), st(0)
00425949  def9                     fdivp     st(1)
0042594b  5e                       pop       esi
0042594c  5b                       pop       ebx
0042594d  8be5                     mov       esp, ebp
0042594f  5d                       pop       ebp
00425950  c3                       ret
00425951  90                       nop
00425952  8da42400000000           lea       esp, [esp]
00425959  8da42400000000           lea       esp, [esp]
