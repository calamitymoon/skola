#include <iostream>

using namespace std;

int main()
{
    int pole[5];
    int pole2[] = {15,2,7,6,8,5};
    for(int a = 0; a <5; a++) {
        cout << "zadejte cislo -> " << endl;
        cin >> pole[a];
    }

    for(int a = 0; a < 5; a++) {
        cout << " | " << pole[a] << " | ";
    }
    cout << endl;

    for(int a = 0; a < sizeof (pole2)/sizeof (int); a++){
        cout << a << endl;
    }
    return 0;
}
