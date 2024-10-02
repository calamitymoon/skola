; header file
Copy_Flash_2_SRAM:
	lpm r16, Z+
	ST Y+, R16
		inc maximalni_iterator_vnitrni_smycky
	cp  ZL, XL
	cpc ZH, XH
	brne Copy_Flash_2_SRAM
	dec maximalni_iterator_vnitrni_smycky
ret
