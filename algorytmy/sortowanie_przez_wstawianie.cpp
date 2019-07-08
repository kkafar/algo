#include <iostream>
#include <string>
using namespace std;
 
 
template<class type>
void sortowanie_przez_wstawianie(type T[], int rozmiar_tablicy)
{
	type ustawiana_liczba;
	int index_liczby_po_lewej;
	for (int i = 1; i < rozmiar_tablicy; ++i)
	{
		ustawiana_liczba = T[i];
		index_liczby_po_lewej = i - 1; 
		while (index_liczby_po_lewej >= 0)
		{
			if (ustawiana_liczba < T[index_liczby_po_lewej])
			{
				T[index_liczby_po_lewej + 1] = T[index_liczby_po_lewej];
				--index_liczby_po_lewej;
			}
 
			else
				break;
		}
		T[index_liczby_po_lewej + 1] = ustawiana_liczba;
	}
}
 
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
 
