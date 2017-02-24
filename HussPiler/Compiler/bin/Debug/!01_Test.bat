@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\01_Test_HussPiler
	if exist 01_Test.obj del 01_Test.obj
	if exist 01_Test.exe del 01_Test.exe

	if not exist 01_Test.mod copy E:\Documents\GitHub\HussPiler\MODS\01_Test.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\01_Test_HussPiler

	C:\masm32\bin\ml /c /coff 01_Test.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 01_Test.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\01_Test_HussPiler
	E:
	copy C:\CompilerOutput\01_Test.exe
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