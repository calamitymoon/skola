;****************************************     
; Max possible amount of sort cycles
;________________________________________
find_amount_of_possible_sort_cycles: ;fínds max amount of possible cycles, and written numbers in number table
	lpm r16, Z+ ;loads number from Flash to r16
		inc maxcisel ;increases maximum amount of sort cycles and written numbers in SRAM
	cp Zl, Xl ;compares lowest Flash with lowest SRAM
	cpc Zh, Xh ;compares highest Flash with highest SRAM
	brne find_amount_of_possible_sort_cycles 

	rcall init_z ;resets Z pointer
	rcall reset_iter ;resets free iter
ret

;****************************************
