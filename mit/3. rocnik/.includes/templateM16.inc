;***********************************
;	lab example number one
;***********************************
;=========Includes =================
;

.NOLIST
.include	"m16def.inc"
.LIST

.EQU DispDataP = PortC  ;display data port
.EQU DispDataD = DDRC	;display data direction register
.EQU DispDataI = PinC	;display data coming in to port C
.EQU DispCtrlP = PortD	;display data control (the three pins) port

; macro na zapnuti led displeje
.MACRO seg_led_pwr_on
	sbi DispCtrlP, 4 ; nastavi ctvrty bit v DispCtrlP (i/o registru) na 1
.ENDMACRO

; macro na vypnuti led displeje
.MACRO seg_led_pwr_off
	cbi DispCtrlP, 4 ; nastavi ctvrty bit v DispCtrlP (i/o registru) na 0
.ENDMACRO

; macro na zobrazeni jednotek
.MACRO digit_units_ON
	sbi DispCtrlP,3 ; nastavi treti bit v DispCtrlP na 1
	sbi DispCtrlP, 2 ; nastavi druhy bit v DispCtrlP na 1
.ENDMACRO

.MACRO digit_tens_ON
	sbi DispCtrlP, 3
	cbi DispCtrlP, 2
.ENDMACRO

.MACRO digit_hundreds_ON
	cbi DispCtrlP, 3
	sbi DispCtrlP, 2
.ENDMACRO

.MACRO digit_thousands_ON
	cbi DispCtrlP, 3
	cbi DispCtrlP, 2
.ENDMACRO

;====== Register definitions =======
.DEF	ZeroReg 	= r0
.DEF	TmpReg		= r19
.DEF	PDelReg		= r20
.DEF	PDelReg0	= r21
.DEF	PDelReg2	= r2
.DEF	PDelReg1	= r22

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
;**************************************************

;************** Delay (PDelReg[ms]) ***************
; this is a delay subroutine
Delay1m:	mov	PDelReg2, PDelReg

;**************************************************
