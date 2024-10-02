
Main:
	rcall init_Z_InFlash	;volá funkci, která inicializuje Z
	rcall init_Y_SRAM		;volá funkci, která inicializuje Y
	rcall init_X_OutFlash	;volá funkci, která inicializuje X	
	clr MAX					;clearuje to registr maximalnich
	rcall CopyFlash_to_SRAM	;volá funkci, která	kopiruje flash do sram

	rcall init_Y_SRAM		;volá funkci, která inicializuje Y
	rcall InnerLoop_Sort
	
	rcall BblSort

	
rjmp Main
