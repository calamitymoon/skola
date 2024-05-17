;include "../templateM16.inc"
.include "obsluha.inc"
.include "delay.inc"

;====================;
;        MAIN        ;
;====================;


Main:
	com Cnt0
	out portA,Cnt0
	com Cnt0
	rjmp Main
