; These are all the procedures for 10_FullExpr.mod. Main is first.

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
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	print	OFFSET str0 
	call	nwln
	print	OFFSET str1 
	call	nwln
	print	OFFSET str2 
	mov		EAX, 42
	push	EAX
	mov		EAX, 8
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
	mov		EAX, [EBP + 8]
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
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
loop_begin_4:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_23
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
	print	OFFSET str10 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_4
loop_end_4:
	cls
	print	OFFSET str11 
	call	nwln
	print	OFFSET str12 
	call	nwln
	print	OFFSET str13 
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
	jg		rel_true_24
	push	0
	jmp		rel_done_24
rel_true_24:
	push	1
rel_done_24:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_18
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_18
else_18:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_18:
	print	OFFSET str14 
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
	print	OFFSET str15 
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
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_27
	push	0
	jmp		rel_done_27
rel_true_27:
	push	1
rel_done_27:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_21
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_21
else_21:
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
end_if_21:
end_if_20:
	print	OFFSET str16 
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
	jl		rel_true_28
	push	0
	jmp		rel_done_28
rel_true_28:
	push	1
rel_done_28:
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
	jge		rel_true_29
	push	0
	jmp		rel_done_29
rel_true_29:
	push	1
rel_done_29:
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
	jne		else_22
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_22
else_22:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_30
	push	0
	jmp		rel_done_30
rel_true_30:
	push	1
rel_done_30:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_23
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_23
else_23:
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
end_if_23:
end_if_22:
	print	OFFSET str17 
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
	jg		rel_true_31
	push	0
	jmp		rel_done_31
rel_true_31:
	push	1
rel_done_31:
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
	jge		rel_true_32
	push	0
	jmp		rel_done_32
rel_true_32:
	push	1
rel_done_32:
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
	jne		else_24
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_24
else_24:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_33
	push	0
	jmp		rel_done_33
rel_true_33:
	push	1
rel_done_33:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_25
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_25
else_25:
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
end_if_25:
end_if_24:
	print	OFFSET str18 
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
	jg		rel_true_34
	push	0
	jmp		rel_done_34
rel_true_34:
	push	1
rel_done_34:
	mov		EAX, 10
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jne		rel_true_35
	push	0
	jmp		rel_done_35
rel_true_35:
	push	1
rel_done_35:
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
	jne		else_26
	mov		EAX, 1111
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_26
else_26:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_36
	push	0
	jmp		rel_done_36
rel_true_36:
	push	1
rel_done_36:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_27
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_27
else_27:
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
end_if_27:
end_if_26:
	print	OFFSET str19 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_37
	push	0
	jmp		rel_done_37
rel_true_37:
	push	1
rel_done_37:
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
	je		rel_true_38
	push	0
	jmp		rel_done_38
rel_true_38:
	push	1
rel_done_38:
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
	jne		else_28
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_28
else_28:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_28:
	print	OFFSET str20 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_39
	push	0
	jmp		rel_done_39
rel_true_39:
	push	1
rel_done_39:
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
	jne		rel_true_40
	push	0
	jmp		rel_done_40
rel_true_40:
	push	1
rel_done_40:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_41
	push	0
	jmp		rel_done_41
rel_true_41:
	push	1
rel_done_41:
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
	jne		else_29
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_29
else_29:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_29:
	print	OFFSET str21 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_42
	push	0
	jmp		rel_done_42
rel_true_42:
	push	1
rel_done_42:
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
	jne		rel_true_43
	push	0
	jmp		rel_done_43
rel_true_43:
	push	1
rel_done_43:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_12
	pop		EAX
	cmp		EAX, 0
	je		log_false_12
	push	1
	jmp		log_done_12
log_false_early_12:
	pop		EAX
log_false_12:
	push	0
log_done_12:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
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
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_13
	pop		EAX
	cmp		EAX, 0
	je		log_false_13
	push	1
	jmp		log_done_13
log_false_early_13:
	pop		EAX
log_false_13:
	push	0
log_done_13:
	mov		EAX, 1
	push	EAX
	mov		EAX, 2
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
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_14
	pop		EAX
	cmp		EAX, 1
	je		log_true_14
	push	0
	jmp		log_done_14
log_true_early_14:
	pop		EAX
log_true_14:
	push	1
log_done_14:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_30
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_30
else_30:
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_30:
	print	OFFSET str22 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_46
	push	0
	jmp		rel_done_46
rel_true_46:
	push	1
rel_done_46:
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
	jne		rel_true_47
	push	0
	jmp		rel_done_47
rel_true_47:
	push	1
rel_done_47:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_15
	pop		EAX
	cmp		EAX, 0
	je		log_false_15
	push	1
	jmp		log_done_15
log_false_early_15:
	pop		EAX
log_false_15:
	push	0
log_done_15:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_48
	push	0
	jmp		rel_done_48
rel_true_48:
	push	1
rel_done_48:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_16
	pop		EAX
	cmp		EAX, 0
	je		log_false_16
	push	1
	jmp		log_done_16
log_false_early_16:
	pop		EAX
log_false_16:
	push	0
log_done_16:
	mov		EAX, 12
	push	EAX
	mov		EAX, 2
	push	EAX
	mov		EAX, 6
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_49
	push	0
	jmp		rel_done_49
rel_true_49:
	push	1
rel_done_49:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_17
	pop		EAX
	cmp		EAX, 1
	je		log_true_17
	push	0
	jmp		log_done_17
log_true_early_17:
	pop		EAX
log_true_17:
	push	1
log_done_17:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_31
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_31
else_31:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_31:
	print	OFFSET str23 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_50
	push	0
	jmp		rel_done_50
rel_true_50:
	push	1
rel_done_50:
	pop		EAX
	cmp		EAX, 1
	je		log_true_18
	push	1
	jmp		log_done_18
log_true_18:
	push	0
log_done_18:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_32
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_32
else_32:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_32:
	print	OFFSET str24 
	mov		EAX, 5
	push	EAX
	mov		EAX, 23
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_51
	push	0
	jmp		rel_done_51
rel_true_51:
	push	1
rel_done_51:
	pop		EAX
	cmp		EAX, 1
	je		log_true_19
	push	1
	jmp		log_done_19
log_true_19:
	push	0
log_done_19:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_33
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_33
else_33:
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_33:
	call	nwln
	print	OFFSET str25 
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
	je		rel_true_52
	push	0
	jmp		rel_done_52
rel_true_52:
	push	1
rel_done_52:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_34
	jmp		loop_end_5
	jmp		end_if_34
else_34:
end_if_34:
	print	OFFSET str26 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_5
loop_end_5:
	cls
	print	OFFSET str27 
	call	nwln
	print	OFFSET str28 
	call	nwln
	call	nwln
	print	OFFSET str29 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	call	nwln
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
loop_begin_6:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_53
	push	0
	jmp		rel_done_53
rel_true_53:
	push	1
rel_done_53:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_35
	jmp		loop_end_6
	jmp		end_if_35
else_35:
end_if_35:
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
	print	OFFSET str30 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
loop_begin_7:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_54
	push	0
	jmp		rel_done_54
rel_true_54:
	push	1
rel_done_54:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_36
	jmp		loop_end_7
	jmp		end_if_36
else_36:
end_if_36:
	print	OFFSET str31 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_7
loop_end_7:
	cls
	print	OFFSET str32 
	call	nwln
	print	OFFSET str33 
	call	nwln
	call	nwln
	print	OFFSET str34 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 24], EAX
	call	nwln
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 20], EAX
loop_begin_8:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, [EBP + 24]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_55
	push	0
	jmp		rel_done_55
rel_true_55:
	push	1
rel_done_55:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_37
	jmp		loop_end_8
	jmp		end_if_37
else_37:
end_if_37:
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 16], EAX
loop_begin_9:
	print	OFFSET str35 
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_56
	push	0
	jmp		rel_done_56
rel_true_56:
	push	1
rel_done_56:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_38
	jmp		loop_end_9
	jmp		end_if_38
else_38:
end_if_38:
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
	jmp		loop_begin_9
loop_end_9:
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
	jmp		loop_begin_8
loop_end_8:
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	28
HussPiler_Main endp
;=============== END PROCEDURE =============
