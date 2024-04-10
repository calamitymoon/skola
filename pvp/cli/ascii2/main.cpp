#include <iostream>

using namespace std;

void ascii(int b) {
    for (int a = 0; a < b; a++) {
        cout << char(a);
    }
}

int main() {
    int cislicko;
    cout << "cislo: ";
    cin >> cislicko;

    if (cislicko >= 0 && cislicko <= 255) {
        ascii(cislicko);
    } else {
        cout << "napis cislo od 0 do 255.\n";
    }

    return 0;
}


//void ascii(int b) {
//    for (int a = 0; a < b; a++) {
//        if ((a + 1) % 4 == 0) {
//            cout << "\x1b[31m" << char(a) << "\x1b[0m\n";
//        }
//        cout << char(a) << endl;
//        if ((a + 1) % 4 == 0) {
//            cout << "\033[0m";
//        }
//    }
//}

//int main() {
//    int cislicko;
//    cout << "cislo: ";
//    cin >> cislicko;

//    if (cislicko >= 0 && cislicko <= 255) {
//        ascii(cislicko);
//    } else {
//        cout << "napis cislo od 0 do 255.\n";
//    }

//    return 0;
//}
