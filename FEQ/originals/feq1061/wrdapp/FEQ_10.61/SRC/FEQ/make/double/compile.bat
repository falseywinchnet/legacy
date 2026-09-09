ECHO OFF
copy ..\..\*.for
copy ..\..\*.cmn
copy ..\..\*.prm
copy ..\..\double\linsys.for
copy ..\..\double\matcom.cmn
copy ..\..\..\share\*.for
copy ..\..\..\share\*.cmn
copy ..\..\..\share\arsize.prm
copy ..\..\..\share\morglh.prm morg.prm
copy ..\..\..\share\lf95_ms_d_npf.who
copy ..\..\..\svn_report\svn_reportdmy.for svn_report.for
copy mkdir_fun_msw_lf95.for mkdir_fun.for
ren lf95_ms_d_npf.who lf95_ms_d_npf.for
rem del hecdmy.for
del hecdss.for
del locsubux.for
rem del locsubs.for
del timer90.for
del mkdir_fun_msw_lf95.for
del mkdir_fun_lx_lf95.for
del mkdir_fun_lx_g95.for
del mkdir_fun_msw_g95.for
del getsvn_lx_g95.for
del getsvn_lx_lf95.for
del getsvn_msw_g95.for
del pwd_lx_g95.for
del pwd_lx_lf95.for
del pwd_msw_g95.for
call am > am.out
del *.for
del *.cmn
del *.prm
del *.obj
del *.map

