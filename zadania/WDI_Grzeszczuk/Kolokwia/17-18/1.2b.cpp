/*
Zadanie 1.2b (2017/18) Kartkówka
Dane są deklaracje:
const int N=1000;
int tab[N];
Tablica tab jest wypełniona liczbami naturalnymi. Proszę napisać funkcję, która zwraca długość
najdłuższego spójnego podciągu będącego palindromem złożonym wyłącznie z liczb
nieparzystych. Do funkcji należy przekazać tablicę, funkcja powinna zwrócić długość
znalezionego podciągu, lub wartość 0, jeżeli taki podciąg nie istnieje.

opis działania w czerwonym 
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 10;

string toStr(int n)
{
    string reversed = "";

    while (n > 0)
    {
        reversed += (char)(n % 10 + '0');
        n /= 10;
    }

    string numb = "";

    for (int i = reversed.length() - 1; i >= 0; --i)
        numb += reversed[i];

    return numb;
}

bool ifOddPalindrome(int l, int r, int T[N])
{
    string numb = "";

    for (int i = l; i <= r; ++i)
    {
        if (T[i] % 2 == 0)
            return false;

        else
            numb += toStr(T[i]);
    }

    for (int i = 0, j = numb.length() - 1; i <= j; ++i, --j)
    {
        if (numb[i] != numb[j])
            return false;
    }

    return true;
}

int subseq(int T[N])
{
    int maxleng = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = N - 1; j >= i; --j)
        {
            if (ifOddPalindrome(i, j, T))
            {
                if ((j - i + 1) > maxleng)
                    maxleng = j - i + 1; 
            }
        }
    }
    return maxleng;
}


int main()
{
    int tab[N] = {2, 4, 6, 8, 11, 12, 1, 3, 31, 20};
    cout << subseq(tab) << "\n";    
    return 0;
}
