@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\20_BubbleSort_Final_HussPiler\
	if exist 20_BubbleSort_Final.obj del 20_BubbleSort_Final.obj
	if exist 20_BubbleSort_Final.exe del 20_BubbleSort_Final.exe

	if not exist 20_BubbleSort_Final.mod copy E:\Documents\GitHub\HussPiler\MODS\20_BubbleSort_Final.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\20_BubbleSort_Final_HussPiler\

	C:\masm32\bin\ml /c /coff 20_BubbleSort_Final.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 20_BubbleSort_Final.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\20_BubbleSort_Final_HussPiler\
	E:
	copy C:\CompilerOutput\20_BubbleSort_Final.exe
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