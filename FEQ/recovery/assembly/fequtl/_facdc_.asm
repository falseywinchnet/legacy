; _facdc_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x33d90
00433d90  55                       push      ebp
00433d91  8bec                     mov       ebp, esp
00433d93  53                       push      ebx
00433d94  8b5508                   mov       edx, dword ptr [ebp + 8]
00433d97  8b5d0c                   mov       ebx, dword ptr [ebp + 0xc]
00433d9a  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
00433d9d  d903                     fld       dword ptr [ebx]
00433d9f  d9ee                     fldz
00433da1  d9c9                     fxch      st(1)
00433da3  dde1                     fucom     st(1)
00433da5  d9c9                     fxch      st(1)
00433da7  dfe0                     fnstsw    ax
00433da9  9e                       sahf
00433daa  0f8a22000000             jp        0x433dd2
00433db0  7520                     jne       0x433dd2
00433db2  ddd9                     fstp      st(1)
00433db4  d902                     fld       dword ptr [edx]
00433db6  d8d1                     fcom      st(1)
00433db8  ddd9                     fstp      st(1)
00433dba  dfe0                     fnstsw    ax
00433dbc  9e                       sahf
00433dbd  0f8a0b000000             jp        0x433dce
00433dc3  7709                     ja        0x433dce
00433dc5  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00433dc8  d808                     fmul      dword ptr [eax]
00433dca  d9e0                     fchs
00433dcc  eb60                     jmp       0x433e2e
00433dce  d809                     fmul      dword ptr [ecx]
00433dd0  eb5c                     jmp       0x433e2e
00433dd2  ddd8                     fstp      st(0)
00433dd4  d9c0                     fld       st(0)
00433dd6  d9e0                     fchs
00433dd8  d902                     fld       dword ptr [edx]
00433dda  d8d1                     fcom      st(1)
00433ddc  ddd9                     fstp      st(1)
00433dde  d9c9                     fxch      st(1)
00433de0  dfe0                     fnstsw    ax
00433de2  9e                       sahf
00433de3  0f8a0d000000             jp        0x433df6
00433de9  770b                     ja        0x433df6
00433deb  ddd8                     fstp      st(0)
00433ded  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00433df0  d808                     fmul      dword ptr [eax]
00433df2  d9e0                     fchs
00433df4  eb38                     jmp       0x433e2e
00433df6  d9c9                     fxch      st(1)
00433df8  d8d1                     fcom      st(1)
00433dfa  d9c9                     fxch      st(1)
00433dfc  dfe0                     fnstsw    ax
00433dfe  9e                       sahf
00433dff  0f8a25000000             jp        0x433e2a
00433e05  7323                     jae       0x433e2a
00433e07  d9c0                     fld       st(0)
00433e09  d8c0                     fadd      st(0)
00433e0b  d9ca                     fxch      st(2)
00433e0d  d8c1                     fadd      st(1)
00433e0f  def2                     fdivrp    st(2)
00433e11  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00433e14  d900                     fld       dword ptr [eax]
00433e16  d9c0                     fld       st(0)
00433e18  d800                     fadd      dword ptr [eax]
00433e1a  d9c1                     fld       st(1)
00433e1c  d801                     fadd      dword ptr [ecx]
00433e1e  d8cc                     fmul      st(4)
00433e20  dee1                     fsubrp    st(1)
00433e22  decb                     fmulp     st(3)
00433e24  dec2                     faddp     st(2)
00433e26  dec9                     fmulp     st(1)
00433e28  eb04                     jmp       0x433e2e
00433e2a  ddd8                     fstp      st(0)
00433e2c  d809                     fmul      dword ptr [ecx]
00433e2e  5b                       pop       ebx
00433e2f  8be5                     mov       esp, ebp
00433e31  5d                       pop       ebp
00433e32  c3                       ret
00433e33  8d9b00000000             lea       ebx, [ebx]
00433e39  8da42400000000           lea       esp, [esp]
