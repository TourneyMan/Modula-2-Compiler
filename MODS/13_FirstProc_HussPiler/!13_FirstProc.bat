@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\13_FirstProc_HussPiler\
	if exist 13_FirstProc.obj del 13_FirstProc.obj
	if exist 13_FirstProc.exe del 13_FirstProc.exe

	if not exist 13_FirstProc.mod copy E:\Documents\GitHub\HussPiler\MODS\13_FirstProc.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\13_FirstProc_HussPiler\

	C:\masm32\bin\ml /c /coff 13_FirstProc.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 13_FirstProc.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\13_FirstProc_HussPiler\
	E:
	copy C:\CompilerOutput\13_FirstProc.exe
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