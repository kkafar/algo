/*
    * ZADANIE 3
    * ZESTAW 5
Proszę napisać funkcję, która odpowiada na pytanie: czy żadne z dwa hetmany się nie
szachują? Do funkcji należy przekazać położenie hetmanów. 

Zauważmy że 2 hetmany szachują się wtw gdy są w tej samej kolumnie lub wierszu lub ich suma/różnica 
indeksów w i k są takie same (aby zrozumieć wystarczy wykonać procedurę rysSzachownice())
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int size = 100;

void rysSzachownice()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = i; j < 8 + i; ++j)
        {
            cout << setw(3) << j;
        }
        cout << "\n";
    }

    cout << "\n\n";
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cout << setw(3) << i - j;
        }
        cout << "\n";
    }
}

struct hetman
{
    int w;
    int k;
};
struct dane
{
    hetman t[size];
    int N;
}

bool f(dane d)
{
    // no to pałujemy i sprawdzamy każdą parę
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N ; ++j)
        {
            if (d.t[i].w == d.t[j].w || d.t[i].k == d.t[j].k || (d.t[i].w + d.t[i].k == d.t[j].w + d.t[j].k)
                || (d.t[i].w - d.t[i].k == d.t[j].w - d.t[j].k))
            {
                // skoro tu jesteśmy, to jakieś 2 się szachują ==> zwracamy false
                return false;
            }
        }
    }
    return true;
}
int main()
{
    return 0;
}
