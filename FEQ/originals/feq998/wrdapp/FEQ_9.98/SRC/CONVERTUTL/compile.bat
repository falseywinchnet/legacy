echo off
copy ..\share\fqshrarg.for
copy ..\share\fqshrunt.for
copy ..\share\fqshrstr.for
copy ..\share\forunit.com
copy ..\share\whatos.cmn
copy ..\share\forunit.cmn
copy ..\convert.feq\*.for
copy ..\convert.feq\*.cmn

rem Edit this file and insert a call to the Make utility or
rem Fortran compiler. An example using Make with Lahey/Fujitsu 
rem Fortran 95 (LF95) is:
rem call am > am.out
rem The included automake.fig contains the settings for LF95.

