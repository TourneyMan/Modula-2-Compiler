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
loop_begin_5:
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 10
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
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_15
	jmp		loop_end_5
	jmp		end_if_15
else_15:
end_if_15:
	mov		EAX, [EBP + 48]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_16
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_16
	jmp		end_if_16
else_16:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_16:
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
	jmp		loop_begin_5
loop_end_5:
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
loop_begin_6:
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_12
	push	0
	jmp		rel_done_12
rel_true_12:
	push	1
rel_done_12:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_17
	jmp		loop_end_6
	jmp		end_if_17
else_17:
end_if_17:
	mov		EAX, [EBP + 48]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_18
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_18
	jmp		end_if_18
else_18:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_18:
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
	jmp		loop_begin_6
loop_end_6:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	44
Print endp
;=============== END PROCEDURE =============
