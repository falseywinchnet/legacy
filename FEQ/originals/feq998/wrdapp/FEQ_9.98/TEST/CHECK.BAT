@echo off
rem  check.bat - batch program to compare original output files
rem              against newly created output files
rem
rem  called from test.bat; not run independently
rem
rem  Usage: check [start [stop]]
rem
rem         where: start = starting test number
rem                 stop = ending test number (may be same as start)
rem
rem  History: 99/04/06 mcrouse
rem

set start=%1
set stop=%2
if exist check.log del check.log

echo.
echo.
echo %divd%%divd%
echo Comparing test output with expected output...
echo.
echo.
goto test%start%

:test1
set n=1
for %%f in (feqex%n%.*) do  fc %data%\%%f %%f >> check.log
if "%stop%"=="%n%" goto end

:test2
set n=2
for %%f in (feqex%n%.*) do  fc %data%\%%f %%f >> check.log
if "%stop%"=="%n%" goto end

:test3
set n=3
for %%f in (feqex%n%.*) do  fc %data%\%%f %%f >> check.log
if "%stop%"=="%n%" goto end

:test4
set n=4
for %%f in (feqex%n%.*) do  fc %data%\%%f %%f >> check.log
if "%stop%"=="%n%" goto end

:test5
set n=5
for %%f in (utlexm.*) do  fc %data%\%%f %%f >> check.log
if "%stop%"=="%n%" goto end

:test6
set n=6
for %%f in (culvert.*) do  fc %data%\%%f %%f >> check.log
if "%stop%"=="%n%" goto end

:end
echo Comparisons completed.  Examine file check.log for any differences.
echo.
echo Any significant differences other than processing times may indicate 
echo a problem with %prognm% installation.
echo.
