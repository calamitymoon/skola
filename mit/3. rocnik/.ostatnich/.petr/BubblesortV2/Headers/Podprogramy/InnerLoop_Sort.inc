;*****************************
;co dela tento podprogram????
;*****************************
;Loopne podpogra Porv�v�n� a bude ��sla rovnat ka�d� sot v ��dku kter� je v�t��. pokud je v�t�� p�ehod jej
InnerLoop_Sort:
	rcall Compare_and_MoveHtoL	;prehodi o jedno
	inc pocet_cisel 		;zvysi registr s aktualnim poctem opakovani
	cp pocet_cisel, MAX 	; checkuje jestli se aktualni pocet opakovani rovna maximalnimu poctu opakovani
	brne InnerLoop_Sort
	dec MAX
ret
;-------------------- END InnerLoop_Sor
