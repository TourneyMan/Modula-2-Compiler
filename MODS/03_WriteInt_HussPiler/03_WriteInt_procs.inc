; These are all the procedures for 03_WriteInt.mod. Main is first.

;============== BEGIN PROCEDURE ============
HussPiler_Main PROC	; Procedure definition
	push	EBP	; save EBP since we use it 
	mov	EBP,ESP
;~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~
	mov		EAX, 42
	push	EAX
	pop		EAX
	print	str$(EAX)
	call	nwln
;~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~
	mov	ESP,EBP
	pop	EBP
	ret	0
HussPiler_Main endp
;=============== END PROCEDURE =============
