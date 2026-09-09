; _rgf3_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x72f40
00472f40  55                       push      ebp
00472f41  8bec                     mov       ebp, esp
00472f43  b87c000000               mov       eax, 0x7c
00472f48  e8b3600700               call      0x4e9000 ; __alloca_probe
00472f4d  53                       push      ebx
00472f4e  56                       push      esi
00472f4f  57                       push      edi
00472f50  8b4508                   mov       eax, dword ptr [ebp + 8]
00472f53  8b750c                   mov       esi, dword ptr [ebp + 0xc]
00472f56  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
00472f59  89459c                   mov       dword ptr [ebp - 0x64], eax
00472f5c  894d98                   mov       dword ptr [ebp - 0x68], ecx
00472f5f  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00472f62  c70000000000             mov       dword ptr [eax], 0
00472f68  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
00472f6b  d901                     fld       dword ptr [ecx]
00472f6d  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
00472f70  d901                     fld       dword ptr [ecx]
00472f72  db7ddc                   fstp      xword ptr [ebp - 0x24]
00472f75  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
00472f78  d901                     fld       dword ptr [ecx]
00472f7a  d9c0                     fld       st(0)
00472f7c  d9e1                     fabs
00472f7e  d906                     fld       dword ptr [esi]
00472f80  d9c9                     fxch      st(1)
00472f82  d81e                     fcomp     dword ptr [esi]
00472f84  db7dd0                   fstp      xword ptr [ebp - 0x30]
00472f87  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00472f8a  894594                   mov       dword ptr [ebp - 0x6c], eax
00472f8d  dfe0                     fnstsw    ax
00472f8f  9e                       sahf
00472f90  894d90                   mov       dword ptr [ebp - 0x70], ecx
00472f93  0f8a0c000000             jp        0x472fa5
00472f99  770a                     ja        0x472fa5
00472f9b  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00472f9e  d918                     fstp      dword ptr [eax]
00472fa0  e953020000               jmp       0x4731f8
00472fa5  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00472fa8  d900                     fld       dword ptr [eax]
00472faa  d9c0                     fld       st(0)
00472fac  d9e1                     fabs
00472fae  db6dd0                   fld       xword ptr [ebp - 0x30]
00472fb1  d9c9                     fxch      st(1)
00472fb3  ded9                     fcompp
00472fb5  db7db8                   fstp      xword ptr [ebp - 0x48]
00472fb8  89458c                   mov       dword ptr [ebp - 0x74], eax
00472fbb  dfe0                     fnstsw    ax
00472fbd  9e                       sahf
00472fbe  0f8a19000000             jp        0x472fdd
00472fc4  7717                     ja        0x472fdd
00472fc6  ddd8                     fstp      st(0)
00472fc8  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00472fcb  db6ddc                   fld       xword ptr [ebp - 0x24]
00472fce  d918                     fstp      dword ptr [eax]
00472fd0  8b4590                   mov       eax, dword ptr [ebp - 0x70]
00472fd3  db6db8                   fld       xword ptr [ebp - 0x48]
00472fd6  d918                     fstp      dword ptr [eax]
00472fd8  e91b020000               jmp       0x4731f8
00472fdd  db6dc4                   fld       xword ptr [ebp - 0x3c]
00472fe0  db6db8                   fld       xword ptr [ebp - 0x48]
00472fe3  db6dc4                   fld       xword ptr [ebp - 0x3c]
00472fe6  dec9                     fmulp     st(1)
00472fe8  d81d0cf45900             fcomp     dword ptr [0x59f40c] ; bits=00000000, f32=0.0
00472fee  d9c9                     fxch      st(1)
00472ff0  dfe0                     fnstsw    ax
00472ff2  9e                       sahf
00472ff3  0f8a14000000             jp        0x47300d
00472ff9  7612                     jbe       0x47300d
00472ffb  ddd8                     fstp      st(0)
00472ffd  8b4594                   mov       eax, dword ptr [ebp - 0x6c]
00473000  ddd8                     fstp      st(0)
00473002  c70001000000             mov       dword ptr [eax], 1
00473008  e9eb010000               jmp       0x4731f8
0047300d  bb00000000               mov       ebx, 0
00473012  8b458c                   mov       eax, dword ptr [ebp - 0x74]
00473015  894588                   mov       dword ptr [ebp - 0x78], eax
00473018  8b4590                   mov       eax, dword ptr [ebp - 0x70]
0047301b  894584                   mov       dword ptr [ebp - 0x7c], eax
0047301e  db7de8                   fstp      xword ptr [ebp - 0x18]
00473021  db7df4                   fstp      xword ptr [ebp - 0xc]
00473024  8b4588                   mov       eax, dword ptr [ebp - 0x78]
00473027  db6de8                   fld       xword ptr [ebp - 0x18]
0047302a  d808                     fmul      dword ptr [eax]
0047302c  8b4d84                   mov       ecx, dword ptr [ebp - 0x7c]
0047302f  db6ddc                   fld       xword ptr [ebp - 0x24]
00473032  d809                     fmul      dword ptr [ecx]
00473034  dee9                     fsubp     st(1)
00473036  8b5520                   mov       edx, dword ptr [ebp + 0x20]
00473039  8b7d1c                   mov       edi, dword ptr [ebp + 0x1c]
0047303c  d907                     fld       dword ptr [edi]
0047303e  d82a                     fsubr     dword ptr [edx]
00473040  def9                     fdivp     st(1)
00473042  8b5524                   mov       edx, dword ptr [ebp + 0x24]
00473045  d91a                     fstp      dword ptr [edx]
00473047  8d12                     lea       edx, [edx]
00473049  52                       push      edx
0047304a  8b5598                   mov       edx, dword ptr [ebp - 0x68]
0047304d  ffd2                     call      edx
0047304f  83c404                   add       esp, 4
00473052  d81518f45900             fcom      dword ptr [0x59f418] ; bits=cded47f1, f32=-9.900000073412052e+29
00473058  db6df4                   fld       xword ptr [ebp - 0xc]
0047305b  db6de8                   fld       xword ptr [ebp - 0x18]
0047305e  dfe0                     fnstsw    ax
00473060  9e                       sahf
00473061  0f8a16000000             jp        0x47307d
00473067  7314                     jae       0x47307d
00473069  ddd8                     fstp      st(0)
0047306b  ddd8                     fstp      st(0)
0047306d  ddd8                     fstp      st(0)
0047306f  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00473072  c70003000000             mov       dword ptr [eax], 3
00473078  e97b010000               jmp       0x4731f8
0047307d  d9ee                     fldz
0047307f  d9cb                     fxch      st(3)
00473081  dde3                     fucom     st(3)
00473083  dddb                     fstp      st(3)
00473085  dfe0                     fnstsw    ax
00473087  9e                       sahf
00473088  0f8a1b000000             jp        0x4730a9
0047308e  7519                     jne       0x4730a9
00473090  ddd9                     fstp      st(1)
00473092  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00473095  d918                     fstp      dword ptr [eax]
00473097  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047309a  db6ddc                   fld       xword ptr [ebp - 0x24]
0047309d  d918                     fstp      dword ptr [eax]
0047309f  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004730a2  d918                     fstp      dword ptr [eax]
004730a4  e94f010000               jmp       0x4731f8
004730a9  d9c0                     fld       st(0)
004730ab  d9e1                     fabs
004730ad  db6ddc                   fld       xword ptr [ebp - 0x24]
004730b0  d9e1                     fabs
004730b2  dec1                     faddp     st(1)
004730b4  db6ddc                   fld       xword ptr [ebp - 0x24]
004730b7  d8ea                     fsubr     st(2)
004730b9  d9e1                     fabs
004730bb  8b459c                   mov       eax, dword ptr [ebp - 0x64]
004730be  def1                     fdivrp    st(1)
004730c0  d818                     fcomp     dword ptr [eax]
004730c2  dfe0                     fnstsw    ax
004730c4  9e                       sahf
004730c5  0f8a55000000             jp        0x473120
004730cb  7353                     jae       0x473120
004730cd  ddd9                     fstp      st(1)
004730cf  ddd9                     fstp      st(1)
004730d1  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004730d4  d910                     fst       dword ptr [eax]
004730d6  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004730d9  db6ddc                   fld       xword ptr [ebp - 0x24]
004730dc  d918                     fstp      dword ptr [eax]
004730de  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
004730e1  d901                     fld       dword ptr [ecx]
004730e3  d9e1                     fabs
004730e5  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004730e8  d900                     fld       dword ptr [eax]
004730ea  d9c0                     fld       st(0)
004730ec  d9e1                     fabs
004730ee  d9ca                     fxch      st(2)
004730f0  d8da                     fcomp     st(2)
004730f2  ddd9                     fstp      st(1)
004730f4  db7dac                   fstp      xword ptr [ebp - 0x54]
004730f7  dfe0                     fnstsw    ax
004730f9  9e                       sahf
004730fa  0f8a0c000000             jp        0x47310c
00473100  730a                     jae       0x47310c
00473102  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00473105  d918                     fstp      dword ptr [eax]
00473107  e9ec000000               jmp       0x4731f8
0047310c  ddd8                     fstp      st(0)
0047310e  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00473111  db6ddc                   fld       xword ptr [ebp - 0x24]
00473114  d918                     fstp      dword ptr [eax]
00473116  db6dac                   fld       xword ptr [ebp - 0x54]
00473119  d919                     fstp      dword ptr [ecx]
0047311b  e9d8000000               jmp       0x4731f8
00473120  d9c2                     fld       st(2)
00473122  d9e1                     fabs
00473124  d81e                     fcomp     dword ptr [esi]
00473126  dfe0                     fnstsw    ax
00473128  9e                       sahf
00473129  0f8a1b000000             jp        0x47314a
0047312f  7319                     jae       0x47314a
00473131  ddd9                     fstp      st(1)
00473133  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00473136  d918                     fstp      dword ptr [eax]
00473138  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047313b  db6ddc                   fld       xword ptr [ebp - 0x24]
0047313e  d918                     fstp      dword ptr [eax]
00473140  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00473143  d918                     fstp      dword ptr [eax]
00473145  e9ae000000               jmp       0x4731f8
0047314a  43                       inc       ebx
0047314b  83fb64                   cmp       ebx, 0x64
0047314e  7e1f                     jle       0x47316f
00473150  ddd9                     fstp      st(1)
00473152  ddd9                     fstp      st(1)
00473154  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00473157  d918                     fstp      dword ptr [eax]
00473159  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047315c  db6ddc                   fld       xword ptr [ebp - 0x24]
0047315f  d918                     fstp      dword ptr [eax]
00473161  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00473164  c70002000000             mov       dword ptr [eax], 2
0047316a  e989000000               jmp       0x4731f8
0047316f  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
00473172  d901                     fld       dword ptr [ecx]
00473174  d9c3                     fld       st(3)
00473176  d809                     fmul      dword ptr [ecx]
00473178  d9ee                     fldz
0047317a  d9c9                     fxch      st(1)
0047317c  d81d0cf45900             fcomp     dword ptr [0x59f40c] ; bits=00000000, f32=0.0
00473182  d9c9                     fxch      st(1)
00473184  db7da0                   fstp      xword ptr [ebp - 0x60]
00473187  d9c9                     fxch      st(1)
00473189  dfe0                     fnstsw    ax
0047318b  9e                       sahf
0047318c  0f8a34000000             jp        0x4731c6
00473192  7732                     ja        0x4731c6
00473194  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00473197  d900                     fld       dword ptr [eax]
00473199  db7ddc                   fstp      xword ptr [ebp - 0x24]
0047319c  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0047319f  d9cb                     fxch      st(3)
004731a1  d910                     fst       dword ptr [eax]
004731a3  dcca                     fmul      st(2), st(0)
004731a5  d9ca                     fxch      st(2)
004731a7  ded9                     fcompp
004731a9  d9c9                     fxch      st(1)
004731ab  dfe0                     fnstsw    ax
004731ad  9e                       sahf
004731ae  0f8a0d000000             jp        0x4731c1
004731b4  760b                     jbe       0x4731c1
004731b6  db6da0                   fld       xword ptr [ebp - 0x60]
004731b9  d80d14f45900             fmul      dword ptr [0x59f414] ; bits=0000003f, f32=0.5
004731bf  d919                     fstp      dword ptr [ecx]
004731c1  e958feffff               jmp       0x47301e
004731c6  ddd8                     fstp      st(0)
004731c8  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004731cb  d900                     fld       dword ptr [eax]
004731cd  89c8                     mov       eax, ecx
004731cf  d9cb                     fxch      st(3)
004731d1  d910                     fst       dword ptr [eax]
004731d3  dcca                     fmul      st(2), st(0)
004731d5  d9ca                     fxch      st(2)
004731d7  ded9                     fcompp
004731d9  d9c9                     fxch      st(1)
004731db  dfe0                     fnstsw    ax
004731dd  9e                       sahf
004731de  0f8a0f000000             jp        0x4731f3
004731e4  760d                     jbe       0x4731f3
004731e6  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004731e9  d90514f45900             fld       dword ptr [0x59f414] ; bits=0000003f, f32=0.5
004731ef  d808                     fmul      dword ptr [eax]
004731f1  d918                     fstp      dword ptr [eax]
004731f3  e926feffff               jmp       0x47301e
004731f8  b800000000               mov       eax, 0
004731fd  5f                       pop       edi
004731fe  5e                       pop       esi
004731ff  5b                       pop       ebx
00473200  8be5                     mov       esp, ebp
00473202  5d                       pop       ebp
00473203  c3                       ret
00473204  0500000000               add       eax, 0
00473209  8da42400000000           lea       esp, [esp]
