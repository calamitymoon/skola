;***************************************
.include "../templateM16.inc"
;***************************************

;		< definitions >

.def selectedNumber = r16
.def Number = r17
.def Iterator = r18

;		< subprogram >

;***************************************
; zapne led display
LedOn:
		in 		TmpReg, DispCtrlP
		andi 	TmpReg, 0b11110011
		ori 	TmpReg, 0b00010000
		out 	DispCtrlP, TmpReg
		ret

;***************************************


init_Z_seg:
	ldi ZH, high (2* segment_display) ; nacita hodnotu do registru ZH, ktera bude obsahovat vyssi bit adresy dvakrat (segment_display)
	ldi ZL, low (2* segment_display) ; nacita hodnotu do registru ZL, ktera bude obsahovat nizsi bit adresy dvakrat (segment_display)
ret

loadNumber:
	rcall init_Z_seg ; vola podprogram, ktery inicializuje pametovy ukazatel Z
	add ZL, selectedNumber ; pricita hodnotu v registru selectedNumber k nizsimu bytu (ZL) registru Z
	adc ZH, ZeroReg ; pricita hodnotu v ZeroReg (nula) k vyssimu bytu (ZH) registru Z a zahrnuje i priznak prenosu z predchozi operace (pokud dojde k preteceni 'adc' prida 1 k vysledku operace ZH + ZeroReg
ret

showNumber:
    lpm Number, Z
    out DispDataP, Number
ret

print:
    rcall loadNumber ; volani podprogramu, ktery nacita cislo
    rcall showNumber ; volani podprogramu, ktery zobrazuje cislo
ret

;		< main >

Main:
	ldi PDelReg, 255 ; zapise do registru PDelReg hodnotu 255, coz rozsviti vsechny led diody na displeji
	seg_led_pwr_on ; volani makra, ktere zapne led displej
	ldi selectedNumber, 15 ; upravim podle toho, jake cislo chci zobrazit
	rcall Delay1m ; volani podprogramu, ktery donuti program pockat 1 ms
	rcall print ; volani podprogramu, ktery nacte a zobrazi cislo
	digit_units_ON ; volani makra, ktere 

rjmp Main

;		< table >

segment_display:
	.db	0b11000000, 0b11111001		; '0', '1'
	.db	0b10100100, 0b10110000		; '2', '3'
	.db	0b10011001, 0b10010010		; '4', '5'
	.db	0b10000010, 0b11111000		; '6', '7'
	.db	0b10000000, 0b10010000		; '8', '9'
	.db	0b10001000, 0b10000011		; 'A', 'B'
	.db	0b11000110, 0b10100001		; 'C', 'D'
	.db	0b10000110, 0b10001110		; 'E', 'F'
end_of_segment_display:
