#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    cout << "napis pocet radku -> ";
    cin >> x;

    for(int a = 1; a <= x; a++)                                              {
        for(int b = 1; b <= a; b++) {
            cout << "*";
        }
//        cout << endl;
//        if (a % 3 == 0) {
//            cout << "nesnasim hvezdicky" << endl;
//        }
    }
    return 0;
}
