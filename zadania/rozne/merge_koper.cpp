/* K. Kafara */

#include <iostream>

using namespace std;


/**
 * Postanowiłem że jednak nie będę tamtego poprawiał, bo się zarypię xD Po prostu napiszę Ci jak to zrobić w miarę dobrze
 * Takiego mergesorta robiłbym trochę inaczej bo:
 * 1. jeżeli masz np. 65 liczb, to twój program będzie potrzebował miejsca na aż 128 liczb, a to zbędne + spowalnia
 * 2. W C++ pamięć można rezerwować dynamicznie (nie musisz pisać int A[10000] i na sztywno zakładać że będzie 10k liczb, bo co gdy będzie ich więcej?)
 * 3. Zrorganizujemy to troszeczkę inaczej:
 *	Podzielimy mergesorta na 2 funkcje:
 *	a) merge(…) scalająca 2 posortowane fragmenty tablicy w jeden dalej posortowany fragment: 
 * 		np. jak masz {1, 3, 5, 7} i {2, 4, 6, 9} to dostaniesz {1, 2, 3, 4, 5, 6, 7, 9}
 * 	b) merge_sort(…) - właściwą funkcję zarządzającą sortowaniem
 */

/**
 * Funkcja (a właściwie procedura - bo nic nie zwraca) scalająca 2 posortowane fragmenty tablicy A w jeden
 * Scalane fragmenty to: A[lewy_p … lewy_k] oraz A[(lewy_k + 1) … prawy_k]
 * \param lewy_p - "lewy_poczatek"
 * \param lewy_k - "lewy_koniec"
 * \param prawy_k - 'prawy koniec"
 * Prawy początek to lewy_koniec + 1, więc nie musimy go przesyłać
 */
void merge(int * A, int lewy_p, int lewy_k, int prawy_k)
{
	// Tworzymy sobie tablicę pomocniczą o takim rozmiarze ile jest elementów w rozważanym fragmencie tablicy A
	// to jest przedział [lewy_p, prawy_k] - ma (prawy_k - lewy_p + 1) elementow ==> 
	int B[prawy_k - lewy_p + 1];

	// tworzymy też sobie pomocnicze zmienne, którymi będziemy się poruszać po tablicy A
	int plewy_p = lewy_p, pprawy_p = lewy_k + 1;
	// zmienna lecąca po tablicy pomocniczej B
	int idx = 0; 

	/**
	 * No i teraz kluczowy fragment: 
	 * Mamy te 2 POSORTOWANE podtablice A[lewy_p … lewy_k] i A[lewy_k + 1 … prawy_k]
	 * scalamy je następująco: 
	 * 1. ustawiamy sobie zmienne na początki tych przedziałów (to już wyżej, w linii 35 zostało zrobione)
	 * 2. w każdej iteracji, bierzemy mniejszą z dwóch początkowych wartości w tych tablicach i wpisujemy ją do tablicy pomocniczej
	 * 3. zmienną lecącą po fragmencie z którego "wzięliśmy wartość" przesuwamy o jeden w prawo
	 * 4. powtarzamy kroki 2-3 do momentu w którym nie wyczerpie nam się jeden z fragmentów
	 * 5. przepisujemy to co zostało w jednym z fragmentów już do końca to tablicy pomocniczej. 
	 */ 

	while (plewy_p <= lewy_k && pprawy_p <= prawy_k)
	{
		if (A[plewy_p] <= A[pprawy_p])
		{
			B[idx] = A[plewy_p];
			++idx;
			++plewy_p;
		}
		else
		{
			B[idx] = A[pprawy_p];
			++idx;
			++pprawy_p;
		}
	}

	/// tutaj jeden fragment tablicy już się wyczerpał, więc jedna z tych pętli nie wykona się ani razu
	while (plewy_p <= lewy_k)
	{
		B[idx] = A[plewy_p];
		++idx; 
		++plewy_p;
	}
	while (pprawy_p <= prawy_k)
	{
		B[idx] = A[pprawy_p];
		++idx; 
		++pprawy_p;
	}

	// teraz w tablicy B mamy ten scalony fragment, pozostaje po przepisać to tablicy którą sortujemy, czyli A
	idx = 0;
	plewy_p = lewy_p;
	while (plewy_p <= prawy_k)
	{
		A[plewy_p] = B[idx];
		++plewy_p;
		++idx;
	}
}


/**
 * Właściwa funkcja sortująca
 */
void merge_sort(int * A, int size)
{
	// jeżeli długość tablicy jest <= 1 to znaczy że nie ma co sortować, więc przerywamy działanie procedury
	if (size <= 1) return;

	int krok = 2; 
	int lewy, prawy;

	while (krok <= size)
	{
		lewy = 0;
		prawy = krok - 1;

		while (lewy < (size - 1))
		{
			merge(A, lewy, (lewy + prawy) / 2, prawy);
			lewy += krok;
			prawy += krok;
			
			if (prawy >= size)
				prawy = size - 1;
			
		}

		krok *= 2;
	}
	merge(A, 0, (krok / 2) - 1, size - 1);
}


int main()
{
	const int SIZE = 12;
	int A[] = {2, 1, 4, 7, 2, 5, 2, 22, 18, 99, 1001, 33};

	merge_sort(A, SIZE);

	for (int i = 0; i < SIZE; ++i)
		cout << A[i] << " ";

	cout << "\n";
	return 0;
}
