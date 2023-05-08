@echo off

SET compilerFlags=-pedantic-errors -Wall -Werror -O3 -std=c17 -Wextra -Wconversion -m64 

ECHO "Building ..."
clang %compilerFlags% -c code/000.c -o release/000.o
clang %compilerFlags% -c code/platform_win32.c -o release/platform_win32.o
clang -mwindows -o release/win32.exe release/000.o release/platform_win32.o

pause
ECHO "Cleaning ..."
@IF EXIST "release\*.o" DEL /F "release\*.o"
@IF EXIST "release\*.tmp" DEL /F "release\*.tmp"

ECHO "Running ..."
release\win32.exe

