#include <iostream>

using namespace std;

int main() {
    int nejvyssiCislajz = -1;
    int VZUM;

    do {
        cout << "davaj cislo >_ ";
        cin >> VZUM;

        if (VZUM > nejvyssiCislajz) {
            nejvyssiCislajz = VZUM;
        }
    } while (VZUM != 0);
    cout << "nejvyssi cislajz je >_ " << nejvyssiCislajz << endl;

    return 0;
}


