;****************************************
;       Zkopiruje flash do SRAM
;________________________________________
copy_flash_to_sram: ;naète èísla do pamìti
		lpm r16, Z+ ;loads number from Flash to r16
		ST Y+, r16 ;stores number on r16 to SRAM
			inc iter ;increases free iter
		cp Zl, Xl ;compares lowest Flash with lowest SRAM
		cpc Zh, Xh ;compares highest Flash with highest SRAM
		cp iter, maxcisel ;compares if number of written down numbers is the total amount
	brne copy_flash_to_sram

	rcall reset_iter ;resets free iter
	rcall init_y ;resets Y pointer to zero
ret
;****************************************
