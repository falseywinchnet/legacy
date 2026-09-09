; _compel_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x979e0
004979e0  55                       push      ebp
004979e1  8bec                     mov       ebp, esp
004979e3  b8cc010000               mov       eax, 0x1cc
004979e8  e813160500               call      0x4e9000 ; __alloca_probe
004979ed  53                       push      ebx
004979ee  56                       push      esi
004979ef  57                       push      edi
004979f0  8b4508                   mov       eax, dword ptr [ebp + 8]
004979f3  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
004979f6  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
004979f9  89854cfeffff             mov       dword ptr [ebp - 0x1b4], eax
004979ff  898d48feffff             mov       dword ptr [ebp - 0x1b8], ecx
00497a05  d90530bcf400             fld       dword ptr [0xf4bc30] ; _grvcom_
00497a0b  8d15609a5b00             lea       edx, [0x5b9a60] ; bits=d0200000, f32=1.1770907100328463e-41
00497a11  d85a90                   fcomp     dword ptr [edx - 0x70]
00497a14  dfe0                     fnstsw    ax
00497a16  9e                       sahf
00497a17  0f8a0a000000             jp        0x497a27
00497a1d  7608                     jbe       0x497a27
00497a1f  d94294                   fld       dword ptr [edx - 0x6c]
00497a22  db7ddc                   fstp      xword ptr [ebp - 0x24]
00497a25  eb08                     jmp       0x497a2f
00497a27  89d0                     mov       eax, edx
00497a29  d94098                   fld       dword ptr [eax - 0x68]
00497a2c  db7ddc                   fstp      xword ptr [ebp - 0x24]
00497a2f  d905accc1204             fld       dword ptr [0x412ccac]
00497a35  d80dfc995b00             fmul      dword ptr [0x5b99fc] ; bits=4703803f, f32=1.000100016593933
00497a3b  db7dd0                   fstp      xword ptr [ebp - 0x30]
00497a3e  6a08                     push      8
00497a40  68c0aeb000               push      0xb0aec0
00497a45  6840bbb000               push      0xb0bb40
00497a4a  6860beb000               push      0xb0be60
00497a4f  68a0c4b000               push      0xb0c4a0
00497a54  68789c5b00               push      0x5b9c78
00497a59  68709c5b00               push      0x5b9c70
00497a5e  68489c5b00               push      0x5b9c48
00497a63  68509c5b00               push      0x5b9c50
00497a68  68589c5b00               push      0x5b9c58
00497a6d  68609c5b00               push      0x5b9c60
00497a72  68689c5b00               push      0x5b9c68
00497a77  68809c5b00               push      0x5b9c80
00497a7c  6800b5b000               push      0xb0b500
00497a81  6800ceb000               push      0xb0ce00
00497a86  68c0c7b000               push      0xb0c7c0
00497a8b  6820b8b000               push      0xb0b820
00497a90  6880c1b000               push      0xb0c180
00497a95  8b4554                   mov       eax, dword ptr [ebp + 0x54]
00497a98  8d00                     lea       eax, [eax]
00497a9a  50                       push      eax
00497a9b  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00497a9e  8d00                     lea       eax, [eax]
00497aa0  50                       push      eax
00497aa1  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00497aa4  8d00                     lea       eax, [eax]
00497aa6  50                       push      eax
00497aa7  8b4540                   mov       eax, dword ptr [ebp + 0x40]
00497aaa  8d00                     lea       eax, [eax]
00497aac  50                       push      eax
00497aad  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
00497ab0  8d00                     lea       eax, [eax]
00497ab2  50                       push      eax
00497ab3  8b4538                   mov       eax, dword ptr [ebp + 0x38]
00497ab6  8d00                     lea       eax, [eax]
00497ab8  50                       push      eax
00497ab9  8b4544                   mov       eax, dword ptr [ebp + 0x44]
00497abc  8d00                     lea       eax, [eax]
00497abe  50                       push      eax
00497abf  8b4534                   mov       eax, dword ptr [ebp + 0x34]
00497ac2  8d00                     lea       eax, [eax]
00497ac4  50                       push      eax
00497ac5  8b4530                   mov       eax, dword ptr [ebp + 0x30]
00497ac8  8d00                     lea       eax, [eax]
00497aca  50                       push      eax
00497acb  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00497ace  8d00                     lea       eax, [eax]
00497ad0  50                       push      eax
00497ad1  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00497ad4  8d00                     lea       eax, [eax]
00497ad6  50                       push      eax
00497ad7  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00497ada  8d00                     lea       eax, [eax]
00497adc  50                       push      eax
00497add  8d03                     lea       eax, [ebx]
00497adf  50                       push      eax
00497ae0  8b8548feffff             mov       eax, dword ptr [ebp - 0x1b8]
00497ae6  8d08                     lea       ecx, [eax]
00497ae8  8b854cfeffff             mov       eax, dword ptr [ebp - 0x1b4]
00497aee  51                       push      ecx
00497aef  8d08                     lea       ecx, [eax]
00497af1  51                       push      ecx
00497af2  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
00497af5  8d09                     lea       ecx, [ecx]
00497af7  51                       push      ecx
00497af8  e853e7ffff               call      0x496250 ; _fbasel_
00497afd  81c488000000             add       esp, 0x88
00497b03  d9ee                     fldz
00497b05  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00497b08  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497b0b  db7db8                   fstp      xword ptr [ebp - 0x48]
00497b0e  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497b11  db7dac                   fstp      xword ptr [ebp - 0x54]
00497b14  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497b17  db7da0                   fstp      xword ptr [ebp - 0x60]
00497b1a  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497b1d  db7d94                   fstp      xword ptr [ebp - 0x6c]
00497b20  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497b23  db7d88                   fstp      xword ptr [ebp - 0x78]
00497b26  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497b29  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
00497b2f  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497b32  dbbd70ffffff             fstp      xword ptr [ebp - 0x90]
00497b38  8b03                     mov       eax, dword ptr [ebx]
00497b3a  89c1                     mov       ecx, eax
00497b3c  83f900                   cmp       ecx, 0
00497b3f  898544feffff             mov       dword ptr [ebp - 0x1bc], eax
00497b45  898d40feffff             mov       dword ptr [ebp - 0x1c0], ecx
00497b4b  0f8e35040000             jle       0x497f86
00497b51  bb01000000               mov       ebx, 1
00497b56  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00497b59  8b08                     mov       ecx, dword ptr [eax]
00497b5b  898d3cfeffff             mov       dword ptr [ebp - 0x1c4], ecx
00497b61  db6dac                   fld       xword ptr [ebp - 0x54]
00497b64  db6db8                   fld       xword ptr [ebp - 0x48]
00497b67  c7049ddcb1b00000000000   mov       dword ptr [ebx*4 + 0xb0b1dc], 0
00497b72  d9049d7cc1b000           fld       dword ptr [ebx*4 + 0xb0c17c]
00497b79  d9c9                     fxch      st(1)
00497b7b  d8049d7cc1b000           fadd      dword ptr [ebx*4 + 0xb0c17c]
00497b82  d9049d1cb8b000           fld       dword ptr [ebx*4 + 0xb0b81c]
00497b89  d9cb                     fxch      st(3)
00497b8b  d8049d1cb8b000           fadd      dword ptr [ebx*4 + 0xb0b81c]
00497b92  d9cb                     fxch      st(3)
00497b94  dbbd64ffffff             fstp      xword ptr [ebp - 0x9c]
00497b9a  db7db8                   fstp      xword ptr [ebp - 0x48]
00497b9d  d9c9                     fxch      st(1)
00497b9f  db7dac                   fstp      xword ptr [ebp - 0x54]
00497ba2  83bd3cfeffff01           cmp       dword ptr [ebp - 0x1c4], 1
00497ba9  751b                     jne       0x497bc6
00497bab  dbad70ffffff             fld       xword ptr [ebp - 0x90]
00497bb1  8b4554                   mov       eax, dword ptr [ebp + 0x54]
00497bb4  dbad64ffffff             fld       xword ptr [ebp - 0x9c]
00497bba  d84c98fc                 fmul      dword ptr [eax + ebx*4 - 4]
00497bbe  dec1                     faddp     st(1)
00497bc0  dbbd70ffffff             fstp      xword ptr [ebp - 0x90]
00497bc6  d9ee                     fldz
00497bc8  dbad64ffffff             fld       xword ptr [ebp - 0x9c]
00497bce  dae9                     fucompp
00497bd0  dfe0                     fnstsw    ax
00497bd2  9e                       sahf
00497bd3  0f8a06000000             jp        0x497bdf
00497bd9  0f8493030000             je        0x497f72
00497bdf  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497be2  db6da0                   fld       xword ptr [ebp - 0x60]
00497be5  dd04ddb8c7b000           fld       qword ptr [ebx*8 + 0xb0c7b8]
00497bec  d9ca                     fxch      st(2)
00497bee  dc04ddb8c7b000           fadd      qword ptr [ebx*8 + 0xb0c7b8]
00497bf5  d95dfc                   fstp      dword ptr [ebp - 4]
00497bf8  d945fc                   fld       dword ptr [ebp - 4]
00497bfb  d9c9                     fxch      st(1)
00497bfd  dc04ddf8cdb000           fadd      qword ptr [ebx*8 + 0xb0cdf8]
00497c04  d95dfc                   fstp      dword ptr [ebp - 4]
00497c07  d945fc                   fld       dword ptr [ebp - 4]
00497c0a  d9ca                     fxch      st(2)
00497c0c  dd9d58ffffff             fstp      qword ptr [ebp - 0xa8]
00497c12  d9c9                     fxch      st(1)
00497c14  db7da0                   fstp      xword ptr [ebp - 0x60]
00497c17  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00497c1a  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00497c1d  833800                   cmp       dword ptr [eax], 0
00497c20  0f8543030000             jne       0x497f69
00497c26  d9ee                     fldz
00497c28  dd8558ffffff             fld       qword ptr [ebp - 0xa8]
00497c2e  dc1de0995b00             fcomp     qword ptr [0x5b99e0] ; bits=0000000000000000, f64=0.0
00497c34  dd9d50ffffff             fstp      qword ptr [ebp - 0xb0]
00497c3a  dfe0                     fnstsw    ax
00497c3c  9e                       sahf
00497c3d  0f8a50000000             jp        0x497c93
00497c43  734e                     jae       0x497c93
00497c45  8b854cfeffff             mov       eax, dword ptr [ebp - 0x1b4]
00497c4b  db7de8                   fstp      xword ptr [ebp - 0x18]
00497c4e  8b08                     mov       ecx, dword ptr [eax]
00497c50  8d15109c5b00             lea       edx, [0x5b9c10] ; bits=09020000, f32=7.300764999132297e-43
00497c56  894dfc                   mov       dword ptr [ebp - 4], ecx
00497c59  8d4dfc                   lea       ecx, [ebp - 4]
00497c5c  894a28                   mov       dword ptr [edx + 0x28], ecx
00497c5f  895df8                   mov       dword ptr [ebp - 8], ebx
00497c62  8d4df8                   lea       ecx, [ebp - 8]
00497c65  894a34                   mov       dword ptr [edx + 0x34], ecx
00497c68  52                       push      edx
00497c69  e882a90000               call      0x4a25f0 ; _jwe_isfm
00497c6e  83c404                   add       esp, 4
00497c71  c7054895b70001000000     mov       dword ptr [0xb79548], 1
00497c7b  dd04ddb8c7b000           fld       qword ptr [ebx*8 + 0xb0c7b8]
00497c82  d9e1                     fabs
00497c84  dd1cddb8c7b000           fstp      qword ptr [ebx*8 + 0xb0c7b8]
00497c8b  db6de8                   fld       xword ptr [ebp - 0x18]
00497c8e  e9aa000000               jmp       0x497d3d
00497c93  dd8558ffffff             fld       qword ptr [ebp - 0xa8]
00497c99  dd8550ffffff             fld       qword ptr [ebp - 0xb0]
00497c9f  d9c9                     fxch      st(1)
00497ca1  dae9                     fucompp
00497ca3  dfe0                     fnstsw    ax
00497ca5  9e                       sahf
00497ca6  0f8a91000000             jp        0x497d3d
00497cac  0f858b000000             jne       0x497d3d
00497cb2  d9ee                     fldz
00497cb4  d9c9                     fxch      st(1)
00497cb6  dde1                     fucom     st(1)
00497cb8  ddd9                     fstp      st(1)
00497cba  dfe0                     fnstsw    ax
00497cbc  9e                       sahf
00497cbd  0f8a5d000000             jp        0x497d20
00497cc3  755b                     jne       0x497d20
00497cc5  ddd8                     fstp      st(0)
00497cc7  8b4548                   mov       eax, dword ptr [ebp + 0x48]
00497cca  833801                   cmp       dword ptr [eax], 1
00497ccd  898534feffff             mov       dword ptr [ebp - 0x1cc], eax
00497cd3  0f859f020000             jne       0x497f78
00497cd9  8b854cfeffff             mov       eax, dword ptr [ebp - 0x1b4]
00497cdf  8b08                     mov       ecx, dword ptr [eax]
00497ce1  8d15d89b5b00             lea       edx, [0x5b9bd8] ; bits=09020000, f32=7.300764999132297e-43
00497ce7  894dfc                   mov       dword ptr [ebp - 4], ecx
00497cea  8d4dfc                   lea       ecx, [ebp - 4]
00497ced  894a28                   mov       dword ptr [edx + 0x28], ecx
00497cf0  895df8                   mov       dword ptr [ebp - 8], ebx
00497cf3  8d4df8                   lea       ecx, [ebp - 8]
00497cf6  894a34                   mov       dword ptr [edx + 0x34], ecx
00497cf9  52                       push      edx
00497cfa  e8f1a80000               call      0x4a25f0 ; _jwe_isfm
00497cff  83c404                   add       esp, 4
00497d02  8b8534feffff             mov       eax, dword ptr [ebp - 0x1cc]
00497d08  c70000000000             mov       dword ptr [eax], 0
00497d0e  68b89b5b00               push      0x5b9bb8
00497d13  e8d8a80000               call      0x4a25f0 ; _jwe_isfm
00497d18  83c404                   add       esp, 4
00497d1b  e958020000               jmp       0x497f78
00497d20  dd8550ffffff             fld       qword ptr [ebp - 0xb0]
00497d26  dd8558ffffff             fld       qword ptr [ebp - 0xa8]
00497d2c  dae9                     fucompp
00497d2e  dfe0                     fnstsw    ax
00497d30  9e                       sahf
00497d31  0f8a06000000             jp        0x497d3d
00497d37  0f8439020000             je        0x497f76
00497d3d  db7de8                   fstp      xword ptr [ebp - 0x18]
00497d40  dd04ddb8c7b000           fld       qword ptr [ebx*8 + 0xb0c7b8]
00497d47  dd9d48ffffff             fstp      qword ptr [ebp - 0xb8]
00497d4d  dbad64ffffff             fld       xword ptr [ebp - 0x9c]
00497d53  dcbd48ffffff             fdivr     qword ptr [ebp - 0xb8]
00497d59  d91d889c5b00             fstp      dword ptr [0x5b9c88] ; bits=00000000, f32=0.0
00497d5f  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00497d62  d900                     fld       dword ptr [eax]
00497d64  dc8d48ffffff             fmul      qword ptr [ebp - 0xb8]
00497d6a  dd9d40ffffff             fstp      qword ptr [ebp - 0xc0]
00497d70  68009a5b00               push      0x5b9a00
00497d75  68889c5b00               push      0x5b9c88
00497d7a  e8318a0000               call      0x4a07b0 ; _g_arxr
00497d7f  83c408                   add       esp, 8
00497d82  dc8d40ffffff             fmul      qword ptr [ebp - 0xc0]
00497d88  8b4554                   mov       eax, dword ptr [ebp + 0x54]
00497d8b  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
00497d8f  dbbd34ffffff             fstp      xword ptr [ebp - 0xcc]
00497d95  dbad34ffffff             fld       xword ptr [ebp - 0xcc]
00497d9b  def9                     fdivp     st(1)
00497d9d  d95dfc                   fstp      dword ptr [ebp - 4]
00497da0  d945fc                   fld       dword ptr [ebp - 4]
00497da3  db6de8                   fld       xword ptr [ebp - 0x18]
00497da6  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
00497da9  8b10                     mov       edx, dword ptr [eax]
00497dab  83fa02                   cmp       edx, 2
00497dae  7539                     jne       0x497de9
00497db0  d9049d5cbeb000           fld       dword ptr [ebx*4 + 0xb0be5c]
00497db7  d9c0                     fld       st(0)
00497db9  d9fa                     fsqrt
00497dbb  d95dfc                   fstp      dword ptr [ebp - 4]
00497dbe  d9ca                     fxch      st(2)
00497dc0  d875fc                   fdiv      dword ptr [ebp - 4]
00497dc3  d9c2                     fld       st(2)
00497dc5  dc8d48ffffff             fmul      qword ptr [ebp - 0xb8]
00497dcb  dc05709c5b00             fadd      qword ptr [0x5b9c70] ; bits=0000000000000000, f64=0.0
00497dd1  dd1d709c5b00             fstp      qword ptr [0x5b9c70] ; bits=0000000000000000, f64=0.0
00497dd7  dcca                     fmul      st(2), st(0)
00497dd9  d9ca                     fxch      st(2)
00497ddb  dc05789c5b00             fadd      qword ptr [0x5b9c78] ; bits=0000000000000000, f64=0.0
00497de1  dd1d789c5b00             fstp      qword ptr [0x5b9c78] ; bits=0000000000000000, f64=0.0
00497de7  eb38                     jmp       0x497e21
00497de9  83fa01                   cmp       edx, 1
00497dec  7533                     jne       0x497e21
00497dee  d9049dbcaeb000           fld       dword ptr [ebx*4 + 0xb0aebc]
00497df5  d9ee                     fldz
00497df7  d9c9                     fxch      st(1)
00497df9  dde1                     fucom     st(1)
00497dfb  ddd9                     fstp      st(1)
00497dfd  dbbd28ffffff             fstp      xword ptr [ebp - 0xd8]
00497e03  dfe0                     fnstsw    ax
00497e05  9e                       sahf
00497e06  0f8a02000000             jp        0x497e0e
00497e0c  7413                     je        0x497e21
00497e0e  d9c9                     fxch      st(1)
00497e10  d80c9d3cbbb000           fmul      dword ptr [ebx*4 + 0xb0bb3c]
00497e17  dbad28ffffff             fld       xword ptr [ebp - 0xd8]
00497e1d  def9                     fdivp     st(1)
00497e1f  d9c9                     fxch      st(1)
00497e21  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
00497e24  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
00497e28  d9ca                     fxch      st(2)
00497e2a  d85498fc                 fcom      dword ptr [eax + ebx*4 - 4]
00497e2e  d9ca                     fxch      st(2)
00497e30  dbbd1cffffff             fstp      xword ptr [ebp - 0xe4]
00497e36  dfe0                     fnstsw    ax
00497e38  9e                       sahf
00497e39  0f8a39000000             jp        0x497e78
00497e3f  7337                     jae       0x497e78
00497e41  db6dd0                   fld       xword ptr [ebp - 0x30]
00497e44  d9c9                     fxch      st(1)
00497e46  d8d1                     fcom      st(1)
00497e48  ddd9                     fstp      st(1)
00497e4a  dfe0                     fnstsw    ax
00497e4c  9e                       sahf
00497e4d  0f8a25000000             jp        0x497e78
00497e53  7723                     ja        0x497e78
00497e55  8b4550                   mov       eax, dword ptr [ebp + 0x50]
00497e58  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
00497e5c  db6dd0                   fld       xword ptr [ebp - 0x30]
00497e5f  d9c9                     fxch      st(1)
00497e61  ded9                     fcompp
00497e63  dfe0                     fnstsw    ax
00497e65  9e                       sahf
00497e66  0f8a0c000000             jp        0x497e78
00497e6c  770a                     ja        0x497e78
00497e6e  ddd9                     fstp      st(1)
00497e70  dbad1cffffff             fld       xword ptr [ebp - 0xe4]
00497e76  d9c9                     fxch      st(1)
00497e78  db6d94                   fld       xword ptr [ebp - 0x6c]
00497e7b  d9ca                     fxch      st(2)
00497e7d  d9149ddcb1b000           fst       dword ptr [ebx*4 + 0xb0b1dc]
00497e84  dcc2                     fadd      st(2), st(0)
00497e86  d9ca                     fxch      st(2)
00497e88  db7d94                   fstp      xword ptr [ebp - 0x6c]
00497e8b  833db0cc120401           cmp       dword ptr [0x412ccb0], 1
00497e92  7578                     jne       0x497f0c
00497e94  8d05609a5b00             lea       eax, [0x5b9a60] ; bits=d0200000, f32=1.1770907100328463e-41
00497e9a  dbad34ffffff             fld       xword ptr [ebp - 0xcc]
00497ea0  d848a4                   fmul      dword ptr [eax - 0x5c]
00497ea3  d840a8                   fadd      dword ptr [eax - 0x58]
00497ea6  d940ac                   fld       dword ptr [eax - 0x54]
00497ea9  d9c9                     fxch      st(1)
00497eab  d850ac                   fcom      dword ptr [eax - 0x54]
00497eae  d9c9                     fxch      st(1)
00497eb0  dbbd10ffffff             fstp      xword ptr [ebp - 0xf0]
00497eb6  d9c9                     fxch      st(1)
00497eb8  dfe0                     fnstsw    ax
00497eba  9e                       sahf
00497ebb  0f8a0c000000             jp        0x497ecd
00497ec1  760a                     jbe       0x497ecd
00497ec3  ddd9                     fstp      st(1)
00497ec5  dbad10ffffff             fld       xword ptr [ebp - 0xf0]
00497ecb  d9c9                     fxch      st(1)
00497ecd  d9e8                     fld1
00497ecf  d9ca                     fxch      st(2)
00497ed1  d815109a5b00             fcom      dword ptr [0x5b9a10] ; bits=0000803f, f32=1.0
00497ed7  d9ca                     fxch      st(2)
00497ed9  dbbd04ffffff             fstp      xword ptr [ebp - 0xfc]
00497edf  dfe0                     fnstsw    ax
00497ee1  9e                       sahf
00497ee2  0f8a0c000000             jp        0x497ef4
00497ee8  730a                     jae       0x497ef4
00497eea  ddd9                     fstp      st(1)
00497eec  dbad04ffffff             fld       xword ptr [ebp - 0xfc]
00497ef2  d9c9                     fxch      st(1)
00497ef4  d9c1                     fld       st(1)
00497ef6  d825109a5b00             fsub      dword ptr [0x5b9a10] ; bits=0000803f, f32=1.0
00497efc  d80d149a5b00             fmul      dword ptr [0x5b9a14] ; bits=aa82b13e, f32=0.3467000126838684
00497f02  d805109a5b00             fadd      dword ptr [0x5b9a10] ; bits=0000803f, f32=1.0
00497f08  d9c9                     fxch      st(1)
00497f0a  eb08                     jmp       0x497f14
00497f0c  d9e8                     fld1
00497f0e  d9c0                     fld       st(0)
00497f10  d9c9                     fxch      st(1)
00497f12  d9ca                     fxch      st(2)
00497f14  d9cb                     fxch      st(3)
00497f16  dbbdf8feffff             fstp      xword ptr [ebp - 0x108]
00497f1c  db6d88                   fld       xword ptr [ebp - 0x78]
00497f1f  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00497f25  dbadf8feffff             fld       xword ptr [ebp - 0x108]
00497f2b  d8c8                     fmul      st(0)
00497f2d  dd04ddb8c7b000           fld       qword ptr [ebx*8 + 0xb0c7b8]
00497f34  d9c9                     fxch      st(1)
00497f36  dc34ddb8c7b000           fdiv      qword ptr [ebx*8 + 0xb0c7b8]
00497f3d  d95dfc                   fstp      dword ptr [ebp - 4]
00497f40  d9cb                     fxch      st(3)
00497f42  d84dfc                   fmul      dword ptr [ebp - 4]
00497f45  dec1                     faddp     st(1)
00497f47  dbadf8feffff             fld       xword ptr [ebp - 0x108]
00497f4d  decc                     fmulp     st(4)
00497f4f  d9cb                     fxch      st(3)
00497f51  d84dfc                   fmul      dword ptr [ebp - 4]
00497f54  def2                     fdivrp    st(2)
00497f56  dec1                     faddp     st(1)
00497f58  d95dfc                   fstp      dword ptr [ebp - 4]
00497f5b  d945fc                   fld       dword ptr [ebp - 4]
00497f5e  d9c9                     fxch      st(1)
00497f60  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
00497f66  db7d88                   fstp      xword ptr [ebp - 0x78]
00497f69  8b4550                   mov       eax, dword ptr [ebp + 0x50]
00497f6c  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
00497f70  eb06                     jmp       0x497f78
00497f72  ddd8                     fstp      st(0)
00497f74  eb02                     jmp       0x497f78
00497f76  ddd8                     fstp      st(0)
00497f78  43                       inc       ebx
00497f79  83ad40feffff01           sub       dword ptr [ebp - 0x1c0], 1
00497f80  0f85dbfbffff             jne       0x497b61
00497f86  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00497f89  833801                   cmp       dword ptr [eax], 1
00497f8c  7569                     jne       0x497ff7
00497f8e  d9ee                     fldz
00497f90  db6dac                   fld       xword ptr [ebp - 0x54]
00497f93  d81de8995b00             fcomp     dword ptr [0x5b99e8] ; bits=00000000, f32=0.0
00497f99  dbbdecfeffff             fstp      xword ptr [ebp - 0x114]
00497f9f  dfe0                     fnstsw    ax
00497fa1  9e                       sahf
00497fa2  0f8a46000000             jp        0x497fee
00497fa8  7644                     jbe       0x497fee
00497faa  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00497fad  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497fb0  d808                     fmul      dword ptr [eax]
00497fb2  dbbde0feffff             fstp      xword ptr [ebp - 0x120]
00497fb8  db6dc4                   fld       xword ptr [ebp - 0x3c]
00497fbb  db6dac                   fld       xword ptr [ebp - 0x54]
00497fbe  def9                     fdivp     st(1)
00497fc0  d95dfc                   fstp      dword ptr [ebp - 4]
00497fc3  68009a5b00               push      0x5b9a00
00497fc8  8d45fc                   lea       eax, [ebp - 4]
00497fcb  50                       push      eax
00497fcc  e8df870000               call      0x4a07b0 ; _g_arxr
00497fd1  83c408                   add       esp, 8
00497fd4  dbade0feffff             fld       xword ptr [ebp - 0x120]
00497fda  dec9                     fmulp     st(1)
00497fdc  db6dac                   fld       xword ptr [ebp - 0x54]
00497fdf  dec9                     fmulp     st(1)
00497fe1  dbad70ffffff             fld       xword ptr [ebp - 0x90]
00497fe7  def9                     fdivp     st(1)
00497fe9  db7d94                   fstp      xword ptr [ebp - 0x6c]
00497fec  eb09                     jmp       0x497ff7
00497fee  dbadecfeffff             fld       xword ptr [ebp - 0x114]
00497ff4  db7d94                   fstp      xword ptr [ebp - 0x6c]
00497ff7  db6d94                   fld       xword ptr [ebp - 0x6c]
00497ffa  d81de8995b00             fcomp     dword ptr [0x5b99e8] ; bits=00000000, f32=0.0
00498000  dfe0                     fnstsw    ax
00498002  9e                       sahf
00498003  0f8a02000000             jp        0x49800b
00498009  762d                     jbe       0x498038
0049800b  db6d88                   fld       xword ptr [ebp - 0x78]
0049800e  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00498014  db6d94                   fld       xword ptr [ebp - 0x6c]
00498017  db6d94                   fld       xword ptr [ebp - 0x6c]
0049801a  dec9                     fmulp     st(1)
0049801c  db6dc4                   fld       xword ptr [ebp - 0x3c]
0049801f  def1                     fdivrp    st(1)
00498021  dcc9                     fmul      st(1), st(0)
00498023  deca                     fmulp     st(2)
00498025  db6dc4                   fld       xword ptr [ebp - 0x3c]
00498028  deca                     fmulp     st(2)
0049802a  db6d94                   fld       xword ptr [ebp - 0x6c]
0049802d  defa                     fdivp     st(2)
0049802f  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
00498035  db7d88                   fstp      xword ptr [ebp - 0x78]
00498038  d9e8                     fld1
0049803a  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00498040  d81d109a5b00             fcomp     dword ptr [0x5b9a10] ; bits=0000803f, f32=1.0
00498046  dbbdd4feffff             fstp      xword ptr [ebp - 0x12c]
0049804c  dfe0                     fnstsw    ax
0049804e  9e                       sahf
0049804f  0f8a0e000000             jp        0x498063
00498055  730c                     jae       0x498063
00498057  dbadd4feffff             fld       xword ptr [ebp - 0x12c]
0049805d  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
00498063  d9e8                     fld1
00498065  db6d88                   fld       xword ptr [ebp - 0x78]
00498068  d81d109a5b00             fcomp     dword ptr [0x5b9a10] ; bits=0000803f, f32=1.0
0049806e  dbbdc8feffff             fstp      xword ptr [ebp - 0x138]
00498074  dfe0                     fnstsw    ax
00498076  9e                       sahf
00498077  0f8a0b000000             jp        0x498088
0049807d  7309                     jae       0x498088
0049807f  dbadc8feffff             fld       xword ptr [ebp - 0x138]
00498085  db7d88                   fstp      xword ptr [ebp - 0x78]
00498088  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
0049808e  898538feffff             mov       dword ptr [ebp - 0x1c8], eax
00498094  3d00000000               cmp       eax, 0
00498099  0f8ec6000000             jle       0x498165
0049809f  bb01000000               mov       ebx, 1
004980a4  d9049ddcb1b000           fld       dword ptr [ebx*4 + 0xb0b1dc]
004980ab  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
004980ae  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
004980b2  d9c9                     fxch      st(1)
004980b4  d85498fc                 fcom      dword ptr [eax + ebx*4 - 4]
004980b8  d9c9                     fxch      st(1)
004980ba  dfe0                     fnstsw    ax
004980bc  9e                       sahf
004980bd  0f8a7f000000             jp        0x498142
004980c3  737d                     jae       0x498142
004980c5  833da8cc120400           cmp       dword ptr [0x412cca8], 0
004980cc  7578                     jne       0x498146
004980ce  d9c1                     fld       st(1)
004980d0  d8e1                     fsub      st(1)
004980d2  def1                     fdivrp    st(1)
004980d4  d80d189a5b00             fmul      dword ptr [0x5b9a18] ; bits=0000c842, f32=100.0
004980da  d9049d7cc1b000           fld       dword ptr [ebx*4 + 0xb0c17c]
004980e1  db6ddc                   fld       xword ptr [ebp - 0x24]
004980e4  d9c9                     fxch      st(1)
004980e6  ded9                     fcompp
004980e8  dfe0                     fnstsw    ax
004980ea  9e                       sahf
004980eb  0f8a59000000             jp        0x49814a
004980f1  7657                     jbe       0x49814a
004980f3  d9e1                     fabs
004980f5  d815109a5b00             fcom      dword ptr [0x5b9a10] ; bits=0000803f, f32=1.0
004980fb  dfe0                     fnstsw    ax
004980fd  9e                       sahf
004980fe  0f8a4a000000             jp        0x49814e
00498104  7648                     jbe       0x49814e
00498106  d9c9                     fxch      st(1)
00498108  8b854cfeffff             mov       eax, dword ptr [ebp - 0x1b4]
0049810e  db7de8                   fstp      xword ptr [ebp - 0x18]
00498111  8b08                     mov       ecx, dword ptr [eax]
00498113  8d15749b5b00             lea       edx, [0x5b9b74] ; bits=09020000, f32=7.300764999132297e-43
00498119  895df8                   mov       dword ptr [ebp - 8], ebx
0049811c  8d75f8                   lea       esi, [ebp - 8]
0049811f  897228                   mov       dword ptr [edx + 0x28], esi
00498122  894dfc                   mov       dword ptr [ebp - 4], ecx
00498125  8d4dfc                   lea       ecx, [ebp - 4]
00498128  894a34                   mov       dword ptr [edx + 0x34], ecx
0049812b  d95df4                   fstp      dword ptr [ebp - 0xc]
0049812e  8d4df4                   lea       ecx, [ebp - 0xc]
00498131  894a40                   mov       dword ptr [edx + 0x40], ecx
00498134  52                       push      edx
00498135  e8b6a40000               call      0x4a25f0 ; _jwe_isfm
0049813a  db6de8                   fld       xword ptr [ebp - 0x18]
0049813d  83c404                   add       esp, 4
00498140  eb0e                     jmp       0x498150
00498142  ddd8                     fstp      st(0)
00498144  eb0a                     jmp       0x498150
00498146  ddd8                     fstp      st(0)
00498148  eb06                     jmp       0x498150
0049814a  ddd8                     fstp      st(0)
0049814c  eb02                     jmp       0x498150
0049814e  ddd8                     fstp      st(0)
00498150  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
00498153  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
00498157  43                       inc       ebx
00498158  83ad38feffff01           sub       dword ptr [ebp - 0x1c8], 1
0049815f  0f853fffffff             jne       0x4980a4
00498165  8b5d58                   mov       ebx, dword ptr [ebp + 0x58]
00498168  db6db8                   fld       xword ptr [ebp - 0x48]
0049816b  d95b04                   fstp      dword ptr [ebx + 4]
0049816e  db6dc4                   fld       xword ptr [ebp - 0x3c]
00498171  d95b08                   fstp      dword ptr [ebx + 8]
00498174  db6da0                   fld       xword ptr [ebp - 0x60]
00498177  d95b0c                   fstp      dword ptr [ebx + 0xc]
0049817a  db6d94                   fld       xword ptr [ebp - 0x6c]
0049817d  d9fa                     fsqrt
0049817f  d95dfc                   fstp      dword ptr [ebp - 4]
00498182  8b45fc                   mov       eax, dword ptr [ebp - 4]
00498185  894310                   mov       dword ptr [ebx + 0x10], eax
00498188  db6dac                   fld       xword ptr [ebp - 0x54]
0049818b  d95b3c                   fstp      dword ptr [ebx + 0x3c]
0049818e  db6dc4                   fld       xword ptr [ebp - 0x3c]
00498191  d81de8995b00             fcomp     dword ptr [0x5b99e8] ; bits=00000000, f32=0.0
00498197  dfe0                     fnstsw    ax
00498199  9e                       sahf
0049819a  0f8a3e000000             jp        0x4981de
004981a0  763c                     jbe       0x4981de
004981a2  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004981a5  db6dc4                   fld       xword ptr [ebp - 0x3c]
004981a8  d808                     fmul      dword ptr [eax]
004981aa  dbbdbcfeffff             fstp      xword ptr [ebp - 0x144]
004981b0  db6dc4                   fld       xword ptr [ebp - 0x3c]
004981b3  db6dac                   fld       xword ptr [ebp - 0x54]
004981b6  def9                     fdivp     st(1)
004981b8  d95dfc                   fstp      dword ptr [ebp - 4]
004981bb  68009a5b00               push      0x5b9a00
004981c0  8d45fc                   lea       eax, [ebp - 4]
004981c3  50                       push      eax
004981c4  e8e7850000               call      0x4a07b0 ; _g_arxr
004981c9  83c408                   add       esp, 8
004981cc  dbadbcfeffff             fld       xword ptr [ebp - 0x144]
004981d2  dec9                     fmulp     st(1)
004981d4  db6d94                   fld       xword ptr [ebp - 0x6c]
004981d7  def9                     fdivp     st(1)
004981d9  d95b40                   fstp      dword ptr [ebx + 0x40]
004981dc  eb09                     jmp       0x4981e7
004981de  89d8                     mov       eax, ebx
004981e0  c7404000000000           mov       dword ptr [eax + 0x40], 0
004981e7  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004981ea  8d10                     lea       edx, [eax]
004981ec  8d1d409b5b00             lea       ebx, [0x5b9b40] ; bits=4f4c4442, f32=49.074520111083984
004981f2  b908000000               mov       ecx, 8
004981f7  89d6                     mov       esi, edx
004981f9  89df                     mov       edi, ebx
004981fb  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
004981fd  0f8584000000             jne       0x498287
00498203  8b4558                   mov       eax, dword ptr [ebp + 0x58]
00498206  dbad7cffffff             fld       xword ptr [ebp - 0x84]
0049820c  d95814                   fstp      dword ptr [eax + 0x14]
0049820f  db6d88                   fld       xword ptr [ebp - 0x78]
00498212  d95818                   fstp      dword ptr [eax + 0x18]
00498215  c7401c00000000           mov       dword ptr [eax + 0x1c], 0
0049821c  8b4558                   mov       eax, dword ptr [ebp + 0x58]
0049821f  c7402000000000           mov       dword ptr [eax + 0x20], 0
00498226  8b4558                   mov       eax, dword ptr [ebp + 0x58]
00498229  c7402400000000           mov       dword ptr [eax + 0x24], 0
00498230  8b4558                   mov       eax, dword ptr [ebp + 0x58]
00498233  c7402800000000           mov       dword ptr [eax + 0x28], 0
0049823a  8b5558                   mov       edx, dword ptr [ebp + 0x58]
0049823d  c7422c00000000           mov       dword ptr [edx + 0x2c], 0
00498244  db6db8                   fld       xword ptr [ebp - 0x48]
00498247  d81de8995b00             fcomp     dword ptr [0x5b99e8] ; bits=00000000, f32=0.0
0049824d  dfe0                     fnstsw    ax
0049824f  9e                       sahf
00498250  0f8a23000000             jp        0x498279
00498256  7621                     jbe       0x498279
00498258  db6dc4                   fld       xword ptr [ebp - 0x3c]
0049825b  d80d30bcf400             fmul      dword ptr [0xf4bc30] ; _grvcom_
00498261  db6db8                   fld       xword ptr [ebp - 0x48]
00498264  def9                     fdivp     st(1)
00498266  d9fa                     fsqrt
00498268  d95dfc                   fstp      dword ptr [ebp - 4]
0049826b  db6dc4                   fld       xword ptr [ebp - 0x3c]
0049826e  d84dfc                   fmul      dword ptr [ebp - 4]
00498271  d95a30                   fstp      dword ptr [edx + 0x30]
00498274  e9ca030000               jmp       0x498643
00498279  89d0                     mov       eax, edx
0049827b  c7403000000000           mov       dword ptr [eax + 0x30], 0
00498282  e9bc030000               jmp       0x498643
00498287  dd05809c5b00             fld       qword ptr [0x5b9c80] ; bits=0000000000000000, f64=0.0
0049828d  dc15e0995b00             fcom      qword ptr [0x5b99e0] ; bits=0000000000000000, f64=0.0
00498293  dd9db0feffff             fstp      qword ptr [ebp - 0x150]
00498299  dfe0                     fnstsw    ax
0049829b  9e                       sahf
0049829c  0f8a20010000             jp        0x4983c2
004982a2  0f861a010000             jbe       0x4983c2
004982a8  db6dc4                   fld       xword ptr [ebp - 0x3c]
004982ab  dd9d98feffff             fstp      qword ptr [ebp - 0x168]
004982b1  dd05689c5b00             fld       qword ptr [0x5b9c68] ; bits=0000000000000000, f64=0.0
004982b7  dd9da0feffff             fstp      qword ptr [ebp - 0x160]
004982bd  dd8598feffff             fld       qword ptr [ebp - 0x168]
004982c3  dc0d689c5b00             fmul      qword ptr [0x5b9c68] ; bits=0000000000000000, f64=0.0
004982c9  dd85b0feffff             fld       qword ptr [ebp - 0x150]
004982cf  ddd8                     fstp      st(0)
004982d1  dd85b0feffff             fld       qword ptr [ebp - 0x150]
004982d7  dc8db0feffff             fmul      qword ptr [ebp - 0x150]
004982dd  dd9da8feffff             fstp      qword ptr [ebp - 0x158]
004982e3  dcb5a8feffff             fdiv      qword ptr [ebp - 0x158]
004982e9  d95dfc                   fstp      dword ptr [ebp - 4]
004982ec  8b45fc                   mov       eax, dword ptr [ebp - 4]
004982ef  8b4d58                   mov       ecx, dword ptr [ebp + 0x58]
004982f2  894114                   mov       dword ptr [ecx + 0x14], eax
004982f5  db6dc4                   fld       xword ptr [ebp - 0x3c]
004982f8  db6dc4                   fld       xword ptr [ebp - 0x3c]
004982fb  dec9                     fmulp     st(1)
004982fd  dbbdf8feffff             fstp      xword ptr [ebp - 0x108]
00498303  dbadf8feffff             fld       xword ptr [ebp - 0x108]
00498309  dd05609c5b00             fld       qword ptr [0x5b9c60] ; bits=0000000000000000, f64=0.0
0049830f  d9c1                     fld       st(1)
00498311  dc0d609c5b00             fmul      qword ptr [0x5b9c60] ; bits=0000000000000000, f64=0.0
00498317  dd85a8feffff             fld       qword ptr [ebp - 0x158]
0049831d  dc8db0feffff             fmul      qword ptr [ebp - 0x150]
00498323  dcf9                     fdiv      st(1), st(0)
00498325  d9c9                     fxch      st(1)
00498327  d95dfc                   fstp      dword ptr [ebp - 4]
0049832a  8b45fc                   mov       eax, dword ptr [ebp - 4]
0049832d  894118                   mov       dword ptr [ecx + 0x18], eax
00498330  db6db8                   fld       xword ptr [ebp - 0x48]
00498333  dc8da0feffff             fmul      qword ptr [ebp - 0x160]
00498339  dcb5a8feffff             fdiv      qword ptr [ebp - 0x158]
0049833f  db6dc4                   fld       xword ptr [ebp - 0x3c]
00498342  db6dc4                   fld       xword ptr [ebp - 0x3c]
00498345  dec1                     faddp     st(1)
00498347  d9c0                     fld       st(0)
00498349  dc8da0feffff             fmul      qword ptr [ebp - 0x160]
0049834f  dd05589c5b00             fld       qword ptr [0x5b9c58] ; bits=0000000000000000, f64=0.0
00498355  d9c9                     fxch      st(1)
00498357  dc0d589c5b00             fmul      qword ptr [0x5b9c58] ; bits=0000000000000000, f64=0.0
0049835d  d8f4                     fdiv      st(4)
0049835f  deeb                     fsubp     st(3)
00498361  dd8598feffff             fld       qword ptr [ebp - 0x168]
00498367  dc0d509c5b00             fmul      qword ptr [0x5b9c50] ; bits=0000000000000000, f64=0.0
0049836d  dcb5a8feffff             fdiv      qword ptr [ebp - 0x158]
00498373  dec3                     faddp     st(3)
00498375  d9ca                     fxch      st(2)
00498377  d95dfc                   fstp      dword ptr [ebp - 4]
0049837a  8b45fc                   mov       eax, dword ptr [ebp - 4]
0049837d  89411c                   mov       dword ptr [ecx + 0x1c], eax
00498380  db6db8                   fld       xword ptr [ebp - 0x48]
00498383  dec9                     fmulp     st(1)
00498385  d8cb                     fmul      st(3)
00498387  d8f2                     fdiv      st(2)
00498389  dbadf8feffff             fld       xword ptr [ebp - 0x108]
0049838f  d80d1c9a5b00             fmul      dword ptr [0x5b9a1c] ; bits=00004040, f32=3.0
00498395  decc                     fmulp     st(4)
00498397  d9cb                     fxch      st(3)
00498399  dec9                     fmulp     st(1)
0049839b  dd85a8feffff             fld       qword ptr [ebp - 0x158]
004983a1  dc8da8feffff             fmul      qword ptr [ebp - 0x158]
004983a7  def9                     fdivp     st(1)
004983a9  deea                     fsubp     st(2)
004983ab  d9ca                     fxch      st(2)
004983ad  dc0d489c5b00             fmul      qword ptr [0x5b9c48] ; bits=0000000000000000, f64=0.0
004983b3  def2                     fdivrp    st(2)
004983b5  dec1                     faddp     st(1)
004983b7  d95dfc                   fstp      dword ptr [ebp - 4]
004983ba  8b45fc                   mov       eax, dword ptr [ebp - 4]
004983bd  894120                   mov       dword ptr [ecx + 0x20], eax
004983c0  eb32                     jmp       0x4983f4
004983c2  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004983c5  c740140000803f           mov       dword ptr [eax + 0x14], 0x3f800000
004983cc  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004983cf  c740180000803f           mov       dword ptr [eax + 0x18], 0x3f800000
004983d6  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004983d9  c7401c00000000           mov       dword ptr [eax + 0x1c], 0
004983e0  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004983e3  c7402000000000           mov       dword ptr [eax + 0x20], 0
004983ea  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004983ed  c7403000000000           mov       dword ptr [eax + 0x30], 0
004983f4  d9ee                     fldz
004983f6  db6dc4                   fld       xword ptr [ebp - 0x3c]
004983f9  d81de8995b00             fcomp     dword ptr [0x5b99e8] ; bits=00000000, f32=0.0
004983ff  dbbd8cfeffff             fstp      xword ptr [ebp - 0x174]
00498405  dfe0                     fnstsw    ax
00498407  9e                       sahf
00498408  0f8ac7010000             jp        0x4985d5
0049840e  0f86c1010000             jbe       0x4985d5
00498414  8b5558                   mov       edx, dword ptr [ebp + 0x58]
00498417  db6db8                   fld       xword ptr [ebp - 0x48]
0049841a  d84a14                   fmul      dword ptr [edx + 0x14]
0049841d  db6dc4                   fld       xword ptr [ebp - 0x3c]
00498420  d84a1c                   fmul      dword ptr [edx + 0x1c]
00498423  dee9                     fsubp     st(1)
00498425  dbad8cfeffff             fld       xword ptr [ebp - 0x174]
0049842b  d9c9                     fxch      st(1)
0049842d  d8d1                     fcom      st(1)
0049842f  ddd9                     fstp      st(1)
00498431  dbbd80feffff             fstp      xword ptr [ebp - 0x180]
00498437  dfe0                     fnstsw    ax
00498439  9e                       sahf
0049843a  0f8a0b000000             jp        0x49844b
00498440  7709                     ja        0x49844b
00498442  c742243db416cb           mov       dword ptr [edx + 0x24], 0xcb16b43d
00498449  eb21                     jmp       0x49846c
0049844b  db6dc4                   fld       xword ptr [ebp - 0x3c]
0049844e  d80d30bcf400             fmul      dword ptr [0xf4bc30] ; _grvcom_
00498454  dbad80feffff             fld       xword ptr [ebp - 0x180]
0049845a  def9                     fdivp     st(1)
0049845c  d9fa                     fsqrt
0049845e  d95dfc                   fstp      dword ptr [ebp - 4]
00498461  db6dc4                   fld       xword ptr [ebp - 0x3c]
00498464  d84dfc                   fmul      dword ptr [ebp - 4]
00498467  89d0                     mov       eax, edx
00498469  d95824                   fstp      dword ptr [eax + 0x24]
0049846c  8b5558                   mov       edx, dword ptr [ebp + 0x58]
0049846f  db6db8                   fld       xword ptr [ebp - 0x48]
00498472  d84a18                   fmul      dword ptr [edx + 0x18]
00498475  d905209a5b00             fld       dword ptr [0x5b9a20] ; bits=0000003f, f32=0.5
0049847b  d84a20                   fmul      dword ptr [edx + 0x20]
0049847e  db6dc4                   fld       xword ptr [ebp - 0x3c]
00498481  dec9                     fmulp     st(1)
00498483  dee9                     fsubp     st(1)
00498485  d815e8995b00             fcom      dword ptr [0x5b99e8] ; bits=00000000, f32=0.0
0049848b  dbbd80feffff             fstp      xword ptr [ebp - 0x180]
00498491  dfe0                     fnstsw    ax
00498493  9e                       sahf
00498494  0f8a0b000000             jp        0x4984a5
0049849a  7709                     ja        0x4984a5
0049849c  c742283fb416cb           mov       dword ptr [edx + 0x28], 0xcb16b43f
004984a3  eb21                     jmp       0x4984c6
004984a5  db6dc4                   fld       xword ptr [ebp - 0x3c]
004984a8  d80d30bcf400             fmul      dword ptr [0xf4bc30] ; _grvcom_
004984ae  dbad80feffff             fld       xword ptr [ebp - 0x180]
004984b4  def9                     fdivp     st(1)
004984b6  d9fa                     fsqrt
004984b8  d95dfc                   fstp      dword ptr [ebp - 4]
004984bb  db6dc4                   fld       xword ptr [ebp - 0x3c]
004984be  d84dfc                   fmul      dword ptr [ebp - 4]
004984c1  89d0                     mov       eax, edx
004984c3  d95828                   fstp      dword ptr [eax + 0x28]
004984c6  db6db8                   fld       xword ptr [ebp - 0x48]
004984c9  d81de8995b00             fcomp     dword ptr [0x5b99e8] ; bits=00000000, f32=0.0
004984cf  dfe0                     fnstsw    ax
004984d1  9e                       sahf
004984d2  0f8a23000000             jp        0x4984fb
004984d8  7621                     jbe       0x4984fb
004984da  db6dc4                   fld       xword ptr [ebp - 0x3c]
004984dd  d80d30bcf400             fmul      dword ptr [0xf4bc30] ; _grvcom_
004984e3  db6db8                   fld       xword ptr [ebp - 0x48]
004984e6  def9                     fdivp     st(1)
004984e8  d9fa                     fsqrt
004984ea  d95dfc                   fstp      dword ptr [ebp - 4]
004984ed  db6dc4                   fld       xword ptr [ebp - 0x3c]
004984f0  d84dfc                   fmul      dword ptr [ebp - 4]
004984f3  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004984f6  d9582c                   fstp      dword ptr [eax + 0x2c]
004984f9  eb0a                     jmp       0x498505
004984fb  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004984fe  c7402c00000000           mov       dword ptr [eax + 0x2c], 0
00498505  8b5558                   mov       edx, dword ptr [ebp + 0x58]
00498508  d94224                   fld       dword ptr [edx + 0x24]
0049850b  d9ee                     fldz
0049850d  d9c9                     fxch      st(1)
0049850f  d815e8995b00             fcom      dword ptr [0x5b99e8] ; bits=00000000, f32=0.0
00498515  dbbd74feffff             fstp      xword ptr [ebp - 0x18c]
0049851b  dbbd68feffff             fstp      xword ptr [ebp - 0x198]
00498521  dfe0                     fnstsw    ax
00498523  9e                       sahf
00498524  0f8aa0000000             jp        0x4985ca
0049852a  0f829a000000             jb        0x4985ca
00498530  d94228                   fld       dword ptr [edx + 0x28]
00498533  dbad68feffff             fld       xword ptr [ebp - 0x198]
00498539  d9c9                     fxch      st(1)
0049853b  d8d1                     fcom      st(1)
0049853d  ddd9                     fstp      st(1)
0049853f  dbbd5cfeffff             fstp      xword ptr [ebp - 0x1a4]
00498545  dfe0                     fnstsw    ax
00498547  9e                       sahf
00498548  0f8a7c000000             jp        0x4985ca
0049854e  727a                     jb        0x4985ca
00498550  8b5528                   mov       edx, dword ptr [ebp + 0x28]
00498553  8d1a                     lea       ebx, [edx]
00498555  8d3d009b5b00             lea       edi, [0x5b9b00] ; bits=4e455742, f32=53.81768035888672
0049855b  b908000000               mov       ecx, 8
00498560  89de                     mov       esi, ebx
00498562  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00498564  7413                     je        0x498579
00498566  8d1a                     lea       ebx, [edx]
00498568  8d3d089b5b00             lea       edi, [0x5b9b08] ; bits=4e455742, f32=53.81768035888672
0049856e  b908000000               mov       ecx, 8
00498573  89de                     mov       esi, ebx
00498575  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00498577  750e                     jne       0x498587
00498579  8b4558                   mov       eax, dword ptr [ebp + 0x58]
0049857c  dbad74feffff             fld       xword ptr [ebp - 0x18c]
00498582  d95830                   fstp      dword ptr [eax + 0x30]
00498585  eb76                     jmp       0x4985fd
00498587  89d0                     mov       eax, edx
00498589  8d10                     lea       edx, [eax]
0049858b  8d1d109b5b00             lea       ebx, [0x5b9b10] ; bits=4e455742, f32=53.81768035888672
00498591  b908000000               mov       ecx, 8
00498596  89d6                     mov       esi, edx
00498598  89df                     mov       edi, ebx
0049859a  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0049859c  750e                     jne       0x4985ac
0049859e  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004985a1  dbad5cfeffff             fld       xword ptr [ebp - 0x1a4]
004985a7  d95830                   fstp      dword ptr [eax + 0x30]
004985aa  eb51                     jmp       0x4985fd
004985ac  dbad5cfeffff             fld       xword ptr [ebp - 0x1a4]
004985b2  dbad74feffff             fld       xword ptr [ebp - 0x18c]
004985b8  dec9                     fmulp     st(1)
004985ba  d9fa                     fsqrt
004985bc  d95dfc                   fstp      dword ptr [ebp - 4]
004985bf  8b45fc                   mov       eax, dword ptr [ebp - 4]
004985c2  8b4d58                   mov       ecx, dword ptr [ebp + 0x58]
004985c5  894130                   mov       dword ptr [ecx + 0x30], eax
004985c8  eb33                     jmp       0x4985fd
004985ca  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004985cd  8b482c                   mov       ecx, dword ptr [eax + 0x2c]
004985d0  894830                   mov       dword ptr [eax + 0x30], ecx
004985d3  eb28                     jmp       0x4985fd
004985d5  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004985d8  c7402400000000           mov       dword ptr [eax + 0x24], 0
004985df  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004985e2  c7402800000000           mov       dword ptr [eax + 0x28], 0
004985e9  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004985ec  c7402c00000000           mov       dword ptr [eax + 0x2c], 0
004985f3  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004985f6  c7403000000000           mov       dword ptr [eax + 0x30], 0
004985fd  8b5558                   mov       edx, dword ptr [ebp + 0x58]
00498600  d94214                   fld       dword ptr [edx + 0x14]
00498603  d9e8                     fld1
00498605  d9c9                     fxch      st(1)
00498607  d81d109a5b00             fcomp     dword ptr [0x5b9a10] ; bits=0000803f, f32=1.0
0049860d  dbbd50feffff             fstp      xword ptr [ebp - 0x1b0]
00498613  dfe0                     fnstsw    ax
00498615  9e                       sahf
00498616  0f8a02000000             jp        0x49861e
0049861c  7218                     jb        0x498636
0049861e  d94218                   fld       dword ptr [edx + 0x18]
00498621  dbad50feffff             fld       xword ptr [ebp - 0x1b0]
00498627  d9c9                     fxch      st(1)
00498629  ded9                     fcompp
0049862b  dfe0                     fnstsw    ax
0049862d  9e                       sahf
0049862e  0f8a0f000000             jp        0x498643
00498634  730d                     jae       0x498643
00498636  68489b5b00               push      0x5b9b48
0049863b  e840a80000               call      0x4a2e80 ; _jwe_ilst
00498640  83c404                   add       esp, 4
00498643  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
00498646  8b10                     mov       edx, dword ptr [eax]
00498648  83fa01                   cmp       edx, 1
0049864b  7557                     jne       0x4986a4
0049864d  d9ee                     fldz
0049864f  db6dc4                   fld       xword ptr [ebp - 0x3c]
00498652  dae9                     fucompp
00498654  dfe0                     fnstsw    ax
00498656  9e                       sahf
00498657  0f8a1b000000             jp        0x498678
0049865d  7519                     jne       0x498678
0049865f  8b4558                   mov       eax, dword ptr [ebp + 0x58]
00498662  c740340000803f           mov       dword ptr [eax + 0x34], 0x3f800000
00498669  8b4558                   mov       eax, dword ptr [ebp + 0x58]
0049866c  c740380000803f           mov       dword ptr [eax + 0x38], 0x3f800000
00498673  e996000000               jmp       0x49870e
00498678  db6dc4                   fld       xword ptr [ebp - 0x3c]
0049867b  dc3d709c5b00             fdivr     qword ptr [0x5b9c70] ; bits=0000000000000000, f64=0.0
00498681  d95dfc                   fstp      dword ptr [ebp - 4]
00498684  8b45fc                   mov       eax, dword ptr [ebp - 4]
00498687  8b4d58                   mov       ecx, dword ptr [ebp + 0x58]
0049868a  894134                   mov       dword ptr [ecx + 0x34], eax
0049868d  dd05809c5b00             fld       qword ptr [0x5b9c80] ; bits=0000000000000000, f64=0.0
00498693  dc3d789c5b00             fdivr     qword ptr [0x5b9c78] ; bits=0000000000000000, f64=0.0
00498699  d95dfc                   fstp      dword ptr [ebp - 4]
0049869c  8b45fc                   mov       eax, dword ptr [ebp - 4]
0049869f  894138                   mov       dword ptr [ecx + 0x38], eax
004986a2  eb6a                     jmp       0x49870e
004986a4  83fa02                   cmp       edx, 2
004986a7  7551                     jne       0x4986fa
004986a9  d9ee                     fldz
004986ab  db6dc4                   fld       xword ptr [ebp - 0x3c]
004986ae  dae9                     fucompp
004986b0  dfe0                     fnstsw    ax
004986b2  9e                       sahf
004986b3  0f8a18000000             jp        0x4986d1
004986b9  7516                     jne       0x4986d1
004986bb  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004986be  c740340000803f           mov       dword ptr [eax + 0x34], 0x3f800000
004986c5  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004986c8  c740380000803f           mov       dword ptr [eax + 0x38], 0x3f800000
004986cf  eb3d                     jmp       0x49870e
004986d1  db6dc4                   fld       xword ptr [ebp - 0x3c]
004986d4  dc3d709c5b00             fdivr     qword ptr [0x5b9c70] ; bits=0000000000000000, f64=0.0
004986da  d95dfc                   fstp      dword ptr [ebp - 4]
004986dd  8b45fc                   mov       eax, dword ptr [ebp - 4]
004986e0  8b4d58                   mov       ecx, dword ptr [ebp + 0x58]
004986e3  894134                   mov       dword ptr [ecx + 0x34], eax
004986e6  db6d94                   fld       xword ptr [ebp - 0x6c]
004986e9  dc3d789c5b00             fdivr     qword ptr [0x5b9c78] ; bits=0000000000000000, f64=0.0
004986ef  d95dfc                   fstp      dword ptr [ebp - 4]
004986f2  8b45fc                   mov       eax, dword ptr [ebp - 4]
004986f5  894138                   mov       dword ptr [ecx + 0x38], eax
004986f8  eb14                     jmp       0x49870e
004986fa  8b4558                   mov       eax, dword ptr [ebp + 0x58]
004986fd  c740340000803f           mov       dword ptr [eax + 0x34], 0x3f800000
00498704  8b4558                   mov       eax, dword ptr [ebp + 0x58]
00498707  c740380000803f           mov       dword ptr [eax + 0x38], 0x3f800000
0049870e  b800000000               mov       eax, 0
00498713  5f                       pop       edi
00498714  5e                       pop       esi
00498715  5b                       pop       ebx
00498716  8be5                     mov       esp, ebp
00498718  5d                       pop       ebp
00498719  c3                       ret
0049871a  8d9b00000000             lea       ebx, [ebx]
