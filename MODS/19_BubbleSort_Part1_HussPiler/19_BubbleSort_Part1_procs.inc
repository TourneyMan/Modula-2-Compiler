; These are all the procedures for 19_BubbleSort_Part1.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	push	0
	mov		EAX, 44
	push	EAX
	mov		EAX, 40
	push	EAX
	mov		EAX, 36
	push	EAX
	mov		EAX, 32
	push	EAX
	mov		EAX, 28
	push	EAX
	mov		EAX, 24
	push	EAX
	mov		EAX, 20
	push	EAX
	mov		EAX, 16
	push	EAX
	mov		EAX, 12
	push	EAX
	mov		EAX, 8
	push	EAX
	call	Fill
	push	0
	mov		EAX, 44
	push	EAX
	mov		EAX, 40
	push	EAX
	mov		EAX, 36
	push	EAX
	mov		EAX, 32
	push	EAX
	mov		EAX, 28
	push	EAX
	mov		EAX, 24
	push	EAX
	mov		EAX, 20
	push	EAX
	mov		EAX, 16
	push	EAX
	mov		EAX, 12
	push	EAX
	mov		EAX, 8
	push	EAX
	call	Print
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	40
HussPiler_Main endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
Fill PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
loop_begin_24:
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_93
	push	0
	jmp		rel_done_93
rel_true_93:
	push	1
rel_done_93:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_77
	jmp		loop_end_24
	jmp		end_if_77
else_77:
end_if_77:
	mov		EAX, [EBP + 48]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_78
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_78
	jmp		end_if_78
else_78:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_78:
	pop		EAX
	sub		EAX, 1
	mov		EBX, 4
	imul	EBX
	add		EAX, 0
	push	EAX
	mov		EAX, [EBP + 48]
	push	EAX
	pop		EAX
	pop		ECX
	add		ECX, EBP
	add		ECX, 8
	mov		EBX, [ECX]
	add		EBX, 52
	mov		[EBP + EBX], EAX
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
	jmp		loop_begin_24
loop_end_24:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	44
Fill endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
Print PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
loop_begin_25:
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_94
	push	0
	jmp		rel_done_94
rel_true_94:
	push	1
rel_done_94:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_79
	jmp		loop_end_25
	jmp		end_if_79
else_79:
end_if_79:
	mov		EAX, [EBP + 48]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_80
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_80
	jmp		end_if_80
else_80:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_80:
	pop		EAX
	sub		EAX, 1
	mov		EBX, 4
	imul	EBX
	add		EAX, 0
	push	EAX
	pop		ECX
	add		ECX, EBP
	add		ECX, 8
	mov		EBX, [ECX]
	add		EBX, 52
	mov		EAX, [EBP + EBX]
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
	jmp		loop_begin_25
loop_end_25:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	44
Print endp
;=============== END PROCEDURE =============
