
Main:
	rcall init_Z_InFlash	;vol� funkci, kter� inicializuje Z
	rcall init_Y_SRAM		;vol� funkci, kter� inicializuje Y
	rcall init_X_OutFlash	;vol� funkci, kter� inicializuje X	
	clr MAX					;clearuje to registr maximalnich
	rcall CopyFlash_to_SRAM	;vol� funkci, kter�	kopiruje flash do sram

	rcall init_Y_SRAM		;vol� funkci, kter� inicializuje Y
	rcall InnerLoop_Sort
	
	rcall BblSort

	
rjmp Main
