;*****************************
;co dela tento podprogram????
;*****************************;
;Kopíruje data (èísla) z pamìti FLASH do pamìti SRAM
CopyFlash_to_SRAM:		;Kopírvaní dat z Flash do SRAM
	lpm r16, Z+
	ST Y+, r16
	inc MAX
	cp ZL, XL
	cpc ZH, XH
	brne CopyFlash_to_SRAM
	dec MAX
ret
