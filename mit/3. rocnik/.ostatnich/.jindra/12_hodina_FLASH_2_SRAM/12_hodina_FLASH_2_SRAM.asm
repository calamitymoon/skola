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

.DEF pocet_cisel = r14 
.DEF pocet_opakovani = r15
;=====+== PROGRAM segment ==========
.dseg
muj_blok: .byte 32
.cseg
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
.cseg


int_ukazatelu:			;inicializuje ukazatele (Flash,SRAM)
	ldi ZL, low (2*Moje_Tabulka)
	ldi ZH, high (2*Moje_Tabulka)

	ldi YL, low (muj_blok)
	ldi YH, high (muj_blok)

	ldi XL, low (2*konec_tabulky)
	ldi XH, high (2*konec_tabulky)
ret



;****************************
; 		inicializuj
;----------------------------
;popis podprogramu, pouzite registry
;....kde (ve kterych registrech) najde tento podprogram 
;hodnoty ktere ocekava...
int_Y_muj_blok_6:
	ldi YL, low (muj_blok)
	ldi YH, high (muj_blok)
ret
;---------- END init




;****************************
; 	inicializuj na nulu
;----------------------------
;Zapisuje nulu na pozici v pameti
.
Int_SRAM_na_nulu_2:		;blok v SRAM.
	std Y+0, ZeroReg
	std Y+1, ZeroReg
	std Y+2, ZeroReg
	std Y+3, ZeroReg
	std Y+4, ZeroReg
	std Y+5, ZeroReg
	std Y+6, ZeroReg
	std Y+7, ZeroReg
	std Y+8, ZeroReg
	std Y+9, ZeroReg
	std Y+10, ZeroReg
	std Y+11, ZeroReg
	std Y+12, ZeroReg
	std Y+13, ZeroReg
ret
;-----------END init





;****************************
; 	Pøepis Flash do SRAM
;----------------------------
;Zapisuje cisla ulozena v flash do SRAM			 r16
;....r16 - psane cislo
copy_flash_2_SRAM:		
	push r16
		lpm r16,Z+
		st Y+, r16

			inc pocet_opakovani

		cp ZL,XL
		cpc ZH,XH
		brne copy_flash_2_SRAM

			dec pocet_opakovani
	pop r16
ret
;--------------END Copy


;****************************
; 		Porovnani
;----------------------------
;porovnava 2 zasebou jdouci cisla, r16, r17
;....r16 - prvni cislo, r17 - druhe cislo
;r16>r17
PorovnejAprohod:	
	ld r16, Y
	ldd r17, Y+1
	cp r16, r17
	brlo jsou_ok ;porovnava zda je druhy register mensi
		st Y, r17
		std Y+1, r16
	jsou_ok:
		adiw YH:YL,1
ret
;---------END Porovnani




;****************************
;Vnitrni smycka bubble sortu
;----------------------------
;popis podprogramu, 		r14, r15
;pocet_cisel = r14 pocet_opakovani = r15
Vnitrni_smycka:		;ukoncuje serazobani jednoho cisla
	rcall porovnejAprohod

		inc pocet_cisel;iterator poctu setridenych cisel

	cp pocet_opakovani, pocet_cisel
	brne Vnitrni_smycka
ret
;-------END Vnitrni smycky





;****************************
; 		Bubble Sort
;----------------------------
;popis podprogramu, 		r14, r15
;....pocet_cisel = r14 pocet_opakovani = r15
;r14=0 r15=0
Vnejsi_smycka:		;Ukonèuje serazovani celku
;	clr pocet_cisel
;	clr pocet_opakovani
	rcall int_Y_muj_blok_6

	rcall Vnitrni_smycka

		dec pocet_opakovani
		clr pocet_cisel

	cp pocet_cisel, pocet_opakovani
	brne Vnejsi_smycka	
;	clr pocet_cisel
ret
;-----------END Bubble Sortu

Main:
	rcall int_ukazatelu

	rcall Int_SRAM_na_nulu_2

	rcall int_Y_muj_blok_6
	clr pocet_opakovani
	rcall copy_flash_2_SRAM

	rcall int_Y_muj_blok_6
; +
; +
	
	rcall Vnejsi_smycka

rjmp Main

Moje_Tabulka:
.db 14,13
.db 12,11
.db 10,9
.db 8,7
.db 6,5
.db 4,3
.db 2,1
konec_tabulky:
