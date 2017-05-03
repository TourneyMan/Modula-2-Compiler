@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\15_Towers_Part1_HussPiler\
	if exist 15_Towers_Part1.obj del 15_Towers_Part1.obj
	if exist 15_Towers_Part1.exe del 15_Towers_Part1.exe

	if not exist 15_Towers_Part1.mod copy E:\Documents\GitHub\HussPiler\MODS\15_Towers_Part1.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\15_Towers_Part1_HussPiler\

	C:\masm32\bin\ml /c /coff 15_Towers_Part1.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 15_Towers_Part1.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\15_Towers_Part1_HussPiler\
	E:
	copy C:\CompilerOutput\15_Towers_Part1.exe
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