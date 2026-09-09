@echo off
rem  clean.bat - clean up files after test runs
rem  Usage:  clean

rem  remove output from each test
for %%s in (out wsq) do  if exist feqex1.%%s del feqex1.%%s
for %%s in (out wsq) do  if exist feqex2.%%s del feqex2.%%s
for %%s in (out wsq) do  if exist feqex3.%%s del feqex3.%%s
for %%s in (out wsq) do  if exist feqex4.%%s del feqex4.%%s

for %%f in (utlexm.chx utlexm.out utlexm.tab ) do  if exist %%f del %%f
for %%f in (culvert.out culvert.tab)           do  if exist %%f del %%f

if exist check.log del check.log
