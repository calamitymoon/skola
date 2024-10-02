;****************************************
;           Reset Functions
;________________________________________
reset_funkce: ;resets the sort function
	rcall lower_max ;lowers max amount of sort cycles
	rcall reset_iter 
	rcall init_y
	rcall compare 
ret

resetovat_cisla: ;resets the max and free iter
	clr maxcisel
	clr iter
ret

reset_iter: ;resets free iter to 0
	clr iter
ret

;****************************************
