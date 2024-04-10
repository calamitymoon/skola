#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> cisla;
    int vstupik;

    while (true) {
        cout << "dej dej cislicka :O >_ ";
        cin >> vstupik;

        if (vstupik == 0) {
            break;
        }

        cisla.push_back(vstupik);
    }

    sort(cisla.begin(), cisla.end(), greater<int>());

    cout << "cislicka od nejvyssiho po nejnizsi :O >_ " << endl;
    for (int cislo : cisla) {
        cout << cislo << " ";
    }

    return 0;
}
