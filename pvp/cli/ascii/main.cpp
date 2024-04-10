#include <iostream>

using namespace std;

int main()
{
    for(int i = 32; i < 255; i++){
        cout << i << ": " << char(i) << " ";
        if ((i - 31) % 4 == 0) {
            cout << endl;
        }
    }
//    int sloupec = 0;
//    for(int i = 32; i < 255; i++){
//        cout << i << ": " << char(i) << " ";
//        sloupec = sloupec + 1;
//        if (sloupec == 4){
//            cout << endl;
//            sloupec = 0;
//        }
//    }
}
