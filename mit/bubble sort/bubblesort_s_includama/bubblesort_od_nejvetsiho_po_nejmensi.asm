;********************************************************
;               the beginning of bubble sort            *
;********************************************************

;============= Includes =============
.NOLIST
.include	"m16def.inc"
.LIST
;======= Register definitions =======
.include "./header_files/definice_registru.inc"
;========= Interrupt vectors =========
.include "./header_files/prerusujici_vectory.inc"
;====== Unused interrupt vectors ======
.include "./header_files/nevyuzite_prerusujici_vectory.inc"
;======================================
.include "./header_files/reset.inc"
;======================================

;--------- Iterator definiton ---------
.include "./header_files/definice_iteratoru.inc"

;-------- Initialize X, Y and Z --------
.include "./header_files/inicializace_X_Y_Z.inc"

;---------- Copy Flash to RAM ----------
.include "./header_files/copy_flash_to_RAM.inc"

;---------- Compare and switch ----------
.include "./header_files/compare_and_switch.inc"

;------------ InnerLoop sort ------------
.include "./header_files/innerLoop_sort.inc"

;------------- Bubble Sort -------------
.include "./header_files/BubbleSort.inc"

;----------------- Main -----------------
Main:
	rcall init_X
	rcall init_Z
	rcall init_Y
	clr maximalni_iterator_vnitrni_smycky
	rcall Copy_Flash_2_SRAM

	rcall init_Y;
	clr iterator
	clr iterator_bubble_sortu
	rcall innerLoop_sort
	
	rcall bubbleSort
	
rjmp Main


;---------- Compare and switch ----------
.include "./header_files/tabulka_cisel.inc"

;*************************************************
;             the end of bubble sort             *
;*************************************************
