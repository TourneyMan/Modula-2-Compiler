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
loop_begin_15:
	mov		EAX, [EBP + 88]
	push	EAX
	mov		EAX, 30
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_80
	push	0
	jmp		rel_done_80
rel_true_80:
	push	1
rel_done_80:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_56
	jmp		loop_end_15
	jmp		end_if_56
else_56:
end_if_56:
	mov		EAX, [EBP + 88]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 11 
	cmp		EAX, ECX
	jg		else_57
	mov		EAX, 30 
	cmp		EAX, ECX
	jl		else_57
	jmp		end_if_57
else_57:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_57:
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
	jmp		loop_begin_15
loop_end_15:
	mov		EAX, 11
	push	EAX
	pop		EAX
	mov		[EBP + 88], EAX
loop_begin_16:
	mov		EAX, [EBP + 88]
	push	EAX
	mov		EAX, 30
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_81
	push	0
	jmp		rel_done_81
rel_true_81:
	push	1
rel_done_81:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_58
	jmp		loop_end_16
	jmp		end_if_58
else_58:
end_if_58:
	mov		EAX, [EBP + 88]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str0 
	mov		EAX, [EBP + 88]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 11 
	cmp		EAX, ECX
	jg		else_59
	mov		EAX, 30 
	cmp		EAX, ECX
	jl		else_59
	jmp		end_if_59
else_59:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_59:
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
	jmp		loop_begin_16
loop_end_16:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	84
HussPiler_Main endp
;=============== END PROCEDURE =============
