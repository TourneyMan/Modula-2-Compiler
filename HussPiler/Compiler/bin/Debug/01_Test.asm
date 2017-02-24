; HussPiler output for: 01_Test.mod
; Created: Friday, February 24, 2017 3:21:13 PM

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤
	include C:\masm32\include\masm32rt.inc
; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

.stack 1000H

.data
	include 01_Test_strings.inc	; all string literals

.code
	include 01_Test_procs.inc	; all program procedures
	include helper.inc	; includes some helper functions for printing and debugging

start:

	cls
	sub	ESP,8	; Room for main proc local vars
	call HussPiler_Main
	inkey
	exit

end start