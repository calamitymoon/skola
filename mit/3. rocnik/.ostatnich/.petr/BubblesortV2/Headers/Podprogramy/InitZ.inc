;*****************************
;co dela tento podprogram????
;*****************************
;p�e do FLASH pam�ti
init_Z_InFlash:			;Z = Input do FLASHpam�ti
	ldi ZH, high(2*My_Numbers)
	ldi ZL, low(2*My_Numbers)
ret
