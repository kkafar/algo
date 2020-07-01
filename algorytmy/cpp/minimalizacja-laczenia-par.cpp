// zwraca indeks najmniejszego elementu
#include <iostream>
using namespace std;
 
template<class C>
C znajdz_minimum(C tablica[], bool tablica_bool[], int rozmiar)
{
	C minimum, minimum_index;
 
	minimum_index = 0;
	minimum = 1000;
 
	for (int i = 0; i < rozmiar; ++i)
	{
		if (minimum > tablica[i] && tablica_bool[i] == true)
		{
			minimum = tablica[i];
			minimum_index = i;
		}
	}
 
	tablica_bool[minimum_index] = false;
 
	return minimum_index;
}
 
 
int main()
{
	int *tablica, liczba_przypadkow, rozmiar_tablicy, koszt, liczby_niesparowane, index_1, index_2;
	bool *tablica_bool;
 
	cin >> liczba_przypadkow;
 
	for (int i = 0; i < liczba_przypadkow; ++i)
	{
		// w kazdym przypadku koszt na samym poczatku wynosi 0
		koszt = 0; 
 
		cin >> rozmiar_tablicy;
 
		tablica = new int[rozmiar_tablicy];
		tablica_bool = new bool[rozmiar_tablicy];
		liczby_niesparowane = rozmiar_tablicy;
 
		for (int j = 0; j < rozmiar_tablicy; ++j)
		{
			cin >> tablica[j];
			tablica_bool[j] = true;
		}
 
		while (liczby_niesparowane > 1)
		{
			//znajdujemy indeks najmniejszego elementu
			// index_1 != index_2, funkcja dba o to, ale gdy tablica jest jednoelemntowa to też powinno działać (wyjątek)
			index_1 = znajdz_minimum(tablica, tablica_bool, rozmiar_tablicy);
			index_2 = znajdz_minimum(tablica, tablica_bool, rozmiar_tablicy);
 
			tablica[index_1] = tablica[index_1] + tablica[index_2];   //zapisujemy minimalny koszt pojedynczego połączenia w parę
 
			koszt += tablica[index_1];                                // uaktualniamy zmienną koszt
 
			tablica_bool[index_1] = true;							// przywracamy komórkę z nowo utworzoną liczbą do rozważań
 
			--liczby_niesparowane;
		}
 
		cout << "koszt: " << koszt << endl;
 
		delete[] tablica;
	}
	return 0;
}
