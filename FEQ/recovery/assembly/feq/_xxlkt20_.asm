; _xxlkt20_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0xbf70
0040bf70  81ecb8000000             sub       esp, 0xb8
0040bf76  53                       push      ebx
0040bf77  8b8c24c0000000           mov       ecx, dword ptr [esp + 0xc0]
0040bf7e  8b9424c4000000           mov       edx, dword ptr [esp + 0xc4]
0040bf85  8b8424c8000000           mov       eax, dword ptr [esp + 0xc8]
0040bf8c  89442410                 mov       dword ptr [esp + 0x10], eax
0040bf90  d902                     fld       dword ptr [edx]
0040bf92  8b01                     mov       eax, dword ptr [ecx]
0040bf94  8b0c856c2e0302           mov       ecx, dword ptr [eax*4 + 0x2032e6c]
0040bf9b  8b1c85682e0302           mov       ebx, dword ptr [eax*4 + 0x2032e68]
0040bfa2  8b149d1ccf3b05           mov       edx, dword ptr [ebx*4 + 0x53bcf1c]
0040bfa9  8b1c85b42e0302           mov       ebx, dword ptr [eax*4 + 0x2032eb4]
0040bfb0  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0040bfb7  dff1                     fcompi    st(1)
0040bfb9  dbbc24b0000000           fstp      xword ptr [esp + 0xb0]
0040bfc0  8944240c                 mov       dword ptr [esp + 0xc], eax
0040bfc4  895c2408                 mov       dword ptr [esp + 8], ebx
0040bfc8  0f8a23000000             jp        0x40bff1
0040bfce  7721                     ja        0x40bff1
0040bfd0  8d1c0a                   lea       ebx, [edx + ecx]
0040bfd3  dbac24b0000000           fld       xword ptr [esp + 0xb0]
0040bfda  d9049d602e0302           fld       dword ptr [ebx*4 + 0x2032e60]
0040bfe1  dff1                     fcompi    st(1)
0040bfe3  0f8a2b000000             jp        0x40c014
0040bfe9  7329                     jae       0x40c014
0040bfeb  01d1                     add       ecx, edx
0040bfed  01d3                     add       ebx, edx
0040bfef  ebe9                     jmp       0x40bfda
0040bff1  dbac24b0000000           fld       xword ptr [esp + 0xb0]
0040bff8  29d1                     sub       ecx, edx
0040bffa  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0040c001  dff1                     fcompi    st(1)
0040c003  0f8a02000000             jp        0x40c00b
0040c009  77ed                     ja        0x40bff8
0040c00b  dbbc24b0000000           fstp      xword ptr [esp + 0xb0]
0040c012  eb07                     jmp       0x40c01b
0040c014  dbbc24b0000000           fstp      xword ptr [esp + 0xb0]
0040c01b  8b44240c                 mov       eax, dword ptr [esp + 0xc]
0040c01f  890c856c2e0302           mov       dword ptr [eax*4 + 0x2032e6c], ecx
0040c026  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0040c02d  d9048d642e0302           fld       dword ptr [ecx*4 + 0x2032e64]
0040c034  db7c2474                 fstp      xword ptr [esp + 0x74]
0040c038  d9048d6c2e0302           fld       dword ptr [ecx*4 + 0x2032e6c]
0040c03f  d9048d702e0302           fld       dword ptr [ecx*4 + 0x2032e70]
0040c046  89d0                     mov       eax, edx
0040c048  01c8                     add       eax, ecx
0040c04a  89c2                     mov       edx, eax
0040c04c  d90495702e0302           fld       dword ptr [edx*4 + 0x2032e70]
0040c053  dbbc24a4000000           fstp      xword ptr [esp + 0xa4]
0040c05a  d904956c2e0302           fld       dword ptr [edx*4 + 0x2032e6c]
0040c061  dbbc2498000000           fstp      xword ptr [esp + 0x98]
0040c068  d9c2                     fld       st(2)
0040c06a  d82c95602e0302           fsubr     dword ptr [edx*4 + 0x2032e60]
0040c071  db7c245c                 fstp      xword ptr [esp + 0x5c]
0040c075  dbac24b0000000           fld       xword ptr [esp + 0xb0]
0040c07c  dee3                     fsubrp    st(3)
0040c07e  d9ca                     fxch      st(2)
0040c080  db7c2468                 fstp      xword ptr [esp + 0x68]
0040c084  d9e8                     fld1
0040c086  db6c245c                 fld       xword ptr [esp + 0x5c]
0040c08a  d83d60835100             fdivr     dword ptr [0x518360] ; bits=0000803f, f32=1.0
0040c090  db6c2474                 fld       xword ptr [esp + 0x74]
0040c094  d82c95642e0302           fsubr     dword ptr [edx*4 + 0x2032e64]
0040c09b  d8c9                     fmul      st(1)
0040c09d  8b8424d0000000           mov       eax, dword ptr [esp + 0xd0]
0040c0a4  d910                     fst       dword ptr [eax]
0040c0a6  db6c2468                 fld       xword ptr [esp + 0x68]
0040c0aa  dec9                     fmulp     st(1)
0040c0ac  db6c2474                 fld       xword ptr [esp + 0x74]
0040c0b0  dec1                     faddp     st(1)
0040c0b2  8b8424cc000000           mov       eax, dword ptr [esp + 0xcc]
0040c0b9  d910                     fst       dword ptr [eax]
0040c0bb  8d05d8835100             lea       eax, [0x5183d8] ; bits=fa000000, f32=3.5032461608120427e-43
0040c0c1  db6c2468                 fld       xword ptr [esp + 0x68]
0040c0c5  d8488c                   fmul      dword ptr [eax - 0x74]
0040c0c8  db6c2474                 fld       xword ptr [esp + 0x74]
0040c0cc  dec2                     faddp     st(2)
0040c0ce  dec9                     fmulp     st(1)
0040c0d0  8b5c2410                 mov       ebx, dword ptr [esp + 0x10]
0040c0d4  d8048d682e0302           fadd      dword ptr [ecx*4 + 0x2032e68]
0040c0db  d91b                     fstp      dword ptr [ebx]
0040c0dd  db6c2468                 fld       xword ptr [esp + 0x68]
0040c0e1  db6c245c                 fld       xword ptr [esp + 0x5c]
0040c0e5  dbbc248c000000           fstp      xword ptr [esp + 0x8c]
0040c0ec  d9ca                     fxch      st(2)
0040c0ee  dbbc2480000000           fstp      xword ptr [esp + 0x80]
0040c0f5  d9ca                     fxch      st(2)
0040c0f7  8b5c2408                 mov       ebx, dword ptr [esp + 8]
0040c0fb  85db                     test      ebx, ebx
0040c0fd  89442404                 mov       dword ptr [esp + 4], eax
0040c101  754b                     jne       0x40c14e
0040c103  dbac24a4000000           fld       xword ptr [esp + 0xa4]
0040c10a  d8e4                     fsub      st(4)
0040c10c  d8cb                     fmul      st(3)
0040c10e  8b8424e0000000           mov       eax, dword ptr [esp + 0xe0]
0040c115  d910                     fst       dword ptr [eax]
0040c117  d8ca                     fmul      st(2)
0040c119  dec4                     faddp     st(4)
0040c11b  8b8424dc000000           mov       eax, dword ptr [esp + 0xdc]
0040c122  d9cb                     fxch      st(3)
0040c124  d918                     fstp      dword ptr [eax]
0040c126  dbac2498000000           fld       xword ptr [esp + 0x98]
0040c12d  d8e3                     fsub      st(3)
0040c12f  deca                     fmulp     st(2)
0040c131  8b8424d8000000           mov       eax, dword ptr [esp + 0xd8]
0040c138  d9c9                     fxch      st(1)
0040c13a  d910                     fst       dword ptr [eax]
0040c13c  dec9                     fmulp     st(1)
0040c13e  dec1                     faddp     st(1)
0040c140  8b8424d4000000           mov       eax, dword ptr [esp + 0xd4]
0040c147  d918                     fstp      dword ptr [eax]
0040c149  e975010000               jmp       0x40c2c3
0040c14e  db7c2438                 fstp      xword ptr [esp + 0x38]
0040c152  d9ca                     fxch      st(2)
0040c154  db7c2420                 fstp      xword ptr [esp + 0x20]
0040c158  dcc9                     fmul      st(1), st(0)
0040c15a  dbac2480000000           fld       xword ptr [esp + 0x80]
0040c161  d8e2                     fsub      st(2)
0040c163  d9c0                     fld       st(0)
0040c165  d8cb                     fmul      st(3)
0040c167  dbac248c000000           fld       xword ptr [esp + 0x8c]
0040c16e  dec9                     fmulp     st(1)
0040c170  d9c3                     fld       st(3)
0040c172  d8c9                     fmul      st(1)
0040c174  d9e0                     fchs
0040c176  db7c245c                 fstp      xword ptr [esp + 0x5c]
0040c17a  d8c9                     fmul      st(1)
0040c17c  db7c2468                 fstp      xword ptr [esp + 0x68]
0040c180  d9c2                     fld       st(2)
0040c182  d8c0                     fadd      st(0)
0040c184  dbac2480000000           fld       xword ptr [esp + 0x80]
0040c18b  dec1                     faddp     st(1)
0040c18d  8b442404                 mov       eax, dword ptr [esp + 4]
0040c191  d9c0                     fld       st(0)
0040c193  d86894                   fsubr     dword ptr [eax - 0x6c]
0040c196  d8cc                     fmul      st(4)
0040c198  d8cc                     fmul      st(4)
0040c19a  db7c2414                 fstp      xword ptr [esp + 0x14]
0040c19e  d9c1                     fld       st(1)
0040c1a0  d8c8                     fmul      st(0)
0040c1a2  dec9                     fmulp     st(1)
0040c1a4  db7c2474                 fstp      xword ptr [esp + 0x74]
0040c1a8  d9c2                     fld       st(2)
0040c1aa  d84898                   fmul      dword ptr [eax - 0x68]
0040c1ad  dbac2480000000           fld       xword ptr [esp + 0x80]
0040c1b4  dee1                     fsubrp    st(1)
0040c1b6  dbac2480000000           fld       xword ptr [esp + 0x80]
0040c1bd  d8c1                     fadd      st(1)
0040c1bf  d8cc                     fmul      st(4)
0040c1c1  d9e0                     fchs
0040c1c3  db7c2444                 fstp      xword ptr [esp + 0x44]
0040c1c7  d8c9                     fmul      st(1)
0040c1c9  db7c2450                 fstp      xword ptr [esp + 0x50]
0040c1cd  d8489c                   fmul      dword ptr [eax - 0x64]
0040c1d0  deca                     fmulp     st(2)
0040c1d2  dec9                     fmulp     st(1)
0040c1d4  8b442408                 mov       eax, dword ptr [esp + 8]
0040c1d8  db7c242c                 fstp      xword ptr [esp + 0x2c]
0040c1dc  8d1c08                   lea       ebx, [eax + ecx]
0040c1df  01d0                     add       eax, edx
0040c1e1  d9049d602e0302           fld       dword ptr [ebx*4 + 0x2032e60]
0040c1e8  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0040c1ef  d9049d642e0302           fld       dword ptr [ebx*4 + 0x2032e64]
0040c1f6  d90485642e0302           fld       dword ptr [eax*4 + 0x2032e64]
0040c1fd  db6c2468                 fld       xword ptr [esp + 0x68]
0040c201  d80c9d642e0302           fmul      dword ptr [ebx*4 + 0x2032e64]
0040c208  db6c245c                 fld       xword ptr [esp + 0x5c]
0040c20c  d80c85642e0302           fmul      dword ptr [eax*4 + 0x2032e64]
0040c213  dec1                     faddp     st(1)
0040c215  db6c2474                 fld       xword ptr [esp + 0x74]
0040c219  db6c2420                 fld       xword ptr [esp + 0x20]
0040c21d  dec9                     fmulp     st(1)
0040c21f  dec1                     faddp     st(1)
0040c221  dbac24a4000000           fld       xword ptr [esp + 0xa4]
0040c228  db6c2414                 fld       xword ptr [esp + 0x14]
0040c22c  dec9                     fmulp     st(1)
0040c22e  dec1                     faddp     st(1)
0040c230  8b8424dc000000           mov       eax, dword ptr [esp + 0xdc]
0040c237  d918                     fstp      dword ptr [eax]
0040c239  db6c2450                 fld       xword ptr [esp + 0x50]
0040c23d  deca                     fmulp     st(2)
0040c23f  db6c2444                 fld       xword ptr [esp + 0x44]
0040c243  dec9                     fmulp     st(1)
0040c245  dec1                     faddp     st(1)
0040c247  dbac24a4000000           fld       xword ptr [esp + 0xa4]
0040c24e  db6c2420                 fld       xword ptr [esp + 0x20]
0040c252  dee9                     fsubp     st(1)
0040c254  db6c242c                 fld       xword ptr [esp + 0x2c]
0040c258  dec9                     fmulp     st(1)
0040c25a  dec1                     faddp     st(1)
0040c25c  8b8424e0000000           mov       eax, dword ptr [esp + 0xe0]
0040c263  d918                     fstp      dword ptr [eax]
0040c265  db6c2468                 fld       xword ptr [esp + 0x68]
0040c269  d8ca                     fmul      st(2)
0040c26b  db6c245c                 fld       xword ptr [esp + 0x5c]
0040c26f  d8ca                     fmul      st(2)
0040c271  dec1                     faddp     st(1)
0040c273  db6c2474                 fld       xword ptr [esp + 0x74]
0040c277  db6c2438                 fld       xword ptr [esp + 0x38]
0040c27b  dec9                     fmulp     st(1)
0040c27d  dec1                     faddp     st(1)
0040c27f  dbac2498000000           fld       xword ptr [esp + 0x98]
0040c286  db6c2414                 fld       xword ptr [esp + 0x14]
0040c28a  dec9                     fmulp     st(1)
0040c28c  dec1                     faddp     st(1)
0040c28e  8b8424d4000000           mov       eax, dword ptr [esp + 0xd4]
0040c295  d918                     fstp      dword ptr [eax]
0040c297  db6c2450                 fld       xword ptr [esp + 0x50]
0040c29b  deca                     fmulp     st(2)
0040c29d  db6c2444                 fld       xword ptr [esp + 0x44]
0040c2a1  dec9                     fmulp     st(1)
0040c2a3  dec1                     faddp     st(1)
0040c2a5  dbac2498000000           fld       xword ptr [esp + 0x98]
0040c2ac  db6c2438                 fld       xword ptr [esp + 0x38]
0040c2b0  dee9                     fsubp     st(1)
0040c2b2  db6c242c                 fld       xword ptr [esp + 0x2c]
0040c2b6  dec9                     fmulp     st(1)
0040c2b8  dec1                     faddp     st(1)
0040c2ba  8b8424d8000000           mov       eax, dword ptr [esp + 0xd8]
0040c2c1  d918                     fstp      dword ptr [eax]
0040c2c3  8b8424d4000000           mov       eax, dword ptr [esp + 0xd4]
0040c2ca  d900                     fld       dword ptr [eax]
0040c2cc  d9c0                     fld       st(0)
0040c2ce  d800                     fadd      dword ptr [eax]
0040c2d0  8b8c24d8000000           mov       ecx, dword ptr [esp + 0xd8]
0040c2d7  d809                     fmul      dword ptr [ecx]
0040c2d9  d919                     fstp      dword ptr [ecx]
0040c2db  d8c8                     fmul      st(0)
0040c2dd  d918                     fstp      dword ptr [eax]
0040c2df  b800000000               mov       eax, 0
0040c2e4  5b                       pop       ebx
0040c2e5  81c4b8000000             add       esp, 0xb8
0040c2eb  c3                       ret
0040c2ec  8d642400                 lea       esp, [esp]
