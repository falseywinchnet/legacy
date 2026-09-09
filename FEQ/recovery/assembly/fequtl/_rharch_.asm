; _rharch_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xf980
0040f980  55                       push      ebp
0040f981  8bec                     mov       ebp, esp
0040f983  b8a0010000               mov       eax, 0x1a0
0040f988  e873960d00               call      0x4e9000 ; __alloca_probe
0040f98d  53                       push      ebx
0040f98e  56                       push      esi
0040f98f  8b5508                   mov       edx, dword ptr [ebp + 8]
0040f992  8b5d0c                   mov       ebx, dword ptr [ebp + 0xc]
0040f995  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
0040f998  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0040f99b  d900                     fld       dword ptr [eax]
0040f99d  8b7524                   mov       esi, dword ptr [ebp + 0x24]
0040f9a0  d906                     fld       dword ptr [esi]
0040f9a2  d808                     fmul      dword ptr [eax]
0040f9a4  d916                     fst       dword ptr [esi]
0040f9a6  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0040f9a9  d9c1                     fld       st(1)
0040f9ab  d808                     fmul      dword ptr [eax]
0040f9ad  d910                     fst       dword ptr [eax]
0040f9af  d9ee                     fldz
0040f9b1  d9ca                     fxch      st(2)
0040f9b3  d815c4945500             fcom      dword ptr [0x5594c4] ; bits=00000000, f32=0.0
0040f9b9  db7de4                   fstp      xword ptr [ebp - 0x1c]
0040f9bc  d9ca                     fxch      st(2)
0040f9be  db7dd8                   fstp      xword ptr [ebp - 0x28]
0040f9c1  db7dcc                   fstp      xword ptr [ebp - 0x34]
0040f9c4  dfe0                     fnstsw    ax
0040f9c6  9e                       sahf
0040f9c7  89b56cfeffff             mov       dword ptr [ebp - 0x194], esi
0040f9cd  0f8a27020000             jp        0x40fbfa
0040f9d3  0f8621020000             jbe       0x40fbfa
0040f9d9  ddd8                     fstp      st(0)
0040f9db  d901                     fld       dword ptr [ecx]
0040f9dd  db6de4                   fld       xword ptr [ebp - 0x1c]
0040f9e0  d819                     fcomp     dword ptr [ecx]
0040f9e2  db7dc0                   fstp      xword ptr [ebp - 0x40]
0040f9e5  dfe0                     fnstsw    ax
0040f9e7  9e                       sahf
0040f9e8  0f8a28000000             jp        0x40fa16
0040f9ee  7326                     jae       0x40fa16
0040f9f0  db6de4                   fld       xword ptr [ebp - 0x1c]
0040f9f3  d805cc945500             fadd      dword ptr [0x5594cc] ; bits=cdcccc3d, f32=0.10000000149011612
0040f9f9  db6dc0                   fld       xword ptr [ebp - 0x40]
0040f9fc  d9c9                     fxch      st(1)
0040f9fe  ded9                     fcompp
0040fa00  dfe0                     fnstsw    ax
0040fa02  9e                       sahf
0040fa03  0f8a0d000000             jp        0x40fa16
0040fa09  760b                     jbe       0x40fa16
0040fa0b  8b856cfeffff             mov       eax, dword ptr [ebp - 0x194]
0040fa11  db6dc0                   fld       xword ptr [ebp - 0x40]
0040fa14  d918                     fstp      dword ptr [eax]
0040fa16  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040fa19  d900                     fld       dword ptr [eax]
0040fa1b  8b33                     mov       esi, dword ptr [ebx]
0040fa1d  d944b1fc                 fld       dword ptr [ecx + esi*4 - 4]
0040fa21  d9c9                     fxch      st(1)
0040fa23  d854b1fc                 fcom      dword ptr [ecx + esi*4 - 4]
0040fa27  db7db4                   fstp      xword ptr [ebp - 0x4c]
0040fa2a  db7da8                   fstp      xword ptr [ebp - 0x58]
0040fa2d  898568feffff             mov       dword ptr [ebp - 0x198], eax
0040fa33  dfe0                     fnstsw    ax
0040fa35  9e                       sahf
0040fa36  0f8a28000000             jp        0x40fa64
0040fa3c  7626                     jbe       0x40fa64
0040fa3e  db6db4                   fld       xword ptr [ebp - 0x4c]
0040fa41  d825cc945500             fsub      dword ptr [0x5594cc] ; bits=cdcccc3d, f32=0.10000000149011612
0040fa47  db6da8                   fld       xword ptr [ebp - 0x58]
0040fa4a  d9c9                     fxch      st(1)
0040fa4c  ded9                     fcompp
0040fa4e  dfe0                     fnstsw    ax
0040fa50  9e                       sahf
0040fa51  0f8a0d000000             jp        0x40fa64
0040fa57  730b                     jae       0x40fa64
0040fa59  8b8568feffff             mov       eax, dword ptr [ebp - 0x198]
0040fa5f  db6da8                   fld       xword ptr [ebp - 0x58]
0040fa62  d918                     fstp      dword ptr [eax]
0040fa64  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040fa67  d900                     fld       dword ptr [eax]
0040fa69  db6dc0                   fld       xword ptr [ebp - 0x40]
0040fa6c  d9c9                     fxch      st(1)
0040fa6e  d8d1                     fcom      st(1)
0040fa70  ddd9                     fstp      st(1)
0040fa72  db7d9c                   fstp      xword ptr [ebp - 0x64]
0040fa75  dfe0                     fnstsw    ax
0040fa77  9e                       sahf
0040fa78  0f8a02000000             jp        0x40fa80
0040fa7e  7215                     jb        0x40fa95
0040fa80  db6d9c                   fld       xword ptr [ebp - 0x64]
0040fa83  db6da8                   fld       xword ptr [ebp - 0x58]
0040fa86  d9c9                     fxch      st(1)
0040fa88  ded9                     fcompp
0040fa8a  dfe0                     fnstsw    ax
0040fa8c  9e                       sahf
0040fa8d  0f8a5f000000             jp        0x40faf2
0040fa93  765d                     jbe       0x40faf2
0040fa95  8b02                     mov       eax, dword ptr [edx]
0040fa97  db6d9c                   fld       xword ptr [ebp - 0x64]
0040fa9a  db6dd8                   fld       xword ptr [ebp - 0x28]
0040fa9d  def9                     fdivp     st(1)
0040fa9f  db6dc0                   fld       xword ptr [ebp - 0x40]
0040faa2  db6dd8                   fld       xword ptr [ebp - 0x28]
0040faa5  def9                     fdivp     st(1)
0040faa7  db6da8                   fld       xword ptr [ebp - 0x58]
0040faaa  db6dd8                   fld       xword ptr [ebp - 0x28]
0040faad  def9                     fdivp     st(1)
0040faaf  8d0d0c965500             lea       ecx, [0x55960c] ; bits=09020000, f32=7.300764999132297e-43
0040fab5  8945fc                   mov       dword ptr [ebp - 4], eax
0040fab8  8d45fc                   lea       eax, [ebp - 4]
0040fabb  894108                   mov       dword ptr [ecx + 8], eax
0040fabe  d9ca                     fxch      st(2)
0040fac0  d95df8                   fstp      dword ptr [ebp - 8]
0040fac3  8d45f8                   lea       eax, [ebp - 8]
0040fac6  894128                   mov       dword ptr [ecx + 0x28], eax
0040fac9  d95df4                   fstp      dword ptr [ebp - 0xc]
0040facc  8d45f4                   lea       eax, [ebp - 0xc]
0040facf  894134                   mov       dword ptr [ecx + 0x34], eax
0040fad2  d95df0                   fstp      dword ptr [ebp - 0x10]
0040fad5  8d45f0                   lea       eax, [ebp - 0x10]
0040fad8  894140                   mov       dword ptr [ecx + 0x40], eax
0040fadb  51                       push      ecx
0040fadc  e80f2b0900               call      0x4a25f0 ; _jwe_isfm
0040fae1  83c404                   add       esp, 4
0040fae4  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
0040fae7  c70001000000             mov       dword ptr [eax], 1
0040faed  e9350c0000               jmp       0x410727
0040faf2  bb01000000               mov       ebx, 1
0040faf7  db6d9c                   fld       xword ptr [ebp - 0x64]
0040fafa  eb02                     jmp       0x40fafe
0040fafc  ddd9                     fstp      st(1)
0040fafe  43                       inc       ebx
0040faff  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
0040fb03  d8d1                     fcom      st(1)
0040fb05  d9c9                     fxch      st(1)
0040fb07  dfe0                     fnstsw    ax
0040fb09  9e                       sahf
0040fb0a  0f8a02000000             jp        0x40fb12
0040fb10  72ea                     jb        0x40fafc
0040fb12  ddd8                     fstp      st(0)
0040fb14  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040fb17  d94499f8                 fld       dword ptr [ecx + ebx*4 - 8]
0040fb1b  d9c0                     fld       st(0)
0040fb1d  d828                     fsubr     dword ptr [eax]
0040fb1f  d9ca                     fxch      st(2)
0040fb21  dee1                     fsubrp    st(1)
0040fb23  def9                     fdivp     st(1)
0040fb25  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0040fb28  d94498f8                 fld       dword ptr [eax + ebx*4 - 8]
0040fb2c  d9c0                     fld       st(0)
0040fb2e  d86c98fc                 fsubr     dword ptr [eax + ebx*4 - 4]
0040fb32  d8ca                     fmul      st(2)
0040fb34  dec1                     faddp     st(1)
0040fb36  db7d90                   fstp      xword ptr [ebp - 0x70]
0040fb39  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0040fb3c  d900                     fld       dword ptr [eax]
0040fb3e  d815c4945500             fcom      dword ptr [0x5594c4] ; bits=00000000, f32=0.0
0040fb44  db7d84                   fstp      xword ptr [ebp - 0x7c]
0040fb47  dbbd78ffffff             fstp      xword ptr [ebp - 0x88]
0040fb4d  dfe0                     fnstsw    ax
0040fb4f  9e                       sahf
0040fb50  0f8a5d000000             jp        0x40fbb3
0040fb56  765b                     jbe       0x40fbb3
0040fb58  db6d84                   fld       xword ptr [ebp - 0x7c]
0040fb5b  db6d90                   fld       xword ptr [ebp - 0x70]
0040fb5e  dee9                     fsubp     st(1)
0040fb60  d9e1                     fabs
0040fb62  db6d90                   fld       xword ptr [ebp - 0x70]
0040fb65  def9                     fdivp     st(1)
0040fb67  d81dd8945500             fcomp     dword ptr [0x5594d8] ; bits=0ad7a33c, f32=0.019999999552965164
0040fb6d  dfe0                     fnstsw    ax
0040fb6f  9e                       sahf
0040fb70  0f8a3d000000             jp        0x40fbb3
0040fb76  763b                     jbe       0x40fbb3
0040fb78  8b02                     mov       eax, dword ptr [edx]
0040fb7a  8b4d20                   mov       ecx, dword ptr [ebp + 0x20]
0040fb7d  db6d84                   fld       xword ptr [ebp - 0x7c]
0040fb80  d831                     fdiv      dword ptr [ecx]
0040fb82  db6d90                   fld       xword ptr [ebp - 0x70]
0040fb85  d831                     fdiv      dword ptr [ecx]
0040fb87  8d0dd4955500             lea       ecx, [0x5595d4] ; bits=09020000, f32=7.300764999132297e-43
0040fb8d  8945fc                   mov       dword ptr [ebp - 4], eax
0040fb90  8d45fc                   lea       eax, [ebp - 4]
0040fb93  894108                   mov       dword ptr [ecx + 8], eax
0040fb96  d9c9                     fxch      st(1)
0040fb98  d95df8                   fstp      dword ptr [ebp - 8]
0040fb9b  8d45f8                   lea       eax, [ebp - 8]
0040fb9e  894128                   mov       dword ptr [ecx + 0x28], eax
0040fba1  d95df4                   fstp      dword ptr [ebp - 0xc]
0040fba4  8d45f4                   lea       eax, [ebp - 0xc]
0040fba7  894134                   mov       dword ptr [ecx + 0x34], eax
0040fbaa  51                       push      ecx
0040fbab  e8402a0900               call      0x4a25f0 ; _jwe_isfm
0040fbb0  83c404                   add       esp, 4
0040fbb3  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0040fbb6  db6d90                   fld       xword ptr [ebp - 0x70]
0040fbb9  d918                     fstp      dword ptr [eax]
0040fbbb  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0040fbbe  d94498f8                 fld       dword ptr [eax + ebx*4 - 8]
0040fbc2  d9c0                     fld       st(0)
0040fbc4  d86c98fc                 fsubr     dword ptr [eax + ebx*4 - 4]
0040fbc8  dbad78ffffff             fld       xword ptr [ebp - 0x88]
0040fbce  dec9                     fmulp     st(1)
0040fbd0  dec1                     faddp     st(1)
0040fbd2  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
0040fbd8  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0040fbdb  d94498f8                 fld       dword ptr [eax + ebx*4 - 8]
0040fbdf  d9c0                     fld       st(0)
0040fbe1  d86c98fc                 fsubr     dword ptr [eax + ebx*4 - 4]
0040fbe5  dbad78ffffff             fld       xword ptr [ebp - 0x88]
0040fbeb  dec9                     fmulp     st(1)
0040fbed  dec1                     faddp     st(1)
0040fbef  dbbd60ffffff             fstp      xword ptr [ebp - 0xa0]
0040fbf5  e9f6010000               jmp       0x40fdf0
0040fbfa  db6dcc                   fld       xword ptr [ebp - 0x34]
0040fbfd  d9c9                     fxch      st(1)
0040fbff  d8d1                     fcom      st(1)
0040fc01  ddd9                     fstp      st(1)
0040fc03  dfe0                     fnstsw    ax
0040fc05  9e                       sahf
0040fc06  0f8ab9010000             jp        0x40fdc5
0040fc0c  0f86b3010000             jbe       0x40fdc5
0040fc12  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0040fc15  d900                     fld       dword ptr [eax]
0040fc17  d9c9                     fxch      st(1)
0040fc19  d810                     fcom      dword ptr [eax]
0040fc1b  d9c9                     fxch      st(1)
0040fc1d  dbbd54ffffff             fstp      xword ptr [ebp - 0xac]
0040fc23  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
0040fc29  dfe0                     fnstsw    ax
0040fc2b  9e                       sahf
0040fc2c  0f8a02000000             jp        0x40fc34
0040fc32  721b                     jb        0x40fc4f
0040fc34  8bb560feffff             mov       esi, dword ptr [ebp - 0x1a0]
0040fc3a  8b03                     mov       eax, dword ptr [ebx]
0040fc3c  d85486fc                 fcom      dword ptr [esi + eax*4 - 4]
0040fc40  dfe0                     fnstsw    ax
0040fc42  9e                       sahf
0040fc43  0f8afe000000             jp        0x40fd47
0040fc49  0f86f8000000             jbe       0x40fd47
0040fc4f  dbad54ffffff             fld       xword ptr [ebp - 0xac]
0040fc55  d9c9                     fxch      st(1)
0040fc57  d8d1                     fcom      st(1)
0040fc59  ddd9                     fstp      st(1)
0040fc5b  dfe0                     fnstsw    ax
0040fc5d  9e                       sahf
0040fc5e  0f8a2a000000             jp        0x40fc8e
0040fc64  7328                     jae       0x40fc8e
0040fc66  d805cc945500             fadd      dword ptr [0x5594cc] ; bits=cdcccc3d, f32=0.10000000149011612
0040fc6c  dbad54ffffff             fld       xword ptr [ebp - 0xac]
0040fc72  d9c9                     fxch      st(1)
0040fc74  ded9                     fcompp
0040fc76  dfe0                     fnstsw    ax
0040fc78  9e                       sahf
0040fc79  0f8a11000000             jp        0x40fc90
0040fc7f  760f                     jbe       0x40fc90
0040fc81  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0040fc84  dbad54ffffff             fld       xword ptr [ebp - 0xac]
0040fc8a  d918                     fstp      dword ptr [eax]
0040fc8c  eb02                     jmp       0x40fc90
0040fc8e  ddd8                     fstp      st(0)
0040fc90  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0040fc93  d901                     fld       dword ptr [ecx]
0040fc95  8b03                     mov       eax, dword ptr [ebx]
0040fc97  8b7514                   mov       esi, dword ptr [ebp + 0x14]
0040fc9a  d94486fc                 fld       dword ptr [esi + eax*4 - 4]
0040fc9e  d9c9                     fxch      st(1)
0040fca0  d85486fc                 fcom      dword ptr [esi + eax*4 - 4]
0040fca4  dbbd48ffffff             fstp      xword ptr [ebp - 0xb8]
0040fcaa  dbbd3cffffff             fstp      xword ptr [ebp - 0xc4]
0040fcb0  dfe0                     fnstsw    ax
0040fcb2  9e                       sahf
0040fcb3  0f8a2b000000             jp        0x40fce4
0040fcb9  7629                     jbe       0x40fce4
0040fcbb  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
0040fcc1  d825cc945500             fsub      dword ptr [0x5594cc] ; bits=cdcccc3d, f32=0.10000000149011612
0040fcc7  dbad3cffffff             fld       xword ptr [ebp - 0xc4]
0040fccd  d9c9                     fxch      st(1)
0040fccf  ded9                     fcompp
0040fcd1  dfe0                     fnstsw    ax
0040fcd3  9e                       sahf
0040fcd4  0f8a0a000000             jp        0x40fce4
0040fcda  7308                     jae       0x40fce4
0040fcdc  dbad3cffffff             fld       xword ptr [ebp - 0xc4]
0040fce2  d919                     fstp      dword ptr [ecx]
0040fce4  8b02                     mov       eax, dword ptr [edx]
0040fce6  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0040fce9  db6dd8                   fld       xword ptr [ebp - 0x28]
0040fcec  d839                     fdivr     dword ptr [ecx]
0040fcee  dbad54ffffff             fld       xword ptr [ebp - 0xac]
0040fcf4  db6dd8                   fld       xword ptr [ebp - 0x28]
0040fcf7  def9                     fdivp     st(1)
0040fcf9  dbad3cffffff             fld       xword ptr [ebp - 0xc4]
0040fcff  db6dd8                   fld       xword ptr [ebp - 0x28]
0040fd02  def9                     fdivp     st(1)
0040fd04  8d0d90955500             lea       ecx, [0x559590] ; bits=09020000, f32=7.300764999132297e-43
0040fd0a  8945fc                   mov       dword ptr [ebp - 4], eax
0040fd0d  8d45fc                   lea       eax, [ebp - 4]
0040fd10  894108                   mov       dword ptr [ecx + 8], eax
0040fd13  d9ca                     fxch      st(2)
0040fd15  d95df8                   fstp      dword ptr [ebp - 8]
0040fd18  8d45f8                   lea       eax, [ebp - 8]
0040fd1b  894128                   mov       dword ptr [ecx + 0x28], eax
0040fd1e  d95df4                   fstp      dword ptr [ebp - 0xc]
0040fd21  8d45f4                   lea       eax, [ebp - 0xc]
0040fd24  894134                   mov       dword ptr [ecx + 0x34], eax
0040fd27  d95df0                   fstp      dword ptr [ebp - 0x10]
0040fd2a  8d45f0                   lea       eax, [ebp - 0x10]
0040fd2d  894140                   mov       dword ptr [ecx + 0x40], eax
0040fd30  51                       push      ecx
0040fd31  e8ba280900               call      0x4a25f0 ; _jwe_isfm
0040fd36  83c404                   add       esp, 4
0040fd39  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
0040fd3c  c70001000000             mov       dword ptr [eax], 1
0040fd42  e9e0090000               jmp       0x410727
0040fd47  bb01000000               mov       ebx, 1
0040fd4c  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
0040fd52  89c2                     mov       edx, eax
0040fd54  eb02                     jmp       0x40fd58
0040fd56  ddd9                     fstp      st(1)
0040fd58  43                       inc       ebx
0040fd59  d9449afc                 fld       dword ptr [edx + ebx*4 - 4]
0040fd5d  d8d1                     fcom      st(1)
0040fd5f  d9c9                     fxch      st(1)
0040fd61  dfe0                     fnstsw    ax
0040fd63  9e                       sahf
0040fd64  0f8a02000000             jp        0x40fd6c
0040fd6a  72ea                     jb        0x40fd56
0040fd6c  ddd8                     fstp      st(0)
0040fd6e  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0040fd71  8b5514                   mov       edx, dword ptr [ebp + 0x14]
0040fd74  d9449af8                 fld       dword ptr [edx + ebx*4 - 8]
0040fd78  d9c0                     fld       st(0)
0040fd7a  d828                     fsubr     dword ptr [eax]
0040fd7c  d9ca                     fxch      st(2)
0040fd7e  dee1                     fsubrp    st(1)
0040fd80  def9                     fdivp     st(1)
0040fd82  d94499f8                 fld       dword ptr [ecx + ebx*4 - 8]
0040fd86  d9c0                     fld       st(0)
0040fd88  d86c99fc                 fsubr     dword ptr [ecx + ebx*4 - 4]
0040fd8c  d8ca                     fmul      st(2)
0040fd8e  dec1                     faddp     st(1)
0040fd90  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040fd93  d918                     fstp      dword ptr [eax]
0040fd95  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0040fd98  d94498f8                 fld       dword ptr [eax + ebx*4 - 8]
0040fd9c  d9c0                     fld       st(0)
0040fd9e  d86c98fc                 fsubr     dword ptr [eax + ebx*4 - 4]
0040fda2  d8ca                     fmul      st(2)
0040fda4  dec1                     faddp     st(1)
0040fda6  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
0040fdac  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0040fdaf  d94498f8                 fld       dword ptr [eax + ebx*4 - 8]
0040fdb3  d9c0                     fld       st(0)
0040fdb5  d86c98fc                 fsubr     dword ptr [eax + ebx*4 - 4]
0040fdb9  deca                     fmulp     st(2)
0040fdbb  dec1                     faddp     st(1)
0040fdbd  dbbd60ffffff             fstp      xword ptr [ebp - 0xa0]
0040fdc3  eb2b                     jmp       0x40fdf0
0040fdc5  ddd8                     fstp      st(0)
0040fdc7  8b02                     mov       eax, dword ptr [edx]
0040fdc9  8d1d28955500             lea       ebx, [0x559528] ; bits=0b000000, f32=1.5414283107572988e-44
0040fdcf  8d4b48                   lea       ecx, [ebx + 0x48]
0040fdd2  8945fc                   mov       dword ptr [ebp - 4], eax
0040fdd5  8d45fc                   lea       eax, [ebp - 4]
0040fdd8  894108                   mov       dword ptr [ecx + 8], eax
0040fddb  51                       push      ecx
0040fddc  e80f280900               call      0x4a25f0 ; _jwe_isfm
0040fde1  83c404                   add       esp, 4
0040fde4  8d5b3c                   lea       ebx, [ebx + 0x3c]
0040fde7  53                       push      ebx
0040fde8  e853360900               call      0x4a3440 ; _jwe_xstp
0040fded  83c404                   add       esp, 4
0040fdf0  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040fdf3  db6dd8                   fld       xword ptr [ebp - 0x28]
0040fdf6  d838                     fdivr     dword ptr [eax]
0040fdf8  d918                     fstp      dword ptr [eax]
0040fdfa  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0040fdfd  db6dd8                   fld       xword ptr [ebp - 0x28]
0040fe00  d839                     fdivr     dword ptr [ecx]
0040fe02  d911                     fst       dword ptr [ecx]
0040fe04  8b4d20                   mov       ecx, dword ptr [ebp + 0x20]
0040fe07  d901                     fld       dword ptr [ecx]
0040fe09  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0040fe0f  d831                     fdiv      dword ptr [ecx]
0040fe11  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
0040fe17  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0040fe1d  def1                     fdivrp    st(1)
0040fe1f  dbbd60ffffff             fstp      xword ptr [ebp - 0xa0]
0040fe25  8d1d28955500             lea       ebx, [0x559528] ; bits=0b000000, f32=1.5414283107572988e-44
0040fe2b  d84bc4                   fmul      dword ptr [ebx - 0x3c]
0040fe2e  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0040fe34  dee9                     fsubp     st(1)
0040fe36  dbbd30ffffff             fstp      xword ptr [ebp - 0xd0]
0040fe3c  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0040fe42  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0040fe48  dee9                     fsubp     st(1)
0040fe4a  dbbd24ffffff             fstp      xword ptr [ebp - 0xdc]
0040fe50  dbad24ffffff             fld       xword ptr [ebp - 0xdc]
0040fe56  dbad24ffffff             fld       xword ptr [ebp - 0xdc]
0040fe5c  dec9                     fmulp     st(1)
0040fe5e  dbbd18ffffff             fstp      xword ptr [ebp - 0xe8]
0040fe64  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
0040fe6a  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
0040fe70  dec9                     fmulp     st(1)
0040fe72  dbbd0cffffff             fstp      xword ptr [ebp - 0xf4]
0040fe78  dbad18ffffff             fld       xword ptr [ebp - 0xe8]
0040fe7e  dbad0cffffff             fld       xword ptr [ebp - 0xf4]
0040fe84  dee9                     fsubp     st(1)
0040fe86  d9fa                     fsqrt
0040fe88  d95df8                   fstp      dword ptr [ebp - 8]
0040fe8b  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0040fe91  d865f8                   fsub      dword ptr [ebp - 8]
0040fe94  dbbd00ffffff             fstp      xword ptr [ebp - 0x100]
0040fe9a  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0040fea0  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0040fea6  dec9                     fmulp     st(1)
0040fea8  dbbdf4feffff             fstp      xword ptr [ebp - 0x10c]
0040feae  dbadf4feffff             fld       xword ptr [ebp - 0x10c]
0040feb4  dbad0cffffff             fld       xword ptr [ebp - 0xf4]
0040feba  dee9                     fsubp     st(1)
0040febc  d900                     fld       dword ptr [eax]
0040febe  dbad00ffffff             fld       xword ptr [ebp - 0x100]
0040fec4  d828                     fsubr     dword ptr [eax]
0040fec6  d8c8                     fmul      st(0)
0040fec8  deea                     fsubp     st(2)
0040feca  dbad00ffffff             fld       xword ptr [ebp - 0x100]
0040fed0  d820                     fsub      dword ptr [eax]
0040fed2  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0040fed8  dec1                     faddp     st(1)
0040feda  d8c0                     fadd      st(0)
0040fedc  defa                     fdivp     st(2)
0040fede  d9c9                     fxch      st(1)
0040fee0  dbbde8feffff             fstp      xword ptr [ebp - 0x118]
0040fee6  dbade8feffff             fld       xword ptr [ebp - 0x118]
0040feec  dee9                     fsubp     st(1)
0040feee  8b753c                   mov       esi, dword ptr [ebp + 0x3c]
0040fef1  d91e                     fstp      dword ptr [esi]
0040fef3  dbade8feffff             fld       xword ptr [ebp - 0x118]
0040fef9  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0040feff  dee9                     fsubp     st(1)
0040ff01  dbbddcfeffff             fstp      xword ptr [ebp - 0x124]
0040ff07  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
0040ff0d  dbaddcfeffff             fld       xword ptr [ebp - 0x124]
0040ff13  def9                     fdivp     st(1)
0040ff15  d95df8                   fstp      dword ptr [ebp - 8]
0040ff18  8d45f8                   lea       eax, [ebp - 8]
0040ff1b  50                       push      eax
0040ff1c  e86f100900               call      0x4a0f90 ; _g_asin
0040ff21  dbbdd0feffff             fstp      xword ptr [ebp - 0x130]
0040ff27  83c404                   add       esp, 4
0040ff2a  d906                     fld       dword ptr [esi]
0040ff2c  dbad00ffffff             fld       xword ptr [ebp - 0x100]
0040ff32  d9c9                     fxch      st(1)
0040ff34  ded9                     fcompp
0040ff36  dfe0                     fnstsw    ax
0040ff38  9e                       sahf
0040ff39  0f8a1c000000             jp        0x40ff5b
0040ff3f  761a                     jbe       0x40ff5b
0040ff41  dbadd0feffff             fld       xword ptr [ebp - 0x130]
0040ff47  d943d8                   fld       dword ptr [ebx - 0x28]
0040ff4a  dbbdc4feffff             fstp      xword ptr [ebp - 0x13c]
0040ff50  d86bbc                   fsubr     dword ptr [ebx - 0x44]
0040ff53  dbbdd0feffff             fstp      xword ptr [ebp - 0x130]
0040ff59  eb08                     jmp       0x40ff63
0040ff5b  d9e8                     fld1
0040ff5d  dbbdc4feffff             fstp      xword ptr [ebp - 0x13c]
0040ff63  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
0040ff69  dbad24ffffff             fld       xword ptr [ebp - 0xdc]
0040ff6f  def9                     fdivp     st(1)
0040ff71  d95df8                   fstp      dword ptr [ebp - 8]
0040ff74  8d45f8                   lea       eax, [ebp - 8]
0040ff77  50                       push      eax
0040ff78  e813100900               call      0x4a0f90 ; _g_asin
0040ff7d  dbbdb8feffff             fstp      xword ptr [ebp - 0x148]
0040ff83  83c404                   add       esp, 4
0040ff86  8d0528955500             lea       eax, [0x559528] ; bits=0b000000, f32=1.5414283107572988e-44
0040ff8c  dbadd0feffff             fld       xword ptr [ebp - 0x130]
0040ff92  d868c0                   fsubr     dword ptr [eax - 0x40]
0040ff95  dbadb8feffff             fld       xword ptr [ebp - 0x148]
0040ff9b  dee9                     fsubp     st(1)
0040ff9d  dbbdacfeffff             fstp      xword ptr [ebp - 0x154]
0040ffa3  dbade8feffff             fld       xword ptr [ebp - 0x118]
0040ffa9  dbade8feffff             fld       xword ptr [ebp - 0x118]
0040ffaf  dec9                     fmulp     st(1)
0040ffb1  dbadd0feffff             fld       xword ptr [ebp - 0x130]
0040ffb7  dec9                     fmulp     st(1)
0040ffb9  dbadc4feffff             fld       xword ptr [ebp - 0x13c]
0040ffbf  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
0040ffc5  dec9                     fmulp     st(1)
0040ffc7  dbaddcfeffff             fld       xword ptr [ebp - 0x124]
0040ffcd  dbaddcfeffff             fld       xword ptr [ebp - 0x124]
0040ffd3  dec9                     fmulp     st(1)
0040ffd5  dbad0cffffff             fld       xword ptr [ebp - 0xf4]
0040ffdb  dee9                     fsubp     st(1)
0040ffdd  d9fa                     fsqrt
0040ffdf  d95df8                   fstp      dword ptr [ebp - 8]
0040ffe2  d84df8                   fmul      dword ptr [ebp - 8]
0040ffe5  dee9                     fsubp     st(1)
0040ffe7  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0040ffed  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0040fff3  dec1                     faddp     st(1)
0040fff5  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0040fffb  dee9                     fsubp     st(1)
0040fffd  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
00410003  dec9                     fmulp     st(1)
00410005  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0041000b  dbad00ffffff             fld       xword ptr [ebp - 0x100]
00410011  dee9                     fsubp     st(1)
00410013  dcc9                     fmul      st(1), st(0)
00410015  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0041001b  deca                     fmulp     st(2)
0041001d  dbad18ffffff             fld       xword ptr [ebp - 0xe8]
00410023  defa                     fdivp     st(2)
00410025  d9c9                     fxch      st(1)
00410027  dec2                     faddp     st(2)
00410029  dbadf4feffff             fld       xword ptr [ebp - 0x10c]
0041002f  dbadacfeffff             fld       xword ptr [ebp - 0x154]
00410035  dec9                     fmulp     st(1)
00410037  dec2                     faddp     st(2)
00410039  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0041003f  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00410045  dec9                     fmulp     st(1)
00410047  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
0041004d  deca                     fmulp     st(2)
0041004f  dbad18ffffff             fld       xword ptr [ebp - 0xe8]
00410055  defa                     fdivp     st(2)
00410057  dbadb8feffff             fld       xword ptr [ebp - 0x148]
0041005d  dee2                     fsubrp    st(2)
0041005f  dec9                     fmulp     st(1)
00410061  dec1                     faddp     st(1)
00410063  d848c4                   fmul      dword ptr [eax - 0x3c]
00410066  dbbda0feffff             fstp      xword ptr [ebp - 0x160]
0041006c  d9ee                     fldz
0041006e  d9fb                     fsincos
00410070  dbade8feffff             fld       xword ptr [ebp - 0x118]
00410076  deca                     fmulp     st(2)
00410078  8b4d34                   mov       ecx, dword ptr [ebp + 0x34]
0041007b  d9c9                     fxch      st(1)
0041007d  d919                     fstp      dword ptr [ecx]
0041007f  dbade8feffff             fld       xword ptr [ebp - 0x118]
00410085  dec9                     fmulp     st(1)
00410087  8b5538                   mov       edx, dword ptr [ebp + 0x38]
0041008a  d91a                     fstp      dword ptr [edx]
0041008c  d940ac                   fld       dword ptr [eax - 0x54]
0041008f  dbadd0feffff             fld       xword ptr [ebp - 0x130]
00410095  d848ac                   fmul      dword ptr [eax - 0x54]
00410098  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
0041009e  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
004100a4  d9fb                     fsincos
004100a6  dbade8feffff             fld       xword ptr [ebp - 0x118]
004100ac  deca                     fmulp     st(2)
004100ae  d9c9                     fxch      st(1)
004100b0  d95904                   fstp      dword ptr [ecx + 4]
004100b3  dbade8feffff             fld       xword ptr [ebp - 0x118]
004100b9  dec9                     fmulp     st(1)
004100bb  d95a04                   fstp      dword ptr [edx + 4]
004100be  dbadd0feffff             fld       xword ptr [ebp - 0x130]
004100c4  dbadd0feffff             fld       xword ptr [ebp - 0x130]
004100ca  dec1                     faddp     st(1)
004100cc  d8c9                     fmul      st(1)
004100ce  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
004100d4  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
004100da  d9fb                     fsincos
004100dc  dbade8feffff             fld       xword ptr [ebp - 0x118]
004100e2  deca                     fmulp     st(2)
004100e4  d9c9                     fxch      st(1)
004100e6  d95908                   fstp      dword ptr [ecx + 8]
004100e9  dbade8feffff             fld       xword ptr [ebp - 0x118]
004100ef  dec9                     fmulp     st(1)
004100f1  d95a08                   fstp      dword ptr [edx + 8]
004100f4  dbadd0feffff             fld       xword ptr [ebp - 0x130]
004100fa  d84890                   fmul      dword ptr [eax - 0x70]
004100fd  d8c9                     fmul      st(1)
004100ff  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410105  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
0041010b  d9fb                     fsincos
0041010d  dbade8feffff             fld       xword ptr [ebp - 0x118]
00410113  deca                     fmulp     st(2)
00410115  d9c9                     fxch      st(1)
00410117  d9590c                   fstp      dword ptr [ecx + 0xc]
0041011a  dbade8feffff             fld       xword ptr [ebp - 0x118]
00410120  dec9                     fmulp     st(1)
00410122  d95a0c                   fstp      dword ptr [edx + 0xc]
00410125  dbadd0feffff             fld       xword ptr [ebp - 0x130]
0041012b  d84894                   fmul      dword ptr [eax - 0x6c]
0041012e  d8c9                     fmul      st(1)
00410130  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410136  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
0041013c  d9fb                     fsincos
0041013e  dbade8feffff             fld       xword ptr [ebp - 0x118]
00410144  deca                     fmulp     st(2)
00410146  d9c9                     fxch      st(1)
00410148  d95910                   fstp      dword ptr [ecx + 0x10]
0041014b  dbade8feffff             fld       xword ptr [ebp - 0x118]
00410151  dec9                     fmulp     st(1)
00410153  d95a10                   fstp      dword ptr [edx + 0x10]
00410156  dbadd0feffff             fld       xword ptr [ebp - 0x130]
0041015c  d848d4                   fmul      dword ptr [eax - 0x2c]
0041015f  d8c9                     fmul      st(1)
00410161  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410167  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
0041016d  d9fb                     fsincos
0041016f  dbade8feffff             fld       xword ptr [ebp - 0x118]
00410175  deca                     fmulp     st(2)
00410177  d9c9                     fxch      st(1)
00410179  d95914                   fstp      dword ptr [ecx + 0x14]
0041017c  dbade8feffff             fld       xword ptr [ebp - 0x118]
00410182  dec9                     fmulp     st(1)
00410184  d95a14                   fstp      dword ptr [edx + 0x14]
00410187  dbadd0feffff             fld       xword ptr [ebp - 0x130]
0041018d  d8488c                   fmul      dword ptr [eax - 0x74]
00410190  d8c9                     fmul      st(1)
00410192  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410198  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
0041019e  d9fb                     fsincos
004101a0  dbade8feffff             fld       xword ptr [ebp - 0x118]
004101a6  deca                     fmulp     st(2)
004101a8  d9c9                     fxch      st(1)
004101aa  d95918                   fstp      dword ptr [ecx + 0x18]
004101ad  dbade8feffff             fld       xword ptr [ebp - 0x118]
004101b3  dec9                     fmulp     st(1)
004101b5  d95a18                   fstp      dword ptr [edx + 0x18]
004101b8  dbadd0feffff             fld       xword ptr [ebp - 0x130]
004101be  d84888                   fmul      dword ptr [eax - 0x78]
004101c1  dec9                     fmulp     st(1)
004101c3  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
004101c9  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
004101cf  d9fb                     fsincos
004101d1  dbade8feffff             fld       xword ptr [ebp - 0x118]
004101d7  deca                     fmulp     st(2)
004101d9  d9c9                     fxch      st(1)
004101db  d9591c                   fstp      dword ptr [ecx + 0x1c]
004101de  dbade8feffff             fld       xword ptr [ebp - 0x118]
004101e4  dec9                     fmulp     st(1)
004101e6  d95a1c                   fstp      dword ptr [edx + 0x1c]
004101e9  d940cc                   fld       dword ptr [eax - 0x34]
004101ec  dbbd94feffff             fstp      xword ptr [ebp - 0x16c]
004101f2  bb09000000               mov       ebx, 9
004101f7  dbad94feffff             fld       xword ptr [ebp - 0x16c]
004101fd  dbade8feffff             fld       xword ptr [ebp - 0x118]
00410203  dbadd0feffff             fld       xword ptr [ebp - 0x130]
00410209  d9c2                     fld       st(2)
0041020b  d8c9                     fmul      st(1)
0041020d  d80dd4945500             fmul      dword ptr [0x5594d4] ; bits=398ee33d, f32=0.1111111119389534
00410213  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410219  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
0041021f  d9fb                     fsincos
00410221  d9c9                     fxch      st(1)
00410223  d8cb                     fmul      st(3)
00410225  d9c9                     fxch      st(1)
00410227  d8cb                     fmul      st(3)
00410229  d9c9                     fxch      st(1)
0041022b  d95c99fc                 fstp      dword ptr [ecx + ebx*4 - 4]
0041022f  d95c9afc                 fstp      dword ptr [edx + ebx*4 - 4]
00410233  d9ca                     fxch      st(2)
00410235  d805e0945500             fadd      dword ptr [0x5594e0] ; bits=0000803f, f32=1.0
0041023b  d9ca                     fxch      st(2)
0041023d  43                       inc       ebx
0041023e  83fb0b                   cmp       ebx, 0xb
00410241  7cc6                     jl        0x410209
00410243  ddd9                     fstp      st(1)
00410245  ddd9                     fstp      st(1)
00410247  8d1d28955500             lea       ebx, [0x559528] ; bits=0b000000, f32=1.5414283107572988e-44
0041024d  dbadacfeffff             fld       xword ptr [ebp - 0x154]
00410253  d84ba8                   fmul      dword ptr [ebx - 0x58]
00410256  dbbd88feffff             fstp      xword ptr [ebp - 0x178]
0041025c  d86bd0                   fsubr     dword ptr [ebx - 0x30]
0041025f  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410265  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
00410268  d900                     fld       dword ptr [eax]
0041026a  dbad00ffffff             fld       xword ptr [ebp - 0x100]
00410270  d820                     fsub      dword ptr [eax]
00410272  dbad88feffff             fld       xword ptr [ebp - 0x178]
00410278  d82d50965500             fsubr     dword ptr [0x559650] ; bits=00000000, f32=0.0
0041027e  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410284  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
0041028a  d9c0                     fld       st(0)
0041028c  d9fb                     fsincos
0041028e  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00410294  dec9                     fmulp     st(1)
00410296  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
0041029c  dec1                     faddp     st(1)
0041029e  8b4d34                   mov       ecx, dword ptr [ebp + 0x34]
004102a1  d95928                   fstp      dword ptr [ecx + 0x28]
004102a4  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004102aa  dec9                     fmulp     st(1)
004102ac  d8c2                     fadd      st(2)
004102ae  8b5538                   mov       edx, dword ptr [ebp + 0x38]
004102b1  d95a28                   fstp      dword ptr [edx + 0x28]
004102b4  dbad88feffff             fld       xword ptr [ebp - 0x178]
004102ba  dee9                     fsubp     st(1)
004102bc  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
004102c2  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
004102c8  d9c0                     fld       st(0)
004102ca  d9fb                     fsincos
004102cc  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004102d2  dec9                     fmulp     st(1)
004102d4  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
004102da  dec1                     faddp     st(1)
004102dc  d9592c                   fstp      dword ptr [ecx + 0x2c]
004102df  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004102e5  dec9                     fmulp     st(1)
004102e7  d8c2                     fadd      st(2)
004102e9  d95a2c                   fstp      dword ptr [edx + 0x2c]
004102ec  dbad88feffff             fld       xword ptr [ebp - 0x178]
004102f2  dee9                     fsubp     st(1)
004102f4  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
004102fa  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
00410300  d9c0                     fld       st(0)
00410302  d9fb                     fsincos
00410304  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0041030a  dec9                     fmulp     st(1)
0041030c  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
00410312  dec1                     faddp     st(1)
00410314  d95930                   fstp      dword ptr [ecx + 0x30]
00410317  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0041031d  dec9                     fmulp     st(1)
0041031f  d8c2                     fadd      st(2)
00410321  d95a30                   fstp      dword ptr [edx + 0x30]
00410324  dbad88feffff             fld       xword ptr [ebp - 0x178]
0041032a  dee9                     fsubp     st(1)
0041032c  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410332  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
00410338  d9c0                     fld       st(0)
0041033a  d9fb                     fsincos
0041033c  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00410342  dec9                     fmulp     st(1)
00410344  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
0041034a  dec1                     faddp     st(1)
0041034c  d95934                   fstp      dword ptr [ecx + 0x34]
0041034f  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00410355  dec9                     fmulp     st(1)
00410357  d8c2                     fadd      st(2)
00410359  d95a34                   fstp      dword ptr [edx + 0x34]
0041035c  dbad88feffff             fld       xword ptr [ebp - 0x178]
00410362  dee9                     fsubp     st(1)
00410364  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
0041036a  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
00410370  d9c0                     fld       st(0)
00410372  d9fb                     fsincos
00410374  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0041037a  dec9                     fmulp     st(1)
0041037c  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
00410382  dec1                     faddp     st(1)
00410384  d95938                   fstp      dword ptr [ecx + 0x38]
00410387  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0041038d  dec9                     fmulp     st(1)
0041038f  d8c2                     fadd      st(2)
00410391  d95a38                   fstp      dword ptr [edx + 0x38]
00410394  dbad88feffff             fld       xword ptr [ebp - 0x178]
0041039a  dee9                     fsubp     st(1)
0041039c  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
004103a2  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
004103a8  d9c0                     fld       st(0)
004103aa  d9fb                     fsincos
004103ac  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004103b2  dec9                     fmulp     st(1)
004103b4  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
004103ba  dec1                     faddp     st(1)
004103bc  d9593c                   fstp      dword ptr [ecx + 0x3c]
004103bf  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004103c5  dec9                     fmulp     st(1)
004103c7  d8c2                     fadd      st(2)
004103c9  d95a3c                   fstp      dword ptr [edx + 0x3c]
004103cc  dbad88feffff             fld       xword ptr [ebp - 0x178]
004103d2  dee9                     fsubp     st(1)
004103d4  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
004103da  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
004103e0  d9c0                     fld       st(0)
004103e2  d9fb                     fsincos
004103e4  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004103ea  dec9                     fmulp     st(1)
004103ec  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
004103f2  dec1                     faddp     st(1)
004103f4  d95940                   fstp      dword ptr [ecx + 0x40]
004103f7  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004103fd  dec9                     fmulp     st(1)
004103ff  d8c2                     fadd      st(2)
00410401  d95a40                   fstp      dword ptr [edx + 0x40]
00410404  dbad88feffff             fld       xword ptr [ebp - 0x178]
0041040a  dee9                     fsubp     st(1)
0041040c  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410412  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
00410418  d9fb                     fsincos
0041041a  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00410420  dec9                     fmulp     st(1)
00410422  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
00410428  dec1                     faddp     st(1)
0041042a  d95944                   fstp      dword ptr [ecx + 0x44]
0041042d  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00410433  dec9                     fmulp     st(1)
00410435  dec1                     faddp     st(1)
00410437  d95a44                   fstp      dword ptr [edx + 0x44]
0041043a  dbbd7cfeffff             fstp      xword ptr [ebp - 0x184]
00410440  dbadb8feffff             fld       xword ptr [ebp - 0x148]
00410446  d84b94                   fmul      dword ptr [ebx - 0x6c]
00410449  d94398                   fld       dword ptr [ebx - 0x68]
0041044c  d9c9                     fxch      st(1)
0041044e  d84b98                   fmul      dword ptr [ebx - 0x68]
00410451  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410457  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
0041045d  d9fb                     fsincos
0041045f  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00410465  deca                     fmulp     st(2)
00410467  d9c9                     fxch      st(1)
00410469  d95948                   fstp      dword ptr [ecx + 0x48]
0041046c  d82de0945500             fsubr     dword ptr [0x5594e0] ; bits=0000803f, f32=1.0
00410472  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00410478  dec9                     fmulp     st(1)
0041047a  dbad7cfeffff             fld       xword ptr [ebp - 0x184]
00410480  dee9                     fsubp     st(1)
00410482  d95a48                   fstp      dword ptr [edx + 0x48]
00410485  dbadb8feffff             fld       xword ptr [ebp - 0x148]
0041048b  d84b90                   fmul      dword ptr [ebx - 0x70]
0041048e  d8c9                     fmul      st(1)
00410490  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410496  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
0041049c  d9fb                     fsincos
0041049e  dbad6cffffff             fld       xword ptr [ebp - 0x94]
004104a4  deca                     fmulp     st(2)
004104a6  d9c9                     fxch      st(1)
004104a8  d9594c                   fstp      dword ptr [ecx + 0x4c]
004104ab  d82de0945500             fsubr     dword ptr [0x5594e0] ; bits=0000803f, f32=1.0
004104b1  dbad6cffffff             fld       xword ptr [ebp - 0x94]
004104b7  dec9                     fmulp     st(1)
004104b9  dbad7cfeffff             fld       xword ptr [ebp - 0x184]
004104bf  dee9                     fsubp     st(1)
004104c1  d95a4c                   fstp      dword ptr [edx + 0x4c]
004104c4  dbadb8feffff             fld       xword ptr [ebp - 0x148]
004104ca  dbadb8feffff             fld       xword ptr [ebp - 0x148]
004104d0  dec1                     faddp     st(1)
004104d2  d8c9                     fmul      st(1)
004104d4  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
004104da  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
004104e0  d9fb                     fsincos
004104e2  dbad6cffffff             fld       xword ptr [ebp - 0x94]
004104e8  deca                     fmulp     st(2)
004104ea  d9c9                     fxch      st(1)
004104ec  d95950                   fstp      dword ptr [ecx + 0x50]
004104ef  d82de0945500             fsubr     dword ptr [0x5594e0] ; bits=0000803f, f32=1.0
004104f5  dbad6cffffff             fld       xword ptr [ebp - 0x94]
004104fb  dec9                     fmulp     st(1)
004104fd  dbad7cfeffff             fld       xword ptr [ebp - 0x184]
00410503  dee9                     fsubp     st(1)
00410505  d95a50                   fstp      dword ptr [edx + 0x50]
00410508  dbadb8feffff             fld       xword ptr [ebp - 0x148]
0041050e  dec9                     fmulp     st(1)
00410510  d91d50965500             fstp      dword ptr [0x559650] ; bits=00000000, f32=0.0
00410516  d90550965500             fld       dword ptr [0x559650] ; bits=00000000, f32=0.0
0041051c  d9fb                     fsincos
0041051e  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00410524  deca                     fmulp     st(2)
00410526  d9c9                     fxch      st(1)
00410528  d95954                   fstp      dword ptr [ecx + 0x54]
0041052b  d82de0945500             fsubr     dword ptr [0x5594e0] ; bits=0000803f, f32=1.0
00410531  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00410537  dec9                     fmulp     st(1)
00410539  dbad7cfeffff             fld       xword ptr [ebp - 0x184]
0041053f  dee9                     fsubp     st(1)
00410541  d95a54                   fstp      dword ptr [edx + 0x54]
00410544  d9ee                     fldz
00410546  d9fb                     fsincos
00410548  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0041054e  deca                     fmulp     st(2)
00410550  d9c9                     fxch      st(1)
00410552  d95958                   fstp      dword ptr [ecx + 0x58]
00410555  d82de0945500             fsubr     dword ptr [0x5594e0] ; bits=0000803f, f32=1.0
0041055b  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00410561  dec9                     fmulp     st(1)
00410563  dbad7cfeffff             fld       xword ptr [ebp - 0x184]
00410569  dee9                     fsubp     st(1)
0041056b  d95a58                   fstp      dword ptr [edx + 0x58]
0041056e  8b4530                   mov       eax, dword ptr [ebp + 0x30]
00410571  c70017000000             mov       dword ptr [eax], 0x17
00410577  d9ee                     fldz
00410579  dd9d70feffff             fstp      qword ptr [ebp - 0x190]
0041057f  bb02000000               mov       ebx, 2
00410584  dd8570feffff             fld       qword ptr [ebp - 0x190]
0041058a  8b4538                   mov       eax, dword ptr [ebp + 0x38]
0041058d  d94498f8                 fld       dword ptr [eax + ebx*4 - 8]
00410591  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
00410595  d80dec945500             fmul      dword ptr [0x5594ec] ; bits=0000003f, f32=0.5
0041059b  8b4d34                   mov       ecx, dword ptr [ebp + 0x34]
0041059e  d94499f8                 fld       dword ptr [ecx + ebx*4 - 8]
004105a2  d86c99fc                 fsubr     dword ptr [ecx + ebx*4 - 4]
004105a6  dec9                     fmulp     st(1)
004105a8  dec1                     faddp     st(1)
004105aa  d90498                   fld       dword ptr [eax + ebx*4]
004105ad  d9c0                     fld       st(0)
004105af  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
004105b3  d80dec945500             fmul      dword ptr [0x5594ec] ; bits=0000003f, f32=0.5
004105b9  d90499                   fld       dword ptr [ecx + ebx*4]
004105bc  d9c0                     fld       st(0)
004105be  d86499fc                 fsub      dword ptr [ecx + ebx*4 - 4]
004105c2  deca                     fmulp     st(2)
004105c4  d9c9                     fxch      st(1)
004105c6  dec3                     faddp     st(3)
004105c8  d9c9                     fxch      st(1)
004105ca  d8449804                 fadd      dword ptr [eax + ebx*4 + 4]
004105ce  d80dec945500             fmul      dword ptr [0x5594ec] ; bits=0000003f, f32=0.5
004105d4  d9c9                     fxch      st(1)
004105d6  d86c9904                 fsubr     dword ptr [ecx + ebx*4 + 4]
004105da  dec9                     fmulp     st(1)
004105dc  dec1                     faddp     st(1)
004105de  83c303                   add       ebx, 3
004105e1  83fb17                   cmp       ebx, 0x17
004105e4  7ca4                     jl        0x41058a
004105e6  8b4538                   mov       eax, dword ptr [ebp + 0x38]
004105e9  d94498f8                 fld       dword ptr [eax + ebx*4 - 8]
004105ed  d84498fc                 fadd      dword ptr [eax + ebx*4 - 4]
004105f1  d80dec945500             fmul      dword ptr [0x5594ec] ; bits=0000003f, f32=0.5
004105f7  8b4534                   mov       eax, dword ptr [ebp + 0x34]
004105fa  d94498f8                 fld       dword ptr [eax + ebx*4 - 8]
004105fe  d86c98fc                 fsubr     dword ptr [eax + ebx*4 - 4]
00410602  dec9                     fmulp     st(1)
00410604  dec1                     faddp     st(1)
00410606  dbada0feffff             fld       xword ptr [ebp - 0x160]
0041060c  def1                     fdivrp    st(1)
0041060e  d9fa                     fsqrt
00410610  d95df8                   fstp      dword ptr [ebp - 8]
00410613  d945f8                   fld       dword ptr [ebp - 8]
00410616  dbbdc4feffff             fstp      xword ptr [ebp - 0x13c]
0041061c  b917000000               mov       ecx, 0x17
00410621  bb01000000               mov       ebx, 1
00410626  dbadc4feffff             fld       xword ptr [ebp - 0x13c]
0041062c  eb04                     jmp       0x410632
0041062e  d95c9af8                 fstp      dword ptr [edx + ebx*4 - 8]
00410632  8b4534                   mov       eax, dword ptr [ebp + 0x34]
00410635  d9c0                     fld       st(0)
00410637  d84c98fc                 fmul      dword ptr [eax + ebx*4 - 4]
0041063b  d95c98fc                 fstp      dword ptr [eax + ebx*4 - 4]
0041063f  8b5538                   mov       edx, dword ptr [ebp + 0x38]
00410642  d9c0                     fld       st(0)
00410644  d84c9afc                 fmul      dword ptr [edx + ebx*4 - 4]
00410648  d95c9afc                 fstp      dword ptr [edx + ebx*4 - 4]
0041064c  d9c0                     fld       st(0)
0041064e  d80c98                   fmul      dword ptr [eax + ebx*4]
00410651  d91c98                   fstp      dword ptr [eax + ebx*4]
00410654  d9c0                     fld       st(0)
00410656  d80c9a                   fmul      dword ptr [edx + ebx*4]
00410659  d91c9a                   fstp      dword ptr [edx + ebx*4]
0041065c  d9c0                     fld       st(0)
0041065e  d84c9804                 fmul      dword ptr [eax + ebx*4 + 4]
00410662  d95c9804                 fstp      dword ptr [eax + ebx*4 + 4]
00410666  d9c0                     fld       st(0)
00410668  d84c9a04                 fmul      dword ptr [edx + ebx*4 + 4]
0041066c  d95c9a04                 fstp      dword ptr [edx + ebx*4 + 4]
00410670  d9c0                     fld       st(0)
00410672  d84c9808                 fmul      dword ptr [eax + ebx*4 + 8]
00410676  d95c9808                 fstp      dword ptr [eax + ebx*4 + 8]
0041067a  d9c0                     fld       st(0)
0041067c  d84c9a08                 fmul      dword ptr [edx + ebx*4 + 8]
00410680  d95c9a08                 fstp      dword ptr [edx + ebx*4 + 8]
00410684  d9c0                     fld       st(0)
00410686  d84c980c                 fmul      dword ptr [eax + ebx*4 + 0xc]
0041068a  d95c980c                 fstp      dword ptr [eax + ebx*4 + 0xc]
0041068e  d9c0                     fld       st(0)
00410690  d84c9a0c                 fmul      dword ptr [edx + ebx*4 + 0xc]
00410694  d95c9a0c                 fstp      dword ptr [edx + ebx*4 + 0xc]
00410698  d9c0                     fld       st(0)
0041069a  d84c9810                 fmul      dword ptr [eax + ebx*4 + 0x10]
0041069e  d95c9810                 fstp      dword ptr [eax + ebx*4 + 0x10]
004106a2  d9c0                     fld       st(0)
004106a4  d84c9a10                 fmul      dword ptr [edx + ebx*4 + 0x10]
004106a8  d95c9a10                 fstp      dword ptr [edx + ebx*4 + 0x10]
004106ac  d9c0                     fld       st(0)
004106ae  d84c9814                 fmul      dword ptr [eax + ebx*4 + 0x14]
004106b2  d95c9814                 fstp      dword ptr [eax + ebx*4 + 0x14]
004106b6  d9c0                     fld       st(0)
004106b8  d84c9a14                 fmul      dword ptr [edx + ebx*4 + 0x14]
004106bc  d95c9a14                 fstp      dword ptr [edx + ebx*4 + 0x14]
004106c0  d9c0                     fld       st(0)
004106c2  d84c9818                 fmul      dword ptr [eax + ebx*4 + 0x18]
004106c6  d95c9818                 fstp      dword ptr [eax + ebx*4 + 0x18]
004106ca  d9c0                     fld       st(0)
004106cc  d84c9a18                 fmul      dword ptr [edx + ebx*4 + 0x18]
004106d0  83c308                   add       ebx, 8
004106d3  83e908                   sub       ecx, 8
004106d6  83f908                   cmp       ecx, 8
004106d9  0f8d4fffffff             jge       0x41062e
004106df  d95c9af8                 fstp      dword ptr [edx + ebx*4 - 8]
004106e3  dbbdc4feffff             fstp      xword ptr [ebp - 0x13c]
004106e9  8b5534                   mov       edx, dword ptr [ebp + 0x34]
004106ec  8b4538                   mov       eax, dword ptr [ebp + 0x38]
004106ef  dbadc4feffff             fld       xword ptr [ebp - 0x13c]
004106f5  898564feffff             mov       dword ptr [ebp - 0x19c], eax
004106fb  eb04                     jmp       0x410701
004106fd  d95c98f8                 fstp      dword ptr [eax + ebx*4 - 8]
00410701  d9c0                     fld       st(0)
00410703  d84c9afc                 fmul      dword ptr [edx + ebx*4 - 4]
00410707  8b4538                   mov       eax, dword ptr [ebp + 0x38]
0041070a  d95c9afc                 fstp      dword ptr [edx + ebx*4 - 4]
0041070e  8bb564feffff             mov       esi, dword ptr [ebp - 0x19c]
00410714  d9c0                     fld       st(0)
00410716  d84c9efc                 fmul      dword ptr [esi + ebx*4 - 4]
0041071a  43                       inc       ebx
0041071b  49                       dec       ecx
0041071c  83f900                   cmp       ecx, 0
0041071f  7fdc                     jg        0x4106fd
00410721  d95c98f8                 fstp      dword ptr [eax + ebx*4 - 8]
00410725  ddd8                     fstp      st(0)
00410727  b800000000               mov       eax, 0
0041072c  5e                       pop       esi
0041072d  5b                       pop       ebx
0041072e  8be5                     mov       esp, ebp
00410730  5d                       pop       ebp
00410731  c3                       ret
00410732  8da42400000000           lea       esp, [esp]
00410739  8da42400000000           lea       esp, [esp]
