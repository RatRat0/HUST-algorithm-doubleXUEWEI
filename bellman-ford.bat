@echo off
if exist bellman-ford.exe(del bellman-ford.exe)
g++ .\bellman-ford.cpp -o bellman-ford
echo ************************************bellman-ford************************************
.\bellman-ford.exe
@echo on
pause