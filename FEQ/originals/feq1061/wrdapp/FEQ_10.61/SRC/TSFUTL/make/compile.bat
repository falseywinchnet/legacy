ECHO OFF

copy ..\*.for
copy ..\*.cmn

call am > am.out

del *.for
del *.cmn