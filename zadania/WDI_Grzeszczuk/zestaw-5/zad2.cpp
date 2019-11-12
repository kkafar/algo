/*
    * ZADANIE 2
    * ZESTAW 5
Używając funkcji z poprzedniego zadania proszę napisać funkcję rozwiązującą układ 2
równań o 2 niewiadomych.
    * ZAKŁADAMY ŻE WSPÓŁCZYNNIKI SĄ WYMIERNE!!!!!!
*/

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
    a = (a < 0) ? (-a) : (a);
    b = (b < 0) ? (-b) : (b);
    while (a > 0 && b > 0)
    {
        if (a >= b) a %= b;
        else        b %= a;
    }
    // chcemy zwrócić niezerową, ale skoro druga jest zerem, to możemy zwrócić ich sumę
    // i się nie zastanawiać która jest która.
    if (a + b != 0)
        return a + b;
    else
    {
        cout << "nwd(" << a << ", " << b << ") zwraca wartość 0!";
        return -1;
    }
;
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

    void operator = (ulamek a)
    {
        l = a.l; 
        m = a.m;
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

struct rozw 
{
    ulamek x, y;
};
// rozwiąż równianie (2 równiania liniowe)
rozw rr(ulamek a, ulamek b, ulamek c, ulamek d, ulamek k, ulamek l)
{
/*
     (ax + by = k ∧ cx + dy = l) ==> x = (kd - bl) / (ad - bc) ∧ y = (al - ck) / (ad - bc)
     o ile istnieje rozwiązanie.
*/
    ulamek W, Wx, Wy;
    // rozwiązania:
    rozw r; r.x.l = 0; r.x.m = 0; r.y.l = 0; r.y.m = 0;


//  nigdzie nie definiowałem operatora =, ale we wcześniejszym zadaniu działało xD To może tutaj też
    W = a * d - b * c;
    cout << "W: "; W.pisz();
    Wx = k * d - b * l;
        cout << "Wx: "; Wx.pisz();
    Wy = a * l - c * k; 
        cout << "Wy: "; Wy.pisz();

    if (W.l == 0)
    {
        if (Wx.l == 0 && Wy.l == 0)
        {
            cout << "ROWNANIE NA INF WIELE ROZW\n";
        }
        else
        {
            cout << "ROWNANIE JEST SPRZECZNE\n";
        }
        // taka umowa
        return r;
    }

    else
    {
       r.x = (Wx / W);
      r.y = Wy / W;
    }
    return r;
}


int main()
{
    ulamek a, b, c, d, e, f;
    cout << "podaj wspolczynniki przy x odp. z 1. i 2. rownania: ";
    a.wczytaj(); 
    c.wczytaj();
    cout << "podaj wspolczynniki przy y odp. z 1. i 2. rownania: ";
    b.wczytaj();
    d.wczytaj();
    e.wczytaj();
    f.wczytaj();

    rozw R = rr(a, b, c, d, e, f);
    R.x.pisz();
    R.y.pisz();

    return 0;
}
