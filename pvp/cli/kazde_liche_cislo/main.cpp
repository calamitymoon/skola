#include <iostream>
using namespace std;

//
// === pro pochopeni ===
//
// < bool jeSudeCislo >
// pokud je true, tak to vypise sude cisla a pokud je false, tak vypise licha
//
// < int prvky >
// pocet cisel kolik chceme zkontrolovat, zda jsou sude ci liche
//



void dejcisla(bool jeSudeCislo, int prvky, int cislo2[]) {
    cout << "vysledny cisla: ";
    for(int i = 0; i < prvky; i++) {
        int cislo1 = cislo2[i];

        if ((cislo1 % 2 == 0 && jeSudeCislo) || (cislo1 % 2 != 0 && !jeSudeCislo)) {
            cout << cislo1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int prvky;
    cout << "pocet prvku: ";
    cin >> prvky;

    int cislo2[prvky];
    cout << "napis " << prvky << " cisel: ";
    for(int i = 0; i < prvky; i++) {
        cin >> cislo2[i];
    }

    dejcisla(true, prvky, cislo2); // true -> suda; false -> licha

    return 0;
}
