/*
Kolos poprawkowy 2016/17
2. Dana jest tablica booli int t[N][N] reprezentująca szachownicę. Pole szachownicy ma
wartość true, jeżeli stoi na nim figura, a false, jeśli jest ono puste. Proszę napisać
funkcję która sprawdza czy istnieje droga skoczka przemieszczającego się z wiersza
0 do wiersza N-1. Skoczek może poruszać się tylko po polach pustych. Skoczek w
każdym ruchu powinien przybliżać się do N-1 wiersza. Funkcja ma zwrócić
najmniejszą możliwą liczbę ruchów. Skoczek może zacząć poruszać się z dowolnego
pustego pola z wiersza 0. N z zakresu 4...20.

Nie testowałem tego rozwiązania.

*/

#include <iostream>
#include <iomanip>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 5;
const int INF = 2000000;
bool valid(bool T[N][N], int w, int k, int ruch, int & nw, int & nk)
{
    static int dw[4] = {1, 2, 2, 1}, dk[4] = {2, 1, -1, -2};
    nw = w + dw[ruch]; nk = k + dk[ruch];
    if (nw < N && nk >= 0 && nk < N && T[nw][nk] == false)
        return true;
    else 
        return false;
}

int func(bool T[N][N], int & minr, int w, int k, int licz = 0)
{
    cout << w << "  " << k << "\n";
    if (w == N-1)
    {
        if (minr > licz) minr = licz;
        return -1; // wychodzimy instancję wyżej 
    }

    else
    {
        int nw, nk;
        REP(i, 4)
        {
            if (valid(T, w, k, i, nw, nk))
            {
                func(T, minr, nw, nk, licz+1);
            }
        }
    }
    return minr;
}


int main()
{
    int minr = INF;
    bool T[N][N] = { {false, false, false, false, false},
                    {false, false, true,  false, true }, 
                    {false, false, true,  true,  true }, 
                    {false, false, false, false, false},
                    {true,  false,  false, true,  false} };
    cout << func(T, minr, 0, 0) << "\n";
                    
                    

    return 0;
}
