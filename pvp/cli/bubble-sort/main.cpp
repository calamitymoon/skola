#include <iostream>

using namespace std;

int b = 0;

void bubbleSort(int poleCisel[], int pocetPrvkuVpoli) {
    // smycka co prochazi polem
    for (int a = 0; a < pocetPrvkuVpoli - 1; a++) {
        // smycka co porovnava a prohazuje
        while (b < pocetPrvkuVpoli - a - 1) {
            if (poleCisel[b] > poleCisel[b + 1]) {
                // samotny prohazovani kdyz nejsou v dobrym poradi
                int drzimSi = poleCisel[b];
                poleCisel[b] = poleCisel[b + 1];
                poleCisel[b + 1] = drzimSi;
            }
            b++;
        }
    }
}

// podiva se do pole a vypise vsechno co v nem be
void vypisPole(int poleCisel[], int velikostPole) {
    for (int a = 0; a < velikostPole; a++) {
        cout << poleCisel[a] << " ";
    }
    cout << endl;
}

void nakresliAscii() {
    cout << R"(
    
~~~~~~!~~~!~~~~~~~~~~~~~~~!!~~!!!!!!!!!~~!!~~~~!!!!!!~!!~!~~~~~!!~~~~~~~~!~~~~~~~~~~~~~!~!~~~~~~~~~~
~~~~~!!~~~!~~~~~~~~~~~~!!!~~!!!~~~!!!!!~~!!~!!~!!~!!!!~!~!!~!~~!~~~!~~!~~!~~~~~!~~~~~~~~~!~~~~~~~~~~
~~~~!~~~~~~~~~~~~~~!~~!!!!~!!~~~~!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!~!~~~~~!~~~~~~~~~!~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~!~~~!~!!!!~~~~~~~~~!!!!!!77??JJYY5P555555YJJJYYJ?77!~~~~!!!~~!!~~~~~~~~~~~~~~~~~~
~~~~~~~~!~~~~~!~~~~~~~~~~!!~~~~~!7?YY5555PPGGGPGBBBGGGGGGGGGBBBGGBGBGGPPJ7~~~!!~!~~~~~~~~~~~~~~~~~!~
~~~~~~~~~~~~~~~!~~~~~~!~~~~!!7J5PPPPPPPPPPGGPPGGPGGGGGGGGGGGGGGGGGGBBBBBBG5?!~!~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~!~~~!~~~~~~!~~~!?YPPGP55PPPPPPPGGGBBBBBBGBBBBBBBBBBBBBBGGGBBBBBBGGPJ!~~~~!~~~~~~~~~~~~~~~~
~~~~~~~~~~~!~~~~~~~~~~~!J5PP555PPPPPPPPPGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBPY7~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~!?55555PPPPPPPPPPPPP5PGPGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP5J!^!~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~?55555PPPPPPPGGGBBBBBBBBBBBBGBBBBBBBBBBBBBBBBBBBBBBB&BBBBBGBPP5J!~~!~~~~~~~~~~~~
~~~~~~~~!~~~~~~~~~!55Y5555PGGGBGBBBBBBBBBBBBBBB&&BBBBBBBBBBBBBBBBBBBBBBBBBBB&BB&BGGGGY7~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~75P555PGGGGGGGBBBBBBBBBBBBBBBBB&&BB&BBBBBBBBBBBBBBBBB&BBBBBBBBBBBBBBBG?~~~~~~~~~~~~
~~~~~~~~~~~~~~~^755555PPPGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGPPPPGGGBBBBBBBBBB&BGBBBBJ!~~~~~~~~~~
~~~~~~~~~~~~~~~75YY55555PGGGGGGGGGGGGGGGBBBBBBBBBBBBGGGGGGGPPPPP555555PPPPPGBBBBBB&BGGGBB5J!~~~!~~~~
~~~~~~~~~~~~~^?5Y5P55PPPGGPPGGGGGGGPPGGGBBBBGBBBGGGGPPPP55555555555555555555PGB&BBB&BGPGBGPP?~~~~~~~
~~~~~~~~~~~~^?5YPP55PPPPPPPPPPPPP55PPGGGGBBGGGGGPGPPP5555Y5YY5Y555555555555555B&&&BBBBGGGBGPG?^~~~~~
~~~~~~~~~~~~7P55P55555555PPP5555YY55PPPPPGGGGGPP55555YYYYYYYYYYYY555555555Y555GBB&BBBBBGGBBBPP?^~~~~
~~~~~~~~~~^~PP555555PP5PPP5555YY5555555PPPPPPPP55Y5YYYYYYYYYYYYY55YY5555555555PBBBBBBBBBGGBGBPP~~~~~
~~~~~~~~~~^JP5YPPPPP5PPP5YYYYYYYY55555PPPGP55555YYYYYYYYYYYYYYYY55Y55555555555PPBBBBBBBBBGGGBBG7^~~~
~~~~~~~~~~7P5JYGPPPPPP555Y5YYYYYYYY555555555Y5YYYYYYYJYYYYYYYYYYYYYY5555555555PPBBBBBBBBBGBBBBB!!~~~
~~~~~~~~^~55Y5P55PPPP5PP5YYYYY5YYYYYYYYJJJJJJJJJJJJJJJJYYYYYYYYYYYYYY55555555YYPBBBBBBBBBBGBBGG?~~~~
~~~~~~~~^?P55P55PPPPGGG5YJYYYYJJJ??????777???J?JJJJJJJJYYYYYYYYYYY5YYY55555555Y5PBBBBBBBBBBBBGG7^~~~
~~~~~~~~~PPP555PGPPGGGPYJJ77777777??77777777??????J?JJJYYYYYYYYYYYY555PP55555555YPBBBBBBBBBBGGG7~~~~
~~~~~~~^?P55PPPGG5PPGP5Y7!!7!!??YYJJJJJJ???JJ??????7JJJJYYYYYY5PPPGGGGGGGGGGP55YY5GBBBBBBBBBBGGJ^~~~
~~~~~~~^Y55PGPPPP55PGP5?!77!7J55555PPPGGPPPP5YYYJ???JJJYYYY5PPPGBBBBBGGGGGPGPGPP5Y5BBBBBBBGBBGGP7~~~
~~~~~~~^5P5GGGG5555PG5Y!77?JJJJJ???JJJYYYYYYYJJYJ??7?JYY55PPGGPPGP55YYYY555PPPPPPYYPBBBBBBGBBBBBY~~~
~~~~~~~^PB5BGP55555PP5!!!7??!!!!!???JJYYYYJJJJ?7!7!!7?5Y5PPGGGPGGPPPP55PPPPP5PP555Y5PGBBBBBBBBBBP!~~
~~~~~~~^5BPBG5PP55PP5?!7!!!~~!7??YY         J??7!!!7?JYYPP5PGGBBB         GBGPPP555YYPBBBBBBBBBBG!^~
~~~~~~~~7BBGPPBP5555J~!!!!!!7JY55J7         5?777777?JYY5P5PPGBGG         BGGGGGP555YYGBBGGBBBBBGJ~~
~~~~~~~~~BGPBBB55P5J!~!~!!!7JJJJJ77         Y?77777??JYY55P5PPPGG         P55PPP55555YYGBGGGGBBBJ!!~
~~~~~~~^YBGGBBB55PY!!7!~!777777777???JJYYYYY?777777??JYY5555PP5PPPPPPPP555555Y55555555Y5GBGGBPBG7~~~
~~~~~~~^PBB5Y5PP557!!!!!7777777??????JJJJJJ?7777777?JYY55555PPPPPPPPPPP55555555Y5555YYY5PBGBBPBJ~~~~
~~~~~~~~?BP7PYJPGJ!!!!!7777777??JJ??JJJJJJJ?7777?7??JYYY5555PPPPPPPP55555555555555YY5YYY5GPGBPP~~~~~
~~~~~~~~~GY7G77P57~!!!!!!!77!7?????????JJJ??????7!!7?YYJY55555PPPP5555555555555555Y55YYYYPP5GP?^~~~~
~~~~~~~~~5J7P!!5J~!!!!!!!!!!777??????J?JJJJJY777?J??JYYYPPPP555PGP5555555555555555555YYYJ5G5PJ^~~~~~
~~~~~~~~~7J7Y~!Y?!!!!!!!!!!77777????JJJJJYY5Y77YBBPJ7Y55GBBBP5PPGP5555Y5555555555555555YY5P5PJ^~~~~~
~~~~~~~~~~Y!?!Y5?!!!!!!!!!!!7777????JJJJYY5YYJJYYJ?7?JY5PPGGPGGGP5YY5YYYY555555555555YYYY555P5^~~~~~
~~~~~~~~~^Y7!!YPJ~!!!!!!!!!!!!!7777?JJJJJYYJJ?????77J5JJ5GPPGP5555YYYYYYY555555555555YYYY55YP5~~~~~~
~~~~~~~~~^7Y!!!YY!!!!!!!!!!!!!!!777?JJJYYYJ????????J55JJYPPPP55555Y5YYYYYY5555555555Y5YYY5YYBJ~~~~~~
~~~~~~~~~~^J?!~~7777!!!!!!!!!!!!777?JJJJJ?????777??JJJ55555555555555YYY555555555555555YYY5YYB7^~~~~~
~~~~~~~~~~^~?7!!!?777!!!!!!!!!!!7777??J????7777JJJYY5YPGPPPPPP555555555555555555555555YY555PJ~~~~~~~
~~~~~~~~~~~~~7!!!!?77777!!!!!!!!7777?J???JJJJYYY5P55555PPPPPGGGGGPYYYY55555555555555555Y55PJ~~~~~~~~
~~~~~~~~~~~~~~7!!!??7777!!!!!!!!77777?JY5P5J????JYYYYYYY5PPPGPPGPBG5YYYY555555555555555YG5?!~~~~~~~~
~~~~~~~~~~~~~^7Y7!?5?!777!!!!!!!!!!!7JYYJ?!!77???JJJJYYYY55555555555YYJYY5555555555555Y5P?!~~~~~~~~~
~~~~~~~~~~~~~~!77~75Y7!7777!!!!!!!!7?JJ?77777???JYYYYYYYYJJJY5Y5555555YYY5555555555Y555YY7~~~~~~~~~~
~~~~~~~~~~~~~~~~~~!~!J?!77!!!!!!!!!7777777777???JJJJJYYYY5YYYY5555555555Y5555555555555YYJ7~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~^!J?!!7!!!!!!!!7777777777????7?JJJJJJYYYYY555555555555555555555555YJY!~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~!Y?!7!!!!!!!!!77777777??????JYYYJJJYY5555555PPPPPP5PP5555555555YJYY!~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~?J?7!!!!!!!!7???????JJ?JJJJYYYYYJYYY55PPPPGGGPPPGPPPGPP5P5P555YYYY7~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~!7??777777777???JJJYJJYYYJYY555YY55PPPPGGGGGGGGGGGGPPPPPPPPP5YYYYYJ~~~~~~~~~~
~~~~~~~!~~~~~~~~~~~~~~~~7777?777777???JJJYYYYYYY5555P55PPPPPPGGGGGGBBGGGGGGGGGPPPGP5YYYYYY^~~~~!~~~~
~~~~~~~~~~~~~~~~~~~~~~~~!!77???7777J?JJYY55YYY5PP55PGBPPGGPGGGBBBBBBBBBGGGGGGGGPPP55Y5YYY5J!~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~!!!7????7???JYY55555P5PGGPBBBBBBBGGGGBBBBBBBBBBBBBBGGGPP55555YY5555JJ55J7~~
~~~~~~~~~~~~~~~~~~~~~~~~~!!~!7!77??77?YYY5PPPGGGGGGBBBBBBBBBBBBBBBBBBBBBBBGBGGPPP5555555P55YG&&&&BBG
~~~~~~~~~~~~~~~~~~~~~~~~~~!!~!!!7?7??????Y5PP55PGBBBBBBBBBBBBBBBBBBBBBGBGGGPP55P555555PP55PB&BB&&B&&
~~~~~~~~~~~~~~~~~~~~~~~~~~!!~~~~~!!77?J??????JJYYY5Y5555PGPGGGGBGBBGGGGBGGPPP5555555PGPPGBB&&&B&BBBB
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!77??J???JJJJJYYYYY5555GGPPGGGGGGGBPPP5PP555555PP5G&&&&&&&&&B&&&
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!!7!77???JJJJJYY5555P55PPPPPGGP555555555555PPPPGB&&&&&&&&&&&&&&
~~~~~~~~~~~~~~~~~~~~~^~~!!!~~~~~~~~~!!!!!!!7777??JJJJJYYY555PP5YYJJYYJYYYYYYY5P55YGB&&&&&&&&&&&B&&&B
~~~~~~~~~~~~~~~~~^!?????7!!~~~~~~~~~~~~!!!!!!7777?????JJYJJJ?777?7???JJYYJY555YJPB&&B&&&&&&&&&&&&&&B
~~~~~~~~~~~~~~~!JPGY7!!~!!!~~~~~~~~~~~~!~~!!!!!!7777???77!!!!7777??JJJJJJJYYJ?5B&&&&&&&&&&B&&&&&&&&B
!!!!!~~~~~~7J5GBGJ~~!!!!!!!~~~~~~~~~~~~~~~!!!!!!!!7777!!!!!7!777???JJ?JJJJ??5B&&BB&&&&&&&&&&&&&&BBBB
~~~~~~!7JPGBBBBJ~~~!~~!~~~~~~~~~~~~~~~~~~~!!!!!!!!!!!~~!!!!!!!7??????JJ?775B&&BB&B&&&&&&&&&&&&&&&&&&
~!7JYPBBBBBB&5!~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~^~~~~!!!7777777777?5B&&BB&&BB&&&&&BBBBBBBBBBBBB
PBBBBBBBBBBBJ~~~~~~~~~~~~~~~~~~~~~~~^~!7777777???????????JJJJYYYYYYYYY5GGGPPPPPGGGGPPPPPPPPPGPPPGGPP
BBBBBBBBBBG7~~~~~~~~~~~~~~~~~~~~~~~^~YBBGGPGGGBBBBBBBBBBBBBBBBGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB

    )" << endl;
}

int main() {
    int poleCisel[] = {64, 34, 25, 12, 22, 11, 90};
    int pocetPrvkuVpoli = sizeof(poleCisel) / sizeof(poleCisel[0]);
    cout << "nesrovnany pole >_ ";
    vypisPole(poleCisel, pocetPrvkuVpoli); // nejdriv vypisu neserazeny pole
    bubbleSort(poleCisel, pocetPrvkuVpoli); // potom pole seradim
    cout << "srovnany pole >_ ";
    vypisPole(poleCisel, pocetPrvkuVpoli); // a nakonec pole vypisu znova, ale uz serazeny

    nakresliAscii();
    
    return 0;
}
