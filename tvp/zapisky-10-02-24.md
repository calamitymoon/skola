odkaz na obrazky
https://cs.stanford.edu/people/eroberts/courses/soco/projects/risc/pipelining/index.html

#### propustnost MCU se určí v MIPS
- proudově p. cpu
- proč → zvýšení propustnosti MCU tak, že zvýšíme paralelizaci strojů za vteřinu
		→ měříme v MIPS (Milions of Instructions Per Second)
		→ paralelizace zvýší výkon i když pouze jen částečně
		→ paralelizace má režii
		→ existuje sekvenční stroj - nezačne další instrukci dokud ta poslední není zcela vykonána
- není "broken pipeline", všechny instrukce trvají stejný počet taktů
	→ pipeline/proudově pracující MCV - většina instrukcí trvá 2 takty
		=> `nop`            --> jeden takt
		=>`std`, `st`, ... --> tři takty
	- *historie*:
		**~** 1980 RISC
		**~** 1990 sekvenční stroj