@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\07_LoopTest_HussPiler\
	if exist 07_LoopTest.obj del 07_LoopTest.obj
	if exist 07_LoopTest.exe del 07_LoopTest.exe

	if not exist 07_LoopTest.mod copy E:\Documents\GitHub\HussPiler\MODS\07_LoopTest.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\07_LoopTest_HussPiler\

	C:\masm32\bin\ml /c /coff 07_LoopTest.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 07_LoopTest.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\07_LoopTest_HussPiler\
	E:
	copy C:\CompilerOutput\07_LoopTest.exe
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