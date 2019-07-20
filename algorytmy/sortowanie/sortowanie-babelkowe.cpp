#include <iostream>
#include <string>
using namespace std;
 
template<class type> 
void sortowanie_babelkowe_rosnaco(type T[], int rozmiar_tablicy)
{
	type bufor;
	while (rozmiar_tablicy > 0)
	{
		// i < rozmiar_tablicy -1; bo i+1 wykraczałoby przecież poza zarezerwowaną pamięć
		for (int i = 0; i < rozmiar_tablicy - 1; ++i)
		{
			if (T[i] >= T[i + 1]) // no to zamieniamy je kolejnością
			{
				bufor = T[i + 1]; 
				T[i + 1] = T[i];
				T[i] = bufor;
			}
		}
		--rozmiar_tablicy;
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
	double *tablica;
 
	cin >> liczba_przypadkow;
 
	for (int i = 0; i < liczba_przypadkow; ++i)
	{
		cin >> rozmiar_tablicy;
		tablica = new double[rozmiar_tablicy];
 
		for (int j = 0; j < rozmiar_tablicy; ++j)
			cin >> tablica[j];
 
		sortowanie_babelkowe_rosnaco(tablica, rozmiar_tablicy);
		wyswietl_tablice(tablica, rozmiar_tablicy);
 
 
		delete[] tablica;
	}
 
 
	return 0;
}
 
