ECHO OFF

copy ..\..\share\morgux.prm morg.prm
copy ..\*.for

call am > am.out

del *.for
del *.obj
del *.prm
