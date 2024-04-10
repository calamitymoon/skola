#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string picus;
    ifstream souborPicuse("souborpicuse.txt");
    if(souborPicuse.is_open()) {
        while(getline(souborPicuse,picus)){
            cout << picus << endl;
        }
        souborPicuse.close();
    } else {
        cout << "soubor se nepodarilo otevrit" << endl;
    }
}
