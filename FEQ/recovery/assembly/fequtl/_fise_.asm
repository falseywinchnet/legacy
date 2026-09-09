; _fise_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x110b0
004110b0  55                       push      ebp
004110b1  8bec                     mov       ebp, esp
004110b3  53                       push      ebx
004110b4  56                       push      esi
004110b5  8b7508                   mov       esi, dword ptr [ebp + 8]
004110b8  8b06                     mov       eax, dword ptr [esi]
004110ba  8d1d10995500             lea       ebx, [0x559910] ; bits=00000000, f32=0.0
004110c0  8943bc                   mov       dword ptr [ebx - 0x44], eax
004110c3  8b05d0bbf400             mov       eax, dword ptr [0xf4bbd0]
004110c9  83bc8370ffffff01         cmp       dword ptr [ebx + eax*4 - 0x90], 1
004110d1  755d                     jne       0x411130
004110d3  8d43a0                   lea       eax, [ebx - 0x60]
004110d6  50                       push      eax
004110d7  8d4398                   lea       eax, [ebx - 0x68]
004110da  50                       push      eax
004110db  8d43a4                   lea       eax, [ebx - 0x5c]
004110de  50                       push      eax
004110df  8d43b0                   lea       eax, [ebx - 0x50]
004110e2  50                       push      eax
004110e3  8d43a8                   lea       eax, [ebx - 0x58]
004110e6  50                       push      eax
004110e7  8d43b8                   lea       eax, [ebx - 0x48]
004110ea  50                       push      eax
004110eb  8d4394                   lea       eax, [ebx - 0x6c]
004110ee  50                       push      eax
004110ef  8d43bc                   lea       eax, [ebx - 0x44]
004110f2  50                       push      eax
004110f3  68c0bbf400               push      0xf4bbc0 ; _isecom_
004110f8  e833750300               call      0x448630 ; _xlkt20_
004110fd  83c424                   add       esp, 0x24
00411100  d905c4bbf400             fld       dword ptr [0xf4bbc4]
00411106  d80dc4bbf400             fmul      dword ptr [0xf4bbc4]
0041110c  d84b80                   fmul      dword ptr [ebx - 0x80]
0041110f  d94394                   fld       dword ptr [ebx - 0x6c]
00411112  d84b94                   fmul      dword ptr [ebx - 0x6c]
00411115  d80dccbbf400             fmul      dword ptr [0xf4bbcc]
0041111b  def9                     fdivp     st(1)
0041111d  d806                     fadd      dword ptr [esi]
0041111f  d835c8bbf400             fdiv      dword ptr [0xf4bbc8]
00411125  d82594985500             fsub      dword ptr [0x559894] ; bits=0000803f, f32=1.0
0041112b  e98d000000               jmp       0x4111bd
00411130  89d8                     mov       eax, ebx
00411132  8d40b4                   lea       eax, [eax - 0x4c]
00411135  50                       push      eax
00411136  89d8                     mov       eax, ebx
00411138  8d409c                   lea       eax, [eax - 0x64]
0041113b  50                       push      eax
0041113c  89d8                     mov       eax, ebx
0041113e  8d4090                   lea       eax, [eax - 0x70]
00411141  50                       push      eax
00411142  89d8                     mov       eax, ebx
00411144  8d40a0                   lea       eax, [eax - 0x60]
00411147  50                       push      eax
00411148  89d8                     mov       eax, ebx
0041114a  8d4098                   lea       eax, [eax - 0x68]
0041114d  50                       push      eax
0041114e  89d8                     mov       eax, ebx
00411150  8d40a4                   lea       eax, [eax - 0x5c]
00411153  50                       push      eax
00411154  89d8                     mov       eax, ebx
00411156  8d40b0                   lea       eax, [eax - 0x50]
00411159  50                       push      eax
0041115a  89d8                     mov       eax, ebx
0041115c  8d40ac                   lea       eax, [eax - 0x54]
0041115f  50                       push      eax
00411160  89d8                     mov       eax, ebx
00411162  8d40a8                   lea       eax, [eax - 0x58]
00411165  50                       push      eax
00411166  89d8                     mov       eax, ebx
00411168  8d40b8                   lea       eax, [eax - 0x48]
0041116b  50                       push      eax
0041116c  89d8                     mov       eax, ebx
0041116e  8d4094                   lea       eax, [eax - 0x6c]
00411171  50                       push      eax
00411172  89d8                     mov       eax, ebx
00411174  8d40bc                   lea       eax, [eax - 0x44]
00411177  50                       push      eax
00411178  68c0bbf400               push      0xf4bbc0 ; _isecom_
0041117d  e84e800300               call      0x4491d0 ; _xlkt22_
00411182  83c434                   add       esp, 0x34
00411185  89d8                     mov       eax, ebx
00411187  89d9                     mov       ecx, ebx
00411189  d94190                   fld       dword ptr [ecx - 0x70]
0041118c  d84880                   fmul      dword ptr [eax - 0x80]
0041118f  d905c4bbf400             fld       dword ptr [0xf4bbc4]
00411195  d80dc4bbf400             fmul      dword ptr [0xf4bbc4]
0041119b  dec9                     fmulp     st(1)
0041119d  89d8                     mov       eax, ebx
0041119f  89d9                     mov       ecx, ebx
004111a1  d94194                   fld       dword ptr [ecx - 0x6c]
004111a4  d84894                   fmul      dword ptr [eax - 0x6c]
004111a7  d80dccbbf400             fmul      dword ptr [0xf4bbcc]
004111ad  def9                     fdivp     st(1)
004111af  d806                     fadd      dword ptr [esi]
004111b1  d835c8bbf400             fdiv      dword ptr [0xf4bbc8]
004111b7  d82594985500             fsub      dword ptr [0x559894] ; bits=0000803f, f32=1.0
004111bd  5e                       pop       esi
004111be  5b                       pop       ebx
004111bf  8be5                     mov       esp, ebp
004111c1  5d                       pop       ebp
004111c2  c3                       ret
004111c3  8d9b00000000             lea       ebx, [ebx]
004111c9  8da42400000000           lea       esp, [esp]
