#include <iostream>

using namespace std;

int main()
{
    int pocetradku = 0;
    cout << "kolik radku chces?" << endl;
    cin >> pocetradku;
    for (int i = 0; i < pocetradku; i++) {
        cout << i << "." << endl;
    }
}
