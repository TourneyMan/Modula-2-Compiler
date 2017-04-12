@echo off

	Color B

	cd E:\Documents\GitHub\HussPiler\MODS\12_Primes_HussPiler\
	if exist 12_Primes.obj del 12_Primes.obj
	if exist 12_Primes.exe del 12_Primes.exe

	if not exist 12_Primes.mod copy E:\Documents\GitHub\HussPiler\MODS\12_Primes.mod

	cd C:\
	C:

	if exist C:\CompilerOutput rmdir CompilerOutput /s /q
	mkdir CompilerOutput

	cd CompilerOutput

	copy E:\Documents\GitHub\HussPiler\MODS\12_Primes_HussPiler\

	C:\masm32\bin\ml /c /coff 12_Primes.asm
	if errorlevel 1 goto errasm

	C:\masm32\bin\polink /SUBSYSTEM:CONSOLE 12_Primes.obj
	if errorlevel 1 goto errlink

	cd E:\Documents\GitHub\HussPiler\MODS\12_Primes_HussPiler\
	E:
	copy C:\CompilerOutput\12_Primes.exe
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