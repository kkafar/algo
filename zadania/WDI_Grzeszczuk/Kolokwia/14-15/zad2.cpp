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
const int N = 4;
const int M = N * N;


int t1[N][N] = {
    {1, 3, 6, 7},
    {3, 3, 5, 8},
    {4, 5, 6, 7},
    {0, 1, 1, 2}
};

int t2[M];

void printTab(int T[M])
{
    FORU(i, 0, M-1)
        cout << T[i] << " ";

    cout << "\n";
    
}
void printTab2D(int T[N][N])
{
    FORU(i, 0, N-1)
    {
        FORU(j, 0, N-1)
            cout << setw(4) << T[i][j];

        cout << "\n";
    }
}

int main()
{
    /*
        idx - indeks do poruszania się po tablicy t2
        k[i] - nr kolumny na którym jesteśmy w wierszu i-tym
        min - aktualnie wyznaczony element minimalny w "kolumnie" 
        wm - wiersz w którym zostało znalezione minimum

    */
    int idx = 0, k[N], min, wm;

    FORU(i, 0, N-1) k[i] = 0;
    
    printTab2D(t1);

    while (idx < M)
    {
        FORU(j, 0, N-1)
        {
            min = INF;
            wm = INF;
            // lecimy przez "kolumnę""
            FORU(w, 0, N-1)
            {
                if (k[w] < N)
                {
                    if (t1[w][k[w]] < min)
                    {
                        min = t1[w][k[w]];
                        wm = w;
                    }
                }
            }
            cout << "MINIMUM ZNALEZIONO W WIERSZU " << wm << " i bylo to " << min << "\n";
            t2[idx] = min;
            ++idx;
            ++k[wm];
        }
    }
    
    printTab(t2);
    
    return 0;
}
