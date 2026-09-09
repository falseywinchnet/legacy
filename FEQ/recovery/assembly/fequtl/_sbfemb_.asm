; _sbfemb_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x2fb60
0042fb60  55                       push      ebp
0042fb61  8bec                     mov       ebp, esp
0042fb63  b868000000               mov       eax, 0x68
0042fb68  e893940b00               call      0x4e9000 ; __alloca_probe
0042fb6d  53                       push      ebx
0042fb6e  56                       push      esi
0042fb6f  57                       push      edi
0042fb70  8b4508                   mov       eax, dword ptr [ebp + 8]
0042fb73  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
0042fb76  8b5510                   mov       edx, dword ptr [ebp + 0x10]
0042fb79  8945ac                   mov       dword ptr [ebp - 0x54], eax
0042fb7c  894da8                   mov       dword ptr [ebp - 0x58], ecx
0042fb7f  6a08                     push      8
0042fb81  8d1db8cf5600             lea       ebx, [0x56cfb8] ; bits=00000000, f32=0.0
0042fb87  8d4334                   lea       eax, [ebx + 0x34]
0042fb8a  50                       push      eax
0042fb8b  8d4318                   lea       eax, [ebx + 0x18]
0042fb8e  50                       push      eax
0042fb8f  8d433c                   lea       eax, [ebx + 0x3c]
0042fb92  50                       push      eax
0042fb93  8d02                     lea       eax, [edx]
0042fb95  50                       push      eax
0042fb96  8b4568                   mov       eax, dword ptr [ebp + 0x68]
0042fb99  8d00                     lea       eax, [eax]
0042fb9b  50                       push      eax
0042fb9c  8b4560                   mov       eax, dword ptr [ebp + 0x60]
0042fb9f  8d00                     lea       eax, [eax]
0042fba1  50                       push      eax
0042fba2  8b4538                   mov       eax, dword ptr [ebp + 0x38]
0042fba5  8d00                     lea       eax, [eax]
0042fba7  50                       push      eax
0042fba8  8b4534                   mov       eax, dword ptr [ebp + 0x34]
0042fbab  8d00                     lea       eax, [eax]
0042fbad  50                       push      eax
0042fbae  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0042fbb1  8d00                     lea       eax, [eax]
0042fbb3  50                       push      eax
0042fbb4  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0042fbb7  8d00                     lea       eax, [eax]
0042fbb9  50                       push      eax
0042fbba  e851feffff               call      0x42fa10 ; _embsub_
0042fbbf  83c42c                   add       esp, 0x2c
0042fbc2  dd4318                   fld       qword ptr [ebx + 0x18]
0042fbc5  d95dfc                   fstp      dword ptr [ebp - 4]
0042fbc8  d945fc                   fld       dword ptr [ebp - 4]
0042fbcb  db7df0                   fstp      xword ptr [ebp - 0x10]
0042fbce  8b858c000000             mov       eax, dword ptr [ebp + 0x8c]
0042fbd4  db6df0                   fld       xword ptr [ebp - 0x10]
0042fbd7  d918                     fstp      dword ptr [eax]
0042fbd9  db6df0                   fld       xword ptr [ebp - 0x10]
0042fbdc  d81d44cf5600             fcomp     dword ptr [0x56cf44] ; bits=00000000, f32=0.0
0042fbe2  dfe0                     fnstsw    ax
0042fbe4  9e                       sahf
0042fbe5  0f8a26000000             jp        0x42fc11
0042fbeb  7324                     jae       0x42fc11
0042fbed  8d43ec                   lea       eax, [ebx - 0x14]
0042fbf0  db6df0                   fld       xword ptr [ebp - 0x10]
0042fbf3  d95dfc                   fstp      dword ptr [ebp - 4]
0042fbf6  8d4dfc                   lea       ecx, [ebp - 4]
0042fbf9  894828                   mov       dword ptr [eax + 0x28], ecx
0042fbfc  50                       push      eax
0042fbfd  e8ee290700               call      0x4a25f0 ; _jwe_isfm
0042fc02  83c404                   add       esp, 4
0042fc05  8d43e0                   lea       eax, [ebx - 0x20]
0042fc08  50                       push      eax
0042fc09  e832380700               call      0x4a3440 ; _jwe_xstp
0042fc0e  83c404                   add       esp, 4
0042fc11  8b8590000000             mov       eax, dword ptr [ebp + 0x90]
0042fc17  c70000000000             mov       dword ptr [eax], 0
0042fc1d  8b45ac                   mov       eax, dword ptr [ebp - 0x54]
0042fc20  8b10                     mov       edx, dword ptr [eax]
0042fc22  8b8584000000             mov       eax, dword ptr [ebp + 0x84]
0042fc28  8b00                     mov       eax, dword ptr [eax]
0042fc2a  8b8d90000000             mov       ecx, dword ptr [ebp + 0x90]
0042fc30  894491fc                 mov       dword ptr [ecx + edx*4 - 4], eax
0042fc34  89d0                     mov       eax, edx
0042fc36  48                       dec       eax
0042fc37  89c2                     mov       edx, eax
0042fc39  8d42ff                   lea       eax, [edx - 1]
0042fc3c  3d00000000               cmp       eax, 0
0042fc41  8945a4                   mov       dword ptr [ebp - 0x5c], eax
0042fc44  0f8ea3030000             jle       0x42ffed
0042fc4a  8b4da8                   mov       ecx, dword ptr [ebp - 0x58]
0042fc4d  89d0                     mov       eax, edx
0042fc4f  d901                     fld       dword ptr [ecx]
0042fc51  dd5de8                   fstp      qword ptr [ebp - 0x18]
0042fc54  8945a0                   mov       dword ptr [ebp - 0x60], eax
0042fc57  d9ee                     fldz
0042fc59  dd5de0                   fstp      qword ptr [ebp - 0x20]
0042fc5c  8b4da0                   mov       ecx, dword ptr [ebp - 0x60]
0042fc5f  8b8588000000             mov       eax, dword ptr [ebp + 0x88]
0042fc65  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
0042fc69  8d05b8cf5600             lea       eax, [0x56cfb8] ; bits=00000000, f32=0.0
0042fc6f  dc4818                   fmul      qword ptr [eax + 0x18]
0042fc72  dc6de8                   fsubr     qword ptr [ebp - 0x18]
0042fc75  d95834                   fstp      dword ptr [eax + 0x34]
0042fc78  8b4534                   mov       eax, dword ptr [ebp + 0x34]
0042fc7b  8b08                     mov       ecx, dword ptr [eax]
0042fc7d  49                       dec       ecx
0042fc7e  83f900                   cmp       ecx, 0
0042fc81  894d9c                   mov       dword ptr [ebp - 0x64], ecx
0042fc84  0f8e3d030000             jle       0x42ffc7
0042fc8a  bb01000000               mov       ebx, 1
0042fc8f  b808000000               mov       eax, 8
0042fc94  894598                   mov       dword ptr [ebp - 0x68], eax
0042fc97  8b4d98                   mov       ecx, dword ptr [ebp - 0x68]
0042fc9a  8b4538                   mov       eax, dword ptr [ebp + 0x38]
0042fc9d  8d7408f8                 lea       esi, [eax + ecx - 8]
0042fca1  8d15b8cf5600             lea       edx, [0x56cfb8] ; bits=00000000, f32=0.0
0042fca7  8d7ad8                   lea       edi, [edx - 0x28]
0042fcaa  b808000000               mov       eax, 8
0042fcaf  89c1                     mov       ecx, eax
0042fcb1  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0042fcb3  750a                     jne       0x42fcbf
0042fcb5  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
0042fcb8  8b00                     mov       eax, dword ptr [eax]
0042fcba  894228                   mov       dword ptr [edx + 0x28], eax
0042fcbd  eb0a                     jmp       0x42fcc9
0042fcbf  8b4530                   mov       eax, dword ptr [ebp + 0x30]
0042fcc2  8b00                     mov       eax, dword ptr [eax]
0042fcc4  89d1                     mov       ecx, edx
0042fcc6  894128                   mov       dword ptr [ecx + 0x28], eax
0042fcc9  8b4d98                   mov       ecx, dword ptr [ebp - 0x68]
0042fccc  8b4538                   mov       eax, dword ptr [ebp + 0x38]
0042fccf  8d7408f8                 lea       esi, [eax + ecx - 8]
0042fcd3  8d15b8cf5600             lea       edx, [0x56cfb8] ; bits=00000000, f32=0.0
0042fcd9  8d7ad8                   lea       edi, [edx - 0x28]
0042fcdc  b808000000               mov       eax, 8
0042fce1  89c1                     mov       ecx, eax
0042fce3  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0042fce5  7512                     jne       0x42fcf9
0042fce7  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0042fcea  8b00                     mov       eax, dword ptr [eax]
0042fcec  894220                   mov       dword ptr [edx + 0x20], eax
0042fcef  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0042fcf2  8b00                     mov       eax, dword ptr [eax]
0042fcf4  894224                   mov       dword ptr [edx + 0x24], eax
0042fcf7  eb14                     jmp       0x42fd0d
0042fcf9  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0042fcfc  8b00                     mov       eax, dword ptr [eax]
0042fcfe  89d1                     mov       ecx, edx
0042fd00  894120                   mov       dword ptr [ecx + 0x20], eax
0042fd03  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0042fd06  8b00                     mov       eax, dword ptr [eax]
0042fd08  89d1                     mov       ecx, edx
0042fd0a  894124                   mov       dword ptr [ecx + 0x24], eax
0042fd0d  8b4548                   mov       eax, dword ptr [ebp + 0x48]
0042fd10  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
0042fd14  d9ee                     fldz
0042fd16  d9c9                     fxch      st(1)
0042fd18  d81544cf5600             fcom      dword ptr [0x56cf44] ; bits=00000000, f32=0.0
0042fd1e  db7dd4                   fstp      xword ptr [ebp - 0x2c]
0042fd21  dfe0                     fnstsw    ax
0042fd23  9e                       sahf
0042fd24  0f8a02000000             jp        0x42fd2c
0042fd2a  771a                     ja        0x42fd46
0042fd2c  8b4550                   mov       eax, dword ptr [ebp + 0x50]
0042fd2f  d94498fc                 fld       dword ptr [eax + ebx*4 - 4]
0042fd33  ded9                     fcompp
0042fd35  dfe0                     fnstsw    ax
0042fd37  9e                       sahf
0042fd38  0f8a7a020000             jp        0x42ffb8
0042fd3e  0f8674020000             jbe       0x42ffb8
0042fd44  eb02                     jmp       0x42fd48
0042fd46  ddd8                     fstp      st(0)
0042fd48  8b4554                   mov       eax, dword ptr [ebp + 0x54]
0042fd4b  8b4498fc                 mov       eax, dword ptr [eax + ebx*4 - 4]
0042fd4f  8d15b8cf5600             lea       edx, [0x56cfb8] ; bits=00000000, f32=0.0
0042fd55  894240                   mov       dword ptr [edx + 0x40], eax
0042fd58  8b4560                   mov       eax, dword ptr [ebp + 0x60]
0042fd5b  8b4498fc                 mov       eax, dword ptr [eax + ebx*4 - 4]
0042fd5f  894250                   mov       dword ptr [edx + 0x50], eax
0042fd62  d94240                   fld       dword ptr [edx + 0x40]
0042fd65  d9ee                     fldz
0042fd67  d9c9                     fxch      st(1)
0042fd69  d81d44cf5600             fcomp     dword ptr [0x56cf44] ; bits=00000000, f32=0.0
0042fd6f  dfe0                     fnstsw    ax
0042fd71  9e                       sahf
0042fd72  0f8a7f000000             jp        0x42fdf7
0042fd78  767d                     jbe       0x42fdf7
0042fd7a  8b45a8                   mov       eax, dword ptr [ebp - 0x58]
0042fd7d  d900                     fld       dword ptr [eax]
0042fd7f  db6dd4                   fld       xword ptr [ebp - 0x2c]
0042fd82  d828                     fsubr     dword ptr [eax]
0042fd84  d86a34                   fsubr     dword ptr [edx + 0x34]
0042fd87  d95a3c                   fstp      dword ptr [edx + 0x3c]
0042fd8a  d9423c                   fld       dword ptr [edx + 0x3c]
0042fd8d  d8da                     fcomp     st(2)
0042fd8f  ddd9                     fstp      st(1)
0042fd91  db7dc8                   fstp      xword ptr [ebp - 0x38]
0042fd94  dfe0                     fnstsw    ax
0042fd96  9e                       sahf
0042fd97  0f8a0b000000             jp        0x42fda8
0042fd9d  7309                     jae       0x42fda8
0042fd9f  89d0                     mov       eax, edx
0042fda1  c7403c00000000           mov       dword ptr [eax + 0x3c], 0
0042fda8  8b456c                   mov       eax, dword ptr [ebp + 0x6c]
0042fdab  db6dc8                   fld       xword ptr [ebp - 0x38]
0042fdae  d86498fc                 fsub      dword ptr [eax + ebx*4 - 4]
0042fdb2  8d05b8cf5600             lea       eax, [0x56cfb8] ; bits=00000000, f32=0.0
0042fdb8  d9582c                   fstp      dword ptr [eax + 0x2c]
0042fdbb  8d4840                   lea       ecx, [eax + 0x40]
0042fdbe  51                       push      ecx
0042fdbf  8d4850                   lea       ecx, [eax + 0x50]
0042fdc2  51                       push      ecx
0042fdc3  8d482c                   lea       ecx, [eax + 0x2c]
0042fdc6  51                       push      ecx
0042fdc7  8d483c                   lea       ecx, [eax + 0x3c]
0042fdca  51                       push      ecx
0042fdcb  8b4d48                   mov       ecx, dword ptr [ebp + 0x48]
0042fdce  8d4c99fc                 lea       ecx, [ecx + ebx*4 - 4]
0042fdd2  51                       push      ecx
0042fdd3  8b4d78                   mov       ecx, dword ptr [ebp + 0x78]
0042fdd6  8d4c99fc                 lea       ecx, [ecx + ebx*4 - 4]
0042fdda  51                       push      ecx
0042fddb  8b4d3c                   mov       ecx, dword ptr [ebp + 0x3c]
0042fdde  8d09                     lea       ecx, [ecx]
0042fde0  51                       push      ecx
0042fde1  8d4828                   lea       ecx, [eax + 0x28]
0042fde4  51                       push      ecx
0042fde5  8d4824                   lea       ecx, [eax + 0x24]
0042fde8  51                       push      ecx
0042fde9  8d4020                   lea       eax, [eax + 0x20]
0042fdec  50                       push      eax
0042fded  e8aef8ffff               call      0x42f6a0 ; _stothq_
0042fdf2  83c428                   add       esp, 0x28
0042fdf5  eb0b                     jmp       0x42fe02
0042fdf7  ddd8                     fstp      st(0)
0042fdf9  89d0                     mov       eax, edx
0042fdfb  c7404000000000           mov       dword ptr [eax + 0x40], 0
0042fe02  8b4558                   mov       eax, dword ptr [ebp + 0x58]
0042fe05  8b4498fc                 mov       eax, dword ptr [eax + ebx*4 - 4]
0042fe09  8d15b8cf5600             lea       edx, [0x56cfb8] ; bits=00000000, f32=0.0
0042fe0f  894244                   mov       dword ptr [edx + 0x44], eax
0042fe12  8b4564                   mov       eax, dword ptr [ebp + 0x64]
0042fe15  8b4498fc                 mov       eax, dword ptr [eax + ebx*4 - 4]
0042fe19  894250                   mov       dword ptr [edx + 0x50], eax
0042fe1c  d94244                   fld       dword ptr [edx + 0x44]
0042fe1f  d9ee                     fldz
0042fe21  d9c9                     fxch      st(1)
0042fe23  d81d44cf5600             fcomp     dword ptr [0x56cf44] ; bits=00000000, f32=0.0
0042fe29  dfe0                     fnstsw    ax
0042fe2b  9e                       sahf
0042fe2c  0f8a87000000             jp        0x42feb9
0042fe32  0f8681000000             jbe       0x42feb9
0042fe38  8b45a8                   mov       eax, dword ptr [ebp - 0x58]
0042fe3b  d900                     fld       dword ptr [eax]
0042fe3d  8b4d4c                   mov       ecx, dword ptr [ebp + 0x4c]
0042fe40  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
0042fe44  d828                     fsubr     dword ptr [eax]
0042fe46  d86a34                   fsubr     dword ptr [edx + 0x34]
0042fe49  d95a3c                   fstp      dword ptr [edx + 0x3c]
0042fe4c  d9423c                   fld       dword ptr [edx + 0x3c]
0042fe4f  d8da                     fcomp     st(2)
0042fe51  ddd9                     fstp      st(1)
0042fe53  db7dbc                   fstp      xword ptr [ebp - 0x44]
0042fe56  dfe0                     fnstsw    ax
0042fe58  9e                       sahf
0042fe59  0f8a0b000000             jp        0x42fe6a
0042fe5f  7309                     jae       0x42fe6a
0042fe61  89d0                     mov       eax, edx
0042fe63  c7403c00000000           mov       dword ptr [eax + 0x3c], 0
0042fe6a  8b4570                   mov       eax, dword ptr [ebp + 0x70]
0042fe6d  db6dbc                   fld       xword ptr [ebp - 0x44]
0042fe70  d86498fc                 fsub      dword ptr [eax + ebx*4 - 4]
0042fe74  8d05b8cf5600             lea       eax, [0x56cfb8] ; bits=00000000, f32=0.0
0042fe7a  d9582c                   fstp      dword ptr [eax + 0x2c]
0042fe7d  8d4844                   lea       ecx, [eax + 0x44]
0042fe80  51                       push      ecx
0042fe81  8d4850                   lea       ecx, [eax + 0x50]
0042fe84  51                       push      ecx
0042fe85  8d482c                   lea       ecx, [eax + 0x2c]
0042fe88  51                       push      ecx
0042fe89  8d483c                   lea       ecx, [eax + 0x3c]
0042fe8c  51                       push      ecx
0042fe8d  8b4d4c                   mov       ecx, dword ptr [ebp + 0x4c]
0042fe90  8d4c99fc                 lea       ecx, [ecx + ebx*4 - 4]
0042fe94  51                       push      ecx
0042fe95  8b4d7c                   mov       ecx, dword ptr [ebp + 0x7c]
0042fe98  8d4c99fc                 lea       ecx, [ecx + ebx*4 - 4]
0042fe9c  51                       push      ecx
0042fe9d  8b4d3c                   mov       ecx, dword ptr [ebp + 0x3c]
0042fea0  8d09                     lea       ecx, [ecx]
0042fea2  51                       push      ecx
0042fea3  8d4828                   lea       ecx, [eax + 0x28]
0042fea6  51                       push      ecx
0042fea7  8d4824                   lea       ecx, [eax + 0x24]
0042feaa  51                       push      ecx
0042feab  8d4020                   lea       eax, [eax + 0x20]
0042feae  50                       push      eax
0042feaf  e8ecf7ffff               call      0x42f6a0 ; _stothq_
0042feb4  83c428                   add       esp, 0x28
0042feb7  eb0b                     jmp       0x42fec4
0042feb9  ddd8                     fstp      st(0)
0042febb  89d0                     mov       eax, edx
0042febd  c7404400000000           mov       dword ptr [eax + 0x44], 0
0042fec4  8b455c                   mov       eax, dword ptr [ebp + 0x5c]
0042fec7  8b4498fc                 mov       eax, dword ptr [eax + ebx*4 - 4]
0042fecb  8d15b8cf5600             lea       edx, [0x56cfb8] ; bits=00000000, f32=0.0
0042fed1  894248                   mov       dword ptr [edx + 0x48], eax
0042fed4  8b4568                   mov       eax, dword ptr [ebp + 0x68]
0042fed7  8b4498fc                 mov       eax, dword ptr [eax + ebx*4 - 4]
0042fedb  894250                   mov       dword ptr [edx + 0x50], eax
0042fede  d94248                   fld       dword ptr [edx + 0x48]
0042fee1  d9ee                     fldz
0042fee3  d9c9                     fxch      st(1)
0042fee5  d81d44cf5600             fcomp     dword ptr [0x56cf44] ; bits=00000000, f32=0.0
0042feeb  dfe0                     fnstsw    ax
0042feed  9e                       sahf
0042feee  0f8a8a000000             jp        0x42ff7e
0042fef4  0f8684000000             jbe       0x42ff7e
0042fefa  8b45a8                   mov       eax, dword ptr [ebp - 0x58]
0042fefd  d900                     fld       dword ptr [eax]
0042feff  8b4d50                   mov       ecx, dword ptr [ebp + 0x50]
0042ff02  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
0042ff06  d828                     fsubr     dword ptr [eax]
0042ff08  d86a34                   fsubr     dword ptr [edx + 0x34]
0042ff0b  d95a3c                   fstp      dword ptr [edx + 0x3c]
0042ff0e  d9423c                   fld       dword ptr [edx + 0x3c]
0042ff11  d8da                     fcomp     st(2)
0042ff13  ddd9                     fstp      st(1)
0042ff15  db7db0                   fstp      xword ptr [ebp - 0x50]
0042ff18  dfe0                     fnstsw    ax
0042ff1a  9e                       sahf
0042ff1b  0f8a0b000000             jp        0x42ff2c
0042ff21  7309                     jae       0x42ff2c
0042ff23  89d0                     mov       eax, edx
0042ff25  c7403c00000000           mov       dword ptr [eax + 0x3c], 0
0042ff2c  8b4574                   mov       eax, dword ptr [ebp + 0x74]
0042ff2f  db6db0                   fld       xword ptr [ebp - 0x50]
0042ff32  d86498fc                 fsub      dword ptr [eax + ebx*4 - 4]
0042ff36  8d05b8cf5600             lea       eax, [0x56cfb8] ; bits=00000000, f32=0.0
0042ff3c  d9582c                   fstp      dword ptr [eax + 0x2c]
0042ff3f  8d4848                   lea       ecx, [eax + 0x48]
0042ff42  51                       push      ecx
0042ff43  8d4850                   lea       ecx, [eax + 0x50]
0042ff46  51                       push      ecx
0042ff47  8d482c                   lea       ecx, [eax + 0x2c]
0042ff4a  51                       push      ecx
0042ff4b  8d483c                   lea       ecx, [eax + 0x3c]
0042ff4e  51                       push      ecx
0042ff4f  8b4d50                   mov       ecx, dword ptr [ebp + 0x50]
0042ff52  8d4c99fc                 lea       ecx, [ecx + ebx*4 - 4]
0042ff56  51                       push      ecx
0042ff57  8b8d80000000             mov       ecx, dword ptr [ebp + 0x80]
0042ff5d  8d4c99fc                 lea       ecx, [ecx + ebx*4 - 4]
0042ff61  51                       push      ecx
0042ff62  8b4d3c                   mov       ecx, dword ptr [ebp + 0x3c]
0042ff65  8d09                     lea       ecx, [ecx]
0042ff67  51                       push      ecx
0042ff68  8d4828                   lea       ecx, [eax + 0x28]
0042ff6b  51                       push      ecx
0042ff6c  8d4824                   lea       ecx, [eax + 0x24]
0042ff6f  51                       push      ecx
0042ff70  8d4020                   lea       eax, [eax + 0x20]
0042ff73  50                       push      eax
0042ff74  e827f7ffff               call      0x42f6a0 ; _stothq_
0042ff79  83c428                   add       esp, 0x28
0042ff7c  eb0b                     jmp       0x42ff89
0042ff7e  ddd8                     fstp      st(0)
0042ff80  89d0                     mov       eax, edx
0042ff82  c7404800000000           mov       dword ptr [eax + 0x48], 0
0042ff89  dd45e0                   fld       qword ptr [ebp - 0x20]
0042ff8c  8b4544                   mov       eax, dword ptr [ebp + 0x44]
0042ff8f  8b4d40                   mov       ecx, dword ptr [ebp + 0x40]
0042ff92  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
0042ff96  d86c98fc                 fsubr     dword ptr [eax + ebx*4 - 4]
0042ff9a  d9e1                     fabs
0042ff9c  8d05b8cf5600             lea       eax, [0x56cfb8] ; bits=00000000, f32=0.0
0042ffa2  d94044                   fld       dword ptr [eax + 0x44]
0042ffa5  d84894                   fmul      dword ptr [eax - 0x6c]
0042ffa8  d84040                   fadd      dword ptr [eax + 0x40]
0042ffab  d84048                   fadd      dword ptr [eax + 0x48]
0042ffae  dec9                     fmulp     st(1)
0042ffb0  d84888                   fmul      dword ptr [eax - 0x78]
0042ffb3  dec1                     faddp     st(1)
0042ffb5  dd5de0                   fstp      qword ptr [ebp - 0x20]
0042ffb8  43                       inc       ebx
0042ffb9  83459808                 add       dword ptr [ebp - 0x68], 8
0042ffbd  836d9c01                 sub       dword ptr [ebp - 0x64], 1
0042ffc1  0f85d0fcffff             jne       0x42fc97
0042ffc7  dd45e0                   fld       qword ptr [ebp - 0x20]
0042ffca  d95dfc                   fstp      dword ptr [ebp - 4]
0042ffcd  8b45fc                   mov       eax, dword ptr [ebp - 4]
0042ffd0  8b55a0                   mov       edx, dword ptr [ebp - 0x60]
0042ffd3  8b8d90000000             mov       ecx, dword ptr [ebp + 0x90]
0042ffd9  894491fc                 mov       dword ptr [ecx + edx*4 - 4], eax
0042ffdd  83c2ff                   add       edx, -1
0042ffe0  836da401                 sub       dword ptr [ebp - 0x5c], 1
0042ffe4  8955a0                   mov       dword ptr [ebp - 0x60], edx
0042ffe7  0f856afcffff             jne       0x42fc57
0042ffed  b800000000               mov       eax, 0
0042fff2  5f                       pop       edi
0042fff3  5e                       pop       esi
0042fff4  5b                       pop       ebx
0042fff5  8be5                     mov       esp, ebp
0042fff7  5d                       pop       ebp
0042fff8  c3                       ret
0042fff9  8da42400000000           lea       esp, [esp]
