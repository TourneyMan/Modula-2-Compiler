; These are all the procedures for 20_BubbleSort_Final.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	push	0
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
	call	nwln
	push	0
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
	call	Sort
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
Swap PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EBX, [EBP + 12]
	add		EBX, 20
	mov		EAX, [EBP + EBX]
	push	EAX
	pop		EAX
	mov		[EBP + 16], EAX
	mov		EBX, [EBP + 8]
	add		EBX, 20
	mov		EAX, [EBP + EBX]
	push	EAX
	pop		EAX
	mov		 EBX, [EBP + 12]
	add		EBX, 20
	mov		[EBP + EBX], EAX
	mov		EAX, [EBP + 16]
	push	EAX
	pop		EAX
	mov		 EBX, [EBP + 8]
	add		EBX, 20
	mov		[EBP + EBX], EAX
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	12
Swap endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
Random PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EBX, [EBP + 8]
	add		EBX, 16
	mov		EAX, [EBP + EBX]
	push	EAX
	mov		EAX, 4361
	push	EAX
	pop		EBX
	pop		EAX
	imul	EBX
	push	EAX
	mov		EAX, 3899
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	mov		EAX, 8192
	push	EAX
	mov		EDX, 0
	pop		ECX
	pop		EAX
	idiv	ECX
	push	EDX
	pop		EAX
	mov		[EBP + 12], EAX
	mov		EAX, [EBP + 12]
	push	EAX
	pop		EAX
	mov		 EBX, [EBP + 8]
	add		EBX, 16
	mov		[EBP + EBX], EAX
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	8
Random endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
Fill PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 29
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 52], EAX
loop_begin_7:
	mov		EAX, [EBP + 52]
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_13
	push	0
	jmp		rel_done_13
rel_true_13:
	push	1
rel_done_13:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_19
	jmp		loop_end_7
	jmp		end_if_19
else_19:
end_if_19:
	mov		EAX, [EBP + 52]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_20
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_20
	jmp		end_if_20
else_20:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_20:
	pop		EAX
	sub		EAX, 1
	mov		EBX, 4
	imul	EBX
	add		EAX, 0
	push	EAX
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 1000
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	pop		ECX
	add		ECX, EBP
	add		ECX, 8
	mov		EBX, [ECX]
	add		EBX, 56
	mov		[EBP + EBX], EAX
	push	0
	mov		EAX, 48
	push	EAX
	call	Random
	mov		EAX, [EBP + 52]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 52], EAX
	jmp		loop_begin_7
loop_end_7:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	48
Fill endp
;=============== END PROCEDURE =============

;============== BEGIN PROCEDURE ============
Sort PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
loop_begin_8:
	mov		EAX, 0
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 52], EAX
loop_begin_9:
	mov		EAX, [EBP + 52]
	push	EAX
	mov		EAX, 9
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
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_21
	jmp		loop_end_9
	jmp		end_if_21
else_21:
end_if_21:
	mov		EAX, [EBP + 52]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_23
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_23
	jmp		end_if_23
else_23:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_23:
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
	add		EBX, 56
	mov		EAX, [EBP + EBX]
	push	EAX
	mov		EAX, [EBP + 52]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_24
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_24
	jmp		end_if_24
else_24:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_24:
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
	add		EBX, 56
	mov		EAX, [EBP + EBX]
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_15
	push	0
	jmp		rel_done_15
rel_true_15:
	push	1
rel_done_15:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_22
	push	0
	mov		EAX, [EBP + 52]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_25
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_25
	jmp		end_if_25
else_25:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_25:
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
	add		EBX, 56
	push	EBX
	mov		EAX, [EBP + 52]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_26
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_26
	jmp		end_if_26
else_26:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_26:
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
	add		EBX, 56
	push	EBX
	call	Swap
	mov		EAX, 1
	push	EAX
	pop		EAX
	mov		[EBP + 48], EAX
	jmp		end_if_22
else_22:
end_if_22:
	mov		EAX, [EBP + 52]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	add		EAX, EBX
	push	EAX
	pop		EAX
	mov		[EBP + 52], EAX
	jmp		loop_begin_9
loop_end_9:
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 0
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	je		rel_true_16
	push	0
	jmp		rel_done_16
rel_true_16:
	push	1
rel_done_16:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_27
	jmp		loop_end_8
	jmp		end_if_27
else_27:
end_if_27:
	jmp		loop_begin_8
loop_end_8:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	48
Sort endp
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
loop_begin_10:
	mov		EAX, [EBP + 48]
	push	EAX
	mov		EAX, 10
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_17
	push	0
	jmp		rel_done_17
rel_true_17:
	push	1
rel_done_17:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_28
	jmp		loop_end_10
	jmp		end_if_28
else_28:
end_if_28:
	mov		EAX, [EBP + 48]
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_29
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_29
	jmp		end_if_29
else_29:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_29:
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
	jmp		loop_begin_10
loop_end_10:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	44
Print endp
;=============== END PROCEDURE =============
