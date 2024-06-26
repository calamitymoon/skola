;***********************************
;	lab example number one
;***********************************
;=========Includes =================
;
.NOLIST
.include	"m16def.inc"
.LIST



;====== Register definitions =======
.DEF ZeroReg = r0
.DEF TmpReg = r21

.DEF	PDelReg		= r20
.DEF	PDelReg0	= r21
.DEF	PDelReg1	= r22
.DEF	PDelReg2	= r2

;=====+== PROGRAM segment ==========
.CSEG
;******** Interrupt vectors ********
		.ORG	0x0000
		jmp	RESET			; Reset Handler
		jmp	EXT_INT0		; External Interrupt Request 0 Handler
		jmp	EXT_INT1		; External Interrupt Request 1 Handler
		jmp	TIM2_COM		; Timer2 Compare Match Handler
		jmp	TIM2_OVF		; Timer2 Overflow Handler
		jmp	TIM1_CAP		; Timer1 Capture Handler
		jmp	TIM1_COMA		; Timer1 Compare Match A Handler
		jmp	TIM1_COMB		; Timer1 Compare Match B Handler
		jmp	TIM1_OVF		; Timer1 Overflow Handler
		jmp	TIM0_OVF		; Timer0 Overflow Handler
		jmp	SPI_STC			; SPI Transfer Complete Handler
		jmp	UART_RXC		; UART RX Complete Handler
		jmp	UART_DRE		; UART Data Register Empty Handler
		jmp	UART_TXC		; UART TX Complete Handler
		jmp	ADC_COMP		; ADC Conversion Complete Handler
		jmp	EE_RDY			; EEPROM Write Complete (Ready) Handler
		jmp	ANA_COMP		; Analog Comparator Handler
		jmp	TWI				; Two-wire Serial Interface Handler
		jmp	EXT_INT2		; External Interrup Request 2 Handler
		jmp	TIM0_COM		; Timer0 Compare Match Handler
		jmp	SPM_RDY			; Store Program Memory Ready


;******* Reset ********
;********************************** Unused interrupt vectors ***************************************************
EXT_INT0:
EXT_INT1:
TIM2_COM:
TIM2_OVF:
TIM1_CAP:
TIM1_COMA:
TIM1_COMB:
TIM1_OVF:
TIM0_OVF: 
SPI_STC:
UART_DRE:
UART_TXC:
UART_RXC:
ADC_COMP:
EE_RDY:
ANA_COMP:
TWI:
EXT_INT2:
TIM0_COM:
SPM_RDY:	reti


;************************************************
		
		.ORG	0x0030
Reset:		
	
		clr	ZeroReg
		ldi	TmpReg, low(RAMEND)	; Stack Ptr
		out	SPL, TmpReg
		ldi	TmpReg, high(RAMEND)
		out	SPH, TmpReg

		ldi	TmpReg, 0b10000000	; Disable JTAG interface
		out	MCUCSR, TmpReg
		out	MCUCSR, TmpReg

		;port config....
		ldi	TmpReg, 0xFF
		out	DDRA, TmpReg		; Set direction of port A (all inputs)
		out	DDRB, TmpReg		; Set direction of port B (all inputs)
		out	DDRC, TmpReg		; Set direction of port C (all outputs)
		out	DDRD, TmpReg		; Set direction of port D (all outputs)

		out	PortA, ZeroReg		; Set port A to 00h
		out	PortB, ZeroReg		; Set port A to 00h
		out	PortC, ZeroReg		; Set port A to 00h
		out	PortD, ZeroReg		; Set port A to 00h


		rjmp	Main
;***************************************
;************** Delay (PDelReg[ms]) ***************
; this is a delay subroutine 
Delay1m:	mov	PDelReg2, PDelReg
Delay1m0:	ldi	PDelReg0, 20
Delay1m1:	ldi	PDelReg1, 245
Delay1m2:	dec	PDelReg1
		brne	Delay1m2
		dec	PDelReg0
		brne	Delay1m1
		dec	PDelReg2
		brne	Delay1m0
		ret

;**************************************************


init_z_animace:
	ldi ZL, low(2*moje_animace)
	ldi ZH, high(2*moje_animace)
ret

zobraz_snimky:
	out PortB, r16 ; zobrazovani snimku
ret

nacti_snimek:
	lpm r16, Z+ ; nacitani snimku
ret

Main:
	rcall init_z_animace ; volani podprogramu init_z_animace
	clr r17 ; vycisteni iteratoru loopu
	loop:
		rcall nacti_snimek ; volani podprogramu nacti_snimek
		rcall zobraz_snimky ; volani podprogramu zobraz_snimky
		ldi PDelReg, 255
		rcall Delay1m ; volani podprogramu Delay1m

		inc r17 ; zvetsovani registru 17 o 1
		cpi r17, 10 ; checkovani pokud se registr 17 rovna 10
	brne loop ; branch if not equal do loopu
rjmp Main

moje_animace:
	.db 0b01111110, 0b11111101
	.db 0b11111011, 0b11110111
	.db 0b11101111, 0b11011111
	.db 0b10111111, 0b01111111
	.db 0b11111111, 0b00000000
.exit

