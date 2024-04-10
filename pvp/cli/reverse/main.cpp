#include <iostream>
#include <string>

using namespace std;

//string otoc(string opak) {
//    int delka = opak.length();
//    for (int i = 0; i < delka / 2; i++) {
//        swap(opak[i], opak[delka - i - 1]);
//    }
//    return str;
//}

//void otoc(string opak) {
//    string otoceny;
//    for (int i= opak.length()-1; i >= 0; i--) {
//        otoceny += opak[i];
//    }
//}

string otoc(string opak) {
    string otoceny = "";
    for (int i= opak.length()-1; i >= 0; i--) {
        otoceny += opak[i];
    }
    return otoceny;
}

int main() {
    cout << "zprava >_ ";
    string nevim;
    getline(cin, nevim);

    string obracene = otoc(nevim);

    cout << "\nreversnuta zprava >_ " << obracene << endl;

    return 0;
}
