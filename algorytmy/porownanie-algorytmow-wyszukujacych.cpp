/* 
	Porównanie czasu pracy algorytmów wyszukujących: liniowego, binarnego i interpolacyjnego. 
	Generujemy tablicę losowych liczb całkowitych, sortujemy ją, losujemy wartość którą będziemy 
	chcieli znaleźć i mierzymy czas pracy poszczególnych algorytmów
*/
#include <iostream>
#include <time.h>
#include <iomanip>
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
		if (T[i_klucz] == klucz) 		return i_klucz;
		// jeżeli klucz jest po naszej prawej stronie, to odpalamy się na przedziale po naszej prawej stronie
		else if (T[i_klucz] < klucz) 	wyszukiwanie_interpolacyjne_rek(T, klucz, i_klucz + 1, i_prawy);
		// jeżeli klucz jest po naszej lewej stonie to wywołujemy się na przedziale po naszej lewej stronie
		else 							wyszukiwanie_interpolacyjne_rek(T, klucz, i_lewy, i_klucz -1);
	}

	// jeżeli szukana wartość nie mieści się w rozpatrywanym przedziale to zwracamy (-1);
	else 
		return -1;
}
/// ===================================

/* ITERACYJNE WYSZUKIWANIE BINARNE*/
/// ===================================
int wyszukiwanie_binarne(int T[], int l_elementow, int klucz)
{
	// i_spr - indeks aktualnie sprawdzanego elementu, reszta oznaczeń jak w wyszukiwaniu interpolacyjnym
	register int i_spr;
	// warunek kończący pętlę: móglby równie dobrze być taki: klucz >= T[i_lewy] && klucz <= T[i_prawy]
	// taki jak jest też działa, bo w iteracjii po spotkanieu się indeksów i_lewy > i_prawy bądź na odwrót, ponieważ: 
	// wtedy np. T[i_spr] > klucz to musimy się ustawić na przedziale po naszej lewej stronie (a w tej chwili zachodzi równość
	// i_lewy == i_prawy) ==> i_prawy = i_spr - 1 ==> i_prawy < i_lewy i pętla się kończy. 
	for (int i_lewy = 0, i_prawy = l_elementow - 1; i_lewy <= i_prawy; )
	{
		// ustawiamy się na środku rozpatrywanego przedziału
		// dzielenie tutaj oczywiście mus być całkowite, bo i_spr jest liczbą naturalną
		i_spr = (i_prawy + i_lewy) / 2; 

		/* pytanie
			czy średnia arytmetyczna indeksów zawsze da mi środek rozpatrywanego przedziału? 
			wydaje się że tak, zobaczmy jak to będzie działać. 
		*/ 
		// jeżeli dobrze wyznaczyliśmy indeks szukanego elementu to go zwracamy;
		if (T[i_spr] == klucz)	return i_spr;
		// jeżeli klucz znajduje się po naszej prawej stronie
		else if (T[i_spr] < klucz) 
		{
			// to wtedy odpalamy się na przedziale po naszej prawej stronie:
			i_lewy = i_spr + 1; 
			// a i_prawy zostaje taki jak był
		}
		// analogicznie dla T[i_spr] > klucz
		else
		{
			i_prawy = i_spr - 1;
		}
	}

	// jeżeli nie udało się odnaleźć to  zwracamy (-1)
	return -1;


}
/// ===================================

/* WYSZUKIWANIE BINARNE WERSJA REKURENCYJNA */
/// ===================================
int wyszukiwanie_binarne_rek(int T[], int klucz, int i_lewy, int i_prawy)
{
	// ustawiamy się na środku rozpatrywanego przedziału
	int i_spr = (i_lewy + i_prawy) / 2; 

	// tak jak w iteracyjnym w sumie :D
	if (i_lewy <= i_prawy)
	{
		if (T[i_spr] == klucz) return i_spr;
		// klucz jest po naszej lewej stronie, to zmieniamy prawą granicę przedziału
		else if (T[i_spr] > klucz) wyszukiwanie_binarne_rek(T, klucz, i_lewy, i_spr - 1);
		// analogicznie gdy klucz jest po naszej prawej stronie
		else wyszukiwanie_binarne_rek(T, klucz, i_spr + 1, i_prawy);
	}
	// jeżeli nie udało się znaleźć to zwracamy (-1)
	else
		return -1;
}
/// ===================================

/* 	WYSZUKIWANIE LINIOWE */
/// ===================================
int wyszukiwanie_liniowe(int T[], int l_elementow, int klucz)
{
	// iterujemy sie przez całą tablicę i porównujemy klucz z każdym elementem tablicy T[]
	for (int i = 0; i < l_elementow; ++i)
		if (T[i] == klucz) return i;

	// jeżeli tu dotarliśmy to onacza że elementu o wartości klucz nie udało się znaleźć ==> 
	// zwracamy (-1)
	return -1;
}
/// ===================================

/* ALGORYTM SORTOWANIA PRZEZ WSTAWIANIE */
/// ===================================
// zdecydowałem się na niego, żeby dodać komentarze na githuba :D
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


void wyswietl_tablice(int T[], int l_elementow, const string& s)
{
	cout << s << "\n";
	// licznik do przerzucania do nowej lini
	int licznik = 0; 
	for (int i = 0; i < l_elementow; ++i)
	{
		if (licznik == 10)
		{
			cout << "\n";
			licznik = 0; 
		}

		cout << T[i] << " ";

		++licznik;
	}
	cout << "\n";
}

int main()
{
	srand(time(NULL));

	/* DEFINICJE ZMIENNYCH I WEJŚCIE */
	/// ===================================
	// klucz - poszukiwana wartość (tak można ją nazywać)
	// skoro klucz jest typu int, to zakładamy po cichu że elementy
	// zbioru T[] też są typu int
	int l_elementow, klucz, i_klucz;

	// zmienne do pomiaru czasu wykonania algorytmów
	clock_t t1, t2;
	double dt;

	cout << "Podaj liczbe elementoww zbioru: ";
	cin >> l_elementow;

	int * T = new int[l_elementow];

	// losowanie elementów zbioru;
	for (int i = 0; i < l_elementow; ++i)
		T[i] = rand() % 1000;

	// ustawienia wyjścia
	cout << fixed << setprecision(10);
	/// ===================================

	/* WYŚWIETLANIE ZAWARTOŚCI TABLICY T DO DEBUGGOWANIA */
	/// ===================================
	//wyswietl_tablice(T, l_elementow, "PRZED POSORTOWANIEM");
	/// ===================================

	/* SORTOWANIE */ 
	/// ===================================
	t1 = clock();
	sortowanie_przez_wstawianie(T, l_elementow);
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << "czas sortowania: " << dt << "\n";
	/// ===================================

	/* LOSOWANIE WARTOŚCI KLUCZA */ 
	/// ===================================
	i_klucz = rand() % l_elementow;
	klucz = T[i_klucz]; 
	/// ===================================

	/* WYŚWIETLANIE ZAWARTOŚCI TABLICY T DO DEBUGGOWANIA */
	/// ===================================
	//wyswietl_tablice(T, l_elementow, "PO POSORTOWANIU");
	/// ===================================

	/* WYŚWIETLENIE WYNIKU */ 
	/// ===================================	
	cout << "Poszukiwana wartosc to: " << klucz << " | indeks: " << i_klucz << "\n";

	t1 = clock();
	cout << "wyszukiwanie interpolacyjne iter: " << wyszukiwanie_interpolacyjne(T, l_elementow, klucz) << " czas: ";
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << dt << "\n";
	
	t1 = clock();
	cout << "wyszukiwanie interpolacyjne rek: " << wyszukiwanie_interpolacyjne_rek(T, klucz, 0, l_elementow - 1) << " czas: ";
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << dt << "\n";

	t1 = clock();
	cout << "wyszukiwanie binarne iter: " << wyszukiwanie_binarne(T, l_elementow, klucz) << "czas: ";
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << dt << "\n";

	t1 = clock();
	cout << "wyszukiwanie binarne rek: " << wyszukiwanie_binarne_rek(T, klucz, 0, l_elementow - 1) << "czas: ";
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << dt << "\n";

	t1 = clock();
	cout << "wyszukiwanie liniowe: " << wyszukiwanie_liniowe(T, l_elementow, klucz) << "czas: ";
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << dt << "\n";
	/// ===================================	



	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	/// ===================================
	delete[] T;
	/// ===================================

	return 0; 
}
