/* 
    ZESTAW 7
    ZADANIE 1
    Problem skoczka szachowego (treść oczywista) 
    (czy z zadanego miejsca na szachownicy można skoczkiem odwiedzić wszystkie inne pola
    nie stając na żadnym polu dwukrotnie?)
    
    No to idea jest taka, tworzymy sobie tablicę int reprezentującą szachownicę. Wypełniamy ją zerami.
    W miejscu rozpoczęcia (podanym z stdin) wstawiamy jedynkę i przekazujemy tablicę do funkcji. 
    Podejście oczywiśćie rekurencyjnie => 
    0. Zaznaczamy bieżące pole poprzez kolejny numerek (podany jako parametr). Zwiększamy licznik skoków. 
    1. Jeżeli licznik skoków osiągnął wartość 64 tzn. że wszystkie pola zostały odwiedzone. Zwracamy true,
        a w tablicy mamy przechowaną ścieżkę!  
    2. Wywołujemy się na wszystkich polach na które możemy zajść z bieżącego pola. 
    3. Jeżeli nie możemy się nigdzie ruszyć, to odznaczamy pole na którym stoimy i zwracamy false
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int size = 8;
int szachownica[size][size];

void rysSzach(int szach[size][size])
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j) 
            cout << setw(4) << szach[i][j];
        cout << "\n";
    }
}
/*
    S - tablica przechowująca szachownicę
    w - nr wiersza w którym się znajdujemy
    k - nr kolumny w któruej się znajdujemy
    licz - ile skoków do tej pory wykonaliśmy 

*/
bool done = false;
bool skoczek(int S[size][size], int w, int k, int licz = 1)
{
    // zwiększamy licznik skoków oraz oznaczamy odwiedzone pole
    S[w][k] = licz++;
    // jeżeli wykonaliśmy 64 (size) skoki, to możemy zwrócić sukces!
    if (licz == 64) 
    {
       // rysSzach(S);
        cout << "idx: " << licz << " Pole: " << w << " " << k << "\n";
        done = true;
        return true;
    }
    // wywołujemy się rekurencyjnie na wszystkich polach na które możemy się ruszyć
    // 2U 1L
    if ((w-2 >= 0 && k-1 >= 0) && S[w-2][k-1] == 0 && !done) skoczek(S, w-2, k-1, licz);
    // 1U 2L
    if ((w-1 >= 0 && k-2 >= 0) && S[w-1][k-2] == 0 && !done) skoczek(S, w-1, k-2, licz);
    // 1D 2L
    if ((w+1 < size && k-2 >= 0) && S[w+1][k-2] == 0 && !done) skoczek(S, w+1, k-2, licz);
    // 2D 1L
    if ((w+2 < size && k-1 >= 0) && S[w+2][k-1] == 0 && !done) skoczek(S, w+2, k-1, licz);
    // 2U 1P
    if ((w-2 >= 0 && k+1 < size) && S[w-2][k+1] == 0 && !done) skoczek(S, w-2, k+1, licz);
    // 1U 2P
    if ((w-1 >= 0 && k+2 < size) && S[w-1][k+2] == 0 && !done) skoczek(S, w-1, k+2, licz);
    // 1D 2P
    if ((w+1 < size && k+2 < size) && S[w+1][k+2] == 0 && !done) skoczek(S, w+1, k+2, licz);
    // 2D 1P
    if ((w+2 < size && k+1 < size) && S[w+2][k+1] == 0 && !done) skoczek(S, w+2, k+1, licz);

    if (done) 
    {
        cout << "idx: " << licz << " Pole: " << w << " " << k << "\n";
        return true;
    }
    // jeżeli nigdzie się nie możemy ruszyć, od odznaczamy pole na którym jesteśmy, zmniejszamy licznik 
    // oraz zwracamy false
    S[w][k] = 0;
    --licz;
    //cout << "Jestem na polu: " << w << " " << k << " Szachownica:\n";
    //rysSzach(S);
    return false;

}

int main()
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) szachownica[i][j] = 0;

    int w, k;
    cin >> w >> k;

    if(skoczek(szachownica, w, k)) cout << "TAK!@@@@@\n";
    else cout << "TEN PROGRAM NA PEWNO NIE DZIAlA\n";
    rysSzach(szachownica);

    
    return 0;
}
