/*
    ZESTAW 7
    ZADANIE 4
8. Szachownica jest reprezentowana przez tablicę int t[8][8] wypełnioną liczbami
naturalnymi zawierającymi koszt przebywania na danym polu szachownicy. Król
szachowy znajduje się w wierszu 0 i kolumnie k. Król musi w dokładnie 7 ruchach
dotrzeć do wiersza 7. Proszę napisać funkcję, która wyznaczy minimalny koszt
przejścia króla. Do funkcji należy przekazać tablicę t oraz startową kolumnę k.
Koszt przebywania na polu startowym i ostatnim także wliczamy do kosztu przejścia.

Skoro król ma tylko 7 ruchów to musi iść pionowo w dół? 

Nie wiem do końca jak to rozumieć, więc wyznaczam minimum z wszystkich kolumn 
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i => b; --i)
const int INF = 2000000000;
const int N = 8;

void rysSzach(int t[N][N])
{
    FORU(i, 0, N-1)
    {
        FORU(j, 0, N-1)
            cout << setw(4) << t[i][j];

        cout << "\n";
    }
}

int minkoszt = INF;
int path(int koszt[N][N], int k, int aktualnyKoszt = 0)
{
    // stajemy na danym polu, więc zwiększamy koszt ruchu
    FORU(i, 0, N-1)
        aktualnyKoszt += koszt[i][k];
    
    // po tej pętli, zawsze jestem w wierszu o nr 7 (czyli wierszu ósmym)
    if (aktualnyKoszt < minkoszt)
        minkoszt = aktualnyKoszt;
    
    if (k < 7) 
        path(koszt, k + 1, 0);

    return minkoszt;
}


int main()
{
    int t[N][N];
    FORU(i, 0, N-1)
        FORU(j, 0, N-1)
            t[i][j] = (i+3)/(j + 1);

    rysSzach(t);
    cout << path(t, 0) << "\n";
        
    
    return 0;
}
