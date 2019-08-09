#include <iostream>
#include <vector>
using namespace std;

void resetArray(int l, int u, int val, int T[]);

int main()
{
	int l_w, b, e;

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
	cin >> b;

	// tworzymy tablicę z pozycjami mrówek --> w M[i] mamy aktualną pozycję mrówki i (indeks 
	// wierzchołka na którym się aktualnie znajduje). (b + 1) bo numerujemy od 1
	int * M = new int[b + 1];
	// w m[i] mamy ile razy mrówka i przepędziła biedronkę
	int * m = new int[b + 1];

	for (int i = 1; i <= b; ++i)
	{
		// przy okazji zerujemy m[]
		m[i] = 0; 
		// pobieramy pozycje mrówki i 
		cin >> M[i];

		g[M[i]] = i;
	}

	// liczba ataków biedronki
	cin >> b;

	// nie gromadzimy miejsc ataków do tablicy, każdy atak rozważamy oddzielnie
	for (int i = 0; i < b; ++i)
	{
		// pobieramy miejsce ataku biedronki. 
		cin >> e;

		// jeżeli tam gdzie zaatakowała biedronka zjadowała się mrówka, to pozycja żadnej z mrówek się nie zmieni, 
		// zwięszamy tylko licznik m[g[e]];
		if (g[e] != -1)
			++m[g[e]];

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
		}
		resetArray(1, l_w, -1, t);
		resetArray(1, l_w, -1, prev);
	}

	delete[] G; delete[] m; delete[] M; delete[] g; delete[] prev; delete[] t; 
}

void resetArray(int l, int u, int val, int T[])
{
	for (int i = l; i <= u; ++i)
		T[i] = val;
}
