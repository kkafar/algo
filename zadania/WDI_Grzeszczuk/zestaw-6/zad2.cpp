/* 
    ZESTAW 6
    ZADANIE 2
Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać tylko na jednej
szalce.
Poprzednie zadanie, odważniki można umieszczać na obu szalkach. 
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
    return (mass(T, masa - T[n], n + 1) || mass(T, masa, n + 1) || mass(T, masa + T[n], n + 1));
}


int main()
{
    
    int T[N] = {1, 2, 4}, masa;
    cin >> masa;
    if (mass(T, masa, 0) == true) cout << "TAK\n";
    else cout << "NIE\n";

    return 0;
}
