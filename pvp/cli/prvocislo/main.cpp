//#include <iostream>

//using namespace std;

//bool prvnocislo(int cislicko) {
//    if (cislicko <= 1) {
//        return false;
//    }
//    for (int i = 2; i*i <= cislicko; i++) {
//        if (cislicko % i == 0) {
//            return false;
//        }
//    }
//    return true;
//}

//int main() {
//    char volba;
//    do {
//        int cislicko;

//        cout << "napis mi cislicko: ";
//        cin >> cislicko;

//        if (prvnocislo(cislicko)) {
//            cout << cislicko << " je prvocislo." << endl;
//        } else {
//            cout << cislicko << " neni prvocislo." << endl;
//        }

//        cout << "chces pokracovat? (j / n)" << endl;
//        cin >> volba;
//    } while (volba == 'j' || volba == 'J');
//    return 0;
//}

///////////////////////////////////// DALSI KOD /////////////////////////////////////

//#include <iostream>

//using namespace std;

//bool prvnocislo(int cislicko) {
//    if (cislicko <= 1) {
//        return false;
//    }
//    int i = 2;
//    while (i*i <= cislicko) {
//        if (cislicko % i == 0) {
//            return false;
//        }
//        i++;
//    }
//    return true;
//}

//int main() {
//    char volba;
//    do {
//        int cislicko;

//        cout << "napis mi cislicko: ";
//        cin >> cislicko;

//        if (prvnocislo(cislicko)) {
//            cout << cislicko << " je prvocislo." << endl;
//        } else {
//            cout << cislicko << " neni prvocislo." << endl;
//        }

//        cout << "Chces zadat dalsi cislicko? (jo/ne): ";
//        cin >> volba;
//    } while (volba == 'j' || volba == 'J');

//    return 0;
//}

///////////////////////////////////// DALSI KOD /////////////////////////////////////

#include <iostream>

using namespace std;

char konec;
do{
    int c,p=0;
    cout << "napis cislo" << endl;
    cin >> c;
    int i = 1;
    do{
    if (c % i == 0)
        p++
    i++
    }while (p<=2&&i<=c);
    if(p==2){
        cout << "je to prvocislo" << endl;
    }else cout << "neni to prvni cislo" << endl;
    cout << "prisel jsem na to po " << i-1 << " interakcich." << endl;
    cout << "pro dalsi cislo stiskni A";
    cin >> konec;
}while(konec =='a' || konec =='A');
