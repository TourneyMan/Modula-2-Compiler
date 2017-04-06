; These are all the procedures for 00_MyTest.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	print	"OR test:             should be 24:          "
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jg		rel_true_0
	push	0
	jmp		rel_done_0
rel_true_0:
	push	1
rel_done_0:
	mov		EAX, 5
	push	EAX
	mov		EAX, 3
	push	EAX
	pop		ECX
	pop		EAX
	cmp		EAX, ECX
	jl		rel_true_1
	push	0
	jmp		rel_done_1
rel_true_1:
	push	1
rel_done_1:
	pop		EAX
	cmp		EAX, 1
	je		log_true_early_0
	pop		EAX
	cmp		EAX, 1
	je		log_true_0
	push	0
	jmp		log_done_0
log_true_early_0:
	pop		EAX
log_true_0:
	push	1
log_done_0:
	mov		EAX, 1
	pop		ECX
	cmp		EAX, ECX
	jne		else_0
	mov		EAX, 24
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
	jmp		end_if_0
else_0:
end_if_0:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	8
HussPiler_Main endp
;=============== END PROCEDURE =============
