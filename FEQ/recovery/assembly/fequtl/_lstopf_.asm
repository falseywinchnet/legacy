; _lstopf_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x7ef00
0047ef00  55                       push      ebp
0047ef01  8bec                     mov       ebp, esp
0047ef03  b834000000               mov       eax, 0x34
0047ef08  e8f3a00600               call      0x4e9000 ; __alloca_probe
0047ef0d  53                       push      ebx
0047ef0e  56                       push      esi
0047ef0f  8b4d08                   mov       ecx, dword ptr [ebp + 8]
0047ef12  8b5d0c                   mov       ebx, dword ptr [ebp + 0xc]
0047ef15  8b4510                   mov       eax, dword ptr [ebp + 0x10]
0047ef18  8945cc                   mov       dword ptr [ebp - 0x34], eax
0047ef1b  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0047ef1e  d900                     fld       dword ptr [eax]
0047ef20  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0047ef23  d900                     fld       dword ptr [eax]
0047ef25  d9c9                     fxch      st(1)
0047ef27  d810                     fcom      dword ptr [eax]
0047ef29  d9c9                     fxch      st(1)
0047ef2b  dfe0                     fnstsw    ax
0047ef2d  9e                       sahf
0047ef2e  0f8a3f000000             jp        0x47ef73
0047ef34  723d                     jb        0x47ef73
0047ef36  8b01                     mov       eax, dword ptr [ecx]
0047ef38  8d1dd08d5a00             lea       ebx, [0x5a8dd0] ; bits=00000000, f32=0.0
0047ef3e  8d53b0                   lea       edx, [ebx - 0x50]
0047ef41  8945fc                   mov       dword ptr [ebp - 4], eax
0047ef44  8d45fc                   lea       eax, [ebp - 4]
0047ef47  894208                   mov       dword ptr [edx + 8], eax
0047ef4a  d9c9                     fxch      st(1)
0047ef4c  d95df8                   fstp      dword ptr [ebp - 8]
0047ef4f  8d45f8                   lea       eax, [ebp - 8]
0047ef52  894228                   mov       dword ptr [edx + 0x28], eax
0047ef55  d95df4                   fstp      dword ptr [ebp - 0xc]
0047ef58  8d45f4                   lea       eax, [ebp - 0xc]
0047ef5b  894234                   mov       dword ptr [edx + 0x34], eax
0047ef5e  52                       push      edx
0047ef5f  e88c360200               call      0x4a25f0 ; _jwe_isfm
0047ef64  83c404                   add       esp, 4
0047ef67  8d5ba8                   lea       ebx, [ebx - 0x58]
0047ef6a  53                       push      ebx
0047ef6b  e8d0440200               call      0x4a3440 ; _jwe_xstp
0047ef70  83c404                   add       esp, 4
0047ef73  8b5514                   mov       edx, dword ptr [ebp + 0x14]
0047ef76  d902                     fld       dword ptr [edx]
0047ef78  d81d588d5a00             fcomp     dword ptr [0x5a8d58] ; bits=0000803f, f32=1.0
0047ef7e  dfe0                     fnstsw    ax
0047ef80  9e                       sahf
0047ef81  0f8a3d000000             jp        0x47efc4
0047ef87  733b                     jae       0x47efc4
0047ef89  db7dd0                   fstp      xword ptr [ebp - 0x30]
0047ef8c  db7ddc                   fstp      xword ptr [ebp - 0x24]
0047ef8f  8d05d08d5a00             lea       eax, [0x5a8dd0] ; bits=00000000, f32=0.0
0047ef95  8d70f0                   lea       esi, [eax - 0x10]
0047ef98  56                       push      esi
0047ef99  8d70f4                   lea       esi, [eax - 0xc]
0047ef9c  56                       push      esi
0047ef9d  8d70ec                   lea       esi, [eax - 0x14]
0047efa0  56                       push      esi
0047efa1  8b7524                   mov       esi, dword ptr [ebp + 0x24]
0047efa4  8d36                     lea       esi, [esi]
0047efa6  56                       push      esi
0047efa7  8d32                     lea       esi, [edx]
0047efa9  56                       push      esi
0047efaa  8d40a0                   lea       eax, [eax - 0x60]
0047efad  50                       push      eax
0047efae  8d03                     lea       eax, [ebx]
0047efb0  50                       push      eax
0047efb1  8d01                     lea       eax, [ecx]
0047efb3  50                       push      eax
0047efb4  e82710fdff               call      0x44ffe0 ; _tdlk10_
0047efb9  db6ddc                   fld       xword ptr [ebp - 0x24]
0047efbc  db6dd0                   fld       xword ptr [ebp - 0x30]
0047efbf  83c420                   add       esp, 0x20
0047efc2  eb3e                     jmp       0x47f002
0047efc4  db7dd0                   fstp      xword ptr [ebp - 0x30]
0047efc7  db7ddc                   fstp      xword ptr [ebp - 0x24]
0047efca  8d05d08d5a00             lea       eax, [0x5a8dd0] ; bits=00000000, f32=0.0
0047efd0  8d58f0                   lea       ebx, [eax - 0x10]
0047efd3  53                       push      ebx
0047efd4  8d58f4                   lea       ebx, [eax - 0xc]
0047efd7  53                       push      ebx
0047efd8  8d58ec                   lea       ebx, [eax - 0x14]
0047efdb  53                       push      ebx
0047efdc  8b5d24                   mov       ebx, dword ptr [ebp + 0x24]
0047efdf  8d1b                     lea       ebx, [ebx]
0047efe1  53                       push      ebx
0047efe2  89d3                     mov       ebx, edx
0047efe4  8d1b                     lea       ebx, [ebx]
0047efe6  53                       push      ebx
0047efe7  8d40a0                   lea       eax, [eax - 0x60]
0047efea  50                       push      eax
0047efeb  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
0047efee  8d18                     lea       ebx, [eax]
0047eff0  53                       push      ebx
0047eff1  8d01                     lea       eax, [ecx]
0047eff3  50                       push      eax
0047eff4  e8e70ffdff               call      0x44ffe0 ; _tdlk10_
0047eff9  db6ddc                   fld       xword ptr [ebp - 0x24]
0047effc  db6dd0                   fld       xword ptr [ebp - 0x30]
0047efff  83c420                   add       esp, 0x20
0047f002  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047f005  d900                     fld       dword ptr [eax]
0047f007  d9c1                     fld       st(1)
0047f009  d800                     fadd      dword ptr [eax]
0047f00b  d9c3                     fld       st(3)
0047f00d  d800                     fadd      dword ptr [eax]
0047f00f  def9                     fdivp     st(1)
0047f011  8d05d08d5a00             lea       eax, [0x5a8dd0] ; bits=00000000, f32=0.0
0047f017  d958fc                   fstp      dword ptr [eax - 4]
0047f01a  d9ed                     fldln2
0047f01c  d940fc                   fld       dword ptr [eax - 4]
0047f01f  d9c1                     fld       st(1)
0047f021  d9c9                     fxch      st(1)
0047f023  d9f1                     fyl2x
0047f025  d95df8                   fstp      dword ptr [ebp - 8]
0047f028  d945f8                   fld       dword ptr [ebp - 8]
0047f02b  d940ec                   fld       dword ptr [eax - 0x14]
0047f02e  d9ca                     fxch      st(2)
0047f030  d9c9                     fxch      st(1)
0047f032  d9ca                     fxch      st(2)
0047f034  d9f1                     fyl2x
0047f036  d95df8                   fstp      dword ptr [ebp - 8]
0047f039  d9c0                     fld       st(0)
0047f03b  d875f8                   fdiv      dword ptr [ebp - 8]
0047f03e  d805588d5a00             fadd      dword ptr [0x5a8d58] ; bits=0000803f, f32=1.0
0047f044  d97df2                   fnstcw    word ptr [ebp - 0xe]
0047f047  668b5df2                 mov       bx, word ptr [ebp - 0xe]
0047f04b  6681cb000c               or        bx, 0xc00
0047f050  66895df0                 mov       word ptr [ebp - 0x10], bx
0047f054  d96df0                   fldcw     word ptr [ebp - 0x10]
0047f057  df7de8                   fistp     qword ptr [ebp - 0x18]
0047f05a  d96df2                   fldcw     word ptr [ebp - 0xe]
0047f05d  8b5de8                   mov       ebx, dword ptr [ebp - 0x18]
0047f060  8d4b01                   lea       ecx, [ebx + 1]
0047f063  8b552c                   mov       edx, dword ptr [ebp + 0x2c]
0047f066  890a                     mov       dword ptr [edx], ecx
0047f068  895dfc                   mov       dword ptr [ebp - 4], ebx
0047f06b  da75fc                   fidiv     dword ptr [ebp - 4]
0047f06e  d9ea                     fldl2e
0047f070  dec9                     fmulp     st(1)
0047f072  d9c0                     fld       st(0)
0047f074  d9fc                     frndint
0047f076  dce9                     fsub      st(1), st(0)
0047f078  d9c9                     fxch      st(1)
0047f07a  d9f0                     f2xm1
0047f07c  d805588d5a00             fadd      dword ptr [0x5a8d58] ; bits=0000803f, f32=1.0
0047f082  d9fd                     fscale
0047f084  ddd9                     fstp      st(1)
0047f086  d958ec                   fstp      dword ptr [eax - 0x14]
0047f089  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0047f08c  8b00                     mov       eax, dword ptr [eax]
0047f08e  39c1                     cmp       ecx, eax
0047f090  7e1a                     jle       0x47f0ac
0047f092  ddd8                     fstp      st(0)
0047f094  ddd8                     fstp      st(0)
0047f096  ddd8                     fstp      st(0)
0047f098  8b4534                   mov       eax, dword ptr [ebp + 0x34]
0047f09b  c70001000000             mov       dword ptr [eax], 1
0047f0a1  c702ffffffff             mov       dword ptr [edx], 0xffffffff
0047f0a7  e9c8000000               jmp       0x47f174
0047f0ac  dcc2                     fadd      st(2), st(0)
0047f0ae  8b4530                   mov       eax, dword ptr [ebp + 0x30]
0047f0b1  d9ca                     fxch      st(2)
0047f0b3  d918                     fstp      dword ptr [eax]
0047f0b5  d8c1                     fadd      st(1)
0047f0b7  89cb                     mov       ebx, ecx
0047f0b9  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
0047f0bd  8d53fe                   lea       edx, [ebx - 2]
0047f0c0  83fa00                   cmp       edx, 0
0047f0c3  7e49                     jle       0x47f10e
0047f0c5  b902000000               mov       ecx, 2
0047f0ca  83fa02                   cmp       edx, 2
0047f0cd  7c2a                     jl        0x47f0f9
0047f0cf  eb04                     jmp       0x47f0d5
0047f0d1  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
0047f0d5  8b4530                   mov       eax, dword ptr [ebp + 0x30]
0047f0d8  d905bc8d5a00             fld       dword ptr [0x5a8dbc] ; bits=00000000, f32=0.0
0047f0de  d9c0                     fld       st(0)
0047f0e0  d84c88f8                 fmul      dword ptr [eax + ecx*4 - 8]
0047f0e4  d95488fc                 fst       dword ptr [eax + ecx*4 - 4]
0047f0e8  dec9                     fmulp     st(1)
0047f0ea  83c102                   add       ecx, 2
0047f0ed  83ea02                   sub       edx, 2
0047f0f0  83fa02                   cmp       edx, 2
0047f0f3  7ddc                     jge       0x47f0d1
0047f0f5  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
0047f0f9  85d2                     test      edx, edx
0047f0fb  7411                     je        0x47f10e
0047f0fd  8b4530                   mov       eax, dword ptr [ebp + 0x30]
0047f100  d905bc8d5a00             fld       dword ptr [0x5a8dbc] ; bits=00000000, f32=0.0
0047f106  d84c88f8                 fmul      dword ptr [eax + ecx*4 - 8]
0047f10a  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
0047f10e  d9ee                     fldz
0047f110  d9c9                     fxch      st(1)
0047f112  dde1                     fucom     st(1)
0047f114  ddd9                     fstp      st(1)
0047f116  dfe0                     fnstsw    ax
0047f118  9e                       sahf
0047f119  0f8a02000000             jp        0x47f121
0047f11f  7449                     je        0x47f16a
0047f121  89da                     mov       edx, ebx
0047f123  83fb00                   cmp       ebx, 0
0047f126  7e46                     jle       0x47f16e
0047f128  b901000000               mov       ecx, 1
0047f12d  83fa02                   cmp       edx, 2
0047f130  7c27                     jl        0x47f159
0047f132  eb04                     jmp       0x47f138
0047f134  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
0047f138  8b4530                   mov       eax, dword ptr [ebp + 0x30]
0047f13b  d9c0                     fld       st(0)
0047f13d  d86c88fc                 fsubr     dword ptr [eax + ecx*4 - 4]
0047f141  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
0047f145  d9c0                     fld       st(0)
0047f147  d82c88                   fsubr     dword ptr [eax + ecx*4]
0047f14a  83c102                   add       ecx, 2
0047f14d  83ea02                   sub       edx, 2
0047f150  83fa02                   cmp       edx, 2
0047f153  7ddf                     jge       0x47f134
0047f155  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
0047f159  85d2                     test      edx, edx
0047f15b  7415                     je        0x47f172
0047f15d  8b4530                   mov       eax, dword ptr [ebp + 0x30]
0047f160  d86c88fc                 fsubr     dword ptr [eax + ecx*4 - 4]
0047f164  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
0047f168  eb0a                     jmp       0x47f174
0047f16a  ddd8                     fstp      st(0)
0047f16c  eb06                     jmp       0x47f174
0047f16e  ddd8                     fstp      st(0)
0047f170  eb02                     jmp       0x47f174
0047f172  ddd8                     fstp      st(0)
0047f174  b800000000               mov       eax, 0
0047f179  5e                       pop       esi
0047f17a  5b                       pop       ebx
0047f17b  8be5                     mov       esp, ebp
0047f17d  5d                       pop       ebp
0047f17e  c3                       ret
0047f17f  90                       nop
