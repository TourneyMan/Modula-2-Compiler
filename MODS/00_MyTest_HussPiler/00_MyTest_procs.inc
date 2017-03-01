; These are all the procedures for 00_MyTest.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
mov	EAX,	44
push	EAX
mov	EAX,	3
push	EAX
mov	EAX,	5
push	EAX
mov	EAX,	34
push	EAX
pop	EBX
pop	EAX
add	EAX,	EBX
push	EAX
pop	EBX
pop	EAX
add	EAX,	EBX
push	EAX
pop	EBX
pop	EAX
add	EAX,	EBX
push	EAX
pop	EAX
print	str$(EAX)
call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	8
HussPiler_Main endp
;=============== END PROCEDURE =============
