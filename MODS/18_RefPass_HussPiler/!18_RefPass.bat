@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\18_RefPass_HussPiler\
	if exist 18_RefPass.obj del 18_RefPass.obj
	if exist 18_RefPass.exe del 18_RefPass.exe

	if not exist 18_RefPass.mod copy E:\Documents\GitHub\HussPiler\MODS\18_RefPass.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\18_RefPass_HussPiler\

	C:\masm32\bin\ml /c /coff 18_RefPass.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 18_RefPass.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\18_RefPass_HussPiler\
	E:
	copy C:\CompilerOutput\18_RefPass.exe
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