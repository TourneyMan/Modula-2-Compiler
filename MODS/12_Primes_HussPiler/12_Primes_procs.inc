; These are all the procedures for 12_Primes.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 2
	push	EAX
	pop		EAX
	mov		[EBP + 204], EAX
loop_begin_0:
	mov		EAX, [EBP + 204]
	push	EAX
	mov		EAX, 50
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
	mov		EAX, [EBP + 204]
	push	EAX
	pop		ECX
	push		ECX
	mov		EAX, 2 
	push		ECX
	cmp		EAX, ECX
	jg		else_1
	mov		EAX, 50 
	push		ECX
	cmp		EAX, ECX
	jl		else_1
	jmp		end_if_1
else_1:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_1:
	pop		EAX
	sub		EAX, 2
	mov		EBX, 4
	imul	EBX
	add		EAX, 8
	push	EAX
	mov		EAX, 0
	push	EAX
	pop		EAX
	pop		ECX
	mov		EDX, EBP
	add		ECX, EDX
	mov		[ECX], EAX
	mov		EAX, [EBP + 204]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 204], EAX
	jmp		loop_begin_0
loop_end_0:
	mov		EAX, 2
	push	EAX
	pop		EAX
	mov		[EBP + 212], EAX
loop_begin_1:
	mov		EAX, [EBP + 212]
	push	EAX
	mov		EAX, 8
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
	jne		else_2
	jmp		loop_end_1
	jmp		end_if_2
else_2:
end_if_2:
	mov		EAX, 2
	push	EAX
	pop		EAX
	mov		[EBP + 208], EAX
loop_begin_2:
	mov		EAX, [EBP + 208]
	push	EAX
	mov		EAX, [EBP + 212]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 50
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_2
	push	0
	jmp		rel_done_2
rel_true_2:
	push	1
rel_done_2:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_3
	jmp		loop_end_2
	jmp		end_if_3
else_3:
end_if_3:
	mov		EAX, [EBP + 208]
	push	EAX
	mov		EAX, [EBP + 212]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		ECX
	push		ECX
	mov		EAX, 2 
	push		ECX
	cmp		EAX, ECX
	jg		else_4
	mov		EAX, 50 
	push		ECX
	cmp		EAX, ECX
	jl		else_4
	jmp		end_if_4
else_4:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_4:
	pop		EAX
	sub		EAX, 2
	mov		EBX, 4
	imul	EBX
	add		EAX, 8
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EAX
	pop		ECX
	mov		EDX, EBP
	add		ECX, EDX
	mov		[ECX], EAX
	mov		EAX, [EBP + 208]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 208], EAX
	jmp		loop_begin_2
loop_end_2:
loop_begin_3:
	mov		EAX, [EBP + 212]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 212], EAX
	mov		EAX, [EBP + 212]
	push	EAX
	pop		ECX
	push		ECX
	mov		EAX, 2 
	push		ECX
	cmp		EAX, ECX
	jg		else_6
	mov		EAX, 50 
	push		ECX
	cmp		EAX, ECX
	jl		else_6
	jmp		end_if_6
else_6:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_6:
	pop		EAX
	sub		EAX, 2
	mov		EBX, 4
	imul	EBX
	add		EAX, 8
	push	EAX
	pop		ECX
	mov		EAX, [EBP + ECX]
	push	EAX
	mov		EAX, 0
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_3
	push	0
	jmp		rel_done_3
rel_true_3:
	push	1
rel_done_3:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_5
	jmp		loop_end_3
	jmp		end_if_5
else_5:
end_if_5:
	jmp		loop_begin_3
loop_end_3:
	jmp		loop_begin_1
loop_end_1:
	print	OFFSET str0 
	call	nwln
	mov		EAX, 2
	push	EAX
	pop		EAX
	mov		[EBP + 204], EAX
loop_begin_4:
	mov		EAX, [EBP + 204]
	push	EAX
	mov		EAX, 50
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
	jne		else_7
	jmp		loop_end_4
	jmp		end_if_7
else_7:
end_if_7:
	mov		EAX, [EBP + 204]
	push	EAX
	pop		ECX
	push		ECX
	mov		EAX, 2 
	push		ECX
	cmp		EAX, ECX
	jg		else_9
	mov		EAX, 50 
	push		ECX
	cmp		EAX, ECX
	jl		else_9
	jmp		end_if_9
else_9:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_9:
	pop		EAX
	sub		EAX, 2
	mov		EBX, 4
	imul	EBX
	add		EAX, 8
	push	EAX
	pop		ECX
	mov		EAX, [EBP + ECX]
	push	EAX
	mov		EAX, 0
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_5
	push	0
	jmp		rel_done_5
rel_true_5:
	push	1
rel_done_5:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_8
	mov		EAX, [EBP + 204]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_8
else_8:
end_if_8:
	mov		EAX, [EBP + 204]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 204], EAX
	jmp		loop_begin_4
loop_end_4:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	216
HussPiler_Main endp
;=============== END PROCEDURE =============
