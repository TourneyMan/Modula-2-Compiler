; These are all the procedures for 11_Square.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 11
	push	EAX
	pop		EAX
	mov		[EBP + 88], EAX
loop_begin_0:
	mov		EAX, [EBP + 88]
	push	EAX
	mov		EAX, 30
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_0
	push	0
	jmp		rel_done_0
rel_true_0:
	push	1
rel_done_0:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_0
	jmp		loop_end_0
	jmp		end_if_0
else_0:
end_if_0:
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
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 88], EAX
	jmp		loop_begin_0
loop_end_0:
	mov		EAX, 11
	push	EAX
	pop		EAX
	mov		[EBP + 88], EAX
loop_begin_1:
	mov		EAX, [EBP + 88]
	push	EAX
	mov		EAX, 30
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_1
	push	0
	jmp		rel_done_1
rel_true_1:
	push	1
rel_done_1:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_1
	jmp		loop_end_1
	jmp		end_if_1
else_1:
end_if_1:
	mov		EAX, [EBP + 88]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str0 
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
	print	OFFSET str1 
	call	nwln
	mov		EAX, [EBP + 88]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 88], EAX
	jmp		loop_begin_1
loop_end_1:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	92
HussPiler_Main endp
;=============== END PROCEDURE =============
