@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\09_LoopIf_HussPiler\
	if exist 09_LoopIf.obj del 09_LoopIf.obj
	if exist 09_LoopIf.exe del 09_LoopIf.exe

	if not exist 09_LoopIf.mod copy E:\Documents\GitHub\HussPiler\MODS\09_LoopIf.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\09_LoopIf_HussPiler\

	C:\masm32\bin\ml /c /coff 09_LoopIf.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 09_LoopIf.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\09_LoopIf_HussPiler\
	E:
	copy C:\CompilerOutput\09_LoopIf.exe
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