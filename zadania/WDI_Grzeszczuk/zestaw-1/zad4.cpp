/*
    ZESTAW 1
    ZADANIE 4

    4. Napisać program obliczający pierwiastek całkowitoliczbowy z liczby naturalnej
    korzystając z zależności 1+3+5+... = n^2. 
*/

#include <iostream>

using namespace std;

// Szukamy wartości pierwiastka naturalnego z liczby naturalnej M
// idea jest prosta, obliczamy kolejne sumy częściowe S_n zadanego wyżej szeregu,
// tak długo aż nie przekroczymy wartości M

int main()
{
    int M, S_n = 1, n = 1, k = 3;

    cin >> M;

    // jeżeli zachodzi równość to mamy dokładnie pierwiastek z liczby
    while (S_n < M)
    {
        // jeżeli suma jest jeszcze za mała, no to ją powiększamy o kolejny wyraz;
        S_n += k;
        // k powiększamy o 2, bo dodajemy przeciez kolejne nieparzyste
        k += 2;
        // zwiększamy wartość indeksu, bo przesuwamy się na kolejny wyraz. Da się to zrobić bez tej zmiennej, 
        // pamietając o tym, że k = (2*n - 1), możemy potem po prostu wyświetlić (((k + 1) / 2) - 1)
        ++n;
    }
    // jeżeli mamy równo, to potrzebujemy po prostu wyświetlić n
    // jeżeli mamy za dużo, to wyświetlamy n - 1
    cout << ((S_n > M) ? (n - 1) : (n)) << "\n";

    return 0;
}
