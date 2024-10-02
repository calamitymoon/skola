0- zkalibroval jsem osciloskop 17.09.2024 v 8:13

## Měření
## 1. Protokol

### Zadání:
- Zjisti přesnost čítače na AT mega 16 a porovnej naměřenou hodnotu s vypočítanou, sestroj
grafy a udělej závěr.

### Teorie
- ***Čítač*** – má počítací a odpočítávací funkci, jeho úkolem je číselným údajem zaznamenat počet
událostí nebo procesů a informovat, kolikrát proběhly. Je vytvořen proto, aby dokázal rychle
čítat elektrické impulsy, jejichž frekvence je zaznamenána v kHz, MHz a GHz.
- ***Osciloskop*** – elektronický měřicí přístroj s obrazovkou, který zaznamenává průběh měřeného
napěťového signálu. Existuje několik typů osciloskopů, například analogové (klasické,
paměťové, vzorkovací) nebo digitální (spolupracují s osobním počítačem).
- V našem případě byl použit digitální, tedy čtvercovou vlnu jsme mohli vidět na PC
softwarově. 

### Použité přístroje:
***Osciloskop*** – max input: 30Vp, mx output: 10Vpp, 2x 12MHz PC-Scope -> používaný vstup 1
***Programátor*** – Pro spojení desky s počítačem (AVR-ISP)
***Deska*** – Název: MB-ATmega16/32; Používaný krystal: TIC 14.7456 MHz; Používaný typ portu: A 2
***Počítač*** – Použité programy: Khazama AVR Programmer, PcLab2000LT, AVR Studio 4

### Hodnoty:
[ volts/div. | time/div | frequency [MHz] | top value | prescaling ]
- 3V 2us 0.223 32 /0
- 3V 2us 0.189 38 /0
- 3V 2us 0.164 44 /0
- 3V 2us 0.145 50 /0
- 3V 2us 0.129 56 /0
- 3V 2us 0.117 62 /0
- 3V 2us 0.107 68 /0
- 3V 2us 0.098 74 /0
- 3V 2us 0.091 80 /0
- 3V 2us 0.085 86 /0
[ volts/div. | time/div | frequency [kHz] | top value | prescaling ]
- 3V 20us 27.9 32 /8
- 3V 20us 23.6 38 /8
- 3V 20us 20.5 44 /8
- 3V 20us 18.1 50 /8
- 3V 20us 16.2 56 /8
- 3V 20us 14.6 62 /8
- 3V 20us 13.4 68 /8
- 3V 20us 12.3 74 /8
- 3V 20us 11.4 80 /8
- 3V 20us 10.6 86 /8
[ volts/div. | time/div | frequency [kHz] | top value | prescaling ]
- 3V 50us 6.98 32 /64
- 3V 50us 5.91 38 /64
- 3V 50us 5.12 44 /64
- 3V 50us 4.52 50 /64
- 3V 50us 4.04 56 /64
- 3V 50us 3.66 62 /64
- 3V 50us 3.34 68 /64
- 3V 50us 3.07 74 /64
- 3V 50us 2.84 80 /64
- 3V 50us 2.65 86 /64
[ volts/div. | time/div | frequency [kHz] | top value | prescaling ]
- 3V 0.1ms 3.49 32 /128
- 3V 0.1ms 2.95 38 /128
- 3V 0.1ms 2.56 44 /128
- 3V 0.1ms 2.26 50 /128
- 3V 0.1ms 2.02 56 /128
- 3V 0.1ms 1.83 62 /128
- 3V 0.1ms 1.67 68 /128
- 3V 0.1ms 1.54 74 /128
- 3V 0.1ms 1.42 80 /128
- 3V 0.1ms 1.32 86 /128
[ volts/div. | time/div | frequency [kHz] | top value | prescaling ]
- 3V 0.2ms 1.75 32 /256
- 3V 0.2ms 1.48 38 /256
- 3V 0.2ms 1.28 44 /256
- 3V 0.2ms 1.13 50 /256
- 3V 0.2ms 1.01 56 /256
- 3V 0.2ms 0.914 62 /256
- 3V 0.2ms 0.835 68 /256
- 3V 0.2ms 0.768 74 /256
- 3V 0.2ms 0.711 80 /256
- 3V 0.2ms 0.662 86 /256

### Screenshoty:
- **3V 2us 0.145 50 /0**:
  ![[prescale 0.png]]

- **3V 20us 0.145 50 /8**:
	![[prescale 8.png]]

- **3V 50us 0.145 50 /64**:
	![[prescale 64.png]]

- **3V 0.1ms 0.145 50 /256**:
	![[prescale 128.png]]

- **3V 0.2ms 0.145 50 /1024**:
	![[prescale 256.png]]

