ECHO OFF
copy  ..\*.for
copy  ..\single\linsys.for
copy  ..\..\share\*.for
copy  ..\..\share\arsize.prm
copy  ..\..\share\morglh.prm morg.prm
copy  ..\..\share\*.cmn
copy  ..\..\share\lf90_ms_s.who
ren lf90_ms_s.who lf90_ms_s.for
del hecdmy.for
rem del hecdss.for
del locsubux.for
del locsubs.for
copy  ..\*.cmn
copy  ..\single\matcom.cmn
copy  ..\*.prm
call am > am.out
del  *.for
del  *.cmn
del  *.prm
