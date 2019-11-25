/*
    ZESTAW 7
    ZADANIE 2
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5;

bool czyPierwsza(int n)
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i = i + 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool pocz(int T[N], int idx, int numb, int id)
{
    cout << id  << " wywoluje " << id + 1 << "\n";
    int ID = id + 1;
    cout << "Wyowalnie z danymi: idx == " << idx  << "  numb == ";
    if (idx == N) return true;
    cout << numb << "\n";

    for (int i = idx; i < N && (i < idx + 30); ++i)
    {
        cout << numb << " = " << numb << " * 2 +" << T[i] << "\n";
        numb = numb * 2 + T[i];
        cout << "aktualny numb: ";
        cout << numb << "\n";
        if (czyPierwsza(numb))
        {
            cout << numb << "---- pierwsza ----\n"; 
            if (pocz(T, i + 1, 0, ID))
            {
                cout << "ID: " << ID << " zwraca true!\n";
                return true;
            }
        }
        else 
        {
            cout << numb << " --- NIE pierwsza ---\n";
        }
    }
    return false; 
    

    // jeżeli nigdzie nie zwróciliśmy true i wróciliśmy do pierwszego wywołania
    // to możemy z całą odpowiedzalnością zwrócić false
    if (idx == 0)   return false;
}



int main()
{
    int tab[N] = {1, 1, 1, 1, 1};
    //for (int i = 0; i < N; ++i)
      //  tab[i] = i % 2;

    if (pocz(tab, 0, 0, 0)) cout << "dziala\n";
    else cout << "nie\n";
    
    return 0;
}
