Segmentovka

- segmentovka:
	- .db 0b...., 0b.... ; 0,1
	- .db 0b...., 0b.... ; 2,3

- init_Z_seg:
	- ldi ZH, high (2x seg..)
	- ldi ZL, low (2x seg..)
- ret

	nacti_5:
		ldd db, Z+5
	ret

- dva porty na ovladani
	- data - BYTE cislice (Port D)
	- ctrl - port on/of (Port C)

- ?ping of C?
- SBI PortA, 1
- CBI PortA, 2

| 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |


	.equ disp_on_pin = 1 
	.equ disp_off_pin = 1