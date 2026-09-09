; _sort_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x76c10
00476c10  55                       push      ebp
00476c11  8bec                     mov       ebp, esp
00476c13  b804000000               mov       eax, 4
00476c18  e8e3230700               call      0x4e9000 ; __alloca_probe
00476c1d  53                       push      ebx
00476c1e  8b4d08                   mov       ecx, dword ptr [ebp + 8]
00476c21  8b550c                   mov       edx, dword ptr [ebp + 0xc]
00476c24  8b01                     mov       eax, dword ptr [ecx]
00476c26  83c0ff                   add       eax, -1
00476c29  3d00000000               cmp       eax, 0
00476c2e  8945fc                   mov       dword ptr [ebp - 4], eax
00476c31  7e35                     jle       0x476c68
00476c33  bb02000000               mov       ebx, 2
00476c38  89d9                     mov       ecx, ebx
00476c3a  d9449afc                 fld       dword ptr [edx + ebx*4 - 4]
00476c3e  83f901                   cmp       ecx, 1
00476c41  7e1a                     jle       0x476c5d
00476c43  d9448af8                 fld       dword ptr [edx + ecx*4 - 8]
00476c47  d8d1                     fcom      st(1)
00476c49  dfe0                     fnstsw    ax
00476c4b  9e                       sahf
00476c4c  0f8a09000000             jp        0x476c5b
00476c52  7607                     jbe       0x476c5b
00476c54  d95c8afc                 fstp      dword ptr [edx + ecx*4 - 4]
00476c58  49                       dec       ecx
00476c59  ebe3                     jmp       0x476c3e
00476c5b  ddd8                     fstp      st(0)
00476c5d  d95c8afc                 fstp      dword ptr [edx + ecx*4 - 4]
00476c61  43                       inc       ebx
00476c62  836dfc01                 sub       dword ptr [ebp - 4], 1
00476c66  75d0                     jne       0x476c38
00476c68  b800000000               mov       eax, 0
00476c6d  5b                       pop       ebx
00476c6e  8be5                     mov       esp, ebp
00476c70  5d                       pop       ebp
00476c71  c3                       ret
00476c72  8da42400000000           lea       esp, [esp]
00476c79  8da42400000000           lea       esp, [esp]
