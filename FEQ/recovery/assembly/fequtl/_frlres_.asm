; _frlres_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x33c20
00433c20  55                       push      ebp
00433c21  8bec                     mov       ebp, esp
00433c23  8b4d08                   mov       ecx, dword ptr [ebp + 8]
00433c26  8b01                     mov       eax, dword ptr [ecx]
00433c28  890574aee900             mov       dword ptr [0xe9ae74], eax
00433c2e  e86d040000               call      0x4340a0 ; _fndhpl_
00433c33  833d80aee90000           cmp       dword ptr [0xe9ae80], 0
00433c3a  7409                     je        0x433c45
00433c3c  833d80aee90005           cmp       dword ptr [0xe9ae80], 5
00433c43  7514                     jne       0x433c59
00433c45  d90578aee900             fld       dword ptr [0xe9ae78]
00433c4b  d83d74aee900             fdivr     dword ptr [0xe9ae74]
00433c51  d82d30f55600             fsubr     dword ptr [0x56f530] ; bits=0000803f, f32=1.0
00433c57  eb06                     jmp       0x433c5f
00433c59  d90534f55600             fld       dword ptr [0x56f534] ; bits=000080bf, f32=-1.0
00433c5f  8be5                     mov       esp, ebp
00433c61  5d                       pop       ebp
00433c62  c3                       ret
00433c63  8d9b00000000             lea       ebx, [ebx]
00433c69  8da42400000000           lea       esp, [esp]
