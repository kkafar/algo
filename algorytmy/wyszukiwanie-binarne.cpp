#include <iostream>
 
using namespace std;
 
template<class C>
int wyszukiwanie_binarne_iter(C tablica[], int rozmiar, C szukana)
{
	for (int aktualny = rozmiar / 2, prawa_granica = rozmiar - 1, lewa_granica = 0; lewa_granica <= prawa_granica;)
	{
		if (szukana < tablica[aktualny])
		{
			prawa_granica = aktualny - 1;
			aktualny /= 2;
		}
 
		else if (szukana > tablica[aktualny])
		{
			lewa_granica = aktualny + 1;
			aktualny = (lewa_granica + prawa_granica) / 2;
		}
 
		else
			return aktualny;
	}
 
	// umówmy się, że jeśli nie udało się znaleźć to zwracamy -1;
	return -1;
}
 
template<class C>
int wyszukiwanie_binarne_rek(C tablica[], int rozmiar, C szukana, int lewa_granica, int prawa_granica)
{
	if (lewa_granica <= prawa_granica)
	{
		int indeks_srodkowy = (lewa_granica + prawa_granica) / 2;
 
		if (szukana > tablica[indeks_srodkowy])
			return wyszukiwanie_binarne_rek(tablica, rozmiar, szukana, indeks_srodkowy + 1, prawa_granica);
 
		else if (szukana < tablica[indeks_srodkowy])
			return wyszukiwanie_binarne_rek(tablica, rozmiar, szukana, lewa_granica, indeks_srodkowy - 1);
 
		else
			return indeks_srodkowy;
	}
 
	// gdy nie uda się znaleźć szukanego elementu, tak jak w wersji interacyjnej, zwracamy -1
	return -1;
}
 
 
 
int main()
{
	int szukana, *tablica, rozmiar, przypadki_testowe;
 
	cin >> przypadki_testowe;
 
	for (int j = 0; j < przypadki_testowe; ++j)
	{
		cin >> rozmiar;
 
		tablica = new int[rozmiar];
 
		for (int i = 0; i < rozmiar; ++i)
			cin >> tablica[i];
 
		cin >> szukana;
 
		cout << "wersja iteracyjna: " << wyszukiwanie_binarne_iter(tablica, rozmiar, szukana) << endl;
		cout << "wersja rekurencyjna: " << wyszukiwanie_binarne_rek(tablica, rozmiar, szukana, 0, rozmiar - 1) << endl;
		delete[] tablica;
	}
 
    return 0;
}
 
