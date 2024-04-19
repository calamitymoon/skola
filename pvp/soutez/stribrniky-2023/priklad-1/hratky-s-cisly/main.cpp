#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int rady1(double x) // řády
{  
    x = abs(x);
    return (x < 10? 0 :   
        (x < 100? 1 :   
        (x < 1000? 2 :   
        (x < 10000? 3 :   
        (x < 100000? 4 :   
        (x < 1000000? 5 :
        (x < 1000000? 6 :
        10)))))));
}

int main()
{
    double cislo;
    string radycisla1;

    cout << "napis mi cislo (klidne i desetinne)" << endl;
    cin >> cislo;

    if (rady1(cislo) < 6)
    {
        int normalni_cast = (int) cislo; // cislo.toInt()
        double desetinna_cast = cislo - normalni_cast;

        bitset<6> normalni_cast_v_binarce(normalni_cast);
        bitset<6> desetinna_cast_v_binarce;

        if (desetinna_cast > 0)
        {
            int mocnitel /*exponent*/ = ceil(log2(desetinna_cast)); // nejblizsi mozna hodnota >= log2(desetinna_cast)
            double na_druhou = pow(2, mocnitel); // 2^mocnitel
            desetinna_cast *= na_druhou; // desetinna cast na druhou
            desetinna_cast_v_binarce = (int) desetinna_cast; // desetinna_cast.toInt()
            desetinna_cast_v_binarce <<= (32 - mocnitel); 
            }

        bitset<6> binarni_cislo = normalni_cast_v_binarce | desetinna_cast_v_binarce;

        cout << cislo << " v binarce je " << binarni_cislo << endl;
    } else {
        cout << "cislo je vice nez sestimistne" << endl;
    }

    return 0;
}



/*



#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int rady1(double x) // řády
{  
    x = abs(x);
    return (x < 10? 0 :   
        (x < 100? 1 :   
        (x < 1000? 2 :   
        (x < 10000? 3 :   
        (x < 100000? 4 :   
        (x < 1000000? 5 :
        (x < 1000000? 6 :
        10)))))));
}

int main()
{
    double cislo;
    string radycisla1;

    cout << "napis mi cislo (klidne i desetinne)" << endl;
    cin >> cislo;

    if (rady1(cislo) < 6)
    {
        int normalni_cast = (int) cislo; // cislo.toInt()
        double desetinna_cast = cislo - normalni_cast;

        bitset<6> normalni_cast_v_binarce(normalni_cast);
        bitset<6> desetinna_cast_v_binarce;

        if (desetinna_cast > 0)
        {
            int mocnitel /*exponent = ceil(log2(desetinna_cast)); // nejblizsi mozna hodnota >= log2(desetinna_cast)
            cout << "nejblizsi mozna hodnota logaritmu desetinne casti cisla = " << mocnitel << endl;
            double na_druhou = pow(2, mocnitel); // 2^mocnitel
            cout << "2^mocnitel = " << na_druhou << endl;
            cout << "desetinna cast = " << desetinna_cast << endl;
            desetinna_cast = desetinna_cast * na_druhou; // desetinna cast na druhou
            cout << "desetinna cast^2 = " << desetinna_cast << endl;
      /*    bitset neumi convertovat desetinne cislo na binarku
            desetinna_cast_v_binarce = (int) desetinna_cast; // desetinna_cast.toInt()      
            cout << "desetinna_cast.toInt() = " << desetinna_cast_v_binarce << endl;
            desetinna_cast_v_binarce <<= (32 - mocnitel); // presunuti binarneho souctu
            cout << "presunuti binarneho souctu = " << desetinna_cast_v_binarce;
        }

        bitset<6> binarni_cislo = normalni_cast_v_binarce | desetinna_cast_v_binarce;

        cout << cislo << " v binarce je " << binarni_cislo << endl;
    } else {
        cout << "cislo je vice nez sestimistne" << endl;
    }

    return 0;
}







*/