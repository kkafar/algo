/*
Zadanie 2.1a (2016/2017)
Dana jest liczba naturalna N niezawierająca cyfry 0, którą rozbijamy na dwie liczby naturalne
A i B, przenosząc kolejne cyfry z liczby N do liczby A albo B.
Przykładowo: liczbę 21523 możemy rozbić na wiele sposobów, np. (215,23), (2,1523), (223,15), (152,23),
(22,153), (1,2523)...
Uwaga: względna kolejność cyfr w liczbie N oraz liczbach A i B musi być zachowana.
Proszę napisać funkcję generującą i wypisującą wszystkie rozbicia, w których powstałe liczby A i
B są względnie pierwsze. Do funkcji należy przekazać wartość N, funkcja powinna zwrócić liczbę
znalezionych par.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 21523;

int nwd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a >= b)
            a %= b;
        else
            b %= a;
    }
    return (a+b);
}

int rev(int n)
{
    int reversed = 0;
    while (n > 0)
    {
        reversed = (reversed * 10) + (n % 10);
        n /= 10;
    }
    return reversed;
}

int func(int N, int A, int B, int & pary)
{
    cout << "func: N: " << N << " | A: " << A << " | B: " << B << " | pary: " << pary << "\n";
    if (N == 0)
    {
        if (A != 0 && B != 0 && (nwd(rev(A), rev(B)) == 1)) 
        {
            cout << rev(A) << " " << rev(B) << "\n";
            ++pary;
        }

        return -1;
    }

    else
    {
        func(N/10, (A * 10) + (N%10), B, pary);
        func(N/10, A, (B * 10) + (N%10), pary);
    }

    return pary;
}

int main()
{
    int pary = 0;
    cout << "wyw\n";
    cout << func(N, 0, 0, pary) << "\n";
    //cout << rev(189) << "\n";
    return 0;
}
