/*
  Brzydziej się pewnie nie dało, ale PRAWDOPODOBNIE DZIALA
  Zadanie 1 (2015/16)
Dane są trzy operacje na liczbach naturalnych oznaczone literami A, B i C.
A. jeżeli liczba posiada co najmniej 2 cyfry zamienia miejscami dwie ostatnie cyfry w liczbie
B. mnoży liczbę przez 3
C. jeżeli liczba posiada co najmniej 2 cyfry usuwa pierwszą cyfrę z liczby
Proszę napisać funkcję, która szuka sekwencji operacji przekształcającej liczbę naturalną x na y
(x!=y) o długości nie większej niż 7. Do funkcji należy przekazać liczby x, y.
Funkcja powinna zwrócić napis złożony z liter ABC realizujący przekształcenie albo łańcuch pusty
jeżeli przekształcenie nie istnieje. Na przykład dla liczb 6,3 funkcja powinna zwrócić napis
"BACB".
*/

#include <iostream>
#include <math.h>
using namespace std;

int swapLast2(int n)
{
    //cout << "swapLast2\n";
    int lastDigit = n % 10, obLastDigit = (n % 100) / 10;
    n -= n % 100;
    n += lastDigit * 10 + obLastDigit;
    return n;
}

int multiply(int n)
{
    //cout << "multiply\n";
    return 3*n;
}

int reFirstDigit(int n)
{
    //cout << "reFirstDigit\n";
    int kopia = n, currentDigit, iter = 0;
    while (kopia)
    {
        currentDigit = kopia % 10;
        kopia /= 10;
        ++iter;
    }
    n -= currentDigit * pow(10, iter - 1);
    return n;
}

bool done = false;
string f(int x, int y, string path, int i) // pierwsze wywołanie (x, y, x, "")
{
    //cout << "wyw:\n" << x << " " << y << " poziom:" << i << " " << path << "\n";
    cout << path << "\n";
    if (x == y)
    {
        done = true;
        return path;
    }
    if (i == 7)
    {
        if (x!=y) return "TOO DEEP\n";
        else      { done = true; return path;}
    }

    if (done == false && x >= 10) f(reFirstDigit(x), y, path+"rfd ", i + 1);
    if (done == false  && x >= 10) f(swapLast2(x), y, path+"sl2 ", i + 1);
    if (done == false) f(multiply(x), y, path+"mul ", i + 1);

    return path;
}

void wypisz(int n, int i)
{
        cout << i << "\n"; 
        if (i < n) wypisz(n, i + 1);
        if (i < n) cout << "TU\n";
}



int main()
{
    cout << f(6, 3, "", 0) << "WYNIK!!!!!!!!!!!!!!!!!!\n\n";
    return 0;
}
