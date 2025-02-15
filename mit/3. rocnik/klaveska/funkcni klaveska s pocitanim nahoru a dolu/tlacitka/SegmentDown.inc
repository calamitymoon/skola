SegmentDown:
	clr Number
	ldi r25, 1

	subi XL, 1
	sbc XH, ZeroReg	

	mov r24, XH
	mov r20, XL 
	rcall init_Y_display
	rcall clear_display
	rcall disassamble_number
	rcall init_Z_segment_display

	Loop2:
		inc Number

		rcall display_units
		rcall init_Z_segment_display

		rcall display_tens
		rcall init_Z_segment_display

		rcall display_hundreds
		rcall init_Z_segment_display
	
		rcall display_thousands
		rcall init_Z_segment_display
		
		cpi Number, 30
		brne Loop2

		ldi r20, high(0)
		ldi r24, low(0)

		cp XL,r24
		cpc XH,r20

		brne return2

		ldi XL, low(999)
		ldi XH, high(999)

return2:
ret

.exit
