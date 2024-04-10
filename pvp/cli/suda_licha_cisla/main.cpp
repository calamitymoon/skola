#include <iostream>

using namespace std;

int main()
{
    // suda a  licha cisla
    int cislo = 0;
    cout << "napis cislo" << endl;
    cin >> cislo;
    if (cislo == 0) {
        cout << "cislo je nula" << endl;
    } else if (cislo % 2 == 0) {
        cout << "cislo je sude" << endl;
    } else {
        cout << "cislo je liche" << endl;
    }

}
