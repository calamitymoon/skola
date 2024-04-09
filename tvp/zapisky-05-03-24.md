
1) FILE SYSTEM
2) WEAR LEVELING

## FILE SYSTEM
- VFATM NTFS, EXT2, EXT3, EXT4, ...
	[?] Proc to potrebujem?
	 => predstavte si, ze ulozite sektory S1, S2, S3, ...
	 => sektor S2 smazete a tim vznikne misto mezi S1 a 23
- potrebujeme "**MANAGE**"-ovat bloky pameti, ktera souvisi s jednim souborem
				-> [FILESYSTEM] se deli na  `a)` **HW** => vzdy rychlejsi --> SRAM
										`b)` **SW** => VFAT --> HDD, SDD
	- SSD ==> "*FLASH*"
		- [plusy] rychly, levny, matematicky jako HDD
		- [minusy] OMEZENA PREPISOVATELNOST
			- chci vyrovnat pocet prepisu kazdeho bloku po cele pameti -> je potreba vedet kolikrat byl kazdy blok prepsan (ktery blok je vadny \[muze byt od vyroby KO ] )
			- ruzny druhy -> zivotnost pameti