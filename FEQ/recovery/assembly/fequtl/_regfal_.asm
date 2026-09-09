; _regfal_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x722f0
004722f0  55                       push      ebp
004722f1  8bec                     mov       ebp, esp
004722f3  b840000000               mov       eax, 0x40
004722f8  e8036d0700               call      0x4e9000 ; __alloca_probe
004722fd  53                       push      ebx
004722fe  56                       push      esi
004722ff  57                       push      edi
00472300  8b4508                   mov       eax, dword ptr [ebp + 8]
00472303  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00472306  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00472309  8945cc                   mov       dword ptr [ebp - 0x34], eax
0047230c  894dc8                   mov       dword ptr [ebp - 0x38], ecx
0047230f  8955c4                   mov       dword ptr [ebp - 0x3c], edx
00472312  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00472315  8945c0                   mov       dword ptr [ebp - 0x40], eax
00472318  c70000000000             mov       dword ptr [eax], 0
0047231e  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
00472321  8b09                     mov       ecx, dword ptr [ecx]
00472323  8d1d40f35900             lea       ebx, [0x59f340] ; bits=00000000, f32=0.0
00472329  894ba0                   mov       dword ptr [ebx - 0x60], ecx
0047232c  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
0047232f  8b09                     mov       ecx, dword ptr [ecx]
00472331  894ba4                   mov       dword ptr [ebx - 0x5c], ecx
00472334  8d4ba0                   lea       ecx, [ebx - 0x60]
00472337  51                       push      ecx
00472338  8b4dc4                   mov       ecx, dword ptr [ebp - 0x3c]
0047233b  ffd1                     call      ecx
0047233d  db7df4                   fstp      xword ptr [ebp - 0xc]
00472340  83c404                   add       esp, 4
00472343  8d43a4                   lea       eax, [ebx - 0x5c]
00472346  50                       push      eax
00472347  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
0047234a  ffd0                     call      eax
0047234c  83c404                   add       esp, 4
0047234f  db6df4                   fld       xword ptr [ebp - 0xc]
00472352  8b45c8                   mov       eax, dword ptr [ebp - 0x38]
00472355  d9e1                     fabs
00472357  d900                     fld       dword ptr [eax]
00472359  d9c9                     fxch      st(1)
0047235b  d818                     fcomp     dword ptr [eax]
0047235d  db6df4                   fld       xword ptr [ebp - 0xc]
00472360  d9c9                     fxch      st(1)
00472362  dfe0                     fnstsw    ax
00472364  9e                       sahf
00472365  0f8a15000000             jp        0x472380
0047236b  7713                     ja        0x472380
0047236d  ddd8                     fstp      st(0)
0047236f  ddd8                     fstp      st(0)
00472371  ddd8                     fstp      st(0)
00472373  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00472376  8b4ba0                   mov       ecx, dword ptr [ebx - 0x60]
00472379  8908                     mov       dword ptr [eax], ecx
0047237b  e93a020000               jmp       0x4725ba
00472380  d9c2                     fld       st(2)
00472382  d9e1                     fabs
00472384  ded9                     fcompp
00472386  dfe0                     fnstsw    ax
00472388  9e                       sahf
00472389  0f8a15000000             jp        0x4723a4
0047238f  7713                     ja        0x4723a4
00472391  ddd8                     fstp      st(0)
00472393  ddd8                     fstp      st(0)
00472395  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00472398  89d9                     mov       ecx, ebx
0047239a  8b49a4                   mov       ecx, dword ptr [ecx - 0x5c]
0047239d  8908                     mov       dword ptr [eax], ecx
0047239f  e916020000               jmp       0x4725ba
004723a4  d9c0                     fld       st(0)
004723a6  d9c2                     fld       st(2)
004723a8  d8ca                     fmul      st(2)
004723aa  d81dc4f25900             fcomp     dword ptr [0x59f2c4] ; bits=00000000, f32=0.0
004723b0  dfe0                     fnstsw    ax
004723b2  9e                       sahf
004723b3  0f8a16000000             jp        0x4723cf
004723b9  7614                     jbe       0x4723cf
004723bb  ddd8                     fstp      st(0)
004723bd  ddd8                     fstp      st(0)
004723bf  8b45c0                   mov       eax, dword ptr [ebp - 0x40]
004723c2  ddd8                     fstp      st(0)
004723c4  c70001000000             mov       dword ptr [eax], 1
004723ca  e9eb010000               jmp       0x4725ba
004723cf  bb00000000               mov       ebx, 0
004723d4  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
004723d7  d900                     fld       dword ptr [eax]
004723d9  8b751c                   mov       esi, dword ptr [ebp + 0x1c]
004723dc  db7dd0                   fstp      xword ptr [ebp - 0x30]
004723df  db7ddc                   fstp      xword ptr [ebp - 0x24]
004723e2  db7de8                   fstp      xword ptr [ebp - 0x18]
004723e5  db7df4                   fstp      xword ptr [ebp - 0xc]
004723e8  8d3d40f35900             lea       edi, [0x59f340] ; bits=00000000, f32=0.0
004723ee  db6df4                   fld       xword ptr [ebp - 0xc]
004723f1  d84fa0                   fmul      dword ptr [edi - 0x60]
004723f4  db6de8                   fld       xword ptr [ebp - 0x18]
004723f7  d84fa4                   fmul      dword ptr [edi - 0x5c]
004723fa  dee9                     fsubp     st(1)
004723fc  db6df4                   fld       xword ptr [ebp - 0xc]
004723ff  db6de8                   fld       xword ptr [ebp - 0x18]
00472402  dee9                     fsubp     st(1)
00472404  def9                     fdivp     st(1)
00472406  d91e                     fstp      dword ptr [esi]
00472408  8d06                     lea       eax, [esi]
0047240a  50                       push      eax
0047240b  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
0047240e  ffd0                     call      eax
00472410  83c404                   add       esp, 4
00472413  d947a0                   fld       dword ptr [edi - 0x60]
00472416  d9c0                     fld       st(0)
00472418  d9e1                     fabs
0047241a  d947a4                   fld       dword ptr [edi - 0x5c]
0047241d  d9c0                     fld       st(0)
0047241f  d9e1                     fabs
00472421  dec2                     faddp     st(2)
00472423  deea                     fsubp     st(2)
00472425  d9c9                     fxch      st(1)
00472427  d9e1                     fabs
00472429  def1                     fdivrp    st(1)
0047242b  db6dd0                   fld       xword ptr [ebp - 0x30]
0047242e  d9c9                     fxch      st(1)
00472430  ded9                     fcompp
00472432  db6df4                   fld       xword ptr [ebp - 0xc]
00472435  db6de8                   fld       xword ptr [ebp - 0x18]
00472438  db6ddc                   fld       xword ptr [ebp - 0x24]
0047243b  db6dd0                   fld       xword ptr [ebp - 0x30]
0047243e  d9cb                     fxch      st(3)
00472440  d9cc                     fxch      st(4)
00472442  d9ca                     fxch      st(2)
00472444  d9cb                     fxch      st(3)
00472446  dfe0                     fnstsw    ax
00472448  9e                       sahf
00472449  0f8a27000000             jp        0x472476
0047244f  7325                     jae       0x472476
00472451  ddd8                     fstp      st(0)
00472453  ddd8                     fstp      st(0)
00472455  ddd8                     fstp      st(0)
00472457  ddd8                     fstp      st(0)
00472459  ddd8                     fstp      st(0)
0047245b  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0047245e  8d0d40f35900             lea       ecx, [0x59f340] ; bits=00000000, f32=0.0
00472464  8b51a0                   mov       edx, dword ptr [ecx - 0x60]
00472467  8910                     mov       dword ptr [eax], edx
00472469  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047246c  8b49a4                   mov       ecx, dword ptr [ecx - 0x5c]
0047246f  8908                     mov       dword ptr [eax], ecx
00472471  e944010000               jmp       0x4725ba
00472476  d9c2                     fld       st(2)
00472478  8b45c8                   mov       eax, dword ptr [ebp - 0x38]
0047247b  d9e1                     fabs
0047247d  d818                     fcomp     dword ptr [eax]
0047247f  dfe0                     fnstsw    ax
00472481  9e                       sahf
00472482  0f8a27000000             jp        0x4724af
00472488  7325                     jae       0x4724af
0047248a  ddd8                     fstp      st(0)
0047248c  ddd8                     fstp      st(0)
0047248e  ddd8                     fstp      st(0)
00472490  ddd8                     fstp      st(0)
00472492  ddd8                     fstp      st(0)
00472494  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00472497  8d0d40f35900             lea       ecx, [0x59f340] ; bits=00000000, f32=0.0
0047249d  8b51a0                   mov       edx, dword ptr [ecx - 0x60]
004724a0  8910                     mov       dword ptr [eax], edx
004724a2  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004724a5  8b49a4                   mov       ecx, dword ptr [ecx - 0x5c]
004724a8  8908                     mov       dword ptr [eax], ecx
004724aa  e90b010000               jmp       0x4725ba
004724af  d9ee                     fldz
004724b1  d9cc                     fxch      st(4)
004724b3  dde4                     fucom     st(4)
004724b5  d9cc                     fxch      st(4)
004724b7  d9c9                     fxch      st(1)
004724b9  dfe0                     fnstsw    ax
004724bb  9e                       sahf
004724bc  0f8a02000000             jp        0x4724c4
004724c2  741f                     je        0x4724e3
004724c4  d9cd                     fxch      st(5)
004724c6  dde1                     fucom     st(1)
004724c8  d9cd                     fxch      st(5)
004724ca  dfe0                     fnstsw    ax
004724cc  9e                       sahf
004724cd  0f8a37000000             jp        0x47250a
004724d3  7535                     jne       0x47250a
004724d5  ddd8                     fstp      st(0)
004724d7  ddd8                     fstp      st(0)
004724d9  ddd8                     fstp      st(0)
004724db  ddd8                     fstp      st(0)
004724dd  ddd8                     fstp      st(0)
004724df  ddd8                     fstp      st(0)
004724e1  eb0c                     jmp       0x4724ef
004724e3  ddd8                     fstp      st(0)
004724e5  ddd8                     fstp      st(0)
004724e7  ddd8                     fstp      st(0)
004724e9  ddd8                     fstp      st(0)
004724eb  ddd8                     fstp      st(0)
004724ed  ddd8                     fstp      st(0)
004724ef  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004724f2  8d0d40f35900             lea       ecx, [0x59f340] ; bits=00000000, f32=0.0
004724f8  8b51a0                   mov       edx, dword ptr [ecx - 0x60]
004724fb  8910                     mov       dword ptr [eax], edx
004724fd  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00472500  8b49a4                   mov       ecx, dword ptr [ecx - 0x5c]
00472503  8908                     mov       dword ptr [eax], ecx
00472505  e9b0000000               jmp       0x4725ba
0047250a  43                       inc       ebx
0047250b  83fb64                   cmp       ebx, 0x64
0047250e  7e2d                     jle       0x47253d
00472510  ddd8                     fstp      st(0)
00472512  ddd8                     fstp      st(0)
00472514  ddd8                     fstp      st(0)
00472516  ddd8                     fstp      st(0)
00472518  ddd8                     fstp      st(0)
0047251a  ddd8                     fstp      st(0)
0047251c  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0047251f  8d0d40f35900             lea       ecx, [0x59f340] ; bits=00000000, f32=0.0
00472525  8b51a0                   mov       edx, dword ptr [ecx - 0x60]
00472528  8910                     mov       dword ptr [eax], edx
0047252a  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047252d  8b49a4                   mov       ecx, dword ptr [ecx - 0x5c]
00472530  8908                     mov       dword ptr [eax], ecx
00472532  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00472535  c70002000000             mov       dword ptr [eax], 2
0047253b  eb7d                     jmp       0x4725ba
0047253d  d9c3                     fld       st(3)
0047253f  d8cd                     fmul      st(5)
00472541  d8da                     fcomp     st(2)
00472543  ddd9                     fstp      st(1)
00472545  dfe0                     fnstsw    ax
00472547  9e                       sahf
00472548  0f8a37000000             jp        0x472585
0047254e  7735                     ja        0x472585
00472550  dddc                     fstp      st(4)
00472552  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00472555  8b00                     mov       eax, dword ptr [eax]
00472557  8d0d40f35900             lea       ecx, [0x59f340] ; bits=00000000, f32=0.0
0047255d  8941a4                   mov       dword ptr [ecx - 0x5c], eax
00472560  d9c1                     fld       st(1)
00472562  d9c9                     fxch      st(1)
00472564  d8ca                     fmul      st(2)
00472566  d81dc4f25900             fcomp     dword ptr [0x59f2c4] ; bits=00000000, f32=0.0
0047256c  d9cb                     fxch      st(3)
0047256e  dfe0                     fnstsw    ax
00472570  9e                       sahf
00472571  0f8a09000000             jp        0x472580
00472577  7607                     jbe       0x472580
00472579  d9ca                     fxch      st(2)
0047257b  d8498c                   fmul      dword ptr [ecx - 0x74]
0047257e  d9ca                     fxch      st(2)
00472580  e957feffff               jmp       0x4723dc
00472585  dddb                     fstp      st(3)
00472587  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0047258a  8b00                     mov       eax, dword ptr [eax]
0047258c  8d0d40f35900             lea       ecx, [0x59f340] ; bits=00000000, f32=0.0
00472592  8941a0                   mov       dword ptr [ecx - 0x60], eax
00472595  d9c1                     fld       st(1)
00472597  d9c9                     fxch      st(1)
00472599  d8ca                     fmul      st(2)
0047259b  d81dc4f25900             fcomp     dword ptr [0x59f2c4] ; bits=00000000, f32=0.0
004725a1  d9ca                     fxch      st(2)
004725a3  dfe0                     fnstsw    ax
004725a5  9e                       sahf
004725a6  0f8a09000000             jp        0x4725b5
004725ac  7607                     jbe       0x4725b5
004725ae  d9cb                     fxch      st(3)
004725b0  d8498c                   fmul      dword ptr [ecx - 0x74]
004725b3  d9cb                     fxch      st(3)
004725b5  e922feffff               jmp       0x4723dc
004725ba  b800000000               mov       eax, 0
004725bf  5f                       pop       edi
004725c0  5e                       pop       esi
004725c1  5b                       pop       ebx
004725c2  8be5                     mov       esp, ebp
004725c4  5d                       pop       ebp
004725c5  c3                       ret
004725c6  8d4900                   lea       ecx, [ecx]
004725c9  8da42400000000           lea       esp, [esp]
