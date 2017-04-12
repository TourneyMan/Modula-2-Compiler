; These are all the procedures for 00_MyTest.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 30
	push	EAX
	pop		ECX
	push		ECX
	mov		EAX, 11 
	push		ECX
	cmp		EAX, ECX
	jg		else_13
	mov		EAX, 30 
	push		ECX
	cmp		EAX, ECX
	jl		else_13
	jmp		end_if_13
else_13:
	print	"Run-time Error: Out of bounds index"
end_if_13:
	pop		EAX
	sub		EAX, 11
	mov		EBX, 4
	imul	EBX
	add		EAX, 8
	push	EAX
	mov		EAX, 4
	push	EAX
	pop		EAX
	pop		ECX
	mov		EDX, EBP
	add		ECX, EDX
	mov		[ECX], EAX
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	92
HussPiler_Main endp
;=============== END PROCEDURE =============
