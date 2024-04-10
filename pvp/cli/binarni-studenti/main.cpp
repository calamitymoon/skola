#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Student {
    char jmeno[50];
    int vek;
    double prumer;
};

void zapisStudenta(vector<Student> & studenti, string &nazevsouboru) {
    ofstream outFile(nazevsouboru, ios::binary);
    if (!outFile) {
        cerr << "soubor nejde otevrit pro zapis." << endl;
        return;
    }
    for (auto & student : studenti) {
        outFile.write(reinterpret_cast<char *>(&student), sizeof(Student));
    }
    outFile.close();
}

vector<Student> zobrazStudenta(string& nazevsouboru) {
    vector<Student> studenti;
    ifstream inFile(nazevsouboru, ios::binary);
    if (!inFile) {
        cerr << "soubor nejde otevrit pro cteni." << endl;
    }
    
    Student temp;
    while(inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        studenti.push_back(temp);
    }
    inFile.close();
    return studenti;

}

int main() {
    vector<Student> E3A = {
        {"Petr Hypius", 18, 3.5},
        {"Dominik Juza", 17, 3.7},
        {"Vojta Vasek", 18, 2.2},
    };

    string nazevsouboru = "studenti.data";
    zapisStudenta(E3A, nazevsouboru);

    return 0;
}