import math

pocet_vzorku = 60
amplituda = 127 / 2  # for 7-bit resolution (0-127), centered
offset = amplituda

# generujem 60 vzorku sinusovky, ktere jsou v rozsahu 0-127 a zarovnane na stred (pomoci offsetu)
vzorky = [
    int(offset + amplituda * math.sin(2 * math.pi * i / pocet_vzorku))
    for i in range(pocet_vzorku)
]

vysledek = []
for i in range(0, pocet_vzorku, 2):
    vysledek.append(f".db {vzorky[i]},{vzorky[i+1]}")

for radek in vysledek:
    print(radek)
