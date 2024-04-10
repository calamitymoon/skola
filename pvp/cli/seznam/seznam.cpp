#include "seznam.h"
#include <iostream>

Seznam::Seznam() {
    hlava = new Prvek();
    zarazka = hlava;
}

void Seznam::vlozNaKonec(int Data) {
    zarazka->setData(Data);
    zarazka->setDalsi(new Prvek);
    zarazka = zarazka->getDalsi();
}

void Seznam::vlozNaZacatek(int Data) {
    Prvek *novyPrvek = new Prvek(Data);
    novyPrvek->setDalsi(hlava);
    hlava = novyPrvek;
}

void Seznam::vypis() {
    Prvek *pomocny = hlava;
    while (pomocny != zarazka) {
        std::cout << pomocny->getData() << " | ";
        pomocny = pomocny->getDalsi();
    }
}

bool Seznam::najdi(int co) {
    Prvek *pomocny = hlava;
    while (pomocny != zarazka) {
        if (pomocny->getData() == co) {
            return true;
        }
        pomocny = pomocny->getDalsi();
    }
    return false;
}

Prvek *Seznam::najdiPrvek(int co) {
    Prvek *pomocny = hlava;
    while (pomocny != zarazka) {
        if (pomocny->getData() == co) {
            return pomocny;
        }
        pomocny = pomocny->getDalsi();
    }
    return nullptr;
}

void Seznam::vlozZa(int co, int zaCo) {
    Prvek *zaCoPrvek = najdiPrvek(zaCo);
    if (zaCoPrvek != nullptr) {
        Prvek *novyPrvek = new Prvek();
        novyPrvek->setData(co);

        Prvek *zaCoPrvekDalsi = zaCoPrvek->getDalsi();
        zaCoPrvek->setDalsi(novyPrvek);
        novyPrvek->setDalsi(zaCoPrvekDalsi);
    }
}
