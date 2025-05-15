@echo off
set SFML=C:\Users\Admin\Documents\libraries\SFML-3.0.0

echo [1/3] Compiling main.cpp...
g++ -c main.cpp -I %SFML%\include
if errorlevel 1 exit /b

echo [2/3] Linking...
g++ main.o -o main -L %SFML%\lib -lsfml-graphics -lsfml-window -lsfml-system
if errorlevel 1 exit /b

echo [3/3] Running...
copy %SFML%\bin\*.dll . >nul
main.exe