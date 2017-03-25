@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\05_TestExpr_HussPiler\
	if exist 05_TestExpr.obj del 05_TestExpr.obj
	if exist 05_TestExpr.exe del 05_TestExpr.exe

	if not exist 05_TestExpr.mod copy E:\Documents\GitHub\HussPiler\MODS\05_TestExpr.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\05_TestExpr_HussPiler\

	C:\masm32\bin\ml /c /coff 05_TestExpr.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 05_TestExpr.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\05_TestExpr_HussPiler\
	E:
	copy C:\CompilerOutput\05_TestExpr.exe
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