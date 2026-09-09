; _interp_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x42940
00442940  55                       push      ebp
00442941  8bec                     mov       ebp, esp
00442943  b894020000               mov       eax, 0x294
00442948  e8b3660a00               call      0x4e9000 ; __alloca_probe
0044294d  53                       push      ebx
0044294e  56                       push      esi
0044294f  57                       push      edi
00442950  8b4508                   mov       eax, dword ptr [ebp + 8]
00442953  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00442956  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00442959  8985e0fdffff             mov       dword ptr [ebp - 0x220], eax
0044295f  898ddcfdffff             mov       dword ptr [ebp - 0x224], ecx
00442965  8995d8fdffff             mov       dword ptr [ebp - 0x228], edx
0044296b  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
00442971  8b08                     mov       ecx, dword ptr [eax]
00442973  8b148dc8e5f400           mov       edx, dword ptr [ecx*4 + 0xf4e5c8]
0044297a  83fa1e                   cmp       edx, 0x1e
0044297d  8995d4fdffff             mov       dword ptr [ebp - 0x22c], edx
00442983  7c16                     jl        0x44299b
00442985  83bdd4fdffff23           cmp       dword ptr [ebp - 0x22c], 0x23
0044298c  7f0d                     jg        0x44299b
0044298e  b80a000000               mov       eax, 0xa
00442993  8985d0fdffff             mov       dword ptr [ebp - 0x230], eax
00442999  eb0b                     jmp       0x4429a6
0044299b  b800000000               mov       eax, 0
004429a0  8985d0fdffff             mov       dword ptr [ebp - 0x230], eax
004429a6  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
004429ac  8b08                     mov       ecx, dword ptr [eax]
004429ae  8b148dc8e5f400           mov       edx, dword ptr [ecx*4 + 0xf4e5c8]
004429b5  83fa1e                   cmp       edx, 0x1e
004429b8  8995ccfdffff             mov       dword ptr [ebp - 0x234], edx
004429be  7c16                     jl        0x4429d6
004429c0  83bdccfdffff23           cmp       dword ptr [ebp - 0x234], 0x23
004429c7  7f0d                     jg        0x4429d6
004429c9  b80a000000               mov       eax, 0xa
004429ce  8985c8fdffff             mov       dword ptr [ebp - 0x238], eax
004429d4  eb0b                     jmp       0x4429e1
004429d6  b800000000               mov       eax, 0
004429db  8985c8fdffff             mov       dword ptr [ebp - 0x238], eax
004429e1  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
004429e7  8d08                     lea       ecx, [eax]
004429e9  51                       push      ecx
004429ea  e831ffffff               call      0x442920 ; _get_slot_depth_
004429ef  db7db0                   fstp      xword ptr [ebp - 0x50]
004429f2  83c404                   add       esp, 4
004429f5  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
004429fb  8d08                     lea       ecx, [eax]
004429fd  51                       push      ecx
004429fe  e81dffffff               call      0x442920 ; _get_slot_depth_
00442a03  db7da4                   fstp      xword ptr [ebp - 0x5c]
00442a06  83c404                   add       esp, 4
00442a09  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
00442a0f  8b08                     mov       ecx, dword ptr [eax]
00442a11  83c108                   add       ecx, 8
00442a14  894dfc                   mov       dword ptr [ebp - 4], ecx
00442a17  8d4dfc                   lea       ecx, [ebp - 4]
00442a1a  51                       push      ecx
00442a1b  e810c3ffff               call      0x43ed30 ; _get_dp_from_ft_
00442a20  dd5d98                   fstp      qword ptr [ebp - 0x68]
00442a23  83c404                   add       esp, 4
00442a26  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
00442a2c  8b08                     mov       ecx, dword ptr [eax]
00442a2e  83c10a                   add       ecx, 0xa
00442a31  894dfc                   mov       dword ptr [ebp - 4], ecx
00442a34  8d4dfc                   lea       ecx, [ebp - 4]
00442a37  51                       push      ecx
00442a38  e8f3c2ffff               call      0x43ed30 ; _get_dp_from_ft_
00442a3d  dd5d90                   fstp      qword ptr [ebp - 0x70]
00442a40  83c404                   add       esp, 4
00442a43  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
00442a49  8b08                     mov       ecx, dword ptr [eax]
00442a4b  83c108                   add       ecx, 8
00442a4e  894dfc                   mov       dword ptr [ebp - 4], ecx
00442a51  8d4dfc                   lea       ecx, [ebp - 4]
00442a54  51                       push      ecx
00442a55  e8d6c2ffff               call      0x43ed30 ; _get_dp_from_ft_
00442a5a  dd5d88                   fstp      qword ptr [ebp - 0x78]
00442a5d  83c404                   add       esp, 4
00442a60  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
00442a66  8b08                     mov       ecx, dword ptr [eax]
00442a68  83c10a                   add       ecx, 0xa
00442a6b  894dfc                   mov       dword ptr [ebp - 4], ecx
00442a6e  8d4dfc                   lea       ecx, [ebp - 4]
00442a71  51                       push      ecx
00442a72  e8b9c2ffff               call      0x43ed30 ; _get_dp_from_ft_
00442a77  dd5d80                   fstp      qword ptr [ebp - 0x80]
00442a7a  83c404                   add       esp, 4
00442a7d  8b85d4fdffff             mov       eax, dword ptr [ebp - 0x22c]
00442a83  2b85d0fdffff             sub       eax, dword ptr [ebp - 0x230]
00442a89  3d14000000               cmp       eax, 0x14
00442a8e  8985c4fdffff             mov       dword ptr [ebp - 0x23c], eax
00442a94  7c09                     jl        0x442a9f
00442a96  83bdc4fdffff19           cmp       dword ptr [ebp - 0x23c], 0x19
00442a9d  7e3c                     jle       0x442adb
00442a9f  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
00442aa5  8b08                     mov       ecx, dword ptr [eax]
00442aa7  8d0500c85700             lea       eax, [0x57c800] ; bits=09020000, f32=7.300764999132297e-43
00442aad  894dfc                   mov       dword ptr [ebp - 4], ecx
00442ab0  8d4dfc                   lea       ecx, [ebp - 4]
00442ab3  894808                   mov       dword ptr [eax + 8], ecx
00442ab6  8b8dd4fdffff             mov       ecx, dword ptr [ebp - 0x22c]
00442abc  894df8                   mov       dword ptr [ebp - 8], ecx
00442abf  8d4df8                   lea       ecx, [ebp - 8]
00442ac2  894828                   mov       dword ptr [eax + 0x28], ecx
00442ac5  50                       push      eax
00442ac6  e825fb0500               call      0x4a25f0 ; _jwe_isfm
00442acb  83c404                   add       esp, 4
00442ace  686cc75700               push      0x57c76c
00442ad3  e868090600               call      0x4a3440 ; _jwe_xstp
00442ad8  83c404                   add       esp, 4
00442adb  8b85ccfdffff             mov       eax, dword ptr [ebp - 0x234]
00442ae1  2b85c8fdffff             sub       eax, dword ptr [ebp - 0x238]
00442ae7  3d14000000               cmp       eax, 0x14
00442aec  8985c0fdffff             mov       dword ptr [ebp - 0x240], eax
00442af2  7c09                     jl        0x442afd
00442af4  83bdc0fdffff19           cmp       dword ptr [ebp - 0x240], 0x19
00442afb  7e3c                     jle       0x442b39
00442afd  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
00442b03  8b08                     mov       ecx, dword ptr [eax]
00442b05  8d05d4c75700             lea       eax, [0x57c7d4] ; bits=09020000, f32=7.300764999132297e-43
00442b0b  894dfc                   mov       dword ptr [ebp - 4], ecx
00442b0e  8d4dfc                   lea       ecx, [ebp - 4]
00442b11  894808                   mov       dword ptr [eax + 8], ecx
00442b14  8b8dccfdffff             mov       ecx, dword ptr [ebp - 0x234]
00442b1a  894df8                   mov       dword ptr [ebp - 8], ecx
00442b1d  8d4df8                   lea       ecx, [ebp - 8]
00442b20  894828                   mov       dword ptr [eax + 0x28], ecx
00442b23  50                       push      eax
00442b24  e8c7fa0500               call      0x4a25f0 ; _jwe_isfm
00442b29  83c404                   add       esp, 4
00442b2c  6860c75700               push      0x57c760
00442b31  e80a090600               call      0x4a3440 ; _jwe_xstp
00442b36  83c404                   add       esp, 4
00442b39  8b85d4fdffff             mov       eax, dword ptr [ebp - 0x22c]
00442b3f  83e813                   sub       eax, 0x13
00442b42  8b8dd0fdffff             mov       ecx, dword ptr [ebp - 0x230]
00442b48  29c8                     sub       eax, ecx
00442b4a  8b95ccfdffff             mov       edx, dword ptr [ebp - 0x234]
00442b50  83ea13                   sub       edx, 0x13
00442b53  2b95c8fdffff             sub       edx, dword ptr [ebp - 0x238]
00442b59  8d1c52                   lea       ebx, [edx + edx*2]
00442b5c  89da                     mov       edx, ebx
00442b5e  01da                     add       edx, ebx
00442b60  01c2                     add       edx, eax
00442b62  8b049598c95700           mov       eax, dword ptr [edx*4 + 0x57c998]
00442b69  83f900                   cmp       ecx, 0
00442b6c  8985bcfdffff             mov       dword ptr [ebp - 0x244], eax
00442b72  7e32                     jle       0x442ba6
00442b74  83bdc8fdffff00           cmp       dword ptr [ebp - 0x238], 0
00442b7b  7e29                     jle       0x442ba6
00442b7d  b80a000000               mov       eax, 0xa
00442b82  8b8dbcfdffff             mov       ecx, dword ptr [ebp - 0x244]
00442b88  83c10a                   add       ecx, 0xa
00442b8b  8b148d445b5700           mov       edx, dword ptr [ecx*4 + 0x575b44]
00442b92  8985b8fdffff             mov       dword ptr [ebp - 0x248], eax
00442b98  898dbcfdffff             mov       dword ptr [ebp - 0x244], ecx
00442b9e  8995b4fdffff             mov       dword ptr [ebp - 0x24c], edx
00442ba4  eb1e                     jmp       0x442bc4
00442ba6  b800000000               mov       eax, 0
00442bab  8b8dbcfdffff             mov       ecx, dword ptr [ebp - 0x244]
00442bb1  8b148d445b5700           mov       edx, dword ptr [ecx*4 + 0x575b44]
00442bb8  8985b8fdffff             mov       dword ptr [ebp - 0x248], eax
00442bbe  8995b4fdffff             mov       dword ptr [ebp - 0x24c], edx
00442bc4  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
00442bca  8b08                     mov       ecx, dword ptr [eax]
00442bcc  8b95d8fdffff             mov       edx, dword ptr [ebp - 0x228]
00442bd2  d9048dd8e5f400           fld       dword ptr [ecx*4 + 0xf4e5d8]
00442bd9  8b1a                     mov       ebx, dword ptr [edx]
00442bdb  d9049dd8e5f400           fld       dword ptr [ebx*4 + 0xf4e5d8]
00442be2  d8148dd8e5f400           fcom      dword ptr [ecx*4 + 0xf4e5d8]
00442be9  dbbd74ffffff             fstp      xword ptr [ebp - 0x8c]
00442bef  dfe0                     fnstsw    ax
00442bf1  66a90041                 test      ax, 0x4100
00442bf5  7508                     jne       0x442bff
00442bf7  dbbd74ffffff             fstp      xword ptr [ebp - 0x8c]
00442bfd  eb02                     jmp       0x442c01
00442bff  ddd8                     fstp      st(0)
00442c01  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00442c04  8b08                     mov       ecx, dword ptr [eax]
00442c06  0faf8db4fdffff           imul      ecx, dword ptr [ebp - 0x24c]
00442c0d  83c120                   add       ecx, 0x20
00442c10  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00442c13  8b10                     mov       edx, dword ptr [eax]
00442c15  0fafd1                   imul      edx, ecx
00442c18  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
00442c1b  8b08                     mov       ecx, dword ptr [eax]
00442c1d  01d1                     add       ecx, edx
00442c1f  8b5528                   mov       edx, dword ptr [ebp + 0x28]
00442c22  8b12                     mov       edx, dword ptr [edx]
00442c24  39d1                     cmp       ecx, edx
00442c26  8985b0fdffff             mov       dword ptr [ebp - 0x250], eax
00442c2c  7c1c                     jl        0x442c4a
00442c2e  8b4548                   mov       eax, dword ptr [ebp + 0x48]
00442c31  8d00                     lea       eax, [eax]
00442c33  50                       push      eax
00442c34  8b85b0fdffff             mov       eax, dword ptr [ebp - 0x250]
00442c3a  8d08                     lea       ecx, [eax]
00442c3c  51                       push      ecx
00442c3d  688cc65700               push      0x57c68c
00442c42  e8e9120000               call      0x443f30 ; _kil_
00442c47  83c40c                   add       esp, 0xc
00442c4a  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00442c4d  8b08                     mov       ecx, dword ptr [eax]
00442c4f  0faf8db4fdffff           imul      ecx, dword ptr [ebp - 0x24c]
00442c56  83c120                   add       ecx, 0x20
00442c59  898dacfdffff             mov       dword ptr [ebp - 0x254], ecx
00442c5f  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00442c62  8b08                     mov       ecx, dword ptr [eax]
00442c64  89c8                     mov       eax, ecx
00442c66  3d00000000               cmp       eax, 0
00442c6b  8985a8fdffff             mov       dword ptr [ebp - 0x258], eax
00442c71  898da4fdffff             mov       dword ptr [ebp - 0x25c], ecx
00442c77  0f8e9f000000             jle       0x442d1c
00442c7d  b801000000               mov       eax, 1
00442c82  8b4d4c                   mov       ecx, dword ptr [ebp + 0x4c]
00442c85  8b11                     mov       edx, dword ptr [ecx]
00442c87  83bda8fdffff02           cmp       dword ptr [ebp - 0x258], 2
00442c8e  8985a0fdffff             mov       dword ptr [ebp - 0x260], eax
00442c94  89959cfdffff             mov       dword ptr [ebp - 0x264], edx
00442c9a  7c4c                     jl        0x442ce8
00442c9c  8d0540a17500             lea       eax, [0x75a140]
00442ca2  8b95a0fdffff             mov       edx, dword ptr [ebp - 0x260]
00442ca8  8b8d9cfdffff             mov       ecx, dword ptr [ebp - 0x264]
00442cae  898c907cffffff           mov       dword ptr [eax + edx*4 - 0x84], ecx
00442cb5  8b9dacfdffff             mov       ebx, dword ptr [ebp - 0x254]
00442cbb  01d9                     add       ecx, ebx
00442cbd  894c9080                 mov       dword ptr [eax + edx*4 - 0x80], ecx
00442cc1  01d9                     add       ecx, ebx
00442cc3  8b85a8fdffff             mov       eax, dword ptr [ebp - 0x258]
00442cc9  83e802                   sub       eax, 2
00442ccc  83c202                   add       edx, 2
00442ccf  3d02000000               cmp       eax, 2
00442cd4  8985a8fdffff             mov       dword ptr [ebp - 0x258], eax
00442cda  898d9cfdffff             mov       dword ptr [ebp - 0x264], ecx
00442ce0  8995a0fdffff             mov       dword ptr [ebp - 0x260], edx
00442ce6  7db4                     jge       0x442c9c
00442ce8  8b85a8fdffff             mov       eax, dword ptr [ebp - 0x258]
00442cee  85c0                     test      eax, eax
00442cf0  741f                     je        0x442d11
00442cf2  8b8da0fdffff             mov       ecx, dword ptr [ebp - 0x260]
00442cf8  8b859cfdffff             mov       eax, dword ptr [ebp - 0x264]
00442cfe  89048dbca07500           mov       dword ptr [ecx*4 + 0x75a0bc], eax
00442d05  0385acfdffff             add       eax, dword ptr [ebp - 0x254]
00442d0b  89859cfdffff             mov       dword ptr [ebp - 0x264], eax
00442d11  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
00442d14  8b8d9cfdffff             mov       ecx, dword ptr [ebp - 0x264]
00442d1a  8908                     mov       dword ptr [eax], ecx
00442d1c  8b85a4fdffff             mov       eax, dword ptr [ebp - 0x25c]
00442d22  898598fdffff             mov       dword ptr [ebp - 0x268], eax
00442d28  3d00000000               cmp       eax, 0
00442d2d  0f8e5a010000             jle       0x442e8d
00442d33  b801000000               mov       eax, 1
00442d38  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
00442d3b  d901                     fld       dword ptr [ecx]
00442d3d  8985a0fdffff             mov       dword ptr [ebp - 0x260], eax
00442d43  8b8da0fdffff             mov       ecx, dword ptr [ebp - 0x260]
00442d49  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
00442d4c  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
00442d50  d9c9                     fxch      st(1)
00442d52  d85488fc                 fcom      dword ptr [eax + ecx*4 - 4]
00442d56  dfe0                     fnstsw    ax
00442d58  9e                       sahf
00442d59  0f8a1a000000             jp        0x442d79
00442d5f  7318                     jae       0x442d79
00442d61  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00442d64  d9c9                     fxch      st(1)
00442d66  d810                     fcom      dword ptr [eax]
00442d68  d9c9                     fxch      st(1)
00442d6a  dfe0                     fnstsw    ax
00442d6c  9e                       sahf
00442d6d  0f8a06000000             jp        0x442d79
00442d73  0f82f7000000             jb        0x442e70
00442d79  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00442d7c  d900                     fld       dword ptr [eax]
00442d7e  d8d2                     fcom      st(2)
00442d80  dfe0                     fnstsw    ax
00442d82  9e                       sahf
00442d83  0f8a17000000             jp        0x442da0
00442d89  7315                     jae       0x442da0
00442d8b  d9ca                     fxch      st(2)
00442d8d  d8d1                     fcom      st(1)
00442d8f  d9ca                     fxch      st(2)
00442d91  dfe0                     fnstsw    ax
00442d93  9e                       sahf
00442d94  0f8a06000000             jp        0x442da0
00442d9a  0f82d4000000             jb        0x442e74
00442da0  d9c9                     fxch      st(1)
00442da2  db7de0                   fstp      xword ptr [ebp - 0x20]
00442da5  8b4548                   mov       eax, dword ptr [ebp + 0x48]
00442da8  c70001000000             mov       dword ptr [eax], 1
00442dae  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
00442db4  8b18                     mov       ebx, dword ptr [eax]
00442db6  8b4d3c                   mov       ecx, dword ptr [ebp + 0x3c]
00442db9  d901                     fld       dword ptr [ecx]
00442dbb  db6de0                   fld       xword ptr [ebp - 0x20]
00442dbe  d831                     fdiv      dword ptr [ecx]
00442dc0  dbbd68ffffff             fstp      xword ptr [ebp - 0x98]
00442dc6  dcfa                     fdiv      st(2), st(0)
00442dc8  d9ca                     fxch      st(2)
00442dca  dbbd5cffffff             fstp      xword ptr [ebp - 0xa4]
00442dd0  def1                     fdivrp    st(1)
00442dd2  8b8ddcfdffff             mov       ecx, dword ptr [ebp - 0x224]
00442dd8  dbbd50ffffff             fstp      xword ptr [ebp - 0xb0]
00442dde  8d11                     lea       edx, [ecx]
00442de0  52                       push      edx
00442de1  e81afbffff               call      0x442900 ; _gettbn_
00442de6  83c404                   add       esp, 4
00442de9  8945fc                   mov       dword ptr [ebp - 4], eax
00442dec  8d45fc                   lea       eax, [ebp - 4]
00442def  50                       push      eax
00442df0  6a10                     push      0x10
00442df2  6820c95700               push      0x57c920
00442df7  e894450300               call      0x477390 ; _get_tabid_
00442dfc  83c40c                   add       esp, 0xc
00442dff  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
00442e05  8d08                     lea       ecx, [eax]
00442e07  51                       push      ecx
00442e08  e8f3faffff               call      0x442900 ; _gettbn_
00442e0d  83c404                   add       esp, 4
00442e10  8945fc                   mov       dword ptr [ebp - 4], eax
00442e13  8d45fc                   lea       eax, [ebp - 4]
00442e16  50                       push      eax
00442e17  6a10                     push      0x10
00442e19  6830c95700               push      0x57c930
00442e1e  e86d450300               call      0x477390 ; _get_tabid_
00442e23  83c40c                   add       esp, 0xc
00442e26  8d0578c75700             lea       eax, [0x57c778] ; bits=09020000, f32=7.300764999132297e-43
00442e2c  895dfc                   mov       dword ptr [ebp - 4], ebx
00442e2f  8d4dfc                   lea       ecx, [ebp - 4]
00442e32  894808                   mov       dword ptr [eax + 8], ecx
00442e35  dbad68ffffff             fld       xword ptr [ebp - 0x98]
00442e3b  d95df4                   fstp      dword ptr [ebp - 0xc]
00442e3e  8d4df4                   lea       ecx, [ebp - 0xc]
00442e41  894828                   mov       dword ptr [eax + 0x28], ecx
00442e44  dbad5cffffff             fld       xword ptr [ebp - 0xa4]
00442e4a  d95df0                   fstp      dword ptr [ebp - 0x10]
00442e4d  8d4df0                   lea       ecx, [ebp - 0x10]
00442e50  894834                   mov       dword ptr [eax + 0x34], ecx
00442e53  dbad50ffffff             fld       xword ptr [ebp - 0xb0]
00442e59  d95dec                   fstp      dword ptr [ebp - 0x14]
00442e5c  8d4dec                   lea       ecx, [ebp - 0x14]
00442e5f  894840                   mov       dword ptr [eax + 0x40], ecx
00442e62  50                       push      eax
00442e63  e888f70500               call      0x4a25f0 ; _jwe_isfm
00442e68  db6de0                   fld       xword ptr [ebp - 0x20]
00442e6b  83c404                   add       esp, 4
00442e6e  eb08                     jmp       0x442e78
00442e70  ddd9                     fstp      st(1)
00442e72  eb04                     jmp       0x442e78
00442e74  ddd8                     fstp      st(0)
00442e76  ddd9                     fstp      st(1)
00442e78  ff85a0fdffff             inc       dword ptr [ebp - 0x260]
00442e7e  83ad98fdffff01           sub       dword ptr [ebp - 0x268], 1
00442e85  0f85b8feffff             jne       0x442d43
00442e8b  ddd8                     fstp      st(0)
00442e8d  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00442e90  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
00442e93  d901                     fld       dword ptr [ecx]
00442e95  d9c0                     fld       st(0)
00442e97  d828                     fsubr     dword ptr [eax]
00442e99  dbbd44ffffff             fstp      xword ptr [ebp - 0xbc]
00442e9f  dbbd38ffffff             fstp      xword ptr [ebp - 0xc8]
00442ea5  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00442ea8  8b08                     mov       ecx, dword ptr [eax]
00442eaa  83f900                   cmp       ecx, 0
00442ead  898d94fdffff             mov       dword ptr [ebp - 0x26c], ecx
00442eb3  0f8e88030000             jle       0x443241
00442eb9  be01000000               mov       esi, 1
00442ebe  8b85acfdffff             mov       eax, dword ptr [ebp - 0x254]
00442ec4  2b85b4fdffff             sub       eax, dword ptr [ebp - 0x24c]
00442eca  898590fdffff             mov       dword ptr [ebp - 0x270], eax
00442ed0  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
00442ed3  d9e8                     fld1
00442ed5  d9c0                     fld       st(0)
00442ed7  d830                     fdiv      dword ptr [eax]
00442ed9  dbbd2cffffff             fstp      xword ptr [ebp - 0xd4]
00442edf  dbad38ffffff             fld       xword ptr [ebp - 0xc8]
00442ee5  dbbd20ffffff             fstp      xword ptr [ebp - 0xe0]
00442eeb  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00442ef1  def9                     fdivp     st(1)
00442ef3  dbbd14ffffff             fstp      xword ptr [ebp - 0xec]
00442ef9  db6da4                   fld       xword ptr [ebp - 0x5c]
00442efc  db6db0                   fld       xword ptr [ebp - 0x50]
00442eff  dee9                     fsubp     st(1)
00442f01  dbbd08ffffff             fstp      xword ptr [ebp - 0xf8]
00442f07  dd4598                   fld       qword ptr [ebp - 0x68]
00442f0a  dc6d88                   fsubr     qword ptr [ebp - 0x78]
00442f0d  dd9d00ffffff             fstp      qword ptr [ebp - 0x100]
00442f13  dd4590                   fld       qword ptr [ebp - 0x70]
00442f16  dc6d80                   fsubr     qword ptr [ebp - 0x80]
00442f19  dd9df8feffff             fstp      qword ptr [ebp - 0x108]
00442f1f  dbad74ffffff             fld       xword ptr [ebp - 0x8c]
00442f25  db6db0                   fld       xword ptr [ebp - 0x50]
00442f28  dd4598                   fld       qword ptr [ebp - 0x68]
00442f2b  dd4590                   fld       qword ptr [ebp - 0x70]
00442f2e  db7dbc                   fstp      xword ptr [ebp - 0x44]
00442f31  db7dc8                   fstp      xword ptr [ebp - 0x38]
00442f34  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00442f37  db7de0                   fstp      xword ptr [ebp - 0x20]
00442f3a  8b1cb5bca07500           mov       ebx, dword ptr [esi*4 + 0x75a0bc]
00442f41  8b8590fdffff             mov       eax, dword ptr [ebp - 0x270]
00442f47  8d0c18                   lea       ecx, [eax + ebx]
00442f4a  890c9dc0e5f400           mov       dword ptr [ebx*4 + 0xf4e5c0], ecx
00442f51  8b7d34                   mov       edi, dword ptr [ebp + 0x34]
00442f54  8b4cb7fc                 mov       ecx, dword ptr [edi + esi*4 - 4]
00442f58  890c9dc4e5f400           mov       dword ptr [ebx*4 + 0xf4e5c4], ecx
00442f5f  8b8dbcfdffff             mov       ecx, dword ptr [ebp - 0x244]
00442f65  890c9dc8e5f400           mov       dword ptr [ebx*4 + 0xf4e5c8], ecx
00442f6c  8d5320                   lea       edx, [ebx + 0x20]
00442f6f  899588fdffff             mov       dword ptr [ebp - 0x278], edx
00442f75  89149dcce5f400           mov       dword ptr [ebx*4 + 0xf4e5cc], edx
00442f7c  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
00442f7f  dbad2cffffff             fld       xword ptr [ebp - 0xd4]
00442f85  d84cb0fc                 fmul      dword ptr [eax + esi*4 - 4]
00442f89  d91c9dd0e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d0]
00442f90  89bd8cfdffff             mov       dword ptr [ebp - 0x274], edi
00442f96  8b7d30                   mov       edi, dword ptr [ebp + 0x30]
00442f99  8b7cb7fc                 mov       edi, dword ptr [edi + esi*4 - 4]
00442f9d  893c9dd4e5f400           mov       dword ptr [ebx*4 + 0xf4e5d4], edi
00442fa4  db6de0                   fld       xword ptr [ebp - 0x20]
00442fa7  d91c9dd8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d8]
00442fae  dbad20ffffff             fld       xword ptr [ebp - 0xe0]
00442fb4  d86cb0fc                 fsubr     dword ptr [eax + esi*4 - 4]
00442fb8  dbad14ffffff             fld       xword ptr [ebp - 0xec]
00442fbe  dec9                     fmulp     st(1)
00442fc0  dbad08ffffff             fld       xword ptr [ebp - 0xf8]
00442fc6  d8c9                     fmul      st(1)
00442fc8  db6dd4                   fld       xword ptr [ebp - 0x2c]
00442fcb  dec1                     faddp     st(1)
00442fcd  d91c9ddce5f400           fstp      dword ptr [ebx*4 + 0xf4e5dc]
00442fd4  d9c0                     fld       st(0)
00442fd6  dc8d00ffffff             fmul      qword ptr [ebp - 0x100]
00442fdc  db6dc8                   fld       xword ptr [ebp - 0x38]
00442fdf  dec1                     faddp     st(1)
00442fe1  dd1d30c85700             fstp      qword ptr [0x57c830] ; bits=0000000000000000, f64=0.0
00442fe7  dc8df8feffff             fmul      qword ptr [ebp - 0x108]
00442fed  db6dbc                   fld       xword ptr [ebp - 0x44]
00442ff0  dec1                     faddp     st(1)
00442ff2  dd1d38c85700             fstp      qword ptr [0x57c838] ; bits=0000000000000000, f64=0.0
00442ff8  8d4308                   lea       eax, [ebx + 8]
00442ffb  8945fc                   mov       dword ptr [ebp - 4], eax
00442ffe  6830c85700               push      0x57c830
00443003  8d45fc                   lea       eax, [ebp - 4]
00443006  50                       push      eax
00443007  e8e4bcffff               call      0x43ecf0 ; _put_dp_in_ft_
0044300c  83c408                   add       esp, 8
0044300f  8d430a                   lea       eax, [ebx + 0xa]
00443012  8945fc                   mov       dword ptr [ebp - 4], eax
00443015  6838c85700               push      0x57c838
0044301a  8d45fc                   lea       eax, [ebp - 4]
0044301d  50                       push      eax
0044301e  e8cdbcffff               call      0x43ecf0 ; _put_dp_in_ft_
00443023  83c408                   add       esp, 8
00443026  8d430c                   lea       eax, [ebx + 0xc]
00443029  8945fc                   mov       dword ptr [ebp - 4], eax
0044302c  6a10                     push      0x10
0044302e  6850c75700               push      0x57c750
00443033  8d45fc                   lea       eax, [ebp - 4]
00443036  50                       push      eax
00443037  e874b9ffff               call      0x43e9b0 ; _put_string_in_ft_
0044303c  83c40c                   add       esp, 0xc
0044303f  8bbd8cfdffff             mov       edi, dword ptr [ebp - 0x274]
00443045  8d7cb7fc                 lea       edi, [edi + esi*4 - 4]
00443049  57                       push      edi
0044304a  6a10                     push      0x10
0044304c  6840c95700               push      0x57c940
00443051  e83a430300               call      0x477390 ; _get_tabid_
00443056  83c40c                   add       esp, 0xc
00443059  8d0510c95700             lea       eax, [0x57c910] ; bits=00000000, f32=0.0
0044305f  8d0d40c95700             lea       ecx, [0x57c940] ; bits=00000000, f32=0.0
00443065  8a11                     mov       dl, byte ptr [ecx]
00443067  8810                     mov       byte ptr [eax], dl
00443069  8a5101                   mov       dl, byte ptr [ecx + 1]
0044306c  885001                   mov       byte ptr [eax + 1], dl
0044306f  8a5102                   mov       dl, byte ptr [ecx + 2]
00443072  885002                   mov       byte ptr [eax + 2], dl
00443075  8a5103                   mov       dl, byte ptr [ecx + 3]
00443078  885003                   mov       byte ptr [eax + 3], dl
0044307b  8a5104                   mov       dl, byte ptr [ecx + 4]
0044307e  885004                   mov       byte ptr [eax + 4], dl
00443081  8a5105                   mov       dl, byte ptr [ecx + 5]
00443084  885005                   mov       byte ptr [eax + 5], dl
00443087  8a5106                   mov       dl, byte ptr [ecx + 6]
0044308a  885006                   mov       byte ptr [eax + 6], dl
0044308d  8a5107                   mov       dl, byte ptr [ecx + 7]
00443090  885007                   mov       byte ptr [eax + 7], dl
00443093  8a5108                   mov       dl, byte ptr [ecx + 8]
00443096  885008                   mov       byte ptr [eax + 8], dl
00443099  8a5109                   mov       dl, byte ptr [ecx + 9]
0044309c  885009                   mov       byte ptr [eax + 9], dl
0044309f  8a510a                   mov       dl, byte ptr [ecx + 0xa]
004430a2  88500a                   mov       byte ptr [eax + 0xa], dl
004430a5  8a510b                   mov       dl, byte ptr [ecx + 0xb]
004430a8  88500b                   mov       byte ptr [eax + 0xb], dl
004430ab  8a510c                   mov       dl, byte ptr [ecx + 0xc]
004430ae  88500c                   mov       byte ptr [eax + 0xc], dl
004430b1  8a510d                   mov       dl, byte ptr [ecx + 0xd]
004430b4  88500d                   mov       byte ptr [eax + 0xd], dl
004430b7  8a510e                   mov       dl, byte ptr [ecx + 0xe]
004430ba  88500e                   mov       byte ptr [eax + 0xe], dl
004430bd  8a510f                   mov       dl, byte ptr [ecx + 0xf]
004430c0  88500f                   mov       byte ptr [eax + 0xf], dl
004430c3  8d4310                   lea       eax, [ebx + 0x10]
004430c6  8945fc                   mov       dword ptr [ebp - 4], eax
004430c9  6a10                     push      0x10
004430cb  6810c95700               push      0x57c910
004430d0  8d45fc                   lea       eax, [ebp - 4]
004430d3  50                       push      eax
004430d4  e8d7b8ffff               call      0x43e9b0 ; _put_string_in_ft_
004430d9  db6de0                   fld       xword ptr [ebp - 0x20]
004430dc  db6dd4                   fld       xword ptr [ebp - 0x2c]
004430df  db6dc8                   fld       xword ptr [ebp - 0x38]
004430e2  db6dbc                   fld       xword ptr [ebp - 0x44]
004430e5  83c40c                   add       esp, 0xc
004430e8  c7049d10e6f40001000000   mov       dword ptr [ebx*4 + 0xf4e610], 1
004430f3  8b85bcfdffff             mov       eax, dword ptr [ebp - 0x244]
004430f9  3d19000000               cmp       eax, 0x19
004430fe  7f0d                     jg        0x44310d
00443100  c7049d14e6f40000000000   mov       dword ptr [ebx*4 + 0xf4e614], 0
0044310b  eb14                     jmp       0x443121
0044310d  8b85bcfdffff             mov       eax, dword ptr [ebp - 0x244]
00443113  8b0c851c5b5700           mov       ecx, dword ptr [eax*4 + 0x575b1c]
0044311a  890c9d14e6f400           mov       dword ptr [ebx*4 + 0xf4e614], ecx
00443121  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
00443127  8b08                     mov       ecx, dword ptr [eax]
00443129  8d5116                   lea       edx, [ecx + 0x16]
0044312c  8d7b16                   lea       edi, [ebx + 0x16]
0044312f  8b0495c0e5f400           mov       eax, dword ptr [edx*4 + 0xf4e5c0]
00443136  8904bdc0e5f400           mov       dword ptr [edi*4 + 0xf4e5c0], eax
0044313d  8b0495c4e5f400           mov       eax, dword ptr [edx*4 + 0xf4e5c4]
00443144  8904bdc4e5f400           mov       dword ptr [edi*4 + 0xf4e5c4], eax
0044314b  8b0495c8e5f400           mov       eax, dword ptr [edx*4 + 0xf4e5c8]
00443152  8904bdc8e5f400           mov       dword ptr [edi*4 + 0xf4e5c8], eax
00443159  8b0495cce5f400           mov       eax, dword ptr [edx*4 + 0xf4e5cc]
00443160  8904bdcce5f400           mov       dword ptr [edi*4 + 0xf4e5cc], eax
00443167  8b0495d0e5f400           mov       eax, dword ptr [edx*4 + 0xf4e5d0]
0044316e  8904bdd0e5f400           mov       dword ptr [edi*4 + 0xf4e5d0], eax
00443175  8b0495d4e5f400           mov       eax, dword ptr [edx*4 + 0xf4e5d4]
0044317c  8904bdd4e5f400           mov       dword ptr [edi*4 + 0xf4e5d4], eax
00443183  8b0495d8e5f400           mov       eax, dword ptr [edx*4 + 0xf4e5d8]
0044318a  8904bdd8e5f400           mov       dword ptr [edi*4 + 0xf4e5d8], eax
00443191  8b1495dce5f400           mov       edx, dword ptr [edx*4 + 0xf4e5dc]
00443198  8914bddce5f400           mov       dword ptr [edi*4 + 0xf4e5dc], edx
0044319f  8b048d38e6f400           mov       eax, dword ptr [ecx*4 + 0xf4e638]
004431a6  89049d38e6f400           mov       dword ptr [ebx*4 + 0xf4e638], eax
004431ad  8b0c8d3ce6f400           mov       ecx, dword ptr [ecx*4 + 0xf4e63c]
004431b4  890c9d3ce6f400           mov       dword ptr [ebx*4 + 0xf4e63c], ecx
004431bb  8b4534                   mov       eax, dword ptr [ebp + 0x34]
004431be  8b44b0fc                 mov       eax, dword ptr [eax + esi*4 - 4]
004431c2  890540c85700             mov       dword ptr [0x57c840], eax ; bits=00000000, f32=0.0
004431c8  833c85ec5a0e0400         cmp       dword ptr [eax*4 + 0x40e5aec], 0
004431d0  7430                     je        0x443202
004431d2  db7dbc                   fstp      xword ptr [ebp - 0x44]
004431d5  db7dc8                   fstp      xword ptr [ebp - 0x38]
004431d8  db7dd4                   fstp      xword ptr [ebp - 0x2c]
004431db  db7de0                   fstp      xword ptr [ebp - 0x20]
004431de  8b4548                   mov       eax, dword ptr [ebp + 0x48]
004431e1  8d00                     lea       eax, [eax]
004431e3  50                       push      eax
004431e4  6840c85700               push      0x57c840
004431e9  6820c75700               push      0x57c720
004431ee  e83d0d0000               call      0x443f30 ; _kil_
004431f3  db6de0                   fld       xword ptr [ebp - 0x20]
004431f6  db6dd4                   fld       xword ptr [ebp - 0x2c]
004431f9  db6dc8                   fld       xword ptr [ebp - 0x38]
004431fc  db6dbc                   fld       xword ptr [ebp - 0x44]
004431ff  83c40c                   add       esp, 0xc
00443202  8b4534                   mov       eax, dword ptr [ebp + 0x34]
00443205  8b44b0fc                 mov       eax, dword ptr [eax + esi*4 - 4]
00443209  891c85ec5a0e04           mov       dword ptr [eax*4 + 0x40e5aec], ebx
00443210  8b4538                   mov       eax, dword ptr [ebp + 0x38]
00443213  8b44b0fc                 mov       eax, dword ptr [eax + esi*4 - 4]
00443217  8b4d50                   mov       ecx, dword ptr [ebp + 0x50]
0044321a  895c81fc                 mov       dword ptr [ecx + eax*4 - 4], ebx
0044321e  8b8588fdffff             mov       eax, dword ptr [ebp - 0x278]
00443224  8904b5bca07500           mov       dword ptr [esi*4 + 0x75a0bc], eax
0044322b  46                       inc       esi
0044322c  83ad94fdffff01           sub       dword ptr [ebp - 0x26c], 1
00443233  0f85f5fcffff             jne       0x442f2e
00443239  ddd8                     fstp      st(0)
0044323b  ddd8                     fstp      st(0)
0044323d  ddd8                     fstp      st(0)
0044323f  ddd8                     fstp      st(0)
00443241  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00443244  8b08                     mov       ecx, dword ptr [eax]
00443246  83f900                   cmp       ecx, 0
00443249  898d84fdffff             mov       dword ptr [ebp - 0x27c], ecx
0044324f  0f8ec40c0000             jle       0x443f19
00443255  b801000000               mov       eax, 1
0044325a  8b8dc4fdffff             mov       ecx, dword ptr [ebp - 0x23c]
00443260  83e913                   sub       ecx, 0x13
00443263  898d80fdffff             mov       dword ptr [ebp - 0x280], ecx
00443269  8b8dc0fdffff             mov       ecx, dword ptr [ebp - 0x240]
0044326f  83e913                   sub       ecx, 0x13
00443272  898d7cfdffff             mov       dword ptr [ebp - 0x284], ecx
00443278  8b8dbcfdffff             mov       ecx, dword ptr [ebp - 0x244]
0044327e  89ca                     mov       edx, ecx
00443280  2b95b8fdffff             sub       edx, dword ptr [ebp - 0x248]
00443286  89d7                     mov       edi, edx
00443288  8d51e2                   lea       edx, [ecx - 0x1e]
0044328b  8985a0fdffff             mov       dword ptr [ebp - 0x260], eax
00443291  899578fdffff             mov       dword ptr [ebp - 0x288], edx
00443297  8b8da0fdffff             mov       ecx, dword ptr [ebp - 0x260]
0044329d  8b4540                   mov       eax, dword ptr [ebp + 0x40]
004432a0  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
004432a4  8905d4c85700             mov       dword ptr [0x57c8d4], eax ; bits=00000000, f32=0.0
004432aa  8b4544                   mov       eax, dword ptr [ebp + 0x44]
004432ad  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
004432b1  8905d8c85700             mov       dword ptr [0x57c8d8], eax ; bits=00000000, f32=0.0
004432b7  83bd80fdffff07           cmp       dword ptr [ebp - 0x280], 7
004432be  730f                     jae       0x4432cf
004432c0  8b8580fdffff             mov       eax, dword ptr [ebp - 0x280]
004432c6  8b0c85fccb5700           mov       ecx, dword ptr [eax*4 + 0x57cbfc]
004432cd  ffe1                     jmp       ecx
004432cf  6874c85700               push      0x57c874
004432d4  6864c85700               push      0x57c864
004432d9  687cc85700               push      0x57c87c
004432de  68a4c85700               push      0x57c8a4
004432e3  6894c85700               push      0x57c894
004432e8  68ccc85700               push      0x57c8cc
004432ed  684cc85700               push      0x57c84c
004432f2  68d4c85700               push      0x57c8d4
004432f7  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
004432fd  8d08                     lea       ecx, [eax]
004432ff  51                       push      ecx
00443300  e82b530000               call      0x448630 ; _xlkt20_
00443305  83c424                   add       esp, 0x24
00443308  e99c010000               jmp       0x4434a9
0044330d  6874c85700               push      0x57c874
00443312  6864c85700               push      0x57c864
00443317  687cc85700               push      0x57c87c
0044331c  68a4c85700               push      0x57c8a4
00443321  68e0c85700               push      0x57c8e0
00443326  6894c85700               push      0x57c894
0044332b  68ccc85700               push      0x57c8cc
00443330  684cc85700               push      0x57c84c
00443335  68d4c85700               push      0x57c8d4
0044333a  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
00443340  8d08                     lea       ecx, [eax]
00443342  51                       push      ecx
00443343  e878580000               call      0x448bc0 ; _xlkt21_
00443348  83c428                   add       esp, 0x28
0044334b  e959010000               jmp       0x4434a9
00443350  68c0c85700               push      0x57c8c0
00443355  686cc85700               push      0x57c86c
0044335a  6854c85700               push      0x57c854
0044335f  6874c85700               push      0x57c874
00443364  6864c85700               push      0x57c864
00443369  687cc85700               push      0x57c87c
0044336e  68a4c85700               push      0x57c8a4
00443373  68e0c85700               push      0x57c8e0
00443378  6894c85700               push      0x57c894
0044337d  68ccc85700               push      0x57c8cc
00443382  684cc85700               push      0x57c84c
00443387  68d4c85700               push      0x57c8d4
0044338c  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
00443392  8d08                     lea       ecx, [eax]
00443394  51                       push      ecx
00443395  e8365e0000               call      0x4491d0 ; _xlkt22_
0044339a  83c434                   add       esp, 0x34
0044339d  e907010000               jmp       0x4434a9
004433a2  688cc85700               push      0x57c88c
004433a7  68b4c85700               push      0x57c8b4
004433ac  6884c85700               push      0x57c884
004433b1  68acc85700               push      0x57c8ac
004433b6  6874c85700               push      0x57c874
004433bb  6864c85700               push      0x57c864
004433c0  687cc85700               push      0x57c87c
004433c5  68a4c85700               push      0x57c8a4
004433ca  6894c85700               push      0x57c894
004433cf  68ccc85700               push      0x57c8cc
004433d4  684cc85700               push      0x57c84c
004433d9  68d4c85700               push      0x57c8d4
004433de  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
004433e4  8d08                     lea       ecx, [eax]
004433e6  51                       push      ecx
004433e7  e864660000               call      0x449a50 ; _xlkt23_
004433ec  83c434                   add       esp, 0x34
004433ef  e9b5000000               jmp       0x4434a9
004433f4  688cc85700               push      0x57c88c
004433f9  68b4c85700               push      0x57c8b4
004433fe  6884c85700               push      0x57c884
00443403  68acc85700               push      0x57c8ac
00443408  6874c85700               push      0x57c874
0044340d  6864c85700               push      0x57c864
00443412  687cc85700               push      0x57c87c
00443417  68a4c85700               push      0x57c8a4
0044341c  68e0c85700               push      0x57c8e0
00443421  6894c85700               push      0x57c894
00443426  68ccc85700               push      0x57c8cc
0044342b  684cc85700               push      0x57c84c
00443430  68d4c85700               push      0x57c8d4
00443435  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
0044343b  8d08                     lea       ecx, [eax]
0044343d  51                       push      ecx
0044343e  e8bd6e0000               call      0x44a300 ; _xlkt24_
00443443  83c438                   add       esp, 0x38
00443446  eb61                     jmp       0x4434a9
00443448  688cc85700               push      0x57c88c
0044344d  68b4c85700               push      0x57c8b4
00443452  6884c85700               push      0x57c884
00443457  68acc85700               push      0x57c8ac
0044345c  68c0c85700               push      0x57c8c0
00443461  686cc85700               push      0x57c86c
00443466  6854c85700               push      0x57c854
0044346b  6874c85700               push      0x57c874
00443470  6864c85700               push      0x57c864
00443475  687cc85700               push      0x57c87c
0044347a  68a4c85700               push      0x57c8a4
0044347f  68e0c85700               push      0x57c8e0
00443484  6894c85700               push      0x57c894
00443489  68ccc85700               push      0x57c8cc
0044348e  684cc85700               push      0x57c84c
00443493  68d4c85700               push      0x57c8d4
00443498  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
0044349e  8d08                     lea       ecx, [eax]
004434a0  51                       push      ecx
004434a1  e8ea760000               call      0x44ab90 ; _xlkt25_
004434a6  83c444                   add       esp, 0x44
004434a9  83bd7cfdffff07           cmp       dword ptr [ebp - 0x284], 7
004434b0  730f                     jae       0x4434c1
004434b2  8b857cfdffff             mov       eax, dword ptr [ebp - 0x284]
004434b8  8b0c85e0cb5700           mov       ecx, dword ptr [eax*4 + 0x57cbe0]
004434bf  ffe1                     jmp       ecx
004434c1  6878c85700               push      0x57c878
004434c6  6868c85700               push      0x57c868
004434cb  6880c85700               push      0x57c880
004434d0  68a8c85700               push      0x57c8a8
004434d5  6898c85700               push      0x57c898
004434da  68d0c85700               push      0x57c8d0
004434df  685cc85700               push      0x57c85c
004434e4  68d8c85700               push      0x57c8d8
004434e9  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
004434ef  8d08                     lea       ecx, [eax]
004434f1  51                       push      ecx
004434f2  e839510000               call      0x448630 ; _xlkt20_
004434f7  83c424                   add       esp, 0x24
004434fa  e99c010000               jmp       0x44369b
004434ff  6878c85700               push      0x57c878
00443504  6868c85700               push      0x57c868
00443509  6880c85700               push      0x57c880
0044350e  68a8c85700               push      0x57c8a8
00443513  68e4c85700               push      0x57c8e4
00443518  6898c85700               push      0x57c898
0044351d  68d0c85700               push      0x57c8d0
00443522  685cc85700               push      0x57c85c
00443527  68d8c85700               push      0x57c8d8
0044352c  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
00443532  8d08                     lea       ecx, [eax]
00443534  51                       push      ecx
00443535  e886560000               call      0x448bc0 ; _xlkt21_
0044353a  83c428                   add       esp, 0x28
0044353d  e959010000               jmp       0x44369b
00443542  68c4c85700               push      0x57c8c4
00443547  6870c85700               push      0x57c870
0044354c  6858c85700               push      0x57c858
00443551  6878c85700               push      0x57c878
00443556  6868c85700               push      0x57c868
0044355b  6880c85700               push      0x57c880
00443560  68a8c85700               push      0x57c8a8
00443565  68e4c85700               push      0x57c8e4
0044356a  6898c85700               push      0x57c898
0044356f  68d0c85700               push      0x57c8d0
00443574  685cc85700               push      0x57c85c
00443579  68d8c85700               push      0x57c8d8
0044357e  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
00443584  8d08                     lea       ecx, [eax]
00443586  51                       push      ecx
00443587  e8445c0000               call      0x4491d0 ; _xlkt22_
0044358c  83c434                   add       esp, 0x34
0044358f  e907010000               jmp       0x44369b
00443594  6890c85700               push      0x57c890
00443599  68b8c85700               push      0x57c8b8
0044359e  6888c85700               push      0x57c888
004435a3  68b0c85700               push      0x57c8b0
004435a8  6878c85700               push      0x57c878
004435ad  6868c85700               push      0x57c868
004435b2  6880c85700               push      0x57c880
004435b7  68a8c85700               push      0x57c8a8
004435bc  6898c85700               push      0x57c898
004435c1  68d0c85700               push      0x57c8d0
004435c6  685cc85700               push      0x57c85c
004435cb  68d8c85700               push      0x57c8d8
004435d0  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
004435d6  8d08                     lea       ecx, [eax]
004435d8  51                       push      ecx
004435d9  e872640000               call      0x449a50 ; _xlkt23_
004435de  83c434                   add       esp, 0x34
004435e1  e9b5000000               jmp       0x44369b
004435e6  6890c85700               push      0x57c890
004435eb  68b8c85700               push      0x57c8b8
004435f0  6888c85700               push      0x57c888
004435f5  68b0c85700               push      0x57c8b0
004435fa  6878c85700               push      0x57c878
004435ff  6868c85700               push      0x57c868
00443604  6880c85700               push      0x57c880
00443609  68a8c85700               push      0x57c8a8
0044360e  68e4c85700               push      0x57c8e4
00443613  6898c85700               push      0x57c898
00443618  68d0c85700               push      0x57c8d0
0044361d  685cc85700               push      0x57c85c
00443622  68d8c85700               push      0x57c8d8
00443627  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
0044362d  8d08                     lea       ecx, [eax]
0044362f  51                       push      ecx
00443630  e8cb6c0000               call      0x44a300 ; _xlkt24_
00443635  83c438                   add       esp, 0x38
00443638  eb61                     jmp       0x44369b
0044363a  6890c85700               push      0x57c890
0044363f  68b8c85700               push      0x57c8b8
00443644  6888c85700               push      0x57c888
00443649  68b0c85700               push      0x57c8b0
0044364e  68c4c85700               push      0x57c8c4
00443653  6870c85700               push      0x57c870
00443658  6858c85700               push      0x57c858
0044365d  6878c85700               push      0x57c878
00443662  6868c85700               push      0x57c868
00443667  6880c85700               push      0x57c880
0044366c  68a8c85700               push      0x57c8a8
00443671  68e4c85700               push      0x57c8e4
00443676  6898c85700               push      0x57c898
0044367b  68d0c85700               push      0x57c8d0
00443680  685cc85700               push      0x57c85c
00443685  68d8c85700               push      0x57c8d8
0044368a  8b85d8fdffff             mov       eax, dword ptr [ebp - 0x228]
00443690  8d08                     lea       ecx, [eax]
00443692  51                       push      ecx
00443693  e8f8740000               call      0x44ab90 ; _xlkt25_
00443698  83c444                   add       esp, 0x44
0044369b  d905a4c85700             fld       dword ptr [0x57c8a4] ; bits=00000000, f32=0.0
004436a1  d9fa                     fsqrt
004436a3  d91da4c85700             fstp      dword ptr [0x57c8a4] ; bits=00000000, f32=0.0
004436a9  d905a8c85700             fld       dword ptr [0x57c8a8] ; bits=00000000, f32=0.0
004436af  d9fa                     fsqrt
004436b1  d91da8c85700             fstp      dword ptr [0x57c8a8] ; bits=00000000, f32=0.0
004436b7  d905a4c85700             fld       dword ptr [0x57c8a4] ; bits=00000000, f32=0.0
004436bd  d8153cc65700             fcom      dword ptr [0x57c63c] ; bits=00000000, f32=0.0
004436c3  dbbdecfeffff             fstp      xword ptr [ebp - 0x114]
004436c9  dfe0                     fnstsw    ax
004436cb  9e                       sahf
004436cc  0f8a1e000000             jp        0x4436f0
004436d2  761c                     jbe       0x4436f0
004436d4  d9057cc85700             fld       dword ptr [0x57c87c] ; bits=00000000, f32=0.0
004436da  d80d44c65700             fmul      dword ptr [0x57c644] ; bits=0000003f, f32=0.5
004436e0  dbadecfeffff             fld       xword ptr [ebp - 0x114]
004436e6  def9                     fdivp     st(1)
004436e8  d91d7cc85700             fstp      dword ptr [0x57c87c] ; bits=00000000, f32=0.0
004436ee  eb0a                     jmp       0x4436fa
004436f0  c7057cc8570000000000     mov       dword ptr [0x57c87c], 0 ; bits=00000000, f32=0.0
004436fa  d905a8c85700             fld       dword ptr [0x57c8a8] ; bits=00000000, f32=0.0
00443700  d8153cc65700             fcom      dword ptr [0x57c63c] ; bits=00000000, f32=0.0
00443706  dbbde0feffff             fstp      xword ptr [ebp - 0x120]
0044370c  dfe0                     fnstsw    ax
0044370e  9e                       sahf
0044370f  0f8a1e000000             jp        0x443733
00443715  761c                     jbe       0x443733
00443717  d90580c85700             fld       dword ptr [0x57c880] ; bits=00000000, f32=0.0
0044371d  d80d44c65700             fmul      dword ptr [0x57c644] ; bits=0000003f, f32=0.5
00443723  dbade0feffff             fld       xword ptr [ebp - 0x120]
00443729  def9                     fdivp     st(1)
0044372b  d91d80c85700             fstp      dword ptr [0x57c880] ; bits=00000000, f32=0.0
00443731  eb0a                     jmp       0x44373d
00443733  c70580c8570000000000     mov       dword ptr [0x57c880], 0 ; bits=00000000, f32=0.0
0044373d  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00443740  8b08                     mov       ecx, dword ptr [eax]
00443742  83f900                   cmp       ecx, 0
00443745  898d74fdffff             mov       dword ptr [ebp - 0x28c], ecx
0044374b  0f8eb5070000             jle       0x443f06
00443751  be01000000               mov       esi, 1
00443756  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00443759  d900                     fld       dword ptr [eax]
0044375b  dbbdd4feffff             fstp      xword ptr [ebp - 0x12c]
00443761  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00443767  d83d38c65700             fdivr     dword ptr [0x57c638] ; bits=0000803f, f32=1.0
0044376d  dbbdc8feffff             fstp      xword ptr [ebp - 0x138]
00443773  d905ccc85700             fld       dword ptr [0x57c8cc] ; bits=00000000, f32=0.0
00443779  d82dd0c85700             fsubr     dword ptr [0x57c8d0] ; bits=00000000, f32=0.0
0044377f  dbbdbcfeffff             fstp      xword ptr [ebp - 0x144]
00443785  d9054cc85700             fld       dword ptr [0x57c84c] ; bits=00000000, f32=0.0
0044378b  d82d5cc85700             fsubr     dword ptr [0x57c85c] ; bits=00000000, f32=0.0
00443791  dbbdb0feffff             fstp      xword ptr [ebp - 0x150]
00443797  d905a4c85700             fld       dword ptr [0x57c8a4] ; bits=00000000, f32=0.0
0044379d  d82da8c85700             fsubr     dword ptr [0x57c8a8] ; bits=00000000, f32=0.0
004437a3  dbbda4feffff             fstp      xword ptr [ebp - 0x15c]
004437a9  d90564c85700             fld       dword ptr [0x57c864] ; bits=00000000, f32=0.0
004437af  d82d68c85700             fsubr     dword ptr [0x57c868] ; bits=00000000, f32=0.0
004437b5  dbbd98feffff             fstp      xword ptr [ebp - 0x168]
004437bb  d905d4c85700             fld       dword ptr [0x57c8d4] ; bits=00000000, f32=0.0
004437c1  d82dd8c85700             fsubr     dword ptr [0x57c8d8] ; bits=00000000, f32=0.0
004437c7  dbbd8cfeffff             fstp      xword ptr [ebp - 0x174]
004437cd  8b04bd4cc95700           mov       eax, dword ptr [edi*4 + 0x57c94c]
004437d4  d905e0c85700             fld       dword ptr [0x57c8e0] ; bits=00000000, f32=0.0
004437da  d82de4c85700             fsubr     dword ptr [0x57c8e4] ; bits=00000000, f32=0.0
004437e0  dbbd80feffff             fstp      xword ptr [ebp - 0x180]
004437e6  8b0cbd40ca5700           mov       ecx, dword ptr [edi*4 + 0x57ca40]
004437ed  d90554c85700             fld       dword ptr [0x57c854] ; bits=00000000, f32=0.0
004437f3  d82d58c85700             fsubr     dword ptr [0x57c858] ; bits=00000000, f32=0.0
004437f9  dbbd74feffff             fstp      xword ptr [ebp - 0x18c]
004437ff  d905c0c85700             fld       dword ptr [0x57c8c0] ; bits=00000000, f32=0.0
00443805  d82dc4c85700             fsubr     dword ptr [0x57c8c4] ; bits=00000000, f32=0.0
0044380b  dbbd68feffff             fstp      xword ptr [ebp - 0x198]
00443811  d905acc85700             fld       dword ptr [0x57c8ac] ; bits=00000000, f32=0.0
00443817  d82db0c85700             fsubr     dword ptr [0x57c8b0] ; bits=00000000, f32=0.0
0044381d  dbbd5cfeffff             fstp      xword ptr [ebp - 0x1a4]
00443823  d905b4c85700             fld       dword ptr [0x57c8b4] ; bits=00000000, f32=0.0
00443829  d82db8c85700             fsubr     dword ptr [0x57c8b8] ; bits=00000000, f32=0.0
0044382f  dbbd50feffff             fstp      xword ptr [ebp - 0x1b0]
00443835  d9057cc85700             fld       dword ptr [0x57c87c] ; bits=00000000, f32=0.0
0044383b  d82d80c85700             fsubr     dword ptr [0x57c880] ; bits=00000000, f32=0.0
00443841  dbbd44feffff             fstp      xword ptr [ebp - 0x1bc]
00443847  d90574c85700             fld       dword ptr [0x57c874] ; bits=00000000, f32=0.0
0044384d  d82d78c85700             fsubr     dword ptr [0x57c878] ; bits=00000000, f32=0.0
00443853  dbbd38feffff             fstp      xword ptr [ebp - 0x1c8]
00443859  d9056cc85700             fld       dword ptr [0x57c86c] ; bits=00000000, f32=0.0
0044385f  d82d70c85700             fsubr     dword ptr [0x57c870] ; bits=00000000, f32=0.0
00443865  dbbd2cfeffff             fstp      xword ptr [ebp - 0x1d4]
0044386b  d90584c85700             fld       dword ptr [0x57c884] ; bits=00000000, f32=0.0
00443871  d82d88c85700             fsubr     dword ptr [0x57c888] ; bits=00000000, f32=0.0
00443877  dbbd20feffff             fstp      xword ptr [ebp - 0x1e0]
0044387d  d9058cc85700             fld       dword ptr [0x57c88c] ; bits=00000000, f32=0.0
00443883  d82d90c85700             fsubr     dword ptr [0x57c890] ; bits=00000000, f32=0.0
00443889  dbbd14feffff             fstp      xword ptr [ebp - 0x1ec]
0044388f  898570fdffff             mov       dword ptr [ebp - 0x290], eax
00443895  898d6cfdffff             mov       dword ptr [ebp - 0x294], ecx
0044389b  8b1cb5bca07500           mov       ebx, dword ptr [esi*4 + 0x75a0bc]
004438a2  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
004438a5  dbadd4feffff             fld       xword ptr [ebp - 0x12c]
004438ab  d86cb0fc                 fsubr     dword ptr [eax + esi*4 - 4]
004438af  dbadc8feffff             fld       xword ptr [ebp - 0x138]
004438b5  dec9                     fmulp     st(1)
004438b7  dbadbcfeffff             fld       xword ptr [ebp - 0x144]
004438bd  d8c9                     fmul      st(1)
004438bf  d805ccc85700             fadd      dword ptr [0x57c8cc] ; bits=00000000, f32=0.0
004438c5  dbadb0feffff             fld       xword ptr [ebp - 0x150]
004438cb  d8ca                     fmul      st(2)
004438cd  d8054cc85700             fadd      dword ptr [0x57c84c] ; bits=00000000, f32=0.0
004438d3  dbada4feffff             fld       xword ptr [ebp - 0x15c]
004438d9  d8cb                     fmul      st(3)
004438db  d805a4c85700             fadd      dword ptr [0x57c8a4] ; bits=00000000, f32=0.0
004438e1  dbad98feffff             fld       xword ptr [ebp - 0x168]
004438e7  d8cc                     fmul      st(4)
004438e9  d80564c85700             fadd      dword ptr [0x57c864] ; bits=00000000, f32=0.0
004438ef  dbad8cfeffff             fld       xword ptr [ebp - 0x174]
004438f5  d8cd                     fmul      st(5)
004438f7  d805d4c85700             fadd      dword ptr [0x57c8d4] ; bits=00000000, f32=0.0
004438fd  d91c9dc0e5f400           fstp      dword ptr [ebx*4 + 0xf4e5c0]
00443904  d9cb                     fxch      st(3)
00443906  d91c9dc4e5f400           fstp      dword ptr [ebx*4 + 0xf4e5c4]
0044390d  d9c9                     fxch      st(1)
0044390f  d91c9dc8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5c8]
00443916  d91c9dcce5f400           fstp      dword ptr [ebx*4 + 0xf4e5cc]
0044391d  d91c9dd0e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d0]
00443924  dbbd08feffff             fstp      xword ptr [ebp - 0x1f8]
0044392a  83bd70fdffff01           cmp       dword ptr [ebp - 0x290], 1
00443931  751b                     jne       0x44394e
00443933  dbad80feffff             fld       xword ptr [ebp - 0x180]
00443939  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
0044393f  dec9                     fmulp     st(1)
00443941  d805e0c85700             fadd      dword ptr [0x57c8e0] ; bits=00000000, f32=0.0
00443947  d91c9dd4e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d4]
0044394e  83bd6cfdffff01           cmp       dword ptr [ebp - 0x294], 1
00443955  7538                     jne       0x44398f
00443957  dbad74feffff             fld       xword ptr [ebp - 0x18c]
0044395d  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443963  dec9                     fmulp     st(1)
00443965  d80554c85700             fadd      dword ptr [0x57c854] ; bits=00000000, f32=0.0
0044396b  dbad68feffff             fld       xword ptr [ebp - 0x198]
00443971  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443977  dec9                     fmulp     st(1)
00443979  d805c0c85700             fadd      dword ptr [0x57c8c0] ; bits=00000000, f32=0.0
0044397f  d9c9                     fxch      st(1)
00443981  d91c9dd8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d8]
00443988  d91c9ddce5f400           fstp      dword ptr [ebx*4 + 0xf4e5dc]
0044398f  83ff17                   cmp       edi, 0x17
00443992  0f8c95000000             jl        0x443a2d
00443998  dbad5cfeffff             fld       xword ptr [ebp - 0x1a4]
0044399e  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
004439a4  dec9                     fmulp     st(1)
004439a6  d805acc85700             fadd      dword ptr [0x57c8ac] ; bits=00000000, f32=0.0
004439ac  dbbdfcfdffff             fstp      xword ptr [ebp - 0x204]
004439b2  dbad50feffff             fld       xword ptr [ebp - 0x1b0]
004439b8  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
004439be  dec9                     fmulp     st(1)
004439c0  d805b4c85700             fadd      dword ptr [0x57c8b4] ; bits=00000000, f32=0.0
004439c6  dbbdf0fdffff             fstp      xword ptr [ebp - 0x210]
004439cc  83ff17                   cmp       edi, 0x17
004439cf  751c                     jne       0x4439ed
004439d1  dbadfcfdffff             fld       xword ptr [ebp - 0x204]
004439d7  d91c9dd4e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d4]
004439de  dbadf0fdffff             fld       xword ptr [ebp - 0x210]
004439e4  d91c9dd8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d8]
004439eb  eb40                     jmp       0x443a2d
004439ed  83ff18                   cmp       edi, 0x18
004439f0  751c                     jne       0x443a0e
004439f2  dbadfcfdffff             fld       xword ptr [ebp - 0x204]
004439f8  d91c9dd8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d8]
004439ff  dbadf0fdffff             fld       xword ptr [ebp - 0x210]
00443a05  d91c9ddce5f400           fstp      dword ptr [ebx*4 + 0xf4e5dc]
00443a0c  eb1f                     jmp       0x443a2d
00443a0e  83ff19                   cmp       edi, 0x19
00443a11  751a                     jne       0x443a2d
00443a13  dbadfcfdffff             fld       xword ptr [ebp - 0x204]
00443a19  d91c9de0e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e0]
00443a20  dbadf0fdffff             fld       xword ptr [ebp - 0x210]
00443a26  d91c9de4e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e4]
00443a2d  83bdbcfdffff1e           cmp       dword ptr [ebp - 0x244], 0x1e
00443a34  0f8caf040000             jl        0x443ee9
00443a3a  83bd78fdffff06           cmp       dword ptr [ebp - 0x288], 6
00443a41  0f83a2040000             jae       0x443ee9
00443a47  8b8578fdffff             mov       eax, dword ptr [ebp - 0x288]
00443a4d  8b0c85c8cb5700           mov       ecx, dword ptr [eax*4 + 0x57cbc8]
00443a54  ffe1                     jmp       ecx
00443a56  dbad44feffff             fld       xword ptr [ebp - 0x1bc]
00443a5c  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443a62  dec9                     fmulp     st(1)
00443a64  d8057cc85700             fadd      dword ptr [0x57c87c] ; bits=00000000, f32=0.0
00443a6a  dbad38feffff             fld       xword ptr [ebp - 0x1c8]
00443a70  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443a76  dec9                     fmulp     st(1)
00443a78  d80574c85700             fadd      dword ptr [0x57c874] ; bits=00000000, f32=0.0
00443a7e  d9c1                     fld       st(1)
00443a80  d9e1                     fabs
00443a82  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443a88  d9c9                     fxch      st(1)
00443a8a  dfe0                     fnstsw    ax
00443a8c  9e                       sahf
00443a8d  0f8a06000000             jp        0x443a99
00443a93  7304                     jae       0x443a99
00443a95  ddd8                     fstp      st(0)
00443a97  d9ee                     fldz
00443a99  d9c1                     fld       st(1)
00443a9b  d9e1                     fabs
00443a9d  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443aa3  dfe0                     fnstsw    ax
00443aa5  9e                       sahf
00443aa6  0f8a08000000             jp        0x443ab4
00443aac  7306                     jae       0x443ab4
00443aae  ddd9                     fstp      st(1)
00443ab0  d9ee                     fldz
00443ab2  d9c9                     fxch      st(1)
00443ab4  d91c9dd4e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d4]
00443abb  d91c9dd8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d8]
00443ac2  e922040000               jmp       0x443ee9
00443ac7  dbad44feffff             fld       xword ptr [ebp - 0x1bc]
00443acd  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443ad3  dec9                     fmulp     st(1)
00443ad5  d8057cc85700             fadd      dword ptr [0x57c87c] ; bits=00000000, f32=0.0
00443adb  dbad38feffff             fld       xword ptr [ebp - 0x1c8]
00443ae1  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443ae7  dec9                     fmulp     st(1)
00443ae9  d80574c85700             fadd      dword ptr [0x57c874] ; bits=00000000, f32=0.0
00443aef  d9c1                     fld       st(1)
00443af1  d9e1                     fabs
00443af3  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443af9  d9c9                     fxch      st(1)
00443afb  dfe0                     fnstsw    ax
00443afd  9e                       sahf
00443afe  0f8a06000000             jp        0x443b0a
00443b04  7304                     jae       0x443b0a
00443b06  ddd8                     fstp      st(0)
00443b08  d9ee                     fldz
00443b0a  d9c1                     fld       st(1)
00443b0c  d9e1                     fabs
00443b0e  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443b14  dfe0                     fnstsw    ax
00443b16  9e                       sahf
00443b17  0f8a08000000             jp        0x443b25
00443b1d  7306                     jae       0x443b25
00443b1f  ddd9                     fstp      st(1)
00443b21  d9ee                     fldz
00443b23  d9c9                     fxch      st(1)
00443b25  d91c9dd8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d8]
00443b2c  d91c9ddce5f400           fstp      dword ptr [ebx*4 + 0xf4e5dc]
00443b33  e9b1030000               jmp       0x443ee9
00443b38  dbad44feffff             fld       xword ptr [ebp - 0x1bc]
00443b3e  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443b44  dec9                     fmulp     st(1)
00443b46  d8057cc85700             fadd      dword ptr [0x57c87c] ; bits=00000000, f32=0.0
00443b4c  dbad38feffff             fld       xword ptr [ebp - 0x1c8]
00443b52  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443b58  dec9                     fmulp     st(1)
00443b5a  d80574c85700             fadd      dword ptr [0x57c874] ; bits=00000000, f32=0.0
00443b60  dbad2cfeffff             fld       xword ptr [ebp - 0x1d4]
00443b66  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443b6c  dec9                     fmulp     st(1)
00443b6e  d8056cc85700             fadd      dword ptr [0x57c86c] ; bits=00000000, f32=0.0
00443b74  dbbde4fdffff             fstp      xword ptr [ebp - 0x21c]
00443b7a  d9c1                     fld       st(1)
00443b7c  d9e1                     fabs
00443b7e  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443b84  d9c9                     fxch      st(1)
00443b86  dfe0                     fnstsw    ax
00443b88  9e                       sahf
00443b89  0f8a06000000             jp        0x443b95
00443b8f  7304                     jae       0x443b95
00443b91  ddd8                     fstp      st(0)
00443b93  d9ee                     fldz
00443b95  d9c1                     fld       st(1)
00443b97  d9e1                     fabs
00443b99  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443b9f  dfe0                     fnstsw    ax
00443ba1  9e                       sahf
00443ba2  0f8a08000000             jp        0x443bb0
00443ba8  7306                     jae       0x443bb0
00443baa  ddd9                     fstp      st(1)
00443bac  d9ee                     fldz
00443bae  d9c9                     fxch      st(1)
00443bb0  dbade4fdffff             fld       xword ptr [ebp - 0x21c]
00443bb6  d9e1                     fabs
00443bb8  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443bbe  dfe0                     fnstsw    ax
00443bc0  9e                       sahf
00443bc1  0f8a0a000000             jp        0x443bd1
00443bc7  7308                     jae       0x443bd1
00443bc9  d9ee                     fldz
00443bcb  dbbde4fdffff             fstp      xword ptr [ebp - 0x21c]
00443bd1  d91c9de0e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e0]
00443bd8  d91c9de4e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e4]
00443bdf  dbade4fdffff             fld       xword ptr [ebp - 0x21c]
00443be5  d91c9de8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e8]
00443bec  e9f8020000               jmp       0x443ee9
00443bf1  dbad44feffff             fld       xword ptr [ebp - 0x1bc]
00443bf7  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443bfd  dec9                     fmulp     st(1)
00443bff  d8057cc85700             fadd      dword ptr [0x57c87c] ; bits=00000000, f32=0.0
00443c05  dbad38feffff             fld       xword ptr [ebp - 0x1c8]
00443c0b  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443c11  dec9                     fmulp     st(1)
00443c13  d80574c85700             fadd      dword ptr [0x57c874] ; bits=00000000, f32=0.0
00443c19  dbad20feffff             fld       xword ptr [ebp - 0x1e0]
00443c1f  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443c25  dec9                     fmulp     st(1)
00443c27  d80584c85700             fadd      dword ptr [0x57c884] ; bits=00000000, f32=0.0
00443c2d  dbad14feffff             fld       xword ptr [ebp - 0x1ec]
00443c33  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443c39  dec9                     fmulp     st(1)
00443c3b  d8058cc85700             fadd      dword ptr [0x57c88c] ; bits=00000000, f32=0.0
00443c41  d9c3                     fld       st(3)
00443c43  d9e1                     fabs
00443c45  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443c4b  d9ca                     fxch      st(2)
00443c4d  d9cb                     fxch      st(3)
00443c4f  d9ca                     fxch      st(2)
00443c51  dfe0                     fnstsw    ax
00443c53  9e                       sahf
00443c54  0f8a08000000             jp        0x443c62
00443c5a  7306                     jae       0x443c62
00443c5c  ddda                     fstp      st(2)
00443c5e  d9ee                     fldz
00443c60  d9ca                     fxch      st(2)
00443c62  d9c3                     fld       st(3)
00443c64  d9e1                     fabs
00443c66  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443c6c  dfe0                     fnstsw    ax
00443c6e  9e                       sahf
00443c6f  0f8a08000000             jp        0x443c7d
00443c75  7306                     jae       0x443c7d
00443c77  dddb                     fstp      st(3)
00443c79  d9ee                     fldz
00443c7b  d9cb                     fxch      st(3)
00443c7d  d9c1                     fld       st(1)
00443c7f  d9e1                     fabs
00443c81  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443c87  dfe0                     fnstsw    ax
00443c89  9e                       sahf
00443c8a  0f8a08000000             jp        0x443c98
00443c90  7306                     jae       0x443c98
00443c92  ddd9                     fstp      st(1)
00443c94  d9ee                     fldz
00443c96  d9c9                     fxch      st(1)
00443c98  d9c0                     fld       st(0)
00443c9a  d9e1                     fabs
00443c9c  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443ca2  dfe0                     fnstsw    ax
00443ca4  9e                       sahf
00443ca5  0f8a06000000             jp        0x443cb1
00443cab  7304                     jae       0x443cb1
00443cad  ddd8                     fstp      st(0)
00443caf  d9ee                     fldz
00443cb1  d9ca                     fxch      st(2)
00443cb3  d91c9ddce5f400           fstp      dword ptr [ebx*4 + 0xf4e5dc]
00443cba  d9ca                     fxch      st(2)
00443cbc  d91c9de0e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e0]
00443cc3  d9c9                     fxch      st(1)
00443cc5  d91c9de4e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e4]
00443ccc  d91c9de8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e8]
00443cd3  e911020000               jmp       0x443ee9
00443cd8  dbad44feffff             fld       xword ptr [ebp - 0x1bc]
00443cde  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443ce4  dec9                     fmulp     st(1)
00443ce6  d8057cc85700             fadd      dword ptr [0x57c87c] ; bits=00000000, f32=0.0
00443cec  dbad38feffff             fld       xword ptr [ebp - 0x1c8]
00443cf2  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443cf8  dec9                     fmulp     st(1)
00443cfa  d80574c85700             fadd      dword ptr [0x57c874] ; bits=00000000, f32=0.0
00443d00  dbad20feffff             fld       xword ptr [ebp - 0x1e0]
00443d06  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443d0c  dec9                     fmulp     st(1)
00443d0e  d80584c85700             fadd      dword ptr [0x57c884] ; bits=00000000, f32=0.0
00443d14  dbad14feffff             fld       xword ptr [ebp - 0x1ec]
00443d1a  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443d20  dec9                     fmulp     st(1)
00443d22  d8058cc85700             fadd      dword ptr [0x57c88c] ; bits=00000000, f32=0.0
00443d28  d9c3                     fld       st(3)
00443d2a  d9e1                     fabs
00443d2c  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443d32  d9ca                     fxch      st(2)
00443d34  d9cb                     fxch      st(3)
00443d36  d9ca                     fxch      st(2)
00443d38  dfe0                     fnstsw    ax
00443d3a  9e                       sahf
00443d3b  0f8a08000000             jp        0x443d49
00443d41  7306                     jae       0x443d49
00443d43  ddda                     fstp      st(2)
00443d45  d9ee                     fldz
00443d47  d9ca                     fxch      st(2)
00443d49  d9c3                     fld       st(3)
00443d4b  d9e1                     fabs
00443d4d  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443d53  dfe0                     fnstsw    ax
00443d55  9e                       sahf
00443d56  0f8a08000000             jp        0x443d64
00443d5c  7306                     jae       0x443d64
00443d5e  dddb                     fstp      st(3)
00443d60  d9ee                     fldz
00443d62  d9cb                     fxch      st(3)
00443d64  d9c1                     fld       st(1)
00443d66  d9e1                     fabs
00443d68  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443d6e  dfe0                     fnstsw    ax
00443d70  9e                       sahf
00443d71  0f8a08000000             jp        0x443d7f
00443d77  7306                     jae       0x443d7f
00443d79  ddd9                     fstp      st(1)
00443d7b  d9ee                     fldz
00443d7d  d9c9                     fxch      st(1)
00443d7f  d9c0                     fld       st(0)
00443d81  d9e1                     fabs
00443d83  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443d89  dfe0                     fnstsw    ax
00443d8b  9e                       sahf
00443d8c  0f8a06000000             jp        0x443d98
00443d92  7304                     jae       0x443d98
00443d94  ddd8                     fstp      st(0)
00443d96  d9ee                     fldz
00443d98  d9ca                     fxch      st(2)
00443d9a  d91c9de0e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e0]
00443da1  d9ca                     fxch      st(2)
00443da3  d91c9de4e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e4]
00443daa  d9c9                     fxch      st(1)
00443dac  d91c9de8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e8]
00443db3  d91c9dece5f400           fstp      dword ptr [ebx*4 + 0xf4e5ec]
00443dba  e92a010000               jmp       0x443ee9
00443dbf  dbad44feffff             fld       xword ptr [ebp - 0x1bc]
00443dc5  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443dcb  dec9                     fmulp     st(1)
00443dcd  d8057cc85700             fadd      dword ptr [0x57c87c] ; bits=00000000, f32=0.0
00443dd3  dbad38feffff             fld       xword ptr [ebp - 0x1c8]
00443dd9  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443ddf  dec9                     fmulp     st(1)
00443de1  d80574c85700             fadd      dword ptr [0x57c874] ; bits=00000000, f32=0.0
00443de7  dbad2cfeffff             fld       xword ptr [ebp - 0x1d4]
00443ded  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443df3  dec9                     fmulp     st(1)
00443df5  d8056cc85700             fadd      dword ptr [0x57c86c] ; bits=00000000, f32=0.0
00443dfb  dbbde4fdffff             fstp      xword ptr [ebp - 0x21c]
00443e01  dbad20feffff             fld       xword ptr [ebp - 0x1e0]
00443e07  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443e0d  dec9                     fmulp     st(1)
00443e0f  d80584c85700             fadd      dword ptr [0x57c884] ; bits=00000000, f32=0.0
00443e15  dbad14feffff             fld       xword ptr [ebp - 0x1ec]
00443e1b  dbad08feffff             fld       xword ptr [ebp - 0x1f8]
00443e21  dec9                     fmulp     st(1)
00443e23  d8058cc85700             fadd      dword ptr [0x57c88c] ; bits=00000000, f32=0.0
00443e29  d9c3                     fld       st(3)
00443e2b  d9e1                     fabs
00443e2d  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443e33  d9ca                     fxch      st(2)
00443e35  d9cb                     fxch      st(3)
00443e37  d9ca                     fxch      st(2)
00443e39  dfe0                     fnstsw    ax
00443e3b  9e                       sahf
00443e3c  0f8a08000000             jp        0x443e4a
00443e42  7306                     jae       0x443e4a
00443e44  ddda                     fstp      st(2)
00443e46  d9ee                     fldz
00443e48  d9ca                     fxch      st(2)
00443e4a  d9c3                     fld       st(3)
00443e4c  d9e1                     fabs
00443e4e  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443e54  dfe0                     fnstsw    ax
00443e56  9e                       sahf
00443e57  0f8a08000000             jp        0x443e65
00443e5d  7306                     jae       0x443e65
00443e5f  dddb                     fstp      st(3)
00443e61  d9ee                     fldz
00443e63  d9cb                     fxch      st(3)
00443e65  dbade4fdffff             fld       xword ptr [ebp - 0x21c]
00443e6b  d9e1                     fabs
00443e6d  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443e73  dfe0                     fnstsw    ax
00443e75  9e                       sahf
00443e76  0f8a0a000000             jp        0x443e86
00443e7c  7308                     jae       0x443e86
00443e7e  d9ee                     fldz
00443e80  dbbde4fdffff             fstp      xword ptr [ebp - 0x21c]
00443e86  d9c1                     fld       st(1)
00443e88  d9e1                     fabs
00443e8a  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443e90  dfe0                     fnstsw    ax
00443e92  9e                       sahf
00443e93  0f8a08000000             jp        0x443ea1
00443e99  7306                     jae       0x443ea1
00443e9b  ddd9                     fstp      st(1)
00443e9d  d9ee                     fldz
00443e9f  d9c9                     fxch      st(1)
00443ea1  d9c0                     fld       st(0)
00443ea3  d9e1                     fabs
00443ea5  d81d48c65700             fcomp     dword ptr [0x57c648] ; bits=37d08a30, f32=1.0099999725454722e-09
00443eab  dfe0                     fnstsw    ax
00443ead  9e                       sahf
00443eae  0f8a06000000             jp        0x443eba
00443eb4  7304                     jae       0x443eba
00443eb6  ddd8                     fstp      st(0)
00443eb8  d9ee                     fldz
00443eba  d9ca                     fxch      st(2)
00443ebc  d91c9de8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5e8]
00443ec3  d9ca                     fxch      st(2)
00443ec5  d91c9dece5f400           fstp      dword ptr [ebx*4 + 0xf4e5ec]
00443ecc  d9c9                     fxch      st(1)
00443ece  d91c9df0e5f400           fstp      dword ptr [ebx*4 + 0xf4e5f0]
00443ed5  d91c9df4e5f400           fstp      dword ptr [ebx*4 + 0xf4e5f4]
00443edc  dbade4fdffff             fld       xword ptr [ebp - 0x21c]
00443ee2  d91c9df8e5f400           fstp      dword ptr [ebx*4 + 0xf4e5f8]
00443ee9  89d8                     mov       eax, ebx
00443eeb  0385b4fdffff             add       eax, dword ptr [ebp - 0x24c]
00443ef1  8904b5bca07500           mov       dword ptr [esi*4 + 0x75a0bc], eax
00443ef8  46                       inc       esi
00443ef9  83ad74fdffff01           sub       dword ptr [ebp - 0x28c], 1
00443f00  0f8595f9ffff             jne       0x44389b
00443f06  ff85a0fdffff             inc       dword ptr [ebp - 0x260]
00443f0c  83ad84fdffff01           sub       dword ptr [ebp - 0x27c], 1
00443f13  0f857ef3ffff             jne       0x443297
00443f19  b800000000               mov       eax, 0
00443f1e  5f                       pop       edi
00443f1f  5e                       pop       esi
00443f20  5b                       pop       ebx
00443f21  8be5                     mov       esp, ebp
00443f23  5d                       pop       ebp
00443f24  c3                       ret
00443f25  8d642400                 lea       esp, [esp]
00443f29  8da42400000000           lea       esp, [esp]
