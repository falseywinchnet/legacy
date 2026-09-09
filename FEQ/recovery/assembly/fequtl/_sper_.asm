; _sper_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x25fe0
00425fe0  55                       push      ebp
00425fe1  8bec                     mov       ebp, esp
00425fe3  53                       push      ebx
00425fe4  56                       push      esi
00425fe5  8b5d08                   mov       ebx, dword ptr [ebp + 8]
00425fe8  d903                     fld       dword ptr [ebx]
00425fea  d81568b2e900             fcom      dword ptr [0xe9b268]
00425ff0  dfe0                     fnstsw    ax
00425ff2  66a90041                 test      ax, 0x4100
00425ff6  7508                     jne       0x426000
00425ff8  ddd8                     fstp      st(0)
00425ffa  d90568b2e900             fld       dword ptr [0xe9b268]
00426000  8d35e0835600             lea       esi, [0x5683e0] ; bits=4556203e, f32=0.15657909214496613
00426006  d95eb4                   fstp      dword ptr [esi - 0x4c]
00426009  8d4690                   lea       eax, [esi - 0x70]
0042600c  50                       push      eax
0042600d  8d4688                   lea       eax, [esi - 0x78]
00426010  50                       push      eax
00426011  8d4694                   lea       eax, [esi - 0x6c]
00426014  50                       push      eax
00426015  8d468c                   lea       eax, [esi - 0x74]
00426018  50                       push      eax
00426019  8d4698                   lea       eax, [esi - 0x68]
0042601c  50                       push      eax
0042601d  8d46a8                   lea       eax, [esi - 0x58]
00426020  50                       push      eax
00426021  8d46a4                   lea       eax, [esi - 0x5c]
00426024  50                       push      eax
00426025  8d469c                   lea       eax, [esi - 0x64]
00426028  50                       push      eax
00426029  8d46ac                   lea       eax, [esi - 0x54]
0042602c  50                       push      eax
0042602d  8d4684                   lea       eax, [esi - 0x7c]
00426030  50                       push      eax
00426031  8d46b4                   lea       eax, [esi - 0x4c]
00426034  50                       push      eax
00426035  6844b2e900               push      0xe9b244
0042603a  e861550200               call      0x44b5a0 ; _xlktal_
0042603f  83c430                   add       esp, 0x30
00426042  d90558b2e900             fld       dword ptr [0xe9b258]
00426048  d94684                   fld       dword ptr [esi - 0x7c]
0042604b  d9c9                     fxch      st(1)
0042604d  d85684                   fcom      dword ptr [esi - 0x7c]
00426050  d9c9                     fxch      st(1)
00426052  dfe0                     fnstsw    ax
00426054  9e                       sahf
00426055  0f8a34000000             jp        0x42608f
0042605b  7332                     jae       0x42608f
0042605d  d9c9                     fxch      st(1)
0042605f  d8c8                     fmul      st(0)
00426061  d83d60835600             fdivr     dword ptr [0x568360] ; bits=0000803f, f32=1.0
00426067  d9c9                     fxch      st(1)
00426069  d8c8                     fmul      st(0)
0042606b  d83d60835600             fdivr     dword ptr [0x568360] ; bits=0000803f, f32=1.0
00426071  dee9                     fsubp     st(1)
00426073  d80d64b2e900             fmul      dword ptr [0xe9b264]
00426079  d90548b2e900             fld       dword ptr [0xe9b248]
0042607f  d80d48b2e900             fmul      dword ptr [0xe9b248]
00426085  dec9                     fmulp     st(1)
00426087  d83534bcf400             fdiv      dword ptr [0xf4bc34]
0042608d  eb30                     jmp       0x4260bf
0042608f  d9c0                     fld       st(0)
00426091  dec9                     fmulp     st(1)
00426093  d83d60835600             fdivr     dword ptr [0x568360] ; bits=0000803f, f32=1.0
00426099  d9c9                     fxch      st(1)
0042609b  d8c8                     fmul      st(0)
0042609d  d83d60835600             fdivr     dword ptr [0x568360] ; bits=0000803f, f32=1.0
004260a3  dee9                     fsubp     st(1)
004260a5  d80d60b2e900             fmul      dword ptr [0xe9b260]
004260ab  d90548b2e900             fld       dword ptr [0xe9b248]
004260b1  d80d48b2e900             fmul      dword ptr [0xe9b248]
004260b7  dec9                     fmulp     st(1)
004260b9  d83534bcf400             fdiv      dword ptr [0xf4bc34]
004260bf  8d05e0835600             lea       eax, [0x5683e0] ; bits=4556203e, f32=0.15657909214496613
004260c5  d94084                   fld       dword ptr [eax - 0x7c]
004260c8  d83d48b2e900             fdivr     dword ptr [0xe9b248]
004260ce  d8c8                     fmul      st(0)
004260d0  d84888                   fmul      dword ptr [eax - 0x78]
004260d3  d83534bcf400             fdiv      dword ptr [0xf4bc34]
004260d9  d803                     fadd      dword ptr [ebx]
004260db  d9054cb2e900             fld       dword ptr [0xe9b24c]
004260e1  d80d48b2e900             fmul      dword ptr [0xe9b248]
004260e7  d90550b2e900             fld       dword ptr [0xe9b250]
004260ed  d848a8                   fmul      dword ptr [eax - 0x58]
004260f0  def9                     fdivp     st(1)
004260f2  d8056cb2e900             fadd      dword ptr [0xe9b26c]
004260f8  d80d54b2e900             fmul      dword ptr [0xe9b254]
004260fe  d8c1                     fadd      st(1)
00426100  dec2                     faddp     st(2)
00426102  d9c9                     fxch      st(1)
00426104  d82d40b2e900             fsubr     dword ptr [0xe9b240] ; _sperc_
0042610a  def1                     fdivrp    st(1)
0042610c  5e                       pop       esi
0042610d  5b                       pop       ebx
0042610e  8be5                     mov       esp, ebp
00426110  5d                       pop       ebp
00426111  c3                       ret
00426112  8da42400000000           lea       esp, [esp]
00426119  8da42400000000           lea       esp, [esp]
