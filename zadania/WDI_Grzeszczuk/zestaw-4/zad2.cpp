/*
    ZESTAW 4
    ZADANIE 2
2. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję który odpowiada na pytanie, czy w każdym wierszu tablicy występuje co
najmniej jedna liczba złożona wyłącznie z nieparzystych cyfr.

*/

#include <iostream>
#include <iomanip>
using namespace std;

#define FORU(i, b, e) for (int i = b; i <= e; ++i)
#define FORD(i, b, e) for (int i = b; i >= e; --i)

const int SIZE = 7;

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


/*
    funkcja sprawdzająca czy dana liczba całkowita n ma tylko nieparzyste cyfry
    jeśli tak - return true
    w przeciwnym wypdaku - return false
*/
bool oddDigits(int n)
{
    bool flag = true;

    while (n > 0)
    {
        if (n % 2 == 0)
        {
            flag = false;
            break;
        }
        n /= 10;
    }

    return flag;
}

int main()
{
    int T[SIZE][SIZE];
    bool odd = false;

    // powinniśmy założyć że jest wypełniona, ale na potrzeby testów jednak musimy ją czymś wypełnić 
    FORU(i, 0, SIZE - 1)
    { 
        FORU(j, 0, SIZE -1)
        {
            // w tej pętli lecimy po każdym wierszu, jeżeli napotkamy choć jedną liczbę złożoną z samych 
            // cyfr nieparzystych to dany wiersz już nas nie interesuje i możemy zbreak'ować
            if (oddDigits(T[i][j]))
            {
                break;
                odd = true;
            }
            // w przeciwnym wypadku lecimy dalej, 
        }
        // jeżeli w jakimś wierszu nie było takiej liczby, to w zmiennej odd mamy wartość 
        // logiczną false ==> breakujemy bo zadana macierz nie spełnia warunków zadania
        if (!odd)
        {
            cout << "NIE\n";
            return 0;
        }
        // jeżeli w sprawdzonym wierszu była taka liczba, to zmieniamy wartość flagi odd
        // oraz przechodzimy do sprawdzania kolejnego wiersza
        else
            odd = false;
    }

    // jeżeli pętla zrobiła swoje wszystkie przebiegi to znaczy że zadana macierz spełnia wymogi zadania
    cout << "TAK\n";
    return 0;
}
