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
loop_begin_11:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
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
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_41
	jmp		loop_end_11
	jmp		end_if_41
else_41:
end_if_41:
	print	OFFSET str10 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_11
loop_end_11:
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
	jg		rel_true_62
	push	0
	jmp		rel_done_62
rel_true_62:
	push	1
rel_done_62:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_42
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_42
else_42:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_42:
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
	jg		rel_true_63
	push	0
	jmp		rel_done_63
rel_true_63:
	push	1
rel_done_63:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_43
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_43
else_43:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_43:
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
	jg		rel_true_64
	push	0
	jmp		rel_done_64
rel_true_64:
	push	1
rel_done_64:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_44
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_44
else_44:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_65
	push	0
	jmp		rel_done_65
rel_true_65:
	push	1
rel_done_65:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_45
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_45
else_45:
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
end_if_45:
end_if_44:
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
	jl		rel_true_66
	push	0
	jmp		rel_done_66
rel_true_66:
	push	1
rel_done_66:
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
	jge		rel_true_67
	push	0
	jmp		rel_done_67
rel_true_67:
	push	1
rel_done_67:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_22
	pop		EAX
	cmp		EAX, 0
	je		log_false_22
	push	1
	jmp		log_done_22
log_false_early_22:
	pop		EAX
log_false_22:
	push	0
log_done_22:
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
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_68
	push	0
	jmp		rel_done_68
rel_true_68:
	push	1
rel_done_68:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_47
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_47
else_47:
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
end_if_47:
end_if_46:
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
	jg		rel_true_69
	push	0
	jmp		rel_done_69
rel_true_69:
	push	1
rel_done_69:
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
	jge		rel_true_70
	push	0
	jmp		rel_done_70
rel_true_70:
	push	1
rel_done_70:
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
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_71
	push	0
	jmp		rel_done_71
rel_true_71:
	push	1
rel_done_71:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_49
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_49
else_49:
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
end_if_49:
end_if_48:
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
	jg		rel_true_72
	push	0
	jmp		rel_done_72
rel_true_72:
	push	1
rel_done_72:
	mov		EAX, 10
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jne		rel_true_73
	push	0
	jmp		rel_done_73
rel_true_73:
	push	1
rel_done_73:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_24
	pop		EAX
	cmp		EAX, 1
	je		log_true_24
	push	0
	jmp		log_done_24
log_true_early_24:
	pop		EAX
log_true_24:
	push	1
log_done_24:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_50
	mov		EAX, 1111
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_50
else_50:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_74
	push	0
	jmp		rel_done_74
rel_true_74:
	push	1
rel_done_74:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_51
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_51
else_51:
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
end_if_51:
end_if_50:
	print	OFFSET str19 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_75
	push	0
	jmp		rel_done_75
rel_true_75:
	push	1
rel_done_75:
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
	je		rel_true_76
	push	0
	jmp		rel_done_76
rel_true_76:
	push	1
rel_done_76:
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
	jne		else_52
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_52
else_52:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_52:
	print	OFFSET str20 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_77
	push	0
	jmp		rel_done_77
rel_true_77:
	push	1
rel_done_77:
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
	jne		rel_true_78
	push	0
	jmp		rel_done_78
rel_true_78:
	push	1
rel_done_78:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_79
	push	0
	jmp		rel_done_79
rel_true_79:
	push	1
rel_done_79:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_26
	pop		EAX
	cmp		EAX, 0
	je		log_false_26
	push	1
	jmp		log_done_26
log_false_early_26:
	pop		EAX
log_false_26:
	push	0
log_done_26:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_27
	pop		EAX
	cmp		EAX, 1
	je		log_true_27
	push	0
	jmp		log_done_27
log_true_early_27:
	pop		EAX
log_true_27:
	push	1
log_done_27:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_53
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_53
else_53:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_53:
	print	OFFSET str21 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_80
	push	0
	jmp		rel_done_80
rel_true_80:
	push	1
rel_done_80:
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
	jne		rel_true_81
	push	0
	jmp		rel_done_81
rel_true_81:
	push	1
rel_done_81:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_28
	pop		EAX
	cmp		EAX, 0
	je		log_false_28
	push	1
	jmp		log_done_28
log_false_early_28:
	pop		EAX
log_false_28:
	push	0
log_done_28:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_82
	push	0
	jmp		rel_done_82
rel_true_82:
	push	1
rel_done_82:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_29
	pop		EAX
	cmp		EAX, 0
	je		log_false_29
	push	1
	jmp		log_done_29
log_false_early_29:
	pop		EAX
log_false_29:
	push	0
log_done_29:
	mov		EAX, 1
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_83
	push	0
	jmp		rel_done_83
rel_true_83:
	push	1
rel_done_83:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_30
	pop		EAX
	cmp		EAX, 1
	je		log_true_30
	push	0
	jmp		log_done_30
log_true_early_30:
	pop		EAX
log_true_30:
	push	1
log_done_30:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_54
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_54
else_54:
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_54:
	print	OFFSET str22 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_84
	push	0
	jmp		rel_done_84
rel_true_84:
	push	1
rel_done_84:
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
	jne		rel_true_85
	push	0
	jmp		rel_done_85
rel_true_85:
	push	1
rel_done_85:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_31
	pop		EAX
	cmp		EAX, 0
	je		log_false_31
	push	1
	jmp		log_done_31
log_false_early_31:
	pop		EAX
log_false_31:
	push	0
log_done_31:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_86
	push	0
	jmp		rel_done_86
rel_true_86:
	push	1
rel_done_86:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_32
	pop		EAX
	cmp		EAX, 0
	je		log_false_32
	push	1
	jmp		log_done_32
log_false_early_32:
	pop		EAX
log_false_32:
	push	0
log_done_32:
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
	je		rel_true_87
	push	0
	jmp		rel_done_87
rel_true_87:
	push	1
rel_done_87:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_33
	pop		EAX
	cmp		EAX, 1
	je		log_true_33
	push	0
	jmp		log_done_33
log_true_early_33:
	pop		EAX
log_true_33:
	push	1
log_done_33:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_55
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_55
else_55:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_55:
	print	OFFSET str23 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_88
	push	0
	jmp		rel_done_88
rel_true_88:
	push	1
rel_done_88:
	pop		EAX
	cmp		EAX, 1
	je		log_true_34
	push	1
	jmp		log_done_34
log_true_34:
	push	0
log_done_34:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_56
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_56
else_56:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_56:
	print	OFFSET str24 
	mov		EAX, 5
	push	EAX
	mov		EAX, 23
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_89
	push	0
	jmp		rel_done_89
rel_true_89:
	push	1
rel_done_89:
	pop		EAX
	cmp		EAX, 1
	je		log_true_35
	push	1
	jmp		log_done_35
log_true_35:
	push	0
log_done_35:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_57
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_57
else_57:
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_57:
	call	nwln
	print	OFFSET str25 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
loop_begin_12:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_90
	push	0
	jmp		rel_done_90
rel_true_90:
	push	1
rel_done_90:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_58
	jmp		loop_end_12
	jmp		end_if_58
else_58:
end_if_58:
	print	OFFSET str26 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_12
loop_end_12:
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
loop_begin_13:
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
	je		rel_true_91
	push	0
	jmp		rel_done_91
rel_true_91:
	push	1
rel_done_91:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_59
	jmp		loop_end_13
	jmp		end_if_59
else_59:
end_if_59:
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
	jmp		loop_begin_13
loop_end_13:
	call	nwln
	print	OFFSET str30 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
loop_begin_14:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_92
	push	0
	jmp		rel_done_92
rel_true_92:
	push	1
rel_done_92:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_60
	jmp		loop_end_14
	jmp		end_if_60
else_60:
end_if_60:
	print	OFFSET str31 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_14
loop_end_14:
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
loop_begin_15:
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
	je		rel_true_93
	push	0
	jmp		rel_done_93
rel_true_93:
	push	1
rel_done_93:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_61
	jmp		loop_end_15
	jmp		end_if_61
else_61:
end_if_61:
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 16], EAX
loop_begin_16:
	print	OFFSET str35 
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_94
	push	0
	jmp		rel_done_94
rel_true_94:
	push	1
rel_done_94:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_62
	jmp		loop_end_16
	jmp		end_if_62
else_62:
end_if_62:
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
	jmp		loop_begin_16
loop_end_16:
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
	jmp		loop_begin_15
loop_end_15:
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	28
HussPiler_Main endp
;=============== END PROCEDURE =============
