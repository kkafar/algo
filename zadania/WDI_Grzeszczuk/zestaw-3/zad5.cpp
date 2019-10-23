/*
        ZESTAW 3
        ZADAMIE 5

        5. Obliczanie stałej e z rozwinięcia w szereg
        e=1/0!+1/1!+1/2!+1/3!+... z dokładnością do np. 1000 cyfr dziesi
        ętnych.

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int precision, mod;

    cin >> precision;

    // w tablicy e[] przechowujemy aktualną wartość liczby e
    // w tmp przechowujemy wartości kolejnych ułamków z szeregu 1 + 1 + 1/2! + 1/3! + ... + 1/n!
    int * e = new int[precision];
    int * tmp = new int[precision + 1]; 

    // zerujemy obydwie tablice
    for (int i = 0; i < precision; ++i) e[i] = tmp[i] = 0;

    // e[0] to skrajna PRAWA cyfra
    e[0] = 2;
    tmp[precision] = 1;

    // pętla iterutąca tyle razy ile ma być ułamków (-2, bo 2 pierwsze mamy już wliczone w e[0])
    for (int i = 2; i <= precision; ++i)
    {
        // najpierw potrzebujemy obliczyc wartość ułamka, a potem dodać ten ułamek do e[]
        // DZIELENIE (obliczanie wartości tego ułamka)
        // dzielenie zaczynamy od skrajnej LEWEJ cyfry
        for (int j = precision; j > 0; --j)
        {
            mod = tmp[j];
            tmp[j] = tmp[j] / i;
            tmp[j - 1] += (mod % i) * 10;
        }


        // debug
        cout << setw(10) << i << ": ";
        for (int j = precision; j > 0; --j)
            cout << tmp[j] << " ";
        cout << "\n";


    }



    delete[] e; delete[] tmp;
    return 0;
}
