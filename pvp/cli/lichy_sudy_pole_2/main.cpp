#include <iostream>
using namespace std;

int SCITANIpozice(int pole[], int VeLiKoSt, bool SUDOSTcislicek) {
    int SOUCETcislicek = 0;
    for (int i = 0; i < VeLiKoSt; i++) {
        if ((i % 2 == 0) == SUDOSTcislicek) {
            SOUCETcislicek += pole[i];
        }
    }
    return SOUCETcislicek;
}

int main() {
    int cisla[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int VeLiKoSt = sizeof(cisla) / sizeof(cisla[0]);

    int soucetSUDYCHcisel = SCITANIpozice(cisla, VeLiKoSt, true);
    int soucetLICHYCHcisel = SCITANIpozice(cisla, VeLiKoSt, false);

    cout << "soucet sudych cislicek: " << soucetSUDYCHcisel << endl;
    cout << "soucet lichych cislicek: " << soucetLICHYCHcisel << endl;

    return 0;
}
