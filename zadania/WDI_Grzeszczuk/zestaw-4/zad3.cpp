/*
   ZESTAW 4
   ZADANIE 3
3. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję który odpowiada na pytanie, czy istnieje wiersz w tablicy w którym każda
z liczb zawiera przynajmniej jedna cyfrę parzystą.
*/

#include <iostream>
#include <iomanip>
using namespace std;

#define FORU(i, b, e) for (int i = b; i <= e; ++i)
#define FORD(i, b, e) for (int i = b; i >= e; --i)

const int SIZE = 7;

// procedura wyświetlająca macierz rozmiaru SIZE x SIZE)
void printTab(int T[SIZE][SIZE])
{
    FORU(i, 0, SIZE -1)
    {
        FORU(j, 0, SIZE - 1)
        {
            cout << setw(4) << T[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// zwraca true  jeżeli choć jedna cyfra liczby n (podanej jako parametr aktualny) 
// jest parzysta, w przeciwnym wypadku oczywiście zwraca false
bool evenDigit(int n)
{
    while (n > 0)
    {
        // testujemy ostatni bit liczby, jeżeli 1 to znaczy że jest nieparzysta => ostatnia 
        // cyfra nie jest parzysta
        // jeżeli na ostatnim miejscu bitowym stoi 0, to dostajemy fałsz w warunku, zaprzeczamy
        // i wsyzstko śmiga
        if (!(n & 1))
            return true;

        n /= 10;
    }
    // jeżeli nie zwróciliśmy do tej pory true, to znaczy że liczba nie zawiera cyfry parzystej 
    // w takim razie zwracamy false
    return false;
}


/*
    funkcja rozwiązujaca nasze zadanie 
*/
bool f(int T[SIZE][SIZE])
{
    bool flaga = = false;
    // jedziemy przez wszyskie wiersze naszej tablicy, 
    // jeżeli evenDigit gdziekolwiek zwróci false, no to oczywiście nasz wiersz
    // nie spełnia warunków zadania => przechodzimy do kolejnego 

    for (int i = 0; i < SIZE; ++i)
    {
        // na początku sprawdzania każdeog wiersza zakładamy że spełnia on warunki zadania
        // jeżeli nie, to zaprzeczamy i przechodzimy do sprawdzania kolejnego 
        flaga = true;
        for (int j = 0; i < SIZE; ++j)
        {
            if (!evenDigit(T[i][j]))
            {
                flaga = false;
                break;
            }
        }
        // jeżeli po przejrzeniu wiersza flaga ma wartość true, tzn. każda liczba w wierszu
        // ma co najmniej jedną cyfrę parzystą 
        if (flaga)
        {
            return true;
        }
    }
    // jeżeli do tej pory nie zwróciliśmy true; no to zwracamy false;
    return false;
}

int main()
{

    return 0;
}
