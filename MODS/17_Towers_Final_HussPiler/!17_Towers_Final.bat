@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\17_Towers_Final_HussPiler\
	if exist 17_Towers_Final.obj del 17_Towers_Final.obj
	if exist 17_Towers_Final.exe del 17_Towers_Final.exe

	if not exist 17_Towers_Final.mod copy E:\Documents\GitHub\HussPiler\MODS\17_Towers_Final.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\17_Towers_Final_HussPiler\

	C:\masm32\bin\ml /c /coff 17_Towers_Final.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 17_Towers_Final.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\17_Towers_Final_HussPiler\
	E:
	copy C:\CompilerOutput\17_Towers_Final.exe
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