;*****************************
;co dela tento podprogram????
;*****************************
;píše do FLASH pamìti
init_Z_InFlash:			;Z = Input do FLASHpamìti
	ldi ZH, high(2*My_Numbers)
	ldi ZL, low(2*My_Numbers)
ret
