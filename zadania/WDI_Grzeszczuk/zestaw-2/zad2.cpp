/*
    ZADANIE 2
    ZESTAW 2
Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
czy liczba ta jest wielokrotnością dowolnego wyrazu ciągu danego wzorem
A(n)=n*n+n+1.
*/

/*
    Łatwo na papierze wyprowadzamy wzór rekurencyjny bo A(n+1) = A(n) + 2n + 2 i A(1) = 3
    Chociaż to jakoś super nie usprawnia, bo trzeba wykoniać 3 flopy, żeby obliczyć A(n) wprost
    ze wzoru też trzeba 3 flopy. 
    Do tego oczywiście łatwo stwierdzamy że ciąg ten jest rosnący (logika albo indukcja)

    Można to też robić inaczej, np. coś jak sito erastotenesa. 
*/


#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    int M, A_n = 3, n = 1; 

    cin >> M;

    // nie ma sensu sprawdzać dalej nić sqrt(M)
    while (A_n * A_n <= M)
    {
        // jeżeli jest wielokrotnością to oczywiście wyświetlamy że jest :D
        if (M % A_n == 0)
        {
            cout << "TAK!\n" << n << "\n";
            return 0;
        }
        else 
        {
            A_n += A_n + 2 * n + 2;
            ++n;
        }
    }
    // jeżeli wyszliśmy poza pętlę, to znaczy że M nie jest wielokrotnością A_n dla żadnego n c N;
    cout << "NIE!\n";

    return 0;
}
