@echo off
call vendor\bin\premake\premake5.exe vs2022
IF %errorlevel% neq 0{
	pause
	}