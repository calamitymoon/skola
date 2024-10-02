SegmentDown:
	clr Number
	ldi r25, 1

	subi XL, 1		; odecte hodnotu 1 od registru XL
	sbc XH, ZeroReg		; odecte hodnotu reigstru ZeroReg (v tomto pripade 0) od registru XH a vezme v uvahu hodnotu prenosu z predchozi operace

	mov r24, XH		; presune obsah registru XH do registru r24
	mov r20, XL		; presune obsah registru XL do registru r20
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

		cp XL,r24		; porovna obsah registru XL s obsahem registru r24
		cpc XH,r20		; porovna obsah registru XH s obsahem registru r20 a vezme v uvahu i hodnotu prenosu z predchoziho porovnani (priznak 'carry')

		brne return2

		ldi XL, low(999)
		ldi XH, high(999)

return2:
ret

.exit
