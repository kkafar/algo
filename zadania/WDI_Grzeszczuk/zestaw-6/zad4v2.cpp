/* 
    ZESTAW 6
    ZADANIE 4 w mojej wersji, wcześniejszy kod jest z zajęć
„Waga” liczby jest określona jako ilość różnych czynników pierwszych liczby. Na
przykład waga(1)=0, waga(2)=1, waga(6)=2, waga(30)=3, waga(64)=1. Dana jest
tablica: int t[N]. Tablica zawiera liczby naturalne. Proszę napisać funkcję, która
sprawdza czy można elementy tablicy podzielić na 3 podzbiory o równych wagach. Do
funkcji należy przekazać wyłącznie tablicę, funkcja powinna zwrócić wartość typu
bool.
*/
#include <iostream>
using namespace std;
// funkcja zliczająca ilość czynników pierwszych danej liczby
int ileCzP(int n)
{
    int licznik = 0, pierwsza = 2, os = 0;
    while (n > 1)
    {
        if (n % pierwsza == 0)
        {
            if (os != pierwsza)
            {
                ++licznik;
                os = pierwsza;
            }
            n /= pierwsza;
        }
        else 
            ++pierwsza;
    }
    return licznik;
}

// przekazujemy tylko tablicę, reszta jest argumentami domyślnymi
// idx - indeks aktualnie rozwazanej liczby w tablicy T[]
// zbA, zbB, zbC - aktualna suma wag odpowiednio w zbiorze A, B, C (bo dzielimy na 3 podzbiory)
bool podzbiory(int T[N], int idx = 0, int zbA = 0, int zbB = 0, int zbC = 0)
{
    // jeżeli udało nam się podzielić tak jak chceliśmy (na trzy podzbiory o równych sumach wag)
    // no to oczywiśćie zwracamy true
    // najpierw zwracamy, przed sprawdzeniem jak daleko w tablicy jesteśmy, bo w najgorszym przypadku 
    // rozważamy ostatni element w tablicy, dopiero niżej odwołujemy się do kolejnego. 
    if ((zbA == zbB) && (zbA == zbC)) return true;
    // jeżeli weszliśmy zbyt głęboko (wychodzimy poza tablicę T[])
    if (idx == N) return false;
    // w innym przypadku wywołujemy się rekurencyjnie na trzy sposoby: 
    // 1. biorąc dany element do zbioru A, 2. biorąc do B, 3. biorąc do C
    // jeżeli w choć jednym miejscu pojawi się true, to oczywiście zwracamy true, stąd alternatywa
    return (podzbiory(T, idx+1, zbA + T[idx], zbB, zbC) || podzbiory(T, idx+1, zbA, zbB+ T[idx], zbC) 
        || podzbiory(T, idx+1, zbA, zbB, zbC+T[idx]));
    // no coś takiego, powinno już działać, choć nie testowałem
}

int main()
{
    cout << ileCzP(1) << " " << ileCzP(2) << " " << ileCzP(6) << " " << ileCzP(30) << " " << ileCzP(64) << "\n";
    return 0;
}
