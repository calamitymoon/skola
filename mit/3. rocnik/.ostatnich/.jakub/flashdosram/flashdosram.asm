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
	muj_blok: .byte 32
;=====+== PROGRAM segment ==========
.CSEG
.include "vectors.inc"

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
.def iter=r18
.def maxcisel=r19
;***************************************
.include "init_XYZ.inc"

.include "max_cycles.inc"

.include "copy_flash_to_sram.inc"

.include "sort_cycle.inc"

.include "reset_functions.inc"



Main:
	rcall init_y ;initializes pointer Y
	rcall init_z ;initializes pointer Z
	rcall init_x ;initializes pointer X
	rcall find_amount_of_possible_sort_cycles ;finds max amount of sort cycles and numbers in number table
	rcall copy_flash_to_sram ;copies Flash numbers to SRAM
	rcall sort ;sorts values in SRAM
	rcall resetovat_cisla ;resets free iter and max number of sort cycles and numbers in number table
rjmp Main

.include "tabulka_hodnot.inc"
