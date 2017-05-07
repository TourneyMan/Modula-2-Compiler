; These are all the procedures for 00_MyTest.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 44
	push	EAX
	mov		EAX, 40
	push	EAX
	mov		EAX, 36
	push	EAX
	mov		EAX, 32
	push	EAX
	mov		EAX, 28
	push	EAX
	mov		EAX, 24
	push	EAX
	mov		EAX, 20
	push	EAX
	mov		EAX, 16
	push	EAX
	mov		EAX, 12
	push	EAX
	mov		EAX, 8
	push	EAX
	call	Fill
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	40
HussPiler_Main endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
Fill PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 1
	push	EAX
	pop		EAX
	sub		EAX, 1
	mov		EBX, 4
	imul	EBX
	add		EAX, 0
	push	EAX
	mov		EAX, 42
	push	EAX
	pop		EAX
	pop		ECX
	add		ECX, EBP
	add		ECX, 8
	mov		EBX, [ECX]
	add		EBX, 48
	mov		[EBP + EBX], EAX ;
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	40
Fill endp
;=============== END PROCEDURE =============
