;===========================================================;
;						  KEYBINDS  						;
;===========================================================;

; 1 => spusti odcitani
; 2 => spusti pricitani
; 3 => zastavi pricitani/odcitani
; 7 => vypne displej
; 8 => zapne displej

;===========================================================;
;						  INCLUDES  						;
;===========================================================;

.include "M16.inc"
.include "LedOn.inc"
.include "Scan.inc"
.include "Delay.inc"
.include "SegmentUp.inc"
.include "SegmentDown.inc"
.include "Disassemble.inc"
.include "Features.inc"

;===========================================================;
;							MAIN							;
;===========================================================;

Main:
	ldi PDelReg, 200

	Main10:
		clr	Key					; nastavi promennou Key na hodnotu nula

		rcall Scan				; vola podprogram Scan; tento podprogram cte vstupy/vstupni hodnoty (stisknute klavesy) a uklada je do promenny Key
		com Key					; invertuje obsah promenne Key
		
		ldi TmpReg,0b00010001	; nacte do registru TmpReg hodnotu 0b00010001
		and TmpReg,Key			; bitovy logicky soucin mezi obsahem registru TmpReg a promennou Key
		breq Higher				; pokud vysledek bitoveho soucinu je nulovy, tak skoci podprogram Higher

		ldi TmpReg,0b00010010
		and TmpReg,Key
		breq Lower

		ldi TmpReg,0b00010100
		and TmpReg,Key
		breq Pause

		ldi TmpReg,0b00100001
		and TmpReg,Key
		breq Off
		
		ldi TmpReg,0b00100010
		and TmpReg,Key
		breq On

;	------------------------------------------------
		
		cpi r16,1	; pokud se r16 rovna 1, tak
		breq Higher ; spustit podprogram Higher

		cpi r16,2	; pokud se r16 rovna 2, tak
		breq Lower	; spustit podprogram Lower

		cpi r16,4	; pokud se r16 rovna 4, tak
		breq Pause	; spustit podprogram Pause

		cpi r16,5	; pokud se r16 rovna 5, tak
		breq Off	; spustit podprogram Off

		cpi r16,6	; pokud se r16 rovna 6, tak
		breq On		; spustit podprogram On
		
rjmp Main10		


