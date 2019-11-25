/*
    ZESTAW 7
    ZADANIE 1
    problem skoczka szachowego, rozwiązanie z wykładu 
    idea mniej więcej taka sama jak moja, tylko ładniej zaimplementowane
*/

#include <iostream>
using namespace std;

// ciała funkcji pod main'em
bool moznaSkakac();
void rysSzach(int ** T, int size);

/*
    Nie będziemy zwracać wartości logicznej, a jedynie wypisywać szachownicę gdy uda nam sie znaleźć scieżkę 
    w, k - aktualne koordynaty
    nr - nr akutalnie wykonywanego skoku
    flaga - aktulny stan algorytmu - false - jeszcze nie znaleziono rozwiązania
            - true - znaleziono rozwiazanie  
        przez referencję żeby wszystkie instancje ją widziały i miały wspólną
*/
void skok(int t[N][N], int w, int k, int nr, bool &flaga)
{
    // oznaczamy pole na którym jestesmy jako odwiedzone
    t[w][k] = nr;
    // jeżeli wykonaliśmy N * N skoków, to możemy zakończyć algorytm z sukcesem i wypisać szachownicę
    if (nr == N * N)
    {
        // do implementacji!
        // rysSzach(t);
        flaga = true;
    }

    int nw, nk; // nowy wiersz, nowa kolumna - tam gdzie będziemy chcieli skoczyć
    
    else
    {
        // w przeciwnym wypadku, oznacza to że mamy jeszcze jakieś skoki do wykonania ==> sprawdzamy gdzie możemy skoczyć
        // jeżeli gdzieś możemy skoczyć to oczywiście wykonujemy ten skok (wywołujemy się rekurencyjnie na danej pozycji)
        // jest maksymalnie 8 możliwośći skoku, tu je po prostu abstrakcyjnie rozważmy, sprawdzaniem gdzie możemy skoczyć 
        // a gdzie nie zajmiemy się w osobnej funkcji
        for (int i = 0; i < 8 && (!flaga); ++i)
        {
            if (moznaSkakac())
            {
                // jeżeli można wykonać dany skok, to skaczemy :) 
                // (do nowego wiersza i nowej kolumny)
                skok(t, nw, nk, nr + 1, flaga);
            }
            // jeżeli gdzieś nie można skoczyć to nie podejmujemy żadnej akcji
        }
    }
    // jeżeli wykonał się else i nie znaleźliśmy scieżki (czyli jeszcze nie wypisaliśmy szachownicy)
    // to znaczy że z naszej obecnej pozycji nie jesteśmy w stanie wykonać zadania ==> tu gdzie stoimy
    // wpisujemy 0, (bo to nie był poprawny ruch) i wychodzimy instancję wyżej
    t[w][k] = 0;
}

int main()
{
    // tablica przechowująca nasze skoki na szachownicy 
    int t[N][N]; 
    bool flaga = false; // flaga którą przekazujemy do pierwszego wywołania
    // zerujemy t[][]
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            t[i][j] = 0;

    return 0;
}
