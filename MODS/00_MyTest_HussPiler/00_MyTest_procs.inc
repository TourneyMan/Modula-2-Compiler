; These are all the procedures for 00_MyTest.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 11
	push	EAX
	pop		EAX
	mov		[EBP + 88], EAX
	mov		EAX, [EBP + 88]
	push	EAX
	pop		EAX
	sub		EAX, 11
	mov		EBX, 4
	imul	EBX
	add		EAX, 8
	push	EAX
	mov		EAX, [EBP + 88]
	push	EAX
	mov		EAX, [EBP + 88]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EAX
	pop		ECX
	mov		EDX, EBP
	add		ECX, EDX
	mov		[ECX], EAX
	mov		EAX, [EBP + 88]
	push	EAX
	pop		EAX
	sub		EAX, 11
	mov		EBX, 4
	imul	EBX
	add		EAX, 8
	push	EAX
	pop		ECX
	mov		EAX, [EBP + ECX]
	push	EAX
	pop		EAX
	print	str$(EAX)
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	92
HussPiler_Main endp
;=============== END PROCEDURE =============
