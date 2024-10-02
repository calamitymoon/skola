;++++++++++++++++++++++++++++;
;     DISASSAMBLE NUMBER     ;
;++++++++++++++++++++++++++++;

disassamble_number11:
	cpi r23,0
	breq disassamble_number3


;++++++++++++++++++++++++++++;
;    DISASSAMBLE NUMBER 2    ;
;++++++++++++++++++++++++++++;

disassamble_number2:	
	clr Accuracy
	ldi r19, high (4095)
	ldi r18, low (4095)
	cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
	cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
	brlo Hundreds12

	Thousands21:
		inc Accuracy
		sub r20, r18	; odecte obsah regisrtu r18 od obsahu registru r20 a vysledek se ulozi zpet do r20
		sbc r24, r19	; odecte obsah registru r19 od obsahu registru r24 a vezme v uvahu i hodnotu z predchozi operace a vysledek se ulozi do r24
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brsh Thousands21

	std Y+Thousands_Offset, Accuracy
	clr Accuracy

	Hundreds12:
		ldi r19, high (255)
		ldi r18, low (255)
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brlo Tens1

	Hundreds2:
		inc Accuracy
		sub r20, r18	; odecte obsah regisrtu r18 od obsahu registru r20 a vysledek ulozi zpet do r20
		sbc r24, r19	; odecte obsah registru r19 od obsahu registru r24 a vezme v uvahu i hodnotu z predchozi operace a vysledek se ulozi do r24
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brsh Hundreds2

	std Y+Hundreds_Offset, Accuracy
	clr Accuracy

	Tens1:	
		ldi r19, high (16)
		ldi r18, low (16)
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brlo Units122

	Tens121:
		inc Accuracy
		sub r20, r18	; odecte obsah regisrtu r18 od obsahu registru r20 a vysledek ulozi zpet do r20
		sbc r24, r19	; odecte obsah registru r19 od obsahu registru r24 a vezme v uvahu i hodnotu z predchozi operace a vysledek se ulozi do r24
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brsh Tens121
	
	std Y+Tens_Offset, Accuracy
	clr Accuracy
	
	Units122:
		ldi r19, high (1)
		ldi r18, low (1)
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brlo Done2

	Units12:
		inc Accuracy
		sub r20, r18	; odecte obsah regisrtu r18 od obsahu registru r20 a vysledek ulozi zpet do r20
		sbc r24, r19	; odecte obsah registru r19 od obsahu registru r24 a vezme v uvahu i hodnotu z predchozi operace a vysledek se ulozi do r24
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brsh Units12
	
	Done2:
	std Y+Units_Offset, Accuracy
ret

;++++++++++++++++++++++++++++++;
;     DISASSAMBLE NUMBER 3     ;
;++++++++++++++++++++++++++++++;

disassamble_number3:		
	clr Accuracy
	ldi r19, high (1000)
	ldi r18, low (1000)
	cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
	cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
	brlo Hundreds111

	Thousands11:
		inc Accuracy
		sub r20, r18	; odecte obsah regisrtu r18 od obsahu registru r20 a vysledek ulozi zpet do r20
		sbc r24, r19	; odecte obsah registru r19 od obsahu registru r24 a vezme v uvahu i hodnotu z predchozi operace a vysledek se ulozi do r24
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brsh Thousands11

	std Y+Thousands_Offset, Accuracy
	clr Accuracy

	Hundreds111:
		ldi r19, high (100)
		ldi r18, low (100)
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brlo Tens111

	Hundreds11:
		inc Accuracy
		sub r20, r18	; odecte obsah regisrtu r18 od obsahu registru r20 a vysledek ulozi zpet do r20
		sbc r24, r19	; odecte obsah registru r19 od obsahu registru r24 a vezme v uvahu i hodnotu z predchozi operace a vysledek se ulozi do r24
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
	brsh Hundreds11

	std Y+Hundreds_Offset, Accuracy
	clr Accuracy

	Tens111:	
		ldi r19, high (10)
		ldi r18, low (10)
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brlo Units111

	Tens11:
		inc Accuracy
		sub r20, r18	; odecte obsah regisrtu r18 od obsahu registru r20 a vysledek ulozi zpet do r20
		sbc r24, r19	; odecte obsah registru r19 od obsahu registru r24 a vezme v uvahu i hodnotu z predchozi operace a vysledek se ulozi do r24
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brsh Tens11
	
	std Y+Tens_Offset, Accuracy
	clr Accuracy
	
	Units111:
		ldi r19, high (1)
		ldi r18, low (1)
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brlo Done11

	Units11:
		inc Accuracy
		sub r20, r18	; odecte obsah regisrtu r18 od obsahu registru r20 a vysledek ulozi zpet do r20
		sbc r24, r19	; odecte obsah registru r19 od obsahu registru r24 a vezme v uvahu i hodnotu z predchozi operace a vysledek se ulozi do r24
		cp  r20, r18	; porovna obsah registru r20 s obsahem registru r18
		cpc  r24, r19	; porovna obsah registru r24 s obsahem registru r19 a vezme v uvahu i hodnotu z predchoziho porovnani (priznak 'carry')
		brsh Units11
	
	Done11:
	std Y+Units_Offset, Accuracy
ret

.exit
