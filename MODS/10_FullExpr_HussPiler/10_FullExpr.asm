; HussPiler output for: 10_FullExpr.mod
; Created: Wednesday, April 12, 2017 3:42:30 PM

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤
	include C:\masm32\include\masm32rt.inc
; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

.stack 1000H

.data
	include 10_FullExpr_strings.inc	; all string literals

.code
	include 10_FullExpr_procs.inc	; all program procedures
	include helper.inc	; includes some helper functions for printing and debugging

start:

	cls
	sub	ESP,28	; Room for main proc local vars
	call HussPiler_Main
	inkey
	exit

end start