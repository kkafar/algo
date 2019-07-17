/* 
	Wyszukiwanie interpolacyjne
	O(log(log n))
	* Dlaczego złożoność jest taka, nie potrafię wytłumaczyć, informacja ze strony
	eduinf.waw.pl
	https://eduinf.waw.pl/inf/alg/001_search/0039.php

	Dokładny opis działania algorytmu w czerwonym zeszycie (to info dla mnie) albo po prostu na internecie

	** Algorytm ten operuje na posortowanej niemalejąco tablicy liczb. 
*/

#include <iostream>

using namespace std;

/* FUNKCJA REALIZUJĄCA ALGORYTM WYSZUKIWANIA INTERPOLACYJNEGO */
// zwraca indeks, pod którym w zbiorze T[] znajduje się szukany element
// jeżeli szukany element nie nalezy do zbioru T[] to zwraca (-1)
/// ===================================
int wyszukiwanie_interpolacyjne(int T[], int l_elementow, int klucz)
{
	// zmienne pomocnicze: 
	/*
	*   i_prawy - indeks ostatniego elementu rozpatrywanego przedziału (= l_elementów - 1)
		bo na początku zaczynamy od rozpatrywania całego zbioru
	*	i_lewy - indeks pierwszego ----------------//---------------- (= 0) bo: jak dla i_prawy
	*	i_klucz - oszacowany indeks pod którym prawdopodobnie znajduje się szukany element.
	*/
	int i_klucz;
	// pętla wykonuje się dopóki wartość klucz zawiera się w przedziale [T[i_lewy] ; T[i_prawy]]
	for (int i_prawy = l_elementow - 1, i_lewy = 0; (klucz <= T[i_prawy]) && (klucz >= T[i_lewy]); )
	{
		// i_klucz obliczamy zgodnie ze wzorem wyprowadzonym w "czerwonym zeszycie"
		// bądź też na stronie: https://eduinf.waw.pl/inf/alg/001_search/0039.php
		// to dzielenie w nawiasach powinno być całkowite, bo przecież i_klucz jest liczbą naturalną.
		i_klucz = i_lewy + ( ( (klucz - T[i_lewy]) * (i_prawy - i_lewy) ) / (T[i_prawy] - T[i_lewy]) );

		//jeżeli udało nam się wyznaczyć indeks poszukiwanego elementu to go zwracamy
		if (T[i_klucz] == klucz)
			return i_klucz;

		// w przeciwynym wypadku:
		// (pamiętajmy, że działamy na posortowanej tablicy):
		// jeżeli T[i_klucz] > klucz to znaczy że wartość klucz jest gdzies po naszej lewej stronie
		// w innym wypadku jest po naszej prawej stronie ==> w odpowiedni sposób (właściwie jak przy
		// wyszukiwaniu binarnym) ustawiamy granice rozpatrywanych przedziałów
		else if (T[i_klucz] > klucz)
		{
			i_prawy = i_klucz - 1; 
			// i_lewy zostaje taki jaki był wczesniej
		}

		else
		{
			i_lewy = i_klucz + 1;
			// i_prawy zostaje taki jaki był wcześniej
		}
	}

	// jeżeli jesteśmy w tym miejscu, to oznacza że w pętli nie został odnaleziony element o wartości 
	// klucz ==> funkcja nie zwróciła wartości, zatem zwracamy (-1) jako znak niepowodzenia
	return -1;
}
/// ===================================

/* wYSZUKIWANIE IINTERPOLACYJNE WERSJA REKURENCYJNA */ 
/// ===================================
int wyszukiwanie_interpolacyjne_rek(int T[], int klucz, int i_lewy, int i_prawy)
{
	// jeżeli szukana wartość mieści się w rozpatrywanym przedziale
	if (klucz >= T[i_lewy] &&  klucz <= T[i_prawy])
	{
		// najpierw obliczamy prawdopodobny indeks szukanego elementu, dokładnie tak jak w wersji iteracyjnej
		int i_klucz = i_lewy + ( ( (klucz - T[i_lewy]) * (i_prawy - i_lewy) ) / (T[i_prawy] - T[i_lewy]) );

		// jeżeli wyznaczyliśmy indeks szukanego elementu poprawnie to go zwracamy
		if (T[i_klucz] == klucz) 	return i_klucz;
		// jeżeli klucz jest po naszej prawej stronie, to odpalamy się na przedziale po naszej prawej stronie
		else if (T[i_klucz] < klucz) 	wyszukiwanie_interpolacyjne_rek(T, klucz, i_klucz + 1, i_prawy);
		// jeżeli klucz jest po naszej lewej stonie to wywołujemy się na przedziale po naszej lewej stronie
		else 				wyszukiwanie_interpolacyjne_rek(T, klucz, i_lewy, i_klucz -1);
	}

	// jeżeli szukana wartość nie mieści się w rozpatrywanym przedziale to zwracamy (-1);
	else 
		return -1;
}
/// ===================================

int main()
{
	/* DEFINICJE ZMIENNYCH I WEJŚCIE */
	/// ===================================
	// klucz - poszukiwana wartość (tak można ją nazywać)
	// skoro klucz jest typu int, to zakładamy po cichu że elementy
	// zbioru T[] też są typu int
	int l_elementow, klucz;

	cin >> l_elementow;

	int * T = new int[l_elementow];
	// pobieranie elementów zbioru
	for (int i = 0; i < l_elementow; ++i)
		cin >> T[i]; 

	cin >> klucz;
	/// ===================================


	/* WYŚWIETLENIE WYNIKU */ 
	/// ===================================	
	cout << "szukana wartosc znajduje sie na pozycji: " << wyszukiwanie_interpolacyjne(T, l_elementow, klucz) << "\n";
	cout << "wg algorytmu rekurencyjnego: " << wyszukiwanie_interpolacyjne_rek(T, klucz, 0, l_elementow - 1) << "\n";
	/// ===================================	



	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	/// ===================================
	delete[] T;
	/// ===================================

	return 0; 
}
