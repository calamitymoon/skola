; header file
bubbleSort:
	clr iterator
	clr iterator_bubble_sortu
	rcall init_Y
	rcall innerLoop_sort
	cp iterator_bubble_sortu, maximalni_iterator_vnitrni_smycky
brne bubbleSort
