; HussPiler output for: 20_BubbleSort_Final.mod
; Created: Monday, May 8, 2017 2:31:35 AM

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤
	include C:\masm32\include\masm32rt.inc
; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

.stack 1000H

.data
	include 20_BubbleSort_Final_strings.inc	; all string literals

.code
	include 20_BubbleSort_Final_procs.inc	; all program procedures
	include helper.inc	; includes some helper functions for printing and debugging

start:

	cls
	sub	ESP,40	; Room for main proc local vars
	call HussPiler_Main
	inkey
	exit

end start