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
loop_begin_11:
	mov		EAX, [EBP + 88]
	push	EAX
	mov		EAX, 30
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_58
	push	0
	jmp		rel_done_58
rel_true_58:
	push	1
rel_done_58:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_40
	jmp		loop_end_11
	jmp		end_if_40
else_40:
end_if_40:
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
	add		ECX, EBP
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
	jmp		loop_begin_11
loop_end_11:
	mov		EAX, 11
	push	EAX
	pop		EAX
	mov		[EBP + 88], EAX
loop_begin_12:
	mov		EAX, [EBP + 88]
	push	EAX
	mov		EAX, 30
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_59
	push	0
	jmp		rel_done_59
rel_true_59:
	push	1
rel_done_59:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_41
	jmp		loop_end_12
	jmp		end_if_41
else_41:
end_if_41:
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
	jmp		loop_begin_12
loop_end_12:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	84
HussPiler_Main endp
;=============== END PROCEDURE =============
