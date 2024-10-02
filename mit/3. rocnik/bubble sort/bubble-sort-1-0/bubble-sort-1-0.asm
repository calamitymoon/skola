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

.DSEG
	muj_blok: .byte 16

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

.def maximalni_iterator_vnitrni_smycky=r5
.def iterator=r6
.def iterator_bubble_sortu=r7

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

Copy_Flash_2_SRAM:
	lpm r16, Z+
	ST Y+, R16
		inc maximalni_iterator_vnitrni_smycky
	cp  ZL, XL
	cpc ZH, XH
	brne Copy_Flash_2_SRAM; 2x dec ?
	dec maximalni_iterator_vnitrni_smycky
ret

porovnejAprehod:
	ld r16, Y
	ldd r17, Y+1
	cp r16, r17
	brsh jsou_ok ; branch if same or higher
		ST Y, R17
		STD Y+1, R16
	jsou_ok:
		adiw YH:YL, 1
ret

innerLoop_sort:
	rcall porovnejAprehod
	inc iterator
	cp iterator, maximalni_iterator_vnitrni_smycky
	brne innerLoop_sort; dec max iteratoru bubble sortu?
	dec maximalni_iterator_vnitrni_smycky
ret

bubbleSort:
	clr iterator
	clr iterator_bubble_sortu
	rcall init_Y
	rcall innerLoop_sort
	cp iterator_bubble_sortu, maximalni_iterator_vnitrni_smycky
brne bubbleSort

stop:
	; breakpoint
ret

Main:
	rcall init_X
	rcall init_Z
	rcall init_Y
	clr maximalni_iterator_vnitrni_smycky
	rcall Copy_Flash_2_SRAM

	rcall init_Y
	clr iterator
	clr iterator_bubble_sortu
	rcall innerLoop_sort
	
	rcall bubbleSort
	
	rcall stop
rjmp Main

tabulkaCisel:
	.db 5, 12
	.db 6, 7
	.db 9, 1
	.db 7, 10
	.db 4, 5
	.db 6, 7
	.db 9, 1
	.db 6, 7
	.db 9, 1
	.db 3, 2
konecCisel:
