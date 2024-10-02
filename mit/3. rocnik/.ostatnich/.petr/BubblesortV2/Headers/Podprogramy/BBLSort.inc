;*****************************
;co dela tento podprogram????
;*****************************
;Volá podprogram co rovná èísla
BblSort:					;fce která se opakuj dokud nebudou všechny èísla srovnána od nejvyšší do nejnižší
	clr pocet_cisel
	clr Sorting
	rcall init_Y_SRAM
	rcall InnerLoop_Sort
	cp Sorting, MAX
	brne BblSort
ret
