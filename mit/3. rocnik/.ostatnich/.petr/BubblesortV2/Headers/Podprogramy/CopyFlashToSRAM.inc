;*****************************
;co dela tento podprogram????
;*****************************;
;Kop�ruje data (��sla) z pam�ti FLASH do pam�ti SRAM
CopyFlash_to_SRAM:		;Kop�rvan� dat z Flash do SRAM
	lpm r16, Z+
	ST Y+, r16
	inc MAX
	cp ZL, XL
	cpc ZH, XH
	brne CopyFlash_to_SRAM
	dec MAX
ret
