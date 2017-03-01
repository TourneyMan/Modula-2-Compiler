@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\04_WriteVar_HussPiler\
	if exist 04_WriteVar.obj del 04_WriteVar.obj
	if exist 04_WriteVar.exe del 04_WriteVar.exe

	if not exist 04_WriteVar.mod copy E:\Documents\GitHub\HussPiler\MODS\04_WriteVar.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\04_WriteVar_HussPiler\

	C:\masm32\bin\ml /c /coff 04_WriteVar.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 04_WriteVar.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\04_WriteVar_HussPiler\
	E:
	copy C:\CompilerOutput\04_WriteVar.exe
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