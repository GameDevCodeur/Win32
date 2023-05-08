@echo off

SET compilerFlags=-pedantic-errors -Wall -Werror -O3 -std=c17 -Wextra -Wconversion -m64 -mwindows
ECHO "Building %assembly%%..."
clang %compilerFlags% code/000.c -o release/000.exe

pause
