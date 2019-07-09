/*
	Moja implementacja podstawowej wersji algorytmu Dijkstry do wyszukiwania 
	najkrótszej ścieżki w grafach nieskierowanych. 
	Zgodnie z tym co czytałem, najlepiej jest rozpoczynać przeglądanie sąsiadów od najbliższego (algorytmem zachłannym), 
	ale nie jest to konieczne. 
*/

#include <iostream> // do wyświetlania tablic i rezultatów
#include <vector>
#include <queue>
#include <stack>
#include <string>	// do wyświetlania tablic
using namespace std;

#define INF 100000

void wyswietl_macierz(int ** macierz, int rozmiar);

void wyswietl_graf(vector<int> * graf, int l_wierzcholkow);

void wyswietl_tablice(int T[], int rozmiar, const string &s);

void error(const string&);

void dij(vector<int> * G, int w_s, int ** W, bool * V, int * P, int * D, queue<int> * q, int l_w)
{
	// zmienna pomocnicza przechowująca drogę z rozważanego wierzchołka do rozważanego sąsiada (aby nie liczyć jej dwukrotnie)
	int d;
	// umieszczamy w kolejce wierzchołek startowy algorytmu
	q->push(w_s);
	// Bo droga z w_startowy do samego siebie wynosi 0
	D[w_s] = 0;
	P[w_s] = w_s;

	// dopóki kolejka nie jest pusta, czyli dopóki nie skończą się wierzchołki grafu
	while (!q->empty())
	{
		// pobieramy pierwszy wierzchołek z kolejki
		w_s = q->front();
		// zabieramy rozważany wierzchołek z kolejki
		q->pop();
		// rozważany wierzchołek oznaczamy jako odwiedzony
		V[w_s] = true;

		// przeglądamy wszystkich jego nieodwiedzonych sąsiadów
		for (auto i = G[w_s].begin(); i != G[w_s].end(); ++i)
		{
			if (!V[*i])
			{
				// liczymy drogę z obecnie rozważanego wierzchołka do obecnie rozważanego sąsiada
				d = D[w_s] + W[w_s][*i];
				// jeżeli nowo policzona droga jest krótsza od tej dotychczas znanej to podmieniamy
				// oraz zmieniamy wierzchołek z którego przyszliśmy 
				if (d < D[*i])
				{
					D[*i] = d;
					// oraz zmieniamy wierzchołek z którego przyszliśmy 
					P[*i] = w_s;
				}
				// dodajemy sąsiada do kolejki, aby go później rozważyć. 
				q->push(*i);
			}
		}
	}
	/* Po wykonianiu się tej funkcji, wszystkie tablice powinny zawierać prawidłowe rezultaty. */
}

void sciezka(int w_s, int w_k, int P[])
{
	// Jako że ścieżkę będziemy odtwarzać od końca, to kolejno uzyskiwane wierzchołki najwygodniej wrzucać jest na stos. 
	stack<int> s;
	// umieszczamy na samym spodzie stosu wierzchołek koncowy
	s.push(w_k);

	// dopóki wierzchołek końcowy nie stanie się wierzchołkiem startowym
	while (w_k != w_s)
	{
		// przypisz do w_koncowy indeks jego poprzednika
		w_k = P[w_k];
		// umiesc w_koncowy na stosie
		s.push(w_k);
	}
	// wyświetlanie stosu
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}

int main()
{
	/* WEJŚCIE I ZMIENNE DO JEGO OSŁUGI */
	/// =======================================
	int l_wierzcholkow, l_krawedzi, w_startowy, w_koncowy, l_testow, k_waga;

	// kolejka potrzebna do algorytmu
	queue<int> q;

	cout << "Podaj liczbe wierzcholkow i liczbe krawedzi: ";
	cin >> l_wierzcholkow >> l_krawedzi;
	/// =======================================

	/* REZERWACJA PAMIĘCI */
	/// =======================================
	// reprezentacja grafu w postaci lisy sąsiedztwa
	vector<int> * G = new vector<int>[l_wierzcholkow];

	// macierz przechowująca wagi poszczególnych krawędzi
	// W[i][j] - to waga krawędzi e(w_i, w_j) (w_i to wierzchołek o indeksie i)
	int ** W = new  int *[l_wierzcholkow];
	for (int i = 0; i < l_wierzcholkow; ++i)
	{
		// tworzenie tablic 1D składających się na całą macierz
		W[i] = new int[l_wierzcholkow];

		// inicjowanie zerami całej macierzy
		for (int j = 0; j < l_wierzcholkow; ++j)
			W[i][j] = 0;
	}

	// tablica wierzcholkow odwiedzonych
	bool * V = new bool[l_wierzcholkow];

	// P[i] - zawiera indeks wierzcholka z którego doszliśmy do w_i
	int * P = new int[l_wierzcholkow];

	// D[i] - zawiera najkrótszą obecnie znaną drogę z w_startowy do w_i
	int * D = new int[l_wierzcholkow];

	// petla inicjująca tablice V[], P[], D[]
	for (int i = 0; i < l_wierzcholkow; ++i)
	{
		V[i] = false;
		// bo jeszcze nie wiemy z jakiego wierzcholka przyszlismy
		P[i] = -1; 
		// INF = 100000, naiwnie zakładamy że większa wartość na wejściu nie wystąpi
		D[i] = INF;
	}
	/// =======================================

	/* WEJŚCIE C.D */
	/// =======================================
	cout << "Podaj kolejne krawedzie wraz z ich wagami:\n";

	for (int i = 0; i < l_krawedzi; ++i)
	{
		cin >> w_startowy >> w_koncowy >> k_waga;
		// uzupełniamy graf 
		G[w_startowy].push_back(w_koncowy);
		// uzupełniamy macierz z wagami poszczególnych krawędzi. 
		W[w_startowy][w_koncowy] = k_waga;
	}

	cout << "Podaj indeks wierzcholka poczatkowego oraz wierzcholka koncowego: ";
	cin >> w_startowy >> w_koncowy;
	/// =======================================

	/* ALGORYTM WYSZUKUJĄCY NAJKRÓTSZĄ ŚCIEŻKĘ (DIJKSTRA) */
	/// =======================================
	dij(G, w_startowy, W, V, P, D, &q, l_wierzcholkow);
	/// =======================================

	/* WYŚWIETLANIE ZAWARTOSCI TABLIC, GRAFU I MACIERZY 
	   W CELU DEBBUGOWANIA */
	/// =======================================
	wyswietl_macierz(W, l_wierzcholkow);

	wyswietl_graf(G, l_wierzcholkow);

	wyswietl_tablice(P, l_wierzcholkow, "POPRZEDNIKOW przed dij()");

	wyswietl_tablice(D, l_wierzcholkow, "DROG przed dij()");
	/// =======================================

	/* WYŚWIETLENIE REZULTATU, korzystając z funkcji sciezka(...) */ 
	/// =======================================
	cout << "Najkrotsza droga: " << D[w_koncowy] << " | poprzez wierzcholki: ";
	sciezka(w_startowy, w_koncowy, P);
	/// =======================================

	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	/// =======================================
	delete[] G;
	for (int i = 0; i < l_wierzcholkow; ++i)
		delete[] W[i];

	delete[] V;
	delete[] P;
	delete[] D;
	/// =======================================

	return 0; 
}

void wyswietl_macierz(int ** macierz, int rozmiar)
{
	cout << "MACIERZ WAG\n============\n";
	for (int i = 0; i < rozmiar; ++i)
	{
		for (int j = 0; j < rozmiar; ++j)
			cout << macierz[i][j] << " ";

		cout << "\n";
	}
	cout << "=============\n";
}

void wyswietl_graf(vector<int> * graf, int l_wierzcholkow)
{
	cout << "GRAF\n";
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

// wyswietl tablice
void wyswietl_tablice(int T[], int rozmiar, const string& s)
{
	cout << "TABLICA " << s << "\n";
	for (int i = 0; i < rozmiar; ++i)
		cout << T[i] << " ";

	cout << "\n";
}

void error(const string&s)
{
	cout << s << "\n";
}
