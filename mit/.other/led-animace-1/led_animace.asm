;***********************************
;	lab example number one
;***********************************
;=========Includes =================
.NOLIST
.include	"m16def.inc"
.LIST
;====== Register definitions =======
.DEF ZeroReg = r0
.DEF TmpReg  = r16

.DEF	PDelReg		= r20
.DEF	PDelReg0	= r21
.DEF	PDelReg1	= r22
.DEF	PDelReg2	= r2
;=====+== PROGRAM segment ==========
.CSEG
;******** Interrupt vectors ********
		.ORG	0x0000
		jmp	RESET	; Reset ISR

;******* Reset ********
		
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
;********************** MAIN **********************
;**************************************************

.equ a=PortA
.equ b=PortB
.def registr1=r16
.def registr2=r17
.def iterator=r18
.equ pocatecni_hodnota=0b00000001
.equ koncova_hodnota=0b10000000
.equ prictena_hodnota=1
	

vytvor_obsah1:
;	inc registr1
;	add registr1, prictena_hodnota
	rcall vyobraz_obsah
	lsl registr1
	cpi registr1, koncova_hodnota
	brne vytvor_obsah1
ret

vytvor_obsah2:
; 	inc registr2
;	add registr2, prictena_hodnota
	rcall vyobraz_obsah2
	lsl registr2
	cpi registr2, koncova_hodnota
	brne vytvor_obsah2
ret

vyobraz_obsah:
	out a,registr1
	ldi PdelReg, 100
;	rcall Delay1m
ret

vyobraz_obsah2:
	out b,registr2
	ldi PdelReg, 100
;	rcall Delay1m
ret

nastaveni_hodnot:
	ldi registr2, pocatecni_hodnota
	ldi registr1, pocatecni_hodnota
ret

zobraz_animaci:
	rcall nastaveni_hodnot
	rcall vytvor_obsah1
	rcall vytvor_obsah2
	rcall vyobraz_obsah
ret


Main:
	ldi registr1,0
	ldi registr2,0
	rcall zobraz_animaci
rjmp Main
