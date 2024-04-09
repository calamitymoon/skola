;****************************************
;             Sort Cycle
;________________________________________
sort: ;runs a single sorting cycle
	ld r16, Y ;load number on Y to r16
	ldd r17, Y+1 ;load number on Y+1 to r17
	cp r16, r17 ;r16 < r17 ? trideni increasing or decreasing? exchange r16 with r17 for choice
	brlo jsemok ;if(r16<r17) do not swap 
		ST Y,r17 ;if(r16>r17) swap
		STD	Y+1, r16 
	jsemok: 
		adiw Yh:Yl, 1
	inc iter ;increases number of finished single cycles
	cp iter, maxcisel ;if number of finished single cycles is same as number of max cycles, reset sort function 
	brne sort 
	
	rcall reset_funkce
ret
;****************************************

;****************************************
;       Pomocne funkce sort cyclu
;________________________________________	
lower_max:	;snizi pocet zbyvajicich cyklu o 1
	dec maxcisel
ret


compare: ; if max cycles is 0 ends sort function
	cpi maxcisel, 0
	brne sort
ret
;****************************************
