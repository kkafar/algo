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

/* ALGORYTM REALIZUJĄCY SCALANIE DWÓCH ZBIORÓW */
/// ================================================
// operujemy na podzbiorach sortowanej tablicy, zatem funkcja jako argumenty przyjmuje 
// indeksy granic scalanych przedziałów: 
// i_lewy_początek - indeks pierwszego elementu lewego przedziału (tego o indeksach mniejszych)
// i_prawy_poczatek  - indeks pierwszego elemntu prawego przedziału (tego o indeksach większych)
// i_prawy_koniec - indeks ostatniego elementu prawego przedziału
// i_lewy_koniec - nie pobieramy, bo to przecież (i_prawy_poczatek - 1);
void merge(int T[], int i_lewy_poczatek, int i_prawy_poczatek, int i_prawy_koniec)
{
	// tworzymy sobie kopie pobranych indeksów, bo będziemy potrzebować zmieniać ich wartości jednocześnie
	// pamiętając ich wartości początkowe
	// i1 - będziemy się za jego pomocą poruszać po lewej części przedziału
	// i2 - będziemy sie za jego pomocą poruszać po prawej części przedziału
	int i1 = i_lewy_poczatek, i2 = i_prawy_poczatek;
	// iterator służący do śledzenia miejsca wpisywania do tablicy pomocniczej P[]
	register int i = 0;

	// tworzymy tablicę pomocniczą, przechowującą tymczasowo scalony zbiór (na końcu przepiszemy jej zawartość do 
	// wejściowej tablicy)
	int * P = new int[i_prawy_koniec - i_lewy_poczatek + 1];

	// dopóki iteratory nie wyjdą poza przedziały na które mają wskazywać
	while (i1 < i_prawy_poczatek && i2 <= i_prawy_koniec)
	{
		// jeżeli pierwszy element prawej części talicy jest mniejszy, to jego wpisujemy do tablicy pomocniczej P[]
		if (T[i1] > T[i2])
		{
			// przypisujemy, a następnie inkrementujemy i2;
			P[i] = T[i2++];
		}
		// w wypadku gdy wartości są równe, bądź to pierwsza liczba w lewej części tablicy jest mniejsza
		else
		{
			P[i] = T[i1++];
		}

		// zwiększamy iterator i;
		++i;
	}

	// skoro wyszliśmy już za tą pętlę, to znaczy, że któraś część tablicy się już wyczerpała, więc resztę z drugiej części
	// przepisujemy do tablicy pomocniczej P[]
	while (i1 < i_prawy_poczatek)
	{
		P[i++] = T[i1++];
	}
	while (i2 <= i_prawy_koniec)
	{
		P[i++] = T[i2++];
	}

	// na koniec pozostaje przepisać zawartość tablicy pomocniczej P[] do tablicy T[]
	// tablice P[], uzupełnialiśmy od indeksu 0 (zawsze), więc trzeba przeliczyć indeksy. 
	for (int j = i_lewy_poczatek; j <= i_prawy_koniec; ++j)
		T[j] = P[j - i_lewy_poczatek];



	delete[] P;
}
/// ================================================


/* ALGORYTM SORTUJĄCY */ 
/// ================================================
// wykorzystujemy rekrurencję
// jako argumenty przyjmujemy indeksy graniczne sortowanego zbioru: 
// i_lewy_poczatek - indeks pierwszego elementu z lewej strony sortowanego zbioru
// i_prawy_koniec - indeks ostatniego elementu w prawej strony sortowanego zbioru
// przy pierwszym wywołaniu funkcji, powinniśmy podać granice zbioru który chcemy posortować
// czyli najczęściej 0 i (l_elementow - 1)
void merge_sort(int T[], int i_lewy_poczatek, int i_prawy_koniec)
{
	// zmienna w której będziemy przechowywać indeks pierwszego elementu w prawym podzbiorze
	// jako że korzystamy z rekurencji to będziemy sobie ją na bieżąco obliczać za każdym wywołaniem funkcji
	// od razu ustawiamy się na środku rozpatrywanego zbioru (może w nawiasie powinno być jeszcze +1)
	int i_prawy_poczatek = (i_lewy_poczatek + i_prawy_koniec + 1) / 2;

	// dzielimy zbiór, aż dojedziemy do singletonów

	// stoimy pośrodku zbioru [i_lewy_poczatek ; i_prawy_koniec]
	// jeżeli zbiór po naszej lewej jest więcej niż 1 elementowy, to wywołujemy się na nim rekurencyjnie
	// warunek: jeżeli (i_prawy_poczatek - 1 - i_lewy_poczatek > 0) <==> i_prawy_poczatek - i_lewy_poczatek > 1
	if (i_prawy_poczatek - i_lewy_poczatek > 1)
		merge_sort(T, i_lewy_poczatek, i_prawy_poczatek - 1);

	// jeżeli zbiór po naszej prawej jest więcej niż 1 elementowy to wywpłujemy sie na nim rekurencyjnie
	if (i_prawy_koniec - i_prawy_poczatek > 0)
		merge_sort(T, i_prawy_poczatek, i_prawy_koniec);

	merge(T, i_lewy_poczatek, i_prawy_poczatek, i_prawy_koniec);
}
/// ================================================



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
	// i_klucz - przechowuje takie indeks, że T[i_klucz] == klucz
	// index - przechowuje rezultat działania algorytmu. 
	int l_elementow, klucz, i_klucz, index;

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
	merge_sort(T, 0, l_elementow -1);
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
	cout << "Czas dzialania algorytmow jest wyrazowny w liczba_sekund\n";

	/// ===================================	
	t1 = clock();
	index = wyszukiwanie_interpolacyjne(T, l_elementow, klucz);
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << "wyszukiwanie interpolacyjne iter: " << index << " czas: " << dt << " znaleziona wartosc: " << T[index]<< "\n";

	/// ===================================	
	t1 = clock();
	index = wyszukiwanie_interpolacyjne_rek(T, klucz, 0, l_elementow - 1);
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << "wyszukiwanie interpolacyjne rek: " << index << " czas: " << dt << " znaleziona wartosc: " << T[index] << "\n";

	/// ===================================	
	t1 = clock();
	index = wyszukiwanie_binarne(T, l_elementow, klucz);
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << "wyszukiwanie binarne iter: " << index << " czas: " << dt << " znaleziona wartosc: " << T[index] << "\n";


	/// ===================================	
	t1 = clock();
	index =  wyszukiwanie_binarne_rek(T, klucz, 0, l_elementow - 1);
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << "wyszukiwanie binarne rek: " << index << " czas: " << dt << " znaleziona wartosc: " << T[index] << "\n";

	/// ===================================	
	t1 = clock();
	index = wyszukiwanie_liniowe(T, l_elementow, klucz);
	t2 = clock();
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	cout << "wyszukiwanie liniowe: " << index << " czas: " << dt << " znaleziona wartosc: " << T[index] << "\n";

	/// ===================================	



	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	/// ===================================
	delete[] T;
	/// ===================================

	return 0; 
}
