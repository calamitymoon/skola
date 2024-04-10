#include <iostream>

using namespace std;

//int secti(int x, int y) {
//    return x+y;
//}

// TAKY FUNGUJE, ALE JE TO MUJ KOD A NE PANA UCITELE
//int faktorial(int a) {
//    if (a == 0 || a == 1) {
//        return 1;
//    } else {
//        return a*faktorial(a-1);
//    }
//}
int faktorial(int a) {
    if (a == 0 || a == 1) {
        return 1;
    } else {
        return a*faktorial(a-1);
    }
}

//void vypis(int pole[], int pocetprvku) {
//    for(int i = 0; i < pocetprvku; i++) {
//        cout << pole[i] << " | ";
//    }
//    cout << endl;
//}

//int main() {
//    int a,b;
//    cout << "napis cislo: " << endl;
//    cin >> a;
//    cout << "napis dalsi cislo: " << endl;
//    cin >> b;
//    cout << "soucet je: " << secti(a,b) << endl;
//    int p[] = {10,1,7,9,2,5};
//    vypis(p,sizeof(p)/sizeof(int));
//    return 0;
//}

int main() {
    int cislicko;
    cout << "napis jakekoliv kladne cislo: " << endl;
    cin >> cislicko;
    if (cislicko < 0) {
        cout << "faktorial pro zaporne cisla neexistuje" << endl;
    }
    else {
        cout << "faktorial cisla " << cislicko << " je " << faktorial(cislicko) << endl;
    }
    return 0;
}
