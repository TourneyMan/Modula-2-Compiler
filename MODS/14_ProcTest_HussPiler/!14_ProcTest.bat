@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\14_ProcTest_HussPiler\
	if exist 14_ProcTest.obj del 14_ProcTest.obj
	if exist 14_ProcTest.exe del 14_ProcTest.exe

	if not exist 14_ProcTest.mod copy E:\Documents\GitHub\HussPiler\MODS\14_ProcTest.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\14_ProcTest_HussPiler\

	C:\masm32\bin\ml /c /coff 14_ProcTest.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 14_ProcTest.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\14_ProcTest_HussPiler\
	E:
	copy C:\CompilerOutput\14_ProcTest.exe
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