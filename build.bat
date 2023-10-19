@echo off

:: Create target directory if does not exist
if not exist .\target\ (
    mkdir .\target
)

:: Clear target directory
del /q /s .\target\* > nul

:: Compile app into .exe
gcc .\src\*.c  -o .\target\app.exe  

:: Run app
start .\target\app.exe