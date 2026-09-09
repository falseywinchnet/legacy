; _rqvstw_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x2dab0
0042dab0  55                       push      ebp
0042dab1  8bec                     mov       ebp, esp
0042dab3  b80c000000               mov       eax, 0xc
0042dab8  e843b50b00               call      0x4e9000 ; __alloca_probe
0042dabd  53                       push      ebx
0042dabe  56                       push      esi
0042dabf  8b5d08                   mov       ebx, dword ptr [ebp + 8]
0042dac2  d905acf3f200             fld       dword ptr [0xf2f3ac]
0042dac8  d82d0cb6e900             fsubr     dword ptr [0xe9b60c]
0042dace  d91de4f3f200             fstp      dword ptr [0xf2f3e4]
0042dad4  8b0500b6e900             mov       eax, dword ptr [0xe9b600] ; _rqvtw_
0042dada  8b0c8564caec00           mov       ecx, dword ptr [eax*4 + 0xecca64]
0042dae1  8d35a8ba5600             lea       esi, [0x56baa8] ; bits=b0040000, f32=1.6815581571897805e-42
0042dae7  894e6c                   mov       dword ptr [esi + 0x6c], ecx
0042daea  8b0504b6e900             mov       eax, dword ptr [0xe9b604]
0042daf0  d9048564caec00           fld       dword ptr [eax*4 + 0xecca64]
0042daf7  db7df4                   fstp      xword ptr [ebp - 0xc]
0042dafa  d903                     fld       dword ptr [ebx]
0042dafc  d9052cbbf400             fld       dword ptr [0xf4bb2c]
0042db02  d803                     fadd      dword ptr [ebx]
0042db04  d91da4f1f200             fstp      dword ptr [0xf2f1a4]
0042db0a  d91544b6e900             fst       dword ptr [0xe9b644]
0042db10  d91da4f3f200             fstp      dword ptr [0xf2f3a4]
0042db16  6a08                     push      8
0042db18  681cb6e900               push      0xe9b61c
0042db1d  8d466c                   lea       eax, [esi + 0x6c]
0042db20  50                       push      eax
0042db21  6830b6e900               push      0xe9b630 ; _rqvtc_
0042db26  8d46f4                   lea       eax, [esi - 0xc]
0042db29  50                       push      eax
0042db2a  6814b6e900               push      0xe9b614
0042db2f  e86cc2ffff               call      0x429da0 ; _fcd123_
0042db34  d91de4f2f200             fstp      dword ptr [0xf2f2e4]
0042db3a  83c418                   add       esp, 0x18
0042db3d  8b05bcf3f200             mov       eax, dword ptr [0xf2f3bc]
0042db43  890508f3f200             mov       dword ptr [0xf2f308], eax
0042db49  6808f3f200               push      0xf2f308
0042db4e  6818b6e900               push      0xe9b618
0042db53  68e4f2f200               push      0xf2f2e4
0042db58  e873b6ffff               call      0x4291d0 ; _degcon_
0042db5d  d91de0f2f200             fstp      dword ptr [0xf2f2e0] ; _cdcom_
0042db63  83c40c                   add       esp, 0xc
0042db66  d90548bbf400             fld       dword ptr [0xf4bb48]
0042db6c  d9468c                   fld       dword ptr [esi - 0x74]
0042db6f  d9c9                     fxch      st(1)
0042db71  dae9                     fucompp
0042db73  db6df4                   fld       xword ptr [ebp - 0xc]
0042db76  dfe0                     fnstsw    ax
0042db78  9e                       sahf
0042db79  0f8a50000000             jp        0x42dbcf
0042db7f  754e                     jne       0x42dbcf
0042db81  d90550bbf400             fld       dword ptr [0xf4bb50]
0042db87  d9c0                     fld       st(0)
0042db89  d82de4f3f200             fsubr     dword ptr [0xf2f3e4]
0042db8f  d90544bbf400             fld       dword ptr [0xf4bb44]
0042db95  d9c0                     fld       st(0)
0042db97  d82de8f2f200             fsubr     dword ptr [0xf2f2e8]
0042db9d  d8ca                     fmul      st(2)
0042db9f  d9cc                     fxch      st(4)
0042dba1  dee3                     fsubrp    st(3)
0042dba3  d9cb                     fxch      st(3)
0042dba5  d8f2                     fdiv      st(2)
0042dba7  dec3                     faddp     st(3)
0042dba9  d9ca                     fxch      st(2)
0042dbab  d91de0f2f200             fstp      dword ptr [0xf2f2e0] ; _cdcom_
0042dbb1  d90540bbf400             fld       dword ptr [0xf4bb40] ; _typtrn_
0042dbb7  d9c0                     fld       st(0)
0042dbb9  d82dbcb6e900             fsubr     dword ptr [0xe9b6bc]
0042dbbf  decb                     fmulp     st(3)
0042dbc1  d9ca                     fxch      st(2)
0042dbc3  def1                     fdivrp    st(1)
0042dbc5  dec1                     faddp     st(1)
0042dbc7  d91d08f3f200             fstp      dword ptr [0xf2f308]
0042dbcd  eb02                     jmp       0x42dbd1
0042dbcf  ddd8                     fstp      st(0)
0042dbd1  d905e0f2f200             fld       dword ptr [0xf2f2e0] ; _cdcom_
0042dbd7  d80de0f2f200             fmul      dword ptr [0xf2f2e0] ; _cdcom_
0042dbdd  d83d30ba5600             fdivr     dword ptr [0x56ba30] ; bits=0000803f, f32=1.0
0042dbe3  d82530ba5600             fsub      dword ptr [0x56ba30] ; bits=0000803f, f32=1.0
0042dbe9  d90508f3f200             fld       dword ptr [0xf2f308]
0042dbef  d83b                     fdivr     dword ptr [ebx]
0042dbf1  d8c8                     fmul      st(0)
0042dbf3  dec9                     fmulp     st(1)
0042dbf5  d83534bcf400             fdiv      dword ptr [0xf4bc34]
0042dbfb  8d35a8ba5600             lea       esi, [0x56baa8] ; bits=b0040000, f32=1.6815581571897805e-42
0042dc01  d95e68                   fstp      dword ptr [esi + 0x68]
0042dc04  c7050cf3f20000000000     mov       dword ptr [0xf2f30c], 0
0042dc0e  8d4664                   lea       eax, [esi + 0x64]
0042dc11  50                       push      eax
0042dc12  6848b6e900               push      0xe9b648
0042dc17  8d465c                   lea       eax, [esi + 0x5c]
0042dc1a  50                       push      eax
0042dc1b  680cb6e900               push      0xe9b60c
0042dc20  68a4f3f200               push      0xf2f3a4
0042dc25  8d4668                   lea       eax, [esi + 0x68]
0042dc28  50                       push      eax
0042dc29  6804b6e900               push      0xe9b604
0042dc2e  6800b6e900               push      0xe9b600 ; _rqvtw_
0042dc33  6814b6e900               push      0xe9b614
0042dc38  e8b38dffff               call      0x4269f0 ; _sfpsbe_
0042dc3d  83c424                   add       esp, 0x24
0042dc40  d9054cb6e900             fld       dword ptr [0xe9b64c]
0042dc46  d82d48b6e900             fsubr     dword ptr [0xe9b648]
0042dc4c  d91d50b6e900             fstp      dword ptr [0xe9b650]
0042dc52  6878b6e900               push      0xe9b678
0042dc57  6874b6e900               push      0xe9b674
0042dc5c  6870b6e900               push      0xe9b670
0042dc61  686cb6e900               push      0xe9b66c
0042dc66  6868b6e900               push      0xe9b668
0042dc6b  6864b6e900               push      0xe9b664
0042dc70  6860b6e900               push      0xe9b660
0042dc75  6858b6e900               push      0xe9b658
0042dc7a  6854b6e900               push      0xe9b654
0042dc7f  685cb6e900               push      0xe9b65c
0042dc84  6850b6e900               push      0xe9b650
0042dc89  6840b6e900               push      0xe9b640 ; _xs2com_
0042dc8e  e80dd90100               call      0x44b5a0 ; _xlktal_
0042dc93  83c430                   add       esp, 0x30
0042dc96  837e6401                 cmp       dword ptr [esi + 0x64], 1
0042dc9a  750c                     jne       0x42dca8
0042dc9c  c70510b6e90000000000     mov       dword ptr [0xe9b610], 0
0042dca6  eb7c                     jmp       0x42dd24
0042dca8  6850b6e900               push      0xe9b650
0042dcad  68a4f3f200               push      0xf2f3a4
0042dcb2  6840b6e900               push      0xe9b640 ; _xs2com_
0042dcb7  6814b6e900               push      0xe9b614
0042dcbc  e86faeffff               call      0x428b30 ; _fndcde_
0042dcc1  83c410                   add       esp, 0x10
0042dcc4  d9054cb6e900             fld       dword ptr [0xe9b64c]
0042dcca  d80550b6e900             fadd      dword ptr [0xe9b650]
0042dcd0  d91d48b6e900             fstp      dword ptr [0xe9b648]
0042dcd6  6878b6e900               push      0xe9b678
0042dcdb  6874b6e900               push      0xe9b674
0042dce0  6870b6e900               push      0xe9b670
0042dce5  686cb6e900               push      0xe9b66c
0042dcea  6868b6e900               push      0xe9b668
0042dcef  6864b6e900               push      0xe9b664
0042dcf4  6860b6e900               push      0xe9b660
0042dcf9  6858b6e900               push      0xe9b658
0042dcfe  6854b6e900               push      0xe9b654
0042dd03  685cb6e900               push      0xe9b65c
0042dd08  6850b6e900               push      0xe9b650
0042dd0d  6840b6e900               push      0xe9b640 ; _xs2com_
0042dd12  e889d80100               call      0x44b5a0 ; _xlktal_
0042dd17  83c430                   add       esp, 0x30
0042dd1a  c70510b6e90000000000     mov       dword ptr [0xe9b610], 0
0042dd24  833d10b6e90000           cmp       dword ptr [0xe9b610], 0
0042dd2b  753a                     jne       0x42dd67
0042dd2d  8d1da8ba5600             lea       ebx, [0x56baa8] ; bits=b0040000, f32=1.6815581571897805e-42
0042dd33  8d4360                   lea       eax, [ebx + 0x60]
0042dd36  50                       push      eax
0042dd37  8d4358                   lea       eax, [ebx + 0x58]
0042dd3a  50                       push      eax
0042dd3b  682cbbf400               push      0xf4bb2c
0042dd40  680cf3f200               push      0xf2f30c
0042dd45  68e0f2f200               push      0xf2f2e0 ; _cdcom_
0042dd4a  6814b6e900               push      0xe9b614
0042dd4f  e8fcdfffff               call      0x42bd50 ; _appro_
0042dd54  83c418                   add       esp, 0x18
0042dd57  837b6001                 cmp       dword ptr [ebx + 0x60], 1
0042dd5b  750a                     jne       0x42dd67
0042dd5d  c70510b6e900feffffff     mov       dword ptr [0xe9b610], 0xfffffffe
0042dd67  d9051cb6e900             fld       dword ptr [0xe9b61c]
0042dd6d  d82da8f1f200             fsubr     dword ptr [0xf2f1a8]
0042dd73  5e                       pop       esi
0042dd74  5b                       pop       ebx
0042dd75  8be5                     mov       esp, ebp
0042dd77  5d                       pop       ebp
0042dd78  c3                       ret
0042dd79  8da42400000000           lea       esp, [esp]
