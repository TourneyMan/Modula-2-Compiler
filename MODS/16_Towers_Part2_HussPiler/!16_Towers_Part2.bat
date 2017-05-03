@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\16_Towers_Part2_HussPiler\
	if exist 16_Towers_Part2.obj del 16_Towers_Part2.obj
	if exist 16_Towers_Part2.exe del 16_Towers_Part2.exe

	if not exist 16_Towers_Part2.mod copy E:\Documents\GitHub\HussPiler\MODS\16_Towers_Part2.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\16_Towers_Part2_HussPiler\

	C:\masm32\bin\ml /c /coff 16_Towers_Part2.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 16_Towers_Part2.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\16_Towers_Part2_HussPiler\
	E:
	copy C:\CompilerOutput\16_Towers_Part2.exe
	rmdir C:\CompilerOutput /s /q

	dir
	goto TheEnd

:errlink
	echo _
	echo Link Error
	goto TheEnd

:errasm
	echo _
	echo Assembly Error
	goto TheEnd

:TheEnd
	pause
	cls

@echo on