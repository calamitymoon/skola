;*****************************
;co dela tento podprogram????
;*****************************
;Vol� podprogram co rovn� ��sla
BblSort:					;fce kter� se opakuj dokud nebudou v�echny ��sla srovn�na od nejvy��� do nejni���
	clr pocet_cisel
	clr Sorting
	rcall init_Y_SRAM
	rcall InnerLoop_Sort
	cp Sorting, MAX
	brne BblSort
ret
