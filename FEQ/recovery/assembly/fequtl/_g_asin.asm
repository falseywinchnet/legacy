; _g_asin
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xa0f90
004a0f90  55                       push      ebp
004a0f91  8bec                     mov       ebp, esp
004a0f93  83ec0c                   sub       esp, 0xc
004a0f96  8b4508                   mov       eax, dword ptr [ebp + 8]
004a0f99  53                       push      ebx
004a0f9a  d900                     fld       dword ptr [eax]
004a0f9c  d955f8                   fst       dword ptr [ebp - 8]
004a0f9f  d9c0                     fld       st(0)
004a0fa1  d9e1                     fabs
004a0fa3  d95508                   fst       dword ptr [ebp + 8]
004a0fa6  d81d3cdd5400             fcomp     dword ptr [0x54dd3c] ; __real@3f000000, bits=0000003f, f32=0.5
004a0fac  dfe0                     fnstsw    ax
004a0fae  f6c441                   test      ah, 0x41
004a0fb1  0f8bd4000000             jnp       0x4a108b
004a0fb7  33db                     xor       ebx, ebx
004a0fb9  d94508                   fld       dword ptr [ebp + 8]
004a0fbc  d81d00dd5400             fcomp     dword ptr [0x54dd00] ; ?rh@?1??g_asin@@9@9, bits=f304353f, f32=0.7071067690849304
004a0fc2  dfe0                     fnstsw    ax
004a0fc4  f6c441                   test      ah, 0x41
004a0fc7  0f8bf9000000             jnp       0x4a10c6
004a0fcd  d94508                   fld       dword ptr [ebp + 8]
004a0fd0  d81d68dc5400             fcomp     dword ptr [0x54dc68] ; __real@3f800000, bits=0000803f, f32=1.0
004a0fd6  dfe0                     fnstsw    ax
004a0fd8  f6c441                   test      ah, 0x41
004a0fdb  0f8b2e010000             jnp       0x4a110f
004a0fe1  d955f4                   fst       dword ptr [ebp - 0xc]
004a0fe4  d95dfc                   fstp      dword ptr [ebp - 4]
004a0fe7  8d4dfc                   lea       ecx, [ebp - 4]
004a0fea  8d55f4                   lea       edx, [ebp - 0xc]
004a0fed  6844ed5b00               push      0x5bed44
004a0ff2  c70528ed5b0094ed5b00     mov       dword ptr [0x5bed28], 0x5bed94 ; bits=94ed5b00, f32=8.442257122977436e-39
004a0ffc  890d30ed5b00             mov       dword ptr [0x5bed30], ecx ; bits=00000000, f32=0.0
004a1002  c70544ed5b00d9000000     mov       dword ptr [0x5bed44], 0xd9 ; bits=00000000, f32=0.0
004a100c  881d48ed5b00             mov       byte ptr [0x5bed48], bl
004a1012  881d49ed5b00             mov       byte ptr [0x5bed49], bl
004a1018  891d4ced5b00             mov       dword ptr [0x5bed4c], ebx ; bits=00000000, f32=0.0
004a101e  891d54ed5b00             mov       dword ptr [0x5bed54], ebx ; bits=00000000, f32=0.0
004a1024  881d58ed5b00             mov       byte ptr [0x5bed58], bl
004a102a  881d59ed5b00             mov       byte ptr [0x5bed59], bl
004a1030  891d60ed5b00             mov       dword ptr [0x5bed60], ebx ; bits=00000000, f32=0.0
004a1036  c70568ed5b0001000000     mov       dword ptr [0x5bed68], 1 ; bits=00000000, f32=0.0
004a1040  89156ced5b00             mov       dword ptr [0x5bed6c], edx ; bits=00000000, f32=0.0
004a1046  66c70570ed5b000900       mov       word ptr [0x5bed70], 9 ; bits=0000
004a104f  66891d72ed5b00           mov       word ptr [0x5bed72], bx ; bits=0000
004a1056  ff1574f35b00             call      dword ptr [0x5bf374] ; bits=80524c00, f32=7.009093131573872e-39
004a105c  a194ed5b00               mov       eax, dword ptr [0x5bed94] ; bits=00000000, f32=0.0
004a1061  83c404                   add       esp, 4
004a1064  3bc3                     cmp       eax, ebx
004a1066  0f84ce000000             je        0x4a113a
004a106c  d945fc                   fld       dword ptr [ebp - 4]
004a106f  d955f8                   fst       dword ptr [ebp - 8]
004a1072  d945fc                   fld       dword ptr [ebp - 4]
004a1075  d9e1                     fabs
004a1077  d95508                   fst       dword ptr [ebp + 8]
004a107a  d81d3cdd5400             fcomp     dword ptr [0x54dd3c] ; __real@3f000000, bits=0000003f, f32=0.5
004a1080  dfe0                     fnstsw    ax
004a1082  f6c441                   test      ah, 0x41
004a1085  0f8a2effffff             jp        0x4a0fb9
004a108b  d9c0                     fld       st(0)
004a108d  d8c9                     fmul      st(1)
004a108f  d90514dd5400             fld       dword ptr [0x54dd14] ; ?a5@?1??g_asin@@9@9, bits=b3a22e3d, f32=0.04263563081622124
004a1095  5b                       pop       ebx
004a1096  d8c9                     fmul      st(1)
004a1098  d80510dd5400             fadd      dword ptr [0x54dd10] ; ?a4@?1??g_asin@@9@9, bits=3f72c33c, f32=0.023858187720179558
004a109e  d8c9                     fmul      st(1)
004a10a0  d8050cdd5400             fadd      dword ptr [0x54dd0c] ; ?a3@?1??g_asin@@9@9, bits=d3923a3d, f32=0.04555017873644829
004a10a6  d8c9                     fmul      st(1)
004a10a8  d80508dd5400             fadd      dword ptr [0x54dd08] ; ?a2@?1??g_asin@@9@9, bits=6c7c993d, f32=0.07494434714317322
004a10ae  d8c9                     fmul      st(1)
004a10b0  d80504dd5400             fadd      dword ptr [0x54dd04] ; ?a1@?1??g_asin@@9@9, bits=feaa2a3e, f32=0.1666679084300995
004a10b6  d8c9                     fmul      st(1)
004a10b8  d80568dc5400             fadd      dword ptr [0x54dc68] ; __real@3f800000, bits=0000803f, f32=1.0
004a10be  deca                     fmulp     st(2)
004a10c0  ddd8                     fstp      st(0)
004a10c2  8be5                     mov       esp, ebp
004a10c4  5d                       pop       ebp
004a10c5  c3                       ret
004a10c6  d9c0                     fld       st(0)
004a10c8  d8c9                     fmul      st(1)
004a10ca  d90530dd5400             fld       dword ptr [0x54dd30] ; ?b6@?1??g_asin@@9@9, bits=88b7833e, f32=0.2572596073150635
004a10d0  5b                       pop       ebx
004a10d1  d8c9                     fmul      st(1)
004a10d3  d8052cdd5400             fadd      dword ptr [0x54dd2c] ; ?b5@?1??g_asin@@9@9, bits=46c9bebe, f32=-0.3726293444633484
004a10d9  d8c9                     fmul      st(1)
004a10db  d80528dd5400             fadd      dword ptr [0x54dd28] ; ?b4@?1??g_asin@@9@9, bits=84a4a63e, f32=0.3254739046096802
004a10e1  d8c9                     fmul      st(1)
004a10e3  d80524dd5400             fadd      dword ptr [0x54dd24] ; ?b3@?1??g_asin@@9@9, bits=31ad9dbd, f32=-0.07699049264192581
004a10e9  d8c9                     fmul      st(1)
004a10eb  d80520dd5400             fadd      dword ptr [0x54dd20] ; ?b2@?1??g_asin@@9@9, bits=2155d43d, f32=0.10367799550294876
004a10f1  d8c9                     fmul      st(1)
004a10f3  d8051cdd5400             fadd      dword ptr [0x54dd1c] ; ?b1@?1??g_asin@@9@9, bits=64f1263e, f32=0.163030207157135
004a10f9  d8c9                     fmul      st(1)
004a10fb  d80518dd5400             fadd      dword ptr [0x54dd18] ; ?b0@?1??g_asin@@9@9, bits=372d4a39, f32=0.00019281065033283085
004a1101  d80568dc5400             fadd      dword ptr [0x54dc68] ; __real@3f800000, bits=0000803f, f32=1.0
004a1107  deca                     fmulp     st(2)
004a1109  ddd8                     fstp      st(0)
004a110b  8be5                     mov       esp, ebp
004a110d  5d                       pop       ebp
004a110e  c3                       ret
004a110f  8d4508                   lea       eax, [ebp + 8]
004a1112  ddd8                     fstp      st(0)
004a1114  50                       push      eax
004a1115  e8a6080000               call      0x4a19c0 ; _g_acos
004a111a  dc2df8dc5400             fsubr     qword ptr [0x54dcf8] ; ?hpi@?1??g_asin@@9@9, bits=c0036054fb21f93f, f64=1.5707963272
004a1120  d945f8                   fld       dword ptr [ebp - 8]
004a1123  d81d6cdc5400             fcomp     dword ptr [0x54dc6c] ; __real@00000000, bits=00000000, f32=0.0
004a1129  83c404                   add       esp, 4
004a112c  dfe0                     fnstsw    ax
004a112e  f6c405                   test      ah, 5
004a1131  7a3e                     jp        0x4a1171
004a1133  d9e0                     fchs
004a1135  5b                       pop       ebx
004a1136  8be5                     mov       esp, ebp
004a1138  5d                       pop       ebp
004a1139  c3                       ret
004a113a  803dc5ec5b0001           cmp       byte ptr [0x5becc5], 1
004a1141  750b                     jne       0x4a114e
004a1143  d90588dc5400             fld       dword ptr [0x54dc88] ; _NaN_F, bits=0000c07f, f32=nan
004a1149  5b                       pop       ebx
004a114a  8be5                     mov       esp, ebp
004a114c  5d                       pop       ebp
004a114d  c3                       ret
004a114e  d945f8                   fld       dword ptr [ebp - 8]
004a1151  d81d6cdc5400             fcomp     dword ptr [0x54dc6c] ; __real@00000000, bits=00000000, f32=0.0
004a1157  dfe0                     fnstsw    ax
004a1159  2500410000               and       eax, 0x4100
004a115e  750b                     jne       0x4a116b
004a1160  d90538dd5400             fld       dword ptr [0x54dd38] ; __real@3fc90fdb, bits=db0fc93f, f32=1.5707963705062866
004a1166  5b                       pop       ebx
004a1167  8be5                     mov       esp, ebp
004a1169  5d                       pop       ebp
004a116a  c3                       ret
004a116b  d90534dd5400             fld       dword ptr [0x54dd34] ; __real@bfc90fdb, bits=db0fc9bf, f32=-1.5707963705062866
004a1171  5b                       pop       ebx
004a1172  8be5                     mov       esp, ebp
004a1174  5d                       pop       ebp
004a1175  c3                       ret
004a1176  90                       nop
004a1177  90                       nop
004a1178  90                       nop
004a1179  90                       nop
004a117a  90                       nop
004a117b  90                       nop
004a117c  90                       nop
004a117d  90                       nop
004a117e  90                       nop
004a117f  90                       nop
