; _g_acos
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xa19c0
004a19c0  55                       push      ebp
004a19c1  8bec                     mov       ebp, esp
004a19c3  83ec08                   sub       esp, 8
004a19c6  8b4508                   mov       eax, dword ptr [ebp + 8]
004a19c9  53                       push      ebx
004a19ca  8b08                     mov       ecx, dword ptr [eax]
004a19cc  894d08                   mov       dword ptr [ebp + 8], ecx
004a19cf  d94508                   fld       dword ptr [ebp + 8]
004a19d2  d9e1                     fabs
004a19d4  d81598035500             fcom      dword ptr [0x550398] ; ?rh@?1??g_acos@@9@9, bits=f304353f, f32=0.7071067690849304
004a19da  dfe0                     fnstsw    ax
004a19dc  f6c441                   test      ah, 0x41
004a19df  0f8bc1000000             jnp       0x4a1aa6
004a19e5  33db                     xor       ebx, ebx
004a19e7  d81568dc5400             fcom      dword ptr [0x54dc68] ; __real@3f800000, bits=0000803f, f32=1.0
004a19ed  dfe0                     fnstsw    ax
004a19ef  f6c441                   test      ah, 0x41
004a19f2  0f8bc7000000             jnp       0x4a1abf
004a19f8  8b5508                   mov       edx, dword ptr [ebp + 8]
004a19fb  8d4dfc                   lea       ecx, [ebp - 4]
004a19fe  8955f8                   mov       dword ptr [ebp - 8], edx
004a1a01  8bc2                     mov       eax, edx
004a1a03  8d55f8                   lea       edx, [ebp - 8]
004a1a06  6844ed5b00               push      0x5bed44
004a1a0b  ddd8                     fstp      st(0)
004a1a0d  8945fc                   mov       dword ptr [ebp - 4], eax
004a1a10  c70528ed5b0094ed5b00     mov       dword ptr [0x5bed28], 0x5bed94 ; bits=94ed5b00, f32=8.442257122977436e-39
004a1a1a  890d30ed5b00             mov       dword ptr [0x5bed30], ecx ; bits=00000000, f32=0.0
004a1a20  c70544ed5b00d9000000     mov       dword ptr [0x5bed44], 0xd9 ; bits=00000000, f32=0.0
004a1a2a  881d48ed5b00             mov       byte ptr [0x5bed48], bl
004a1a30  881d49ed5b00             mov       byte ptr [0x5bed49], bl
004a1a36  891d4ced5b00             mov       dword ptr [0x5bed4c], ebx ; bits=00000000, f32=0.0
004a1a3c  891d54ed5b00             mov       dword ptr [0x5bed54], ebx ; bits=00000000, f32=0.0
004a1a42  881d58ed5b00             mov       byte ptr [0x5bed58], bl
004a1a48  881d59ed5b00             mov       byte ptr [0x5bed59], bl
004a1a4e  891d60ed5b00             mov       dword ptr [0x5bed60], ebx ; bits=00000000, f32=0.0
004a1a54  c70568ed5b0001000000     mov       dword ptr [0x5bed68], 1 ; bits=00000000, f32=0.0
004a1a5e  89156ced5b00             mov       dword ptr [0x5bed6c], edx ; bits=00000000, f32=0.0
004a1a64  66c70570ed5b000900       mov       word ptr [0x5bed70], 9 ; bits=0000
004a1a6d  66891d72ed5b00           mov       word ptr [0x5bed72], bx ; bits=0000
004a1a74  ff1574f35b00             call      dword ptr [0x5bf374] ; bits=80524c00, f32=7.009093131573872e-39
004a1a7a  a194ed5b00               mov       eax, dword ptr [0x5bed94] ; bits=00000000, f32=0.0
004a1a7f  83c404                   add       esp, 4
004a1a82  3bc3                     cmp       eax, ebx
004a1a84  0f848a000000             je        0x4a1b14
004a1a8a  d945fc                   fld       dword ptr [ebp - 4]
004a1a8d  8b45fc                   mov       eax, dword ptr [ebp - 4]
004a1a90  d9e1                     fabs
004a1a92  d81598035500             fcom      dword ptr [0x550398] ; ?rh@?1??g_acos@@9@9, bits=f304353f, f32=0.7071067690849304
004a1a98  894508                   mov       dword ptr [ebp + 8], eax
004a1a9b  dfe0                     fnstsw    ax
004a1a9d  f6c441                   test      ah, 0x41
004a1aa0  0f8a41ffffff             jp        0x4a19e7
004a1aa6  8d4d08                   lea       ecx, [ebp + 8]
004a1aa9  ddd8                     fstp      st(0)
004a1aab  51                       push      ecx
004a1aac  e8dff4ffff               call      0x4a0f90 ; _g_asin
004a1ab1  dc2d88035500             fsubr     qword ptr [0x550388] ; ?hpi@?1??g_acos@@9@9, bits=c0036054fb21f93f, f64=1.5707963272
004a1ab7  83c404                   add       esp, 4
004a1aba  5b                       pop       ebx
004a1abb  8be5                     mov       esp, ebp
004a1abd  5d                       pop       ebp
004a1abe  c3                       ret
004a1abf  d82d68dc5400             fsubr     dword ptr [0x54dc68] ; __real@3f800000, bits=0000803f, f32=1.0
004a1ac5  d9c0                     fld       st(0)
004a1ac7  d9fa                     fsqrt
004a1ac9  d905ac035500             fld       dword ptr [0x5503ac] ; ?p4@?1??g_acos@@9@9, bits=ca266a3b, f32=0.003572868648916483
004a1acf  d8ca                     fmul      st(2)
004a1ad1  d805a8035500             fadd      dword ptr [0x5503a8] ; ?p3@?1??g_acos@@9@9, bits=50a2fa3b, f32=0.007648743689060211
004a1ad7  d8ca                     fmul      st(2)
004a1ad9  d805a4035500             fadd      dword ptr [0x5503a4] ; ?p2@?1??g_acos@@9@9, bits=6070d93c, f32=0.026542842388153076
004a1adf  d8ca                     fmul      st(2)
004a1ae1  d805a0035500             fadd      dword ptr [0x5503a0] ; ?p1@?1??g_acos@@9@9, bits=6a5bf13d, f32=0.11785013973712921
004a1ae7  d8ca                     fmul      st(2)
004a1ae9  d8059c035500             fadd      dword ptr [0x55039c] ; ?p0@?1??g_acos@@9@9, bits=cd13d43e, f32=0.4142135679721832
004a1aef  d80568dc5400             fadd      dword ptr [0x54dc68] ; __real@3f800000, bits=0000803f, f32=1.0
004a1af5  dec9                     fmulp     st(1)
004a1af7  ddd9                     fstp      st(1)
004a1af9  d94508                   fld       dword ptr [ebp + 8]
004a1afc  d81d6cdc5400             fcomp     dword ptr [0x54dc6c] ; __real@00000000, bits=00000000, f32=0.0
004a1b02  dfe0                     fnstsw    ax
004a1b04  f6c405                   test      ah, 5
004a1b07  7a42                     jp        0x4a1b4b
004a1b09  dc2d90035500             fsubr     qword ptr [0x550390] ; ?pi@?1??g_acos@@9@9, bits=e0864454fb210940, f64=3.1415926536
004a1b0f  5b                       pop       ebx
004a1b10  8be5                     mov       esp, ebp
004a1b12  5d                       pop       ebp
004a1b13  c3                       ret
004a1b14  803dc5ec5b0001           cmp       byte ptr [0x5becc5], 1
004a1b1b  750b                     jne       0x4a1b28
004a1b1d  d90518035500             fld       dword ptr [0x550318] ; _NaN_F, bits=0000c07f, f32=nan
004a1b23  5b                       pop       ebx
004a1b24  8be5                     mov       esp, ebp
004a1b26  5d                       pop       ebp
004a1b27  c3                       ret
004a1b28  d94508                   fld       dword ptr [ebp + 8]
004a1b2b  d81d68dc5400             fcomp     dword ptr [0x54dc68] ; __real@3f800000, bits=0000803f, f32=1.0
004a1b31  dfe0                     fnstsw    ax
004a1b33  2500410000               and       eax, 0x4100
004a1b38  750b                     jne       0x4a1b45
004a1b3a  d9056cdc5400             fld       dword ptr [0x54dc6c] ; __real@00000000, bits=00000000, f32=0.0
004a1b40  5b                       pop       ebx
004a1b41  8be5                     mov       esp, ebp
004a1b43  5d                       pop       ebp
004a1b44  c3                       ret
004a1b45  d905b0035500             fld       dword ptr [0x5503b0] ; __real@40490fdb, bits=db0f4940, f32=3.1415927410125732
004a1b4b  5b                       pop       ebx
004a1b4c  8be5                     mov       esp, ebp
004a1b4e  5d                       pop       ebp
004a1b4f  c3                       ret
