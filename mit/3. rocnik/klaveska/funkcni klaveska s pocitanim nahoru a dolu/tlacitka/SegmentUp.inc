.def Number = r16
.def Accuracy = r17

.equ Thousands = 0
.equ Hundreds = 1
.equ Tens = 2
.equ Units = 3

.dseg
	disp: .byte 4
.cseg

;****************************************************

init_Y_display:
	ldi YL, low(disp)
	ldi YH, high(disp)
ret

init_Z_segment_display:
	ldi ZL, low(2*segment_display)
	ldi ZH, high(2*segment_display)
ret

init_X_end_of_segment_display:
	ldi XL,low(2*end_of_segment_display)
	ldi XH,high(2*end_of_segment_display)
ret
;***************************************************

clear_display:
	std Y+Thousands, ZeroReg
	std Y+Hundreds, ZeroReg
	std Y+Tens, ZeroReg
	std Y+Units, ZeroReg	
ret

;******************************************************

disassamble_number:
	clr Accuracy
	ldi r19, high (4095)
	ldi r18, low (4095)
	cp  r20, r18
	cpc  r24, r19
	brlo Hundreds1

	Thousands2:
		inc Accuracy
		sub r20, r18
		sbc r24, r19
		cp  r20, r18
		cpc  r24, r19
		brsh Thousands2

	std Y+Thousands, Accuracy
	clr Accuracy

	Hundreds1:
		ldi r19, high (255)
		ldi r18, low (255)
		cp  r20, r18
		cpc  r24, r19
		brlo Tens12

	Hundreds221:
		inc Accuracy
		sub r20, r18
		sbc r24, r19
		cp  r20, r18
		cpc  r24, r19
	brsh Hundreds221

	std Y+Hundreds, Accuracy
	clr Accuracy

	Tens12:
		ldi r19, high (16)
		ldi r18, low (16)
		cp  r20, r18
		cpc  r24, r19
		brlo Units1

	Tens212:
		inc Accuracy
		sub r20, r18
		sbc r24, r19
		cp  r20, r18
		cpc  r24, r19
		brsh Tens212
	
	std Y+Tens, Accuracy
	clr Accuracy
	
	Units1:
		ldi r19, high (1)
		ldi r18, low (1)
		cp  r20, r18
		cpc  r24, r19
		brlo Done

	Units21:
		inc Accuracy
		sub r20, r18
		sbc r24, r19
		cp  r20, r18
		cpc  r24, r19
		brsh Units21
	
	Done:
	std Y+Units, Accuracy
ret

;*********************************************************

display_units:
	ldi r20, 0b00011100
	out portD, r20
	clr r18
	ldd r19, Y+Units
	add ZL, r19
	adc ZH, ZeroReg
	lpm r18, Z		
	out portC,r18

	ldi PDelReg, 1
	rcall Delay1m
ret

display_tens:
	ldi r20, 0b00011000
	out portD, r20
	clr r18
	ldd r19, Y+Tens
	add ZL, r19
	adc ZH, ZeroReg
	lpm r18, Z		
	out portC,r18

	ldi PDelReg, 1
	rcall Delay1m
ret

display_hundreds:
	ldi r20, 0b00010100
	out portD, r20
	clr r18
	ldd r19, Y+Hundreds
	add ZL, r19
	adc ZH, ZeroReg
	lpm r18, Z		
	out portC,r18

	ldi PDelReg, 1
	rcall Delay1m
ret

display_thousands:
	ldi r20, 0b00010000
	out portD, r20
	clr r18
	ldd r19, Y+Thousands	
	add ZL, r19
	adc ZH, ZeroReg
	lpm r18, Z		
	out portC,r18

	ldi PDelReg, 1
	rcall Delay1m
ret

;*************************************************

SegmentUp:
	clr Number
	ldi r25, 1

	adiw XL, 1
	adc XH, ZeroReg

	mov r24, XH
	mov r20, XL
	rcall init_Y_display
	rcall clear_display
	rcall disassamble_number
	rcall init_Z_segment_display

	Loop:
		inc Number

		rcall display_units
		rcall init_Z_segment_display

		rcall display_tens
		rcall init_Z_segment_display

		rcall display_hundreds
		rcall init_Z_segment_display
	
		rcall display_thousands
		rcall init_Z_segment_display
		
		cpi Number, 30
		brne Loop

		ldi r20, high(999)
		ldi r24, low(999)

		cp XL,r24
		cpc XH,r20

		brne return

		ldi XL, low(0)
		ldi XH, high(0)

return:
ret

;*********************************************

segment_display:
	.db 0b11000000,0b11111001 ; 0,1
	.db 0b10100100,0b10110000 ; 2,3
	.db 0b10011001,0b10010010 ; 4,5
	.db 0b10000010,0b11111000 ; 6,7
	.db 0b10000000,0b10010000 ; 8,9
	.db 0b10001000,0b10000011 ; A,B
	.db 0b11000110,0b10100001 ; C,D
	.db 0b10000110,0b10001110 ; E,F
end_of_segment_display:

.exit
