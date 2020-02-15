#include <iostream>
#include <string>
using namespace std;

// Nowsza, zgrabniejsza implementacja.
// Zasada działania oczywiście taka sama
/// ===================================
void insertion_sort(int * array, const int & size)
{
    int key; 
    register int j; 
    for (int i = 1; i < size; ++i)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
/// ===================================
 
/* ALGORYTM SORTOWANIA PRZEZ WSTAWIANIE */
template<class type>
void sortowanie_przez_wstawianie(type T[], int rozmiar_tablicy)
{
	type ustawiana_liczba;
	int index_liczby_po_lewej;
	// zaczynamy iterowanie od i == 1, bo index_liczby_po_lewe = i-1 ==> inaczej nie miałoby
	// to sensu
	for (int i = 1; i < rozmiar_tablicy; ++i)
	{
		// zapamiętujemy rozważaną liczbę
		ustawiana_liczba = T[i];
		index_liczby_po_lewej = i - 1; 
		// czyli do poki nie dojedziemy do pierwszego elementu tablicy
		while (index_liczby_po_lewej >= 0)
		{
			// jeżeli liczba po naszej lewej jest od nas większa
			if (ustawiana_liczba < T[index_liczby_po_lewej])
			{
				// to przesuwamy tą liczbę o raz w prawo
				T[index_liczby_po_lewej + 1] = T[index_liczby_po_lewej];
				// i idziemy dalej
				--index_liczby_po_lewej;
			}
 
			// jeżeli napotkaliśmy po naszej lewej stronie liczbę mniejszą bądź równą to wychodzimy z while'a
			else
				break;
		}
		// skoro tu jesteśmy to albo przejechaliśmy aż do pierwszego elementu tablicy
		// albo po naszej lewej stronie stoi liczba mniejsza bądź równa od ustawiana_liczba
		// skoro tak to tam skąd wcześniej przesunęliśmy wartość o raz w prawo wpisujemy naszą
		// ustawianą liczbę.
		T[index_liczby_po_lewej + 1] = ustawiana_liczba;
	}
}
/// ===================================
 
template<class type>
void wyswietl_tablice(type T[], int rozmiar_tablicy)
{
	for (int i = 0; i < rozmiar_tablicy; ++i)
		cout << T[i] << " ";
 
	cout << endl;
}
 
 
int main()
{
	int liczba_przypadkow, rozmiar_tablicy;
	double * tablica;
	cin >> liczba_przypadkow;
 
	for (int i = 0; i < liczba_przypadkow; ++i)
	{
		cin >> rozmiar_tablicy;
 
		tablica = new double[rozmiar_tablicy];
 
		for (int j = 0; j < rozmiar_tablicy; ++j)
			cin >> tablica[j]; 
 
		sortowanie_przez_wstawianie(tablica, rozmiar_tablicy);
 
		wyswietl_tablice(tablica, rozmiar_tablicy);
 
		delete[] tablica;
	}
	return 0;
}
 
