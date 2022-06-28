@echo off
DEL RecorridoGucci.txt
setLocal EnableDelayedExpansion
For /f "tokens=* delims= " %%a in (RecorridoCasiGucci.txt) do (
Set str=%%a
set str=!str:_= !
echo !str!>>RecorridoGucci.txt
)
ENDLOCAL
