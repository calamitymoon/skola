;***********************************
;	lab example number one
;***********************************
;=========Includes =================

.NOLIST
.include	"m16def.inc"
.LIST

;====== Register definitions =======
.DEF ZeroReg = r0
.DEF TmpReg = r21
.def db =  r17
.def snimek = r16
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

init_Z_seg:
	ldi ZH,high(2*segmentovka)
	ldi ZL,low(2*segmentovka)
ret

konfig_port_vystup:
	ldi snimek, 0xFF
	out DDRA, snimek
ret

zobrazit_stav:
	out PortA, snimek
ret
znak4:
	lpm db, Z+4
ret
znak5:
	lpm db, Z+5
ret

nacti_snimek:
	lpm snimek, Z+
ret

Main:
rcall init_Z_seg
rcall konfig_port_vystup
rcall znak4
rcall nacti_snimek
rcall zobrazit_stav
	
rjmp main

segmentovka:
.db 0b0111111,0b0000110
.db 0b1011011,0b1001111
.db 0b1100110,0b1101101
.db 0b1111101,0b0000111
.db 0b1111111,0b1100111
konec_segmentovky:


