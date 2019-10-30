/*
    ZESTAW 3
    ZADANIE 9
*/


/* sprawdzać */
#include <iostream>
using namespace std;



const int N = 100;

void czynnikiPierwsze(int x, bool skok[], int i)
{
    bool sito[x + 1];
    for (int j = 0; j < x + 1; j++) sito[j] = false;

    for (int j = 2; j < x + 1; j++)
    {
        if (sito[j] == false)
        {
            if (x % j == 0)
            {
                if (i + j < N)
                {
                                    skok[i + j] = true;
                for (int k = j; k * j < x + 1; k++) sito[k * j] = true;
                }

            }
        }
    }
}


int main()
{
    int T[N]; // zakładamy że tablica jest wypełniona
    bool skok[N] // wypełniamy fałszami
    for (int i = 0; i < N; ++i) skok[i] = false;

    skok[0] = true;

    for (int i = 0; i < N; ++i) 
    {
        czynnikiPierwsze(tab[i], skok, i);
        if (skok[N - 1] == true)
        {
            cout << "skok jest mozliwy!\n";
            return 0;
        }
    }
    cout << "skok nie jest mozliwy\n";

    return 0;
}
