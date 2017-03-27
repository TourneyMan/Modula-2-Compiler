@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\06_IfTest_HussPiler\
	if exist 06_IfTest.obj del 06_IfTest.obj
	if exist 06_IfTest.exe del 06_IfTest.exe

	if not exist 06_IfTest.mod copy E:\Documents\GitHub\HussPiler\MODS\06_IfTest.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\06_IfTest_HussPiler\

	C:\masm32\bin\ml /c /coff 06_IfTest.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 06_IfTest.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\06_IfTest_HussPiler\
	E:
	copy C:\CompilerOutput\06_IfTest.exe
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