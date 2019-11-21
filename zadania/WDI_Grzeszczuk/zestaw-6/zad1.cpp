/* 
    ZESTAW 6
    ZADANIE 1
Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać tylko na jednej
szalce.
*/

#include <iostream>
using namespace std;

/*
    funkcja realizująca zadanie, zwraca true jeżeli podaną masę można   
    odmierzyć, false w wypadku przeciwnym. Opis algorytmu w czerwonym

*/
const int N = 3;
int ID = 0;
bool mass(int T[N], int masa, int n, int ID = 0, int rodzic = 0)
{
    cout << "ID: " << ID << " RODZ: " << rodzic << "\n";
    cout << "mass(" << masa << "(masa), " << n << "(n), " << T[n] << "(waga odw))\n";
    if (masa == 0) return true; 
    if (n == N) return false;
    if (mass(T, masa - T[n], n + 1, ID + 1, ID)) 
    {
        return true;
    }
    if (mass(T, masa, n + 1, ID + 1, ID))
    {
        return true;
    }
    return false;
}


int main()
{
    
    cout << "mass(masa, n, T[n])\n";
    int T[N] = {1, 2, 4}, masa;
    for (int i = 0; i < N; ++i)
        cout << T[i] << " ";
    cout << "\n";
    cin >> masa;
    if (mass(T, masa, 0) == true) cout << "TAK\n";
    else cout << "NIE\n";

    return 0;
}
