; These are all the procedures for 07_LoopTest.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 10
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 12], EAX
loop_begin_4:
	mov		EAX, [EBP + 12]
	push	EAX
	mov		EAX, [EBP + 8]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_23
	push	0
	jmp		rel_done_23
rel_true_23:
	push	1
rel_done_23:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_17
	jmp		loop_end_4
	jmp		end_if_17
else_17:
end_if_17:
	mov		EAX, [EBP + 12]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	mov		EAX, [EBP + 12]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 12], EAX
	jmp		loop_begin_4
loop_end_4:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	16
HussPiler_Main endp
;=============== END PROCEDURE =============
