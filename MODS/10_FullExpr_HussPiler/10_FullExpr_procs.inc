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
loop_begin_0:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_0
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
	print	OFFSET str10 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_0
loop_end_0:
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
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_1
else_1:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_1:
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
	jg		rel_true_2
	push	0
	jmp		rel_done_2
rel_true_2:
	push	1
rel_done_2:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_2
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_2
else_2:
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_2:
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
	jg		rel_true_3
	push	0
	jmp		rel_done_3
rel_true_3:
	push	1
rel_done_3:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_3
	mov		EAX, [EBP + 24]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_3
else_3:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_4
	push	0
	jmp		rel_done_4
rel_true_4:
	push	1
rel_done_4:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_4
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_4
else_4:
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
end_if_4:
end_if_3:
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
	jl		rel_true_5
	push	0
	jmp		rel_done_5
rel_true_5:
	push	1
rel_done_5:
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
	jge		rel_true_6
	push	0
	jmp		rel_done_6
rel_true_6:
	push	1
rel_done_6:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_0
	pop		EAX
	cmp		EAX, 0
	je		log_false_0
	push	1
	jmp		log_done_0
log_false_early_0:
	pop		EAX
log_false_0:
	push	0
log_done_0:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_5
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_5
else_5:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_7
	push	0
	jmp		rel_done_7
rel_true_7:
	push	1
rel_done_7:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_6
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_6
else_6:
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
end_if_6:
end_if_5:
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
	jg		rel_true_8
	push	0
	jmp		rel_done_8
rel_true_8:
	push	1
rel_done_8:
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
	jge		rel_true_9
	push	0
	jmp		rel_done_9
rel_true_9:
	push	1
rel_done_9:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_1
	pop		EAX
	cmp		EAX, 0
	je		log_false_1
	push	1
	jmp		log_done_1
log_false_early_1:
	pop		EAX
log_false_1:
	push	0
log_done_1:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_7
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_7
else_7:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_10
	push	0
	jmp		rel_done_10
rel_true_10:
	push	1
rel_done_10:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_8
	mov		EAX, [EBP + 20]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_8
else_8:
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
end_if_8:
end_if_7:
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
	jg		rel_true_11
	push	0
	jmp		rel_done_11
rel_true_11:
	push	1
rel_done_11:
	mov		EAX, 10
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jne		rel_true_12
	push	0
	jmp		rel_done_12
rel_true_12:
	push	1
rel_done_12:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_2
	pop		EAX
	cmp		EAX, 1
	je		log_true_2
	push	0
	jmp		log_done_2
log_true_early_2:
	pop		EAX
log_true_2:
	push	1
log_done_2:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_9
	mov		EAX, 1111
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_9
else_9:
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, 71
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jle		rel_true_13
	push	0
	jmp		rel_done_13
rel_true_13:
	push	1
rel_done_13:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_10
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_10
else_10:
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
end_if_10:
end_if_9:
	print	OFFSET str19 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_14
	push	0
	jmp		rel_done_14
rel_true_14:
	push	1
rel_done_14:
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
	je		rel_true_15
	push	0
	jmp		rel_done_15
rel_true_15:
	push	1
rel_done_15:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_3
	pop		EAX
	cmp		EAX, 1
	je		log_true_3
	push	0
	jmp		log_done_3
log_true_early_3:
	pop		EAX
log_true_3:
	push	1
log_done_3:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_11
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_11
else_11:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_11:
	print	OFFSET str20 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_16
	push	0
	jmp		rel_done_16
rel_true_16:
	push	1
rel_done_16:
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
	jne		rel_true_17
	push	0
	jmp		rel_done_17
rel_true_17:
	push	1
rel_done_17:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_18
	push	0
	jmp		rel_done_18
rel_true_18:
	push	1
rel_done_18:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_4
	pop		EAX
	cmp		EAX, 0
	je		log_false_4
	push	1
	jmp		log_done_4
log_false_early_4:
	pop		EAX
log_false_4:
	push	0
log_done_4:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_5
	pop		EAX
	cmp		EAX, 1
	je		log_true_5
	push	0
	jmp		log_done_5
log_true_early_5:
	pop		EAX
log_true_5:
	push	1
log_done_5:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_12
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_12
else_12:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_12:
	print	OFFSET str21 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_19
	push	0
	jmp		rel_done_19
rel_true_19:
	push	1
rel_done_19:
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
	jne		rel_true_20
	push	0
	jmp		rel_done_20
rel_true_20:
	push	1
rel_done_20:
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
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_21
	push	0
	jmp		rel_done_21
rel_true_21:
	push	1
rel_done_21:
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
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_22
	push	0
	jmp		rel_done_22
rel_true_22:
	push	1
rel_done_22:
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
	jne		else_13
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_13
else_13:
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_13:
	print	OFFSET str22 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_23
	push	0
	jmp		rel_done_23
rel_true_23:
	push	1
rel_done_23:
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
	jne		rel_true_24
	push	0
	jmp		rel_done_24
rel_true_24:
	push	1
rel_done_24:
	pop		EAX
	cmp		EAX, 0
	je		log_false_early_9
	pop		EAX
	cmp		EAX, 0
	je		log_false_9
	push	1
	jmp		log_done_9
log_false_early_9:
	pop		EAX
log_false_9:
	push	0
log_done_9:
	mov		EAX, 2
	push	EAX
	mov		EAX, 2
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_25
	push	0
	jmp		rel_done_25
rel_true_25:
	push	1
rel_done_25:
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
	je		rel_true_26
	push	0
	jmp		rel_done_26
rel_true_26:
	push	1
rel_done_26:
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
	jne		else_14
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_14
else_14:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_14:
	print	OFFSET str23 
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_27
	push	0
	jmp		rel_done_27
rel_true_27:
	push	1
rel_done_27:
	pop		EAX
	cmp		EAX, 1
	je		log_true_12
	push	1
	jmp		log_done_12
log_true_12:
	push	0
log_done_12:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_15
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_15
else_15:
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_15:
	print	OFFSET str24 
	mov		EAX, 5
	push	EAX
	mov		EAX, 23
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
	pop		EAX
	cmp		EAX, 1
	je		log_true_13
	push	1
	jmp		log_done_13
log_true_13:
	push	0
log_done_13:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_16
	mov		EAX, 9999
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_16
else_16:
	mov		EAX, 1
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_16:
	call	nwln
	print	OFFSET str25 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
loop_begin_1:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_29
	push	0
	jmp		rel_done_29
rel_true_29:
	push	1
rel_done_29:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_17
	jmp		loop_end_1
	jmp		end_if_17
else_17:
end_if_17:
	print	OFFSET str26 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_1
loop_end_1:
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
loop_begin_2:
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
	je		rel_true_30
	push	0
	jmp		rel_done_30
rel_true_30:
	push	1
rel_done_30:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_18
	jmp		loop_end_2
	jmp		end_if_18
else_18:
end_if_18:
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
	jmp		loop_begin_2
loop_end_2:
	call	nwln
	print	OFFSET str30 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
loop_begin_3:
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_31
	push	0
	jmp		rel_done_31
rel_true_31:
	push	1
rel_done_31:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_19
	jmp		loop_end_3
	jmp		end_if_19
else_19:
end_if_19:
	print	OFFSET str31 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	jmp		loop_begin_3
loop_end_3:
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
loop_begin_4:
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
	je		rel_true_32
	push	0
	jmp		rel_done_32
rel_true_32:
	push	1
rel_done_32:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_20
	jmp		loop_end_4
	jmp		end_if_20
else_20:
end_if_20:
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 16], EAX
loop_begin_5:
	print	OFFSET str35 
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_33
	push	0
	jmp		rel_done_33
rel_true_33:
	push	1
rel_done_33:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_21
	jmp		loop_end_5
	jmp		end_if_21
else_21:
end_if_21:
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
	jmp		loop_begin_5
loop_end_5:
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
	jmp		loop_begin_4
loop_end_4:
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	20
HussPiler_Main endp
;=============== END PROCEDURE =============
