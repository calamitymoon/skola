;	==========
;	 DEFINICE
;	==========


.equ prescaler_0 = (0<<CS02)|(0<<CS01)|(1<<CS00)
.equ prescaler_8 = (0<<CS02)|(1<<CS01)|(0<<CS00)
.equ prescaler_64 = (0<<CS02)|(1<<CS01)|(1<<CS00)
.equ prescaler_256 = (1<<CS02)|(0<<CS01)|(0<<CS00)
.equ prescaler_1024 = (1<<CS02)|(0<<CS01)|(1<<CS00)

.equ top_value = 64

;	=======
;    MAKRA
;	=======


.macro set_prescaling
	push TmpReg
    ldi TmpReg, @0		;	prescaler
    out TCCR0, TmpReg
	pop TmpReg
.endm

.macro set_top_val
	push TmpReg
    ldi TmpReg, @0		;	vrchni hodnota
    out OCR0, TmpReg
	pop TmpReg
.endm

.macro setup_timer
	set_prescaling @0
    set_top_val @1
.endm


;	=========
;	 POUZITI
;	=========


;set_prescaling prescaler_0, 0
;set_prescaling prescaler_8, 8
;set_prescaling prescaler_64, 64
;set_prescaling prescaler_256, 256
;set_prescaling prescaler_1024, 1024


;	==================================
;	 taky funguje, ale jde to lehcejc
;	==================================


;.macro set_prescaling_0
;		ldi TmpReg, (0<<CS02)|(0<<CS01)|(1<<CS00)
;		out TCCR0, TmpReg
;.endmacro
;
;.macro set_prescaling_8
;		ldi TmpReg, (0<<CS02)|(1<<CS01)|(0<<CS00)
;		out TCCR0, TmpReg
;.endmacro
;
;.macro set_prescaling_64
;		ldi TmpReg, (0<<CS02)|(1<<CS01)|(1<<CS00)
;		out TCCR0, TmpReg
;.endmacro
;
;.macro set_prescaling_256
;		ldi TmpReg, (1<<CS02)|(0<<CS01)|(0<<CS00)
;		out TCCR0, TmpReg
;.endmacro
;
;.macro set_prescaling_1024
;		ldi TmpReg, (1<<CS02)|(0<<CS01)|(1<<CS00)
;.endmacro
