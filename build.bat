@echo off

:: Clear target directory
del /q /s .\target\* > nul

:: Compile app into .exe
gcc .\src\*.c  -o .\target\app.exe  

:: Run app
start .\target\app.exe