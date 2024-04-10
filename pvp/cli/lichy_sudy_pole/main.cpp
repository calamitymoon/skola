#include <iostream>

using namespace std;

int sectiPole(int hustyPole[], int velikoooost) {
    int SOUCETcislicekCislicek = 0;
    for (int i = 0; i < velikoooost; i++) {
        SOUCETcislicekCislicek += hustyPole[i];
    }
    return SOUCETcislicekCislicek;
}

int main() {
    int hustyPole[] = {5, 5, 5, 5, 5};
    int velikoooost = sizeof(hustyPole) / sizeof(hustyPole[0]);

    int hotovejVysledek = sectiPole(hustyPole, velikoooost);

    cout << "SOUCETcislicek cisel v poli: " << hotovejVysledek << endl;

    return 0;
}

void vypis(string s, bool sudeCisloAnoNe) {
    for (int i = 1; i < s.length(); i++) {
        if ((i % 2 == 0 && sudeCisloAnoNe) || (i % 2 != 0 && !sudeCisloAnoNe)) {

            cout << s[i];
        }
    }
}
