; _stothq_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x2f6a0
0042f6a0  55                       push      ebp
0042f6a1  8bec                     mov       ebp, esp
0042f6a3  b8a8000000               mov       eax, 0xa8
0042f6a8  e853990b00               call      0x4e9000 ; __alloca_probe
0042f6ad  53                       push      ebx
0042f6ae  56                       push      esi
0042f6af  57                       push      edi
0042f6b0  8b4508                   mov       eax, dword ptr [ebp + 8]
0042f6b3  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
0042f6b6  8b7510                   mov       esi, dword ptr [ebp + 0x10]
0042f6b9  898564ffffff             mov       dword ptr [ebp - 0x9c], eax
0042f6bf  898d60ffffff             mov       dword ptr [ebp - 0xa0], ecx
0042f6c5  bb00000000               mov       ebx, 0
0042f6ca  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0042f6cd  d900                     fld       dword ptr [eax]
0042f6cf  db7db0                   fstp      xword ptr [ebp - 0x50]
0042f6d2  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0042f6d5  db6db0                   fld       xword ptr [ebp - 0x50]
0042f6d8  d830                     fdiv      dword ptr [eax]
0042f6da  d91d54ce5600             fstp      dword ptr [0x56ce54] ; bits=00000000, f32=0.0
0042f6e0  6850ce5600               push      0x56ce50
0042f6e5  6844ce5600               push      0x56ce44
0042f6ea  684cce5600               push      0x56ce4c
0042f6ef  8d0508cc5600             lea       eax, [0x56cc08] ; bits=03000000, f32=4.203895392974451e-45
0042f6f5  89855cffffff             mov       dword ptr [ebp - 0xa4], eax
0042f6fb  8d4898                   lea       ecx, [eax - 0x68]
0042f6fe  51                       push      ecx
0042f6ff  6854ce5600               push      0x56ce54
0042f704  8d0e                     lea       ecx, [esi]
0042f706  51                       push      ecx
0042f707  e834490100               call      0x444040 ; _lktab_
0042f70c  83c418                   add       esp, 0x18
0042f70f  d9054cce5600             fld       dword ptr [0x56ce4c] ; bits=00000000, f32=0.0
0042f715  db7da4                   fstp      xword ptr [ebp - 0x5c]
0042f718  d9ee                     fldz
0042f71a  db6da4                   fld       xword ptr [ebp - 0x5c]
0042f71d  dae9                     fucompp
0042f71f  dfe0                     fnstsw    ax
0042f721  9e                       sahf
0042f722  0f8a10000000             jp        0x42f738
0042f728  750e                     jne       0x42f738
0042f72a  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
0042f72d  c70000000000             mov       dword ptr [eax], 0
0042f733  e9c6020000               jmp       0x42f9fe
0042f738  8b855cffffff             mov       eax, dword ptr [ebp - 0xa4]
0042f73e  db6da4                   fld       xword ptr [ebp - 0x5c]
0042f741  d85888                   fcomp     dword ptr [eax - 0x78]
0042f744  dfe0                     fnstsw    ax
0042f746  9e                       sahf
0042f747  0f8a1d000000             jp        0x42f76a
0042f74d  761b                     jbe       0x42f76a
0042f74f  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0042f752  d900                     fld       dword ptr [eax]
0042f754  db6db0                   fld       xword ptr [ebp - 0x50]
0042f757  d9c9                     fxch      st(1)
0042f759  ded9                     fcompp
0042f75b  dfe0                     fnstsw    ax
0042f75d  9e                       sahf
0042f75e  0f8a06000000             jp        0x42f76a
0042f764  0f8794020000             ja        0x42f9fe
0042f76a  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
0042f76d  d9054cce5600             fld       dword ptr [0x56ce4c] ; bits=00000000, f32=0.0
0042f773  d808                     fmul      dword ptr [eax]
0042f775  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0042f778  d900                     fld       dword ptr [eax]
0042f77a  d9ee                     fldz
0042f77c  d9c9                     fxch      st(1)
0042f77e  dde1                     fucom     st(1)
0042f780  ddd9                     fstp      st(1)
0042f782  db7d98                   fstp      xword ptr [ebp - 0x68]
0042f785  dfe0                     fnstsw    ax
0042f787  9e                       sahf
0042f788  0f8a1e000000             jp        0x42f7ac
0042f78e  751c                     jne       0x42f7ac
0042f790  ddd8                     fstp      st(0)
0042f792  6818ce5600               push      0x56ce18
0042f797  e8e4360700               call      0x4a2e80 ; _jwe_ilst
0042f79c  83c404                   add       esp, 4
0042f79f  6800cd5600               push      0x56cd00
0042f7a4  e8973c0700               call      0x4a3440 ; _jwe_xstp
0042f7a9  83c404                   add       esp, 4
0042f7ac  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0042f7af  d900                     fld       dword ptr [eax]
0042f7b1  db6d98                   fld       xword ptr [ebp - 0x68]
0042f7b4  d838                     fdivr     dword ptr [eax]
0042f7b6  d91d58ce5600             fstp      dword ptr [0x56ce58] ; bits=00000000, f32=0.0
0042f7bc  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0042f7bf  d90558ce5600             fld       dword ptr [0x56ce58] ; bits=00000000, f32=0.0
0042f7c5  d818                     fcomp     dword ptr [eax]
0042f7c7  db7d8c                   fstp      xword ptr [ebp - 0x74]
0042f7ca  dfe0                     fnstsw    ax
0042f7cc  9e                       sahf
0042f7cd  0f8a34000000             jp        0x42f807
0042f7d3  7632                     jbe       0x42f807
0042f7d5  db7dd4                   fstp      xword ptr [ebp - 0x2c]
0042f7d8  6850ce5600               push      0x56ce50
0042f7dd  6844ce5600               push      0x56ce44
0042f7e2  6848ce5600               push      0x56ce48
0042f7e7  68a0cb5600               push      0x56cba0
0042f7ec  6858ce5600               push      0x56ce58
0042f7f1  8b8564ffffff             mov       eax, dword ptr [ebp - 0x9c]
0042f7f7  8d08                     lea       ecx, [eax]
0042f7f9  51                       push      ecx
0042f7fa  e841480100               call      0x444040 ; _lktab_
0042f7ff  db6dd4                   fld       xword ptr [ebp - 0x2c]
0042f802  83c418                   add       esp, 0x18
0042f805  eb31                     jmp       0x42f838
0042f807  db7dd4                   fstp      xword ptr [ebp - 0x2c]
0042f80a  6850ce5600               push      0x56ce50
0042f80f  6844ce5600               push      0x56ce44
0042f814  6848ce5600               push      0x56ce48
0042f819  68a0cb5600               push      0x56cba0
0042f81e  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0042f821  8d00                     lea       eax, [eax]
0042f823  50                       push      eax
0042f824  8b8560ffffff             mov       eax, dword ptr [ebp - 0xa0]
0042f82a  8d08                     lea       ecx, [eax]
0042f82c  51                       push      ecx
0042f82d  e80e480100               call      0x444040 ; _lktab_
0042f832  db6dd4                   fld       xword ptr [ebp - 0x2c]
0042f835  83c418                   add       esp, 0x18
0042f838  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0042f83b  d9e8                     fld1
0042f83d  d830                     fdiv      dword ptr [eax]
0042f83f  db7d80                   fstp      xword ptr [ebp - 0x80]
0042f842  db6d8c                   fld       xword ptr [ebp - 0x74]
0042f845  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0042f848  d900                     fld       dword ptr [eax]
0042f84a  dbbd74ffffff             fstp      xword ptr [ebp - 0x8c]
0042f850  db7dbc                   fstp      xword ptr [ebp - 0x44]
0042f853  db7dc8                   fstp      xword ptr [ebp - 0x38]
0042f856  db6dc8                   fld       xword ptr [ebp - 0x38]
0042f859  db6d80                   fld       xword ptr [ebp - 0x80]
0042f85c  dec9                     fmulp     st(1)
0042f85e  d8c8                     fmul      st(0)
0042f860  d83534bcf400             fdiv      dword ptr [0xf4bc34]
0042f866  db6dbc                   fld       xword ptr [ebp - 0x44]
0042f869  dec1                     faddp     st(1)
0042f86b  db7dd4                   fstp      xword ptr [ebp - 0x2c]
0042f86e  dbad74ffffff             fld       xword ptr [ebp - 0x8c]
0042f874  db6dd4                   fld       xword ptr [ebp - 0x2c]
0042f877  def9                     fdivp     st(1)
0042f879  d91d54ce5600             fstp      dword ptr [0x56ce54] ; bits=00000000, f32=0.0
0042f87f  6850ce5600               push      0x56ce50
0042f884  6844ce5600               push      0x56ce44
0042f889  684cce5600               push      0x56ce4c
0042f88e  8d3d08cc5600             lea       edi, [0x56cc08] ; bits=03000000, f32=4.203895392974451e-45
0042f894  8d4798                   lea       eax, [edi - 0x68]
0042f897  50                       push      eax
0042f898  6854ce5600               push      0x56ce54
0042f89d  8d06                     lea       eax, [esi]
0042f89f  50                       push      eax
0042f8a0  e89b470100               call      0x444040 ; _lktab_
0042f8a5  83c418                   add       esp, 0x18
0042f8a8  db6dd4                   fld       xword ptr [ebp - 0x2c]
0042f8ab  d80d48ce5600             fmul      dword ptr [0x56ce48] ; bits=00000000, f32=0.0
0042f8b1  db6dd4                   fld       xword ptr [ebp - 0x2c]
0042f8b4  d9fa                     fsqrt
0042f8b6  d95dfc                   fstp      dword ptr [ebp - 4]
0042f8b9  d84dfc                   fmul      dword ptr [ebp - 4]
0042f8bc  d80d4cce5600             fmul      dword ptr [0x56ce4c] ; bits=00000000, f32=0.0
0042f8c2  db6dc8                   fld       xword ptr [ebp - 0x38]
0042f8c5  d8c1                     fadd      st(1)
0042f8c7  d8478c                   fadd      dword ptr [edi - 0x74]
0042f8ca  db6dc8                   fld       xword ptr [ebp - 0x38]
0042f8cd  d8ea                     fsubr     st(2)
0042f8cf  d9e1                     fabs
0042f8d1  def1                     fdivrp    st(1)
0042f8d3  d85f90                   fcomp     dword ptr [edi - 0x70]
0042f8d6  db6dc8                   fld       xword ptr [ebp - 0x38]
0042f8d9  db6dd4                   fld       xword ptr [ebp - 0x2c]
0042f8dc  db6dbc                   fld       xword ptr [ebp - 0x44]
0042f8df  dfe0                     fnstsw    ax
0042f8e1  9e                       sahf
0042f8e2  0f8a17000000             jp        0x42f8ff
0042f8e8  7715                     ja        0x42f8ff
0042f8ea  ddd8                     fstp      st(0)
0042f8ec  ddd9                     fstp      st(1)
0042f8ee  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
0042f8f1  d9c9                     fxch      st(1)
0042f8f3  d919                     fstp      dword ptr [ecx]
0042f8f5  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0042f8f8  d918                     fstp      dword ptr [eax]
0042f8fa  e9cb000000               jmp       0x42f9ca
0042f8ff  43                       inc       ebx
0042f900  83fb64                   cmp       ebx, 0x64
0042f903  0f8eb8000000             jle       0x42f9c1
0042f909  ddd8                     fstp      st(0)
0042f90b  db7dbc                   fstp      xword ptr [ebp - 0x44]
0042f90e  db7dc8                   fstp      xword ptr [ebp - 0x38]
0042f911  db7dd4                   fstp      xword ptr [ebp - 0x2c]
0042f914  68eccd5600               push      0x56cdec
0042f919  e862350700               call      0x4a2e80 ; _jwe_ilst
0042f91e  83c404                   add       esp, 4
0042f921  8b054cce5600             mov       eax, dword ptr [0x56ce4c] ; bits=00000000, f32=0.0
0042f927  8b4d24                   mov       ecx, dword ptr [ebp + 0x24]
0042f92a  8b09                     mov       ecx, dword ptr [ecx]
0042f92c  8b1548ce5600             mov       edx, dword ptr [0x56ce48] ; bits=00000000, f32=0.0
0042f932  8b5d1c                   mov       ebx, dword ptr [ebp + 0x1c]
0042f935  8b1b                     mov       ebx, dword ptr [ebx]
0042f937  8b7520                   mov       esi, dword ptr [ebp + 0x20]
0042f93a  8b36                     mov       esi, dword ptr [esi]
0042f93c  8d3d0ccd5600             lea       edi, [0x56cd0c] ; bits=09820000, f32=4.664782457890884e-41
0042f942  db6dbc                   fld       xword ptr [ebp - 0x44]
0042f945  d95dfc                   fstp      dword ptr [ebp - 4]
0042f948  898558ffffff             mov       dword ptr [ebp - 0xa8], eax
0042f94e  8d45fc                   lea       eax, [ebp - 4]
0042f951  894734                   mov       dword ptr [edi + 0x34], eax
0042f954  8b8558ffffff             mov       eax, dword ptr [ebp - 0xa8]
0042f95a  8945f8                   mov       dword ptr [ebp - 8], eax
0042f95d  8d45f8                   lea       eax, [ebp - 8]
0042f960  89474c                   mov       dword ptr [edi + 0x4c], eax
0042f963  db6dd4                   fld       xword ptr [ebp - 0x2c]
0042f966  d95df4                   fstp      dword ptr [ebp - 0xc]
0042f969  8d45f4                   lea       eax, [ebp - 0xc]
0042f96c  894764                   mov       dword ptr [edi + 0x64], eax
0042f96f  db6dc8                   fld       xword ptr [ebp - 0x38]
0042f972  d95df0                   fstp      dword ptr [ebp - 0x10]
0042f975  8d45f0                   lea       eax, [ebp - 0x10]
0042f978  89477c                   mov       dword ptr [edi + 0x7c], eax
0042f97b  894dec                   mov       dword ptr [ebp - 0x14], ecx
0042f97e  8d45ec                   lea       eax, [ebp - 0x14]
0042f981  898794000000             mov       dword ptr [edi + 0x94], eax
0042f987  8955e8                   mov       dword ptr [ebp - 0x18], edx
0042f98a  8d45e8                   lea       eax, [ebp - 0x18]
0042f98d  8987ac000000             mov       dword ptr [edi + 0xac], eax
0042f993  895de4                   mov       dword ptr [ebp - 0x1c], ebx
0042f996  8d45e4                   lea       eax, [ebp - 0x1c]
0042f999  8987c4000000             mov       dword ptr [edi + 0xc4], eax
0042f99f  8975e0                   mov       dword ptr [ebp - 0x20], esi
0042f9a2  8d45e0                   lea       eax, [ebp - 0x20]
0042f9a5  8987dc000000             mov       dword ptr [edi + 0xdc], eax
0042f9ab  57                       push      edi
0042f9ac  e8cf340700               call      0x4a2e80 ; _jwe_ilst
0042f9b1  83c404                   add       esp, 4
0042f9b4  68f4cc5600               push      0x56ccf4
0042f9b9  e8823a0700               call      0x4a3440 ; _jwe_xstp
0042f9be  83c404                   add       esp, 4
0042f9c1  ddd9                     fstp      st(1)
0042f9c3  ddd9                     fstp      st(1)
0042f9c5  e986feffff               jmp       0x42f850
0042f9ca  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0042f9cd  d900                     fld       dword ptr [eax]
0042f9cf  d90530bcf400             fld       dword ptr [0xf4bc30] ; _grvcom_
0042f9d5  d808                     fmul      dword ptr [eax]
0042f9d7  d9fa                     fsqrt
0042f9d9  d95dfc                   fstp      dword ptr [ebp - 4]
0042f9dc  d84dfc                   fmul      dword ptr [ebp - 4]
0042f9df  d901                     fld       dword ptr [ecx]
0042f9e1  d8d9                     fcomp     st(1)
0042f9e3  dbbd68ffffff             fstp      xword ptr [ebp - 0x98]
0042f9e9  dfe0                     fnstsw    ax
0042f9eb  9e                       sahf
0042f9ec  0f8a0c000000             jp        0x42f9fe
0042f9f2  760a                     jbe       0x42f9fe
0042f9f4  89c8                     mov       eax, ecx
0042f9f6  dbad68ffffff             fld       xword ptr [ebp - 0x98]
0042f9fc  d918                     fstp      dword ptr [eax]
0042f9fe  b800000000               mov       eax, 0
0042fa03  5f                       pop       edi
0042fa04  5e                       pop       esi
0042fa05  5b                       pop       ebx
0042fa06  8be5                     mov       esp, ebp
0042fa08  5d                       pop       ebp
0042fa09  c3                       ret
0042fa0a  8d9b00000000             lea       ebx, [ebx]
