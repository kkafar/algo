#include <iostream>
#include <math.h>
using namespace std;

// zadanie 4
int ileWag = 0;
bool waga(int n)
{
    int licznik = 0, p = 2, pierwsza = 0;

    while (n > 1 && p <= n)
    {
        if (n % p == 0)
        {
            if (p != pierwsza) licznik++;
            pierwsza = p;
            n = n/p;
        }
        else ++p;
    }
    return licznik;
}

bool suma(int t[N], int p, int a, int b, int c)
{
    if (N == p)
    {
        if ((a == b) && b == c) return true;
        else return false;
    }
    return suma(t, p+1, a + waga(t[p]), c) || suma(t, p+1, a, b + waga(t[p]), c) || suma(t, p+1, a, b, c + waga(t[p]));
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << f(a, b, "", 0) << "WYNIK!!!!!!!!!!!!!!!!!!\n\n";
    return 0;
}
