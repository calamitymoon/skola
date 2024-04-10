//#include <iostream>
//#include <fstream>

//using namespace std;

//int main()
//{
//    ofstream soubor("soubor.txt");
//    if (soubor.is_open() == true) {
//        soubor << "cau, to se mas.\n\nahoj, ja jsem soubor.\ncau, to se mas." << endl;
//        soubor.close();
//    } else {
//        cout << "soubor se nepodarilo otevrit!" << endl;
//    }
//}

//   /////////////////////////////////////////////////////////////////////////////////////////////////////   //

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int pocetCisel;
    cout << "kolik cisel" << endl;
    cin >> pocetCisel;
    ofstream soubor("soubor.txt");
    if(soubor.is_open()) {
        for(int i = 1; i <= pocetCisel; i++)
            soubor << i << endl;
        soubor.close();
        } else {
        cout << "soubor nelze otevrit" << endl;
    }
}

