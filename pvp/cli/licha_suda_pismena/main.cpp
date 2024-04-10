#include <iostream>
using namespace std;

void vypis(string s, bool sudeCisloAnoNe) {
    for (int i = 1; i < s.length(); i++) {
        if ((i % 2 == 0 && sudeCisloAnoNe) || (i % 2 != 0 && !sudeCisloAnoNe)) {
            cout << s[i];
        }
    }
}

int main() {
    string sracka;
    bool sudeCisloAnoNe;

    cout << "napis veticku nejakou: ";
    getline(cin, sracka);

    cout << "lichy pismena (0) nebo sudy pismena (1) ";
    cin >> sudeCisloAnoNe;

    vypis(sracka, sudeCisloAnoNe);

    return 0;
}
