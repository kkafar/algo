/*
   ZESTAW 4
   ZADANIE 4
4. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję która zwraca wiersz i kolumnę dowolnego elementu, dla którego iloraz
sumy elementów w kolumnie w którym leży element do sumy elementów wiersza w
którym leży element jest największa. 


ZAKŁADAM, ŻE NATURALNE SĄ ≥ 1
INACZEJ TRZEBA SPRAWDZAĆ CZY NIE DZIELIMY PRZEZ 0

PrZEDEWSZYSTKIM NEI TRZEBA TUTAJ NIC DZIELIĆ. ZNAJDUJEMY KOLUMNĘ I WIERSZ Z ODPOWIEDNIO NAJWIĘKSZĄ
I NAJMNIEJSZĄ SUMĄ
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

struct PAIR
{
    // wiersz, kolumna
    int w, k;
};

PAIR f(int T[SIZE][SIZE])
{
    // liczymy sumę w danej kolumnie i w danym wierszu
    int W[SIZE], K[SIZE];
    FORU(i, 0, SIZE - 1) W[i] = K[i] = 0;

    FORU(i, 0, SIZE - 1)
    {
        FORU(j, 0, SIZE - 1)
        {
            // liczymy sumę wiersza
            W[i] += T[i][j];
            // no i od razu sumę kolejnych kolumn
            K[j] += T[i][j];
        }
    }
    // teraz potrzebujemy wyznaczyć największy iloraz
    // dla każdego elementu musimy wyznaczyć osbno. 
    double maximum = double(K[0]) / T[0];
    PAIR wk; 
    wk.w = 0;
    wk.k = 0;
    FORU(i, 0, SIZE - 1)
    {
        FORU(j, 0, SIZE - 1)
        {
           if (double(K[j]) / W[i] > maximum)
           {
                maximum = double(K[j]) / W[i];
                wk.w = i;
                wk.k = j;
           }
        }
    }

    return wk;
}
int main() 
{

    return 0;
}
