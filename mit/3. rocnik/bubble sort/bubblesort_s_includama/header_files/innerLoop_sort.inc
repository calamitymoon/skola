; header file
innerLoop_sort:
	rcall porovnejAprehod
	inc iterator
	cp iterator, maximalni_iterator_vnitrni_smycky 
	brne innerLoop_sort
	dec maximalni_iterator_vnitrni_smycky
ret
