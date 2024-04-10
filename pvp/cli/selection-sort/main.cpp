#include <iostream>

using namespace std;

//  a, b        >>      docasny inty; pouzivaji se ve funkci vymena
//  c           >>      docasny ulozeni hodnoty
//  velikost           >>      cislo co urcuje jak je velky pole co se ma tridit
//  nejmensi    >>      cislo co oznacuje index nejmensiho
//                      cisla v nesetrideny casti pole
//  j           >>      iterator ve for loopu;
//                      pouziva se k prohazovani prvku pole za
//                      aktualnim cislem, aby nasel nejmensi cislo

// funkce co pomaha k vymene cislicek
void vymena(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

// funkce pro trideni
void selektivniTrideni(int pole[], int velikost) {
    for (int i = 0; i < velikost - 1; ++i) {
        int nejmensi = i;
        for (int j = i + 1; j < velikost; ++j) {
            if (pole[j] < pole[nejmensi]) {
                nejmensi = j;
            }
        }
        vymena(pole[i], pole[nejmensi]);
    }
}

// funkce co vypisuje pole
void vypisPole(int pole[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << pole[i] << " ";
    }
    cout << endl;
}

int main() {
    int pole[] = {64, 25, 12, 22, 11};
    int velikost = sizeof(pole) / sizeof(pole[0]);

    cout << "pred selection sortem >_ ";
    vypisPole(pole, velikost);

    selektivniTrideni(pole, velikost);

    cout << "po selection sortu >_ ";
    vypisPole(pole, velikost);
    
    return 0;
}
