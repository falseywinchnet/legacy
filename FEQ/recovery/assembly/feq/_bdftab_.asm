; _bdftab_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x202c0
004202c0  81ec90000000             sub       esp, 0x90
004202c6  53                       push      ebx
004202c7  56                       push      esi
004202c8  57                       push      edi
004202c9  8b8424a0000000           mov       eax, dword ptr [esp + 0xa0]
004202d0  8b8c24a8000000           mov       ecx, dword ptr [esp + 0xa8]
004202d7  89442434                 mov       dword ptr [esp + 0x34], eax
004202db  894c2430                 mov       dword ptr [esp + 0x30], ecx
004202df  8b442434                 mov       eax, dword ptr [esp + 0x34]
004202e3  8b10                     mov       edx, dword ptr [eax]
004202e5  8b9c24bc000000           mov       ebx, dword ptr [esp + 0xbc]
004202ec  8b749304                 mov       esi, dword ptr [ebx + edx*4 + 4]
004202f0  8b7c9308                 mov       edi, dword ptr [ebx + edx*4 + 8]
004202f4  8b44930c                 mov       eax, dword ptr [ebx + edx*4 + 0xc]
004202f8  8974242c                 mov       dword ptr [esp + 0x2c], esi
004202fc  8b749310                 mov       esi, dword ptr [ebx + edx*4 + 0x10]
00420300  897c2428                 mov       dword ptr [esp + 0x28], edi
00420304  8b7c9314                 mov       edi, dword ptr [ebx + edx*4 + 0x14]
00420308  8d0d185a5200             lea       ecx, [0x525a18] ; bits=00000000, f32=0.0
0042030e  8979bc                   mov       dword ptr [ecx - 0x44], edi
00420311  8b7c9318                 mov       edi, dword ptr [ebx + edx*4 + 0x18]
00420315  8979c4                   mov       dword ptr [ecx - 0x3c], edi
00420318  8b7c931c                 mov       edi, dword ptr [ebx + edx*4 + 0x1c]
0042031c  8979b8                   mov       dword ptr [ecx - 0x48], edi
0042031f  8b7c9320                 mov       edi, dword ptr [ebx + edx*4 + 0x20]
00420323  8979c0                   mov       dword ptr [ecx - 0x40], edi
00420326  8b7c9324                 mov       edi, dword ptr [ebx + edx*4 + 0x24]
0042032a  897918                   mov       dword ptr [ecx + 0x18], edi
0042032d  d94118                   fld       dword ptr [ecx + 0x18]
00420330  8b7c9328                 mov       edi, dword ptr [ebx + edx*4 + 0x28]
00420334  897918                   mov       dword ptr [ecx + 0x18], edi
00420337  d94118                   fld       dword ptr [ecx + 0x18]
0042033a  8b7c932c                 mov       edi, dword ptr [ebx + edx*4 + 0x2c]
0042033e  897918                   mov       dword ptr [ecx + 0x18], edi
00420341  d94118                   fld       dword ptr [ecx + 0x18]
00420344  d9c0                     fld       st(0)
00420346  d9ee                     fldz
00420348  dfe9                     fucompi   st(1)
0042034a  ddd8                     fstp      st(0)
0042034c  d9ca                     fxch      st(2)
0042034e  89442424                 mov       dword ptr [esp + 0x24], eax
00420352  89742420                 mov       dword ptr [esp + 0x20], esi
00420356  0f8a02000000             jp        0x42035e
0042035c  7475                     je        0x4203d3
0042035e  8b449330                 mov       eax, dword ptr [ebx + edx*4 + 0x30]
00420362  894118                   mov       dword ptr [ecx + 0x18], eax
00420365  8b4118                   mov       eax, dword ptr [ecx + 0x18]
00420368  8941e0                   mov       dword ptr [ecx - 0x20], eax
0042036b  8b449334                 mov       eax, dword ptr [ebx + edx*4 + 0x34]
0042036f  894118                   mov       dword ptr [ecx + 0x18], eax
00420372  8b4118                   mov       eax, dword ptr [ecx + 0x18]
00420375  8941fc                   mov       dword ptr [ecx - 4], eax
00420378  8b449338                 mov       eax, dword ptr [ebx + edx*4 + 0x38]
0042037c  8941b0                   mov       dword ptr [ecx - 0x50], eax
0042037f  8b44933c                 mov       eax, dword ptr [ebx + edx*4 + 0x3c]
00420383  8941a8                   mov       dword ptr [ecx - 0x58], eax
00420386  8b742428                 mov       esi, dword ptr [esp + 0x28]
0042038a  8b8424b0000000           mov       eax, dword ptr [esp + 0xb0]
00420391  8b7cb0fc                 mov       edi, dword ptr [eax + esi*4 - 4]
00420395  8979f4                   mov       dword ptr [ecx - 0xc], edi
00420398  8b7c242c                 mov       edi, dword ptr [esp + 0x2c]
0042039c  8b74b8fc                 mov       esi, dword ptr [eax + edi*4 - 4]
004203a0  8971f0                   mov       dword ptr [ecx - 0x10], esi
004203a3  89d6                     mov       esi, edx
004203a5  8b74b340                 mov       esi, dword ptr [ebx + esi*4 + 0x40]
004203a9  8971b4                   mov       dword ptr [ecx - 0x4c], esi
004203ac  8379b400                 cmp       dword ptr [ecx - 0x4c], 0
004203b0  8944241c                 mov       dword ptr [esp + 0x1c], eax
004203b4  7e14                     jle       0x4203ca
004203b6  89c8                     mov       eax, ecx
004203b8  8b50b4                   mov       edx, dword ptr [eax - 0x4c]
004203bb  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
004203bf  8b5c90fc                 mov       ebx, dword ptr [eax + edx*4 - 4]
004203c3  89c8                     mov       eax, ecx
004203c5  8958f8                   mov       dword ptr [eax - 8], ebx
004203c8  eb09                     jmp       0x4203d3
004203ca  89c8                     mov       eax, ecx
004203cc  c740f800000000           mov       dword ptr [eax - 8], 0
004203d3  8b4c242c                 mov       ecx, dword ptr [esp + 0x2c]
004203d7  8b8424ac000000           mov       eax, dword ptr [esp + 0xac]
004203de  8b542428                 mov       edx, dword ptr [esp + 0x28]
004203e2  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
004203e6  d94490fc                 fld       dword ptr [eax + edx*4 - 4]
004203ea  8b442430                 mov       eax, dword ptr [esp + 0x30]
004203ee  d9c9                     fxch      st(1)
004203f0  d84488fc                 fadd      dword ptr [eax + ecx*4 - 4]
004203f4  d9c9                     fxch      st(1)
004203f6  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
004203fa  d9c9                     fxch      st(1)
004203fc  d9cc                     fxch      st(4)
004203fe  d9c9                     fxch      st(1)
00420400  d9cb                     fxch      st(3)
00420402  d9c9                     fxch      st(1)
00420404  d9ca                     fxch      st(2)
00420406  8d1d185a5200             lea       ebx, [0x525a18] ; bits=00000000, f32=0.0
0042040c  837bc400                 cmp       dword ptr [ebx - 0x3c], 0
00420410  0f84aa060000             je        0x420ac0
00420416  ddd9                     fstp      st(1)
00420418  d9c3                     fld       st(3)
0042041a  d8e1                     fsub      st(1)
0042041c  d95be4                   fstp      dword ptr [ebx - 0x1c]
0042041f  d9c2                     fld       st(2)
00420421  d8e1                     fsub      st(1)
00420423  d95bd0                   fstp      dword ptr [ebx - 0x30]
00420426  d943e4                   fld       dword ptr [ebx - 0x1c]
00420429  d9ee                     fldz
0042042b  dff1                     fcompi    st(1)
0042042d  ddd8                     fstp      st(0)
0042042f  0f8a0b000000             jp        0x420440
00420435  7609                     jbe       0x420440
00420437  89d8                     mov       eax, ebx
00420439  c740e400000000           mov       dword ptr [eax - 0x1c], 0
00420440  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
00420446  d940d0                   fld       dword ptr [eax - 0x30]
00420449  d9ee                     fldz
0042044b  dff1                     fcompi    st(1)
0042044d  ddd8                     fstp      st(0)
0042044f  89442418                 mov       dword ptr [esp + 0x18], eax
00420453  0f8a0d000000             jp        0x420466
00420459  760b                     jbe       0x420466
0042045b  8b442418                 mov       eax, dword ptr [esp + 0x18]
0042045f  c740d000000000           mov       dword ptr [eax - 0x30], 0
00420466  d9cb                     fxch      st(3)
00420468  dbf2                     fcomi     st(2)
0042046a  d9cb                     fxch      st(3)
0042046c  0f8a06000000             jp        0x420478
00420472  0f8278010000             jb        0x4205f0
00420478  8d0d185a5200             lea       ecx, [0x525a18] ; bits=00000000, f32=0.0
0042047e  d941e4                   fld       dword ptr [ecx - 0x1c]
00420481  d9ee                     fldz
00420483  dff1                     fcompi    st(1)
00420485  ddd8                     fstp      st(0)
00420487  0f8a56000000             jp        0x4204e3
0042048d  7354                     jae       0x4204e3
0042048f  db7c2468                 fstp      xword ptr [esp + 0x68]
00420493  db7c2474                 fstp      xword ptr [esp + 0x74]
00420497  dbbc2480000000           fstp      xword ptr [esp + 0x80]
0042049e  dbbc248c000000           fstp      xword ptr [esp + 0x8c]
004204a5  8d41dc                   lea       eax, [ecx - 0x24]
004204a8  50                       push      eax
004204a9  8d41ac                   lea       eax, [ecx - 0x54]
004204ac  50                       push      eax
004204ad  8d41ec                   lea       eax, [ecx - 0x14]
004204b0  50                       push      eax
004204b1  8d419c                   lea       eax, [ecx - 0x64]
004204b4  50                       push      eax
004204b5  8d41e4                   lea       eax, [ecx - 0x1c]
004204b8  50                       push      eax
004204b9  8d41bc                   lea       eax, [ecx - 0x44]
004204bc  50                       push      eax
004204bd  e87e580100               call      0x435d40 ; _lktab_
004204c2  dbac24a4000000           fld       xword ptr [esp + 0xa4]
004204c9  dbac2498000000           fld       xword ptr [esp + 0x98]
004204d0  dbac248c000000           fld       xword ptr [esp + 0x8c]
004204d7  dbac2480000000           fld       xword ptr [esp + 0x80]
004204de  83c418                   add       esp, 0x18
004204e1  eb12                     jmp       0x4204f5
004204e3  89c8                     mov       eax, ecx
004204e5  c740ec00000000           mov       dword ptr [eax - 0x14], 0
004204ec  89c8                     mov       eax, ecx
004204ee  c740dc00000000           mov       dword ptr [eax - 0x24], 0
004204f5  8d0d185a5200             lea       ecx, [0x525a18] ; bits=00000000, f32=0.0
004204fb  d941d0                   fld       dword ptr [ecx - 0x30]
004204fe  d9ee                     fldz
00420500  dff1                     fcompi    st(1)
00420502  0f8a64000000             jp        0x42056c
00420508  7362                     jae       0x42056c
0042050a  d9c9                     fxch      st(1)
0042050c  db7c2468                 fstp      xword ptr [esp + 0x68]
00420510  d9c9                     fxch      st(1)
00420512  db7c2474                 fstp      xword ptr [esp + 0x74]
00420516  d9c9                     fxch      st(1)
00420518  dbbc2480000000           fstp      xword ptr [esp + 0x80]
0042051f  d9c9                     fxch      st(1)
00420521  dbbc248c000000           fstp      xword ptr [esp + 0x8c]
00420528  d871e4                   fdiv      dword ptr [ecx - 0x1c]
0042052b  d959c8                   fstp      dword ptr [ecx - 0x38]
0042052e  8d41d4                   lea       eax, [ecx - 0x2c]
00420531  50                       push      eax
00420532  8d41ac                   lea       eax, [ecx - 0x54]
00420535  50                       push      eax
00420536  8d41cc                   lea       eax, [ecx - 0x34]
00420539  50                       push      eax
0042053a  8d419c                   lea       eax, [ecx - 0x64]
0042053d  50                       push      eax
0042053e  8d41c8                   lea       eax, [ecx - 0x38]
00420541  50                       push      eax
00420542  8d41c4                   lea       eax, [ecx - 0x3c]
00420545  50                       push      eax
00420546  e8f5570100               call      0x435d40 ; _lktab_
0042054b  dbac24a4000000           fld       xword ptr [esp + 0xa4]
00420552  dbac2498000000           fld       xword ptr [esp + 0x98]
00420559  dbac248c000000           fld       xword ptr [esp + 0x8c]
00420560  dbac2480000000           fld       xword ptr [esp + 0x80]
00420567  83c418                   add       esp, 0x18
0042056a  eb1d                     jmp       0x420589
0042056c  ddd8                     fstp      st(0)
0042056e  89c8                     mov       eax, ecx
00420570  c740cc0000803f           mov       dword ptr [eax - 0x34], 0x3f800000
00420577  89c8                     mov       eax, ecx
00420579  c740d400000000           mov       dword ptr [eax - 0x2c], 0
00420580  89c8                     mov       eax, ecx
00420582  c740e40000803f           mov       dword ptr [eax - 0x1c], 0x3f800000
00420589  db7c245c                 fstp      xword ptr [esp + 0x5c]
0042058d  db7c2450                 fstp      xword ptr [esp + 0x50]
00420591  db7c2444                 fstp      xword ptr [esp + 0x44]
00420595  db7c2438                 fstp      xword ptr [esp + 0x38]
00420599  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
0042059f  d940cc                   fld       dword ptr [eax - 0x34]
004205a2  d9c0                     fld       st(0)
004205a4  d848dc                   fmul      dword ptr [eax - 0x24]
004205a7  d940ec                   fld       dword ptr [eax - 0x14]
004205aa  d940d4                   fld       dword ptr [eax - 0x2c]
004205ad  d848ec                   fmul      dword ptr [eax - 0x14]
004205b0  d9c0                     fld       st(0)
004205b2  d848d0                   fmul      dword ptr [eax - 0x30]
004205b5  d940e4                   fld       dword ptr [eax - 0x1c]
004205b8  d9c0                     fld       st(0)
004205ba  d848e4                   fmul      dword ptr [eax - 0x1c]
004205bd  defa                     fdivp     st(2)
004205bf  d9cc                     fxch      st(4)
004205c1  dee1                     fsubrp    st(1)
004205c3  8b8424c4000000           mov       eax, dword ptr [esp + 0xc4]
004205ca  d918                     fstp      dword ptr [eax]
004205cc  def2                     fdivrp    st(2)
004205ce  8b8424cc000000           mov       eax, dword ptr [esp + 0xcc]
004205d5  d9c9                     fxch      st(1)
004205d7  d918                     fstp      dword ptr [eax]
004205d9  dec9                     fmulp     st(1)
004205db  db6c2438                 fld       xword ptr [esp + 0x38]
004205df  db6c2444                 fld       xword ptr [esp + 0x44]
004205e3  db6c2450                 fld       xword ptr [esp + 0x50]
004205e7  db6c245c                 fld       xword ptr [esp + 0x5c]
004205eb  e981010000               jmp       0x420771
004205f0  8d0d185a5200             lea       ecx, [0x525a18] ; bits=00000000, f32=0.0
004205f6  8b41e4                   mov       eax, dword ptr [ecx - 0x1c]
004205f9  8b51d0                   mov       edx, dword ptr [ecx - 0x30]
004205fc  8951e4                   mov       dword ptr [ecx - 0x1c], edx
004205ff  8941d0                   mov       dword ptr [ecx - 0x30], eax
00420602  d941e4                   fld       dword ptr [ecx - 0x1c]
00420605  d9ee                     fldz
00420607  dff1                     fcompi    st(1)
00420609  ddd8                     fstp      st(0)
0042060b  0f8a56000000             jp        0x420667
00420611  7354                     jae       0x420667
00420613  db7c2468                 fstp      xword ptr [esp + 0x68]
00420617  db7c2474                 fstp      xword ptr [esp + 0x74]
0042061b  dbbc2480000000           fstp      xword ptr [esp + 0x80]
00420622  dbbc248c000000           fstp      xword ptr [esp + 0x8c]
00420629  8d41dc                   lea       eax, [ecx - 0x24]
0042062c  50                       push      eax
0042062d  8d41ac                   lea       eax, [ecx - 0x54]
00420630  50                       push      eax
00420631  8d41ec                   lea       eax, [ecx - 0x14]
00420634  50                       push      eax
00420635  8d419c                   lea       eax, [ecx - 0x64]
00420638  50                       push      eax
00420639  8d41e4                   lea       eax, [ecx - 0x1c]
0042063c  50                       push      eax
0042063d  8d41b8                   lea       eax, [ecx - 0x48]
00420640  50                       push      eax
00420641  e8fa560100               call      0x435d40 ; _lktab_
00420646  dbac24a4000000           fld       xword ptr [esp + 0xa4]
0042064d  dbac2498000000           fld       xword ptr [esp + 0x98]
00420654  dbac248c000000           fld       xword ptr [esp + 0x8c]
0042065b  dbac2480000000           fld       xword ptr [esp + 0x80]
00420662  83c418                   add       esp, 0x18
00420665  eb12                     jmp       0x420679
00420667  89c8                     mov       eax, ecx
00420669  c740ec00000000           mov       dword ptr [eax - 0x14], 0
00420670  89c8                     mov       eax, ecx
00420672  c740dc00000000           mov       dword ptr [eax - 0x24], 0
00420679  8d0d185a5200             lea       ecx, [0x525a18] ; bits=00000000, f32=0.0
0042067f  d941d0                   fld       dword ptr [ecx - 0x30]
00420682  d9ee                     fldz
00420684  dff1                     fcompi    st(1)
00420686  0f8a64000000             jp        0x4206f0
0042068c  7362                     jae       0x4206f0
0042068e  d9c9                     fxch      st(1)
00420690  db7c2468                 fstp      xword ptr [esp + 0x68]
00420694  d9c9                     fxch      st(1)
00420696  db7c2474                 fstp      xword ptr [esp + 0x74]
0042069a  d9c9                     fxch      st(1)
0042069c  dbbc2480000000           fstp      xword ptr [esp + 0x80]
004206a3  d9c9                     fxch      st(1)
004206a5  dbbc248c000000           fstp      xword ptr [esp + 0x8c]
004206ac  d871e4                   fdiv      dword ptr [ecx - 0x1c]
004206af  d959c8                   fstp      dword ptr [ecx - 0x38]
004206b2  8d41d4                   lea       eax, [ecx - 0x2c]
004206b5  50                       push      eax
004206b6  8d41ac                   lea       eax, [ecx - 0x54]
004206b9  50                       push      eax
004206ba  8d41cc                   lea       eax, [ecx - 0x34]
004206bd  50                       push      eax
004206be  8d419c                   lea       eax, [ecx - 0x64]
004206c1  50                       push      eax
004206c2  8d41c8                   lea       eax, [ecx - 0x38]
004206c5  50                       push      eax
004206c6  8d41c0                   lea       eax, [ecx - 0x40]
004206c9  50                       push      eax
004206ca  e871560100               call      0x435d40 ; _lktab_
004206cf  dbac24a4000000           fld       xword ptr [esp + 0xa4]
004206d6  dbac2498000000           fld       xword ptr [esp + 0x98]
004206dd  dbac248c000000           fld       xword ptr [esp + 0x8c]
004206e4  dbac2480000000           fld       xword ptr [esp + 0x80]
004206eb  83c418                   add       esp, 0x18
004206ee  eb1d                     jmp       0x42070d
004206f0  ddd8                     fstp      st(0)
004206f2  89c8                     mov       eax, ecx
004206f4  c740cc0000803f           mov       dword ptr [eax - 0x34], 0x3f800000
004206fb  89c8                     mov       eax, ecx
004206fd  c740d400000000           mov       dword ptr [eax - 0x2c], 0
00420704  89c8                     mov       eax, ecx
00420706  c740e40000803f           mov       dword ptr [eax - 0x1c], 0x3f800000
0042070d  d9ca                     fxch      st(2)
0042070f  db7c245c                 fstp      xword ptr [esp + 0x5c]
00420713  d9ca                     fxch      st(2)
00420715  db7c2450                 fstp      xword ptr [esp + 0x50]
00420719  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
0042071f  d940ec                   fld       dword ptr [eax - 0x14]
00420722  d940d4                   fld       dword ptr [eax - 0x2c]
00420725  d848ec                   fmul      dword ptr [eax - 0x14]
00420728  d940e4                   fld       dword ptr [eax - 0x1c]
0042072b  d9c1                     fld       st(1)
0042072d  d870e4                   fdiv      dword ptr [eax - 0x1c]
00420730  d9e0                     fchs
00420732  8b8c24c4000000           mov       ecx, dword ptr [esp + 0xc4]
00420739  d919                     fstp      dword ptr [ecx]
0042073b  d940cc                   fld       dword ptr [eax - 0x34]
0042073e  d9c0                     fld       st(0)
00420740  d848dc                   fmul      dword ptr [eax - 0x24]
00420743  d9cb                     fxch      st(3)
00420745  d848d0                   fmul      dword ptr [eax - 0x30]
00420748  d9ca                     fxch      st(2)
0042074a  d8c8                     fmul      st(0)
0042074c  defa                     fdivp     st(2)
0042074e  d9ca                     fxch      st(2)
00420750  dee1                     fsubrp    st(1)
00420752  d9e0                     fchs
00420754  8b8424cc000000           mov       eax, dword ptr [esp + 0xcc]
0042075b  d918                     fstp      dword ptr [eax]
0042075d  dec9                     fmulp     st(1)
0042075f  d9e0                     fchs
00420761  db6c2450                 fld       xword ptr [esp + 0x50]
00420765  db6c245c                 fld       xword ptr [esp + 0x5c]
00420769  d9ca                     fxch      st(2)
0042076b  d9cc                     fxch      st(4)
0042076d  d9c9                     fxch      st(1)
0042076f  d9cb                     fxch      st(3)
00420771  d9ee                     fldz
00420773  dbea                     fucomi    st(2)
00420775  0f8a06000000             jp        0x420781
0042077b  0f8466050000             je        0x420ce7
00420781  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
00420787  8378b400                 cmp       dword ptr [eax - 0x4c], 0
0042078b  89442414                 mov       dword ptr [esp + 0x14], eax
0042078f  7e35                     jle       0x4207c6
00420791  8b442414                 mov       eax, dword ptr [esp + 0x14]
00420795  d940f8                   fld       dword ptr [eax - 8]
00420798  dff1                     fcompi    st(1)
0042079a  ddd8                     fstp      st(0)
0042079c  0f8a26000000             jp        0x4207c8
004207a2  7624                     jbe       0x4207c8
004207a4  ddd8                     fstp      st(0)
004207a6  ddd8                     fstp      st(0)
004207a8  ddd8                     fstp      st(0)
004207aa  ddd8                     fstp      st(0)
004207ac  8b442434                 mov       eax, dword ptr [esp + 0x34]
004207b0  8b08                     mov       ecx, dword ptr [eax]
004207b2  8b8424bc000000           mov       eax, dword ptr [esp + 0xbc]
004207b9  c744883800000000         mov       dword ptr [eax + ecx*4 + 0x38], 0
004207c1  e92b050000               jmp       0x420cf1
004207c6  ddd8                     fstp      st(0)
004207c8  d9ee                     fldz
004207ca  dff2                     fcompi    st(2)
004207cc  0f8a5f010000             jp        0x420931
004207d2  0f8359010000             jae       0x420931
004207d8  8d0d185a5200             lea       ecx, [0x525a18] ; bits=00000000, f32=0.0
004207de  8379b000                 cmp       dword ptr [ecx - 0x50], 0
004207e2  0f85a5000000             jne       0x42088d
004207e8  ddd8                     fstp      st(0)
004207ea  8379a800                 cmp       dword ptr [ecx - 0x58], 0
004207ee  753d                     jne       0x42082d
004207f0  89c8                     mov       eax, ecx
004207f2  d940e0                   fld       dword ptr [eax - 0x20]
004207f5  dff3                     fcompi    st(3)
004207f7  ddda                     fstp      st(2)
004207f9  d9c9                     fxch      st(1)
004207fb  0f8a79020000             jp        0x420a7a
00420801  0f8373020000             jae       0x420a7a
00420807  89c8                     mov       eax, ecx
00420809  d940fc                   fld       dword ptr [eax - 4]
0042080c  dff2                     fcompi    st(2)
0042080e  ddd9                     fstp      st(1)
00420810  0f8a6a020000             jp        0x420a80
00420816  0f8664020000             jbe       0x420a80
0042081c  c705c859520001000000     mov       dword ptr [0x5259c8], 1 ; bits=00000000, f32=0.0
00420826  dec1                     faddp     st(1)
00420828  e977020000               jmp       0x420aa4
0042082d  ddd9                     fstp      st(1)
0042082f  89c8                     mov       eax, ecx
00420831  d940e0                   fld       dword ptr [eax - 0x20]
00420834  dff2                     fcompi    st(2)
00420836  ddd9                     fstp      st(1)
00420838  0f8a46020000             jp        0x420a84
0042083e  0f8340020000             jae       0x420a84
00420844  89c8                     mov       eax, ecx
00420846  d940f4                   fld       dword ptr [eax - 0xc]
00420849  d9ee                     fldz
0042084b  dff1                     fcompi    st(1)
0042084d  ddd8                     fstp      st(0)
0042084f  0f8a33020000             jp        0x420a88
00420855  0f832d020000             jae       0x420a88
0042085b  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
00420861  d940f4                   fld       dword ptr [eax - 0xc]
00420864  d940fc                   fld       dword ptr [eax - 4]
00420867  dff1                     fcompi    st(1)
00420869  ddd8                     fstp      st(0)
0042086b  89442410                 mov       dword ptr [esp + 0x10], eax
0042086f  0f8a17020000             jp        0x420a8c
00420875  0f8611020000             jbe       0x420a8c
0042087b  8b442410                 mov       eax, dword ptr [esp + 0x10]
0042087f  c740b001000000           mov       dword ptr [eax - 0x50], 1
00420886  dec1                     faddp     st(1)
00420888  e917020000               jmp       0x420aa4
0042088d  89c8                     mov       eax, ecx
0042088f  8378a800                 cmp       dword ptr [eax - 0x58], 0
00420893  754c                     jne       0x4208e1
00420895  8b8424b8000000           mov       eax, dword ptr [esp + 0xb8]
0042089c  89ca                     mov       edx, ecx
0042089e  d942e0                   fld       dword ptr [edx - 0x20]
004208a1  d820                     fsub      dword ptr [eax]
004208a3  dff4                     fcompi    st(4)
004208a5  dddb                     fstp      st(3)
004208a7  d9c9                     fxch      st(1)
004208a9  d9ca                     fxch      st(2)
004208ab  0f8a02000000             jp        0x4208b3
004208b1  7312                     jae       0x4208c5
004208b3  dff2                     fcompi    st(2)
004208b5  ddd9                     fstp      st(1)
004208b7  0f8a1d000000             jp        0x4208da
004208bd  0f8717000000             ja        0x4208da
004208c3  eb04                     jmp       0x4208c9
004208c5  ddd8                     fstp      st(0)
004208c7  ddd9                     fstp      st(1)
004208c9  ddd8                     fstp      st(0)
004208cb  c705c859520000000000     mov       dword ptr [0x5259c8], 0 ; bits=00000000, f32=0.0
004208d5  e9ca010000               jmp       0x420aa4
004208da  dec1                     faddp     st(1)
004208dc  e9c3010000               jmp       0x420aa4
004208e1  ddd8                     fstp      st(0)
004208e3  ddd9                     fstp      st(1)
004208e5  8b8424b8000000           mov       eax, dword ptr [esp + 0xb8]
004208ec  89ca                     mov       edx, ecx
004208ee  d942e0                   fld       dword ptr [edx - 0x20]
004208f1  d820                     fsub      dword ptr [eax]
004208f3  dff2                     fcompi    st(2)
004208f5  ddd9                     fstp      st(1)
004208f7  0f8a02000000             jp        0x4208ff
004208fd  731a                     jae       0x420919
004208ff  d9c0                     fld       st(0)
00420901  d8c0                     fadd      st(0)
00420903  89c8                     mov       eax, ecx
00420905  d840fc                   fadd      dword ptr [eax - 4]
00420908  89c8                     mov       eax, ecx
0042090a  d940f4                   fld       dword ptr [eax - 0xc]
0042090d  dff1                     fcompi    st(1)
0042090f  ddd8                     fstp      st(0)
00420911  0f8a13000000             jp        0x42092a
00420917  7611                     jbe       0x42092a
00420919  ddd8                     fstp      st(0)
0042091b  c705c859520000000000     mov       dword ptr [0x5259c8], 0 ; bits=00000000, f32=0.0
00420925  e97a010000               jmp       0x420aa4
0042092a  dec1                     faddp     st(1)
0042092c  e973010000               jmp       0x420aa4
00420931  8d0d185a5200             lea       ecx, [0x525a18] ; bits=00000000, f32=0.0
00420937  8379b000                 cmp       dword ptr [ecx - 0x50], 0
0042093b  0f85a3000000             jne       0x4209e4
00420941  ddd8                     fstp      st(0)
00420943  8379a800                 cmp       dword ptr [ecx - 0x58], 0
00420947  753b                     jne       0x420984
00420949  89c8                     mov       eax, ecx
0042094b  d940e0                   fld       dword ptr [eax - 0x20]
0042094e  dff2                     fcompi    st(2)
00420950  ddd9                     fstp      st(1)
00420952  0f8a38010000             jp        0x420a90
00420958  0f8332010000             jae       0x420a90
0042095e  89c8                     mov       eax, ecx
00420960  d940fc                   fld       dword ptr [eax - 4]
00420963  dff2                     fcompi    st(2)
00420965  ddd9                     fstp      st(1)
00420967  0f8a29010000             jp        0x420a96
0042096d  0f8623010000             jbe       0x420a96
00420973  c705c859520001000000     mov       dword ptr [0x5259c8], 1 ; bits=00000000, f32=0.0
0042097d  dec1                     faddp     st(1)
0042097f  e920010000               jmp       0x420aa4
00420984  ddda                     fstp      st(2)
00420986  89c8                     mov       eax, ecx
00420988  d940e0                   fld       dword ptr [eax - 0x20]
0042098b  dff1                     fcompi    st(1)
0042098d  ddd8                     fstp      st(0)
0042098f  0f8a05010000             jp        0x420a9a
00420995  0f83ff000000             jae       0x420a9a
0042099b  89c8                     mov       eax, ecx
0042099d  d940f0                   fld       dword ptr [eax - 0x10]
004209a0  d9ee                     fldz
004209a2  dff1                     fcompi    st(1)
004209a4  ddd8                     fstp      st(0)
004209a6  0f8af2000000             jp        0x420a9e
004209ac  0f83ec000000             jae       0x420a9e
004209b2  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
004209b8  d940f0                   fld       dword ptr [eax - 0x10]
004209bb  d940fc                   fld       dword ptr [eax - 4]
004209be  dff1                     fcompi    st(1)
004209c0  ddd8                     fstp      st(0)
004209c2  8944240c                 mov       dword ptr [esp + 0xc], eax
004209c6  0f8ad6000000             jp        0x420aa2
004209cc  0f86d0000000             jbe       0x420aa2
004209d2  8b44240c                 mov       eax, dword ptr [esp + 0xc]
004209d6  c740b001000000           mov       dword ptr [eax - 0x50], 1
004209dd  dec1                     faddp     st(1)
004209df  e9c0000000               jmp       0x420aa4
004209e4  89c8                     mov       eax, ecx
004209e6  8378a800                 cmp       dword ptr [eax - 0x58], 0
004209ea  7544                     jne       0x420a30
004209ec  8b8424b8000000           mov       eax, dword ptr [esp + 0xb8]
004209f3  89ca                     mov       edx, ecx
004209f5  d942e0                   fld       dword ptr [edx - 0x20]
004209f8  d820                     fsub      dword ptr [eax]
004209fa  dff3                     fcompi    st(3)
004209fc  ddda                     fstp      st(2)
004209fe  d9c9                     fxch      st(1)
00420a00  0f8a02000000             jp        0x420a08
00420a06  7312                     jae       0x420a1a
00420a08  dff2                     fcompi    st(2)
00420a0a  ddd9                     fstp      st(1)
00420a0c  0f8a1a000000             jp        0x420a2c
00420a12  0f8714000000             ja        0x420a2c
00420a18  eb04                     jmp       0x420a1e
00420a1a  ddd8                     fstp      st(0)
00420a1c  ddd9                     fstp      st(1)
00420a1e  ddd8                     fstp      st(0)
00420a20  c705c859520000000000     mov       dword ptr [0x5259c8], 0 ; bits=00000000, f32=0.0
00420a2a  eb78                     jmp       0x420aa4
00420a2c  dec1                     faddp     st(1)
00420a2e  eb74                     jmp       0x420aa4
00420a30  ddd8                     fstp      st(0)
00420a32  ddda                     fstp      st(2)
00420a34  8b8424b8000000           mov       eax, dword ptr [esp + 0xb8]
00420a3b  89ca                     mov       edx, ecx
00420a3d  d942e0                   fld       dword ptr [edx - 0x20]
00420a40  d820                     fsub      dword ptr [eax]
00420a42  dff1                     fcompi    st(1)
00420a44  ddd8                     fstp      st(0)
00420a46  0f8a02000000             jp        0x420a4e
00420a4c  731a                     jae       0x420a68
00420a4e  d9c0                     fld       st(0)
00420a50  d8c0                     fadd      st(0)
00420a52  89c8                     mov       eax, ecx
00420a54  d868fc                   fsubr     dword ptr [eax - 4]
00420a57  89c8                     mov       eax, ecx
00420a59  d940f0                   fld       dword ptr [eax - 0x10]
00420a5c  dff1                     fcompi    st(1)
00420a5e  ddd8                     fstp      st(0)
00420a60  0f8a10000000             jp        0x420a76
00420a66  760e                     jbe       0x420a76
00420a68  ddd8                     fstp      st(0)
00420a6a  c705c859520000000000     mov       dword ptr [0x5259c8], 0 ; bits=00000000, f32=0.0
00420a74  eb2e                     jmp       0x420aa4
00420a76  dec1                     faddp     st(1)
00420a78  eb2a                     jmp       0x420aa4
00420a7a  ddd8                     fstp      st(0)
00420a7c  ddd8                     fstp      st(0)
00420a7e  eb24                     jmp       0x420aa4
00420a80  ddd8                     fstp      st(0)
00420a82  eb20                     jmp       0x420aa4
00420a84  ddd8                     fstp      st(0)
00420a86  eb1c                     jmp       0x420aa4
00420a88  ddd8                     fstp      st(0)
00420a8a  eb18                     jmp       0x420aa4
00420a8c  ddd8                     fstp      st(0)
00420a8e  eb14                     jmp       0x420aa4
00420a90  ddd8                     fstp      st(0)
00420a92  ddd8                     fstp      st(0)
00420a94  eb0e                     jmp       0x420aa4
00420a96  ddd8                     fstp      st(0)
00420a98  eb0a                     jmp       0x420aa4
00420a9a  ddd8                     fstp      st(0)
00420a9c  eb06                     jmp       0x420aa4
00420a9e  ddd8                     fstp      st(0)
00420aa0  eb02                     jmp       0x420aa4
00420aa2  ddd8                     fstp      st(0)
00420aa4  8b442434                 mov       eax, dword ptr [esp + 0x34]
00420aa8  8b08                     mov       ecx, dword ptr [eax]
00420aaa  8b8424bc000000           mov       eax, dword ptr [esp + 0xbc]
00420ab1  8b15c8595200             mov       edx, dword ptr [0x5259c8] ; bits=00000000, f32=0.0
00420ab7  89548838                 mov       dword ptr [eax + ecx*4 + 0x38], edx
00420abb  e931020000               jmp       0x420cf1
00420ac0  ddda                     fstp      st(2)
00420ac2  d9c3                     fld       st(3)
00420ac4  d8e3                     fsub      st(3)
00420ac6  89d8                     mov       eax, ebx
00420ac8  d958e4                   fstp      dword ptr [eax - 0x1c]
00420acb  d9ca                     fxch      st(2)
00420acd  dec3                     faddp     st(3)
00420acf  89d8                     mov       eax, ebx
00420ad1  d9ca                     fxch      st(2)
00420ad3  d84890                   fmul      dword ptr [eax - 0x70]
00420ad6  dee2                     fsubrp    st(2)
00420ad8  89d8                     mov       eax, ebx
00420ada  d9c9                     fxch      st(1)
00420adc  d958d0                   fstp      dword ptr [eax - 0x30]
00420adf  89d8                     mov       eax, ebx
00420ae1  d940d0                   fld       dword ptr [eax - 0x30]
00420ae4  d9ee                     fldz
00420ae6  d9c9                     fxch      st(1)
00420ae8  dff1                     fcompi    st(1)
00420aea  0f8a06000000             jp        0x420af6
00420af0  0f8675010000             jbe       0x420c6b
00420af6  89d8                     mov       eax, ebx
00420af8  d940e4                   fld       dword ptr [eax - 0x1c]
00420afb  dfe9                     fucompi   st(1)
00420afd  0f8a06000000             jp        0x420b09
00420b03  0f8462010000             je        0x420c6b
00420b09  dbbc2480000000           fstp      xword ptr [esp + 0x80]
00420b10  dbbc248c000000           fstp      xword ptr [esp + 0x8c]
00420b17  89d8                     mov       eax, ebx
00420b19  8d40d8                   lea       eax, [eax - 0x28]
00420b1c  50                       push      eax
00420b1d  89d8                     mov       eax, ebx
00420b1f  8d40ac                   lea       eax, [eax - 0x54]
00420b22  50                       push      eax
00420b23  89d8                     mov       eax, ebx
00420b25  8d40e8                   lea       eax, [eax - 0x18]
00420b28  50                       push      eax
00420b29  89d8                     mov       eax, ebx
00420b2b  8d409c                   lea       eax, [eax - 0x64]
00420b2e  50                       push      eax
00420b2f  89d8                     mov       eax, ebx
00420b31  8d40d0                   lea       eax, [eax - 0x30]
00420b34  50                       push      eax
00420b35  89d8                     mov       eax, ebx
00420b37  8d40bc                   lea       eax, [eax - 0x44]
00420b3a  50                       push      eax
00420b3b  e800520100               call      0x435d40 ; _lktab_
00420b40  83c418                   add       esp, 0x18
00420b43  89d8                     mov       eax, ebx
00420b45  89d9                     mov       ecx, ebx
00420b47  d941e8                   fld       dword ptr [ecx - 0x18]
00420b4a  d848e8                   fmul      dword ptr [eax - 0x18]
00420b4d  89d8                     mov       eax, ebx
00420b4f  d958e8                   fstp      dword ptr [eax - 0x18]
00420b52  89d8                     mov       eax, ebx
00420b54  89d9                     mov       ecx, ebx
00420b56  d941e8                   fld       dword ptr [ecx - 0x18]
00420b59  d840e8                   fadd      dword ptr [eax - 0x18]
00420b5c  89d8                     mov       eax, ebx
00420b5e  d848d8                   fmul      dword ptr [eax - 0x28]
00420b61  89d8                     mov       eax, ebx
00420b63  d958d8                   fstp      dword ptr [eax - 0x28]
00420b66  89d8                     mov       eax, ebx
00420b68  dbac248c000000           fld       xword ptr [esp + 0x8c]
00420b6f  d878e4                   fdivr     dword ptr [eax - 0x1c]
00420b72  d9c0                     fld       st(0)
00420b74  d9e1                     fabs
00420b76  89d8                     mov       eax, ebx
00420b78  d94094                   fld       dword ptr [eax - 0x6c]
00420b7b  dff1                     fcompi    st(1)
00420b7d  dbac248c000000           fld       xword ptr [esp + 0x8c]
00420b84  dbac2480000000           fld       xword ptr [esp + 0x80]
00420b8b  d9c9                     fxch      st(1)
00420b8d  d9ca                     fxch      st(2)
00420b8f  0f8a49000000             jp        0x420bde
00420b95  7247                     jb        0x420bde
00420b97  ddd8                     fstp      st(0)
00420b99  ddd8                     fstp      st(0)
00420b9b  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
00420ba1  d94098                   fld       dword ptr [eax - 0x68]
00420ba4  d940e8                   fld       dword ptr [eax - 0x18]
00420ba7  d9c0                     fld       st(0)
00420ba9  d84898                   fmul      dword ptr [eax - 0x68]
00420bac  d8cc                     fmul      st(4)
00420bae  d940d8                   fld       dword ptr [eax - 0x28]
00420bb1  d84890                   fmul      dword ptr [eax - 0x70]
00420bb4  decd                     fmulp     st(5)
00420bb6  d9c9                     fxch      st(1)
00420bb8  def3                     fdivrp    st(3)
00420bba  d9c2                     fld       st(2)
00420bbc  d8c4                     fadd      st(4)
00420bbe  d84898                   fmul      dword ptr [eax - 0x68]
00420bc1  8b8424c4000000           mov       eax, dword ptr [esp + 0xc4]
00420bc8  d918                     fstp      dword ptr [eax]
00420bca  d9cb                     fxch      st(3)
00420bcc  dee2                     fsubrp    st(2)
00420bce  dec9                     fmulp     st(1)
00420bd0  8b8424cc000000           mov       eax, dword ptr [esp + 0xcc]
00420bd7  d918                     fstp      dword ptr [eax]
00420bd9  e913010000               jmp       0x420cf1
00420bde  dddb                     fstp      st(3)
00420be0  d9ca                     fxch      st(2)
00420be2  d9fa                     fsqrt
00420be4  d99c2498000000           fstp      dword ptr [esp + 0x98]
00420beb  d9842498000000           fld       dword ptr [esp + 0x98]
00420bf2  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
00420bf8  d940e8                   fld       dword ptr [eax - 0x18]
00420bfb  d88c2498000000           fmul      dword ptr [esp + 0x98]
00420c02  d940e4                   fld       dword ptr [eax - 0x1c]
00420c05  dff4                     fcompi    st(4)
00420c07  dddb                     fstp      st(3)
00420c09  d9c9                     fxch      st(1)
00420c0b  0f8a08000000             jp        0x420c19
00420c11  7306                     jae       0x420c19
00420c13  d9ca                     fxch      st(2)
00420c15  d9e0                     fchs
00420c17  d9ca                     fxch      st(2)
00420c19  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
00420c1f  d940d8                   fld       dword ptr [eax - 0x28]
00420c22  d84890                   fmul      dword ptr [eax - 0x70]
00420c25  d8ca                     fmul      st(2)
00420c27  d940e4                   fld       dword ptr [eax - 0x1c]
00420c2a  d9ee                     fldz
00420c2c  dff1                     fcompi    st(1)
00420c2e  ddd8                     fstp      st(0)
00420c30  0f8a04000000             jp        0x420c3a
00420c36  7602                     jbe       0x420c3a
00420c38  d9e0                     fchs
00420c3a  8d05185a5200             lea       eax, [0x525a18] ; bits=00000000, f32=0.0
00420c40  d940e8                   fld       dword ptr [eax - 0x18]
00420c43  d84890                   fmul      dword ptr [eax - 0x70]
00420c46  d9cb                     fxch      st(3)
00420c48  deca                     fmulp     st(2)
00420c4a  d9ca                     fxch      st(2)
00420c4c  def1                     fdivrp    st(1)
00420c4e  d9c0                     fld       st(0)
00420c50  d8c2                     fadd      st(2)
00420c52  8b8424c4000000           mov       eax, dword ptr [esp + 0xc4]
00420c59  d918                     fstp      dword ptr [eax]
00420c5b  dee9                     fsubp     st(1)
00420c5d  8b8424cc000000           mov       eax, dword ptr [esp + 0xcc]
00420c64  d918                     fstp      dword ptr [eax]
00420c66  e986000000               jmp       0x420cf1
00420c6b  ddd8                     fstp      st(0)
00420c6d  ddd8                     fstp      st(0)
00420c6f  8b8424cc000000           mov       eax, dword ptr [esp + 0xcc]
00420c76  c70000000000             mov       dword ptr [eax], 0
00420c7c  8b8424c4000000           mov       eax, dword ptr [esp + 0xc4]
00420c83  c70000000000             mov       dword ptr [eax], 0
00420c89  8b4c2424                 mov       ecx, dword ptr [esp + 0x24]
00420c8d  8b8424b0000000           mov       eax, dword ptr [esp + 0xb0]
00420c94  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
00420c98  8b9424c0000000           mov       edx, dword ptr [esp + 0xc0]
00420c9f  8902                     mov       dword ptr [edx], eax
00420ca1  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
00420ca5  39c1                     cmp       ecx, eax
00420ca7  741f                     je        0x420cc8
00420ca9  8b8424d0000000           mov       eax, dword ptr [esp + 0xd0]
00420cb0  c7000000803f             mov       dword ptr [eax], 0x3f800000
00420cb6  8b8424c8000000           mov       eax, dword ptr [esp + 0xc8]
00420cbd  c70000000000             mov       dword ptr [eax], 0
00420cc3  e9bc000000               jmp       0x420d84
00420cc8  8b8424c8000000           mov       eax, dword ptr [esp + 0xc8]
00420ccf  c7000000803f             mov       dword ptr [eax], 0x3f800000
00420cd5  8b8424d0000000           mov       eax, dword ptr [esp + 0xd0]
00420cdc  c70000000000             mov       dword ptr [eax], 0
00420ce2  e99d000000               jmp       0x420d84
00420ce7  ddd8                     fstp      st(0)
00420ce9  ddd8                     fstp      st(0)
00420ceb  ddd8                     fstp      st(0)
00420ced  ddd8                     fstp      st(0)
00420cef  ddd8                     fstp      st(0)
00420cf1  837c242000               cmp       dword ptr [esp + 0x20], 0
00420cf6  7f1c                     jg        0x420d14
00420cf8  d9e0                     fchs
00420cfa  8b8424c4000000           mov       eax, dword ptr [esp + 0xc4]
00420d01  d900                     fld       dword ptr [eax]
00420d03  d9e0                     fchs
00420d05  d918                     fstp      dword ptr [eax]
00420d07  8b8424cc000000           mov       eax, dword ptr [esp + 0xcc]
00420d0e  d900                     fld       dword ptr [eax]
00420d10  d9e0                     fchs
00420d12  d918                     fstp      dword ptr [eax]
00420d14  8b4c2424                 mov       ecx, dword ptr [esp + 0x24]
00420d18  8b8424b0000000           mov       eax, dword ptr [esp + 0xb0]
00420d1f  d86c88fc                 fsubr     dword ptr [eax + ecx*4 - 4]
00420d23  8b8424c0000000           mov       eax, dword ptr [esp + 0xc0]
00420d2a  d918                     fstp      dword ptr [eax]
00420d2c  8b8424c4000000           mov       eax, dword ptr [esp + 0xc4]
00420d33  d900                     fld       dword ptr [eax]
00420d35  d9e0                     fchs
00420d37  d918                     fstp      dword ptr [eax]
00420d39  8b8424cc000000           mov       eax, dword ptr [esp + 0xcc]
00420d40  d900                     fld       dword ptr [eax]
00420d42  d9e0                     fchs
00420d44  d918                     fstp      dword ptr [eax]
00420d46  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
00420d4a  39c1                     cmp       ecx, eax
00420d4c  741c                     je        0x420d6a
00420d4e  8b8424d0000000           mov       eax, dword ptr [esp + 0xd0]
00420d55  c7000000803f             mov       dword ptr [eax], 0x3f800000
00420d5b  8b8424c8000000           mov       eax, dword ptr [esp + 0xc8]
00420d62  c70000000000             mov       dword ptr [eax], 0
00420d68  eb1a                     jmp       0x420d84
00420d6a  8b8424d0000000           mov       eax, dword ptr [esp + 0xd0]
00420d71  c70000000000             mov       dword ptr [eax], 0
00420d77  8b8424c8000000           mov       eax, dword ptr [esp + 0xc8]
00420d7e  c7000000803f             mov       dword ptr [eax], 0x3f800000
00420d84  b800000000               mov       eax, 0
00420d89  5f                       pop       edi
00420d8a  5e                       pop       esi
00420d8b  5b                       pop       ebx
00420d8c  81c490000000             add       esp, 0x90
00420d92  c3                       ret
00420d93  8d9b00000000             lea       ebx, [ebx]
00420d99  8da42400000000           lea       esp, [esp]
