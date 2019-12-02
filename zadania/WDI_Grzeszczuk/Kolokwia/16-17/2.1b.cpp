/*
ad-wdi k2b, środa, 14 grudnia 2016
1. Dane są dwie tablice t1[N] i t2[N] zawierające liczby naturalne. Z wartości w obu tablicach
możemy tworzyć sumy. „Poprawna” suma to taka, która zawiera co najmniej jeden element
(z tablicy t1 lub t2) o każdym indeksie. Na przykład dla tablic: t1 = [1,3,2,4] i t2 = [9,7,4,8]
poprawnymi sumami są na przykład 1+3+2+4, 9+7+4+8, 1+7+3+8, 1+9+7+2+4+8.
Proszę napisać funkcję generującą i wypisującą wszystkie poprawne sumy, które są liczbami
pierwszymi. Do funkcji należy przekazać dwie tablice, funkcja powinna zwrócić liczbę
znalezionych i wypisanych sum.
*/

#include <iostream>
#include <iomanip>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 4;

bool isSumPrime(int S[2*N], int idx)
{
    int sum = 0; 
    REP(i, idx) sum += S[i];

    if (sum == 2)                   return true;
    if (sum < 2 || sum % 2 == 0)    return false;
    for (int i = 3; i * i <= sum; i += 2)
        if (sum % i == 0)           return false;

    return true;

}

void print(int S[2*N], int idx)
{
    REP(i, idx)
        cout << S[i] << " + ";

    //cout << S[idx - 1];
    cout << "\n";
}

int func(int A[N], int B[N], int S[2*N], int & count, int iS = 0, int iAB = 0)
{
    //cout << "func: count: " << count << " | iS: " << iS << " | iAB: " << iAB << "\n";
    //cout << "S[]: "; print(S, iS); cout << "\n";
    if (iAB == N)
    {
        if (isSumPrime(S, iS))
        {
            ++count;
            print(S, iS);
        }
        return -1;
    }

    else
    {
        S[iS] = A[iAB];
        func(A, B, S, count, iS + 1, iAB + 1);
        S[iS] = 0;
        S[iS] = B[iAB];
        func(A, B, S, count, iS + 1, iAB + 1);
        S[iS] = 0;
       // if (iS + 2 < 2*N)
        //{
            S[iS] = A[iAB];
            S[iS + 1] = B[iAB];
            func(A, B, S, count, iS + 2, iAB + 1);
            S[iS] = S[iS + 1] = 0;
        //}
 
    }

    return count;
}


int main()
{
    int count = 0, A[N] = {1, 3, 2, 4}, B[N] = {9, 7, 4, 8};
    int S[2*N];
    //bool v[N];
    //REP(i, N) v[i] = false;
    REP(i, 2*N) S[i] = 0;
    print(S, 2*N);
    cout << func(A, B, S, count) << "\n";
    return 0;
}
