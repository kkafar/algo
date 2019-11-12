#include <iostream>
using namespace std;


// METODY
// ==================================
/*
* Metoda zwracająca największy wspólny dzielnik liczb a i b 
* z wykorzystaniem arytmetyki modulo
*/
int nwd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a >= b) a %= b;
        else        b %= a;
    }
    // chcemy zwrócić niezerową, ale skoro druga jest zerem, to możemy zwrócić ich sumę
    // i się nie zastanawiać która jest która.
    return a + b;
}

/*
*   Metoda zwracająca najmniejszą wspólną wielokrotność 2 liczb.
*   Nie wiem czy istnieje fajniejszy algorytm (szybszy, z mniejszym ryzkiem wyjścia poza zakres int)
*/
int nww(int a, int b)
{
    // w takiej kolejności bo chcemy maksymalnie zminimalizować szanse wyjscia poza zkares typu int 
    return a / nwd(a, b) * b;
}
// ==================================

struct ulamek
{
    // POLA
    // ==================================
    // l - licznik, m - mianownik
    int l = 0, m = 1;
    // ==================================

    // METODY
    // ==================================
    // podnosimy ułamek do zadanej potęgi 
    void fpow(int exp)
    {
        int licznik = 1, mianownik = 1, wl = l, wm = m;
        while (exp)
        {
            if (exp & 1)
            {
                licznik *= wl;
                mianownik *= wm;
            }

            exp >>= 1;

            if (!exp) break;

            wl *= l;
            wm *= m;
            // TU KONTUNUUJEMY
        }
        
        // od razu skracamy
        int nw = nwd(licznik, mianownik);
        l = licznik;
        m = mianownik;
    }

    // skracamy ulamek
    void skroc()
    {
        int nw = nwd(l, m);
        l = l / nw;
        m = m / nw;
    }

    // wypisujemy ulamek
    void pisz()
    {
        cout << l << "/" << m << "\n";
    }

    void wczytaj()
    {
        cout << "\nPodaj ulamek, licznik, mianownik: ";
        cin >> l >> m;
    }
    // ==================================
};
/*
*   operator +, przeciążony tutaj, bo w structurze operator nie może przyjmować podwójnych argumentów? Przynajmniej tak 
*   interpretuje błędy wywalane przez kompilator. 
*   zwracamy ulamek względnie pierwszy!!!
*/
ulamek operator + (ulamek a, ulamek b)
{
    int nw = nww(a.m, b.m);
    ulamek returnVal; 
    returnVal.l = a.l * nw / a.m + b.l * nw / b.m;
    returnVal.m = nw;
    return returnVal;
}
ulamek operator - (ulamek a, ulamek b)
{
    int nw = nww(a.m, b.m);
    ulamek returnVal;
    returnVal.l = a.l * nw / a.m - b.l * nw / b.m;
    returnVal.m = nw;
    return returnVal;
}
ulamek operator * (ulamek a, ulamek b)
{
    ulamek returnVal;
    returnVal.l = a.l * b.l;
    returnVal.m = a.m * b.m;
    // jeszcze potrzebujemy skrócić ten ułamek
    returnVal.skroc();
    return returnVal;
}
ulamek operator / (ulamek a, ulamek b)
{
    ulamek returnVal;
    returnVal.l = a.l * b.m;
    returnVal.m = a.m * b.l;
    int nw = nwd(returnVal.l, returnVal.m);
    returnVal.skroc();
    return returnVal;

}
int main()
{
    ulamek a, b; 
    a.wczytaj();
    a.skroc();
    a.pisz();
    a.fpow(3);
    a.pisz();
    return 0;
}
