@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\01_Test_HussPiler\
	if exist 02_HelloWorld.obj del 02_HelloWorld.obj
	if exist 02_HelloWorld.exe del 02_HelloWorld.exe

	if not exist 02_HelloWorld.mod copy E:\Documents\GitHub\HussPiler\MODS\02_HelloWorld.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\01_Test_HussPiler\

	C:\masm32\bin\ml /c /coff 02_HelloWorld.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 02_HelloWorld.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\01_Test_HussPiler\
	E:
	copy C:\CompilerOutput\02_HelloWorld.exe
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