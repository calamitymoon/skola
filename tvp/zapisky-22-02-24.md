Pametove cipy

+-------+
|              |     -> datova sbernice
|      ?      |     => **zde**: 18
|              |
+-------+

`?` jaky je pocet bytu?
`~` 1k, 2k, 4k, ...

1k ==> 1024 B --> kolik bitu je potreba na adrevaci 1024B ?

`?` jak to vypada vevnitr?
`~` tento cip je v podstate "pole" / "array"

- vstup:       
- vystupy:   

-> problem: `?` co kdyz sirka slova mcu neni 1B ale 2B?
-> problem: `?` co nepotrebujeme 1k ale 4kB a mame k dispozici pouze 1kB cipy?

==zadání:===
> mame:              1kB cipy se sirkou dat 8-bit
> potrebujem:     pamet 2kB se sirkou slova 2B

![[Pasted image 20240222121521.png]]
- je potreba si uvedomit, ze existuji i kombinace seriovych/paralelnich zapojeni:
	-> kapacita 4kB, sirka slova 16-bit
	-> adresova sbernice bude 

