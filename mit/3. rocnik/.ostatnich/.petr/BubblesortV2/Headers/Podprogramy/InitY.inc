;*****************************
;co dela tento podprogram????
;*****************************
;
init_Y_SRAM:			;Y = SRAM pamÏù
	ldi YH, high(MyBlock)
	ldi YL, low(MyBlock)
ret
