; These are all the procedures for 00_MyTest.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 0
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_30
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_30
	jmp		end_if_30
else_30:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_30:
	pop		EAX
	sub		EAX, 1
	mov		EBX, 4
	imul	EBX
	add		EAX, 8
	push	EAX
	mov		EAX, 4
	push	EAX
	pop		EAX
	pop		ECX
	add		ECX, EBP
	mov		[ECX], EAX
	mov		EAX, 11
	push	EAX
	pop		ECX
	push	ECX
	mov		EAX, 1 
	cmp		EAX, ECX
	jg		else_31
	mov		EAX, 10 
	cmp		EAX, ECX
	jl		else_31
	jmp		end_if_31
else_31:
	print	"Run-time Error: Out of bounds index"
	call	nwln
end_if_31:
	pop		EAX
	sub		EAX, 1
	mov		EBX, 4
	imul	EBX
	add		EAX, 8
	push	EAX
	pop		ECX
	mov		EAX, [EBP + ECX]
	push	EAX
	pop		EAX
	print	str$(EAX)
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	40
HussPiler_Main endp
;=============== END PROCEDURE =============
