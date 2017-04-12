@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\11_Square_HussPiler\
	if exist 11_Square.obj del 11_Square.obj
	if exist 11_Square.exe del 11_Square.exe

	if not exist 11_Square.mod copy E:\Documents\GitHub\HussPiler\MODS\11_Square.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\11_Square_HussPiler\

	C:\masm32\bin\ml /c /coff 11_Square.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 11_Square.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\11_Square_HussPiler\
	E:
	copy C:\CompilerOutput\11_Square.exe
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