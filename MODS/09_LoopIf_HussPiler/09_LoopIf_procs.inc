; These are all the procedures for 09_LoopIf.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 42
	push	EAX
	mov		EAX, 7
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	mov		EAX, 31
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	mov		EAX, 14
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	pop		EAX
	mov		[EBP + 16], EAX
	print	OFFSET str0 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
loop_begin_5:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_24
	push	0
	jmp		rel_done_24
rel_true_24:
	push	1
rel_done_24:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_18
	jmp		loop_end_5
	jmp		end_if_18
else_18:
end_if_18:
	print	OFFSET str1 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_5
loop_end_5:
	cls
	print	OFFSET str2 
	mov		EAX, 42
	push	EAX
	mov		EAX, 7
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	mov		EAX, 31
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	print	OFFSET str3 
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	print	OFFSET str4 
	mov		EAX, 42000
	push	EAX
	mov		EAX, 4200
	push	EAX
	mov		EDX, 0
	pop		ECX
	pop		EAX
	idiv	ECX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	print	OFFSET str5 
	mov		EAX, 42042
	push	EAX
	mov		EAX, 100
	push	EAX
	mov		EDX, 0
	pop		ECX
	pop		EAX
	idiv	ECX
	push	EDX
	pop		EAX
	print	str$(EAX)
	call	nwln
	print	OFFSET str6 
	mov		EAX, 20000
	push	EAX
	mov		EAX, 21000
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	print	OFFSET str7 
	mov		EAX, 6
	push	EAX
	mov		EAX, 7
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 2
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	print	OFFSET str8 
	mov		EAX, 6
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 1
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	mov		EAX, 2
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	call	nwln
	print	OFFSET str9 
	mov		EAX, 4
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	mov		EAX, 3
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_25
	push	0
	jmp		rel_done_25
rel_true_25:
	push	1
rel_done_25:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_19
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_19
else_19:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_19:
	print	OFFSET str10 
	mov		EAX, 4
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	mov		EAX, 17
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_26
	push	0
	jmp		rel_done_26
rel_true_26:
	push	1
rel_done_26:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_20
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_20
else_20:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_20:
	print	OFFSET str11 
	mov		EAX, 4
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	mov		EAX, 71
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_27
	push	0
	jmp		rel_done_27
rel_true_27:
	push	1
rel_done_27:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_21
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_21
else_21:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_28
	push	0
	jmp		rel_done_28
rel_true_28:
	push	1
rel_done_28:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_22
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_22
else_22:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 10000
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_22:
end_if_21:
	call	nwln
	print	OFFSET str12 
	mov		EAX, 4
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	mov		EAX, 71
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_29
	push	0
	jmp		rel_done_29
rel_true_29:
	push	1
rel_done_29:
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jge		rel_true_30
	push	0
	jmp		rel_done_30
rel_true_30:
	push	1
rel_done_30:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_6
	pop		EAX
	cmp		EAX, 0
	je		log_false_6
	push	1
	jmp		log_done_6
log_false_early_6:
	pop		EAX
log_false_6:
	push	0
log_done_6:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_23
	mov		EAX, 21
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_23
else_23:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_31
	push	0
	jmp		rel_done_31
rel_true_31:
	push	1
rel_done_31:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_24
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_24
else_24:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 10000
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_24:
end_if_23:
	print	OFFSET str13 
	mov		EAX, 4
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	mov		EAX, 71
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_32
	push	0
	jmp		rel_done_32
rel_true_32:
	push	1
rel_done_32:
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jge		rel_true_33
	push	0
	jmp		rel_done_33
rel_true_33:
	push	1
rel_done_33:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_7
	pop		EAX
	cmp		EAX, 0
	je		log_false_7
	push	1
	jmp		log_done_7
log_false_early_7:
	pop		EAX
log_false_7:
	push	0
log_done_7:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_25
	mov		EAX, 22
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_25
else_25:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_34
	push	0
	jmp		rel_done_34
rel_true_34:
	push	1
rel_done_34:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_26
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_26
else_26:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 10000
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_26:
end_if_25:
	call	nwln
	print	OFFSET str14 
	mov		EAX, 4
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	mov		EAX, 71
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_35
	push	0
	jmp		rel_done_35
rel_true_35:
	push	1
rel_done_35:
	mov		EAX, 10
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jne		rel_true_36
	push	0
	jmp		rel_done_36
rel_true_36:
	push	1
rel_done_36:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_8
	pop		EAX
	cmp		EAX, 1
	je		log_true_8
	push	0
	jmp		log_done_8
log_true_early_8:
	pop		EAX
log_true_8:
	push	1
log_done_8:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_27
	mov		EAX, 1111
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_27
else_27:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_37
	push	0
	jmp		rel_done_37
rel_true_37:
	push	1
rel_done_37:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_28
	mov		EAX, 23
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_28
else_28:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 10000
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_28:
end_if_27:
	print	OFFSET str15 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_38
	push	0
	jmp		rel_done_38
rel_true_38:
	push	1
rel_done_38:
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_39
	push	0
	jmp		rel_done_39
rel_true_39:
	push	1
rel_done_39:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_9
	pop		EAX
	cmp		EAX, 1
	je		log_true_9
	push	0
	jmp		log_done_9
log_true_early_9:
	pop		EAX
log_true_9:
	push	1
log_done_9:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_29
	mov		EAX, 24
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_29
else_29:
end_if_29:
	print	OFFSET str16 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_40
	push	0
	jmp		rel_done_40
rel_true_40:
	push	1
rel_done_40:
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jne		rel_true_41
	push	0
	jmp		rel_done_41
rel_true_41:
	push	1
rel_done_41:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_42
	push	0
	jmp		rel_done_42
rel_true_42:
	push	1
rel_done_42:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_10
	pop		EAX
	cmp		EAX, 0
	je		log_false_10
	push	1
	jmp		log_done_10
log_false_early_10:
	pop		EAX
log_false_10:
	push	0
log_done_10:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_11
	pop		EAX
	cmp		EAX, 1
	je		log_true_11
	push	0
	jmp		log_done_11
log_true_early_11:
	pop		EAX
log_true_11:
	push	1
log_done_11:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_30
	mov		EAX, 25
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_30
else_30:
end_if_30:
	call	nwln
	print	OFFSET str17 
	call	nwln
	mov		EAX, 10
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
loop_begin_6:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_43
	push	0
	jmp		rel_done_43
rel_true_43:
	push	1
rel_done_43:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_31
	jmp		loop_end_6
	jmp		end_if_31
else_31:
end_if_31:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
	jmp		loop_begin_6
loop_end_6:
	call	nwln
	print	OFFSET str18 
	call	nwln
	mov		EAX, 10
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
loop_begin_7:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_44
	push	0
	jmp		rel_done_44
rel_true_44:
	push	1
rel_done_44:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_32
	jmp		loop_end_7
	jmp		end_if_32
else_32:
end_if_32:
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 16], EAX
loop_begin_8:
	print	OFFSET str19 
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_45
	push	0
	jmp		rel_done_45
rel_true_45:
	push	1
rel_done_45:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_33
	jmp		loop_end_8
	jmp		end_if_33
else_33:
end_if_33:
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 16], EAX
	jmp		loop_begin_8
loop_end_8:
	call	nwln
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
	jmp		loop_begin_7
loop_end_7:
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	20
HussPiler_Main endp
;=============== END PROCEDURE =============
