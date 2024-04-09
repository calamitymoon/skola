;***************************************
.include "../templateM16.inc"
;***************************************

;		< definitions >

.def selectedNumber = r16
.def Number = r17
.def Iterator = r18
;
.def thousandsCount = r1
.def hundredsCount = r7
.def tensCount = r25
.def unitsCount = r15
;
.equ thousandsOffset = 0
.equ hundredsOffset = 0
.equ tensOffset = 0
.equ unitsOffset = 0

.dseg
DISPLAY:	.byte	4 ; blok v SRAM
.cseg

;volne registry 25,23,15,13,11,09,07,05,03,01

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

adjustOffsetZ:
	rcall init_Z_seg ; vola podprogram, ktery inicializuje pametovy ukazatel Z
	add ZL, selectedNumber ; pricita hodnotu v registru selectedNumber k nizsimu bytu (ZL) registru Z
	adc ZH, ZeroReg ; pricita hodnotu v ZeroReg (nula) k vyssimu bytu (ZH) registru Z a zahrnuje i priznak prenosu z predchozi operace (pokud dojde k preteceni 'adc' prida 1 k vysledku operace ZH + ZeroReg
ret

showNumber:
    lpm Number, Z ; nacita hodnotu ze segmentu displeje (ulozeneho v pameti programu) do registru Number
    out DispDataP, Number ; zobrazi cislo
ret

print:
    rcall adjustOffsetZ ; vola podprogram, ktery upravuje offset od zakladni adresy v Z
    rcall showNumber ; vola podprogram, ktery zobrazuje cislo
ret

;		< disassmble >

disassemble:
;	THOUSANDS:
;	subi selectedNumber, 1000
;	inc thousandsCount
;	brsh THOUSANDS
		HUNDREDS:
		subi selectedNumber, 100
		inc hundredsCount
		cpi selectedNumber, 100
		brsh HUNDREDS
			TENS:
			inc tensCount
			subi selectedNumber, 10
				cpi selectedNumber, 10
			brsh TENS
				UNITS:
				inc unitsCount
				subi selectedNumber, 1
				cpi selectedNumber, 1
				brsh UNITS
ret

; ; ;

;save_thousands:
;	std Y+thousandsOffset, thousandsCount
;ret

save_hundrends:
	std Y+hundredsOffset, hundredsCount
ret

save_tens:
	std Y+tensOffset, tensCount
ret

save_units:
	std Y+unitsOffset, unitsCount
ret

; ; ;

;load_thousands:
;	ldd selectedNumber, Y+thousandsOffset
;ret

load_hundrends:
	ldd selectedNumber, Y+hundredsOffset
ret

load_tens:
	ldd selectedNumber, Y+tensOffset
ret

load_units:
	ldd selectedNumber, Y+unitsOffset
ret

; ; ;


;		< main >

Main:
;	ldi PDelReg, 255 ; zapise do registru PDelReg hodnotu 255, coz rozsviti vsechny led diody na displeji
	seg_led_pwr_on ; vola makro, ktere zapne led displej

	ldi selectedNumber, 255 ; upravim podle toho, jake cislo chci zobrazit
	rcall disassemble
	
	rcall load_hundrends
	rcall load_tens
	rcall load_units
;	innerLoop:
;		rcall print ;nacte znak ktery se ma zobrazit zobrazit cislici
	
	ldi PDelReg, 5
	rcall Delay1m
	digit_hundreds_ON ;zapne pozici stovek ;prepnout misto
  	rcall print ;nacte znak ktery se ma zobrazit zobrazit cislici

	ldi PDelReg, 5
	rcall Delay1m
	digit_tens_ON ;zapne pozici desitek ;prepnout misto
  	rcall print ;nacte znak ktery se ma zobrazit zobrazit cislici

	ldi PDelReg, 5
	rcall Delay1m
 	digit_units_ON ;zapne pozici jednotek ;prepnout misto
 	rcall print ;nacte znak ktery se ma zobrazit zobrazit cislici

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
