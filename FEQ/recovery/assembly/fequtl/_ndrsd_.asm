; _ndrsd_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x28600
00428600  55                       push      ebp
00428601  8bec                     mov       ebp, esp
00428603  53                       push      ebx
00428604  8b4d08                   mov       ecx, dword ptr [ebp + 8]
00428607  8b01                     mov       eax, dword ptr [ecx]
00428609  8d1df8915600             lea       ebx, [0x5691f8] ; bits=b0915600, f32=7.950115497112703e-39
0042860f  894384                   mov       dword ptr [ebx - 0x7c], eax
00428612  8d4380                   lea       eax, [ebx - 0x80]
00428615  50                       push      eax
00428616  8d4384                   lea       eax, [ebx - 0x7c]
00428619  50                       push      eax
0042861a  6810b2e900               push      0xe9b210 ; _ndrsdc_
0042861f  e85cf20400               call      0x477880 ; _lktk_
00428624  83c40c                   add       esp, 0xc
00428627  d90518b2e900             fld       dword ptr [0xe9b218]
0042862d  d84b80                   fmul      dword ptr [ebx - 0x80]
00428630  d82514b2e900             fsub      dword ptr [0xe9b214]
00428636  d83514b2e900             fdiv      dword ptr [0xe9b214]
0042863c  5b                       pop       ebx
0042863d  8be5                     mov       esp, ebp
0042863f  5d                       pop       ebp
00428640  c3                       ret
00428641  90                       nop
00428642  8da42400000000           lea       esp, [esp]
00428649  8da42400000000           lea       esp, [esp]
