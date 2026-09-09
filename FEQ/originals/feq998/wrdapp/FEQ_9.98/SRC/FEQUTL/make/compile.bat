ECHO OFF
copy  ..\*.for
copy  ..\..\share\*.for
copy  ..\..\share\*.cmn
copy  ..\..\share\arsize.prm
copy  ..\..\share\morglh.prm  morg.prm
del locsubs.for
del timer90.for
del locsubux.for
copy  ..\*.cmn
copy  ..\*.prm
call am > am.out
del  *.for
del  *.cmn
del  *.prm
