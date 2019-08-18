#include <iostream>
 /* na moich testach dziala dobrze - spoj nie przyjmuje !!! (ludzie w komentarzach pisza ze im tez!! */
 // musi sie to dac lepiej, latwiej, prosciej, szybciej zrobic!!
 // to rozwiazanie jest kijowe!
using namespace std;
/*
    * 0 - polnoc
    * 1 - polodnie
    * 2 - zachod
    * 3 - wschod
*/
int main()
{
    short testy;                                  // ile zestawow
    int lWsk, suma01, suma23;                     // ile wskazowek w zestawie
    cin >> testy;
    for (int i = 0; i < testy; ++i) {
        suma01 = 0;                                       // zerowanie, przed kazda iteracja
        suma23 = 0;
        cin >> lWsk;
        int kierunek[lWsk], kroki[lWsk];                   // rezerwacja pamieci
        for (int j = 0; j < lWsk; ++j) {
            cin >> kierunek[j] >> kroki[j];
            if (kierunek[j] == 0) {                       //jak idzie na polnoc to dodaje do sumy, jak na polodnie to odejmuje
                suma01 += kroki[j];                       //zachod-wschod analogicznie
                continue;
            }
            else if (kierunek[j] == 1) {
                suma01 -= kroki[j];
                continue;
            }
            else if (kierunek[j] == 2) {
                suma23 += kroki[j];
                continue;
            }
            else if (kierunek[j] == 3) {
                suma23 -= kroki[j];
                continue;
            }                                              // --------------------------------
        }
        if (suma01 == 0 && suma23 == 0) cout << "studnia" << endl;   // jak obydwie sie wyzerowaly, to nie ma po co isc :)
        else if (suma01 == 0 || suma23 == 0) {
            if (suma01 == 0) {                                  // ten else if i nastepny sprawdzaja czy nie trzbeba
                if (suma23 < 0)                                      // isc tylko w jednym kierunku
                    cout << 3 << " " << -suma23 << endl;
                else
                    cout << 2 << " " << suma23 << endl;
            }
 
            else if (suma23 == 0) {                                  // as over
                if (suma01 < 0)
                    cout << 1 << " " << -suma01 << endl;
                else
                    cout << 0 << " " << suma01 << endl;
            }
        }
        else if (suma01 < 0 && suma23 < 0)                                              // leci po wszystkich przypadkach
            cout << 1 << " " << -suma01 << endl << 3 << " " << -suma23 << endl;        // musi sie to dac lepiej rozwiazac :P
        else if (suma01 < 0 && suma23 > 0)
            cout << 1 << " " << -suma01 << endl << 2 << " " << suma23 << endl;
        else if (suma01 > 0 && suma23 < 0)
            cout << 0 << " " << suma01 << endl << 3 << " " << -suma23 << endl;
        else if (suma01 > 0 && suma23 > 0)
            cout << 0 << " " << suma01 << endl << 2 << " " << suma23 << endl;
    }
    return 0;
} 
