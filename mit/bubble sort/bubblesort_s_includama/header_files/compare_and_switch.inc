; header file
porovnejAprehod:
	ld r16, Y
	ldd r17, Y+1
	cp r16, r17
	brsh jsou_ok
		ST Y, R17
		STD Y+1, R16
	jsou_ok:
		adiw YH:YL, 1
ret
