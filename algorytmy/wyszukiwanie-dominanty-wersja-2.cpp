/*
	Wyszukiwanie dominanty w zbiorze liczbowym 
	WERSJA 2
	z wykorzystaniem sortowania przez scalanie.  

	Idea:
	Sortujewmy sobie zbiór niemalejąco ==> elementy o równych wartościach
	są zatem ustawione obok siebie ==> liniowo zliczamy który z elementów 
	występuje najwięcej razy! 
*/

#include <iostream>
#include <time.h> 		// do generowania liczb "losowych"

using namespace std;


template<class C>
void scalaj(C T[], int ilp, int ipp, int ipk)
{
	// iteratory służące do poruszania się po odpowiednio:
	// lewej i prawej części tablicy, oraz iterator poruszacjący się
	// po pomocniczej tablicy P[];
	register int lewy = ilp, prawy = ipp, i = 0; 

	// tworzymy pomocniczą tablicę P[] - tylu elementową ile elementów ma 
	// przedział [ilp; ipk];
	C P[ipk - ilp + 1];

	// dokonujemy scalania dopóki jeden z podzbiorów nam się nie wyczerpie
	while (lewy < ipp && prawy <= ipk)
	{
		// bierzemy mniejszy z najmniejszych elementów obu zbiorów
		// i od razu inkrementujemy iteratory
		if (T[lewy] < T[prawy])
		{

			P[i++] = T[lewy++];
		}

		else 
		{
			P[i++] = T[prawy++];
		}
	}

	// skoro wyszliśmy z tej pętli to conajmniej jeden ze zbiorów się wyczerpał
	// ==> zawartość drugiego zostaje nam już tylko przepisać do tablicy pomocniczej P[]
	
	while (lewy < ipp)
		P[i++] = T[lewy++];
	
	while (prawy <= ipk)
		P[i++] = T[prawy++];

	// pozostaje jedynie przepisać pomocniczą tablicę P[] do właściwej tablicy T[]

	// pamiętajmy że indeksy w tablicy P[] liczone są od zera, zatem musimy przesunąć
	for (int j = ilp; j <= ipk; ++j)
		T[j] = P[j - ilp];
}

template<class C>
void sortowanie_przez_scalanie(C T[], int ilp, int ipk)
{
	// oblicamy indeks pierwszego elementu prawego przedziału, musimy dodać 1
	// aby ipp był zawsze różny od ilp (inaczej mówiąć: lewy i prawy przedział były rozłącznę)
	int ipp = (ilp + ipk + 1) / 2;
	// dzelimy nasz zbiór na zbiory jedno elementowe! 
	// najpierw robimy to dla lewej strony (to bez znaczenia która najpierw)
	if (ipp - ilp > 1) sortowanie_przez_scalanie(T, ilp, ipp - 1);
	if (ipk - ipp > 0) sortowanie_przez_scalanie(T, ipp, ipk);

	scalaj(T, ilp, ipp, ipk);
}

template<class C>
void wyswietl_tablice(C T[], int l_elementow, const string& s)
{
	int licznik = 0;
	cout << s << "\n";
	for (int i = 0; i < l_elementow; ++i, ++licznik)
	{
		if (licznik == 15)
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

	/* ZMIENNE I WEJŚCIE */
	/// =====================================
	int l_elementow, l_wystapien, max_wystapien;
	double wartosc;

	// pobieramy liczbę elementów zbioru T[] (tego w którym szukamy dominanty)
	cin >> l_elementow; 
	
	// tablica przechowująca zbiór w którym szukamy dominanty 
	double * T = new double[l_elementow];
	/// ===================================== 

	/* GENEROWANIE ZAWARTOŚCI ZBIORU T[] */
	/// =====================================
	for (int i = 0; i < l_elementow; ++i)
		T[i] = rand() % 50;
	/// ===================================== 

	/* WYŚWIETLANIE ZAWARTOŚCI TABLICY DO DEBUGOWANIA */ 
	/// =====================================
	wyswietl_tablice(T, l_elementow, "T[] przed sortowaniem");
	/// =====================================

	/* SORTOWANIE ZBIORU */
	/// =====================================
	sortowanie_przez_scalanie(T, 0, l_elementow - 1);
	/// =====================================
	
	/* WYŚWIETLANIE ZAWARTOŚCI TABLICY DO DEBUGOWANIA */ 
	/// =====================================
	wyswietl_tablice(T, l_elementow, "T[] po sortowaniu");
	/// =====================================

	/* WYSZUKUJEMY NAJCZĘŚCIEJ WYSTĘPUJĄCY ELEMENT */
	/// ===================================== 
	// w tym momencie mamy już posortowaną tablicę, teraz należy znaleźć najczęściej
	// wsytępujący element. Przypisujemy wartości startowe, a następnie przeglądamy cały zbiór
	wartosc = T[0]; l_wystapien = 1; max_wystapien = 1;
	for (int i = 1; i < l_elementow; ++i)
	{
		// jeżeli natrafiliśmy na element zbioru T[] o innej wartości:
		if (T[i] != T[i - 1])
		{
			// to sprawdzamy czy liczba wystąpień starej wartości jest większa od max_wystąpień:
			if (l_wystapien > max_wystapien)
			{
				max_wystapien = l_wystapien;
				wartosc = T[i - 1];
			}

			// zerujemy licznik wystąpień dla nowej wartości 
			// zerujemy, a nie przypisujemy 1, bo po tym ifie i tak zostanie ta zmienna zinkrementowana
			l_wystapien = 0; 
		}

		++l_wystapien;
	}
	/// =====================================

	/* WYSWIETLANIE REZULTATÓW */
	/// =====================================
	cout << "dominanta: " << wartosc << " wystapila: " << max_wystapien << " razy.\n";
	/// =====================================


	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	/// =====================================
	delete[] T;
	/// =====================================
	return 0; 
}
