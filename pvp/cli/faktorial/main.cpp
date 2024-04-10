#include <iostream>

using namespace std;

int main()
{
    int c = 0;
    cout << "faktorial jakeho cisla chces ?" << endl;
    cin >> c;
    float f = 1;
    for (int n = c; n > 1; n--) {
        f *= n;
    }
    cout << "faktorial cisla " << c << " je " << f << "." << endl;
}
