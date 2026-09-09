ECHO OFF
copy ..\..\*.for
copy ..\..\*.cmn
copy ..\..\*.prm
copy ..\..\dsslf95.lib 
copy ..\..\single\linsys.for
copy ..\..\single\matcom.cmn
copy ..\..\..\share\*.for
copy ..\..\..\share\*.cmn
copy ..\..\..\share\arsize.prm
copy ..\..\..\share\morglh.prm morg.prm
copy ..\..\..\share\lf95_ms_s_npf.who
copy ..\..\..\svn_report\svn_reportdmy.for svn_report.for
copy mkdir_fun_msw_lf95.for mkdir_fun.for
ren lf95_ms_s_npf.who lf95_ms_s_npf.for
del hecdmy.for
del locsubux.for
del locsubs.for
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
del *.map
del *.obj