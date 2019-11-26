/*
    ZESTAW 7
    ZADANIE 4 (/8)
8. Szachownica jest reprezentowana przez tablicę int t[8][8] wypełnioną liczbami
naturalnymi zawierającymi koszt przebywania na danym polu szachownicy. Król
szachowy znajduje się w wierszu 0 i kolumnie k. Król musi w dokładnie 7 ruchach
dotrzeć do wiersza 7. Proszę napisać funkcję, która wyznaczy minimalny koszt
przejścia króla. Do funkcji należy przekazać tablicę t oraz startową kolumnę k.
Koszt przebywania na polu startowym i ostatnim także wliczamy do kosztu przejścia.


To zadanie brzmi jak konkretny dynamik, ale trzeba rekurencyjnie.
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i => b; --i)
const int N = 8;
const int INF = 200000000;

int t[N][N] = {
    {1, 3, 6, 0, 0, 0, 0, 0},
    {3, 0, 5, 8, 1, 9, 9, 7},
    {4, 5, 0, 7, 1, 2, 3, 0},
    {9, 9, 0, 0, 2, 1, 3, 4},
    {1, 3, 6, 7, 0, 2, 3, 4},
    {3, 3, 5, 8, 1, 0, 9, 7},
    {4, 5, 6, 7, 1, 2, 0, 0},
    {0, 1, 1, 2, 2, 1, 3, 0}
};

void printTab(int T[N])
{
    FORU(i, 0, N-1)
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

int min(int a, int b)
{
    return ((a <= b) ? (a) : (b));
}

bool mozliwy(int w, int k, int n)
{
    int dw = 1;
    int dk[3] = {-1, 0, 1};
    return (w + 1 < N && k + dk[n-1] >= 0 && k + dk[n-1] < N);
}

int path(int t[N][N], int k, int w = 0, int koszt = 0, string sciezka = "")
{
    /*
        startujemy z pozycji (0, k), mamy 3 (lub mniej) możliwości ruchu, o wektor:
        1. (1, 0) (dół)
        2. (1, -1) (dół, lewoskos)
        3. (1, 1) (dół, prawoskos)
        Pamiętajmy że może ograniczać nas szachownica. 
    */
    // stajemy na danym polu (w,k), musimy doliczyć koszt postawienia na nim stopy
    koszt += t[w][k];
    if (w == 7)
    {
        cout << sciezka << "\n";
        cout << "(" << w << ", " << k << ") KOSZT: " << (koszt) << "\n";
        return koszt;
    }

    int a, b, c;
    a = b = c = INF;
    if (mozliwy(w, k, 1)) a = path(t, k-1, w+1, koszt, sciezka + "LD ");
    if (mozliwy(w, k, 2)) b = path(t, k, w+1, koszt, sciezka + "D ");
    if (mozliwy(w, k, 3)) c = path(t, k+1, w+1, koszt, sciezka + "PD ");

    cout << sciezka << "\n";
    cout << "(" << w << ", " << k << ") zwraca: " << (min(a, min(b,c))) << "\n";
    return (min(a, min(b, c)));
}

int main()
{
   
    cout << path(t, 3) << "\n";
    return 0;
}
