#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//int main()
//{
//    string neco;
//    cout << "napis neco" << endl;
//    getline(cin, neco);

//    for(char &nevim : neco) {
//        if (nevim == 'ě' || nevim == 'š' || nevim == 'č' ) {
//            nevim = tolower(nevim);
//        }
//        else {
//            nevim = toupper(nevim);
//        }
//    }

//    cout << "upravenej text: " << neco << endl;
//}

int main()
{
    system("chcp 6001"); // utf-8

    string neco;
    cout << "napis neco" << endl;
    getline(cin, neco);

    for(char &nevim : neco) {
        if (isalpha(nevim)){
            nevim = toupper(nevim);
        }
    }
        cout << "upravenej text: " << neco << endl;
}
