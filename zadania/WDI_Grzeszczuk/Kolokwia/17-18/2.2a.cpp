/*
Zadanie 2a. Kolos 2017/18
 Dane s¡ deklaracje:
const int N=1000;
int tab[N];
Tablica tab jest wypeªniona liczbami naturalnymi. Prosz¦ napisa¢ funkcj¦, która zwraca dªugo±¢ najdªu»szego
spójnego podci¡gu rosn¡cego, dla którego suma jego elementów jest równa sumie indeksów tych elementów.
Do funkcji nale»y przekaza¢ tablic¦, funkcja powinna zwróci¢ dªugo±¢ znalezionego podci¡gu, lub warto±¢ 0,
je»eli taki podci¡g nie istnieje.

W rozwiązaniu objętym komentarzem zapomniałem o tym że podciąg ma być spójny, ale zostawiam bo (RACZEJ) dobrze znajduje
takie podciagi, ale niekoniecznie spójne
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 7;
/*
int func(int T[N], int sumaEl, int sumaIdx, int idx, int ost, int dl, int & dlmax)
{
    if (sumaEl == sumaIdx and ost != -1)
    {
        if (dl > dlmax)
            dlmax = dl;
    }

    if (idx == N) return 0;

    else 
    {
        if (T[idx] > ost) func(T, sumaEl + T[idx], sumaIdx + idx, idx + 1, T[idx], dl + 1, dlmax);
        func(T, sumaEl, sumaIdx, idx + 1, ost, dl, dlmax);
    }
    return dlmax;
}
*/

int func(int T[N])
{
    int dlmax = 0, dl, sumaEl, sumaIdx;
    for (int i = 0; i < N; ++i)
    {
        sumaEl = sumaIdx = 0;
        dl = 1; // bo bierzemy elemetn i-ty
        for (int j = i + 1; j < N; ++j)
        {
            if (T[j] > T[j-1])
            {
                ++dl;
                sumaEl += T[j];
                sumaIdx += j;
            }
            else break;
        }
        if (dlmax < dl) dlmax = dl;
    }
    return dlmax;
}
int main()
{
    int T[N] = {0,11, 2, 3, 4, 1, 6};
    int dl = 0;
    cout << func(T) << "\n";
    //cout << isPrime(75123) << "\n";
    //cout << rev(32157) << "\n";
    return 0;
}
