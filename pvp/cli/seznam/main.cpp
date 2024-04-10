#include <iostream>
#include "prvek.h"
#include "seznam.h"

using namespace std;

int main()
{
    Prvek m;    
    cout << m.getData() << endl;
    m.setData(10);
    cout << m.getData() << endl;
    Prvek h(158);
    cout << h.getData() << endl;

    Seznam s;
    s.vlozNaKonec(10);
    s.vlozNaKonec(158);
    s.vlozNaKonec(7);
    s.vlozNaZacatek(666);
    s.vypis();
    cout << endl;
    cout << "Je tam 10? " << s.najdi(10) << endl;
    cout << "Je tam 100? " << s.najdi(100) << endl;
    return 0;
}
