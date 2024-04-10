#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string hmhmhm;
    string nazev;
    string nazev2;
    int mezeryyy;
    int srackyNaRadku;

    cout << "1/4 jakej soubor chces otevrit? " << endl;
    cin >> nazev;
    cout << "2/4 do jakyho soubor ho chces zkopirovat? " << endl;
    cin >> nazev2;
    cout << "3/4 kolik mezer zleva? " << endl;
    cin >> mezeryyy;
    cout << "4/4 maximalni pocet znaku na jednom radku? " << endl;
    cin >> srackyNaRadku;

    ifstream souborik(nazev);
    ofstream souborik2(nazev2);

    if (souborik.is_open() && souborik2.is_open()) {
        while (getline(souborik, hmhmhm)) {
            cout << string(mezeryyy, ' ') << hmhmhm << endl;
            for (int i = 0; i < hmhmhm.length(); i += srackyNaRadku - mezeryyy) {
                souborik2 << string(mezeryyy, ' ') << hmhmhm.substr(i, srackyNaRadku - mezeryyy) << endl;
            }
        }

        souborik.close();
        souborik2.close();
    } else {
        cout << "soubor se nepodarilo otevrit" << endl;
    }

    return 0;
}
