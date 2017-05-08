; These are all the procedures for 16_Towers_Part2.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	print	OFFSET str4 
	call	nwln
	print	OFFSET str5 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	push	0
	mov		EAX, [EBP + 8]
	push	EAX
	mov		EAX, 1
	push	EAX
	mov		EAX, 3
	push	EAX
	call	TowersOfHanoi
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	4
HussPiler_Main endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
TowersOfHanoi PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, [EBP + 8]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_88
	push	0
	jmp		rel_done_88
rel_true_88:
	push	1
rel_done_88:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_70
	mov		EAX, [EBP + 16]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str0 
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_70
else_70:
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str1 
	mov		EAX, [EBP + 16]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_70:
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, [EBP + 16]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_89
	push	0
	jmp		rel_done_89
rel_true_89:
	push	1
rel_done_89:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_71
	mov		EAX, [EBP + 16]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str2 
	mov		EAX, [EBP + 16]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_71
else_71:
	mov		EAX, [EBP + 16]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str3 
	mov		EAX, [EBP + 16]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
end_if_71:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	16
TowersOfHanoi endp
;=============== END PROCEDURE =============
