;*****************************
;co dela tento podprogram????
;*****************************
;
init_X_OutFlash:		;X = Output do FLASH pamìti
	ldi XH, high(2*End_Of_My_Numbers)
	ldi XL, low(2*End_Of_My_Numbers)
ret
