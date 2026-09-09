; _setext_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x27020
00427020  81ec74030000             sub       esp, 0x374
00427026  55                       push      ebp
00427027  53                       push      ebx
00427028  56                       push      esi
00427029  57                       push      edi
0042702a  8b842488030000           mov       eax, dword ptr [esp + 0x388]
00427031  8b8c248c030000           mov       ecx, dword ptr [esp + 0x38c]
00427038  8b942490030000           mov       edx, dword ptr [esp + 0x390]
0042703f  898424c4010000           mov       dword ptr [esp + 0x1c4], eax
00427046  898c24c0010000           mov       dword ptr [esp + 0x1c0], ecx
0042704d  899424bc010000           mov       dword ptr [esp + 0x1bc], edx
00427054  8b8424c8030000           mov       eax, dword ptr [esp + 0x3c8]
0042705b  c70000000000             mov       dword ptr [eax], 0
00427061  8b8424cc030000           mov       eax, dword ptr [esp + 0x3cc]
00427068  c70000000000             mov       dword ptr [eax], 0
0042706e  8b8424d0030000           mov       eax, dword ptr [esp + 0x3d0]
00427075  c70000000000             mov       dword ptr [eax], 0
0042707b  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
00427082  c70000000000             mov       dword ptr [eax], 0
00427088  8b8424d8030000           mov       eax, dword ptr [esp + 0x3d8]
0042708f  c70000000000             mov       dword ptr [eax], 0
00427095  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
0042709c  c70000000000             mov       dword ptr [eax], 0
004270a2  8b8424c0030000           mov       eax, dword ptr [esp + 0x3c0]
004270a9  c700515904e9             mov       dword ptr [eax], 0xe9045951
004270af  8b0524007501             mov       eax, dword ptr [0x1750024]
004270b5  8b2c85ac837601           mov       ebp, dword ptr [eax*4 + 0x17683ac]
004270bc  83fd00                   cmp       ebp, 0
004270bf  7e3a                     jle       0x4270fb
004270c1  b901000000               mov       ecx, 1
004270c6  83fd02                   cmp       ebp, 2
004270c9  7c21                     jl        0x4270ec
004270cb  c7048df8e27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2f8], 0
004270d6  c7048dfce27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2fc], 0
004270e1  83c102                   add       ecx, 2
004270e4  83ed02                   sub       ebp, 2
004270e7  83fd02                   cmp       ebp, 2
004270ea  7ddf                     jge       0x4270cb
004270ec  85ed                     test      ebp, ebp
004270ee  740b                     je        0x4270fb
004270f0  c7048df8e27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2f8], 0
004270fb  c705a875520000000000     mov       dword ptr [0x5275a8], 0 ; bits=00000000, f32=0.0
00427105  b801000000               mov       eax, 1
0042710a  c7054076520000000000     mov       dword ptr [0x527640], 0 ; bits=00000000, f32=0.0
00427114  8b8c24b4030000           mov       ecx, dword ptr [esp + 0x3b4]
0042711b  898424b4010000           mov       dword ptr [esp + 0x1b4], eax
00427122  898c24b0010000           mov       dword ptr [esp + 0x1b0], ecx
00427129  8b8424b4010000           mov       eax, dword ptr [esp + 0x1b4]
00427130  8b148578dc7b01           mov       edx, dword ptr [eax*4 + 0x17bdc78]
00427137  8915ac755200             mov       dword ptr [0x5275ac], edx ; bits=00000000, f32=0.0
0042713d  40                       inc       eax
0042713e  8b9424b0010000           mov       edx, dword ptr [esp + 0x1b0]
00427145  8b0dac755200             mov       ecx, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
0042714b  8b5c8afc                 mov       ebx, dword ptr [edx + ecx*4 - 4]
0042714f  83fbff                   cmp       ebx, -1
00427152  898424b4010000           mov       dword ptr [esp + 0x1b4], eax
00427159  0f8467370000             je        0x42a8c6
0042715f  83fb10                   cmp       ebx, 0x10
00427162  7309                     jae       0x42716d
00427164  8b049d74775200           mov       eax, dword ptr [ebx*4 + 0x527774]
0042716b  ffe0                     jmp       eax
0042716d  8d055c755200             lea       eax, [0x52755c] ; bits=09820000, f32=4.664782457890884e-41
00427173  899c2480030000           mov       dword ptr [esp + 0x380], ebx
0042717a  8d8c2480030000           lea       ecx, [esp + 0x380]
00427181  894834                   mov       dword ptr [eax + 0x34], ecx
00427184  50                       push      eax
00427185  e876540900               call      0x4bc600 ; _jwe_ilst
0042718a  83c404                   add       esp, 4
0042718d  6844745200               push      0x527444
00427192  e8b9620900               call      0x4bd450 ; _jwe_xstp
00427197  83c404                   add       esp, 4
0042719a  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
004271a1  89ca                     mov       edx, ecx
004271a3  8b0490                   mov       eax, dword ptr [eax + edx*4]
004271a6  8905b0755200             mov       dword ptr [0x5275b0], eax ; bits=00000000, f32=0.0
004271ac  8b2c85a0cbe501           mov       ebp, dword ptr [eax*4 + 0x1e5cba0]
004271b3  83fd05                   cmp       ebp, 5
004271b6  7309                     jae       0x4271c1
004271b8  8b0cad60775200           mov       ecx, dword ptr [ebp*4 + 0x527760]
004271bf  ffe1                     jmp       ecx
004271c1  6830755200               push      0x527530
004271c6  e835540900               call      0x4bc600 ; _jwe_ilst
004271cb  83c404                   add       esp, 4
004271ce  6838745200               push      0x527438
004271d3  e878620900               call      0x4bd450 ; _jwe_xstp
004271d8  83c404                   add       esp, 4
004271db  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
004271e2  8d00                     lea       eax, [eax]
004271e4  50                       push      eax
004271e5  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
004271ec  8d00                     lea       eax, [eax]
004271ee  50                       push      eax
004271ef  8b8424e0030000           mov       eax, dword ptr [esp + 0x3e0]
004271f6  8d00                     lea       eax, [eax]
004271f8  50                       push      eax
004271f9  8b8424e8030000           mov       eax, dword ptr [esp + 0x3e8]
00427200  8d00                     lea       eax, [eax]
00427202  50                       push      eax
00427203  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
0042720a  8d00                     lea       eax, [eax]
0042720c  50                       push      eax
0042720d  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
00427214  8d00                     lea       eax, [eax]
00427216  50                       push      eax
00427217  68a8755200               push      0x5275a8
0042721c  8b8424bc030000           mov       eax, dword ptr [esp + 0x3bc]
00427223  8d00                     lea       eax, [eax]
00427225  50                       push      eax
00427226  8b8424dc010000           mov       eax, dword ptr [esp + 0x1dc]
0042722d  8d08                     lea       ecx, [eax]
0042722f  51                       push      ecx
00427230  8b8c24bc030000           mov       ecx, dword ptr [esp + 0x3bc]
00427237  8d09                     lea       ecx, [ecx]
00427239  51                       push      ecx
0042723a  68b0755200               push      0x5275b0
0042723f  8b8c24f0010000           mov       ecx, dword ptr [esp + 0x1f0]
00427246  8d11                     lea       edx, [ecx]
00427248  52                       push      edx
00427249  e8a250feff               call      0x40c2f0 ; _setinx_
0042724e  83c430                   add       esp, 0x30
00427251  e9d3feffff               jmp       0x427129
00427256  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
0042725d  8d00                     lea       eax, [eax]
0042725f  50                       push      eax
00427260  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
00427267  8d00                     lea       eax, [eax]
00427269  50                       push      eax
0042726a  8b8424e0030000           mov       eax, dword ptr [esp + 0x3e0]
00427271  8d00                     lea       eax, [eax]
00427273  50                       push      eax
00427274  8b8424e8030000           mov       eax, dword ptr [esp + 0x3e8]
0042727b  8d00                     lea       eax, [eax]
0042727d  50                       push      eax
0042727e  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
00427285  8d00                     lea       eax, [eax]
00427287  50                       push      eax
00427288  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
0042728f  8d00                     lea       eax, [eax]
00427291  50                       push      eax
00427292  68a8755200               push      0x5275a8
00427297  8b8424bc030000           mov       eax, dword ptr [esp + 0x3bc]
0042729e  8d00                     lea       eax, [eax]
004272a0  50                       push      eax
004272a1  8b8424dc010000           mov       eax, dword ptr [esp + 0x1dc]
004272a8  8d08                     lea       ecx, [eax]
004272aa  51                       push      ecx
004272ab  8b8c24bc030000           mov       ecx, dword ptr [esp + 0x3bc]
004272b2  8d09                     lea       ecx, [ecx]
004272b4  51                       push      ecx
004272b5  68b0755200               push      0x5275b0
004272ba  8b8c24f0010000           mov       ecx, dword ptr [esp + 0x1f0]
004272c1  8d11                     lea       edx, [ecx]
004272c3  52                       push      edx
004272c4  e88733feff               call      0x40a650 ; _setinw_
004272c9  83c430                   add       esp, 0x30
004272cc  e958feffff               jmp       0x427129
004272d1  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
004272d8  8d00                     lea       eax, [eax]
004272da  50                       push      eax
004272db  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
004272e2  8d00                     lea       eax, [eax]
004272e4  50                       push      eax
004272e5  8b8424e0030000           mov       eax, dword ptr [esp + 0x3e0]
004272ec  8d00                     lea       eax, [eax]
004272ee  50                       push      eax
004272ef  8b8424e8030000           mov       eax, dword ptr [esp + 0x3e8]
004272f6  8d00                     lea       eax, [eax]
004272f8  50                       push      eax
004272f9  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
00427300  8d00                     lea       eax, [eax]
00427302  50                       push      eax
00427303  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
0042730a  8d00                     lea       eax, [eax]
0042730c  50                       push      eax
0042730d  68a8755200               push      0x5275a8
00427312  8b8424bc030000           mov       eax, dword ptr [esp + 0x3bc]
00427319  8d00                     lea       eax, [eax]
0042731b  50                       push      eax
0042731c  8b8424dc010000           mov       eax, dword ptr [esp + 0x1dc]
00427323  8d08                     lea       ecx, [eax]
00427325  51                       push      ecx
00427326  8b8c24bc030000           mov       ecx, dword ptr [esp + 0x3bc]
0042732d  8d09                     lea       ecx, [ecx]
0042732f  51                       push      ecx
00427330  68b0755200               push      0x5275b0
00427335  8b8c24f0010000           mov       ecx, dword ptr [esp + 0x1f0]
0042733c  8d11                     lea       edx, [ecx]
0042733e  52                       push      edx
0042733f  e85c19feff               call      0x408ca0 ; _seticx_
00427344  83c430                   add       esp, 0x30
00427347  e9ddfdffff               jmp       0x427129
0042734c  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
00427353  8d00                     lea       eax, [eax]
00427355  50                       push      eax
00427356  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
0042735d  8d00                     lea       eax, [eax]
0042735f  50                       push      eax
00427360  8b8424e0030000           mov       eax, dword ptr [esp + 0x3e0]
00427367  8d00                     lea       eax, [eax]
00427369  50                       push      eax
0042736a  8b8424e8030000           mov       eax, dword ptr [esp + 0x3e8]
00427371  8d00                     lea       eax, [eax]
00427373  50                       push      eax
00427374  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
0042737b  8d00                     lea       eax, [eax]
0042737d  50                       push      eax
0042737e  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
00427385  8d00                     lea       eax, [eax]
00427387  50                       push      eax
00427388  68a8755200               push      0x5275a8
0042738d  8b8424bc030000           mov       eax, dword ptr [esp + 0x3bc]
00427394  8d00                     lea       eax, [eax]
00427396  50                       push      eax
00427397  8b8424dc010000           mov       eax, dword ptr [esp + 0x1dc]
0042739e  8d08                     lea       ecx, [eax]
004273a0  51                       push      ecx
004273a1  8b8c24bc030000           mov       ecx, dword ptr [esp + 0x3bc]
004273a8  8d09                     lea       ecx, [ecx]
004273aa  51                       push      ecx
004273ab  68b0755200               push      0x5275b0
004273b0  8b8c24f0010000           mov       ecx, dword ptr [esp + 0x1f0]
004273b7  8d11                     lea       edx, [ecx]
004273b9  52                       push      edx
004273ba  e841fdfdff               call      0x407100 ; _seticw_
004273bf  83c430                   add       esp, 0x30
004273c2  e962fdffff               jmp       0x427129
004273c7  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
004273ce  89ca                     mov       edx, ecx
004273d0  8b2c90                   mov       ebp, dword ptr [eax + edx*4]
004273d3  c7054076520000000000     mov       dword ptr [0x527640], 0 ; bits=00000000, f32=0.0
004273dd  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004273e3  40                       inc       eax
004273e4  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
004273ea  896c2428                 mov       dword ptr [esp + 0x28], ebp
004273ee  83fd00                   cmp       ebp, 0
004273f1  0f8edb010000             jle       0x4275d2
004273f7  8b05ac755200             mov       eax, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
004273fd  40                       inc       eax
004273fe  89c1                     mov       ecx, eax
00427400  837c242802               cmp       dword ptr [esp + 0x28], 2
00427405  0f8c23010000             jl        0x42752e
0042740b  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
00427411  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00427418  8b0488                   mov       eax, dword ptr [eax + ecx*4]
0042741b  8d14c0                   lea       edx, [eax + eax*8]
0042741e  8bbc24b8030000           mov       edi, dword ptr [esp + 0x3b8]
00427425  89442424                 mov       dword ptr [esp + 0x24], eax
00427429  8b4497dc                 mov       eax, dword ptr [edi + edx*4 - 0x24]
0042742d  89842480030000           mov       dword ptr [esp + 0x380], eax
00427434  8b442424                 mov       eax, dword ptr [esp + 0x24]
00427438  db842480030000           fild      dword ptr [esp + 0x380]
0042743f  d904855c14ff01           fld       dword ptr [eax*4 + 0x1ff145c]
00427446  da8c2480030000           fimul     dword ptr [esp + 0x380]
0042744d  dec2                     faddp     st(2)
0042744f  d9c9                     fxch      st(1)
00427451  8b7497ec                 mov       esi, dword ptr [edi + edx*4 - 0x14]
00427455  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042745b  89ea                     mov       edx, ebp
0042745d  29f2                     sub       edx, esi
0042745f  89d3                     mov       ebx, edx
00427461  83fb00                   cmp       ebx, 0
00427464  7e14                     jle       0x42747a
00427466  8b34ad28007501           mov       esi, dword ptr [ebp*4 + 0x1750028]
0042746d  29de                     sub       esi, ebx
0042746f  d9c9                     fxch      st(1)
00427471  d91cb5fce27c01           fstp      dword ptr [esi*4 + 0x17ce2fc]
00427478  eb12                     jmp       0x42748c
0042747a  8b34b5ac837601           mov       esi, dword ptr [esi*4 + 0x17683ac]
00427481  01de                     add       esi, ebx
00427483  d9c9                     fxch      st(1)
00427485  d91cb5f8e27c01           fstp      dword ptr [esi*4 + 0x17ce2f8]
0042748c  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00427493  8b6c8804                 mov       ebp, dword ptr [eax + ecx*4 + 4]
00427497  8d44ed00                 lea       eax, [ebp + ebp*8]
0042749b  8bbc24b8030000           mov       edi, dword ptr [esp + 0x3b8]
004274a2  8b5487dc                 mov       edx, dword ptr [edi + eax*4 - 0x24]
004274a6  89942480030000           mov       dword ptr [esp + 0x380], edx
004274ad  db842480030000           fild      dword ptr [esp + 0x380]
004274b4  d904ad5c14ff01           fld       dword ptr [ebp*4 + 0x1ff145c]
004274bb  da8c2480030000           fimul     dword ptr [esp + 0x380]
004274c2  dec2                     faddp     st(2)
004274c4  d9c9                     fxch      st(1)
004274c6  8b7487ec                 mov       esi, dword ptr [edi + eax*4 - 0x14]
004274ca  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004274d0  89c7                     mov       edi, eax
004274d2  29f7                     sub       edi, esi
004274d4  89fb                     mov       ebx, edi
004274d6  83fb00                   cmp       ebx, 0
004274d9  89442418                 mov       dword ptr [esp + 0x18], eax
004274dd  7e18                     jle       0x4274f7
004274df  8b442418                 mov       eax, dword ptr [esp + 0x18]
004274e3  8b348528007501           mov       esi, dword ptr [eax*4 + 0x1750028]
004274ea  29de                     sub       esi, ebx
004274ec  d9c9                     fxch      st(1)
004274ee  d91cb5fce27c01           fstp      dword ptr [esi*4 + 0x17ce2fc]
004274f5  eb12                     jmp       0x427509
004274f7  8b34b5ac837601           mov       esi, dword ptr [esi*4 + 0x17683ac]
004274fe  01de                     add       esi, ebx
00427500  d9c9                     fxch      st(1)
00427502  d91cb5f8e27c01           fstp      dword ptr [esi*4 + 0x17ce2f8]
00427509  83c102                   add       ecx, 2
0042750c  8b442428                 mov       eax, dword ptr [esp + 0x28]
00427510  83e802                   sub       eax, 2
00427513  3d02000000               cmp       eax, 2
00427518  89442428                 mov       dword ptr [esp + 0x28], eax
0042751c  0f8deffeffff             jge       0x427411
00427522  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00427528  892db8755200             mov       dword ptr [0x5275b8], ebp ; bits=00000000, f32=0.0
0042752e  8b442428                 mov       eax, dword ptr [esp + 0x28]
00427532  85c0                     test      eax, eax
00427534  0f8498000000             je        0x4275d2
0042753a  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00427541  8b0488                   mov       eax, dword ptr [eax + ecx*4]
00427544  8905b8755200             mov       dword ptr [0x5275b8], eax ; bits=00000000, f32=0.0
0042754a  8d04c0                   lea       eax, [eax + eax*8]
0042754d  8b9424b8030000           mov       edx, dword ptr [esp + 0x3b8]
00427554  8b7c82dc                 mov       edi, dword ptr [edx + eax*4 - 0x24]
00427558  89bc2480030000           mov       dword ptr [esp + 0x380], edi
0042755f  db842480030000           fild      dword ptr [esp + 0x380]
00427566  8b3db8755200             mov       edi, dword ptr [0x5275b8] ; bits=00000000, f32=0.0
0042756c  d904bd5c14ff01           fld       dword ptr [edi*4 + 0x1ff145c]
00427573  da8c2480030000           fimul     dword ptr [esp + 0x380]
0042757a  d80540765200             fadd      dword ptr [0x527640] ; bits=00000000, f32=0.0
00427580  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00427586  dbbc2460030000           fstp      xword ptr [esp + 0x360]
0042758d  8b7482ec                 mov       esi, dword ptr [edx + eax*4 - 0x14]
00427591  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00427597  89ea                     mov       edx, ebp
00427599  29f2                     sub       edx, esi
0042759b  89d3                     mov       ebx, edx
0042759d  83fb00                   cmp       ebx, 0
004275a0  7e19                     jle       0x4275bb
004275a2  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
004275a9  29d9                     sub       ecx, ebx
004275ab  dbac2460030000           fld       xword ptr [esp + 0x360]
004275b2  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
004275b9  eb17                     jmp       0x4275d2
004275bb  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004275c2  01d9                     add       ecx, ebx
004275c4  dbac2460030000           fld       xword ptr [esp + 0x360]
004275cb  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
004275d2  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
004275d8  d9e0                     fchs
004275da  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004275e0  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
004275e7  e93dfbffff               jmp       0x427129
004275ec  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
004275f3  89ca                     mov       edx, ecx
004275f5  8b3c90                   mov       edi, dword ptr [eax + edx*4]
004275f8  89ca                     mov       edx, ecx
004275fa  8b449004                 mov       eax, dword ptr [eax + edx*4 + 4]
004275fe  8905a4755200             mov       dword ptr [0x5275a4], eax ; bits=00000000, f32=0.0
00427604  d904bd9ca40102           fld       dword ptr [edi*4 + 0x201a49c]
0042760b  d804bd1c9e0002           fadd      dword ptr [edi*4 + 0x2009e1c]
00427612  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00427618  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042761e  40                       inc       eax
0042761f  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
00427625  8d3cff                   lea       edi, [edi + edi*8]
00427628  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
0042762f  8b74b8ec                 mov       esi, dword ptr [eax + edi*4 - 0x14]
00427633  46                       inc       esi
00427634  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042763a  89ea                     mov       edx, ebp
0042763c  29f2                     sub       edx, esi
0042763e  89d3                     mov       ebx, edx
00427640  83fb00                   cmp       ebx, 0
00427643  7e16                     jle       0x42765b
00427645  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
0042764c  29d9                     sub       ecx, ebx
0042764e  c7048dfce27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2fc], 0x3f800000
00427659  eb14                     jmp       0x42766f
0042765b  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00427662  01d9                     add       ecx, ebx
00427664  c7048df8e27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2f8], 0x3f800000
0042766f  8b05a4755200             mov       eax, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
00427675  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
0042767b  d824851c9e0002           fsub      dword ptr [eax*4 + 0x2009e1c]
00427682  d824859ca40102           fsub      dword ptr [eax*4 + 0x201a49c]
00427689  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
0042768f  8d0cc0                   lea       ecx, [eax + eax*8]
00427692  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00427699  8b7488ec                 mov       esi, dword ptr [eax + ecx*4 - 0x14]
0042769d  46                       inc       esi
0042769e  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004276a4  89e9                     mov       ecx, ebp
004276a6  29f1                     sub       ecx, esi
004276a8  89cb                     mov       ebx, ecx
004276aa  83fb00                   cmp       ebx, 0
004276ad  7e16                     jle       0x4276c5
004276af  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
004276b6  29d9                     sub       ecx, ebx
004276b8  c7048dfce27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2fc], 0xbf800000
004276c3  eb14                     jmp       0x4276d9
004276c5  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004276cc  01d9                     add       ecx, ebx
004276ce  c7048df8e27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2f8], 0xbf800000
004276d9  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
004276df  d9e0                     fchs
004276e1  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004276e7  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
004276ee  e936faffff               jmp       0x427129
004276f3  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
004276fa  89ca                     mov       edx, ecx
004276fc  8b6c9004                 mov       ebp, dword ptr [eax + edx*4 + 4]
00427700  89ca                     mov       edx, ecx
00427702  8b7c900c                 mov       edi, dword ptr [eax + edx*4 + 0xc]
00427706  6800765200               push      0x527600
0042770b  6814765200               push      0x527614
00427710  8b9424b0030000           mov       edx, dword ptr [esp + 0x3b0]
00427717  8d12                     lea       edx, [edx]
00427719  52                       push      edx
0042771a  68a80eeb01               push      0x1eb0ea8
0042771f  68e8c5f301               push      0x1f3c5e8
00427724  68283cf201               push      0x1f23c28
00427729  8d00                     lea       eax, [eax]
0042772b  50                       push      eax
0042772c  8b8424d4030000           mov       eax, dword ptr [esp + 0x3d4]
00427733  8944245c                 mov       dword ptr [esp + 0x5c], eax
00427737  8d10                     lea       edx, [eax]
00427739  52                       push      edx
0042773a  8b9424d0030000           mov       edx, dword ptr [esp + 0x3d0]
00427741  8d12                     lea       edx, [edx]
00427743  52                       push      edx
00427744  68b80e6c01               push      0x16c0eb8
00427749  8b9424c4030000           mov       edx, dword ptr [esp + 0x3c4]
00427750  8d12                     lea       edx, [edx]
00427752  52                       push      edx
00427753  8b9424c0030000           mov       edx, dword ptr [esp + 0x3c0]
0042775a  8d12                     lea       edx, [edx]
0042775c  52                       push      edx
0042775d  68b40e6c01               push      0x16c0eb4
00427762  68ac755200               push      0x5275ac
00427767  e834b4ffff               call      0x422ba0 ; _contrl_
0042776c  83c438                   add       esp, 0x38
0042776f  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00427775  40                       inc       eax
00427776  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
0042777c  d90500765200             fld       dword ptr [0x527600] ; bits=00000000, f32=0.0
00427782  d82cbd5c14ff01           fsubr     dword ptr [edi*4 + 0x1ff145c]
00427789  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
0042778f  8b442440                 mov       eax, dword ptr [esp + 0x40]
00427793  8d3cff                   lea       edi, [edi + edi*8]
00427796  8b74b8ec                 mov       esi, dword ptr [eax + edi*4 - 0x14]
0042779a  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004277a0  89c2                     mov       edx, eax
004277a2  29f2                     sub       edx, esi
004277a4  89d3                     mov       ebx, edx
004277a6  83fb00                   cmp       ebx, 0
004277a9  8944243c                 mov       dword ptr [esp + 0x3c], eax
004277ad  7e1a                     jle       0x4277c9
004277af  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
004277b3  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
004277ba  29d9                     sub       ecx, ebx
004277bc  c7048dfce27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2fc], 0x3f800000
004277c7  eb14                     jmp       0x4277dd
004277c9  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004277d0  01d9                     add       ecx, ebx
004277d2  c7048df8e27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2f8], 0x3f800000
004277dd  8d4ced00                 lea       ecx, [ebp + ebp*8]
004277e1  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
004277e8  8b7488ec                 mov       esi, dword ptr [eax + ecx*4 - 0x14]
004277ec  46                       inc       esi
004277ed  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004277f3  89e9                     mov       ecx, ebp
004277f5  29f1                     sub       ecx, esi
004277f7  89cb                     mov       ebx, ecx
004277f9  83fb00                   cmp       ebx, 0
004277fc  7e1a                     jle       0x427818
004277fe  d90514765200             fld       dword ptr [0x527614] ; bits=00000000, f32=0.0
00427804  d9e0                     fchs
00427806  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
0042780d  29d9                     sub       ecx, ebx
0042780f  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00427816  eb18                     jmp       0x427830
00427818  d90514765200             fld       dword ptr [0x527614] ; bits=00000000, f32=0.0
0042781e  d9e0                     fchs
00427820  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00427827  01d9                     add       ecx, ebx
00427829  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00427830  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
00427836  d9e0                     fchs
00427838  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042783e  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
00427845  e9dff8ffff               jmp       0x427129
0042784a  8b9c24b4030000           mov       ebx, dword ptr [esp + 0x3b4]
00427851  89c8                     mov       eax, ecx
00427853  8b1483                   mov       edx, dword ptr [ebx + eax*4]
00427856  89c8                     mov       eax, ecx
00427858  8b6c8304                 mov       ebp, dword ptr [ebx + eax*4 + 4]
0042785c  89c8                     mov       eax, ecx
0042785e  8b7c8308                 mov       edi, dword ptr [ebx + eax*4 + 8]
00427862  893da4755200             mov       dword ptr [0x5275a4], edi ; bits=00000000, f32=0.0
00427868  83fa0a                   cmp       edx, 0xa
0042786b  89542478                 mov       dword ptr [esp + 0x78], edx
0042786f  730d                     jae       0x42787e
00427871  8b442478                 mov       eax, dword ptr [esp + 0x78]
00427875  8b0c8538775200           mov       ecx, dword ptr [eax*4 + 0x527738]
0042787c  ffe1                     jmp       ecx
0042787e  8d05ec745200             lea       eax, [0x5274ec] ; bits=09820000, f32=4.664782457890884e-41
00427884  8b4c2478                 mov       ecx, dword ptr [esp + 0x78]
00427888  898c2480030000           mov       dword ptr [esp + 0x380], ecx
0042788f  8d8c2480030000           lea       ecx, [esp + 0x380]
00427896  894840                   mov       dword ptr [eax + 0x40], ecx
00427899  50                       push      eax
0042789a  e8614d0900               call      0x4bc600 ; _jwe_ilst
0042789f  83c404                   add       esp, 4
004278a2  682c745200               push      0x52742c
004278a7  e8a45b0900               call      0x4bd450 ; _jwe_xstp
004278ac  83c404                   add       esp, 4
004278af  6820765200               push      0x527620
004278b4  682c765200               push      0x52762c
004278b9  6818765200               push      0x527618
004278be  6824765200               push      0x527624
004278c3  6840765200               push      0x527640
004278c8  89d8                     mov       eax, ebx
004278ca  8d00                     lea       eax, [eax]
004278cc  50                       push      eax
004278cd  68a0a40102               push      0x201a4a0
004278d2  68209e0002               push      0x2009e20
004278d7  686014ff01               push      0x1ff1460
004278dc  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
004278e3  8d00                     lea       eax, [eax]
004278e5  50                       push      eax
004278e6  6884725200               push      0x527284
004278eb  8b8424c8030000           mov       eax, dword ptr [esp + 0x3c8]
004278f2  8d00                     lea       eax, [eax]
004278f4  50                       push      eax
004278f5  8b8424e0030000           mov       eax, dword ptr [esp + 0x3e0]
004278fc  8d00                     lea       eax, [eax]
004278fe  50                       push      eax
004278ff  68b40e6c01               push      0x16c0eb4
00427904  68ac755200               push      0x5275ac
00427909  e8b2b9ffff               call      0x4232c0 ; _excon_
0042790e  83c43c                   add       esp, 0x3c
00427911  e9bf030000               jmp       0x427cd5
00427916  6820765200               push      0x527620
0042791b  682c765200               push      0x52762c
00427920  6818765200               push      0x527618
00427925  6824765200               push      0x527624
0042792a  6840765200               push      0x527640
0042792f  89d8                     mov       eax, ebx
00427931  8d00                     lea       eax, [eax]
00427933  50                       push      eax
00427934  68bc3bfb01               push      0x1fb3bbc
00427939  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00427940  8d00                     lea       eax, [eax]
00427942  50                       push      eax
00427943  686014ff01               push      0x1ff1460
00427948  68a0a40102               push      0x201a4a0
0042794d  68209e0002               push      0x2009e20
00427952  6884725200               push      0x527284
00427957  68ac755200               push      0x5275ac
0042795c  e85f89ffff               call      0x4202c0 ; _bdftab_
00427961  83c434                   add       esp, 0x34
00427964  e96c030000               jmp       0x427cd5
00427969  6820765200               push      0x527620
0042796e  682c765200               push      0x52762c
00427973  6818765200               push      0x527618
00427978  6824765200               push      0x527624
0042797d  6840765200               push      0x527640
00427982  68b40e6c01               push      0x16c0eb4
00427987  8b8424c8030000           mov       eax, dword ptr [esp + 0x3c8]
0042798e  8d00                     lea       eax, [eax]
00427990  50                       push      eax
00427991  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00427998  8d00                     lea       eax, [eax]
0042799a  50                       push      eax
0042799b  686014ff01               push      0x1ff1460
004279a0  68a0a40102               push      0x201a4a0
004279a5  68209e0002               push      0x2009e20
004279aa  68c414e001               push      0x1e014c4
004279af  68c014e001               push      0x1e014c0 ; _gravcm_
004279b4  6884725200               push      0x527284
004279b9  89d8                     mov       eax, ebx
004279bb  8d00                     lea       eax, [eax]
004279bd  50                       push      eax
004279be  68ac755200               push      0x5275ac
004279c3  e8f8e3ffff               call      0x425dc0 ; _pump_
004279c8  83c440                   add       esp, 0x40
004279cb  e905030000               jmp       0x427cd5
004279d0  6820765200               push      0x527620
004279d5  682c765200               push      0x52762c
004279da  6818765200               push      0x527618
004279df  6824765200               push      0x527624
004279e4  6840765200               push      0x527640
004279e9  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
004279f0  8d00                     lea       eax, [eax]
004279f2  50                       push      eax
004279f3  68a0a40102               push      0x201a4a0
004279f8  68209e0002               push      0x2009e20
004279fd  686014ff01               push      0x1ff1460
00427a02  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
00427a09  8d00                     lea       eax, [eax]
00427a0b  50                       push      eax
00427a0c  89d8                     mov       eax, ebx
00427a0e  8d00                     lea       eax, [eax]
00427a10  50                       push      eax
00427a11  6884725200               push      0x527284
00427a16  8b8424cc030000           mov       eax, dword ptr [esp + 0x3cc]
00427a1d  8d00                     lea       eax, [eax]
00427a1f  50                       push      eax
00427a20  68b40e6c01               push      0x16c0eb4
00427a25  68c014e001               push      0x1e014c0 ; _gravcm_
00427a2a  68ac755200               push      0x5275ac
00427a2f  e8dca6ffff               call      0x422110 ; _cbrid_
00427a34  83c440                   add       esp, 0x40
00427a37  e999020000               jmp       0x427cd5
00427a3c  6820765200               push      0x527620
00427a41  682c765200               push      0x52762c
00427a46  6818765200               push      0x527618
00427a4b  6824765200               push      0x527624
00427a50  6840765200               push      0x527640
00427a55  89d8                     mov       eax, ebx
00427a57  8d00                     lea       eax, [eax]
00427a59  50                       push      eax
00427a5a  68a0a40102               push      0x201a4a0
00427a5f  68209e0002               push      0x2009e20
00427a64  686014ff01               push      0x1ff1460
00427a69  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
00427a70  8d00                     lea       eax, [eax]
00427a72  50                       push      eax
00427a73  6884725200               push      0x527284
00427a78  8b8424c8030000           mov       eax, dword ptr [esp + 0x3c8]
00427a7f  8d00                     lea       eax, [eax]
00427a81  50                       push      eax
00427a82  8b8424e0030000           mov       eax, dword ptr [esp + 0x3e0]
00427a89  8d00                     lea       eax, [eax]
00427a8b  50                       push      eax
00427a8c  68b40e6c01               push      0x16c0eb4
00427a91  68c014e001               push      0x1e014c0 ; _gravcm_
00427a96  68ac755200               push      0x5275ac
00427a9b  e8607effff               call      0x41f900 ; _abrexp_
00427aa0  83c440                   add       esp, 0x40
00427aa3  e92d020000               jmp       0x427cd5
00427aa8  89d8                     mov       eax, ebx
00427aaa  8b0dac755200             mov       ecx, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
00427ab0  837c881400               cmp       dword ptr [eax + ecx*4 + 0x14], 0
00427ab5  7e62                     jle       0x427b19
00427ab7  6820765200               push      0x527620
00427abc  682c765200               push      0x52762c
00427ac1  6818765200               push      0x527618
00427ac6  6824765200               push      0x527624
00427acb  6840765200               push      0x527640
00427ad0  68a0a40102               push      0x201a4a0
00427ad5  68209e0002               push      0x2009e20
00427ada  686014ff01               push      0x1ff1460
00427adf  89d8                     mov       eax, ebx
00427ae1  8d00                     lea       eax, [eax]
00427ae3  50                       push      eax
00427ae4  8b8424cc030000           mov       eax, dword ptr [esp + 0x3cc]
00427aeb  8d00                     lea       eax, [eax]
00427aed  50                       push      eax
00427aee  8b8424c4030000           mov       eax, dword ptr [esp + 0x3c4]
00427af5  8d00                     lea       eax, [eax]
00427af7  50                       push      eax
00427af8  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
00427aff  8d00                     lea       eax, [eax]
00427b01  50                       push      eax
00427b02  68b40e6c01               push      0x16c0eb4
00427b07  68ac755200               push      0x5275ac
00427b0c  e83f370000               call      0x42b250 ; _twod6_
00427b11  83c438                   add       esp, 0x38
00427b14  e9bc010000               jmp       0x427cd5
00427b19  6820765200               push      0x527620
00427b1e  682c765200               push      0x52762c
00427b23  6818765200               push      0x527618
00427b28  6824765200               push      0x527624
00427b2d  6840765200               push      0x527640
00427b32  68a0a40102               push      0x201a4a0
00427b37  68209e0002               push      0x2009e20
00427b3c  686014ff01               push      0x1ff1460
00427b41  89d8                     mov       eax, ebx
00427b43  8d00                     lea       eax, [eax]
00427b45  50                       push      eax
00427b46  8b8424cc030000           mov       eax, dword ptr [esp + 0x3cc]
00427b4d  8d00                     lea       eax, [eax]
00427b4f  50                       push      eax
00427b50  8b8424c4030000           mov       eax, dword ptr [esp + 0x3c4]
00427b57  8d00                     lea       eax, [eax]
00427b59  50                       push      eax
00427b5a  8b8424dc030000           mov       eax, dword ptr [esp + 0x3dc]
00427b61  8d00                     lea       eax, [eax]
00427b63  50                       push      eax
00427b64  68b40e6c01               push      0x16c0eb4
00427b69  68ac755200               push      0x5275ac
00427b6e  e81d310000               call      0x42ac90 ; _twod14_
00427b73  83c438                   add       esp, 0x38
00427b76  e95a010000               jmp       0x427cd5
00427b7b  8b8c24c0010000           mov       ecx, dword ptr [esp + 0x1c0]
00427b82  8b8424b0030000           mov       eax, dword ptr [esp + 0x3b0]
00427b89  dd01                     fld       qword ptr [ecx]
00427b8b  dc28                     fsubr     qword ptr [eax]
00427b8d  dd1d98755200             fstp      qword ptr [0x527598] ; bits=0000000000000000, f64=0.0
00427b93  6820765200               push      0x527620
00427b98  682c765200               push      0x52762c
00427b9d  6818765200               push      0x527618
00427ba2  6824765200               push      0x527624
00427ba7  6840765200               push      0x527640
00427bac  68c014e001               push      0x1e014c0 ; _gravcm_
00427bb1  6898755200               push      0x527598
00427bb6  68b40e6c01               push      0x16c0eb4
00427bbb  8b8424bc030000           mov       eax, dword ptr [esp + 0x3bc]
00427bc2  8d00                     lea       eax, [eax]
00427bc4  50                       push      eax
00427bc5  6820ab0202               push      0x202ab20
00427bca  686007fd01               push      0x1fd0760
00427bcf  686014ff01               push      0x1ff1460
00427bd4  68a0a40102               push      0x201a4a0
00427bd9  68209e0002               push      0x2009e20
00427bde  6884725200               push      0x527284
00427be3  89d8                     mov       eax, ebx
00427be5  8d00                     lea       eax, [eax]
00427be7  50                       push      eax
00427be8  68ac755200               push      0x5275ac
00427bed  e8ae91ffff               call      0x420da0 ; _bdfwr_
00427bf2  83c444                   add       esp, 0x44
00427bf5  e9db000000               jmp       0x427cd5
00427bfa  8b8c24c0010000           mov       ecx, dword ptr [esp + 0x1c0]
00427c01  8b8424b0030000           mov       eax, dword ptr [esp + 0x3b0]
00427c08  dd01                     fld       qword ptr [ecx]
00427c0a  dc28                     fsubr     qword ptr [eax]
00427c0c  dd1d98755200             fstp      qword ptr [0x527598] ; bits=0000000000000000, f64=0.0
00427c12  6820765200               push      0x527620
00427c17  682c765200               push      0x52762c
00427c1c  6818765200               push      0x527618
00427c21  6824765200               push      0x527624
00427c26  6840765200               push      0x527640
00427c2b  6898755200               push      0x527598
00427c30  68b40e6c01               push      0x16c0eb4
00427c35  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00427c3c  8d00                     lea       eax, [eax]
00427c3e  50                       push      eax
00427c3f  686014ff01               push      0x1ff1460
00427c44  68a0a40102               push      0x201a4a0
00427c49  68209e0002               push      0x2009e20
00427c4e  6884725200               push      0x527284
00427c53  89d8                     mov       eax, ebx
00427c55  8d00                     lea       eax, [eax]
00427c57  50                       push      eax
00427c58  68ac755200               push      0x5275ac
00427c5d  e81ecdffff               call      0x424980 ; _mchgat_
00427c62  83c438                   add       esp, 0x38
00427c65  eb6e                     jmp       0x427cd5
00427c67  8b8c24c0010000           mov       ecx, dword ptr [esp + 0x1c0]
00427c6e  8b8424b0030000           mov       eax, dword ptr [esp + 0x3b0]
00427c75  dd01                     fld       qword ptr [ecx]
00427c77  dc28                     fsubr     qword ptr [eax]
00427c79  dd1d98755200             fstp      qword ptr [0x527598] ; bits=0000000000000000, f64=0.0
00427c7f  6820765200               push      0x527620
00427c84  682c765200               push      0x52762c
00427c89  6818765200               push      0x527618
00427c8e  6824765200               push      0x527624
00427c93  6840765200               push      0x527640
00427c98  682091fe01               push      0x1fe9120
00427c9d  6898755200               push      0x527598
00427ca2  68b40e6c01               push      0x16c0eb4
00427ca7  8b8424bc030000           mov       eax, dword ptr [esp + 0x3bc]
00427cae  8d00                     lea       eax, [eax]
00427cb0  50                       push      eax
00427cb1  686014ff01               push      0x1ff1460
00427cb6  68a0a40102               push      0x201a4a0
00427cbb  68209e0002               push      0x2009e20
00427cc0  6884725200               push      0x527284
00427cc5  8d03                     lea       eax, [ebx]
00427cc7  50                       push      eax
00427cc8  68ac755200               push      0x5275ac
00427ccd  e8be3b0000               call      0x42b890 ; _ufgate_
00427cd2  83c43c                   add       esp, 0x3c
00427cd5  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00427cdb  40                       inc       eax
00427cdc  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
00427ce2  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
00427ce8  d9e0                     fchs
00427cea  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00427cf0  d91c8df84baa01           fstp      dword ptr [ecx*4 + 0x1aa4bf8]
00427cf7  8d54ed00                 lea       edx, [ebp + ebp*8]
00427cfb  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00427d02  8b7490ec                 mov       esi, dword ptr [eax + edx*4 - 0x14]
00427d06  89c8                     mov       eax, ecx
00427d08  29f0                     sub       eax, esi
00427d0a  89c3                     mov       ebx, eax
00427d0c  83fb00                   cmp       ebx, 0
00427d0f  7e18                     jle       0x427d29
00427d11  8b0c8d28007501           mov       ecx, dword ptr [ecx*4 + 0x1750028]
00427d18  29d9                     sub       ecx, ebx
00427d1a  8b0518765200             mov       eax, dword ptr [0x527618] ; bits=00000000, f32=0.0
00427d20  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
00427d27  eb16                     jmp       0x427d3f
00427d29  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00427d30  01d9                     add       ecx, ebx
00427d32  8b0518765200             mov       eax, dword ptr [0x527618] ; bits=00000000, f32=0.0
00427d38  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
00427d3f  46                       inc       esi
00427d40  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00427d46  89e9                     mov       ecx, ebp
00427d48  29f1                     sub       ecx, esi
00427d4a  89cb                     mov       ebx, ecx
00427d4c  83fb00                   cmp       ebx, 0
00427d4f  7e18                     jle       0x427d69
00427d51  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
00427d58  29d9                     sub       ecx, ebx
00427d5a  8b0524765200             mov       eax, dword ptr [0x527624] ; bits=00000000, f32=0.0
00427d60  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
00427d67  eb16                     jmp       0x427d7f
00427d69  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00427d70  01d9                     add       ecx, ebx
00427d72  8b0524765200             mov       eax, dword ptr [0x527624] ; bits=00000000, f32=0.0
00427d78  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
00427d7f  8b05a4755200             mov       eax, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
00427d85  8d04c0                   lea       eax, [eax + eax*8]
00427d88  8b8c24b8030000           mov       ecx, dword ptr [esp + 0x3b8]
00427d8f  8b7481ec                 mov       esi, dword ptr [ecx + eax*4 - 0x14]
00427d93  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00427d99  89e9                     mov       ecx, ebp
00427d9b  29f1                     sub       ecx, esi
00427d9d  89cb                     mov       ebx, ecx
00427d9f  83fb00                   cmp       ebx, 0
00427da2  7e18                     jle       0x427dbc
00427da4  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
00427dab  29d9                     sub       ecx, ebx
00427dad  8b0520765200             mov       eax, dword ptr [0x527620] ; bits=00000000, f32=0.0
00427db3  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
00427dba  eb16                     jmp       0x427dd2
00427dbc  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00427dc3  01d9                     add       ecx, ebx
00427dc5  8b0520765200             mov       eax, dword ptr [0x527620] ; bits=00000000, f32=0.0
00427dcb  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
00427dd2  46                       inc       esi
00427dd3  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00427dd9  89e9                     mov       ecx, ebp
00427ddb  29f1                     sub       ecx, esi
00427ddd  89cb                     mov       ebx, ecx
00427ddf  83fb00                   cmp       ebx, 0
00427de2  7e1b                     jle       0x427dff
00427de4  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
00427deb  29d9                     sub       ecx, ebx
00427ded  8b052c765200             mov       eax, dword ptr [0x52762c] ; bits=00000000, f32=0.0
00427df3  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
00427dfa  e92af3ffff               jmp       0x427129
00427dff  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00427e06  01d9                     add       ecx, ebx
00427e08  8b052c765200             mov       eax, dword ptr [0x52762c] ; bits=00000000, f32=0.0
00427e0e  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
00427e15  e90ff3ffff               jmp       0x427129
00427e1a  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00427e21  89ca                     mov       edx, ecx
00427e23  8b1c90                   mov       ebx, dword ptr [eax + edx*4]
00427e26  83fb03                   cmp       ebx, 3
00427e29  895c2478                 mov       dword ptr [esp + 0x78], ebx
00427e2d  7507                     jne       0x427e36
00427e2f  bd01000000               mov       ebp, 1
00427e34  eb06                     jmp       0x427e3c
00427e36  8b442478                 mov       eax, dword ptr [esp + 0x78]
00427e3a  89c5                     mov       ebp, eax
00427e3c  8b8c24b4030000           mov       ecx, dword ptr [esp + 0x3b4]
00427e43  8b1dac755200             mov       ebx, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
00427e49  8b449904                 mov       eax, dword ptr [ecx + ebx*4 + 4]
00427e4d  8905b8755200             mov       dword ptr [0x5275b8], eax ; bits=00000000, f32=0.0
00427e53  8b449908                 mov       eax, dword ptr [ecx + ebx*4 + 8]
00427e57  8b54990c                 mov       edx, dword ptr [ecx + ebx*4 + 0xc]
00427e5b  8915b4755200             mov       dword ptr [0x5275b4], edx ; bits=00000000, f32=0.0
00427e61  8b549914                 mov       edx, dword ptr [ecx + ebx*4 + 0x14]
00427e65  8915a0765200             mov       dword ptr [0x5276a0], edx ; bits=00000000, f32=0.0
00427e6b  8b15a0765200             mov       edx, dword ptr [0x5276a0] ; bits=00000000, f32=0.0
00427e71  891510765200             mov       dword ptr [0x527610], edx ; bits=00000000, f32=0.0
00427e77  8b54991c                 mov       edx, dword ptr [ecx + ebx*4 + 0x1c]
00427e7b  8915a0765200             mov       dword ptr [0x5276a0], edx ; bits=00000000, f32=0.0
00427e81  d905a0765200             fld       dword ptr [0x5276a0] ; bits=00000000, f32=0.0
00427e87  dbbc2454030000           fstp      xword ptr [esp + 0x354]
00427e8e  8b549920                 mov       edx, dword ptr [ecx + ebx*4 + 0x20]
00427e92  8915a0765200             mov       dword ptr [0x5276a0], edx ; bits=00000000, f32=0.0
00427e98  d90510765200             fld       dword ptr [0x527610] ; bits=00000000, f32=0.0
00427e9e  d80da0765200             fmul      dword ptr [0x5276a0] ; bits=00000000, f32=0.0
00427ea4  d91d10765200             fstp      dword ptr [0x527610] ; bits=00000000, f32=0.0
00427eaa  837c992400               cmp       dword ptr [ecx + ebx*4 + 0x24], 0
00427eaf  89442470                 mov       dword ptr [esp + 0x70], eax
00427eb3  7e38                     jle       0x427eed
00427eb5  6814765200               push      0x527614
00427eba  68b4755200               push      0x5275b4
00427ebf  6868765200               push      0x527668
00427ec4  8b8424bc030000           mov       eax, dword ptr [esp + 0x3bc]
00427ecb  8d00                     lea       eax, [eax]
00427ecd  50                       push      eax
00427ece  8d449924                 lea       eax, [ecx + ebx*4 + 0x24]
00427ed2  50                       push      eax
00427ed3  e8d8e20000               call      0x4361b0 ; _lktstab_
00427ed8  83c414                   add       esp, 0x14
00427edb  d90510765200             fld       dword ptr [0x527610] ; bits=00000000, f32=0.0
00427ee1  d80d68765200             fmul      dword ptr [0x527668] ; bits=00000000, f32=0.0
00427ee7  d91d10765200             fstp      dword ptr [0x527610] ; bits=00000000, f32=0.0
00427eed  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00427ef3  40                       inc       eax
00427ef4  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
00427efa  8b05b8755200             mov       eax, dword ptr [0x5275b8] ; bits=00000000, f32=0.0
00427f00  8d0cc0                   lea       ecx, [eax + eax*8]
00427f03  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00427f0a  8b5c88ec                 mov       ebx, dword ptr [eax + ecx*4 - 0x14]
00427f0e  01eb                     add       ebx, ebp
00427f10  89d8                     mov       eax, ebx
00427f12  48                       dec       eax
00427f13  89c6                     mov       esi, eax
00427f15  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00427f1b  89ea                     mov       edx, ebp
00427f1d  29f2                     sub       edx, esi
00427f1f  89d3                     mov       ebx, edx
00427f21  83fb00                   cmp       ebx, 0
00427f24  7e16                     jle       0x427f3c
00427f26  8b2cad28007501           mov       ebp, dword ptr [ebp*4 + 0x1750028]
00427f2d  29dd                     sub       ebp, ebx
00427f2f  c704adfce27c010000803f   mov       dword ptr [ebp*4 + 0x17ce2fc], 0x3f800000
00427f3a  eb14                     jmp       0x427f50
00427f3c  8b2cb5ac837601           mov       ebp, dword ptr [esi*4 + 0x17683ac]
00427f43  01dd                     add       ebp, ebx
00427f45  c704adf8e27c010000803f   mov       dword ptr [ebp*4 + 0x17ce2f8], 0x3f800000
00427f50  837c247803               cmp       dword ptr [esp + 0x78], 3
00427f55  751a                     jne       0x427f71
00427f57  68c0745200               push      0x5274c0
00427f5c  e89f460900               call      0x4bc600 ; _jwe_ilst
00427f61  83c404                   add       esp, 4
00427f64  6820745200               push      0x527420
00427f69  e8e2540900               call      0x4bd450 ; _jwe_xstp
00427f6e  83c404                   add       esp, 4
00427f71  837c247802               cmp       dword ptr [esp + 0x78], 2
00427f76  7464                     je        0x427fdc
00427f78  d90510765200             fld       dword ptr [0x527610] ; bits=00000000, f32=0.0
00427f7e  dbac2454030000           fld       xword ptr [esp + 0x354]
00427f85  dff1                     fcompi    st(1)
00427f87  ddd8                     fstp      st(0)
00427f89  0f8a0f000000             jp        0x427f9e
00427f8f  760d                     jbe       0x427f9e
00427f91  dbac2454030000           fld       xword ptr [esp + 0x354]
00427f98  d91d10765200             fstp      dword ptr [0x527610] ; bits=00000000, f32=0.0
00427f9e  837c247000               cmp       dword ptr [esp + 0x70], 0
00427fa3  7d0e                     jge       0x427fb3
00427fa5  d90510765200             fld       dword ptr [0x527610] ; bits=00000000, f32=0.0
00427fab  d9e0                     fchs
00427fad  d91d10765200             fstp      dword ptr [0x527610] ; bits=00000000, f32=0.0
00427fb3  837c247801               cmp       dword ptr [esp + 0x78], 1
00427fb8  0f8525040000             jne       0x4283e3
00427fbe  8b05b8755200             mov       eax, dword ptr [0x5275b8] ; bits=00000000, f32=0.0
00427fc4  d90510765200             fld       dword ptr [0x527610] ; bits=00000000, f32=0.0
00427fca  d82c855c14ff01           fsubr     dword ptr [eax*4 + 0x1ff145c]
00427fd1  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00427fd7  e907040000               jmp       0x4283e3
00427fdc  d90510765200             fld       dword ptr [0x527610] ; bits=00000000, f32=0.0
00427fe2  dbac2454030000           fld       xword ptr [esp + 0x354]
00427fe9  dff1                     fcompi    st(1)
00427feb  ddd8                     fstp      st(0)
00427fed  0f8a0f000000             jp        0x428002
00427ff3  760d                     jbe       0x428002
00427ff5  dbac2454030000           fld       xword ptr [esp + 0x354]
00427ffc  d91d10765200             fstp      dword ptr [0x527610] ; bits=00000000, f32=0.0
00428002  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00428009  837c88e400               cmp       dword ptr [eax + ecx*4 - 0x1c], 0
0042800e  89442468                 mov       dword ptr [esp + 0x68], eax
00428012  7f25                     jg        0x428039
00428014  8b05b8755200             mov       eax, dword ptr [0x5275b8] ; bits=00000000, f32=0.0
0042801a  d904859ca40102           fld       dword ptr [eax*4 + 0x201a49c]
00428021  d804851c9e0002           fadd      dword ptr [eax*4 + 0x2009e1c]
00428028  d82510765200             fsub      dword ptr [0x527610] ; bits=00000000, f32=0.0
0042802e  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00428034  e9aa030000               jmp       0x4283e3
00428039  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00428040  8b15ac755200             mov       edx, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
00428046  837c901000               cmp       dword ptr [eax + edx*4 + 0x10], 0
0042804b  89442464                 mov       dword ptr [esp + 0x64], eax
0042804f  89542460                 mov       dword ptr [esp + 0x60], edx
00428053  0f8fdc010000             jg        0x428235
00428059  8b442468                 mov       eax, dword ptr [esp + 0x68]
0042805d  8b5488e0                 mov       edx, dword ptr [eax + ecx*4 - 0x20]
00428061  8b1495a435f101           mov       edx, dword ptr [edx*4 + 0x1f135a4]
00428068  891548765200             mov       dword ptr [0x527648], edx ; bits=00000000, f32=0.0
0042806e  8b2db8755200             mov       ebp, dword ptr [0x5275b8] ; bits=00000000, f32=0.0
00428074  d904ad5c07fd01           fld       dword ptr [ebp*4 + 0x1fd075c]
0042807b  d9c0                     fld       st(0)
0042807d  d80cad5c07fd01           fmul      dword ptr [ebp*4 + 0x1fd075c]
00428084  dec9                     fmulp     st(1)
00428086  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0042808c  d83548765200             fdiv      dword ptr [0x527648] ; bits=00000000, f32=0.0
00428092  d904ad5c14ff01           fld       dword ptr [ebp*4 + 0x1ff145c]
00428099  d80cad5c14ff01           fmul      dword ptr [ebp*4 + 0x1ff145c]
004280a0  dff1                     fcompi    st(1)
004280a2  ddd8                     fstp      st(0)
004280a4  0f8a02000000             jp        0x4280ac
004280aa  771f                     ja        0x4280cb
004280ac  d904ad9ca40102           fld       dword ptr [ebp*4 + 0x201a49c]
004280b3  d804ad1c9e0002           fadd      dword ptr [ebp*4 + 0x2009e1c]
004280ba  d82510765200             fsub      dword ptr [0x527610] ; bits=00000000, f32=0.0
004280c0  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
004280c6  e918030000               jmp       0x4283e3
004280cb  8b542464                 mov       edx, dword ptr [esp + 0x64]
004280cf  8b442460                 mov       eax, dword ptr [esp + 0x60]
004280d3  c744821001000000         mov       dword ptr [edx + eax*4 + 0x10], 1
004280db  8b442468                 mov       eax, dword ptr [esp + 0x68]
004280df  8b4488e8                 mov       eax, dword ptr [eax + ecx*4 - 0x18]
004280e3  8905a0755200             mov       dword ptr [0x5275a0], eax ; bits=00000000, f32=0.0
004280e9  68f0755200               push      0x5275f0
004280ee  68d8755200               push      0x5275d8
004280f3  68fc755200               push      0x5275fc
004280f8  68e0755200               push      0x5275e0
004280fd  6808765200               push      0x527608
00428102  6848765200               push      0x527648
00428107  68cc755200               push      0x5275cc
0042810c  89ea                     mov       edx, ebp
0042810e  8d3c951c9e0002           lea       edi, [edx*4 + 0x2009e1c]
00428115  57                       push      edi
00428116  68a0755200               push      0x5275a0
0042811b  e8d0260100               call      0x43a7f0 ; _xlkt20_
00428120  83c424                   add       esp, 0x24
00428123  89e8                     mov       eax, ebp
00428125  d904855c14ff01           fld       dword ptr [eax*4 + 0x1ff145c]
0042812c  dbbc2448030000           fstp      xword ptr [esp + 0x348]
00428133  dbac2448030000           fld       xword ptr [esp + 0x348]
0042813a  dbac2448030000           fld       xword ptr [esp + 0x348]
00428141  dec9                     fmulp     st(1)
00428143  d905cc755200             fld       dword ptr [0x5275cc] ; bits=00000000, f32=0.0
00428149  d9c0                     fld       st(0)
0042814b  d80dcc755200             fmul      dword ptr [0x5275cc] ; bits=00000000, f32=0.0
00428151  d9c0                     fld       st(0)
00428153  d8ca                     fmul      st(2)
00428155  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0042815b  d90548765200             fld       dword ptr [0x527648] ; bits=00000000, f32=0.0
00428161  d9c9                     fxch      st(1)
00428163  d83548765200             fdiv      dword ptr [0x527648] ; bits=00000000, f32=0.0
00428169  deec                     fsubp     st(4)
0042816b  d9cb                     fxch      st(3)
0042816d  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00428173  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00428179  d9c9                     fxch      st(1)
0042817b  d80d08765200             fmul      dword ptr [0x527608] ; bits=00000000, f32=0.0
00428181  d9ca                     fxch      st(2)
00428183  d80d48765200             fmul      dword ptr [0x527648] ; bits=00000000, f32=0.0
00428189  defa                     fdivp     st(2)
0042818b  d9c9                     fxch      st(1)
0042818d  d82d0c725200             fsubr     dword ptr [0x52720c] ; bits=00004040, f32=3.0
00428193  dec9                     fmulp     st(1)
00428195  d9e0                     fchs
00428197  dbbc243c030000           fstp      xword ptr [esp + 0x33c]
0042819e  83fb00                   cmp       ebx, 0
004281a1  7e1f                     jle       0x4281c2
004281a3  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004281a9  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
004281b0  29d9                     sub       ecx, ebx
004281b2  dbac243c030000           fld       xword ptr [esp + 0x33c]
004281b9  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
004281c0  eb17                     jmp       0x4281d9
004281c2  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004281c9  01d9                     add       ecx, ebx
004281cb  dbac243c030000           fld       xword ptr [esp + 0x33c]
004281d2  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
004281d9  4e                       dec       esi
004281da  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004281e0  89e9                     mov       ecx, ebp
004281e2  29f1                     sub       ecx, esi
004281e4  89cb                     mov       ebx, ecx
004281e6  83fb00                   cmp       ebx, 0
004281e9  7e25                     jle       0x428210
004281eb  dbac2448030000           fld       xword ptr [esp + 0x348]
004281f2  dbac2448030000           fld       xword ptr [esp + 0x348]
004281f9  dec1                     faddp     st(1)
004281fb  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
00428202  29d9                     sub       ecx, ebx
00428204  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
0042820b  e9d3010000               jmp       0x4283e3
00428210  dbac2448030000           fld       xword ptr [esp + 0x348]
00428217  dbac2448030000           fld       xword ptr [esp + 0x348]
0042821e  dec1                     faddp     st(1)
00428220  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00428227  01d9                     add       ecx, ebx
00428229  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00428230  e9ae010000               jmp       0x4283e3
00428235  8b2db8755200             mov       ebp, dword ptr [0x5275b8] ; bits=00000000, f32=0.0
0042823b  d904ad9ca40102           fld       dword ptr [ebp*4 + 0x201a49c]
00428242  d804ad1c9e0002           fadd      dword ptr [ebp*4 + 0x2009e1c]
00428249  d90510765200             fld       dword ptr [0x527610] ; bits=00000000, f32=0.0
0042824f  dbf1                     fcomi     st(1)
00428251  d9c9                     fxch      st(1)
00428253  dbbc2430030000           fstp      xword ptr [esp + 0x330]
0042825a  dbbc2424030000           fstp      xword ptr [esp + 0x324]
00428261  0f8a06000000             jp        0x42826d
00428267  0f8750010000             ja        0x4283bd
0042826d  8b442468                 mov       eax, dword ptr [esp + 0x68]
00428271  8b4488e8                 mov       eax, dword ptr [eax + ecx*4 - 0x18]
00428275  8905a0755200             mov       dword ptr [0x5275a0], eax ; bits=00000000, f32=0.0
0042827b  68f0755200               push      0x5275f0
00428280  68d8755200               push      0x5275d8
00428285  68fc755200               push      0x5275fc
0042828a  68e0755200               push      0x5275e0
0042828f  6808765200               push      0x527608
00428294  6848765200               push      0x527648
00428299  68cc755200               push      0x5275cc
0042829e  8d14ad1c9e0002           lea       edx, [ebp*4 + 0x2009e1c]
004282a5  52                       push      edx
004282a6  68a0755200               push      0x5275a0
004282ab  e840250100               call      0x43a7f0 ; _xlkt20_
004282b0  83c424                   add       esp, 0x24
004282b3  d904ad5c14ff01           fld       dword ptr [ebp*4 + 0x1ff145c]
004282ba  dbbc2418030000           fstp      xword ptr [esp + 0x318]
004282c1  dbac2418030000           fld       xword ptr [esp + 0x318]
004282c8  dbac2418030000           fld       xword ptr [esp + 0x318]
004282cf  dec9                     fmulp     st(1)
004282d1  d905cc755200             fld       dword ptr [0x5275cc] ; bits=00000000, f32=0.0
004282d7  d9c0                     fld       st(0)
004282d9  d80dcc755200             fmul      dword ptr [0x5275cc] ; bits=00000000, f32=0.0
004282df  d9c0                     fld       st(0)
004282e1  d8ca                     fmul      st(2)
004282e3  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
004282e9  d90548765200             fld       dword ptr [0x527648] ; bits=00000000, f32=0.0
004282ef  d9c9                     fxch      st(1)
004282f1  d83548765200             fdiv      dword ptr [0x527648] ; bits=00000000, f32=0.0
004282f7  deec                     fsubp     st(4)
004282f9  d9cb                     fxch      st(3)
004282fb  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00428301  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00428307  d9c9                     fxch      st(1)
00428309  d80d08765200             fmul      dword ptr [0x527608] ; bits=00000000, f32=0.0
0042830f  d9ca                     fxch      st(2)
00428311  d80d48765200             fmul      dword ptr [0x527648] ; bits=00000000, f32=0.0
00428317  defa                     fdivp     st(2)
00428319  d9c9                     fxch      st(1)
0042831b  d82d0c725200             fsubr     dword ptr [0x52720c] ; bits=00004040, f32=3.0
00428321  dec9                     fmulp     st(1)
00428323  d9e0                     fchs
00428325  dbbc243c030000           fstp      xword ptr [esp + 0x33c]
0042832c  83fb00                   cmp       ebx, 0
0042832f  7e1f                     jle       0x428350
00428331  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428337  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042833e  29d9                     sub       ecx, ebx
00428340  dbac243c030000           fld       xword ptr [esp + 0x33c]
00428347  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
0042834e  eb17                     jmp       0x428367
00428350  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00428357  01d9                     add       ecx, ebx
00428359  dbac243c030000           fld       xword ptr [esp + 0x33c]
00428360  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00428367  4e                       dec       esi
00428368  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042836e  89e9                     mov       ecx, ebp
00428370  29f1                     sub       ecx, esi
00428372  89cb                     mov       ebx, ecx
00428374  83fb00                   cmp       ebx, 0
00428377  7e22                     jle       0x42839b
00428379  dbac2418030000           fld       xword ptr [esp + 0x318]
00428380  dbac2418030000           fld       xword ptr [esp + 0x318]
00428387  dec1                     faddp     st(1)
00428389  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
00428390  29d9                     sub       ecx, ebx
00428392  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00428399  eb48                     jmp       0x4283e3
0042839b  dbac2418030000           fld       xword ptr [esp + 0x318]
004283a2  dbac2418030000           fld       xword ptr [esp + 0x318]
004283a9  dec1                     faddp     st(1)
004283ab  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004283b2  01d9                     add       ecx, ebx
004283b4  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
004283bb  eb26                     jmp       0x4283e3
004283bd  8b442464                 mov       eax, dword ptr [esp + 0x64]
004283c1  8b4c2460                 mov       ecx, dword ptr [esp + 0x60]
004283c5  c7448810ffffffff         mov       dword ptr [eax + ecx*4 + 0x10], 0xffffffff
004283cd  dbac2430030000           fld       xword ptr [esp + 0x330]
004283d4  dbac2424030000           fld       xword ptr [esp + 0x324]
004283db  dee9                     fsubp     st(1)
004283dd  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
004283e3  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
004283e9  d9e0                     fchs
004283eb  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004283f1  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
004283f8  e92cedffff               jmp       0x427129
004283fd  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00428404  89ca                     mov       edx, ecx
00428406  8b3c90                   mov       edi, dword ptr [eax + edx*4]
00428409  893da4755200             mov       dword ptr [0x5275a4], edi ; bits=00000000, f32=0.0
0042840f  89ca                     mov       edx, ecx
00428411  8b7c9004                 mov       edi, dword ptr [eax + edx*4 + 4]
00428415  893db4755200             mov       dword ptr [0x5275b4], edi ; bits=00000000, f32=0.0
0042841b  89ca                     mov       edx, ecx
0042841d  8b6c9010                 mov       ebp, dword ptr [eax + edx*4 + 0x10]
00428421  89ca                     mov       edx, ecx
00428423  8b449018                 mov       eax, dword ptr [eax + edx*4 + 0x18]
00428427  8905a0765200             mov       dword ptr [0x5276a0], eax ; bits=00000000, f32=0.0
0042842d  d905a0765200             fld       dword ptr [0x5276a0] ; bits=00000000, f32=0.0
00428433  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428439  40                       inc       eax
0042843a  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
00428440  8d44ed00                 lea       eax, [ebp + ebp*8]
00428444  8b9424b8030000           mov       edx, dword ptr [esp + 0x3b8]
0042844b  8b7482ec                 mov       esi, dword ptr [edx + eax*4 - 0x14]
0042844f  8b15a8755200             mov       edx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428455  89d7                     mov       edi, edx
00428457  29f7                     sub       edi, esi
00428459  89fb                     mov       ebx, edi
0042845b  83fb00                   cmp       ebx, 0
0042845e  898424a4000000           mov       dword ptr [esp + 0xa4], eax
00428465  899424a0000000           mov       dword ptr [esp + 0xa0], edx
0042846c  7e1d                     jle       0x42848b
0042846e  d9c0                     fld       st(0)
00428470  8b8424a0000000           mov       eax, dword ptr [esp + 0xa0]
00428477  d9e0                     fchs
00428479  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
00428480  29d9                     sub       ecx, ebx
00428482  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00428489  eb14                     jmp       0x42849f
0042848b  d9c0                     fld       st(0)
0042848d  d9e0                     fchs
0042848f  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00428496  01d9                     add       ecx, ebx
00428498  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042849f  46                       inc       esi
004284a0  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004284a6  89c1                     mov       ecx, eax
004284a8  29f1                     sub       ecx, esi
004284aa  89cb                     mov       ebx, ecx
004284ac  83fb00                   cmp       ebx, 0
004284af  8984249c000000           mov       dword ptr [esp + 0x9c], eax
004284b6  7e1d                     jle       0x4284d5
004284b8  8b84249c000000           mov       eax, dword ptr [esp + 0x9c]
004284bf  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
004284c6  29d9                     sub       ecx, ebx
004284c8  c7048dfce27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2fc], 0x3f800000
004284d3  eb14                     jmp       0x4284e9
004284d5  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004284dc  01d9                     add       ecx, ebx
004284de  c7048df8e27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2f8], 0x3f800000
004284e9  8b05a4755200             mov       eax, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
004284ef  8d0cc0                   lea       ecx, [eax + eax*8]
004284f2  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
004284f9  8b7488ec                 mov       esi, dword ptr [eax + ecx*4 - 0x14]
004284fd  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428503  89c2                     mov       edx, eax
00428505  29f2                     sub       edx, esi
00428507  89d3                     mov       ebx, edx
00428509  83fb00                   cmp       ebx, 0
0042850c  89842498000000           mov       dword ptr [esp + 0x98], eax
00428513  898c2494000000           mov       dword ptr [esp + 0x94], ecx
0042851a  7e1d                     jle       0x428539
0042851c  d9c0                     fld       st(0)
0042851e  8b842498000000           mov       eax, dword ptr [esp + 0x98]
00428525  d9e0                     fchs
00428527  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042852e  29d9                     sub       ecx, ebx
00428530  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00428537  eb14                     jmp       0x42854d
00428539  d9c0                     fld       st(0)
0042853b  d9e0                     fchs
0042853d  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00428544  01d9                     add       ecx, ebx
00428546  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042854d  46                       inc       esi
0042854e  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428554  89c1                     mov       ecx, eax
00428556  29f1                     sub       ecx, esi
00428558  89cb                     mov       ebx, ecx
0042855a  83fb00                   cmp       ebx, 0
0042855d  89842490000000           mov       dword ptr [esp + 0x90], eax
00428564  7e1d                     jle       0x428583
00428566  8b842490000000           mov       eax, dword ptr [esp + 0x90]
0042856d  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
00428574  29d9                     sub       ecx, ebx
00428576  c7048dfce27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2fc], 0xbf800000
00428581  eb14                     jmp       0x428597
00428583  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042858a  01d9                     add       ecx, ebx
0042858c  c7048df8e27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2f8], 0xbf800000
00428597  d904ad9ca40102           fld       dword ptr [ebp*4 + 0x201a49c]
0042859e  d804ad1c9e0002           fadd      dword ptr [ebp*4 + 0x2009e1c]
004285a5  8b0da4755200             mov       ecx, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
004285ab  d8248d1c9e0002           fsub      dword ptr [ecx*4 + 0x2009e1c]
004285b2  d8248d9ca40102           fsub      dword ptr [ecx*4 + 0x201a49c]
004285b9  d904ad5c14ff01           fld       dword ptr [ebp*4 + 0x1ff145c]
004285c0  d9048d5c14ff01           fld       dword ptr [ecx*4 + 0x1ff145c]
004285c7  d9c0                     fld       st(0)
004285c9  d804ad5c14ff01           fadd      dword ptr [ebp*4 + 0x1ff145c]
004285d0  decc                     fmulp     st(4)
004285d2  d9ca                     fxch      st(2)
004285d4  dee3                     fsubrp    st(3)
004285d6  d9ca                     fxch      st(2)
004285d8  d9e0                     fchs
004285da  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004285e0  8b9424bc010000           mov       edx, dword ptr [esp + 0x1bc]
004285e7  d91c8df84baa01           fstp      dword ptr [ecx*4 + 0x1aa4bf8]
004285ee  d902                     fld       dword ptr [edx]
004285f0  d9e8                     fld1
004285f2  d822                     fsub      dword ptr [edx]
004285f4  dbbc240c030000           fstp      xword ptr [esp + 0x30c]
004285fb  dbbc2400030000           fstp      xword ptr [esp + 0x300]
00428602  d9c9                     fxch      st(1)
00428604  dbbc24f4020000           fstp      xword ptr [esp + 0x2f4]
0042860b  dbbc24e8020000           fstp      xword ptr [esp + 0x2e8]
00428612  41                       inc       ecx
00428613  890da8755200             mov       dword ptr [0x5275a8], ecx ; bits=00000000, f32=0.0
00428619  8bbc24a4000000           mov       edi, dword ptr [esp + 0xa4]
00428620  8b8c24b8030000           mov       ecx, dword ptr [esp + 0x3b8]
00428627  8b74b9ec                 mov       esi, dword ptr [ecx + edi*4 - 0x14]
0042862b  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428631  89c8                     mov       eax, ecx
00428633  29f0                     sub       eax, esi
00428635  89c3                     mov       ebx, eax
00428637  83fb00                   cmp       ebx, 0
0042863a  898c248c000000           mov       dword ptr [esp + 0x8c], ecx
00428641  7e37                     jle       0x42867a
00428643  dbac2400030000           fld       xword ptr [esp + 0x300]
0042864a  8b8424c4010000           mov       eax, dword ptr [esp + 0x1c4]
00428651  8b94248c000000           mov       edx, dword ptr [esp + 0x8c]
00428658  dc08                     fmul      qword ptr [eax]
0042865a  8b0c9528007501           mov       ecx, dword ptr [edx*4 + 0x1750028]
00428661  29d9                     sub       ecx, ebx
00428663  d99c247c030000           fstp      dword ptr [esp + 0x37c]
0042866a  8b94247c030000           mov       edx, dword ptr [esp + 0x37c]
00428671  89148dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], edx
00428678  eb2e                     jmp       0x4286a8
0042867a  dbac2400030000           fld       xword ptr [esp + 0x300]
00428681  8b8424c4010000           mov       eax, dword ptr [esp + 0x1c4]
00428688  dc08                     fmul      qword ptr [eax]
0042868a  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00428691  01d9                     add       ecx, ebx
00428693  d99c247c030000           fstp      dword ptr [esp + 0x37c]
0042869a  8b94247c030000           mov       edx, dword ptr [esp + 0x37c]
004286a1  89148df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], edx
004286a8  dbac240c030000           fld       xword ptr [esp + 0x30c]
004286af  d80cad1c91fe01           fmul      dword ptr [ebp*4 + 0x1fe911c]
004286b6  dbac24f4020000           fld       xword ptr [esp + 0x2f4]
004286bd  dbac2400030000           fld       xword ptr [esp + 0x300]
004286c4  dec9                     fmulp     st(1)
004286c6  dec1                     faddp     st(1)
004286c8  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
004286ce  8b942494000000           mov       edx, dword ptr [esp + 0x94]
004286d5  8b8c24b8030000           mov       ecx, dword ptr [esp + 0x3b8]
004286dc  8b7491ec                 mov       esi, dword ptr [ecx + edx*4 - 0x14]
004286e0  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004286e6  89ca                     mov       edx, ecx
004286e8  29f2                     sub       edx, esi
004286ea  89d3                     mov       ebx, edx
004286ec  83fb00                   cmp       ebx, 0
004286ef  898c2488000000           mov       dword ptr [esp + 0x88], ecx
004286f6  7e39                     jle       0x428731
004286f8  dbac2400030000           fld       xword ptr [esp + 0x300]
004286ff  8b8424c4010000           mov       eax, dword ptr [esp + 0x1c4]
00428706  dc08                     fmul      qword ptr [eax]
00428708  8b942488000000           mov       edx, dword ptr [esp + 0x88]
0042870f  d9e0                     fchs
00428711  8b0c9528007501           mov       ecx, dword ptr [edx*4 + 0x1750028]
00428718  29d9                     sub       ecx, ebx
0042871a  d99c247c030000           fstp      dword ptr [esp + 0x37c]
00428721  8b94247c030000           mov       edx, dword ptr [esp + 0x37c]
00428728  89148dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], edx
0042872f  eb30                     jmp       0x428761
00428731  dbac2400030000           fld       xword ptr [esp + 0x300]
00428738  8b8424c4010000           mov       eax, dword ptr [esp + 0x1c4]
0042873f  dc08                     fmul      qword ptr [eax]
00428741  d9e0                     fchs
00428743  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042874a  01d9                     add       ecx, ebx
0042874c  d99c247c030000           fstp      dword ptr [esp + 0x37c]
00428753  8b94247c030000           mov       edx, dword ptr [esp + 0x37c]
0042875a  89148df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], edx
00428761  8b05a4755200             mov       eax, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
00428767  dbac240c030000           fld       xword ptr [esp + 0x30c]
0042876e  d80c851c91fe01           fmul      dword ptr [eax*4 + 0x1fe911c]
00428775  dbac24e8020000           fld       xword ptr [esp + 0x2e8]
0042877c  dbac2400030000           fld       xword ptr [esp + 0x300]
00428783  dec9                     fmulp     st(1)
00428785  dec1                     faddp     st(1)
00428787  d82d40765200             fsubr     dword ptr [0x527640] ; bits=00000000, f32=0.0
0042878d  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00428793  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
0042879a  8b0dac755200             mov       ecx, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
004287a0  8b548808                 mov       edx, dword ptr [eax + ecx*4 + 8]
004287a4  83fa00                   cmp       edx, 0
004287a7  89942484000000           mov       dword ptr [esp + 0x84], edx
004287ae  7e1a                     jle       0x4287ca
004287b0  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
004287b6  8b842484000000           mov       eax, dword ptr [esp + 0x84]
004287bd  d80485fc43e001           fadd      dword ptr [eax*4 + 0x1e043fc]
004287c4  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
004287ca  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
004287d1  8b0dac755200             mov       ecx, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
004287d7  8b54881c                 mov       edx, dword ptr [eax + ecx*4 + 0x1c]
004287db  8915a0765200             mov       dword ptr [0x5276a0], edx ; bits=00000000, f32=0.0
004287e1  d905a0765200             fld       dword ptr [0x5276a0] ; bits=00000000, f32=0.0
004287e7  d80540765200             fadd      dword ptr [0x527640] ; bits=00000000, f32=0.0
004287ed  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
004287f3  8b448820                 mov       eax, dword ptr [eax + ecx*4 + 0x20]
004287f7  8905a0765200             mov       dword ptr [0x5276a0], eax ; bits=00000000, f32=0.0
004287fd  d905a0765200             fld       dword ptr [0x5276a0] ; bits=00000000, f32=0.0
00428803  d82d40765200             fsubr     dword ptr [0x527640] ; bits=00000000, f32=0.0
00428809  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
0042880f  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
00428815  8b8424c4010000           mov       eax, dword ptr [esp + 0x1c4]
0042881c  dc08                     fmul      qword ptr [eax]
0042881e  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00428824  8b0da4755200             mov       ecx, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
0042882a  d9048d1c9e0002           fld       dword ptr [ecx*4 + 0x2009e1c]
00428831  d804ad1c9e0002           fadd      dword ptr [ebp*4 + 0x2009e1c]
00428838  8d0d78725200             lea       ecx, [0x527278] ; bits=e0600000, f32=3.4752201915255463e-41
0042883e  d8499c                   fmul      dword ptr [ecx - 0x64]
00428841  d91dd0755200             fstp      dword ptr [0x5275d0] ; bits=00000000, f32=0.0
00428847  6814765200               push      0x527614
0042884c  68b8755200               push      0x5275b8
00428851  6810765200               push      0x527610
00428856  8d49b4                   lea       ecx, [ecx - 0x4c]
00428859  51                       push      ecx
0042885a  68d0755200               push      0x5275d0
0042885f  68b4755200               push      0x5275b4
00428864  e8d7d40000               call      0x435d40 ; _lktab_
00428869  83c418                   add       esp, 0x18
0042886c  d90514765200             fld       dword ptr [0x527614] ; bits=00000000, f32=0.0
00428872  d905c83bfb01             fld       dword ptr [0x1fb3bc8]
00428878  dff1                     fcompi    st(1)
0042887a  ddd8                     fstp      st(0)
0042887c  0f8a0e000000             jp        0x428890
00428882  760c                     jbe       0x428890
00428884  8b05c83bfb01             mov       eax, dword ptr [0x1fb3bc8]
0042888a  890514765200             mov       dword ptr [0x527614], eax ; bits=00000000, f32=0.0
00428890  46                       inc       esi
00428891  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428897  89e9                     mov       ecx, ebp
00428899  29f1                     sub       ecx, esi
0042889b  89cb                     mov       ebx, ecx
0042889d  83fb00                   cmp       ebx, 0
004288a0  7e20                     jle       0x4288c2
004288a2  d90514765200             fld       dword ptr [0x527614] ; bits=00000000, f32=0.0
004288a8  d80d14725200             fmul      dword ptr [0x527214] ; bits=0000003f, f32=0.5
004288ae  d9e0                     fchs
004288b0  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
004288b7  29d9                     sub       ecx, ebx
004288b9  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
004288c0  eb1e                     jmp       0x4288e0
004288c2  d90514765200             fld       dword ptr [0x527614] ; bits=00000000, f32=0.0
004288c8  d80d14725200             fmul      dword ptr [0x527214] ; bits=0000003f, f32=0.5
004288ce  d9e0                     fchs
004288d0  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004288d7  01d9                     add       ecx, ebx
004288d9  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
004288e0  8b8c24a4000000           mov       ecx, dword ptr [esp + 0xa4]
004288e7  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
004288ee  8b7488ec                 mov       esi, dword ptr [eax + ecx*4 - 0x14]
004288f2  46                       inc       esi
004288f3  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004288f9  89e9                     mov       ecx, ebp
004288fb  29f1                     sub       ecx, esi
004288fd  89cb                     mov       ebx, ecx
004288ff  83fb00                   cmp       ebx, 0
00428902  7e20                     jle       0x428924
00428904  d90514765200             fld       dword ptr [0x527614] ; bits=00000000, f32=0.0
0042890a  d80d14725200             fmul      dword ptr [0x527214] ; bits=0000003f, f32=0.5
00428910  d9e0                     fchs
00428912  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
00428919  29d9                     sub       ecx, ebx
0042891b  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00428922  eb1e                     jmp       0x428942
00428924  d90514765200             fld       dword ptr [0x527614] ; bits=00000000, f32=0.0
0042892a  d80d14725200             fmul      dword ptr [0x527214] ; bits=0000003f, f32=0.5
00428930  d9e0                     fchs
00428932  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00428939  01d9                     add       ecx, ebx
0042893b  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00428942  d90514765200             fld       dword ptr [0x527614] ; bits=00000000, f32=0.0
00428948  d9ee                     fldz
0042894a  dff1                     fcompi    st(1)
0042894c  ddd8                     fstp      st(0)
0042894e  0f8a60000000             jp        0x4289b4
00428954  725e                     jb        0x4289b4
00428956  68a4755200               push      0x5275a4
0042895b  6a05                     push      5
0042895d  6894765200               push      0x527694
00428962  e859490400               call      0x46d2c0 ; _getusn_
00428967  83c40c                   add       esp, 0xc
0042896a  8b0514765200             mov       eax, dword ptr [0x527614] ; bits=00000000, f32=0.0
00428970  8b0dd0755200             mov       ecx, dword ptr [0x5275d0] ; bits=00000000, f32=0.0
00428976  8d157c745200             lea       edx, [0x52747c] ; bits=09020000, f32=7.300764999132297e-43
0042897c  8984247c030000           mov       dword ptr [esp + 0x37c], eax
00428983  8d84247c030000           lea       eax, [esp + 0x37c]
0042898a  894234                   mov       dword ptr [edx + 0x34], eax
0042898d  898c2478030000           mov       dword ptr [esp + 0x378], ecx
00428994  8d842478030000           lea       eax, [esp + 0x378]
0042899b  894240                   mov       dword ptr [edx + 0x40], eax
0042899e  52                       push      edx
0042899f  e81c420900               call      0x4bcbc0 ; _jwe_isfm
004289a4  83c404                   add       esp, 4
004289a7  6814745200               push      0x527414
004289ac  e89f4a0900               call      0x4bd450 ; _jwe_xstp
004289b1  83c404                   add       esp, 4
004289b4  d90510765200             fld       dword ptr [0x527610] ; bits=00000000, f32=0.0
004289ba  d9c0                     fld       st(0)
004289bc  d82d40765200             fsubr     dword ptr [0x527640] ; bits=00000000, f32=0.0
004289c2  8b05a4755200             mov       eax, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
004289c8  d904851c84fc01           fld       dword ptr [eax*4 + 0x1fc841c]
004289cf  d9e1                     fabs
004289d1  dec1                     faddp     st(1)
004289d3  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
004289d9  d9e0                     fchs
004289db  d91c855c07fd01           fstp      dword ptr [eax*4 + 0x1fd075c]
004289e2  8b0d14765200             mov       ecx, dword ptr [0x527614] ; bits=00000000, f32=0.0
004289e8  890c851cab0202           mov       dword ptr [eax*4 + 0x202ab1c], ecx
004289ef  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
004289f5  d9e0                     fchs
004289f7  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004289fd  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
00428a04  e920e7ffff               jmp       0x427129
00428a09  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00428a10  89ca                     mov       edx, ecx
00428a12  8b0490                   mov       eax, dword ptr [eax + edx*4]
00428a15  8905b8755200             mov       dword ptr [0x5275b8], eax ; bits=00000000, f32=0.0
00428a1b  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428a21  40                       inc       eax
00428a22  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
00428a28  8b05b8755200             mov       eax, dword ptr [0x5275b8] ; bits=00000000, f32=0.0
00428a2e  8d2cc0                   lea       ebp, [eax + eax*8]
00428a31  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00428a38  8b74a8ec                 mov       esi, dword ptr [eax + ebp*4 - 0x14]
00428a3c  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428a42  89c7                     mov       edi, eax
00428a44  29f7                     sub       edi, esi
00428a46  89fb                     mov       ebx, edi
00428a48  83fb00                   cmp       ebx, 0
00428a4b  898424ac000000           mov       dword ptr [esp + 0xac], eax
00428a52  7e1d                     jle       0x428a71
00428a54  8b8424ac000000           mov       eax, dword ptr [esp + 0xac]
00428a5b  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
00428a62  29d9                     sub       ecx, ebx
00428a64  c7048dfce27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2fc], 0x3f800000
00428a6f  eb14                     jmp       0x428a85
00428a71  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00428a78  01d9                     add       ecx, ebx
00428a7a  c7048df8e27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2f8], 0x3f800000
00428a85  8b9c24b8030000           mov       ebx, dword ptr [esp + 0x3b8]
00428a8c  8b4cabe8                 mov       ecx, dword ptr [ebx + ebp*4 - 0x18]
00428a90  890da0755200             mov       dword ptr [0x5275a0], ecx ; bits=00000000, f32=0.0
00428a96  68f0755200               push      0x5275f0
00428a9b  68d8755200               push      0x5275d8
00428aa0  68fc755200               push      0x5275fc
00428aa5  68e0755200               push      0x5275e0
00428aaa  6808765200               push      0x527608
00428aaf  6848765200               push      0x527648
00428ab4  68cc755200               push      0x5275cc
00428ab9  8b0db8755200             mov       ecx, dword ptr [0x5275b8] ; bits=00000000, f32=0.0
00428abf  8d148d1c9e0002           lea       edx, [ecx*4 + 0x2009e1c]
00428ac6  52                       push      edx
00428ac7  68a0755200               push      0x5275a0
00428acc  e81f1d0100               call      0x43a7f0 ; _xlkt20_
00428ad1  83c424                   add       esp, 0x24
00428ad4  d905cc755200             fld       dword ptr [0x5275cc] ; bits=00000000, f32=0.0
00428ada  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00428ae0  d83548765200             fdiv      dword ptr [0x527648] ; bits=00000000, f32=0.0
00428ae6  d9fa                     fsqrt
00428ae8  d99c247c030000           fstp      dword ptr [esp + 0x37c]
00428aef  d984247c030000           fld       dword ptr [esp + 0x37c]
00428af6  dbbc24dc020000           fstp      xword ptr [esp + 0x2dc]
00428afd  837cabdc00               cmp       dword ptr [ebx + ebp*4 - 0x24], 0
00428b02  7d10                     jge       0x428b14
00428b04  dbac24dc020000           fld       xword ptr [esp + 0x2dc]
00428b0b  d9e0                     fchs
00428b0d  dbbc24dc020000           fstp      xword ptr [esp + 0x2dc]
00428b14  dbac24dc020000           fld       xword ptr [esp + 0x2dc]
00428b1b  d80dcc755200             fmul      dword ptr [0x5275cc] ; bits=00000000, f32=0.0
00428b21  8b05b8755200             mov       eax, dword ptr [0x5275b8] ; bits=00000000, f32=0.0
00428b27  d82c855c14ff01           fsubr     dword ptr [eax*4 + 0x1ff145c]
00428b2e  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00428b34  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
00428b3a  d9e0                     fchs
00428b3c  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428b42  d91c8df84baa01           fstp      dword ptr [ecx*4 + 0x1aa4bf8]
00428b49  46                       inc       esi
00428b4a  89c8                     mov       eax, ecx
00428b4c  29f0                     sub       eax, esi
00428b4e  89c3                     mov       ebx, eax
00428b50  8d0578725200             lea       eax, [0x527278] ; bits=e0600000, f32=3.4752201915255463e-41
00428b56  d9409c                   fld       dword ptr [eax - 0x64]
00428b59  d80dcc755200             fmul      dword ptr [0x5275cc] ; bits=00000000, f32=0.0
00428b5f  d80d08765200             fmul      dword ptr [0x527608] ; bits=00000000, f32=0.0
00428b65  d83548765200             fdiv      dword ptr [0x527648] ; bits=00000000, f32=0.0
00428b6b  d940a0                   fld       dword ptr [eax - 0x60]
00428b6e  d80d48765200             fmul      dword ptr [0x527648] ; bits=00000000, f32=0.0
00428b74  dee9                     fsubp     st(1)
00428b76  dbac24dc020000           fld       xword ptr [esp + 0x2dc]
00428b7d  dec9                     fmulp     st(1)
00428b7f  dbbc243c030000           fstp      xword ptr [esp + 0x33c]
00428b86  83fb00                   cmp       ebx, 0
00428b89  7e1c                     jle       0x428ba7
00428b8b  8b0c8d28007501           mov       ecx, dword ptr [ecx*4 + 0x1750028]
00428b92  29d9                     sub       ecx, ebx
00428b94  dbac243c030000           fld       xword ptr [esp + 0x33c]
00428b9b  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00428ba2  e982e5ffff               jmp       0x427129
00428ba7  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00428bae  01d9                     add       ecx, ebx
00428bb0  dbac243c030000           fld       xword ptr [esp + 0x33c]
00428bb7  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00428bbe  e966e5ffff               jmp       0x427129
00428bc3  6850745200               push      0x527450
00428bc8  e8333a0900               call      0x4bc600 ; _jwe_ilst
00428bcd  83c404                   add       esp, 4
00428bd0  6808745200               push      0x527408
00428bd5  e876480900               call      0x4bd450 ; _jwe_xstp
00428bda  83c404                   add       esp, 4
00428bdd  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00428be4  89ca                     mov       edx, ecx
00428be6  8b2c90                   mov       ebp, dword ptr [eax + edx*4]
00428be9  89ca                     mov       edx, ecx
00428beb  8b4c9004                 mov       ecx, dword ptr [eax + edx*4 + 4]
00428bef  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428bf5  40                       inc       eax
00428bf6  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
00428bfc  d904ad1c9e0002           fld       dword ptr [ebp*4 + 0x2009e1c]
00428c03  d9e0                     fchs
00428c05  d824ad9ca40102           fsub      dword ptr [ebp*4 + 0x201a49c]
00428c0c  d8048d1c9e0002           fadd      dword ptr [ecx*4 + 0x2009e1c]
00428c13  d8048d9ca40102           fadd      dword ptr [ecx*4 + 0x201a49c]
00428c1a  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00428c20  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428c26  8b1540765200             mov       edx, dword ptr [0x527640] ; bits=00000000, f32=0.0
00428c2c  891485f84baa01           mov       dword ptr [eax*4 + 0x1aa4bf8], edx
00428c33  8d54ed00                 lea       edx, [ebp + ebp*8]
00428c37  898424d4000000           mov       dword ptr [esp + 0xd4], eax
00428c3e  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00428c45  8b7490ec                 mov       esi, dword ptr [eax + edx*4 - 0x14]
00428c49  8b8424d4000000           mov       eax, dword ptr [esp + 0xd4]
00428c50  89c7                     mov       edi, eax
00428c52  29f7                     sub       edi, esi
00428c54  89fb                     mov       ebx, edi
00428c56  83fb00                   cmp       ebx, 0
00428c59  899424cc000000           mov       dword ptr [esp + 0xcc], edx
00428c60  7e25                     jle       0x428c87
00428c62  8b8424d4000000           mov       eax, dword ptr [esp + 0xd4]
00428c69  8b148528007501           mov       edx, dword ptr [eax*4 + 0x1750028]
00428c70  29da                     sub       edx, ebx
00428c72  42                       inc       edx
00428c73  c70495f8e27c0100000000   mov       dword ptr [edx*4 + 0x17ce2f8], 0
00428c7e  899424c8000000           mov       dword ptr [esp + 0xc8], edx
00428c85  eb1b                     jmp       0x428ca2
00428c87  8b04b5ac837601           mov       eax, dword ptr [esi*4 + 0x17683ac]
00428c8e  01d8                     add       eax, ebx
00428c90  c70485f8e27c0100000000   mov       dword ptr [eax*4 + 0x17ce2f8], 0
00428c9b  898424c8000000           mov       dword ptr [esp + 0xc8], eax
00428ca2  46                       inc       esi
00428ca3  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428ca9  89c2                     mov       edx, eax
00428cab  29f2                     sub       edx, esi
00428cad  89d3                     mov       ebx, edx
00428caf  83fb00                   cmp       ebx, 0
00428cb2  898424c4000000           mov       dword ptr [esp + 0xc4], eax
00428cb9  7e27                     jle       0x428ce2
00428cbb  8b8424c4000000           mov       eax, dword ptr [esp + 0xc4]
00428cc2  8b348528007501           mov       esi, dword ptr [eax*4 + 0x1750028]
00428cc9  29de                     sub       esi, ebx
00428ccb  89f0                     mov       eax, esi
00428ccd  40                       inc       eax
00428cce  c70485f8e27c010000803f   mov       dword ptr [eax*4 + 0x17ce2f8], 0x3f800000
00428cd9  898424c0000000           mov       dword ptr [esp + 0xc0], eax
00428ce0  eb1b                     jmp       0x428cfd
00428ce2  8b04b5ac837601           mov       eax, dword ptr [esi*4 + 0x17683ac]
00428ce9  01d8                     add       eax, ebx
00428ceb  c70485f8e27c010000803f   mov       dword ptr [eax*4 + 0x17ce2f8], 0x3f800000
00428cf6  898424c0000000           mov       dword ptr [esp + 0xc0], eax
00428cfd  8d04c9                   lea       eax, [ecx + ecx*8]
00428d00  8b9424b8030000           mov       edx, dword ptr [esp + 0x3b8]
00428d07  8b7482ec                 mov       esi, dword ptr [edx + eax*4 - 0x14]
00428d0b  8b15a8755200             mov       edx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428d11  89d7                     mov       edi, edx
00428d13  29f7                     sub       edi, esi
00428d15  89fb                     mov       ebx, edi
00428d17  83fb00                   cmp       ebx, 0
00428d1a  898424bc000000           mov       dword ptr [esp + 0xbc], eax
00428d21  899424b8000000           mov       dword ptr [esp + 0xb8], edx
00428d28  7e25                     jle       0x428d4f
00428d2a  8b8424b8000000           mov       eax, dword ptr [esp + 0xb8]
00428d31  8b148528007501           mov       edx, dword ptr [eax*4 + 0x1750028]
00428d38  29da                     sub       edx, ebx
00428d3a  42                       inc       edx
00428d3b  c70495f8e27c0100000000   mov       dword ptr [edx*4 + 0x17ce2f8], 0
00428d46  899424b4000000           mov       dword ptr [esp + 0xb4], edx
00428d4d  eb1b                     jmp       0x428d6a
00428d4f  8b04b5ac837601           mov       eax, dword ptr [esi*4 + 0x17683ac]
00428d56  01d8                     add       eax, ebx
00428d58  c70485f8e27c0100000000   mov       dword ptr [eax*4 + 0x17ce2f8], 0
00428d63  898424b4000000           mov       dword ptr [esp + 0xb4], eax
00428d6a  46                       inc       esi
00428d6b  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428d71  89c2                     mov       edx, eax
00428d73  29f2                     sub       edx, esi
00428d75  89d3                     mov       ebx, edx
00428d77  83fb00                   cmp       ebx, 0
00428d7a  898424b0000000           mov       dword ptr [esp + 0xb0], eax
00428d81  7e22                     jle       0x428da5
00428d83  8b8424b0000000           mov       eax, dword ptr [esp + 0xb0]
00428d8a  8b348528007501           mov       esi, dword ptr [eax*4 + 0x1750028]
00428d91  29de                     sub       esi, ebx
00428d93  89f0                     mov       eax, esi
00428d95  40                       inc       eax
00428d96  89c6                     mov       esi, eax
00428d98  c704b5f8e27c01000080bf   mov       dword ptr [esi*4 + 0x17ce2f8], 0xbf800000
00428da3  eb14                     jmp       0x428db9
00428da5  8b34b5ac837601           mov       esi, dword ptr [esi*4 + 0x17683ac]
00428dac  01de                     add       esi, ebx
00428dae  c704b5f8e27c01000080bf   mov       dword ptr [esi*4 + 0x17ce2f8], 0xbf800000
00428db9  d904ad5c07fd01           fld       dword ptr [ebp*4 + 0x1fd075c]
00428dc0  d9ee                     fldz
00428dc2  dbf1                     fcomi     st(1)
00428dc4  d9c9                     fxch      st(1)
00428dc6  dbbc24d0020000           fstp      xword ptr [esp + 0x2d0]
00428dcd  dbbc24c4020000           fstp      xword ptr [esp + 0x2c4]
00428dd4  0f8adb000000             jp        0x428eb5
00428dda  0f83d5000000             jae       0x428eb5
00428de0  d904ad5c14ff01           fld       dword ptr [ebp*4 + 0x1ff145c]
00428de7  d9c0                     fld       st(0)
00428de9  d80cad5c14ff01           fmul      dword ptr [ebp*4 + 0x1ff145c]
00428df0  dbac24d0020000           fld       xword ptr [esp + 0x2d0]
00428df7  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00428dfd  dbac24d0020000           fld       xword ptr [esp + 0x2d0]
00428e04  dec9                     fmulp     st(1)
00428e06  def9                     fdivp     st(1)
00428e08  d9c0                     fld       st(0)
00428e0a  d80d14725200             fmul      dword ptr [0x527214] ; bits=0000003f, f32=0.5
00428e10  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428e16  d82c85f84baa01           fsubr     dword ptr [eax*4 + 0x1aa4bf8]
00428e1d  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00428e23  8b1540765200             mov       edx, dword ptr [0x527640] ; bits=00000000, f32=0.0
00428e29  891485f84baa01           mov       dword ptr [eax*4 + 0x1aa4bf8], edx
00428e30  dbac24c4020000           fld       xword ptr [esp + 0x2c4]
00428e37  dfea                     fucompi   st(2)
00428e39  d9c9                     fxch      st(1)
00428e3b  dbbc24b8020000           fstp      xword ptr [esp + 0x2b8]
00428e42  dbbc24dc020000           fstp      xword ptr [esp + 0x2dc]
00428e49  0f8a0b000000             jp        0x428e5a
00428e4f  7509                     jne       0x428e5a
00428e51  d9e8                     fld1
00428e53  dbbc24b8020000           fstp      xword ptr [esp + 0x2b8]
00428e5a  dbac24dc020000           fld       xword ptr [esp + 0x2dc]
00428e61  dbac24b8020000           fld       xword ptr [esp + 0x2b8]
00428e68  8b8424c8000000           mov       eax, dword ptr [esp + 0xc8]
00428e6f  def9                     fdivp     st(1)
00428e71  d91c85f8e27c01           fstp      dword ptr [eax*4 + 0x17ce2f8]
00428e78  8b9424cc000000           mov       edx, dword ptr [esp + 0xcc]
00428e7f  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00428e86  8b4490e0                 mov       eax, dword ptr [eax + edx*4 - 0x20]
00428e8a  dbac24dc020000           fld       xword ptr [esp + 0x2dc]
00428e91  d80c85a435f101           fmul      dword ptr [eax*4 + 0x1f135a4]
00428e98  dbac24d0020000           fld       xword ptr [esp + 0x2d0]
00428e9f  def9                     fdivp     st(1)
00428ea1  d82d08725200             fsubr     dword ptr [0x527208] ; bits=0000803f, f32=1.0
00428ea7  8b8424c0000000           mov       eax, dword ptr [esp + 0xc0]
00428eae  d91c85f8e27c01           fstp      dword ptr [eax*4 + 0x17ce2f8]
00428eb5  d9048d5c07fd01           fld       dword ptr [ecx*4 + 0x1fd075c]
00428ebc  d9ee                     fldz
00428ebe  dbf1                     fcomi     st(1)
00428ec0  d9c9                     fxch      st(1)
00428ec2  dbbc24ac020000           fstp      xword ptr [esp + 0x2ac]
00428ec9  dbbc24a0020000           fstp      xword ptr [esp + 0x2a0]
00428ed0  0f8a53e2ffff             jp        0x427129
00428ed6  0f834de2ffff             jae       0x427129
00428edc  d9048d5c14ff01           fld       dword ptr [ecx*4 + 0x1ff145c]
00428ee3  d9c0                     fld       st(0)
00428ee5  d80c8d5c14ff01           fmul      dword ptr [ecx*4 + 0x1ff145c]
00428eec  dbac24ac020000           fld       xword ptr [esp + 0x2ac]
00428ef3  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00428ef9  dbac24ac020000           fld       xword ptr [esp + 0x2ac]
00428f00  dec9                     fmulp     st(1)
00428f02  def9                     fdivp     st(1)
00428f04  d9c0                     fld       st(0)
00428f06  d80d14725200             fmul      dword ptr [0x527214] ; bits=0000003f, f32=0.5
00428f0c  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428f12  d80485f84baa01           fadd      dword ptr [eax*4 + 0x1aa4bf8]
00428f19  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00428f1f  8b1540765200             mov       edx, dword ptr [0x527640] ; bits=00000000, f32=0.0
00428f25  891485f84baa01           mov       dword ptr [eax*4 + 0x1aa4bf8], edx
00428f2c  dbac24a0020000           fld       xword ptr [esp + 0x2a0]
00428f33  dfea                     fucompi   st(2)
00428f35  d9c9                     fxch      st(1)
00428f37  dbbc24b8020000           fstp      xword ptr [esp + 0x2b8]
00428f3e  dbbc24dc020000           fstp      xword ptr [esp + 0x2dc]
00428f45  0f8a0b000000             jp        0x428f56
00428f4b  7509                     jne       0x428f56
00428f4d  d9e8                     fld1
00428f4f  dbbc24b8020000           fstp      xword ptr [esp + 0x2b8]
00428f56  dbac24dc020000           fld       xword ptr [esp + 0x2dc]
00428f5d  dbac24b8020000           fld       xword ptr [esp + 0x2b8]
00428f64  def9                     fdivp     st(1)
00428f66  8b8424b4000000           mov       eax, dword ptr [esp + 0xb4]
00428f6d  d9e0                     fchs
00428f6f  d91c85f8e27c01           fstp      dword ptr [eax*4 + 0x17ce2f8]
00428f76  8b9424bc000000           mov       edx, dword ptr [esp + 0xbc]
00428f7d  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00428f84  8b4490e0                 mov       eax, dword ptr [eax + edx*4 - 0x20]
00428f88  dbac24dc020000           fld       xword ptr [esp + 0x2dc]
00428f8f  d80c85a435f101           fmul      dword ptr [eax*4 + 0x1f135a4]
00428f96  d8348d5c07fd01           fdiv      dword ptr [ecx*4 + 0x1fd075c]
00428f9d  d82508725200             fsub      dword ptr [0x527208] ; bits=0000803f, f32=1.0
00428fa3  d91cb5f8e27c01           fstp      dword ptr [esi*4 + 0x17ce2f8]
00428faa  e97ae1ffff               jmp       0x427129
00428faf  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00428fb6  89ca                     mov       edx, ecx
00428fb8  8b3c90                   mov       edi, dword ptr [eax + edx*4]
00428fbb  89ca                     mov       edx, ecx
00428fbd  8b449004                 mov       eax, dword ptr [eax + edx*4 + 4]
00428fc1  8b14bd1c9e0002           mov       edx, dword ptr [edi*4 + 0x2009e1c]
00428fc8  891560765200             mov       dword ptr [0x527660], edx ; bits=00000000, f32=0.0
00428fce  8b14851c9e0002           mov       edx, dword ptr [eax*4 + 0x2009e1c]
00428fd5  891564765200             mov       dword ptr [0x527664], edx ; bits=00000000, f32=0.0
00428fdb  d904bd5c14ff01           fld       dword ptr [edi*4 + 0x1ff145c]
00428fe2  d904855c14ff01           fld       dword ptr [eax*4 + 0x1ff145c]
00428fe9  8b15a8755200             mov       edx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00428fef  42                       inc       edx
00428ff0  8915a8755200             mov       dword ptr [0x5275a8], edx ; bits=00000000, f32=0.0
00428ff6  8d34ff                   lea       esi, [edi + edi*8]
00428ff9  8b9c24b8030000           mov       ebx, dword ptr [esp + 0x3b8]
00429000  8b54b3dc                 mov       edx, dword ptr [ebx + esi*4 - 0x24]
00429004  89942480030000           mov       dword ptr [esp + 0x380], edx
0042900b  d9c1                     fld       st(1)
0042900d  da8c2480030000           fimul     dword ptr [esp + 0x380]
00429014  8d2cc0                   lea       ebp, [eax + eax*8]
00429017  8b44abdc                 mov       eax, dword ptr [ebx + ebp*4 - 0x24]
0042901b  89842480030000           mov       dword ptr [esp + 0x380], eax
00429022  d9c1                     fld       st(1)
00429024  da8c2480030000           fimul     dword ptr [esp + 0x380]
0042902b  dec1                     faddp     st(1)
0042902d  d9ee                     fldz
0042902f  dff1                     fcompi    st(1)
00429031  ddd8                     fstp      st(0)
00429033  dbbc2494020000           fstp      xword ptr [esp + 0x294]
0042903a  0f8ad2020000             jp        0x429312
00429040  0f86cc020000             jbe       0x429312
00429046  dbbc246c030000           fstp      xword ptr [esp + 0x36c]
0042904d  68ec755200               push      0x5275ec
00429052  68d4755200               push      0x5275d4
00429057  68f8755200               push      0x5275f8
0042905c  68e0755200               push      0x5275e0
00429061  6850765200               push      0x527650
00429066  6804765200               push      0x527604
0042906b  6844765200               push      0x527644
00429070  68bc755200               push      0x5275bc
00429075  6860765200               push      0x527660
0042907a  8d44b3e8                 lea       eax, [ebx + esi*4 - 0x18]
0042907e  50                       push      eax
0042907f  e89c1d0100               call      0x43ae20 ; _xlkt21_
00429084  83c428                   add       esp, 0x28
00429087  68f4755200               push      0x5275f4
0042908c  68dc755200               push      0x5275dc
00429091  68f8755200               push      0x5275f8
00429096  68e0755200               push      0x5275e0
0042909b  6854765200               push      0x527654
004290a0  680c765200               push      0x52760c
004290a5  684c765200               push      0x52764c
004290aa  68c8755200               push      0x5275c8
004290af  6864765200               push      0x527664
004290b4  8d54abe8                 lea       edx, [ebx + ebp*4 - 0x18]
004290b8  52                       push      edx
004290b9  e8621d0100               call      0x43ae20 ; _xlkt21_
004290be  83c428                   add       esp, 0x28
004290c1  dbac246c030000           fld       xword ptr [esp + 0x36c]
004290c8  d835bc755200             fdiv      dword ptr [0x5275bc] ; bits=00000000, f32=0.0
004290ce  dbac2494020000           fld       xword ptr [esp + 0x294]
004290d5  d835c8755200             fdiv      dword ptr [0x5275c8] ; bits=00000000, f32=0.0
004290db  d905d4755200             fld       dword ptr [0x5275d4] ; bits=00000000, f32=0.0
004290e1  dbbc2488020000           fstp      xword ptr [esp + 0x288]
004290e8  dbac2488020000           fld       xword ptr [esp + 0x288]
004290ef  d8ca                     fmul      st(2)
004290f1  dbac246c030000           fld       xword ptr [esp + 0x36c]
004290f8  dec9                     fmulp     st(1)
004290fa  d90554765200             fld       dword ptr [0x527654] ; bits=00000000, f32=0.0
00429100  d82d50765200             fsubr     dword ptr [0x527650] ; bits=00000000, f32=0.0
00429106  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0042910c  dec1                     faddp     st(1)
0042910e  d9c1                     fld       st(1)
00429110  d80ddc755200             fmul      dword ptr [0x5275dc] ; bits=00000000, f32=0.0
00429116  dbac2494020000           fld       xword ptr [esp + 0x294]
0042911d  dec9                     fmulp     st(1)
0042911f  dee9                     fsubp     st(1)
00429121  d9e0                     fchs
00429123  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429129  d91c8df84baa01           fstp      dword ptr [ecx*4 + 0x1aa4bf8]
00429130  8b74b3ec                 mov       esi, dword ptr [ebx + esi*4 - 0x14]
00429134  89c8                     mov       eax, ecx
00429136  29f0                     sub       eax, esi
00429138  89c3                     mov       ebx, eax
0042913a  83fb00                   cmp       ebx, 0
0042913d  7e24                     jle       0x429163
0042913f  dbac2488020000           fld       xword ptr [esp + 0x288]
00429146  dbac2488020000           fld       xword ptr [esp + 0x288]
0042914d  dec1                     faddp     st(1)
0042914f  d8ca                     fmul      st(2)
00429151  8b0c8d28007501           mov       ecx, dword ptr [ecx*4 + 0x1750028]
00429158  29d9                     sub       ecx, ebx
0042915a  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00429161  eb1b                     jmp       0x42917e
00429163  dbac2488020000           fld       xword ptr [esp + 0x288]
0042916a  d8c0                     fadd      st(0)
0042916c  d8ca                     fmul      st(2)
0042916e  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429175  01d9                     add       ecx, ebx
00429177  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042917e  46                       inc       esi
0042917f  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429185  89c1                     mov       ecx, eax
00429187  29f1                     sub       ecx, esi
00429189  89cb                     mov       ebx, ecx
0042918b  83fb00                   cmp       ebx, 0
0042918e  898424ec000000           mov       dword ptr [esp + 0xec], eax
00429195  7e45                     jle       0x4291dc
00429197  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
0042919d  d9c0                     fld       st(0)
0042919f  d80dec755200             fmul      dword ptr [0x5275ec] ; bits=00000000, f32=0.0
004291a5  d905d4755200             fld       dword ptr [0x5275d4] ; bits=00000000, f32=0.0
004291ab  d80d44765200             fmul      dword ptr [0x527644] ; bits=00000000, f32=0.0
004291b1  dee9                     fsubp     st(1)
004291b3  d9cb                     fxch      st(3)
004291b5  d8c8                     fmul      st(0)
004291b7  decb                     fmulp     st(3)
004291b9  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
004291bf  8b8424ec000000           mov       eax, dword ptr [esp + 0xec]
004291c6  dec2                     faddp     st(2)
004291c8  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
004291cf  29d9                     sub       ecx, ebx
004291d1  d9c9                     fxch      st(1)
004291d3  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
004291da  eb3c                     jmp       0x429218
004291dc  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
004291e2  d9c0                     fld       st(0)
004291e4  d80dec755200             fmul      dword ptr [0x5275ec] ; bits=00000000, f32=0.0
004291ea  d905d4755200             fld       dword ptr [0x5275d4] ; bits=00000000, f32=0.0
004291f0  d80d44765200             fmul      dword ptr [0x527644] ; bits=00000000, f32=0.0
004291f6  dee9                     fsubp     st(1)
004291f8  d9cb                     fxch      st(3)
004291fa  d8c8                     fmul      st(0)
004291fc  decb                     fmulp     st(3)
004291fe  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00429204  dec2                     faddp     st(2)
00429206  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042920d  01d9                     add       ecx, ebx
0042920f  d9c9                     fxch      st(1)
00429211  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00429218  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
0042921f  8b74a8ec                 mov       esi, dword ptr [eax + ebp*4 - 0x14]
00429223  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429229  89e9                     mov       ecx, ebp
0042922b  29f1                     sub       ecx, esi
0042922d  89cb                     mov       ebx, ecx
0042922f  83fb00                   cmp       ebx, 0
00429232  7e22                     jle       0x429256
00429234  d905dc755200             fld       dword ptr [0x5275dc] ; bits=00000000, f32=0.0
0042923a  d805dc755200             fadd      dword ptr [0x5275dc] ; bits=00000000, f32=0.0
00429240  d8c9                     fmul      st(1)
00429242  d9e0                     fchs
00429244  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
0042924b  29d9                     sub       ecx, ebx
0042924d  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00429254  eb20                     jmp       0x429276
00429256  d905dc755200             fld       dword ptr [0x5275dc] ; bits=00000000, f32=0.0
0042925c  d805dc755200             fadd      dword ptr [0x5275dc] ; bits=00000000, f32=0.0
00429262  d8c9                     fmul      st(1)
00429264  d9e0                     fchs
00429266  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042926d  01d9                     add       ecx, ebx
0042926f  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00429276  46                       inc       esi
00429277  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042927d  89e9                     mov       ecx, ebp
0042927f  29f1                     sub       ecx, esi
00429281  89cb                     mov       ebx, ecx
00429283  83fb00                   cmp       ebx, 0
00429286  7e45                     jle       0x4292cd
00429288  d905c8755200             fld       dword ptr [0x5275c8] ; bits=00000000, f32=0.0
0042928e  d9c0                     fld       st(0)
00429290  d80df4755200             fmul      dword ptr [0x5275f4] ; bits=00000000, f32=0.0
00429296  d905dc755200             fld       dword ptr [0x5275dc] ; bits=00000000, f32=0.0
0042929c  d80d4c765200             fmul      dword ptr [0x52764c] ; bits=00000000, f32=0.0
004292a2  dee9                     fsubp     st(1)
004292a4  d9ca                     fxch      st(2)
004292a6  d8c8                     fmul      st(0)
004292a8  deca                     fmulp     st(2)
004292aa  d9c9                     fxch      st(1)
004292ac  d9e0                     fchs
004292ae  d9c9                     fxch      st(1)
004292b0  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
004292b6  dee9                     fsubp     st(1)
004292b8  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
004292bf  29d9                     sub       ecx, ebx
004292c1  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
004292c8  e95cdeffff               jmp       0x427129
004292cd  d905c8755200             fld       dword ptr [0x5275c8] ; bits=00000000, f32=0.0
004292d3  d9c0                     fld       st(0)
004292d5  d80df4755200             fmul      dword ptr [0x5275f4] ; bits=00000000, f32=0.0
004292db  d905dc755200             fld       dword ptr [0x5275dc] ; bits=00000000, f32=0.0
004292e1  d80d4c765200             fmul      dword ptr [0x52764c] ; bits=00000000, f32=0.0
004292e7  dee9                     fsubp     st(1)
004292e9  d9ca                     fxch      st(2)
004292eb  d8c8                     fmul      st(0)
004292ed  deca                     fmulp     st(2)
004292ef  d9c9                     fxch      st(1)
004292f1  d9e0                     fchs
004292f3  d9c9                     fxch      st(1)
004292f5  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
004292fb  dee9                     fsubp     st(1)
004292fd  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429304  01d9                     add       ecx, ebx
00429306  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042930d  e917deffff               jmp       0x427129
00429312  ddd8                     fstp      st(0)
00429314  d90564765200             fld       dword ptr [0x527664] ; bits=00000000, f32=0.0
0042931a  d82d60765200             fsubr     dword ptr [0x527660] ; bits=00000000, f32=0.0
00429320  d9e0                     fchs
00429322  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429328  d91c8df84baa01           fstp      dword ptr [ecx*4 + 0x1aa4bf8]
0042932f  89d8                     mov       eax, ebx
00429331  8b74b0ec                 mov       esi, dword ptr [eax + esi*4 - 0x14]
00429335  89c8                     mov       eax, ecx
00429337  29f0                     sub       eax, esi
00429339  89c3                     mov       ebx, eax
0042933b  83fb00                   cmp       ebx, 0
0042933e  7e16                     jle       0x429356
00429340  8b0c8d28007501           mov       ecx, dword ptr [ecx*4 + 0x1750028]
00429347  29d9                     sub       ecx, ebx
00429349  c7048dfce27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2fc], 0
00429354  eb14                     jmp       0x42936a
00429356  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042935d  01d9                     add       ecx, ebx
0042935f  c7048df8e27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2f8], 0
0042936a  46                       inc       esi
0042936b  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429371  89c1                     mov       ecx, eax
00429373  29f1                     sub       ecx, esi
00429375  89cb                     mov       ebx, ecx
00429377  83fb00                   cmp       ebx, 0
0042937a  898424e0000000           mov       dword ptr [esp + 0xe0], eax
00429381  7e1d                     jle       0x4293a0
00429383  8b8424e0000000           mov       eax, dword ptr [esp + 0xe0]
0042938a  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
00429391  29d9                     sub       ecx, ebx
00429393  c7048dfce27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2fc], 0x3f800000
0042939e  eb14                     jmp       0x4293b4
004293a0  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004293a7  01d9                     add       ecx, ebx
004293a9  c7048df8e27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2f8], 0x3f800000
004293b4  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
004293bb  8b74a8ec                 mov       esi, dword ptr [eax + ebp*4 - 0x14]
004293bf  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004293c5  89e9                     mov       ecx, ebp
004293c7  29f1                     sub       ecx, esi
004293c9  89cb                     mov       ebx, ecx
004293cb  83fb00                   cmp       ebx, 0
004293ce  7e16                     jle       0x4293e6
004293d0  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
004293d7  29d9                     sub       ecx, ebx
004293d9  c7048dfce27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2fc], 0
004293e4  eb14                     jmp       0x4293fa
004293e6  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004293ed  01d9                     add       ecx, ebx
004293ef  c7048df8e27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2f8], 0
004293fa  46                       inc       esi
004293fb  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429401  89e9                     mov       ecx, ebp
00429403  29f1                     sub       ecx, esi
00429405  89cb                     mov       ebx, ecx
00429407  83fb00                   cmp       ebx, 0
0042940a  7e19                     jle       0x429425
0042940c  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
00429413  29d9                     sub       ecx, ebx
00429415  c7048dfce27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2fc], 0xbf800000
00429420  e904ddffff               jmp       0x427129
00429425  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042942c  01d9                     add       ecx, ebx
0042942e  c7048df8e27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2f8], 0xbf800000
00429439  e9ebdcffff               jmp       0x427129
0042943e  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00429445  89ca                     mov       edx, ecx
00429447  8b3c90                   mov       edi, dword ptr [eax + edx*4]
0042944a  89ca                     mov       edx, ecx
0042944c  57                       push      edi
0042944d  8b7c9004                 mov       edi, dword ptr [eax + edx*4 + 4]
00429451  893da4755200             mov       dword ptr [0x5275a4], edi ; bits=00000000, f32=0.0
00429457  89ca                     mov       edx, ecx
00429459  8b6c9008                 mov       ebp, dword ptr [eax + edx*4 + 8]
0042945d  89ca                     mov       edx, ecx
0042945f  8b44900c                 mov       eax, dword ptr [eax + edx*4 + 0xc]
00429463  8905a0765200             mov       dword ptr [0x5276a0], eax ; bits=00000000, f32=0.0
00429469  d905a0765200             fld       dword ptr [0x5276a0] ; bits=00000000, f32=0.0
0042946f  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429475  40                       inc       eax
00429476  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
0042947c  58                       pop       eax
0042947d  d904859ca40102           fld       dword ptr [eax*4 + 0x201a49c]
00429484  d804851c9e0002           fadd      dword ptr [eax*4 + 0x2009e1c]
0042948b  d9c1                     fld       st(1)
0042948d  dec9                     fmulp     st(1)
0042948f  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00429495  dbbc247c020000           fstp      xword ptr [esp + 0x27c]
0042949c  8d04c0                   lea       eax, [eax + eax*8]
0042949f  8b9424b8030000           mov       edx, dword ptr [esp + 0x3b8]
004294a6  8b7482ec                 mov       esi, dword ptr [edx + eax*4 - 0x14]
004294aa  46                       inc       esi
004294ab  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004294b1  89c2                     mov       edx, eax
004294b3  29f2                     sub       edx, esi
004294b5  89d3                     mov       ebx, edx
004294b7  83fb00                   cmp       ebx, 0
004294ba  898424f8000000           mov       dword ptr [esp + 0xf8], eax
004294c1  7e20                     jle       0x4294e3
004294c3  8b8424f8000000           mov       eax, dword ptr [esp + 0xf8]
004294ca  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
004294d1  29d9                     sub       ecx, ebx
004294d3  dbac247c020000           fld       xword ptr [esp + 0x27c]
004294da  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
004294e1  eb17                     jmp       0x4294fa
004294e3  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004294ea  01d9                     add       ecx, ebx
004294ec  dbac247c020000           fld       xword ptr [esp + 0x27c]
004294f3  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
004294fa  dbac247c020000           fld       xword ptr [esp + 0x27c]
00429501  d82d08725200             fsubr     dword ptr [0x527208] ; bits=0000803f, f32=1.0
00429507  8b05a4755200             mov       eax, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
0042950d  d904859ca40102           fld       dword ptr [eax*4 + 0x201a49c]
00429514  d804851c9e0002           fadd      dword ptr [eax*4 + 0x2009e1c]
0042951b  d8c9                     fmul      st(1)
0042951d  d80540765200             fadd      dword ptr [0x527640] ; bits=00000000, f32=0.0
00429523  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
00429529  dbbc2470020000           fstp      xword ptr [esp + 0x270]
00429530  8d0cc0                   lea       ecx, [eax + eax*8]
00429533  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
0042953a  8b7488ec                 mov       esi, dword ptr [eax + ecx*4 - 0x14]
0042953e  46                       inc       esi
0042953f  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429545  89c1                     mov       ecx, eax
00429547  29f1                     sub       ecx, esi
00429549  89cb                     mov       ebx, ecx
0042954b  83fb00                   cmp       ebx, 0
0042954e  898424f4000000           mov       dword ptr [esp + 0xf4], eax
00429555  7e20                     jle       0x429577
00429557  8b8424f4000000           mov       eax, dword ptr [esp + 0xf4]
0042955e  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
00429565  29d9                     sub       ecx, ebx
00429567  dbac2470020000           fld       xword ptr [esp + 0x270]
0042956e  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00429575  eb17                     jmp       0x42958e
00429577  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042957e  01d9                     add       ecx, ebx
00429580  dbac2470020000           fld       xword ptr [esp + 0x270]
00429587  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042958e  d904ad9ca40102           fld       dword ptr [ebp*4 + 0x201a49c]
00429595  d804ad1c9e0002           fadd      dword ptr [ebp*4 + 0x2009e1c]
0042959c  d82d40765200             fsubr     dword ptr [0x527640] ; bits=00000000, f32=0.0
004295a2  d91d40765200             fstp      dword ptr [0x527640] ; bits=00000000, f32=0.0
004295a8  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
004295ae  d9e0                     fchs
004295b0  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004295b6  d91c8df84baa01           fstp      dword ptr [ecx*4 + 0x1aa4bf8]
004295bd  8d54ed00                 lea       edx, [ebp + ebp*8]
004295c1  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
004295c8  8b7490ec                 mov       esi, dword ptr [eax + edx*4 - 0x14]
004295cc  46                       inc       esi
004295cd  89c8                     mov       eax, ecx
004295cf  29f0                     sub       eax, esi
004295d1  89c3                     mov       ebx, eax
004295d3  83fb00                   cmp       ebx, 0
004295d6  7e19                     jle       0x4295f1
004295d8  8b0c8d28007501           mov       ecx, dword ptr [ecx*4 + 0x1750028]
004295df  29d9                     sub       ecx, ebx
004295e1  c7048dfce27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2fc], 0xbf800000
004295ec  e938dbffff               jmp       0x427129
004295f1  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004295f8  01d9                     add       ecx, ebx
004295fa  c7048df8e27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2f8], 0xbf800000
00429605  e91fdbffff               jmp       0x427129
0042960a  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00429611  89ca                     mov       edx, ecx
00429613  8b3c90                   mov       edi, dword ptr [eax + edx*4]
00429616  89ca                     mov       edx, ecx
00429618  89bc2458010000           mov       dword ptr [esp + 0x158], edi
0042961f  8b7c9004                 mov       edi, dword ptr [eax + edx*4 + 4]
00429623  8b942458010000           mov       edx, dword ptr [esp + 0x158]
0042962a  89842454010000           mov       dword ptr [esp + 0x154], eax
00429631  8b04951c9e0002           mov       eax, dword ptr [edx*4 + 0x2009e1c]
00429638  890560765200             mov       dword ptr [0x527660], eax ; bits=00000000, f32=0.0
0042963e  8b04bd1c9e0002           mov       eax, dword ptr [edi*4 + 0x2009e1c]
00429645  890564765200             mov       dword ptr [0x527664], eax ; bits=00000000, f32=0.0
0042964b  d904955c14ff01           fld       dword ptr [edx*4 + 0x1ff145c]
00429652  d904bd5c14ff01           fld       dword ptr [edi*4 + 0x1ff145c]
00429659  8b942454010000           mov       edx, dword ptr [esp + 0x154]
00429660  89c8                     mov       eax, ecx
00429662  8b4c820c                 mov       ecx, dword ptr [edx + eax*4 + 0xc]
00429666  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042966c  40                       inc       eax
0042966d  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
00429673  8b842458010000           mov       eax, dword ptr [esp + 0x158]
0042967a  8d34c0                   lea       esi, [eax + eax*8]
0042967d  8b9c24b8030000           mov       ebx, dword ptr [esp + 0x3b8]
00429684  8b44b3dc                 mov       eax, dword ptr [ebx + esi*4 - 0x24]
00429688  89842480030000           mov       dword ptr [esp + 0x380], eax
0042968f  d9c1                     fld       st(1)
00429691  da8c2480030000           fimul     dword ptr [esp + 0x380]
00429698  8d2cff                   lea       ebp, [edi + edi*8]
0042969b  8b7cabdc                 mov       edi, dword ptr [ebx + ebp*4 - 0x24]
0042969f  89bc2480030000           mov       dword ptr [esp + 0x380], edi
004296a6  d9c1                     fld       st(1)
004296a8  da8c2480030000           fimul     dword ptr [esp + 0x380]
004296af  dec1                     faddp     st(1)
004296b1  d9c2                     fld       st(2)
004296b3  d9e1                     fabs
004296b5  d9c2                     fld       st(2)
004296b7  d9e1                     fabs
004296b9  dec1                     faddp     st(1)
004296bb  8bbc24ac030000           mov       edi, dword ptr [esp + 0x3ac]
004296c2  d807                     fadd      dword ptr [edi]
004296c4  def9                     fdivp     st(1)
004296c6  d9c0                     fld       st(0)
004296c8  d9e1                     fabs
004296ca  d9051c725200             fld       dword ptr [0x52721c] ; bits=17b7d138, f32=9.999999747378752e-05
004296d0  dff1                     fcompi    st(1)
004296d2  ddd8                     fstp      st(0)
004296d4  dbbc2464020000           fstp      xword ptr [esp + 0x264]
004296db  dbbc2494020000           fstp      xword ptr [esp + 0x294]
004296e2  0f8a3e010000             jp        0x429826
004296e8  0f8238010000             jb        0x429826
004296ee  ddd8                     fstp      st(0)
004296f0  d90564765200             fld       dword ptr [0x527664] ; bits=00000000, f32=0.0
004296f6  d82d60765200             fsubr     dword ptr [0x527660] ; bits=00000000, f32=0.0
004296fc  d9e0                     fchs
004296fe  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429704  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
0042970b  8b74b3ec                 mov       esi, dword ptr [ebx + esi*4 - 0x14]
0042970f  89c1                     mov       ecx, eax
00429711  29f1                     sub       ecx, esi
00429713  89cb                     mov       ebx, ecx
00429715  83fb00                   cmp       ebx, 0
00429718  8984244c010000           mov       dword ptr [esp + 0x14c], eax
0042971f  7e1d                     jle       0x42973e
00429721  8b84244c010000           mov       eax, dword ptr [esp + 0x14c]
00429728  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042972f  29d9                     sub       ecx, ebx
00429731  c7048dfce27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2fc], 0
0042973c  eb14                     jmp       0x429752
0042973e  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429745  01d9                     add       ecx, ebx
00429747  c7048df8e27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2f8], 0
00429752  46                       inc       esi
00429753  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429759  89c1                     mov       ecx, eax
0042975b  29f1                     sub       ecx, esi
0042975d  89cb                     mov       ebx, ecx
0042975f  83fb00                   cmp       ebx, 0
00429762  89842448010000           mov       dword ptr [esp + 0x148], eax
00429769  7e1d                     jle       0x429788
0042976b  8b842448010000           mov       eax, dword ptr [esp + 0x148]
00429772  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
00429779  29d9                     sub       ecx, ebx
0042977b  c7048dfce27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2fc], 0x3f800000
00429786  eb14                     jmp       0x42979c
00429788  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042978f  01d9                     add       ecx, ebx
00429791  c7048df8e27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2f8], 0x3f800000
0042979c  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
004297a3  8b74a8ec                 mov       esi, dword ptr [eax + ebp*4 - 0x14]
004297a7  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004297ad  89e9                     mov       ecx, ebp
004297af  29f1                     sub       ecx, esi
004297b1  89cb                     mov       ebx, ecx
004297b3  83fb00                   cmp       ebx, 0
004297b6  7e16                     jle       0x4297ce
004297b8  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
004297bf  29d9                     sub       ecx, ebx
004297c1  c7048dfce27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2fc], 0
004297cc  eb14                     jmp       0x4297e2
004297ce  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
004297d5  01d9                     add       ecx, ebx
004297d7  c7048df8e27c0100000000   mov       dword ptr [ecx*4 + 0x17ce2f8], 0
004297e2  46                       inc       esi
004297e3  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
004297e9  89e9                     mov       ecx, ebp
004297eb  29f1                     sub       ecx, esi
004297ed  89cb                     mov       ebx, ecx
004297ef  83fb00                   cmp       ebx, 0
004297f2  7e19                     jle       0x42980d
004297f4  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
004297fb  29d9                     sub       ecx, ebx
004297fd  c7048dfce27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2fc], 0xbf800000
00429808  e91cd9ffff               jmp       0x427129
0042980d  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429814  01d9                     add       ecx, ebx
00429816  c7048df8e27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2f8], 0xbf800000
00429821  e903d9ffff               jmp       0x427129
00429826  d9ee                     fldz
00429828  dbac2464020000           fld       xword ptr [esp + 0x264]
0042982f  dff1                     fcompi    st(1)
00429831  ddd8                     fstp      st(0)
00429833  0f8ab8050000             jp        0x429df1
00429839  0f83b2050000             jae       0x429df1
0042983f  83f900                   cmp       ecx, 0
00429842  0f8ea9000000             jle       0x4298f1
00429848  dbbc246c030000           fstp      xword ptr [esp + 0x36c]
0042984f  6834765200               push      0x527634
00429854  68e4755200               push      0x5275e4
00429859  68c0755200               push      0x5275c0
0042985e  68ec755200               push      0x5275ec
00429863  68d4755200               push      0x5275d4
00429868  68f8755200               push      0x5275f8
0042986d  68e0755200               push      0x5275e0
00429872  6850765200               push      0x527650
00429877  6804765200               push      0x527604
0042987c  6844765200               push      0x527644
00429881  68bc755200               push      0x5275bc
00429886  6860765200               push      0x527660
0042988b  89d8                     mov       eax, ebx
0042988d  8d44b0e8                 lea       eax, [eax + esi*4 - 0x18]
00429891  50                       push      eax
00429892  e8891c0100               call      0x43b520 ; _xlkt22_
00429897  83c434                   add       esp, 0x34
0042989a  6830765200               push      0x527630
0042989f  68e8755200               push      0x5275e8
004298a4  68c4755200               push      0x5275c4
004298a9  68f4755200               push      0x5275f4
004298ae  68dc755200               push      0x5275dc
004298b3  68f8755200               push      0x5275f8
004298b8  68e0755200               push      0x5275e0
004298bd  6854765200               push      0x527654
004298c2  680c765200               push      0x52760c
004298c7  684c765200               push      0x52764c
004298cc  68c8755200               push      0x5275c8
004298d1  6864765200               push      0x527664
004298d6  89d8                     mov       eax, ebx
004298d8  8d44a8e8                 lea       eax, [eax + ebp*4 - 0x18]
004298dc  50                       push      eax
004298dd  e83e1c0100               call      0x43b520 ; _xlkt22_
004298e2  dbac24a0030000           fld       xword ptr [esp + 0x3a0]
004298e9  83c434                   add       esp, 0x34
004298ec  e902010000               jmp       0x4299f3
004298f1  dbbc246c030000           fstp      xword ptr [esp + 0x36c]
004298f8  68ec755200               push      0x5275ec
004298fd  68d4755200               push      0x5275d4
00429902  68f8755200               push      0x5275f8
00429907  68e0755200               push      0x5275e0
0042990c  6850765200               push      0x527650
00429911  6804765200               push      0x527604
00429916  6844765200               push      0x527644
0042991b  68bc755200               push      0x5275bc
00429920  6860765200               push      0x527660
00429925  89d8                     mov       eax, ebx
00429927  8d44b0e8                 lea       eax, [eax + esi*4 - 0x18]
0042992b  50                       push      eax
0042992c  e8ef140100               call      0x43ae20 ; _xlkt21_
00429931  83c428                   add       esp, 0x28
00429934  68f4755200               push      0x5275f4
00429939  68dc755200               push      0x5275dc
0042993e  68f8755200               push      0x5275f8
00429943  68e0755200               push      0x5275e0
00429948  6854765200               push      0x527654
0042994d  680c765200               push      0x52760c
00429952  684c765200               push      0x52764c
00429957  68c8755200               push      0x5275c8
0042995c  6864765200               push      0x527664
00429961  89d8                     mov       eax, ebx
00429963  8d44a8e8                 lea       eax, [eax + ebp*4 - 0x18]
00429967  50                       push      eax
00429968  e8b3140100               call      0x43ae20 ; _xlkt21_
0042996d  83c428                   add       esp, 0x28
00429970  d9e8                     fld1
00429972  d915c0755200             fst       dword ptr [0x5275c0] ; bits=00000000, f32=0.0
00429978  d91dc4755200             fstp      dword ptr [0x5275c4] ; bits=00000000, f32=0.0
0042997e  c705e475520000000000     mov       dword ptr [0x5275e4], 0 ; bits=00000000, f32=0.0
00429988  c705e875520000000000     mov       dword ptr [0x5275e8], 0 ; bits=00000000, f32=0.0
00429992  d905c014e001             fld       dword ptr [0x1e014c0] ; _gravcm_
00429998  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
0042999e  d9c0                     fld       st(0)
004299a0  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
004299a6  d83544765200             fdiv      dword ptr [0x527644] ; bits=00000000, f32=0.0
004299ac  d9fa                     fsqrt
004299ae  d99c247c030000           fstp      dword ptr [esp + 0x37c]
004299b5  d88c247c030000           fmul      dword ptr [esp + 0x37c]
004299bc  d91d34765200             fstp      dword ptr [0x527634] ; bits=00000000, f32=0.0
004299c2  d905c8755200             fld       dword ptr [0x5275c8] ; bits=00000000, f32=0.0
004299c8  d9c9                     fxch      st(1)
004299ca  d80dc8755200             fmul      dword ptr [0x5275c8] ; bits=00000000, f32=0.0
004299d0  d8354c765200             fdiv      dword ptr [0x52764c] ; bits=00000000, f32=0.0
004299d6  d9fa                     fsqrt
004299d8  d99c247c030000           fstp      dword ptr [esp + 0x37c]
004299df  d88c247c030000           fmul      dword ptr [esp + 0x37c]
004299e6  d91d30765200             fstp      dword ptr [0x527630] ; bits=00000000, f32=0.0
004299ec  dbac246c030000           fld       xword ptr [esp + 0x36c]
004299f3  d9c0                     fld       st(0)
004299f5  d835bc755200             fdiv      dword ptr [0x5275bc] ; bits=00000000, f32=0.0
004299fb  dbac2494020000           fld       xword ptr [esp + 0x294]
00429a02  d835c8755200             fdiv      dword ptr [0x5275c8] ; bits=00000000, f32=0.0
00429a08  d905d4755200             fld       dword ptr [0x5275d4] ; bits=00000000, f32=0.0
00429a0e  d9c2                     fld       st(2)
00429a10  d80dd4755200             fmul      dword ptr [0x5275d4] ; bits=00000000, f32=0.0
00429a16  d8cc                     fmul      st(4)
00429a18  d90554765200             fld       dword ptr [0x527654] ; bits=00000000, f32=0.0
00429a1e  d82d50765200             fsubr     dword ptr [0x527650] ; bits=00000000, f32=0.0
00429a24  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00429a2a  dec1                     faddp     st(1)
00429a2c  d9c2                     fld       st(2)
00429a2e  d80ddc755200             fmul      dword ptr [0x5275dc] ; bits=00000000, f32=0.0
00429a34  dbac2494020000           fld       xword ptr [esp + 0x294]
00429a3b  dec9                     fmulp     st(1)
00429a3d  dee9                     fsubp     st(1)
00429a3f  d9e0                     fchs
00429a41  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429a47  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
00429a4e  dbbc2458020000           fstp      xword ptr [esp + 0x258]
00429a55  d9c9                     fxch      st(1)
00429a57  d9ca                     fxch      st(2)
00429a59  8b8c24b8030000           mov       ecx, dword ptr [esp + 0x3b8]
00429a60  8b74b1ec                 mov       esi, dword ptr [ecx + esi*4 - 0x14]
00429a64  89c1                     mov       ecx, eax
00429a66  29f1                     sub       ecx, esi
00429a68  89cb                     mov       ebx, ecx
00429a6a  83fb00                   cmp       ebx, 0
00429a6d  8984243c010000           mov       dword ptr [esp + 0x13c], eax
00429a74  7e28                     jle       0x429a9e
00429a76  d9ca                     fxch      st(2)
00429a78  d8c0                     fadd      st(0)
00429a7a  dbac2458020000           fld       xword ptr [esp + 0x258]
00429a81  8b84243c010000           mov       eax, dword ptr [esp + 0x13c]
00429a88  dec9                     fmulp     st(1)
00429a8a  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
00429a91  29d9                     sub       ecx, ebx
00429a93  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00429a9a  d9c9                     fxch      st(1)
00429a9c  eb1f                     jmp       0x429abd
00429a9e  d9ca                     fxch      st(2)
00429aa0  d8c0                     fadd      st(0)
00429aa2  dbac2458020000           fld       xword ptr [esp + 0x258]
00429aa9  dec9                     fmulp     st(1)
00429aab  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429ab2  01d9                     add       ecx, ebx
00429ab4  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00429abb  d9c9                     fxch      st(1)
00429abd  46                       inc       esi
00429abe  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429ac4  89c1                     mov       ecx, eax
00429ac6  29f1                     sub       ecx, esi
00429ac8  89cb                     mov       ebx, ecx
00429aca  83fb00                   cmp       ebx, 0
00429acd  89842438010000           mov       dword ptr [esp + 0x138], eax
00429ad4  7e37                     jle       0x429b0d
00429ad6  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
00429adc  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00429ae2  d9c9                     fxch      st(1)
00429ae4  d83534765200             fdiv      dword ptr [0x527634] ; bits=00000000, f32=0.0
00429aea  d8c8                     fmul      st(0)
00429aec  d82d08725200             fsubr     dword ptr [0x527208] ; bits=0000803f, f32=1.0
00429af2  8b842438010000           mov       eax, dword ptr [esp + 0x138]
00429af9  dec9                     fmulp     st(1)
00429afb  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
00429b02  29d9                     sub       ecx, ebx
00429b04  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00429b0b  eb2e                     jmp       0x429b3b
00429b0d  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
00429b13  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00429b19  d9c9                     fxch      st(1)
00429b1b  d83534765200             fdiv      dword ptr [0x527634] ; bits=00000000, f32=0.0
00429b21  d8c8                     fmul      st(0)
00429b23  d82d08725200             fsubr     dword ptr [0x527208] ; bits=0000803f, f32=1.0
00429b29  dec9                     fmulp     st(1)
00429b2b  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429b32  01d9                     add       ecx, ebx
00429b34  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00429b3b  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
00429b42  8b74a8ec                 mov       esi, dword ptr [eax + ebp*4 - 0x14]
00429b46  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429b4c  89e9                     mov       ecx, ebp
00429b4e  29f1                     sub       ecx, esi
00429b50  89cb                     mov       ebx, ecx
00429b52  83fb00                   cmp       ebx, 0
00429b55  7e1c                     jle       0x429b73
00429b57  d8c0                     fadd      st(0)
00429b59  d80ddc755200             fmul      dword ptr [0x5275dc] ; bits=00000000, f32=0.0
00429b5f  d9e0                     fchs
00429b61  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
00429b68  29d9                     sub       ecx, ebx
00429b6a  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00429b71  eb1a                     jmp       0x429b8d
00429b73  d8c0                     fadd      st(0)
00429b75  d80ddc755200             fmul      dword ptr [0x5275dc] ; bits=00000000, f32=0.0
00429b7b  d9e0                     fchs
00429b7d  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429b84  01d9                     add       ecx, ebx
00429b86  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00429b8d  46                       inc       esi
00429b8e  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429b94  89e9                     mov       ecx, ebp
00429b96  29f1                     sub       ecx, esi
00429b98  89cb                     mov       ebx, ecx
00429b9a  83fb00                   cmp       ebx, 0
00429b9d  7e37                     jle       0x429bd6
00429b9f  d905c8755200             fld       dword ptr [0x5275c8] ; bits=00000000, f32=0.0
00429ba5  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00429bab  dbac2494020000           fld       xword ptr [esp + 0x294]
00429bb2  d83530765200             fdiv      dword ptr [0x527630] ; bits=00000000, f32=0.0
00429bb8  d8c8                     fmul      st(0)
00429bba  d82d08725200             fsubr     dword ptr [0x527208] ; bits=0000803f, f32=1.0
00429bc0  dec9                     fmulp     st(1)
00429bc2  d9e0                     fchs
00429bc4  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
00429bcb  29d9                     sub       ecx, ebx
00429bcd  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00429bd4  eb35                     jmp       0x429c0b
00429bd6  d905c8755200             fld       dword ptr [0x5275c8] ; bits=00000000, f32=0.0
00429bdc  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00429be2  dbac2494020000           fld       xword ptr [esp + 0x294]
00429be9  d83530765200             fdiv      dword ptr [0x527630] ; bits=00000000, f32=0.0
00429bef  d8c8                     fmul      st(0)
00429bf1  d82d08725200             fsubr     dword ptr [0x527208] ; bits=0000803f, f32=1.0
00429bf7  dec9                     fmulp     st(1)
00429bf9  d9e0                     fchs
00429bfb  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429c02  01d9                     add       ecx, ebx
00429c04  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00429c0b  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
00429c12  8b0dac755200             mov       ecx, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
00429c18  8b548814                 mov       edx, dword ptr [eax + ecx*4 + 0x14]
00429c1c  83fa00                   cmp       edx, 0
00429c1f  898c242c010000           mov       dword ptr [esp + 0x12c], ecx
00429c26  89942428010000           mov       dword ptr [esp + 0x128], edx
00429c2d  0f8ef6d4ffff             jle       0x427129
00429c33  8b84242c010000           mov       eax, dword ptr [esp + 0x12c]
00429c3a  8d6807                   lea       ebp, [eax + 7]
00429c3d  83c009                   add       eax, 9
00429c40  89842424010000           mov       dword ptr [esp + 0x124], eax
00429c47  8bbc24b4030000           mov       edi, dword ptr [esp + 0x3b4]
00429c4e  8b54affc                 mov       edx, dword ptr [edi + ebp*4 - 4]
00429c52  8b04951c9e0002           mov       eax, dword ptr [edx*4 + 0x2009e1c]
00429c59  890560765200             mov       dword ptr [0x527660], eax ; bits=00000000, f32=0.0
00429c5f  8d04d2                   lea       eax, [edx + edx*8]
00429c62  89842414010000           mov       dword ptr [esp + 0x114], eax
00429c69  68ec755200               push      0x5275ec
00429c6e  68d4755200               push      0x5275d4
00429c73  68f8755200               push      0x5275f8
00429c78  68e0755200               push      0x5275e0
00429c7d  6804765200               push      0x527604
00429c82  6844765200               push      0x527644
00429c87  68bc755200               push      0x5275bc
00429c8c  6860765200               push      0x527660
00429c91  89bc243c010000           mov       dword ptr [esp + 0x13c], edi
00429c98  8bbc24d8030000           mov       edi, dword ptr [esp + 0x3d8]
00429c9f  89942438010000           mov       dword ptr [esp + 0x138], edx
00429ca6  8d5487e8                 lea       edx, [edi + eax*4 - 0x18]
00429caa  52                       push      edx
00429cab  e8400b0100               call      0x43a7f0 ; _xlkt20_
00429cb0  83c424                   add       esp, 0x24
00429cb3  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
00429cb9  8b842418010000           mov       eax, dword ptr [esp + 0x118]
00429cc0  d83c855c14ff01           fdivr     dword ptr [eax*4 + 0x1ff145c]
00429cc7  8b942424010000           mov       edx, dword ptr [esp + 0x124]
00429cce  89bc2410010000           mov       dword ptr [esp + 0x110], edi
00429cd5  8bbc241c010000           mov       edi, dword ptr [esp + 0x11c]
00429cdc  8b7c97fc                 mov       edi, dword ptr [edi + edx*4 - 4]
00429ce0  893da0765200             mov       dword ptr [0x5276a0], edi ; bits=00000000, f32=0.0
00429ce6  d9c0                     fld       st(0)
00429ce8  d80da0765200             fmul      dword ptr [0x5276a0] ; bits=00000000, f32=0.0
00429cee  d905d4755200             fld       dword ptr [0x5275d4] ; bits=00000000, f32=0.0
00429cf4  d9c0                     fld       st(0)
00429cf6  d80c855c14ff01           fmul      dword ptr [eax*4 + 0x1ff145c]
00429cfd  d8ca                     fmul      st(2)
00429cff  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429d05  d82c8df84baa01           fsubr     dword ptr [ecx*4 + 0x1aa4bf8]
00429d0c  d91c8df84baa01           fstp      dword ptr [ecx*4 + 0x1aa4bf8]
00429d13  d9c9                     fxch      st(1)
00429d15  d9ca                     fxch      st(2)
00429d17  8bbc2414010000           mov       edi, dword ptr [esp + 0x114]
00429d1e  8b842410010000           mov       eax, dword ptr [esp + 0x110]
00429d25  8b74b8ec                 mov       esi, dword ptr [eax + edi*4 - 0x14]
00429d29  89c8                     mov       eax, ecx
00429d2b  29f0                     sub       eax, esi
00429d2d  89c3                     mov       ebx, eax
00429d2f  83fb00                   cmp       ebx, 0
00429d32  7e1a                     jle       0x429d4e
00429d34  d9c2                     fld       st(2)
00429d36  d8c0                     fadd      st(0)
00429d38  deca                     fmulp     st(2)
00429d3a  8b0c8d28007501           mov       ecx, dword ptr [ecx*4 + 0x1750028]
00429d41  29d9                     sub       ecx, ebx
00429d43  d9c9                     fxch      st(1)
00429d45  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00429d4c  eb18                     jmp       0x429d66
00429d4e  d9c2                     fld       st(2)
00429d50  d8c0                     fadd      st(0)
00429d52  deca                     fmulp     st(2)
00429d54  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429d5b  01d9                     add       ecx, ebx
00429d5d  d9c9                     fxch      st(1)
00429d5f  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00429d66  46                       inc       esi
00429d67  8b0da8755200             mov       ecx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
00429d6d  89c8                     mov       eax, ecx
00429d6f  29f0                     sub       eax, esi
00429d71  89c3                     mov       ebx, eax
00429d73  83fb00                   cmp       ebx, 0
00429d76  7e30                     jle       0x429da8
00429d78  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
00429d7e  d80dec755200             fmul      dword ptr [0x5275ec] ; bits=00000000, f32=0.0
00429d84  d905d4755200             fld       dword ptr [0x5275d4] ; bits=00000000, f32=0.0
00429d8a  d80d44765200             fmul      dword ptr [0x527644] ; bits=00000000, f32=0.0
00429d90  dee9                     fsubp     st(1)
00429d92  dec9                     fmulp     st(1)
00429d94  dec9                     fmulp     st(1)
00429d96  8b0c8d28007501           mov       ecx, dword ptr [ecx*4 + 0x1750028]
00429d9d  29d9                     sub       ecx, ebx
00429d9f  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
00429da6  eb2e                     jmp       0x429dd6
00429da8  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
00429dae  d80dec755200             fmul      dword ptr [0x5275ec] ; bits=00000000, f32=0.0
00429db4  d905d4755200             fld       dword ptr [0x5275d4] ; bits=00000000, f32=0.0
00429dba  d80d44765200             fmul      dword ptr [0x527644] ; bits=00000000, f32=0.0
00429dc0  dee9                     fsubp     st(1)
00429dc2  dec9                     fmulp     st(1)
00429dc4  dec9                     fmulp     st(1)
00429dc6  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
00429dcd  01d9                     add       ecx, ebx
00429dcf  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
00429dd6  ff842424010000           inc       dword ptr [esp + 0x124]
00429ddd  45                       inc       ebp
00429dde  83ac242801000001         sub       dword ptr [esp + 0x128], 1
00429de6  0f855bfeffff             jne       0x429c47
00429dec  e938d3ffff               jmp       0x427129
00429df1  8b942454010000           mov       edx, dword ptr [esp + 0x154]
00429df8  8b05ac755200             mov       eax, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
00429dfe  8b7c8210                 mov       edi, dword ptr [edx + eax*4 + 0x10]
00429e02  893da0765200             mov       dword ptr [0x5276a0], edi ; bits=00000000, f32=0.0
00429e08  d905a0765200             fld       dword ptr [0x5276a0] ; bits=00000000, f32=0.0
00429e0e  d82d08725200             fsubr     dword ptr [0x527208] ; bits=0000803f, f32=1.0
00429e14  dbbc244c020000           fstp      xword ptr [esp + 0x24c]
00429e1b  85c9                     test      ecx, ecx
00429e1d  0f8507010000             jne       0x429f2a
00429e23  dbbc246c030000           fstp      xword ptr [esp + 0x36c]
00429e2a  68ec755200               push      0x5275ec
00429e2f  68d4755200               push      0x5275d4
00429e34  68f8755200               push      0x5275f8
00429e39  68e0755200               push      0x5275e0
00429e3e  6850765200               push      0x527650
00429e43  6804765200               push      0x527604
00429e48  6844765200               push      0x527644
00429e4d  68bc755200               push      0x5275bc
00429e52  6860765200               push      0x527660
00429e57  89d8                     mov       eax, ebx
00429e59  8d44b0e8                 lea       eax, [eax + esi*4 - 0x18]
00429e5d  50                       push      eax
00429e5e  e8bd0f0100               call      0x43ae20 ; _xlkt21_
00429e63  83c428                   add       esp, 0x28
00429e66  68f4755200               push      0x5275f4
00429e6b  68dc755200               push      0x5275dc
00429e70  68f8755200               push      0x5275f8
00429e75  68e0755200               push      0x5275e0
00429e7a  6854765200               push      0x527654
00429e7f  680c765200               push      0x52760c
00429e84  684c765200               push      0x52764c
00429e89  68c8755200               push      0x5275c8
00429e8e  6864765200               push      0x527664
00429e93  89d8                     mov       eax, ebx
00429e95  8d44a8e8                 lea       eax, [eax + ebp*4 - 0x18]
00429e99  50                       push      eax
00429e9a  e8810f0100               call      0x43ae20 ; _xlkt21_
00429e9f  83c428                   add       esp, 0x28
00429ea2  d9e8                     fld1
00429ea4  d915c0755200             fst       dword ptr [0x5275c0] ; bits=00000000, f32=0.0
00429eaa  d91dc4755200             fstp      dword ptr [0x5275c4] ; bits=00000000, f32=0.0
00429eb0  c705e475520000000000     mov       dword ptr [0x5275e4], 0 ; bits=00000000, f32=0.0
00429eba  c705e875520000000000     mov       dword ptr [0x5275e8], 0 ; bits=00000000, f32=0.0
00429ec4  d905c014e001             fld       dword ptr [0x1e014c0] ; _gravcm_
00429eca  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
00429ed0  d9c0                     fld       st(0)
00429ed2  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
00429ed8  d83544765200             fdiv      dword ptr [0x527644] ; bits=00000000, f32=0.0
00429ede  d9fa                     fsqrt
00429ee0  d99c247c030000           fstp      dword ptr [esp + 0x37c]
00429ee7  d88c247c030000           fmul      dword ptr [esp + 0x37c]
00429eee  d91d34765200             fstp      dword ptr [0x527634] ; bits=00000000, f32=0.0
00429ef4  d905c8755200             fld       dword ptr [0x5275c8] ; bits=00000000, f32=0.0
00429efa  d9c9                     fxch      st(1)
00429efc  d80dc8755200             fmul      dword ptr [0x5275c8] ; bits=00000000, f32=0.0
00429f02  d8354c765200             fdiv      dword ptr [0x52764c] ; bits=00000000, f32=0.0
00429f08  d9fa                     fsqrt
00429f0a  d99c247c030000           fstp      dword ptr [esp + 0x37c]
00429f11  d88c247c030000           fmul      dword ptr [esp + 0x37c]
00429f18  d91d30765200             fstp      dword ptr [0x527630] ; bits=00000000, f32=0.0
00429f1e  dbac246c030000           fld       xword ptr [esp + 0x36c]
00429f25  e9a4000000               jmp       0x429fce
00429f2a  dbbc246c030000           fstp      xword ptr [esp + 0x36c]
00429f31  6834765200               push      0x527634
00429f36  68e4755200               push      0x5275e4
00429f3b  68c0755200               push      0x5275c0
00429f40  68ec755200               push      0x5275ec
00429f45  68d4755200               push      0x5275d4
00429f4a  68f8755200               push      0x5275f8
00429f4f  68e0755200               push      0x5275e0
00429f54  6858765200               push      0x527658
00429f59  6804765200               push      0x527604
00429f5e  6844765200               push      0x527644
00429f63  68bc755200               push      0x5275bc
00429f68  6860765200               push      0x527660
00429f6d  89d8                     mov       eax, ebx
00429f6f  8d44b0e8                 lea       eax, [eax + esi*4 - 0x18]
00429f73  50                       push      eax
00429f74  e8a7150100               call      0x43b520 ; _xlkt22_
00429f79  83c434                   add       esp, 0x34
00429f7c  6830765200               push      0x527630
00429f81  68e8755200               push      0x5275e8
00429f86  68c4755200               push      0x5275c4
00429f8b  68f4755200               push      0x5275f4
00429f90  68dc755200               push      0x5275dc
00429f95  68f8755200               push      0x5275f8
00429f9a  68e0755200               push      0x5275e0
00429f9f  685c765200               push      0x52765c
00429fa4  680c765200               push      0x52760c
00429fa9  684c765200               push      0x52764c
00429fae  68c8755200               push      0x5275c8
00429fb3  6864765200               push      0x527664
00429fb8  89d8                     mov       eax, ebx
00429fba  8d44a8e8                 lea       eax, [eax + ebp*4 - 0x18]
00429fbe  50                       push      eax
00429fbf  e85c150100               call      0x43b520 ; _xlkt22_
00429fc4  dbac24a0030000           fld       xword ptr [esp + 0x3a0]
00429fcb  83c434                   add       esp, 0x34
00429fce  dbbc2428020000           fstp      xword ptr [esp + 0x228]
00429fd5  d905bc755200             fld       dword ptr [0x5275bc] ; bits=00000000, f32=0.0
00429fdb  dbac2428020000           fld       xword ptr [esp + 0x228]
00429fe2  d835bc755200             fdiv      dword ptr [0x5275bc] ; bits=00000000, f32=0.0
00429fe8  dbac2494020000           fld       xword ptr [esp + 0x294]
00429fef  d835c8755200             fdiv      dword ptr [0x5275c8] ; bits=00000000, f32=0.0
00429ff5  d90564765200             fld       dword ptr [0x527664] ; bits=00000000, f32=0.0
00429ffb  d82d60765200             fsubr     dword ptr [0x527660] ; bits=00000000, f32=0.0
0042a001  d9c2                     fld       st(2)
0042a003  d8c8                     fmul      st(0)
0042a005  d905c0755200             fld       dword ptr [0x5275c0] ; bits=00000000, f32=0.0
0042a00b  d9c9                     fxch      st(1)
0042a00d  d80dc0755200             fmul      dword ptr [0x5275c0] ; bits=00000000, f32=0.0
0042a013  d9c3                     fld       st(3)
0042a015  d8c8                     fmul      st(0)
0042a017  d80dc4755200             fmul      dword ptr [0x5275c4] ; bits=00000000, f32=0.0
0042a01d  dee9                     fsubp     st(1)
0042a01f  dbac244c020000           fld       xword ptr [esp + 0x24c]
0042a026  dec9                     fmulp     st(1)
0042a028  d835c414e001             fdiv      dword ptr [0x1e014c4]
0042a02e  dec2                     faddp     st(2)
0042a030  d9c9                     fxch      st(1)
0042a032  d9e0                     fchs
0042a034  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a03a  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
0042a041  d9cb                     fxch      st(3)
0042a043  dbbc2440020000           fstp      xword ptr [esp + 0x240]
0042a04a  d9ca                     fxch      st(2)
0042a04c  dbbc2434020000           fstp      xword ptr [esp + 0x234]
0042a053  dbac2428020000           fld       xword ptr [esp + 0x228]
0042a05a  d9c9                     fxch      st(1)
0042a05c  d9ca                     fxch      st(2)
0042a05e  d9c9                     fxch      st(1)
0042a060  8b8c24b8030000           mov       ecx, dword ptr [esp + 0x3b8]
0042a067  8b74b1ec                 mov       esi, dword ptr [ecx + esi*4 - 0x14]
0042a06b  89c1                     mov       ecx, eax
0042a06d  29f1                     sub       ecx, esi
0042a06f  89cb                     mov       ebx, ecx
0042a071  83fb00                   cmp       ebx, 0
0042a074  8984240c010000           mov       dword ptr [esp + 0x10c], eax
0042a07b  7e3e                     jle       0x42a0bb
0042a07d  dbac244c020000           fld       xword ptr [esp + 0x24c]
0042a084  dbac2434020000           fld       xword ptr [esp + 0x234]
0042a08b  dec9                     fmulp     st(1)
0042a08d  decb                     fmulp     st(3)
0042a08f  dbac2440020000           fld       xword ptr [esp + 0x240]
0042a096  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0042a09c  8b84240c010000           mov       eax, dword ptr [esp + 0x10c]
0042a0a3  defb                     fdivp     st(3)
0042a0a5  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a0ac  29d9                     sub       ecx, ebx
0042a0ae  d9ca                     fxch      st(2)
0042a0b0  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
0042a0b7  d9c9                     fxch      st(1)
0042a0b9  eb35                     jmp       0x42a0f0
0042a0bb  dbac2434020000           fld       xword ptr [esp + 0x234]
0042a0c2  dbac244c020000           fld       xword ptr [esp + 0x24c]
0042a0c9  dec9                     fmulp     st(1)
0042a0cb  decb                     fmulp     st(3)
0042a0cd  dbac2440020000           fld       xword ptr [esp + 0x240]
0042a0d4  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0042a0da  defb                     fdivp     st(3)
0042a0dc  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a0e3  01d9                     add       ecx, ebx
0042a0e5  d9ca                     fxch      st(2)
0042a0e7  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042a0ee  d9c9                     fxch      st(1)
0042a0f0  46                       inc       esi
0042a0f1  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a0f7  89c1                     mov       ecx, eax
0042a0f9  29f1                     sub       ecx, esi
0042a0fb  89cb                     mov       ebx, ecx
0042a0fd  83fb00                   cmp       ebx, 0
0042a100  89842408010000           mov       dword ptr [esp + 0x108], eax
0042a107  7e27                     jle       0x42a130
0042a109  d83534765200             fdiv      dword ptr [0x527634] ; bits=00000000, f32=0.0
0042a10f  d8c8                     fmul      st(0)
0042a111  d82d08725200             fsubr     dword ptr [0x527208] ; bits=0000803f, f32=1.0
0042a117  8b842408010000           mov       eax, dword ptr [esp + 0x108]
0042a11e  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a125  29d9                     sub       ecx, ebx
0042a127  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
0042a12e  eb1e                     jmp       0x42a14e
0042a130  d83534765200             fdiv      dword ptr [0x527634] ; bits=00000000, f32=0.0
0042a136  d8c8                     fmul      st(0)
0042a138  d82d08725200             fsubr     dword ptr [0x527208] ; bits=0000803f, f32=1.0
0042a13e  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a145  01d9                     add       ecx, ebx
0042a147  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042a14e  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
0042a155  8b74a8ec                 mov       esi, dword ptr [eax + ebp*4 - 0x14]
0042a159  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a15f  89e9                     mov       ecx, ebp
0042a161  29f1                     sub       ecx, esi
0042a163  89cb                     mov       ebx, ecx
0042a165  83fb00                   cmp       ebx, 0
0042a168  7e31                     jle       0x42a19b
0042a16a  dbac244c020000           fld       xword ptr [esp + 0x24c]
0042a171  d80dc4755200             fmul      dword ptr [0x5275c4] ; bits=00000000, f32=0.0
0042a177  dec9                     fmulp     st(1)
0042a179  d905c8755200             fld       dword ptr [0x5275c8] ; bits=00000000, f32=0.0
0042a17f  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0042a185  def9                     fdivp     st(1)
0042a187  d9e0                     fchs
0042a189  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
0042a190  29d9                     sub       ecx, ebx
0042a192  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
0042a199  eb2f                     jmp       0x42a1ca
0042a19b  dbac244c020000           fld       xword ptr [esp + 0x24c]
0042a1a2  d80dc4755200             fmul      dword ptr [0x5275c4] ; bits=00000000, f32=0.0
0042a1a8  dec9                     fmulp     st(1)
0042a1aa  d905c8755200             fld       dword ptr [0x5275c8] ; bits=00000000, f32=0.0
0042a1b0  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0042a1b6  def9                     fdivp     st(1)
0042a1b8  d9e0                     fchs
0042a1ba  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a1c1  01d9                     add       ecx, ebx
0042a1c3  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042a1ca  46                       inc       esi
0042a1cb  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a1d1  89e9                     mov       ecx, ebp
0042a1d3  29f1                     sub       ecx, esi
0042a1d5  89cb                     mov       ebx, ecx
0042a1d7  83fb00                   cmp       ebx, 0
0042a1da  7e2a                     jle       0x42a206
0042a1dc  dbac2494020000           fld       xword ptr [esp + 0x294]
0042a1e3  d83530765200             fdiv      dword ptr [0x527630] ; bits=00000000, f32=0.0
0042a1e9  d8c8                     fmul      st(0)
0042a1eb  d80528725200             fadd      dword ptr [0x527228] ; bits=000080bf, f32=-1.0
0042a1f1  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
0042a1f8  29d9                     sub       ecx, ebx
0042a1fa  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
0042a201  e923cfffff               jmp       0x427129
0042a206  dbac2494020000           fld       xword ptr [esp + 0x294]
0042a20d  d83530765200             fdiv      dword ptr [0x527630] ; bits=00000000, f32=0.0
0042a213  d8c8                     fmul      st(0)
0042a215  d80528725200             fadd      dword ptr [0x527228] ; bits=000080bf, f32=-1.0
0042a21b  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a222  01d9                     add       ecx, ebx
0042a224  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042a22b  e9f9ceffff               jmp       0x427129
0042a230  681c765200               push      0x52761c
0042a235  6828765200               push      0x527628
0042a23a  6820765200               push      0x527620
0042a23f  682c765200               push      0x52762c
0042a244  6818765200               push      0x527618
0042a249  6824765200               push      0x527624
0042a24e  6840765200               push      0x527640
0042a253  68a0a40102               push      0x201a4a0
0042a258  68209e0002               push      0x2009e20
0042a25d  686014ff01               push      0x1ff1460
0042a262  8bbc24e0030000           mov       edi, dword ptr [esp + 0x3e0]
0042a269  8d07                     lea       eax, [edi]
0042a26b  50                       push      eax
0042a26c  8b8424e0030000           mov       eax, dword ptr [esp + 0x3e0]
0042a273  898424b0010000           mov       dword ptr [esp + 0x1b0], eax
0042a27a  8d08                     lea       ecx, [eax]
0042a27c  51                       push      ecx
0042a27d  6884725200               push      0x527284
0042a282  8b8c24d0030000           mov       ecx, dword ptr [esp + 0x3d0]
0042a289  8d09                     lea       ecx, [ecx]
0042a28b  51                       push      ecx
0042a28c  8b8c24e8030000           mov       ecx, dword ptr [esp + 0x3e8]
0042a293  8d09                     lea       ecx, [ecx]
0042a295  51                       push      ecx
0042a296  68b40e6c01               push      0x16c0eb4
0042a29b  68ac755200               push      0x5275ac
0042a2a0  e82b40feff               call      0x40e2d0 ; _sidewr_
0042a2a5  83c444                   add       esp, 0x44
0042a2a8  8b8c2484010000           mov       ecx, dword ptr [esp + 0x184]
0042a2af  8b05ac755200             mov       eax, dword ptr [0x5275ac] ; bits=00000000, f32=0.0
0042a2b5  8b1481                   mov       edx, dword ptr [ecx + eax*4]
0042a2b8  89bc2480010000           mov       dword ptr [esp + 0x180], edi
0042a2bf  8b7c8104                 mov       edi, dword ptr [ecx + eax*4 + 4]
0042a2c3  8994247c010000           mov       dword ptr [esp + 0x17c], edx
0042a2ca  8b6c8108                 mov       ebp, dword ptr [ecx + eax*4 + 8]
0042a2ce  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a2d4  40                       inc       eax
0042a2d5  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
0042a2db  d90540765200             fld       dword ptr [0x527640] ; bits=00000000, f32=0.0
0042a2e1  d9e0                     fchs
0042a2e3  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a2e9  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
0042a2f0  8b8c247c010000           mov       ecx, dword ptr [esp + 0x17c]
0042a2f7  89bc2478010000           mov       dword ptr [esp + 0x178], edi
0042a2fe  8d3cc9                   lea       edi, [ecx + ecx*8]
0042a301  8b8c2480010000           mov       ecx, dword ptr [esp + 0x180]
0042a308  8b74b9ec                 mov       esi, dword ptr [ecx + edi*4 - 0x14]
0042a30c  89c1                     mov       ecx, eax
0042a30e  29f1                     sub       ecx, esi
0042a310  89cb                     mov       ebx, ecx
0042a312  83fb00                   cmp       ebx, 0
0042a315  89842474010000           mov       dword ptr [esp + 0x174], eax
0042a31c  7e1f                     jle       0x42a33d
0042a31e  8b842474010000           mov       eax, dword ptr [esp + 0x174]
0042a325  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a32c  29d9                     sub       ecx, ebx
0042a32e  8b0518765200             mov       eax, dword ptr [0x527618] ; bits=00000000, f32=0.0
0042a334  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
0042a33b  eb16                     jmp       0x42a353
0042a33d  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a344  01d9                     add       ecx, ebx
0042a346  8b0518765200             mov       eax, dword ptr [0x527618] ; bits=00000000, f32=0.0
0042a34c  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
0042a353  46                       inc       esi
0042a354  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a35a  89c1                     mov       ecx, eax
0042a35c  29f1                     sub       ecx, esi
0042a35e  89cb                     mov       ebx, ecx
0042a360  83fb00                   cmp       ebx, 0
0042a363  8984246c010000           mov       dword ptr [esp + 0x16c], eax
0042a36a  7e1f                     jle       0x42a38b
0042a36c  8b84246c010000           mov       eax, dword ptr [esp + 0x16c]
0042a373  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a37a  29d9                     sub       ecx, ebx
0042a37c  8b0524765200             mov       eax, dword ptr [0x527624] ; bits=00000000, f32=0.0
0042a382  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
0042a389  eb16                     jmp       0x42a3a1
0042a38b  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a392  01d9                     add       ecx, ebx
0042a394  8b0524765200             mov       eax, dword ptr [0x527624] ; bits=00000000, f32=0.0
0042a39a  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
0042a3a1  8b842478010000           mov       eax, dword ptr [esp + 0x178]
0042a3a8  8d0cc0                   lea       ecx, [eax + eax*8]
0042a3ab  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
0042a3b2  8b7488ec                 mov       esi, dword ptr [eax + ecx*4 - 0x14]
0042a3b6  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a3bc  89c1                     mov       ecx, eax
0042a3be  29f1                     sub       ecx, esi
0042a3c0  89cb                     mov       ebx, ecx
0042a3c2  83fb00                   cmp       ebx, 0
0042a3c5  89842468010000           mov       dword ptr [esp + 0x168], eax
0042a3cc  7e1f                     jle       0x42a3ed
0042a3ce  8b842468010000           mov       eax, dword ptr [esp + 0x168]
0042a3d5  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a3dc  29d9                     sub       ecx, ebx
0042a3de  8b0520765200             mov       eax, dword ptr [0x527620] ; bits=00000000, f32=0.0
0042a3e4  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
0042a3eb  eb16                     jmp       0x42a403
0042a3ed  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a3f4  01d9                     add       ecx, ebx
0042a3f6  8b0520765200             mov       eax, dword ptr [0x527620] ; bits=00000000, f32=0.0
0042a3fc  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
0042a403  46                       inc       esi
0042a404  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a40a  89c1                     mov       ecx, eax
0042a40c  29f1                     sub       ecx, esi
0042a40e  89cb                     mov       ebx, ecx
0042a410  83fb00                   cmp       ebx, 0
0042a413  89842464010000           mov       dword ptr [esp + 0x164], eax
0042a41a  7e1f                     jle       0x42a43b
0042a41c  8b842464010000           mov       eax, dword ptr [esp + 0x164]
0042a423  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a42a  29d9                     sub       ecx, ebx
0042a42c  8b052c765200             mov       eax, dword ptr [0x52762c] ; bits=00000000, f32=0.0
0042a432  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
0042a439  eb16                     jmp       0x42a451
0042a43b  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a442  01d9                     add       ecx, ebx
0042a444  8b052c765200             mov       eax, dword ptr [0x52762c] ; bits=00000000, f32=0.0
0042a44a  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
0042a451  8d4ced00                 lea       ecx, [ebp + ebp*8]
0042a455  8b8424b8030000           mov       eax, dword ptr [esp + 0x3b8]
0042a45c  8b7488ec                 mov       esi, dword ptr [eax + ecx*4 - 0x14]
0042a460  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a466  89e9                     mov       ecx, ebp
0042a468  29f1                     sub       ecx, esi
0042a46a  89cb                     mov       ebx, ecx
0042a46c  83fb00                   cmp       ebx, 0
0042a46f  7e18                     jle       0x42a489
0042a471  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
0042a478  29d9                     sub       ecx, ebx
0042a47a  8b051c765200             mov       eax, dword ptr [0x52761c] ; bits=00000000, f32=0.0
0042a480  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
0042a487  eb16                     jmp       0x42a49f
0042a489  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a490  01d9                     add       ecx, ebx
0042a492  8b051c765200             mov       eax, dword ptr [0x52761c] ; bits=00000000, f32=0.0
0042a498  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
0042a49f  46                       inc       esi
0042a4a0  8b2da8755200             mov       ebp, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a4a6  89e9                     mov       ecx, ebp
0042a4a8  29f1                     sub       ecx, esi
0042a4aa  89cb                     mov       ebx, ecx
0042a4ac  83fb00                   cmp       ebx, 0
0042a4af  7e1b                     jle       0x42a4cc
0042a4b1  8b0cad28007501           mov       ecx, dword ptr [ebp*4 + 0x1750028]
0042a4b8  29d9                     sub       ecx, ebx
0042a4ba  8b0528765200             mov       eax, dword ptr [0x527628] ; bits=00000000, f32=0.0
0042a4c0  89048dfce27c01           mov       dword ptr [ecx*4 + 0x17ce2fc], eax
0042a4c7  e95dccffff               jmp       0x427129
0042a4cc  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a4d3  01d9                     add       ecx, ebx
0042a4d5  8b0528765200             mov       eax, dword ptr [0x527628] ; bits=00000000, f32=0.0
0042a4db  89048df8e27c01           mov       dword ptr [ecx*4 + 0x17ce2f8], eax
0042a4e2  e942ccffff               jmp       0x427129
0042a4e7  8b8424b4030000           mov       eax, dword ptr [esp + 0x3b4]
0042a4ee  8b2c88                   mov       ebp, dword ptr [eax + ecx*4]
0042a4f1  8b7c8804                 mov       edi, dword ptr [eax + ecx*4 + 4]
0042a4f5  893da4755200             mov       dword ptr [0x5275a4], edi ; bits=00000000, f32=0.0
0042a4fb  8b7c880c                 mov       edi, dword ptr [eax + ecx*4 + 0xc]
0042a4ff  893da0765200             mov       dword ptr [0x5276a0], edi ; bits=00000000, f32=0.0
0042a505  d905a0765200             fld       dword ptr [0x5276a0] ; bits=00000000, f32=0.0
0042a50b  8b448810                 mov       eax, dword ptr [eax + ecx*4 + 0x10]
0042a50f  8905a0765200             mov       dword ptr [0x5276a0], eax ; bits=00000000, f32=0.0
0042a515  d905a0765200             fld       dword ptr [0x5276a0] ; bits=00000000, f32=0.0
0042a51b  dbbc241c020000           fstp      xword ptr [esp + 0x21c]
0042a522  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a528  40                       inc       eax
0042a529  8905a8755200             mov       dword ptr [0x5275a8], eax ; bits=00000000, f32=0.0
0042a52f  8d44ed00                 lea       eax, [ebp + ebp*8]
0042a533  8bbc24b8030000           mov       edi, dword ptr [esp + 0x3b8]
0042a53a  8b7487ec                 mov       esi, dword ptr [edi + eax*4 - 0x14]
0042a53e  8b3da8755200             mov       edi, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a544  89fa                     mov       edx, edi
0042a546  29f2                     sub       edx, esi
0042a548  89d3                     mov       ebx, edx
0042a54a  83fb00                   cmp       ebx, 0
0042a54d  898424a8010000           mov       dword ptr [esp + 0x1a8], eax
0042a554  89bc24a4010000           mov       dword ptr [esp + 0x1a4], edi
0042a55b  7e1d                     jle       0x42a57a
0042a55d  d9c0                     fld       st(0)
0042a55f  8b8424a4010000           mov       eax, dword ptr [esp + 0x1a4]
0042a566  d9e0                     fchs
0042a568  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a56f  29d9                     sub       ecx, ebx
0042a571  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
0042a578  eb14                     jmp       0x42a58e
0042a57a  d9c0                     fld       st(0)
0042a57c  d9e0                     fchs
0042a57e  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a585  01d9                     add       ecx, ebx
0042a587  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042a58e  46                       inc       esi
0042a58f  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a595  89c1                     mov       ecx, eax
0042a597  29f1                     sub       ecx, esi
0042a599  89cb                     mov       ebx, ecx
0042a59b  83fb00                   cmp       ebx, 0
0042a59e  898424a0010000           mov       dword ptr [esp + 0x1a0], eax
0042a5a5  7e1d                     jle       0x42a5c4
0042a5a7  8b8424a0010000           mov       eax, dword ptr [esp + 0x1a0]
0042a5ae  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a5b5  29d9                     sub       ecx, ebx
0042a5b7  c7048dfce27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2fc], 0x3f800000
0042a5c2  eb14                     jmp       0x42a5d8
0042a5c4  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a5cb  01d9                     add       ecx, ebx
0042a5cd  c7048df8e27c010000803f   mov       dword ptr [ecx*4 + 0x17ce2f8], 0x3f800000
0042a5d8  8b05a4755200             mov       eax, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
0042a5de  8d04c0                   lea       eax, [eax + eax*8]
0042a5e1  8b9424b8030000           mov       edx, dword ptr [esp + 0x3b8]
0042a5e8  8b4c82ec                 mov       ecx, dword ptr [edx + eax*4 - 0x14]
0042a5ec  89ce                     mov       esi, ecx
0042a5ee  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a5f4  89c2                     mov       edx, eax
0042a5f6  29ca                     sub       edx, ecx
0042a5f8  89d3                     mov       ebx, edx
0042a5fa  83fb00                   cmp       ebx, 0
0042a5fd  8984249c010000           mov       dword ptr [esp + 0x19c], eax
0042a604  7e1d                     jle       0x42a623
0042a606  d9c0                     fld       st(0)
0042a608  8b84249c010000           mov       eax, dword ptr [esp + 0x19c]
0042a60f  d9e0                     fchs
0042a611  8b148528007501           mov       edx, dword ptr [eax*4 + 0x1750028]
0042a618  29da                     sub       edx, ebx
0042a61a  d91c95fce27c01           fstp      dword ptr [edx*4 + 0x17ce2fc]
0042a621  eb14                     jmp       0x42a637
0042a623  d9c0                     fld       st(0)
0042a625  d9e0                     fchs
0042a627  8b04b5ac837601           mov       eax, dword ptr [esi*4 + 0x17683ac]
0042a62e  01d8                     add       eax, ebx
0042a630  d91c85f8e27c01           fstp      dword ptr [eax*4 + 0x17ce2f8]
0042a637  46                       inc       esi
0042a638  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a63e  89c2                     mov       edx, eax
0042a640  29f2                     sub       edx, esi
0042a642  89d3                     mov       ebx, edx
0042a644  83fb00                   cmp       ebx, 0
0042a647  89842498010000           mov       dword ptr [esp + 0x198], eax
0042a64e  7e1d                     jle       0x42a66d
0042a650  8b842498010000           mov       eax, dword ptr [esp + 0x198]
0042a657  8b348528007501           mov       esi, dword ptr [eax*4 + 0x1750028]
0042a65e  29de                     sub       esi, ebx
0042a660  c704b5fce27c01000080bf   mov       dword ptr [esi*4 + 0x17ce2fc], 0xbf800000
0042a66b  eb14                     jmp       0x42a681
0042a66d  8b34b5ac837601           mov       esi, dword ptr [esi*4 + 0x17683ac]
0042a674  01de                     add       esi, ebx
0042a676  c704b5f8e27c01000080bf   mov       dword ptr [esi*4 + 0x17ce2f8], 0xbf800000
0042a681  d904ad1c9e0002           fld       dword ptr [ebp*4 + 0x2009e1c]
0042a688  d904ad9ca40102           fld       dword ptr [ebp*4 + 0x201a49c]
0042a68f  d804ad1c9e0002           fadd      dword ptr [ebp*4 + 0x2009e1c]
0042a696  8b15a4755200             mov       edx, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
0042a69c  d904951c9e0002           fld       dword ptr [edx*4 + 0x2009e1c]
0042a6a3  d9c9                     fxch      st(1)
0042a6a5  d824951c9e0002           fsub      dword ptr [edx*4 + 0x2009e1c]
0042a6ac  d824959ca40102           fsub      dword ptr [edx*4 + 0x201a49c]
0042a6b3  d904ad5c14ff01           fld       dword ptr [ebp*4 + 0x1ff145c]
0042a6ba  d904955c14ff01           fld       dword ptr [edx*4 + 0x1ff145c]
0042a6c1  d9c0                     fld       st(0)
0042a6c3  d804ad5c14ff01           fadd      dword ptr [ebp*4 + 0x1ff145c]
0042a6ca  dece                     fmulp     st(6)
0042a6cc  d9ca                     fxch      st(2)
0042a6ce  dee5                     fsubrp    st(5)
0042a6d0  d9cc                     fxch      st(4)
0042a6d2  d9e0                     fchs
0042a6d4  8b15a8755200             mov       edx, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a6da  d91c95f84baa01           fstp      dword ptr [edx*4 + 0x1aa4bf8]
0042a6e1  dbac241c020000           fld       xword ptr [esp + 0x21c]
0042a6e8  8bbc24c4010000           mov       edi, dword ptr [esp + 0x1c4]
0042a6ef  dc37                     fdiv      qword ptr [edi]
0042a6f1  d9e0                     fchs
0042a6f3  d99c247c030000           fstp      dword ptr [esp + 0x37c]
0042a6fa  d984247c030000           fld       dword ptr [esp + 0x37c]
0042a701  dbbc2410020000           fstp      xword ptr [esp + 0x210]
0042a708  d9ca                     fxch      st(2)
0042a70a  dbbc2404020000           fstp      xword ptr [esp + 0x204]
0042a711  dbbc24f8010000           fstp      xword ptr [esp + 0x1f8]
0042a718  dbbc24ec010000           fstp      xword ptr [esp + 0x1ec]
0042a71f  dbbc24e0010000           fstp      xword ptr [esp + 0x1e0]
0042a726  42                       inc       edx
0042a727  8915a8755200             mov       dword ptr [0x5275a8], edx ; bits=00000000, f32=0.0
0042a72d  8b8424a8010000           mov       eax, dword ptr [esp + 0x1a8]
0042a734  8b9424b8030000           mov       edx, dword ptr [esp + 0x3b8]
0042a73b  8b7482ec                 mov       esi, dword ptr [edx + eax*4 - 0x14]
0042a73f  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a745  89c2                     mov       edx, eax
0042a747  29f2                     sub       edx, esi
0042a749  89d3                     mov       ebx, edx
0042a74b  83fb00                   cmp       ebx, 0
0042a74e  89842494010000           mov       dword ptr [esp + 0x194], eax
0042a755  7e1d                     jle       0x42a774
0042a757  8b842494010000           mov       eax, dword ptr [esp + 0x194]
0042a75e  8b148528007501           mov       edx, dword ptr [eax*4 + 0x1750028]
0042a765  29da                     sub       edx, ebx
0042a767  c70495fce27c010000803f   mov       dword ptr [edx*4 + 0x17ce2fc], 0x3f800000
0042a772  eb14                     jmp       0x42a788
0042a774  8b04b5ac837601           mov       eax, dword ptr [esi*4 + 0x17683ac]
0042a77b  01d8                     add       eax, ebx
0042a77d  c70485f8e27c010000803f   mov       dword ptr [eax*4 + 0x17ce2f8], 0x3f800000
0042a788  46                       inc       esi
0042a789  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a78f  89c2                     mov       edx, eax
0042a791  29f2                     sub       edx, esi
0042a793  89d3                     mov       ebx, edx
0042a795  83fb00                   cmp       ebx, 0
0042a798  89842490010000           mov       dword ptr [esp + 0x190], eax
0042a79f  7e20                     jle       0x42a7c1
0042a7a1  8b842490010000           mov       eax, dword ptr [esp + 0x190]
0042a7a8  8b348528007501           mov       esi, dword ptr [eax*4 + 0x1750028]
0042a7af  29de                     sub       esi, ebx
0042a7b1  dbac2410020000           fld       xword ptr [esp + 0x210]
0042a7b8  d91cb5fce27c01           fstp      dword ptr [esi*4 + 0x17ce2fc]
0042a7bf  eb17                     jmp       0x42a7d8
0042a7c1  8b34b5ac837601           mov       esi, dword ptr [esi*4 + 0x17683ac]
0042a7c8  01de                     add       esi, ebx
0042a7ca  dbac2410020000           fld       xword ptr [esp + 0x210]
0042a7d1  d91cb5f8e27c01           fstp      dword ptr [esi*4 + 0x17ce2f8]
0042a7d8  89ce                     mov       esi, ecx
0042a7da  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a7e0  89c2                     mov       edx, eax
0042a7e2  29ca                     sub       edx, ecx
0042a7e4  89d3                     mov       ebx, edx
0042a7e6  83fb00                   cmp       ebx, 0
0042a7e9  8984248c010000           mov       dword ptr [esp + 0x18c], eax
0042a7f0  7e1d                     jle       0x42a80f
0042a7f2  8b84248c010000           mov       eax, dword ptr [esp + 0x18c]
0042a7f9  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a800  29d9                     sub       ecx, ebx
0042a802  c7048dfce27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2fc], 0xbf800000
0042a80d  eb14                     jmp       0x42a823
0042a80f  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a816  01d9                     add       ecx, ebx
0042a818  c7048df8e27c01000080bf   mov       dword ptr [ecx*4 + 0x17ce2f8], 0xbf800000
0042a823  46                       inc       esi
0042a824  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a82a  89c1                     mov       ecx, eax
0042a82c  29f1                     sub       ecx, esi
0042a82e  89cb                     mov       ebx, ecx
0042a830  83fb00                   cmp       ebx, 0
0042a833  89842488010000           mov       dword ptr [esp + 0x188], eax
0042a83a  7e20                     jle       0x42a85c
0042a83c  8b842488010000           mov       eax, dword ptr [esp + 0x188]
0042a843  8b0c8528007501           mov       ecx, dword ptr [eax*4 + 0x1750028]
0042a84a  29d9                     sub       ecx, ebx
0042a84c  dbac2410020000           fld       xword ptr [esp + 0x210]
0042a853  d91c8dfce27c01           fstp      dword ptr [ecx*4 + 0x17ce2fc]
0042a85a  eb17                     jmp       0x42a873
0042a85c  8b0cb5ac837601           mov       ecx, dword ptr [esi*4 + 0x17683ac]
0042a863  01d9                     add       ecx, ebx
0042a865  dbac2410020000           fld       xword ptr [esp + 0x210]
0042a86c  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0042a873  dbac24e0010000           fld       xword ptr [esp + 0x1e0]
0042a87a  dbac24ec010000           fld       xword ptr [esp + 0x1ec]
0042a881  dee9                     fsubp     st(1)
0042a883  dbac2404020000           fld       xword ptr [esp + 0x204]
0042a88a  dbac24f8010000           fld       xword ptr [esp + 0x1f8]
0042a891  dec1                     faddp     st(1)
0042a893  8b05a4755200             mov       eax, dword ptr [0x5275a4] ; bits=00000000, f32=0.0
0042a899  d82485dc1a0002           fsub      dword ptr [eax*4 + 0x2001adc]
0042a8a0  d824addc1a0002           fsub      dword ptr [ebp*4 + 0x2001adc]
0042a8a7  dbac2410020000           fld       xword ptr [esp + 0x210]
0042a8ae  dec9                     fmulp     st(1)
0042a8b0  dec1                     faddp     st(1)
0042a8b2  d9e0                     fchs
0042a8b4  8b05a8755200             mov       eax, dword ptr [0x5275a8] ; bits=00000000, f32=0.0
0042a8ba  d91c85f84baa01           fstp      dword ptr [eax*4 + 0x1aa4bf8]
0042a8c1  e963c8ffff               jmp       0x427129
0042a8c6  8b8424bc030000           mov       eax, dword ptr [esp + 0x3bc]
0042a8cd  c70000000000             mov       dword ptr [eax], 0
0042a8d3  8b1d24007501             mov       ebx, dword ptr [0x1750024]
0042a8d9  83fb00                   cmp       ebx, 0
0042a8dc  0f8e58010000             jle       0x42aa3a
0042a8e2  b901000000               mov       ecx, 1
0042a8e7  d9ee                     fldz
0042a8e9  dbbc24d4010000           fstp      xword ptr [esp + 0x1d4]
0042a8f0  83fb02                   cmp       ebx, 2
0042a8f3  0f8cce000000             jl        0x42a9c7
0042a8f9  dbac24d4010000           fld       xword ptr [esp + 0x1d4]
0042a900  d9048df84baa01           fld       dword ptr [ecx*4 + 0x1aa4bf8]
0042a907  d9c0                     fld       st(0)
0042a909  d9e1                     fabs
0042a90b  d90520725200             fld       dword ptr [0x527220] ; bits=a95f6358, f32=999999986991104.0
0042a911  d9c9                     fxch      st(1)
0042a913  dff1                     fcompi    st(1)
0042a915  dbbc24c8010000           fstp      xword ptr [esp + 0x1c8]
0042a91c  d9c9                     fxch      st(1)
0042a91e  0f8a0d000000             jp        0x42a931
0042a924  760b                     jbe       0x42a931
0042a926  ddd9                     fstp      st(1)
0042a928  dbac24c8010000           fld       xword ptr [esp + 0x1c8]
0042a92f  d9c9                     fxch      st(1)
0042a931  d9c1                     fld       st(1)
0042a933  d8c8                     fmul      st(0)
0042a935  dec1                     faddp     st(1)
0042a937  d9c9                     fxch      st(1)
0042a939  d9e1                     fabs
0042a93b  8bb424c0030000           mov       esi, dword ptr [esp + 0x3c0]
0042a942  d906                     fld       dword ptr [esi]
0042a944  dff1                     fcompi    st(1)
0042a946  0f8a0f000000             jp        0x42a95b
0042a94c  730d                     jae       0x42a95b
0042a94e  d91e                     fstp      dword ptr [esi]
0042a950  8b8424c4030000           mov       eax, dword ptr [esp + 0x3c4]
0042a957  8908                     mov       dword ptr [eax], ecx
0042a959  eb02                     jmp       0x42a95d
0042a95b  ddd8                     fstp      st(0)
0042a95d  41                       inc       ecx
0042a95e  d9048df84baa01           fld       dword ptr [ecx*4 + 0x1aa4bf8]
0042a965  d9c0                     fld       st(0)
0042a967  d9e1                     fabs
0042a969  d90520725200             fld       dword ptr [0x527220] ; bits=a95f6358, f32=999999986991104.0
0042a96f  d9c9                     fxch      st(1)
0042a971  dff1                     fcompi    st(1)
0042a973  d9c9                     fxch      st(1)
0042a975  d9ca                     fxch      st(2)
0042a977  d9c9                     fxch      st(1)
0042a979  0f8a06000000             jp        0x42a985
0042a97f  7604                     jbe       0x42a985
0042a981  ddda                     fstp      st(2)
0042a983  eb02                     jmp       0x42a987
0042a985  ddd8                     fstp      st(0)
0042a987  d9c1                     fld       st(1)
0042a989  d8c8                     fmul      st(0)
0042a98b  dec1                     faddp     st(1)
0042a98d  d9c9                     fxch      st(1)
0042a98f  d9e1                     fabs
0042a991  8bb424c0030000           mov       esi, dword ptr [esp + 0x3c0]
0042a998  d906                     fld       dword ptr [esi]
0042a99a  dff1                     fcompi    st(1)
0042a99c  0f8a0f000000             jp        0x42a9b1
0042a9a2  730d                     jae       0x42a9b1
0042a9a4  d91e                     fstp      dword ptr [esi]
0042a9a6  8b8424c4030000           mov       eax, dword ptr [esp + 0x3c4]
0042a9ad  8908                     mov       dword ptr [eax], ecx
0042a9af  eb02                     jmp       0x42a9b3
0042a9b1  ddd8                     fstp      st(0)
0042a9b3  41                       inc       ecx
0042a9b4  83eb02                   sub       ebx, 2
0042a9b7  83fb02                   cmp       ebx, 2
0042a9ba  0f8d40ffffff             jge       0x42a900
0042a9c0  dbbc24d4010000           fstp      xword ptr [esp + 0x1d4]
0042a9c7  85db                     test      ebx, ebx
0042a9c9  745f                     je        0x42aa2a
0042a9cb  d9048df84baa01           fld       dword ptr [ecx*4 + 0x1aa4bf8]
0042a9d2  d9c0                     fld       st(0)
0042a9d4  d9e1                     fabs
0042a9d6  d90520725200             fld       dword ptr [0x527220] ; bits=a95f6358, f32=999999986991104.0
0042a9dc  d9c9                     fxch      st(1)
0042a9de  dff1                     fcompi    st(1)
0042a9e0  0f8a06000000             jp        0x42a9ec
0042a9e6  7604                     jbe       0x42a9ec
0042a9e8  ddd9                     fstp      st(1)
0042a9ea  eb02                     jmp       0x42a9ee
0042a9ec  ddd8                     fstp      st(0)
0042a9ee  dbac24d4010000           fld       xword ptr [esp + 0x1d4]
0042a9f5  d9c1                     fld       st(1)
0042a9f7  d8c8                     fmul      st(0)
0042a9f9  dec1                     faddp     st(1)
0042a9fb  d9c9                     fxch      st(1)
0042a9fd  d9e1                     fabs
0042a9ff  8b9c24c0030000           mov       ebx, dword ptr [esp + 0x3c0]
0042aa06  d903                     fld       dword ptr [ebx]
0042aa08  dff1                     fcompi    st(1)
0042aa0a  d9c9                     fxch      st(1)
0042aa0c  dbbc24d4010000           fstp      xword ptr [esp + 0x1d4]
0042aa13  0f8a0f000000             jp        0x42aa28
0042aa19  730d                     jae       0x42aa28
0042aa1b  d91b                     fstp      dword ptr [ebx]
0042aa1d  8b8424c4030000           mov       eax, dword ptr [esp + 0x3c4]
0042aa24  8908                     mov       dword ptr [eax], ecx
0042aa26  eb02                     jmp       0x42aa2a
0042aa28  ddd8                     fstp      st(0)
0042aa2a  8b8424bc030000           mov       eax, dword ptr [esp + 0x3bc]
0042aa31  dbac24d4010000           fld       xword ptr [esp + 0x1d4]
0042aa38  d918                     fstp      dword ptr [eax]
0042aa3a  b800000000               mov       eax, 0
0042aa3f  5f                       pop       edi
0042aa40  5e                       pop       esi
0042aa41  5b                       pop       ebx
0042aa42  5d                       pop       ebp
0042aa43  81c474030000             add       esp, 0x374
0042aa49  c3                       ret
0042aa4a  8d9b00000000             lea       ebx, [ebx]
