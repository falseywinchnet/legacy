; _regflt_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x725d0
004725d0  55                       push      ebp
004725d1  8bec                     mov       ebp, esp
004725d3  b840000000               mov       eax, 0x40
004725d8  e8236a0700               call      0x4e9000 ; __alloca_probe
004725dd  53                       push      ebx
004725de  56                       push      esi
004725df  57                       push      edi
004725e0  8b7508                   mov       esi, dword ptr [ebp + 8]
004725e3  8b450c                   mov       eax, dword ptr [ebp + 0xc]
004725e6  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
004725e9  8945d8                   mov       dword ptr [ebp - 0x28], eax
004725ec  894dd4                   mov       dword ptr [ebp - 0x2c], ecx
004725ef  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004725f2  c70000000000             mov       dword ptr [eax], 0
004725f8  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
004725fb  d901                     fld       dword ptr [ecx]
004725fd  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
00472600  d901                     fld       dword ptr [ecx]
00472602  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
00472605  d901                     fld       dword ptr [ecx]
00472607  8b5520                   mov       edx, dword ptr [ebp + 0x20]
0047260a  d902                     fld       dword ptr [edx]
0047260c  d809                     fmul      dword ptr [ecx]
0047260e  d81decf25900             fcomp     dword ptr [0x59f2ec] ; bits=00000000, f32=0.0
00472614  8945d0                   mov       dword ptr [ebp - 0x30], eax
00472617  dfe0                     fnstsw    ax
00472619  9e                       sahf
0047261a  894dcc                   mov       dword ptr [ebp - 0x34], ecx
0047261d  8955c8                   mov       dword ptr [ebp - 0x38], edx
00472620  0f8a16000000             jp        0x47263c
00472626  7614                     jbe       0x47263c
00472628  ddd8                     fstp      st(0)
0047262a  ddd8                     fstp      st(0)
0047262c  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
0047262f  ddd8                     fstp      st(0)
00472631  c70001000000             mov       dword ptr [eax], 1
00472637  e9f3010000               jmp       0x47282f
0047263c  bb00000000               mov       ebx, 0
00472641  8b45c8                   mov       eax, dword ptr [ebp - 0x38]
00472644  8945c4                   mov       dword ptr [ebp - 0x3c], eax
00472647  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
0047264a  8945c0                   mov       dword ptr [ebp - 0x40], eax
0047264d  db7ddc                   fstp      xword ptr [ebp - 0x24]
00472650  db7de8                   fstp      xword ptr [ebp - 0x18]
00472653  db7df4                   fstp      xword ptr [ebp - 0xc]
00472656  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
00472659  db6df4                   fld       xword ptr [ebp - 0xc]
0047265c  d808                     fmul      dword ptr [eax]
0047265e  8b4dc0                   mov       ecx, dword ptr [ebp - 0x40]
00472661  db6de8                   fld       xword ptr [ebp - 0x18]
00472664  d809                     fmul      dword ptr [ecx]
00472666  dee9                     fsubp     st(1)
00472668  8b5520                   mov       edx, dword ptr [ebp + 0x20]
0047266b  8b7d1c                   mov       edi, dword ptr [ebp + 0x1c]
0047266e  d907                     fld       dword ptr [edi]
00472670  d82a                     fsubr     dword ptr [edx]
00472672  def9                     fdivp     st(1)
00472674  8b5524                   mov       edx, dword ptr [ebp + 0x24]
00472677  d91a                     fstp      dword ptr [edx]
00472679  8d12                     lea       edx, [edx]
0047267b  52                       push      edx
0047267c  8b55d4                   mov       edx, dword ptr [ebp - 0x2c]
0047267f  ffd2                     call      edx
00472681  83c404                   add       esp, 4
00472684  d815f8f25900             fcom      dword ptr [0x59f2f8] ; bits=cded47f1, f32=-9.900000073412052e+29
0047268a  db6df4                   fld       xword ptr [ebp - 0xc]
0047268d  db6de8                   fld       xword ptr [ebp - 0x18]
00472690  db6ddc                   fld       xword ptr [ebp - 0x24]
00472693  dfe0                     fnstsw    ax
00472695  9e                       sahf
00472696  0f8a18000000             jp        0x4726b4
0047269c  7316                     jae       0x4726b4
0047269e  ddd8                     fstp      st(0)
004726a0  ddd8                     fstp      st(0)
004726a2  ddd8                     fstp      st(0)
004726a4  ddd8                     fstp      st(0)
004726a6  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004726a9  c70003000000             mov       dword ptr [eax], 3
004726af  e97b010000               jmp       0x47282f
004726b4  d9ee                     fldz
004726b6  d9cc                     fxch      st(4)
004726b8  dde4                     fucom     st(4)
004726ba  dddc                     fstp      st(4)
004726bc  dfe0                     fnstsw    ax
004726be  9e                       sahf
004726bf  0f8a1a000000             jp        0x4726df
004726c5  7518                     jne       0x4726df
004726c7  ddd8                     fstp      st(0)
004726c9  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004726cc  d9c9                     fxch      st(1)
004726ce  d918                     fstp      dword ptr [eax]
004726d0  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004726d3  d918                     fstp      dword ptr [eax]
004726d5  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004726d8  d918                     fstp      dword ptr [eax]
004726da  e950010000               jmp       0x47282f
004726df  d9c3                     fld       st(3)
004726e1  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
004726e4  d9e1                     fabs
004726e6  d818                     fcomp     dword ptr [eax]
004726e8  dfe0                     fnstsw    ax
004726ea  9e                       sahf
004726eb  0f8a1a000000             jp        0x47270b
004726f1  7318                     jae       0x47270b
004726f3  ddd8                     fstp      st(0)
004726f5  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004726f8  d9c9                     fxch      st(1)
004726fa  d918                     fstp      dword ptr [eax]
004726fc  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004726ff  d918                     fstp      dword ptr [eax]
00472701  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00472704  d918                     fstp      dword ptr [eax]
00472706  e924010000               jmp       0x47282f
0047270b  d9c2                     fld       st(2)
0047270d  d9e1                     fabs
0047270f  d9c2                     fld       st(2)
00472711  d9e1                     fabs
00472713  dec1                     faddp     st(1)
00472715  d9c3                     fld       st(3)
00472717  d8e3                     fsub      st(3)
00472719  d9e1                     fabs
0047271b  def1                     fdivrp    st(1)
0047271d  d81e                     fcomp     dword ptr [esi]
0047271f  dfe0                     fnstsw    ax
00472721  9e                       sahf
00472722  0f8a4f000000             jp        0x472777
00472728  734d                     jae       0x472777
0047272a  ddd8                     fstp      st(0)
0047272c  ddda                     fstp      st(2)
0047272e  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00472731  d910                     fst       dword ptr [eax]
00472733  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00472736  d9c9                     fxch      st(1)
00472738  d910                     fst       dword ptr [eax]
0047273a  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
0047273d  d901                     fld       dword ptr [ecx]
0047273f  d9e1                     fabs
00472741  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00472744  d900                     fld       dword ptr [eax]
00472746  d9c0                     fld       st(0)
00472748  d9e1                     fabs
0047274a  d9ca                     fxch      st(2)
0047274c  d8da                     fcomp     st(2)
0047274e  ddd9                     fstp      st(1)
00472750  dfe0                     fnstsw    ax
00472752  9e                       sahf
00472753  0f8a10000000             jp        0x472769
00472759  730e                     jae       0x472769
0047275b  ddd8                     fstp      st(0)
0047275d  ddd8                     fstp      st(0)
0047275f  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00472762  d918                     fstp      dword ptr [eax]
00472764  e9c6000000               jmp       0x47282f
00472769  ddda                     fstp      st(2)
0047276b  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0047276e  d918                     fstp      dword ptr [eax]
00472770  d919                     fstp      dword ptr [ecx]
00472772  e9b8000000               jmp       0x47282f
00472777  43                       inc       ebx
00472778  83fb64                   cmp       ebx, 0x64
0047277b  7e1c                     jle       0x472799
0047277d  ddd8                     fstp      st(0)
0047277f  ddda                     fstp      st(2)
00472781  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00472784  d918                     fstp      dword ptr [eax]
00472786  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00472789  d918                     fstp      dword ptr [eax]
0047278b  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0047278e  c70002000000             mov       dword ptr [eax], 2
00472794  e996000000               jmp       0x47282f
00472799  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
0047279c  d901                     fld       dword ptr [ecx]
0047279e  d9c4                     fld       st(4)
004727a0  d809                     fmul      dword ptr [ecx]
004727a2  d9ee                     fldz
004727a4  d9c9                     fxch      st(1)
004727a6  d81decf25900             fcomp     dword ptr [0x59f2ec] ; bits=00000000, f32=0.0
004727ac  d9c9                     fxch      st(1)
004727ae  dfe0                     fnstsw    ax
004727b0  9e                       sahf
004727b1  0f8a3a000000             jp        0x4727f1
004727b7  7738                     ja        0x4727f1
004727b9  dddb                     fstp      st(3)
004727bb  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004727be  d900                     fld       dword ptr [eax]
004727c0  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004727c3  d9cd                     fxch      st(5)
004727c5  d910                     fst       dword ptr [eax]
004727c7  dcca                     fmul      st(2), st(0)
004727c9  d9ca                     fxch      st(2)
004727cb  ded9                     fcompp
004727cd  d9cb                     fxch      st(3)
004727cf  d9c9                     fxch      st(1)
004727d1  dfe0                     fnstsw    ax
004727d3  9e                       sahf
004727d4  0f8a0c000000             jp        0x4727e6
004727da  760a                     jbe       0x4727e6
004727dc  d80df4f25900             fmul      dword ptr [0x59f2f4] ; bits=6666663f, f32=0.8999999761581421
004727e2  d919                     fstp      dword ptr [ecx]
004727e4  eb02                     jmp       0x4727e8
004727e6  ddd8                     fstp      st(0)
004727e8  d9c9                     fxch      st(1)
004727ea  d9ca                     fxch      st(2)
004727ec  e95cfeffff               jmp       0x47264d
004727f1  ddd8                     fstp      st(0)
004727f3  dddb                     fstp      st(3)
004727f5  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004727f8  d900                     fld       dword ptr [eax]
004727fa  89c8                     mov       eax, ecx
004727fc  d9cc                     fxch      st(4)
004727fe  d910                     fst       dword ptr [eax]
00472800  dcc9                     fmul      st(1), st(0)
00472802  d9c9                     fxch      st(1)
00472804  d8db                     fcomp     st(3)
00472806  ddda                     fstp      st(2)
00472808  d9c9                     fxch      st(1)
0047280a  d9ca                     fxch      st(2)
0047280c  d9c9                     fxch      st(1)
0047280e  dfe0                     fnstsw    ax
00472810  9e                       sahf
00472811  0f8a0f000000             jp        0x472826
00472817  760d                     jbe       0x472826
00472819  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0047281c  d905f4f25900             fld       dword ptr [0x59f2f4] ; bits=6666663f, f32=0.8999999761581421
00472822  d808                     fmul      dword ptr [eax]
00472824  d918                     fstp      dword ptr [eax]
00472826  d9c9                     fxch      st(1)
00472828  d9ca                     fxch      st(2)
0047282a  e91efeffff               jmp       0x47264d
0047282f  b800000000               mov       eax, 0
00472834  5f                       pop       edi
00472835  5e                       pop       esi
00472836  5b                       pop       ebx
00472837  8be5                     mov       esp, ebp
00472839  5d                       pop       ebp
0047283a  c3                       ret
0047283b  0500000000               add       eax, 0
