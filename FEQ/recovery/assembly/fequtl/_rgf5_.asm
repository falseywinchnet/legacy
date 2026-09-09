; _rgf5_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x73210
00473210  55                       push      ebp
00473211  8bec                     mov       ebp, esp
00473213  b86c000000               mov       eax, 0x6c
00473218  e8e35d0700               call      0x4e9000 ; __alloca_probe
0047321d  53                       push      ebx
0047321e  56                       push      esi
0047321f  57                       push      edi
00473220  8b4d08                   mov       ecx, dword ptr [ebp + 8]
00473223  8b750c                   mov       esi, dword ptr [ebp + 0xc]
00473226  8b4510                   mov       eax, dword ptr [ebp + 0x10]
00473229  8945a8                   mov       dword ptr [ebp - 0x58], eax
0047322c  d901                     fld       dword ptr [ecx]
0047322e  d9053cf45900             fld       dword ptr [0x59f43c] ; bits=bd378635, f32=9.999999974752427e-07
00473234  d9c9                     fxch      st(1)
00473236  d8153cf45900             fcom      dword ptr [0x59f43c] ; bits=bd378635, f32=9.999999974752427e-07
0047323c  db7ddc                   fstp      xword ptr [ebp - 0x24]
0047323f  db7dd0                   fstp      xword ptr [ebp - 0x30]
00473242  dfe0                     fnstsw    ax
00473244  9e                       sahf
00473245  0f8a08000000             jp        0x473253
0047324b  7306                     jae       0x473253
0047324d  db6dd0                   fld       xword ptr [ebp - 0x30]
00473250  db7ddc                   fstp      xword ptr [ebp - 0x24]
00473253  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00473256  c70000000000             mov       dword ptr [eax], 0
0047325c  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
0047325f  d901                     fld       dword ptr [ecx]
00473261  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
00473264  d901                     fld       dword ptr [ecx]
00473266  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00473269  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
0047326c  d901                     fld       dword ptr [ecx]
0047326e  8b5520                   mov       edx, dword ptr [ebp + 0x20]
00473271  d902                     fld       dword ptr [edx]
00473273  d809                     fmul      dword ptr [ecx]
00473275  d81d34f45900             fcomp     dword ptr [0x59f434] ; bits=00000000, f32=0.0
0047327b  d9c9                     fxch      st(1)
0047327d  8945a4                   mov       dword ptr [ebp - 0x5c], eax
00473280  dfe0                     fnstsw    ax
00473282  9e                       sahf
00473283  894da0                   mov       dword ptr [ebp - 0x60], ecx
00473286  89559c                   mov       dword ptr [ebp - 0x64], edx
00473289  0f8a14000000             jp        0x4732a3
0047328f  7612                     jbe       0x4732a3
00473291  ddd8                     fstp      st(0)
00473293  8b45a4                   mov       eax, dword ptr [ebp - 0x5c]
00473296  ddd8                     fstp      st(0)
00473298  c70001000000             mov       dword ptr [eax], 1
0047329e  e9ed010000               jmp       0x473490
004732a3  bb00000000               mov       ebx, 0
004732a8  8b459c                   mov       eax, dword ptr [ebp - 0x64]
004732ab  894598                   mov       dword ptr [ebp - 0x68], eax
004732ae  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
004732b1  894594                   mov       dword ptr [ebp - 0x6c], eax
004732b4  db7de8                   fstp      xword ptr [ebp - 0x18]
004732b7  db7df4                   fstp      xword ptr [ebp - 0xc]
004732ba  8b4598                   mov       eax, dword ptr [ebp - 0x68]
004732bd  db6de8                   fld       xword ptr [ebp - 0x18]
004732c0  d808                     fmul      dword ptr [eax]
004732c2  8b4d94                   mov       ecx, dword ptr [ebp - 0x6c]
004732c5  db6dc4                   fld       xword ptr [ebp - 0x3c]
004732c8  d809                     fmul      dword ptr [ecx]
004732ca  dee9                     fsubp     st(1)
004732cc  8b5520                   mov       edx, dword ptr [ebp + 0x20]
004732cf  8b7d1c                   mov       edi, dword ptr [ebp + 0x1c]
004732d2  d907                     fld       dword ptr [edi]
004732d4  d82a                     fsubr     dword ptr [edx]
004732d6  def9                     fdivp     st(1)
004732d8  8b5524                   mov       edx, dword ptr [ebp + 0x24]
004732db  d91a                     fstp      dword ptr [edx]
004732dd  8d12                     lea       edx, [edx]
004732df  52                       push      edx
004732e0  8b55a8                   mov       edx, dword ptr [ebp - 0x58]
004732e3  ffd2                     call      edx
004732e5  83c404                   add       esp, 4
004732e8  d81544f45900             fcom      dword ptr [0x59f444] ; bits=cded47f1, f32=-9.900000073412052e+29
004732ee  db6df4                   fld       xword ptr [ebp - 0xc]
004732f1  db6de8                   fld       xword ptr [ebp - 0x18]
004732f4  dfe0                     fnstsw    ax
004732f6  9e                       sahf
004732f7  0f8a16000000             jp        0x473313
004732fd  7314                     jae       0x473313
004732ff  ddd8                     fstp      st(0)
00473301  ddd8                     fstp      st(0)
00473303  ddd8                     fstp      st(0)
00473305  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00473308  c70003000000             mov       dword ptr [eax], 3
0047330e  e97d010000               jmp       0x473490
00473313  d9ee                     fldz
00473315  d9cb                     fxch      st(3)
00473317  dde3                     fucom     st(3)
00473319  dddb                     fstp      st(3)
0047331b  dfe0                     fnstsw    ax
0047331d  9e                       sahf
0047331e  0f8a1b000000             jp        0x47333f
00473324  7519                     jne       0x47333f
00473326  ddd9                     fstp      st(1)
00473328  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0047332b  d918                     fstp      dword ptr [eax]
0047332d  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00473330  db6dc4                   fld       xword ptr [ebp - 0x3c]
00473333  d918                     fstp      dword ptr [eax]
00473335  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00473338  d918                     fstp      dword ptr [eax]
0047333a  e951010000               jmp       0x473490
0047333f  d9c0                     fld       st(0)
00473341  d9e1                     fabs
00473343  db6dc4                   fld       xword ptr [ebp - 0x3c]
00473346  d9e1                     fabs
00473348  dec1                     faddp     st(1)
0047334a  db6dc4                   fld       xword ptr [ebp - 0x3c]
0047334d  d8ea                     fsubr     st(2)
0047334f  d9e1                     fabs
00473351  def1                     fdivrp    st(1)
00473353  db6ddc                   fld       xword ptr [ebp - 0x24]
00473356  d9c9                     fxch      st(1)
00473358  ded9                     fcompp
0047335a  dfe0                     fnstsw    ax
0047335c  9e                       sahf
0047335d  0f8a55000000             jp        0x4733b8
00473363  7753                     ja        0x4733b8
00473365  ddd9                     fstp      st(1)
00473367  ddd9                     fstp      st(1)
00473369  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0047336c  d910                     fst       dword ptr [eax]
0047336e  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00473371  db6dc4                   fld       xword ptr [ebp - 0x3c]
00473374  d918                     fstp      dword ptr [eax]
00473376  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
00473379  d901                     fld       dword ptr [ecx]
0047337b  d9e1                     fabs
0047337d  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00473380  d900                     fld       dword ptr [eax]
00473382  d9c0                     fld       st(0)
00473384  d9e1                     fabs
00473386  d9ca                     fxch      st(2)
00473388  d8da                     fcomp     st(2)
0047338a  ddd9                     fstp      st(1)
0047338c  db7db8                   fstp      xword ptr [ebp - 0x48]
0047338f  dfe0                     fnstsw    ax
00473391  9e                       sahf
00473392  0f8a0c000000             jp        0x4733a4
00473398  730a                     jae       0x4733a4
0047339a  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0047339d  d918                     fstp      dword ptr [eax]
0047339f  e9ec000000               jmp       0x473490
004733a4  ddd8                     fstp      st(0)
004733a6  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004733a9  db6dc4                   fld       xword ptr [ebp - 0x3c]
004733ac  d918                     fstp      dword ptr [eax]
004733ae  db6db8                   fld       xword ptr [ebp - 0x48]
004733b1  d919                     fstp      dword ptr [ecx]
004733b3  e9d8000000               jmp       0x473490
004733b8  d9c2                     fld       st(2)
004733ba  d9e1                     fabs
004733bc  d81e                     fcomp     dword ptr [esi]
004733be  dfe0                     fnstsw    ax
004733c0  9e                       sahf
004733c1  0f8a1b000000             jp        0x4733e2
004733c7  7319                     jae       0x4733e2
004733c9  ddd9                     fstp      st(1)
004733cb  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004733ce  d918                     fstp      dword ptr [eax]
004733d0  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004733d3  db6dc4                   fld       xword ptr [ebp - 0x3c]
004733d6  d918                     fstp      dword ptr [eax]
004733d8  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004733db  d918                     fstp      dword ptr [eax]
004733dd  e9ae000000               jmp       0x473490
004733e2  43                       inc       ebx
004733e3  83fb64                   cmp       ebx, 0x64
004733e6  7e1f                     jle       0x473407
004733e8  ddd9                     fstp      st(1)
004733ea  ddd9                     fstp      st(1)
004733ec  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004733ef  d918                     fstp      dword ptr [eax]
004733f1  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004733f4  db6dc4                   fld       xword ptr [ebp - 0x3c]
004733f7  d918                     fstp      dword ptr [eax]
004733f9  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004733fc  c70002000000             mov       dword ptr [eax], 2
00473402  e989000000               jmp       0x473490
00473407  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
0047340a  d901                     fld       dword ptr [ecx]
0047340c  d9c3                     fld       st(3)
0047340e  d809                     fmul      dword ptr [ecx]
00473410  d9ee                     fldz
00473412  d9c9                     fxch      st(1)
00473414  d81d34f45900             fcomp     dword ptr [0x59f434] ; bits=00000000, f32=0.0
0047341a  d9c9                     fxch      st(1)
0047341c  db7dac                   fstp      xword ptr [ebp - 0x54]
0047341f  d9c9                     fxch      st(1)
00473421  dfe0                     fnstsw    ax
00473423  9e                       sahf
00473424  0f8a34000000             jp        0x47345e
0047342a  7732                     ja        0x47345e
0047342c  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0047342f  d900                     fld       dword ptr [eax]
00473431  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00473434  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00473437  d9cb                     fxch      st(3)
00473439  d910                     fst       dword ptr [eax]
0047343b  dcca                     fmul      st(2), st(0)
0047343d  d9ca                     fxch      st(2)
0047343f  ded9                     fcompp
00473441  d9c9                     fxch      st(1)
00473443  dfe0                     fnstsw    ax
00473445  9e                       sahf
00473446  0f8a0d000000             jp        0x473459
0047344c  760b                     jbe       0x473459
0047344e  db6dac                   fld       xword ptr [ebp - 0x54]
00473451  d80d40f45900             fmul      dword ptr [0x59f440] ; bits=0000003f, f32=0.5
00473457  d919                     fstp      dword ptr [ecx]
00473459  e956feffff               jmp       0x4732b4
0047345e  ddd8                     fstp      st(0)
00473460  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00473463  d900                     fld       dword ptr [eax]
00473465  89c8                     mov       eax, ecx
00473467  d9cb                     fxch      st(3)
00473469  d910                     fst       dword ptr [eax]
0047346b  dcca                     fmul      st(2), st(0)
0047346d  d9ca                     fxch      st(2)
0047346f  ded9                     fcompp
00473471  d9c9                     fxch      st(1)
00473473  dfe0                     fnstsw    ax
00473475  9e                       sahf
00473476  0f8a0f000000             jp        0x47348b
0047347c  760d                     jbe       0x47348b
0047347e  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00473481  d90540f45900             fld       dword ptr [0x59f440] ; bits=0000003f, f32=0.5
00473487  d808                     fmul      dword ptr [eax]
00473489  d918                     fstp      dword ptr [eax]
0047348b  e924feffff               jmp       0x4732b4
00473490  b800000000               mov       eax, 0
00473495  5f                       pop       edi
00473496  5e                       pop       esi
00473497  5b                       pop       ebx
00473498  8be5                     mov       esp, ebp
0047349a  5d                       pop       ebp
0047349b  c3                       ret
0047349c  8d642400                 lea       esp, [esp]
