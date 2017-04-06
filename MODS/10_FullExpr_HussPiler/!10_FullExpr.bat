@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\10_FullExpr_HussPiler\
	if exist 10_FullExpr.obj del 10_FullExpr.obj
	if exist 10_FullExpr.exe del 10_FullExpr.exe

	if not exist 10_FullExpr.mod copy E:\Documents\GitHub\HussPiler\MODS\10_FullExpr.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\10_FullExpr_HussPiler\

	C:\masm32\bin\ml /c /coff 10_FullExpr.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 10_FullExpr.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\10_FullExpr_HussPiler\
	E:
	copy C:\CompilerOutput\10_FullExpr.exe
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