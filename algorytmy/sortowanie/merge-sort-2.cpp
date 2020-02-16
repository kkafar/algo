/* 
	MERGE SORT 		WERSJA 2, bardziej przejrzysta i prostsza
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

/* Merge Sort */
/// ===================================================
void __merge(int * array, int left_beg, int left_end, int right_end)
{
	// additional one for sentinel
	int left_leng = left_end - left_beg + 1, right_leng = right_end - left_end;
	int left[left_leng + 1], right[right_leng + 1];
	// copying array's content
	for (int i = 0; i < left_leng; ++i)
		left[i] = array[left_beg + i];
	for (int i = 0; i < right_leng; ++i)
		right[i] = array[left_end + 1 + i];

	left[left_leng] = right[right_leng] = MAX_INT_32;
	
	//__print_array(left, left_leng);
	//__print_array(right, right_leng);

	for (register int i = 0, j = 0, k = left_beg; k <= right_end; ++k)
	{
		if (left[i] <= right[j])
			array[k] = left[i++];

		else
			array[k] = right[j++];			 
	}
}
/*
	\brief sorts given interval(?) of a given array

	\param *array - pointer to first element of to-be-sorted-array
	\param l      - beginning of the interval
	\param r 	  - end of the interval (must be in array's range)
*/
void __merge_sort(int * array, int l, int r)
{
	if (l < r)
	{
		int q = (l + r) / 2;
		__merge_sort(array, l, q);
		__merge_sort(array, q + 1, r);
		__merge(array, l, q, r);
	}
}
/// ===================================================

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
	int i1 = i_lewy_poczatek, i2 = i_prawy_poczatek;
	// iterator służący do śledzenia miejsca wpisywania do tablicy pomocniczej P[]
	register int i = 0;

	// tworzymy tablicę pomocniczą, przechowującą tymczasowo scalony zbiór (na końcu przepiszemy jej zawartość do 
	// wejściowej tablicy)
	int * P = new int[i_prawy_koniec - i_lewy_poczatek + 1];

	// dopóki iteratory nie wyjdą poza przedziały na które mają wskazywać
	while (i1 < i_prawy_poczatek && i2 <= i_prawy_koniec)
	{
		// jeżeli pierwszy element prawej części talicy jest mniejszy, to jego wpisujemy do tablicy pomocniczej P[]
		if (T[i1] > T[i2])
		{
			// przypisujemy, a następnie inkrementujemy i2;
			P[i] = T[i2++];
		}
		// w wypadku gdy wartości są równe, bądź to pierwsza liczba w lewej części tablicy jest mniejsza
		else
		{
			P[i] = T[i1++];
		}

		// zwiększamy iterator i;
		++i;
	}

	// skoro wyszliśmy już za tą pętlę, to znaczy, że któraś część tablicy się już wyczerpała, więc resztę z drugiej części
	// przepisujemy do tablicy pomocniczej P[]
	while (i1 < i_prawy_poczatek)
	{
		P[i++] = T[i1++];
	}
	while (i2 <= i_prawy_koniec)
	{
		P[i++] = T[i2++];
	}

	// na koniec pozostaje przepisać zawartość tablicy pomocniczej P[] do tablicy T[]
	// tablice P[], uzupełnialiśmy od indeksu 0 (zawsze), więc trzeba przeliczyć indeksy. 
	for (int j = i_lewy_poczatek; j <= i_prawy_koniec; ++j)
		T[j] = P[j - i_lewy_poczatek];



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
	// zmienna w której będziemy przechowywać indeks pierwszego elementu w prawym podzbiorze
	// jako że korzystamy z rekurencji to będziemy sobie ją na bieżąco obliczać za każdym wywołaniem funkcji
	// od razu ustawiamy się na środku rozpatrywanego zbioru (może w nawiasie powinno być jeszcze +1)
	int i_prawy_poczatek = (i_lewy_poczatek + i_prawy_koniec + 1) / 2;

	// dzielimy zbiór, aż dojedziemy do singletonów

	// stoimy pośrodku zbioru [i_lewy_poczatek ; i_prawy_koniec]
	// jeżeli zbiór po naszej lewej jest więcej niż 1 elementowy, to wywołujemy się na nim rekurencyjnie
	// warunek: jeżeli (i_prawy_poczatek - 1 - i_lewy_poczatek > 0) <==> i_prawy_poczatek - i_lewy_poczatek > 1
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
