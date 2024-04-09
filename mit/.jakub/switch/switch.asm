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
.def key=r16
.def a = r17
.def b = r18
.equ konecna_podminka=10
.equ konecna_podminka2=20
.def iterator = r20
.equ konecna_podminka3=40
IfElse:
clr a 	//zkontroluje a
	clr b 	//zkontroluje b
	ldi a,6 	//zadá promìnnou a

	if:
		cpi a,5		//zkontroluje zda iterátor a=5
		brne else	//pokud se nerovná pošle do else
		ldi b,6		//pokud se rovná zadá údaj do b jako 6
	rjmp hotovo

	else:
		ldi b,7		//pokud se a nerovná 5 zadá b jako 7
	rjmp hotovo

	hotovo:
	clr r17
	clr r18
ret

SwitchMain:
ldi key, 10 // nastavi key na 10
	for4:
		cpi key, konecna_podminka3
		brne Switch
		rjmp hotovo5
	loop:
	

	Switch:
		cpi key,10	//zkonrtoluje jestli je key 10
		brne case_20	//pokud neni key 10 tak posle do case_20, pokud je key 10 posle do case_10
		case_10:
		
			ldi key, 20	// nasavi key na 20
			
		rjmp hotovo2	//skoci na hotovo2
	
		case_20:
			cpi key, 20	//zkotroluje zda je key 20
			brne case_30	//pokud neni posle do case_30
			
				ldi key, 30	//pokud je key 20 nastavi hodnotuna 30

		rjmp hotovo2	
	
	
		case_30:
		cpi key, 30	//zkotroluje zda je key 30
		brne hotovo2	//posle do hotovo2

			ldi key, 40	//nastavi hodnotu key na 40 


	hotovo2:	
	cpi key, 40
	rjmp for4
	
rjmp hotovo5

hotovo5:
ret
For1:
	ldi iterator,0 //zada hodnotu iteratoru na 0
			For:
			inc iterator //zvysi hodnotu iteratoru o 1
			cpi iterator,konecna_podminka	//kontroluje zda se iterator rovna konecne podmince
			brne for //pokud neni zopakuje funkci For, pokud ano zopakuje funkci main
			
rjmp hotovo3

hotovo3:
clr iterator
ret
For3:
ldi iterator,0 //zada hodnotu iteratoru na 0
			For2:
			inc iterator //zvysi hodnotu iteratoru o 1
			cpi iterator,konecna_podminka	//kontroluje zda se iterator rovna konecne podmince
			brne for2
				loop3:
					inc iterator
					cpi iterator,konecna_podminka2
					brne loop3 //pokud neni zopakuje funkci For, pokud ano zopakuje funkci main
			
rjmp hotovo4

hotovo4:
ret
Main:
	rcall IfElse
	rcall SwitchMain
	rcall For1
	rcall For3
rjmp Main

