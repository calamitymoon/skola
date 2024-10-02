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
.DEF TmpReg = r24


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
;*********************************************
.def snimek = r16

init_z_moje_tabulka:
	ldi ZL, low(2*moje_tabulka)
	ldi ZH, high(2*moje_tabulka)
ret

nacti_snimek:
	lpm r16, Z+
ret

konfig_port_vystup:
	ldi r16, 0xFF
	out DDRA, r16
ret

init_prvni_stav:
	ldi snimek, 0b00011111
;	com snimek
ret

next_state_calc:
	ror snimek
ret

zobrazit_stav:
	out PortA, snimek
ret



Main:
	clr r17
;	rcall moje_tabulka
	rcall init_z_moje_tabulka
	rcall konfig_port_vystup
;	rcall init_prvni_stav
	main2:
		rcall nacti_snimek
;		rcall next_state_calc
		rcall zobrazit_stav
		ldi PDelReg, 100
		rcall Delay1m
			inc r17
			cpi r17, 14
			brne main2
;	rjmp main2;podminena smycka...
rjmp Main

moje_tabulka:
.db 0b01111110, 0b00111100
.db 0b00011000, 0b00000000
.db 0b10000001, 0b11000011
.db 0b11100111, 0b11111111
.db 0b11111111, 0b11100111
.db 0b11000011, 0b10000001
.db 0b00000000, 0b00000000
.exit
