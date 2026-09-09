@echo off
rem  test.bat - batch program to run FEQ tests
rem
rem  Usage: test [start [stop]]
rem
rem         where: start = starting test number
rem                 stop = ending test number (may be same as start)
rem
rem         (Note that start and stop are assumed to be within the valid
rem          test range and are assumed to be in ascending order--the
rem          absence of numeric variables in batch files makes error checking
rem          awkward.)
rem
rem  History: 99/04/06 mcrouse
rem
set topdir=..
set data=%topdir%\data
set prog=%topdir%\bin\feq.exe
set prog2=%topdir%\bin\fequtl.exe
set prognm=feq
set divd=---------------------------------------

rem  assign valid test range values as default values
set start=1
set stop=6
rem  if values supplied for start and stop, use those
if not "%1"=="" set start=%1
if not "%2"=="" set stop=%2

echo.
echo %divd%%divd%
echo Begin processing %prognm% test runs %start% to %stop%
goto test%start%

:test1
set n=1
if exist feqex%n%.* del feqex%n%.*
echo.
echo.
echo %divd%%divd%
echo Test run number %n%
%prog% %data%\feqex%n% feqex%n%.out
if "%stop%"=="%n%" goto end

:test2
set n=2
if exist feqex%n%.* del feqex%n%.*
echo.
echo.
echo %divd%%divd%
echo Test run number %n%
%prog% %data%\feqex%n% feqex%n%.out
if "%stop%"=="%n%" goto end

:test3
set n=3
if exist feqex%n%.* del feqex%n%.*
echo.
echo.
echo %divd%%divd%
echo Test run number %n%
%prog% %data%\feqex%n% feqex%n%.out
if "%stop%"=="%n%" goto end

:test4
set n=4
if exist feqex%n%.* del feqex%n%.*
echo.
echo.
echo %divd%%divd%
echo Test run number %n%
%prog% %data%\feqex%n% feqex%n%.out
if "%stop%"=="%n%" goto end

:test5
set n=5
if exist utlexm.* del utlexm.*
echo.
echo.
echo %divd%%divd%
echo Test run number %n%
%prog2% %data%\utlexm.in utlexm.out utlexm.tab
if "%stop%"=="%n%" goto end

:test6
set n=6
if exist culvert.* del culvert.*
echo.
echo.
echo %divd%%divd%
echo Test run number %n%
%prog2% %data%\culvert.in culvert.out culvert.tab
if "%stop%"=="%n%" goto end

:end
call %topdir%\test\check %start% %stop%

rem  clear the variables used from the environment
set topdir=
set data=
set prog=
set prog2=
set prognm=
set divd=
set start=
set stop=
set n=
