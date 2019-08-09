#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void resetArray(int l, int u, int val, int T[]);

void printGraph(vector<int> * G, int size);

void printArray(int T[], int size);

int main()
{
	// liczba wierzchołków, początek krawędzi, koniec krawędzi, liczba mrówek, zmienna pomocnicza
	int l_w, b, e, l_m, v;
	// pobieramy liczbę liści i rozgałęzień
	cin >> l_w; 

	// lw + 1 bo numerujemy liście i gałęzie od 1
	vector<int> * G = new vector<int>[l_w + 1];
	// g[i] - ID mrówki znajdującej się na wierzchołku i
	int * g = new int[l_w + 1], * prev = new int[l_w + 1], * t = new int[l_w + 1];
	// jeżeli g[i] == -1 to znaczy że nie ma tam mrówki. g[i] - mamy id mrówki na wierzchołku i
	for (int i = 1; i <= l_w; ++i)	
		t[i] = prev[i] = g[i] = -1;

	// pobieramy definicje kolejnych krawędzi 
	for (int i = 1; i <= l_w-1; ++i)
	{
		cin >> b >> e;
		// krawędzie są dwustronne
		G[b].push_back(e);
		G[e].push_back(b);
	}

	// pobieramy liczbę mrówek 
	cin >> l_m;

	// tworzymy tablicę z pozycjami mrówek --> w M[i] mamy aktualną pozycję mrówki i (indeks 
	// wierzchołka na którym się aktualnie znajduje). (b + 1) bo numerujemy od 1
	int * M = new int[l_m + 1];
	// w m[i] mamy ile razy mrówka i przepędziła biedronkę
	int * m = new int[l_m + 1];
	int * blocked = new int[l_m + 1];

	for (int i = 1; i <= l_m; ++i)
	{
		// przy okazji zerujemy m[] i blocked[]
		blocked[i] = 0;
		m[i] = 0; 
		// pobieramy pozycje mrówki i 
		cin >> M[i];

		g[M[i]] = i;
	}
	cout << "Zawartosc grafu: \n"; printGraph(G, l_w);
	cout << "\nblocked[]: "; printArray(blocked, l_m);
	cout << "\nm[]: "; printArray(m, l_m);
	cout << "\nM[]: "; printArray(M, l_m);
	cout << "\ng[]: "; printArray(g, l_w);

	// liczba ataków biedronki
	cout << "\nPodaj liczbe atakow biedronki: ";
	cin >> b;

	// nie gromadzimy miejsc ataków do tablicy, każdy atak rozważamy oddzielnie
	for (int i = 0; i < b; ++i)
	{
		// pobieramy miejsce ataku biedronki. 
		cout << "\nPodaj miejsce ataku biedronki: ";
		cin >> e;

		// jeżeli tam gdzie zaatakowała biedronka zjadowała się mrówka, to pozycja żadnej z mrówek się nie zmieni, 
		// zwięszamy tylko licznik m[g[e]];
		if (g[e] != -1)
		{
			++m[g[e]];
			/* WYPISYWANIE REZULTATOW */
			cout << setw(5) << "Lp.  PK   W\n";
			for (int j = 1; j <= l_m; ++j)
			{
				cout << j << setw(5) << M[j] << setw(5) << m[j] << "\n";
			} 
		}

		else
		{
			// puszczamy bfs'a 
			// kolejka i iteratory do niej
			int * q = new int[l_w], first, add = 1, current;
			q[first = 0] = (prev[e] = e);
			t[e] = 0;
			while (first <= add)
			{
				current = q[first++];
				for (auto j = G[current].begin(); j != G[current].end(); ++j)
				{
					if (t[*j] == -1)
					{
						q[add++] = *j;
						t[*j] = t[current] + 1;
						prev[*j] = current; 
					}
				}
			}
			delete[] q;

			// iterujemy się dla każdej mrówki 
			for (int j = 1; (j <= l_m); ++j)
			{
				if (!blocked[j])
				{
					// sprawdzamy ścieżkę j-tej mrówki; Jeżeli ścieżka jest pusta, to ruszamy mrówką
					v = prev[j];
					while (v != e)
					{
						if (g[v] != -1)
						{
							blocked[j] = 1;
							break;
						}
						v = prev[v];
					}

					if (!blocked[j])
					{
						// zwalniamy wierzchołek na którym jesteśmy (czy jest to konieczne? jeżeli inna mrówka chce wejść na ten
						// wierzchołek to znaczy że już jest zablokowana i nie może się ruszać. Więc na razie umieścmy tę linię w komentarzu)
						//g[j] = -1;

						M[j] = prev[j];
						g[prev[j]] = j;

						// jeżeli doszliśmy do miejsca gdzie jest biedronka to kończymy przesuwanie mrówek 
						if (M[j] == e)
						{
							++m[j]; 
							break;
						}
					}

				}
			}

			/* WYPISYWANIE REZULTATOW */
			cout << setw(5) << "Lp.  PK   W\n";
			for (int j = 1; j <= l_m; ++j)
			{
				cout << j << setw(5) << M[j] << setw(5) << m[j] << "\n";
			} 

			resetArray(1, l_w, -1, t);
			resetArray(1, l_w, -1, prev);
			resetArray(1, l_m, 0, blocked);
		}

	}

	delete[] G; delete[] m; delete[] M; delete[] g; delete[] prev; delete[] t; delete[] blocked;
}

void resetArray(int l, int u, int val, int T[])
{
	for (int i = l; i <= u; ++i)
		T[i] = val;
}

void printGraph(vector<int> * G, int size)
{
	for (int i = 1; i <= size; ++i)
	{
		cout << i << ": ";
		for (auto j = G[i].begin(); j != G[i].end(); ++j)
			cout << *j << " ";
		
		cout << "\n";
	}
}

void printArray(int T[], int size)
{
	for (int i = 1; i <= size; ++i)
		cout << T[i] << " ";
}
