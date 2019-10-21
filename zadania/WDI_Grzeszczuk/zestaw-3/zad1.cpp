/* 
    ZESTAW 3 
    ZADANIE 1
    1.  Napisać program zamieniający liczbę naturalną z systemu 10 na
        podstawę 2-16  
*/

#include <iostream>
#include <string>
using namespace std;

void error(string err_mssg)
{
    cout << err_mssg << "\n";
}

/* 
    Funkcja konwertująca liczbę z systemu dziesiętnego na system o dowolnej podstawie
    z przedziału [2, 16]. Zwraca liczbę jako string.

    n - liczba w systemie dziesiętnym przeznaczona do konwertowania
    sys_base - podstawa systemu liczbowego do którego konwertujemy liczbę n
*/
string convert(int n, int sys_base)
{
    // jako że liczbę będziemy mieć zapisaną od końca, to rozróżniamy liczbę 
    // powstałą w wyniku algorytmu od zwracanego wyniku
    string reversed_value, return_value;

    // dopóki nie przetworzymy n do końca
    while (n > 0)
    {
        if (n % sys_base < 10)
        {
            // +48 wynika z tablicy ascii 
            reversed_value += (char)(n % sys_base + 48);
            n /= sys_base;
        }
        else // czyli w przypadku gdy reszta wychodzi poza cyfry 0…9 => będziemy potrzebowali zapisać literę
        {
            // +55 tak samo wynika z tablicy ascii
            reversed_value += (char)(n % sys_base + 55);
            n /= sys_base;
        }
    }
    // pętla odwracająca reversed_value
    for (int i = reversed_value.length() - 1; i >= 0; --i)
        return_value += reversed_value[i];

    return return_value;
}

int main()
{
    int n; 

    cin >> n;

    for (int i = 2; i <= 16; ++i)
    {
        cout << i << ": " << convert(n, i) << "\n";
    }
    return 0;
}
