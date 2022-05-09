@echo off
if exist n-queen.exe(del n-queen.exe)
g++ .\n-queen.cpp -o n-queen
echo ************************************n-queen************************************
.\n-queen.exe
@echo on
pause