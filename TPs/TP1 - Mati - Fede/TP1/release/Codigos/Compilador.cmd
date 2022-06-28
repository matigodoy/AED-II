@echo off
title [Compilador] TP1 - AEDII
color 0a
set entrada=C:\TP1\release\Codigos\RecorridoGucci.txt
set salida=C:\TP1\release\Codigos\Recorrido.png
cd C:\TP1\release\bin\
dot.exe -Tpng %entrada% -o %salida%
exit