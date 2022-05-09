@echo off
if exist floyd-warshall.exe(del floyd-warshall.exe)
g++ .\floyd-warshall.cpp -o floyd-warshall
echo ************************************floyd-warshall************************************
.\floyd-warshall.exe
@echo on
pause