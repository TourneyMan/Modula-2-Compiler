@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\08_ReadTest_HussPiler\
	if exist 08_ReadTest.obj del 08_ReadTest.obj
	if exist 08_ReadTest.exe del 08_ReadTest.exe

	if not exist 08_ReadTest.mod copy E:\Documents\GitHub\HussPiler\MODS\08_ReadTest.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\08_ReadTest_HussPiler\

	C:\masm32\bin\ml /c /coff 08_ReadTest.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 08_ReadTest.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\08_ReadTest_HussPiler\
	E:
	copy C:\CompilerOutput\08_ReadTest.exe
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