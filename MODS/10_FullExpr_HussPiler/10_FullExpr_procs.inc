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
loop_begin_10:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_40
	push	0
	jmp		rel_done_40
rel_true_40:
	push	1
rel_done_40:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_34
	jmp		loop_end_10
	jmp		end_if_34
else_34:
end_if_34:
	print	OFFSET str10 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_10
loop_end_10:
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
	jg		rel_true_41
	push	0
	jmp		rel_done_41
rel_true_41:
	push	1
rel_done_41:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_35
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_35
else_35:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_35:
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
	jg		rel_true_42
	push	0
	jmp		rel_done_42
rel_true_42:
	push	1
rel_done_42:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_36
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_36
else_36:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_36:
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
	jg		rel_true_43
	push	0
	jmp		rel_done_43
rel_true_43:
	push	1
rel_done_43:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_37
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_37
else_37:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_44
	push	0
	jmp		rel_done_44
rel_true_44:
	push	1
rel_done_44:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_38
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_38
else_38:
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
end_if_38:
end_if_37:
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
	jl		rel_true_45
	push	0
	jmp		rel_done_45
rel_true_45:
	push	1
rel_done_45:
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
	jge		rel_true_46
	push	0
	jmp		rel_done_46
rel_true_46:
	push	1
rel_done_46:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_14
	pop		EAX
	cmp		EAX, 0
	je		log_false_14
	push	1
	jmp		log_done_14
log_false_early_14:
	pop		EAX
log_false_14:
	push	0
log_done_14:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_39
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_39
else_39:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_47
	push	0
	jmp		rel_done_47
rel_true_47:
	push	1
rel_done_47:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_40
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_40
else_40:
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
end_if_40:
end_if_39:
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
	jg		rel_true_48
	push	0
	jmp		rel_done_48
rel_true_48:
	push	1
rel_done_48:
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
	jge		rel_true_49
	push	0
	jmp		rel_done_49
rel_true_49:
	push	1
rel_done_49:
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
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_41
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_41
else_41:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_50
	push	0
	jmp		rel_done_50
rel_true_50:
	push	1
rel_done_50:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_42
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_42
else_42:
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
end_if_42:
end_if_41:
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
	jg		rel_true_51
	push	0
	jmp		rel_done_51
rel_true_51:
	push	1
rel_done_51:
	mov		EAX, 10
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jne		rel_true_52
	push	0
	jmp		rel_done_52
rel_true_52:
	push	1
rel_done_52:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_16
	pop		EAX
	cmp		EAX, 1
	je		log_true_16
	push	0
	jmp		log_done_16
log_true_early_16:
	pop		EAX
log_true_16:
	push	1
log_done_16:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_43
	mov		EAX, 1111
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_43
else_43:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_53
	push	0
	jmp		rel_done_53
rel_true_53:
	push	1
rel_done_53:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_44
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_44
else_44:
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
end_if_44:
end_if_43:
	print	OFFSET str19 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_54
	push	0
	jmp		rel_done_54
rel_true_54:
	push	1
rel_done_54:
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
	je		rel_true_55
	push	0
	jmp		rel_done_55
rel_true_55:
	push	1
rel_done_55:
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
	jne		else_45
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_45
else_45:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_45:
	print	OFFSET str20 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_56
	push	0
	jmp		rel_done_56
rel_true_56:
	push	1
rel_done_56:
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
	jne		rel_true_57
	push	0
	jmp		rel_done_57
rel_true_57:
	push	1
rel_done_57:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_58
	push	0
	jmp		rel_done_58
rel_true_58:
	push	1
rel_done_58:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_18
	pop		EAX
	cmp		EAX, 0
	je		log_false_18
	push	1
	jmp		log_done_18
log_false_early_18:
	pop		EAX
log_false_18:
	push	0
log_done_18:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_19
	pop		EAX
	cmp		EAX, 1
	je		log_true_19
	push	0
	jmp		log_done_19
log_true_early_19:
	pop		EAX
log_true_19:
	push	1
log_done_19:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_46
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_46
else_46:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_46:
	print	OFFSET str21 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_59
	push	0
	jmp		rel_done_59
rel_true_59:
	push	1
rel_done_59:
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
	jne		rel_true_60
	push	0
	jmp		rel_done_60
rel_true_60:
	push	1
rel_done_60:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_20
	pop		EAX
	cmp		EAX, 0
	je		log_false_20
	push	1
	jmp		log_done_20
log_false_early_20:
	pop		EAX
log_false_20:
	push	0
log_done_20:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_61
	push	0
	jmp		rel_done_61
rel_true_61:
	push	1
rel_done_61:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_21
	pop		EAX
	cmp		EAX, 0
	je		log_false_21
	push	1
	jmp		log_done_21
log_false_early_21:
	pop		EAX
log_false_21:
	push	0
log_done_21:
	mov		EAX, 1
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_62
	push	0
	jmp		rel_done_62
rel_true_62:
	push	1
rel_done_62:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_22
	pop		EAX
	cmp		EAX, 1
	je		log_true_22
	push	0
	jmp		log_done_22
log_true_early_22:
	pop		EAX
log_true_22:
	push	1
log_done_22:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_47
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_47
else_47:
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_47:
	print	OFFSET str22 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_63
	push	0
	jmp		rel_done_63
rel_true_63:
	push	1
rel_done_63:
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
	jne		rel_true_64
	push	0
	jmp		rel_done_64
rel_true_64:
	push	1
rel_done_64:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_23
	pop		EAX
	cmp		EAX, 0
	je		log_false_23
	push	1
	jmp		log_done_23
log_false_early_23:
	pop		EAX
log_false_23:
	push	0
log_done_23:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_65
	push	0
	jmp		rel_done_65
rel_true_65:
	push	1
rel_done_65:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_24
	pop		EAX
	cmp		EAX, 0
	je		log_false_24
	push	1
	jmp		log_done_24
log_false_early_24:
	pop		EAX
log_false_24:
	push	0
log_done_24:
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
	je		rel_true_66
	push	0
	jmp		rel_done_66
rel_true_66:
	push	1
rel_done_66:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_25
	pop		EAX
	cmp		EAX, 1
	je		log_true_25
	push	0
	jmp		log_done_25
log_true_early_25:
	pop		EAX
log_true_25:
	push	1
log_done_25:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_48
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_48
else_48:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_48:
	print	OFFSET str23 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_67
	push	0
	jmp		rel_done_67
rel_true_67:
	push	1
rel_done_67:
	pop		EAX
	cmp		EAX, 1
	je		log_true_26
	push	1
	jmp		log_done_26
log_true_26:
	push	0
log_done_26:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_49
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_49
else_49:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_49:
	print	OFFSET str24 
	mov		EAX, 5
	push	EAX
	mov		EAX, 23
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_68
	push	0
	jmp		rel_done_68
rel_true_68:
	push	1
rel_done_68:
	pop		EAX
	cmp		EAX, 1
	je		log_true_27
	push	1
	jmp		log_done_27
log_true_27:
	push	0
log_done_27:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_50
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_50
else_50:
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_50:
	call	nwln
	print	OFFSET str25 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
loop_begin_11:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_69
	push	0
	jmp		rel_done_69
rel_true_69:
	push	1
rel_done_69:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_51
	jmp		loop_end_11
	jmp		end_if_51
else_51:
end_if_51:
	print	OFFSET str26 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_11
loop_end_11:
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
loop_begin_12:
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
	je		rel_true_70
	push	0
	jmp		rel_done_70
rel_true_70:
	push	1
rel_done_70:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_52
	jmp		loop_end_12
	jmp		end_if_52
else_52:
end_if_52:
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
	jmp		loop_begin_12
loop_end_12:
	call	nwln
	print	OFFSET str30 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
loop_begin_13:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_71
	push	0
	jmp		rel_done_71
rel_true_71:
	push	1
rel_done_71:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_53
	jmp		loop_end_13
	jmp		end_if_53
else_53:
end_if_53:
	print	OFFSET str31 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_13
loop_end_13:
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
loop_begin_14:
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
	je		rel_true_72
	push	0
	jmp		rel_done_72
rel_true_72:
	push	1
rel_done_72:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_54
	jmp		loop_end_14
	jmp		end_if_54
else_54:
end_if_54:
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 16], EAX
loop_begin_15:
	print	OFFSET str35 
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_73
	push	0
	jmp		rel_done_73
rel_true_73:
	push	1
rel_done_73:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_55
	jmp		loop_end_15
	jmp		end_if_55
else_55:
end_if_55:
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
	jmp		loop_begin_15
loop_end_15:
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
	jmp		loop_begin_14
loop_end_14:
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	20
HussPiler_Main endp
;=============== END PROCEDURE =============
