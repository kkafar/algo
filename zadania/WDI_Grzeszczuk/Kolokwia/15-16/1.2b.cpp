/*
Zadanie 1.2b kolos 2015 ad-wdi-k2a, wtoreŁ 8 grudnia 2015
2) Dana jest tablica t[N][N] (reprezentująca szachownicę) wypełniona liczbami całkowitymi z zakresu -9 ..9. Proszę napisać funkcję.która
ustawia na szachownicy dwie wieŹe, tak aby suma liczb na szachowanych polach była największa. Do funkcji należy przekazać tablicę, funkcja
powinna zwrócić położenie wież'
*/

#include <iostream>
#include <time.h>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 15;
const int INF = 2000000000;

template<class C>
void printTab(C T[], int size)
{
    REP(i, size)
        cout << T[i] << " ";
    cout << "\n";
}

int gfs(int T[N][N], int w1, int k1, int w2, int k2)
{
    int sum = 0;
    if (w1 != w2 and k1 != k2)
    {
        REP(i, N) 
            sum += T[i][k1] + T[w1][i] + T[i][k2] + T[w2][i];
        
        sum -= 2 * (T[w1][k1] + T[w2][k2]) + T[w2][k1] + T[w1][k2];
    }
    if (w1 == w2)
    {
        REP(i, N) 
            sum += T[i][k1] + T[w1][i] + T[i][k2];

         sum -= 2 * (T[w1][k1] + T[w2][k2]);
    }
    if (k1 == k2)
    {
        REP(i, N) 
            sum += T[w1][i] + T[i][k1] + T[w2][i];

        sum -= 2 * (T[w1][k1] + T[w2][k2]);
    }
    return sum;
}
// zwracamy coś innego niż proszą w zadaniu,ale to tylko szczegół :() 
void func(int T[N][N])
{
    // wieże na starcie umieszczamy na (0,0), (1, 0)
    int sum, maxSum;
    REP(x1, N)
    {
        REP(y1, N)
        {


        }
    }
}


int main()
{

    return 0;
}
