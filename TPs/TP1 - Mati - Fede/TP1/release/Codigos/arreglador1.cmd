@echo off
DEL RecorridoCasiGucci.txt
setLocal EnableDelayedExpansion
For /f "tokens=* delims= " %%a in (RecorridoNoGucci.txt) do (
Set str=%%a
set str=!str:.="!
echo !str!>>RecorridoCasiGucci.txt
)
ENDLOCAL
