; These are all the procedures for 04_WriteVar.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
mov	EAX,	32
push	EAX
pop	EAX
mov	[EBP + 8],	EAX
mov	EAX,	[EBP + 8]
push	EAX
pop	EAX
print	str$(EAX)
call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	12
HussPiler_Main endp
;=============== END PROCEDURE =============
