; _jwe_gpwd
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xa1660
004a1660  55                       push      ebp
004a1661  8bec                     mov       ebp, esp
004a1663  83ec20                   sub       esp, 0x20
004a1666  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
004a1669  8b4508                   mov       eax, dword ptr [ebp + 8]
004a166c  8bd1                     mov       edx, ecx
004a166e  8945e8                   mov       dword ptr [ebp - 0x18], eax
004a1671  894dec                   mov       dword ptr [ebp - 0x14], ecx
004a1674  8bc2                     mov       eax, edx
004a1676  8d8a000018c0             lea       ecx, [edx - 0x3fe80000]
004a167c  c1f914                   sar       ecx, 0x14
004a167f  c1f80b                   sar       eax, 0xb
004a1682  894dfc                   mov       dword ptr [ebp - 4], ecx
004a1685  25ff010000               and       eax, 0x1ff
004a168a  db45fc                   fild      dword ptr [ebp - 4]
004a168d  81fa00001000             cmp       edx, 0x100000
004a1693  7c1b                     jl        0x4a16b0
004a1695  c1e114                   shl       ecx, 0x14
004a1698  2bd1                     sub       edx, ecx
004a169a  8bca                     mov       ecx, edx
004a169c  89550c                   mov       dword ptr [ebp + 0xc], edx
004a169f  8b55e8                   mov       edx, dword ptr [ebp - 0x18]
004a16a2  81e100f8ff7f             and       ecx, 0x7ffff800
004a16a8  894dfc                   mov       dword ptr [ebp - 4], ecx
004a16ab  895508                   mov       dword ptr [ebp + 8], edx
004a16ae  eb49                     jmp       0x4a16f9
004a16b0  dd4508                   fld       qword ptr [ebp + 8]
004a16b3  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004a16b9  dfe0                     fnstsw    ax
004a16bb  2500410000               and       eax, 0x4100
004a16c0  0f8589000000             jne       0x4a174f
004a16c6  dd05f0fd5400             fld       qword ptr [0x54fdf0] ; bits=0000000000003043, f64=4503599627370496.0
004a16cc  dc4d08                   fmul      qword ptr [ebp + 8]
004a16cf  dd5d08                   fstp      qword ptr [ebp + 8]
004a16d2  8b450c                   mov       eax, dword ptr [ebp + 0xc]
004a16d5  8d88000018c0             lea       ecx, [eax - 0x3fe80000]
004a16db  c1f914                   sar       ecx, 0x14
004a16de  c1e114                   shl       ecx, 0x14
004a16e1  2bc1                     sub       eax, ecx
004a16e3  8bd0                     mov       edx, eax
004a16e5  89450c                   mov       dword ptr [ebp + 0xc], eax
004a16e8  81e200f8ff7f             and       edx, 0x7ffff800
004a16ee  c1e80b                   shr       eax, 0xb
004a16f1  8955fc                   mov       dword ptr [ebp - 4], edx
004a16f4  25ff010000               and       eax, 0x1ff
004a16f9  dd4508                   fld       qword ptr [ebp + 8]
004a16fc  c745f800000000           mov       dword ptr [ebp - 8], 0
004a1703  dc65f8                   fsub      qword ptr [ebp - 8]
004a1706  dd45f8                   fld       qword ptr [ebp - 8]
004a1709  dc4508                   fadd      qword ptr [ebp + 8]
004a170c  c1e004                   shl       eax, 4
004a170f  def9                     fdivp     st(1)
004a1711  dd55e0                   fst       qword ptr [ebp - 0x20]
004a1714  d9c0                     fld       st(0)
004a1716  d8c9                     fmul      st(1)
004a1718  dd5df0                   fstp      qword ptr [ebp - 0x10]
004a171b  ddd8                     fstp      st(0)
004a171d  dd80b0dd5400             fld       qword ptr [eax + 0x54ddb0]
004a1723  dd05d8fd5400             fld       qword ptr [0x54fdd8] ; bits=94f8ce8e6d77e23f, f64=0.5770786084392676
004a1729  dc4df0                   fmul      qword ptr [ebp - 0x10]
004a172c  dc05d0fd5400             fadd      qword ptr [0x54fdd0] ; bits=7dfc39dc09c7ee3f, f64=0.9617966939257624
004a1732  dd45f0                   fld       qword ptr [ebp - 0x10]
004a1735  dc4de0                   fmul      qword ptr [ebp - 0x20]
004a1738  dec9                     fmulp     st(1)
004a173a  dd80b8dd5400             fld       qword ptr [eax + 0x54ddb8]
004a1740  dd05c8fd5400             fld       qword ptr [0x54fdc8] ; bits=fe822b6547150740, f64=2.8853900817779268
004a1746  dc4de0                   fmul      qword ptr [ebp - 0x20]
004a1749  dec1                     faddp     st(1)
004a174b  dec1                     faddp     st(1)
004a174d  eb06                     jmp       0x4a1755
004a174f  dd4508                   fld       qword ptr [ebp + 8]
004a1752  dd4508                   fld       qword ptr [ebp + 8]
004a1755  d9c1                     fld       st(1)
004a1757  d8c3                     fadd      st(3)
004a1759  8b4510                   mov       eax, dword ptr [ebp + 0x10]
004a175c  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
004a175f  894508                   mov       dword ptr [ebp + 8], eax
004a1762  57                       push      edi
004a1763  d8c1                     fadd      st(1)
004a1765  8b5508                   mov       edx, dword ptr [ebp + 8]
004a1768  b8000000f8               mov       eax, 0xf8000000
004a176d  23d0                     and       edx, eax
004a176f  894d0c                   mov       dword ptr [ebp + 0xc], ecx
004a1772  895508                   mov       dword ptr [ebp + 8], edx
004a1775  dd5df0                   fstp      qword ptr [ebp - 0x10]
004a1778  d9ca                     fxch      st(2)
004a177a  dc65f0                   fsub      qword ptr [ebp - 0x10]
004a177d  8b7df0                   mov       edi, dword ptr [ebp - 0x10]
004a1780  23f8                     and       edi, eax
004a1782  8b45f4                   mov       eax, dword ptr [ebp - 0xc]
004a1785  d8c1                     fadd      st(1)
004a1787  8bd0                     mov       edx, eax
004a1789  81e20000f07f             and       edx, 0x7ff00000
004a178f  dec2                     faddp     st(2)
004a1791  ddd8                     fstp      st(0)
004a1793  dd45f0                   fld       qword ptr [ebp - 0x10]
004a1796  897df0                   mov       dword ptr [ebp - 0x10], edi
004a1799  8bf9                     mov       edi, ecx
004a179b  81e70000f07f             and       edi, 0x7ff00000
004a17a1  03d7                     add       edx, edi
004a17a3  5f                       pop       edi
004a17a4  81fa00009080             cmp       edx, 0x80900000
004a17aa  7621                     jbe       0x4a17cd
004a17ac  33c1                     xor       eax, ecx
004a17ae  ddd8                     fstp      st(0)
004a17b0  85c0                     test      eax, eax
004a17b2  ddd8                     fstp      st(0)
004a17b4  0f88e7000000             js        0x4a18a1
004a17ba  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004a17bd  dd0580025500             fld       qword ptr [0x550280] ; __real@7fefffffffffffb6, bits=b6ffffffffffef7f, f64=1.7976931348623011e+308
004a17c3  c70089050000             mov       dword ptr [eax], 0x589
004a17c9  8be5                     mov       esp, ebp
004a17cb  5d                       pop       ebp
004a17cc  c3                       ret
004a17cd  dd45f0                   fld       qword ptr [ebp - 0x10]
004a17d0  dc4d08                   fmul      qword ptr [ebp + 8]
004a17d3  dd0550fe5400             fld       qword ptr [0x54fe50] ; ?bg@?1??jwe_gpwd@@9@9, bits=000000000000d842, f64=105553116266496.0
004a17d9  c745f800000000           mov       dword ptr [ebp - 8], 0
004a17e0  d8c1                     fadd      st(1)
004a17e2  dd5de8                   fstp      qword ptr [ebp - 0x18]
004a17e5  d9c9                     fxch      st(1)
004a17e7  dc65f0                   fsub      qword ptr [ebp - 0x10]
004a17ea  8b55e8                   mov       edx, dword ptr [ebp - 0x18]
004a17ed  8bca                     mov       ecx, edx
004a17ef  dec2                     faddp     st(2)
004a17f1  d9c9                     fxch      st(1)
004a17f3  83e13f                   and       ecx, 0x3f
004a17f6  8bc1                     mov       eax, ecx
004a17f8  dc4d10                   fmul      qword ptr [ebp + 0x10]
004a17fb  dd4510                   fld       qword ptr [ebp + 0x10]
004a17fe  dc6508                   fsub      qword ptr [ebp + 8]
004a1801  c1e004                   shl       eax, 4
004a1804  dc4df0                   fmul      qword ptr [ebp - 0x10]
004a1807  dec1                     faddp     st(1)
004a1809  dd45e8                   fld       qword ptr [ebp - 0x18]
004a180c  dc2550fe5400             fsub      qword ptr [0x54fe50] ; ?bg@?1??jwe_gpwd@@9@9, bits=000000000000d842, f64=105553116266496.0
004a1812  d8ea                     fsubr     st(2)
004a1814  dec1                     faddp     st(1)
004a1816  ddd9                     fstp      st(1)
004a1818  dd0578fe5400             fld       qword ptr [0x54fe78] ; ?p5@?1??jwe_gpwd@@9@9, bits=dfae83a17ed8553f, f64=0.0013333546285662563
004a181e  d8c9                     fmul      st(1)
004a1820  dc0570fe5400             fadd      qword ptr [0x54fe70] ; ?p4@?1??jwe_gpwd@@9@9, bits=fb414654adb2833f, f64=0.009618143209793031
004a1826  d9c1                     fld       st(1)
004a1828  d8ca                     fmul      st(2)
004a182a  dec9                     fmulp     st(1)
004a182c  dd0568fe5400             fld       qword ptr [0x54fe68] ; ?p3@?1??jwe_gpwd@@9@9, bits=b4fd04d7086bac3f, f64=0.0555041086649867
004a1832  d8ca                     fmul      st(2)
004a1834  dc0560fe5400             fadd      qword ptr [0x54fe60] ; ?p2@?1??jwe_gpwd@@9@9, bits=229882ffbdbfce3f, f64=0.24022650695877795
004a183a  dec1                     faddp     st(1)
004a183c  d8c9                     fmul      st(1)
004a183e  dc0558fe5400             fadd      qword ptr [0x54fe58] ; ?p1@?1??jwe_gpwd@@9@9, bits=ef39fafe422ee63f, f64=0.6931471805599453
004a1844  d9c9                     fxch      st(1)
004a1846  dc8880fe5400             fmul      qword ptr [eax + 0x54fe80]
004a184c  dec9                     fmulp     st(1)
004a184e  dc8088fe5400             fadd      qword ptr [eax + 0x54fe88]
004a1854  dc8080fe5400             fadd      qword ptr [eax + 0x54fe80]
004a185a  8bc2                     mov       eax, edx
004a185c  2bc1                     sub       eax, ecx
004a185e  05c0ff0000               add       eax, 0xffc0
004a1863  dd5d08                   fstp      qword ptr [ebp + 8]
004a1866  c1e00e                   shl       eax, 0xe
004a1869  8945fc                   mov       dword ptr [ebp - 4], eax
004a186c  8b450c                   mov       eax, dword ptr [ebp + 0xc]
004a186f  250000f07f               and       eax, 0x7ff00000
004a1874  2d01c0ef3f               sub       eax, 0x3fefc001
004a1879  c1f80e                   sar       eax, 0xe
004a187c  2bc1                     sub       eax, ecx
004a187e  03c2                     add       eax, edx
004a1880  3d00000100               cmp       eax, 0x10000
004a1885  7c13                     jl        0x4a189a
004a1887  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
004a188a  dd0580025500             fld       qword ptr [0x550280] ; __real@7fefffffffffffb6, bits=b6ffffffffffef7f, f64=1.7976931348623011e+308
004a1890  c70189050000             mov       dword ptr [ecx], 0x589
004a1896  8be5                     mov       esp, ebp
004a1898  5d                       pop       ebp
004a1899  c3                       ret
004a189a  3d4000ffff               cmp       eax, 0xffff0040
004a189f  7f0a                     jg        0x4a18ab
004a18a1  dd0560dc5400             fld       qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004a18a7  8be5                     mov       esp, ebp
004a18a9  5d                       pop       ebp
004a18aa  c3                       ret
004a18ab  dd45f8                   fld       qword ptr [ebp - 8]
004a18ae  dc4d08                   fmul      qword ptr [ebp + 8]
004a18b1  8be5                     mov       esp, ebp
004a18b3  5d                       pop       ebp
004a18b4  c3                       ret
004a18b5  90                       nop
004a18b6  90                       nop
004a18b7  90                       nop
004a18b8  90                       nop
004a18b9  90                       nop
004a18ba  90                       nop
004a18bb  90                       nop
004a18bc  90                       nop
004a18bd  90                       nop
004a18be  90                       nop
004a18bf  90                       nop
