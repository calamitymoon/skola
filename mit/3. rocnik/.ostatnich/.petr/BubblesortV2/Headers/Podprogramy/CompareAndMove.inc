;*****************************
;co dela tento podprogram????
;*****************************
;porovnává èísla v tabulce
Compare_and_MoveHtoL:		;fce porovnává 
	ld r16,Y
	ldd r17,Y+1
	cp r16,r17
	
	brsh jsou_ok1			;brsh = branch if same or higher
	
	ST Y,r17
	STD Y+1, r16
	jsou_ok1:
		adiw YH:YL,1
ret
;-------------------- END

;*****************************
;co dela tento podprogram????
;*****************************
;porovnává èísla v tabulce
;Compare_and_Move_LtoH:		;fce porovnává 
;	ld r16,Y
;	ldd r17,Y+1
;	cp r16,r17
;	
;	brlo jsou_ok2			;brlo = branch if 
;	
;	ST Y,r17
;	STD Y+1, r16
;	jsou_ok2:
;		adiw YH:YL,1
;ret
