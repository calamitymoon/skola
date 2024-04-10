#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream outFile("data.nevim", ios::binary);
    for(int i = 0; i < 10; i++) {
        outFile.write(reinterpret_cast<char*>(&i), sizeof(int));
    }
    outFile.close();

    ifstream inFile("data.nevim", ios::binary);
    vector<int> cisla(10);
    for(int &cislo : cisla) {
        inFile.read(reinterpret_cast<char*>(&cislo), sizeof(cislo));
    }
    inFile.close();

    for(int cislo : cisla) {
        cout << cislo << endl;
    }

    int pozice = 5;
    int hodnota = 3876;

    fstream file("data.nevim", ios::in | ios::out | ios::binary);
    file.seekp((pozice * sizeof(int)));
    file.write(reinterpret_cast<char*>(&hodnota), sizeof(hodnota));

    file.close();

    inFile.open("data.nevim", ios::binary);
    int cislo;
    while(inFile.read(reinterpret_cast<char*>(&cislo), sizeof(cislo))) {
        cout << cislo << endl;
    }
    inFile.close();

    inFile.open("data.nevim", ios::binary | ios::ate);
    if (!inFile.is_open()) {
        cerr << "soubor nejde otevrit." << endl;
        return 1;
    }
    streampos fileSize = inFile.tellg();
    inFile.close();

    int velikostIntu = sizeof(int);
    int pocetZaznamu = fileSize/velikostIntu;

    cout << "velikost souboru je >_ " << fileSize << " bytu." << endl;
    cout << "pocet zaznamu v souboru je >_ " << pocetZaznamu << endl;

    return 0;
}