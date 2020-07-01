#include <iostream>
#include <string>
using namespace std;
 
bool czy_jest_lider(int tablica[], int rozmiar_tablicy)
{
	// nazwy zmiennych może nie ideale, ale dobrze mi się z nimi teraz myśli
	int aktualny_lider, licznik_rownowagi = 0, wystapienia_lidera = 0;
 
	aktualny_lider = tablica[0];
	++licznik_rownowagi;
 
	// zaczynamy od i = 1, bo  pierwszy element już rozważyliśmy
	for (int i = 1; i < rozmiar_tablicy; ++i)
	{
		// jezeli dotychczas rozważany element występuje rzadziej niż inne, to w rym miejscu na pewno nie jest liderem
		// zatem  trzeba go zmienic
		if (licznik_rownowagi == 0)
		{
			aktualny_lider = tablica[i];
			licznik_rownowagi = 1;
		}
 
		else if (aktualny_lider == tablica[i])
			++licznik_rownowagi;
 
		else
			--licznik_rownowagi;
	}
 
	//jeżeli po ostatniej iteracji licznik wyniósł 0, to musimy wyłapać ten przypadek;
	if (licznik_rownowagi == 0) return false;
 
	else
	{
		for (int i = 0; i < rozmiar_tablicy; ++i)
		{
			if (tablica[i] == aktualny_lider)
				++wystapienia_lidera;
		}
	}
 
 
	if (wystapienia_lidera > (rozmiar_tablicy / 2))
		return true;
 
	else
		return false;
}
 
 
int main()
{
 
	int rozmiar_tablicy, liczba_przypadkow;
	int * tablica;
 
	cin >> liczba_przypadkow;
 
	for (int i = 0; i < liczba_przypadkow; ++i)
	{
		cin >> rozmiar_tablicy;
 
		tablica = new int[rozmiar_tablicy];
 
		for (int j = 0; j < rozmiar_tablicy; ++j)
			cin >> tablica[j];
 
		if (czy_jest_lider(tablica, rozmiar_tablicy) == true)
			cout << "TAK\n";
 
		else
			cout << "NIE\n";
 
		delete[] tablica;
	}
 
	return 0;
}
