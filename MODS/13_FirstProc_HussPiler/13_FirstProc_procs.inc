; These are all the procedures for 13_FirstProc.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 3
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	print	OFFSET str1 
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	call	little
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	12
HussPiler_Main endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
little PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	print	OFFSET str0 
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	8
little endp
;=============== END PROCEDURE =============
