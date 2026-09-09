@echo off
rem  clean.bat - clean up files after test runs
rem  Usage:  clean

rem  remove output from each test
for %%s in (spi wsq) do  if exist feqex1.out.%%s del feqex1.out.%%s
for %%s in (spi wsq) do  if exist feqex2.out.%%s del feqex2.out.%%s
for %%s in (spi wsq) do  if exist feqex3.out.%%s del feqex3.out.%%s
for %%s in (spi wsq) do  if exist feqex4.out.%%s del feqex4.out.%%s
for %%s in (feqex1.out feqex2.out feqex3.out feqex4.out) do  if exist %%s del %%s

for %%f in (utlexm.chx utlexm.out utlexm.tab ) do  if exist %%f del %%f
for %%f in (culvert.out culvert.tab)           do  if exist %%f del %%f

if exist check.log del check.log
