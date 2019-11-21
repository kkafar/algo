/* 
    ZESTAW 6
    ZADANIE 3
(1) Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać tylko na jednej
szalce.
(2) Poprzednie zadanie, odważniki można umieszczać na obu szalkach. 
(3) Poprzednie zadanie. Program powinien wypisywać wybrane odważniki.

*/

#include <iostream>
using namespace std;

/*
    funkcja realizująca zadanie, zwraca true jeżeli podaną masę można   
    odmierzyć, false w wypadku przeciwnym. Opis algorytmu w czerwonym

*/
const int N = 3;
bool mass(int T[N], int masa, int n)
{
    if (masa == 0)  return true;
    if (n == N)     return false;
    //return (mass(T, masa - T[n], n + 1) || mass(T, masa, n + 1) || mass(T, masa + T[n], n + 1));
    if (mass(T, masa - T[n], n + 1)) 
    {
        cout << "L" << T[n] << " ";
        return true;
    }
    if (mass(T, masa, n + 1))
    {
        return true;
    }
    if (mass(T, masa + T[n], n + 1))
    {
        cout << "P" << T[n] << " ";
        return true;
    }
}


int main()
{
    
    int T[N] = {1, 2, 6}, masa;
    cin >> masa;
    if (mass(T, masa, 0) == true) cout << "TAK\n";
    else cout << "NIE\n";

    return 0;
}
