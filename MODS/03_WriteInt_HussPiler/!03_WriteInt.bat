@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\03_WriteInt_HussPiler\
	if exist 03_WriteInt.obj del 03_WriteInt.obj
	if exist 03_WriteInt.exe del 03_WriteInt.exe

	if not exist 03_WriteInt.mod copy E:\Documents\GitHub\HussPiler\MODS\03_WriteInt.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\03_WriteInt_HussPiler\

	C:\masm32\bin\ml /c /coff 03_WriteInt.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 03_WriteInt.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\03_WriteInt_HussPiler\
	E:
	copy C:\CompilerOutput\03_WriteInt.exe
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