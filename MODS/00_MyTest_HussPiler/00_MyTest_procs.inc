; These are all the procedures for 00_MyTest.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	push	0
	push	0
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
	push	0
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
	call	Print
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	40
HussPiler_Main endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
Random PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EBX, [EBP + 8]
	add		EBX, 16
	mov		EAX, [EBP + EBX]
	push	EAX
	mov		EAX, 4361
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 3899
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	mov		EAX, 8192
	push	EAX
	mov		EDX, 0
	pop		ECX
	pop		EAX
	idiv	ECX
	push	EDX
	pop		EAX
	mov		[EBP + 12], EAX
	mov		EAX, [EBP + 12]
	push	EAX
	pop		EAX
	mov		 EBX, [EBP + 8]
	add		EBX, 16
	mov		[EBP + EBX], EAX
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	8
Random endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
Fill PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 29
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 52], EAX
loop_begin_2:
	mov		EAX, [EBP + 52]
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_3
	push	0
	jmp		rel_done_3
rel_true_3:
	push	1
rel_done_3:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_3
	jmp		loop_end_2
	jmp		end_if_3
else_3:
end_if_3:
	mov		EAX, [EBP + 52]
	push	EAX
	pop		EAX
	sub		EAX, 1
	mov		EBX, 4
	imul	EBX
	add		EAX, 0
	push	EAX
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 1000
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	pop		ECX
	add		ECX, EBP
	add		ECX, 8
	mov		EBX, [ECX]
	add		EBX, 56
	mov		[EBP + EBX], EAX
	push	0
	mov		EAX, 48
	push	EAX
	call	Random
	mov		EAX, [EBP + 52]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 52], EAX
	jmp		loop_begin_2
loop_end_2:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	48
Fill endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
Print PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
loop_begin_3:
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_4
	push	0
	jmp		rel_done_4
rel_true_4:
	push	1
rel_done_4:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_4
	jmp		loop_end_3
	jmp		end_if_4
else_4:
end_if_4:
	mov		EAX, [EBP + 48]
	push	EAX
	pop		EAX
	sub		EAX, 1
	mov		EBX, 4
	imul	EBX
	add		EAX, 0
	push	EAX
	pop		ECX
	add		ECX, EBP
	add		ECX, 8
	mov		EBX, [ECX]
	add		EBX, 52
	mov		EAX, [EBP + EBX]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
	jmp		loop_begin_3
loop_end_3:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	44
Print endp
;=============== END PROCEDURE =============
