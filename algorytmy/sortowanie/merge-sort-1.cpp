/* 
	MERGE SORT 		WERSJA 1
	Sortowanie przez scalanie
	O(n * logn)
*/

#include <iostream>
#include <time.h>

using namespace std;
void error(const string& s)
{
	cout << s << "\n";
}

/* ALGORYTM REALIZUJĄCY SCALANIE DWÓCH ZBIORÓW */
/// ================================================
// operujemy na podzbiorach sortowanej tablicy, zatem funkcja jako argumenty przyjmuje 
// indeksy granic scalanych przedziałów: 
// i_lewy_początek - indeks pierwszego elementu lewego przedziału (tego o indeksach mniejszych)
// i_prawy_poczatek  - indeks pierwszego elemntu prawego przedziału (tego o indeksach większych)
// i_prawy_koniec - indeks ostatniego elementu prawego przedziału
// i_lewy_koniec - nie pobieramy, bo to przecież (i_prawy_poczatek - 1);
void merge(int T[], int i_lewy_poczatek, int i_prawy_poczatek, int i_prawy_koniec)
{
	// tworzymy sobie kopie pobranych indeksów, bo będziemy potrzebować zmieniać ich wartości jednocześnie
	// pamiętając ich wartości początkowe
	// i1 - będziemy się za jego pomocą poruszać po lewej części przedziału
	// i2 - będziemy sie za jego pomocą poruszać po prawej części przedziału
	int i1 = i_lewy_poczatek, i2 = i_prawy_poczatek, i3 = i_prawy_koniec;

	// tworzymy tablicę pomocniczą, przechowującą tymczasowo scalony zbiór (na końcu przepiszemy jej zawartość do 
	// wejściowej tablicy)
	int * P = new int[i_prawy_koniec - i_lewy_poczatek + 1];
	for (int i = i_lewy_poczatek; i <= i_prawy_koniec; ++i)
		P[i] = 0;

	// pętla iterująca przez cały rozważay przedział, od skrajnego lewego elementu, to skrajnego prawego
	for (int i = i_lewy_poczatek; i <= i_prawy_koniec; ++i)
	{
		// na to trzeba wpatrywać się tak długo, aż stanie się oczywiste :D
		// i1 == i_prawy_poczatek - czyli gdy skończą nam się elementy lewej częsci tablicy
		// to wtedy chcemy po prostu przepisać to co zostało z prawej strony
		// (i2 <= i_prawy_koniec && T[i1] > T[i2]) - jeżeli iterator prawej strony nie wyszedł poza nią i pierwszy element 
		// z prawej strony jest mniejszy niż pierwszy z lewej - to bierzemy pierwszy element w prawej strony i 
		// zwiększamy iterator
		if ( (i1 == i_prawy_poczatek) || (i2 <= i_prawy_koniec && T[i1] > T[i2]) )
		{
			P[i] = T[i2];
			++i2;
		}

		// to gdy obydwa iteratory są w swoich granicach i T[i1] < T[i2]
		// wtedy bierzemy pierwszy element z lewego przedziału
		else 
		{
			P[i] = T[i1];
			++i1;
		}
	}

	// na koniec pozostaje na przepisać zawartość tablicy pomocniczej do sortowanej
	for (int i = i_lewy_poczatek; i <= i_prawy_koniec; ++i)
		T[i] = P[i];

	delete[] P;
}
/// ================================================


/* ALGORYTM SORTUJĄCY */ 
/// ================================================
// wykorzystujemy rekrurencję
// jako argumenty przyjmujemy indeksy graniczne sortowanego zbioru: 
// i_lewy_poczatek - indeks pierwszego elementu z lewej strony sortowanego zbioru
// i_prawy_koniec - indeks ostatniego elementu w prawej strony sortowanego zbioru
// przy pierwszym wywołaniu funkcji, powinniśmy podać granice zbioru który chcemy posortować
// czyli najczęściej 0 i (l_elementow - 1)
void merge_sort(int T[], int i_lewy_poczatek, int i_prawy_koniec)
{
	error("merge_sort()");
	cout << "wywolany na argumentach: " << i_lewy_poczatek << " " << i_prawy_koniec << "\n";
	// zmienna w której będziemy przechowywać indeks pierwszego elementu w prawym podzbiorze
	// jako że korzystamy z rekurencji to będziemy sobie ją na bieżąco obliczać za każdym wywołaniem funkcji
	// od razu ustawiamy się na środku rozpatrywanego zbioru (może w nawiasie powinno być jeszcze +1)
	int i_prawy_poczatek = (i_lewy_poczatek + i_prawy_koniec +  1) / 2;

	// dzielimy zbiór, aż dojedziemy do singletonów

	// stoimy pośrodku zbioru [i_lewy_poczatek ; i_prawy_koniec]
	// jeżeli zbiór po naszej lewej jest więcej niż 1 elementowy, to wywołujemy się na nim rekurencyjnie
	// warunek: jeżeli (i_prawy_poczatek - 1 - i_lewy_poczatek > 0) <==> i_prawy_poczatek - i_lewy_poczatek > 1
	cout << "1. if " << i_prawy_poczatek - i_lewy_poczatek << "\n";
	if (i_prawy_poczatek - i_lewy_poczatek > 1)
		merge_sort(T, i_lewy_poczatek, i_prawy_poczatek - 1);

	// jeżeli zbiór po naszej prawej jest więcej niż 1 elementowy to wywpłujemy sie na nim rekurencyjnie
	if (i_prawy_koniec - i_prawy_poczatek > 0)
		merge_sort(T, i_prawy_poczatek, i_prawy_koniec);

	merge(T, i_lewy_poczatek, i_prawy_poczatek, i_prawy_koniec);
}
/// ================================================




template<class C>
void wyswietl_tablice(C T[], int rozmiar, const string& s)
{
	register int licznik = 0; 
	cout << s << "\n";
	for (int i = 0; i < rozmiar; ++i, ++licznik)
	{
		if (licznik == 20)
		{
			cout << "\n";
			licznik = 0; 
		}

		cout << T[i] << " ";
	}
	cout << "\n";
}

int main()
{
	srand(time(NULL));

	int l_elementow;

	cin >> l_elementow;

	int * T = new int[l_elementow];

	for (int i = 0; i < l_elementow; ++i)
		T[i] = rand() % 1000;

	wyswietl_tablice(T, l_elementow, "tablica T[] przed posortowaniem");

	merge_sort(T, 0, l_elementow - 1);

	wyswietl_tablice(T, l_elementow, "tablica T[] po posortowaniu");

	delete[] T;

	return 0;
}
