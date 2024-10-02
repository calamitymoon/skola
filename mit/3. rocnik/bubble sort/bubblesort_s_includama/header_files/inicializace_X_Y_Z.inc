; header file
init_X:
	ldi XH, high(2*konecCisel)
	ldi XL, low(2*konecCisel)
ret

init_Y:
	ldi YH, high(muj_blok)
	ldi YL, low(muj_blok)
ret

init_Z:
	ldi ZH, high(2*tabulkaCisel)
	ldi ZL, low(2*tabulkaCisel)
ret
