/*
    ZADANIE 5
    ZESTAW 1
    5. Napisać program wyznaczający pierwiastek kwadratowy ze wzoru Newtona.
*/
/* 
    Korzystamy z metody Newtona obliczania pierwiastków 
    
    https://pl.wikipedia.org/wiki/Algorytm_obliczania_pierwiastka_n-tego_stopnia

    Niestety nie mam pomysłu jak to obliczać równolegle, dlatego najpierw obliczymy wartośc dwumianu newtona, a następnie wyliczymy z niego pierwiastek za pomocą tego algorytmu. 
*/ 
#include <iostream>
#include <iomanip>
using namespace std;

double absoluteValue(double x)
{
    return (x < 0) ? (-x) : (x);
}

// consty, bo  wartości tych zmiennych nie będą w żaden sposób modyfikowane 
unsigned long long dwumianNewtona(const int n, int k)
{
    unsigned long long result = 1;
    // będziemy liczyć z tej postaci: 
    // n(n-1)(n-2)(n-3)…(n - k + 1) / 1 / 2 / 3 / 4 / … / k

    // aby to chociaż troszeczkę usprawnić to korzystamy z wzoru (n po k) = (n po n - k)
    // bierzemy po prostu mniejsze k => będzie mniej mnożeń
    k = ((n - k) < k) ? (n - k) : (k);

    // dlatego pętla wykonująca się akurat k - razy.
    for (int i = 1; i <= k; ++i)
        result = (result * (n + 1 - i)) / i;
    
    return result;
}

// metoda jest następująca: 
/*
    Liczymy pierwiastek stopnia 2
    1. Jako pierwsze przybliżenie liczby bierzemy np. x_0 = M
    2.  x_(k+1) = 1/2 * ( x_k - a/x_k); 

    Można rekurencyjnie, ale można też iteracyjnie;
    Epsilon to żądana precyzja (domyślnie epsilon == 0.0001)
*/
double pierwiastekNewton(const unsigned long long M, const double epsilon = 0.0001)
{
    double x = M / 2; 
    while (absoluteValue(x * x - M) > epsilon)
        x = (x - M/x) / 2;

    // nie wiem dlaczego zwracało mi ujemy wynik, poprawny co do modułu. 
    // dlatego biorę |x|. 
    return absoluteValue(x);
}


int main()
{
    int n, k;
    cin >> n >> k;
    unsigned long long dwumian = dwumianNewtona(n, k);

    cout << dwumian << "\n";
    cout << "pierwiastek z dwumianu: " << setprecision(20) <<  pierwiastekNewton(dwumian, 0.00001) << "\n";
    // z jakichś dziwnych przyczyn zwara mi ujemny wynik? o co chodzi?
    // dobry co do wartości bezwzględnej
    return 0;
}
