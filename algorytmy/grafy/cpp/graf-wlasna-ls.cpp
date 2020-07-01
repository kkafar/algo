/*
 * Ćwiczenie: Reprezentacja grafu za pomocą listy sąsiedztwa ( z tym, że wykorzystujemy własną listę jednokierunkową)
 */

#include <iostream>

using namespace std;


/* KLASA REPREZENTUJĄCA LISTĘ JEDNOKIERUNKOWĄ */
/// =========================================
template<class T>
class List
{
public:
	// wartośc danego elementu w liście
	T value;

	// wskaźnik do następnego elementu w liście
	// inicjujemy NULL'em, żeby zawsze ostatni element listy
	// wskazywał na NULL
	List<T> * next = NULL;
};
/// =========================================


void wyswietl_graf(List<int> ** G, int l_w, const string& str)
{
	cout << str << "\n";
	for (int i = 0; i < l_w; ++i)
	{
		cout << i << ": ";
		for (List<int> * j = G[i]; j; j = j->next)
		{
			cout << j->value << " ";
		}
		cout << "\n";
	}
}

int main()
{
	/* REZERWACJA PAMIĘCI + WEJŚCIE */
	/// =========================================
	int l_wierzcholkow, l_krawedzi, w_startowy, w_koncowy;

	cin >> l_wierzcholkow >> l_krawedzi;

	// graf będziemy reprezentować jako listę sąsiedztwa, potrzebujemy zatem tablicę list sąsiedztwa
	List<int> ** G = new List<int> * [l_wierzcholkow];
	// zmienna pomocnicza do dodawania nowych elementów na listę
	List<int> * p;
	// tworzymy osobną listę dla każdego z wierzchołków.
	// przypisujemy null, aby lista była pusta
	// gdybyśmy napisali G[i] = new List<int>; to dodalibyśmy wierzchołkowi i sąsiada,
	// a jeszcze nie wiemy czy ma jakiegokolwiek.
	for (int i = 0; i < l_wierzcholkow; ++i)
		G[i] = NULL;

	/// =========================================

	/* WCZYTYWANIE GRAFU */
	/// =========================================
	for (int i = 0; i < l_krawedzi; ++i)
	{
		// pobieramy dane krawędzi
		cin >> w_startowy >> w_koncowy;

		// tworzymy nowy element, który trafi na listę
		p = new List<int>;

		// nadajemy my wartość indesku sąsiada w_i
		p->value = w_koncowy;

		// dodajemy go na początek listy G[i] w sposób następujący
		// Zapisujemy w obiekcie p adres obecnego pierwszego elementu listy.
		p->next = G[w_startowy];
		// ustawiamy p jako pierwszy element listy. (wcześniejszy pierwszy, teraz drugi, jest wskazywany przez
		// pole G[w_startowy]->next
		G[w_startowy] = p;
	}
	/// =========================================

	/* WYŚWIETLANIE GRAFU */
	/// =========================================
	wyswietl_graf(G, l_wierzcholkow, "GRAF");
	/// =========================================


	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	/// =========================================
	// zmienna pomocnicza do usuwania
	List<int> * u;
	for (int i = 0; i < l_wierzcholkow; ++i)
	{
    // iterujemy się przez wszystkich sąsiadów wierzchołka i
		for (List<int> * j = G[i]; j;)
		{
			u = j;
			j = j->next;
			delete u;
		}

	}
	delete p;
  // "u" przestawia się na null za każdą iteracją pętli, więc my już tego robić nie musimy
	/// =========================================

	return 0;
}
