#include <iostream>
#include <string>
using namespace std;
 
void sortowanie_przez_zliczanie(int tablica[], int rozmiar_tablicy, int liczba_wartosci)
{
	int * tablica_wystapien_wartosci = new int[liczba_wartosci], index = 0; 
 
	for (int i = 0; i < liczba_wartosci; ++i)
		tablica_wystapien_wartosci[i] = 0; 
 
	for (int i = 0; i < rozmiar_tablicy; ++i)
		++tablica_wystapien_wartosci[tablica[i]];
 
	for (int i = 0; i < liczba_wartosci; ++i)
		for (int j = tablica_wystapien_wartosci[i]; j > 0; --j)
		{
			tablica[index] = i;
			++index;
		}
 
	delete[] tablica_wystapien_wartosci;
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
	int liczba_przypadkow, rozmiar_tablicy, maksymalna_wartosc;
	int * tablica;
	cin >> liczba_przypadkow;
 
	for (int i = 0; i < liczba_przypadkow; ++i)
	{
		cin >> rozmiar_tablicy >> maksymalna_wartosc;
		tablica = new int[rozmiar_tablicy];
 
		for (int j = 0; j < rozmiar_tablicy; ++j)
			cin >> tablica[j]; 
 
		sortowanie_przez_zliczanie(tablica, rozmiar_tablicy, maksymalna_wartosc + 1);
		wyswietl_tablice(tablica, rozmiar_tablicy);
 
		delete[] tablica;
	}
	return 0;
}
