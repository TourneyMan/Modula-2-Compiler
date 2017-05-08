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
loop_begin_17:
	mov		EAX, [EBP + 204]
	push	EAX
	mov		EAX, 50
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_82
	push	0
	jmp		rel_done_82
rel_true_82:
	push	1
rel_done_82:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_60
	jmp		loop_end_17
	jmp		end_if_60
else_60:
end_if_60:
	mov		EAX, [EBP + 204]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 2 
	cmp		EAX, ECX
	jg		else_61
	mov		EAX, 50 
	cmp		EAX, ECX
	jl		else_61
	jmp		end_if_61
else_61:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_61:
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
	add		ECX, EBP
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
	jmp		loop_begin_17
loop_end_17:
	mov		EAX, 2
	push	EAX
	pop		EAX
	mov		[EBP + 212], EAX
loop_begin_18:
	mov		EAX, [EBP + 212]
	push	EAX
	mov		EAX, 8
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_83
	push	0
	jmp		rel_done_83
rel_true_83:
	push	1
rel_done_83:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_62
	jmp		loop_end_18
	jmp		end_if_62
else_62:
end_if_62:
	mov		EAX, 2
	push	EAX
	pop		EAX
	mov		[EBP + 208], EAX
loop_begin_19:
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
	jg		rel_true_84
	push	0
	jmp		rel_done_84
rel_true_84:
	push	1
rel_done_84:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_63
	jmp		loop_end_19
	jmp		end_if_63
else_63:
end_if_63:
	mov		EAX, [EBP + 208]
	push	EAX
	mov		EAX, [EBP + 212]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 2 
	cmp		EAX, ECX
	jg		else_64
	mov		EAX, 50 
	cmp		EAX, ECX
	jl		else_64
	jmp		end_if_64
else_64:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_64:
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
	add		ECX, EBP
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
	jmp		loop_begin_19
loop_end_19:
loop_begin_20:
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
	push	ECX
	mov		EAX, 2 
	cmp		EAX, ECX
	jg		else_66
	mov		EAX, 50 
	cmp		EAX, ECX
	jl		else_66
	jmp		end_if_66
else_66:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_66:
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
	je		rel_true_85
	push	0
	jmp		rel_done_85
rel_true_85:
	push	1
rel_done_85:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_65
	jmp		loop_end_20
	jmp		end_if_65
else_65:
end_if_65:
	jmp		loop_begin_20
loop_end_20:
	jmp		loop_begin_18
loop_end_18:
	print	OFFSET str0 
	call	nwln
	mov		EAX, 2
	push	EAX
	pop		EAX
	mov		[EBP + 204], EAX
loop_begin_21:
	mov		EAX, [EBP + 204]
	push	EAX
	mov		EAX, 50
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_86
	push	0
	jmp		rel_done_86
rel_true_86:
	push	1
rel_done_86:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_67
	jmp		loop_end_21
	jmp		end_if_67
else_67:
end_if_67:
	mov		EAX, [EBP + 204]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 2 
	cmp		EAX, ECX
	jg		else_69
	mov		EAX, 50 
	cmp		EAX, ECX
	jl		else_69
	jmp		end_if_69
else_69:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_69:
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
	je		rel_true_87
	push	0
	jmp		rel_done_87
rel_true_87:
	push	1
rel_done_87:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_68
	mov		EAX, [EBP + 204]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_68
else_68:
end_if_68:
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
	jmp		loop_begin_21
loop_end_21:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	208
HussPiler_Main endp
;=============== END PROCEDURE =============
