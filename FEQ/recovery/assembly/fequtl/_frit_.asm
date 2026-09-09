; _frit_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x71660
00471660  55                       push      ebp
00471661  8bec                     mov       ebp, esp
00471663  53                       push      ebx
00471664  56                       push      esi
00471665  8b5d08                   mov       ebx, dword ptr [ebp + 8]
00471668  68484db600               push      0xb64d48
0047166d  8d35b8e95900             lea       esi, [0x59e9b8] ; bits=00000000, f32=0.0
00471673  8d4694                   lea       eax, [esi - 0x6c]
00471676  50                       push      eax
00471677  8d4698                   lea       eax, [esi - 0x68]
0047167a  50                       push      eax
0047167b  8d46a0                   lea       eax, [esi - 0x60]
0047167e  50                       push      eax
0047167f  684c4db600               push      0xb64d4c
00471684  8d03                     lea       eax, [ebx]
00471686  50                       push      eax
00471687  685c4db600               push      0xb64d5c
0047168c  68544db600               push      0xb64d54
00471691  e81a5f0000               call      0x4775b0 ; _xlookw_
00471696  83c420                   add       esp, 0x20
00471699  8d469c                   lea       eax, [esi - 0x64]
0047169c  50                       push      eax
0047169d  8d4690                   lea       eax, [esi - 0x70]
004716a0  50                       push      eax
004716a1  68504db600               push      0xb64d50
004716a6  8d768c                   lea       esi, [esi - 0x74]
004716a9  56                       push      esi
004716aa  8d03                     lea       eax, [ebx]
004716ac  50                       push      eax
004716ad  68584db600               push      0xb64d58
004716b2  e88929fdff               call      0x444040 ; _lktab_
004716b7  83c418                   add       esp, 0x18
004716ba  d9054c4db600             fld       dword ptr [0xb64d4c]
004716c0  d81d38e95900             fcomp     dword ptr [0x59e938] ; bits=00000000, f32=0.0
004716c6  dfe0                     fnstsw    ax
004716c8  9e                       sahf
004716c9  0f8a0c000000             jp        0x4716db
004716cf  770a                     ja        0x4716db
004716d1  c7054c4db6000000803f     mov       dword ptr [0xb64d4c], 0x3f800000
004716db  d905404db600             fld       dword ptr [0xb64d40] ; _ritcom_
004716e1  d805444db600             fadd      dword ptr [0xb64d44]
004716e7  d9c0                     fld       st(0)
004716e9  d825484db600             fsub      dword ptr [0xb64d48]
004716ef  d9054c4db600             fld       dword ptr [0xb64d4c]
004716f5  d83d504db600             fdivr     dword ptr [0xb64d50]
004716fb  dee9                     fsubp     st(1)
004716fd  def1                     fdivrp    st(1)
004716ff  5e                       pop       esi
00471700  5b                       pop       ebx
00471701  8be5                     mov       esp, ebp
00471703  5d                       pop       ebp
00471704  c3                       ret
00471705  8d642400                 lea       esp, [esp]
00471709  8da42400000000           lea       esp, [esp]
