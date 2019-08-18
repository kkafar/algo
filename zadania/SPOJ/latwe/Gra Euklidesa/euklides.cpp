#include <iostream>
 
using namespace std;
/* GRA EUKLIDESA */
int main()
{
    short t;                                                // ile testow
    cin >> t;
    int a[t], b[t];                                         // tablice na zetony dla graczy A i B;
    for (int i = 0; i < t; ++i) {                           // wczytujemy liczby zetonow na poczatku kazdej z partii
        cin >> a[i] >> b[i];                                // nie chcemy 2 petli, a wiec od razu w tej robimy gre
        while(true) {
            if (a[i] == b[i]) {                             // gdy gra nie moze byc prowadzona, wyswietlamy l. zet.
                cout << 2*a[i] << endl;
                //continue;                                 // i prosimy, aby zaczela sie kolejna partia
                break;
            }
            else if (a[i] < b[i]) {
                b[i] -= a[i];                               // zgodnie z zasadami, pomniejszamy liczbe zet. gracza
                //continue;
            }
            else {
                a[i] -= b[i];                               // to samo tutaj
            }
        }
    }
 
    return 0;
}
 
