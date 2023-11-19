@echo off

::Clear console
cls

:: Create target directory if does not exist
if not exist .\target\ (
    mkdir .\target
)

:: Clear target directory
del /q /s .\target\* > nul

:: Compile app into .exe
gcc .\src\*.c .\src\bmi\*.c .\src\converter\*.c .\src\employee\*.c .\src\fibonacci\*.c -o .\target\app.exe

:: Run app
start .\target\app.exe