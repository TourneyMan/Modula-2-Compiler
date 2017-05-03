; These are all the procedures for 14_ProcTest.mod. Main is first.

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
	print	OFFSET str2 
	call	nwln
	mov		EAX, [EBP + 8]
	push	EAX
	call	little
	print	OFFSET str3 
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	4
HussPiler_Main endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
little PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str0 
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 4
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	4
little endp
;=============== END PROCEDURE =============
