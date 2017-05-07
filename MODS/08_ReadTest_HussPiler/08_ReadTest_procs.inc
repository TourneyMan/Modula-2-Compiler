; These are all the procedures for 08_ReadTest.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 10
	push	EAX
	pop		EAX
	mov		[EBP + 12], EAX
	print	OFFSET str0 
	mov		EAX, [EBP + 12]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	print	OFFSET str1 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	mov		EAX, [EBP + 12]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str2 
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str3 
	mov		EAX, [EBP + 12]
	push	EAX
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	8
HussPiler_Main endp
;=============== END PROCEDURE =============
