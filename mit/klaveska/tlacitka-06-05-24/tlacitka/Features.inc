Display_Juza:	; inicializace digitu na displeji
	rcall display_units
	rcall init_Z_segment_display

	rcall display_tens
	rcall init_Z_segment_display

	rcall display_hundreds
	rcall init_Z_segment_display
	
	rcall display_thousands
	rcall init_Z_segment_display
ret

Higher:	; podprogram, ktery zapricini pocitani smerem nahoru
	ldi r16, 1
	com r16
	out portA,r16
	rcall SegmentUp
	ldi r16, 1
rjmp Main

Lower: 	; podprogram, ktery zapricini pocitani smerem dolu
	ldi r16, 2
	com r16
	out portA, r16	
	rcall SegmentDown
	ldi r16, 2
rjmp Main

Pause:					; podprogram, ktery zapricini
	ldi r16,4			; zastaveni na poslednim zobrazenem
	com r16				; cisle a vyckat na zavolani
	rcall Display_Juza	; Higher nebo Lower podprogramu
	out PortA, r16
	ldi r16, 4
rjmp Main

Off: 	; podprogram, ktery prakticky dela to stene jako LedOff
	ldi r16,5
	com r16
	in TmpReg, DispCtrlP	
	andi TmpReg, 0b11101111
	out	DispCtrlP, TmpReg
	out portA, r16
	ldi r16,5
rjmp Main

On: 	; podprogram, ktery prakticky dela to stene jako LedOn
	ldi r16,6
	com r16	
	in 	TmpReg, DispCtrlP
	andi TmpReg, 0b11110011
	ori TmpReg, 0b00010000
	out DispCtrlP, TmpReg
	rcall Display_Juza
	out portA, r16
	ldi r16,6
rjmp Main
