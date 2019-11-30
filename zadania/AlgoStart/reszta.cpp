/*
Reszta
Proszę napisać funkcję, która dla podanej sumy i listy nominałów wypisuje ilość możliwości
na jakie można wydać daną sumę
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 3;

string toStr(int n)
{
    string rev = "", numb = "";
    while (n > 0)
    {
        rev += (char)(n%10 + '0');
        n /= 10;
    }

    for (int i = rev.length() - 1; i >= 0; --i)
        numb += rev[i];

    return numb;
}

int wydaj(int T[N], int S, int idx, int & ile, string lista = "")
{
    if (S == 0)
    {
        ++ile;
        cout << lista << "\n";
        return -1;
    }
    else if (S < 0 || idx == N)
    {
        return -1;
    }
    else
    {
        //biorę ten sam nominał: 
        wydaj(T, S - T[idx], idx, ile, lista + toStr(T[idx]));
        //albo go nie biorę i przechodzę do następnego:
        wydaj(T, S, idx + 1, ile, lista);
    }
    return ile;
}


int main()
{
    int T[N] = {1, 2, 5};
    int ile = 0;
    cout << wydaj(T, 13, 0, ile) << "\n";
    return 0;
}
