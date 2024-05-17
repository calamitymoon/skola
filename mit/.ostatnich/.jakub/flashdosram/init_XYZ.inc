;***************************************
;     	Inicializátory Ukazatelù
;_______________________________________
init_x: ;inicializuj x, points X pointer to the end of number table
	ldi Xh, high(2*konec_tabulky)
	ldi Xl, low(2*konec_tabulky)
ret

init_y: ;inicializuj y
	ldi Yh,high(muj_blok)
	ldi Yl,low(muj_blok)
ret

init_z: ;inicializuj z, points Z pointer to the start of number table
	ldi Zh, high(2*moje_tabulka) 
	ldi Zl, low(2*moje_tabulka)
ret
;****************************************
