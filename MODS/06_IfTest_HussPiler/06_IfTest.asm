; HussPiler output for: 06_IfTest.mod
; Created: Monday, May 8, 2017 2:24:02 AM

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤
	include C:\masm32\include\masm32rt.inc
; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

.stack 1000H

.data
	include 06_IfTest_strings.inc	; all string literals

.code
	include 06_IfTest_procs.inc	; all program procedures
	include helper.inc	; includes some helper functions for printing and debugging

start:

	cls
	sub	ESP,8	; Room for main proc local vars
	call HussPiler_Main
	inkey
	exit

end start