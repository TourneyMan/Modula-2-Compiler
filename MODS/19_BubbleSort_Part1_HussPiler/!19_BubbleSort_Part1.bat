@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\19_BubbleSort_Part1_HussPiler\
	if exist 19_BubbleSort_Part1.obj del 19_BubbleSort_Part1.obj
	if exist 19_BubbleSort_Part1.exe del 19_BubbleSort_Part1.exe

	if not exist 19_BubbleSort_Part1.mod copy E:\Documents\GitHub\HussPiler\MODS\19_BubbleSort_Part1.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\19_BubbleSort_Part1_HussPiler\

	C:\masm32\bin\ml /c /coff 19_BubbleSort_Part1.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 19_BubbleSort_Part1.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\19_BubbleSort_Part1_HussPiler\
	E:
	copy C:\CompilerOutput\19_BubbleSort_Part1.exe
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