/*
	Algorytm znajdujący graf będący kwadratem wejściowego (początkowego) grafu skierowanego.
	Kwadrat grafu to graf powstały poprzez dodanie krawędzi pomiędzy każdym z wierzchołków,
	a sąsiadami jego bezpośrednich sąsiadów. 

	Algorytm operuje na grafach reprezentowanych poprzez listy sąsiedztwa. 
	
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void wyswietl_graf(vector<int> * graf, int l_wierzcholkow, const string& s);

void sqr_graph(vector<int> * G, vector<int> * sqrG, int l_wierzcholkow)
{
	// zmienna pomocnicza do sprawdzania czy dla pewnego wierzołka i, dodaliśmy 
	// już sąsiada jego bezpośredniego sąsiada
	bool dodany = false;

	// pętla iterująca się przez wszystkie wierzchołki grafu wejściowego 
	for (int i = 0; i < l_wierzcholkow; ++i)
	{
		// odwiedzamy wszyskich sąsiadów wierzchołka i
		for (auto j = G[i].begin(); j != G[i].end(); ++j)
		{
			// wszystkich bezpośrednich sąsiadów umieszczamy w drugim grafie
			sqrG[i].push_back(*j);

			// przeglądamy wszystkich sąsiadów każdego sąsiada wierzchołka i
			// jeżeli nie jest jeszcze dodany to dodajemy
			for (auto k = G[*j].begin(); k != G[*j].end(); ++k)
			{
				// sprawdzamy czy w_k jest już dodany do sąsiadów w_i
				for (auto l = G[i].begin(); l != G[i].end(); ++l)
				{
					// jeżeli w sąsiadach w_i znleźliśmy sąsiada bezpośredniego sąsiada sąsiada (czyli w_k) 
					// to ustawiamy że jest już dodany, i przerywamy działanie pętli szukającej
					if (*l == *k)
					{
						dodany = true;
						break;
					}
				}

				// jeżeli w_k nie był wcześniej dodany, to go dodajemy do sąsiadów w_i
				// i resetujemy wartość zmiennej dodany
				if (!dodany)
				{
					sqrG[i].push_back(*k);
					dodany = false;
				}
			}
	
		}
	}

}

int main()
{
	/* WEJŚCIE, ZMIENNE, OBSŁUGA */
	///===============================
	int l_krawedzi, l_wierzcholkow, w_startowy, w_koncowy;

	cin >> l_wierzcholkow >> l_krawedzi;
	///===============================
	
	/* REZERWOWANIE PAMIĘCI NA GRAF */
	///===============================
	// graf wyjściowy
	vector<int> * G = new vector<int>[l_wierzcholkow];	
	// kwadrat grafu G
	vector<int> * sqrG = new vector<int>[l_wierzcholkow];
	///===============================

	/* WCZYTYWANIE GRAFU */
	///===============================
	for (int i = 0; i < l_krawedzi; ++i)
	{
		cin >> w_startowy >> w_koncowy;
		G[w_startowy].push_back(w_koncowy);
	}
	///===============================

	/* WYWOŁANIE FUNKCJI ZNAJDUJĄCEJ KWADRAT GRAFU G */
	///===============================
	sqr_graph(G, sqrG, l_wierzcholkow);
	///===============================

	/* WYŚWIETLANIE REZULTATÓW */
	///===============================
	wyswietl_graf(G, l_wierzcholkow, "G");
	wyswietl_graf(sqrG, l_wierzcholkow, "sqrG");
	///===============================

	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	///=============================== 
	delete[] G; delete[] sqrG;
	///===============================
	return 0;
}

void wyswietl_graf(vector<int> * graf, int l_wierzcholkow, const string& s)
{
	cout << "GRAF " << s << "\n";
	for (int i = 0; i < l_wierzcholkow; ++i)
	{
		cout << i << ": ";
		for (auto j = graf[i].begin(); j != graf[i].end(); ++j)
		{
			cout << *j << " ";
		}
		cout << "\n";
	}
}
