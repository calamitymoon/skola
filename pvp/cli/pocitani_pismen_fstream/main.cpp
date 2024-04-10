#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char znak;

    cout << "napis znak >> ";
    cin >> znak;
    fstream kouzla("soubor.txt");

    char pismenko;
    int pocetA = 0;

    while (kouzla >> pismenko) {
        if (pismenko == znak) {
            pocetA++;
        }
    }

    cout << "pocet pismen \'a\' v souboru \"soubor.txt\" je " << pocetA << endl;
}
