; These are all the procedures for 17_Towers_Final.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	print	OFFSET str3 
	call	nwln
	print	OFFSET str4 
	mov		EAX, sval(input())
	push	EAX
	pop		EAX
	mov		[EBP + 8], EAX
	call	nwln
	call	nwln
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
	print	OFFSET str0 
	mov		EAX, [EBP + 12]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str1 
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EAX
	print	str$(EAX)
	print	OFFSET str2 
	call	nwln
	jmp		end_if_0
else_0:
	mov		EAX, 6
	push	EAX
	mov		EAX, [EBP + 12]
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	mov		EAX, [EBP + 8]
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	pop		EAX
	mov		[EBP + 20], EAX
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	mov		EAX, [EBP + 12]
	push	EAX
	mov		EAX, [EBP + 20]
	push	EAX
	call	TowersOfHanoi
	mov		EAX, 1
	push	EAX
	mov		EAX, [EBP + 12]
	push	EAX
	mov		EAX, [EBP + 8]
	push	EAX
	call	TowersOfHanoi
	mov		EAX, [EBP + 16]
	push	EAX
	mov		EAX, 1
	push	EAX
	pop		EBX
	pop		EAX
	sub		EAX, EBX
	push		EAX
	mov		EAX, [EBP + 20]
	push	EAX
	mov		EAX, [EBP + 8]
	push	EAX
	call	TowersOfHanoi
end_if_0:
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	16
TowersOfHanoi endp
;=============== END PROCEDURE =============
