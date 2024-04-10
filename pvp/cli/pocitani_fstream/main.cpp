//#include <iostream>
//#include <fstream>

//using namespace std;

//int main()
//{

//    ifstream vstup("1.txt");
//    int a,b;
//    if(vstup.is_open()) {
//        vstup >> a;
//        vstup >> b;
//        cout << "acko je " << a << " a becko je " << b << "\n-> jejich soucet je " << a+b << endl;
//    vstup.close();
//    } else {
//        cout << "soubor se nepodarilo otevrit" << endl;
//    }
//}

/// //////////// ////////////////////////// /////////////// ///////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream kouzla("soubor.txt");

    int pocet = 0;
    int cislo;

    while (kouzla >> cislo) {
        pocet++;
    }

    cout << "pocet cisel v souboru \"soubor.txt\" je " << pocet << endl;
}
