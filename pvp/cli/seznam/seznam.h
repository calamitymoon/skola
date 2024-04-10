    #ifndef SEZNAM_H
    #define SEZNAM_H

    #include "prvek.h"

    class Seznam {
    private:
        Prvek *hlava, *zarazka;

    public:
        Seznam();
        void vlozNaKonec(int Data);
        void vlozNaZacatek(int Data);
        void vypis();
        bool najdi(int co);
        Prvek *najdiPrvek(int co);
        void vlozZa(int co, int zaCo);
    };

    #endif
