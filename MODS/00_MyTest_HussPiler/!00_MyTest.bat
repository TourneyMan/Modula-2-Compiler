@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\00_MyTest_HussPiler\
	if exist 00_MyTest.obj del 00_MyTest.obj
	if exist 00_MyTest.exe del 00_MyTest.exe

	if not exist 00_MyTest.mod copy E:\Documents\GitHub\HussPiler\MODS\00_MyTest.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\00_MyTest_HussPiler\

	C:\masm32\bin\ml /c /coff 00_MyTest.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 00_MyTest.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\00_MyTest_HussPiler\
	E:
	copy C:\CompilerOutput\00_MyTest.exe
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