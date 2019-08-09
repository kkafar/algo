/* 
	BFS dla grafu reprezentowanego poprzez listę sąsiedztwa. ( a właściwie to chodzi o tą całą,
	specyficzną klasę. )

	BFD ma wyznaczać: 
	1. Czas dojścia (długość drogi) do danego wierzchołka od wierzchołka początkowego algorytmu. 
	2. Wierzchołek 'rodzicielski' (ten z którego przyszliśmy) danego wierzchołka. 
	Takie więc pola dodajemy do danych skojarzonych z wierzchołkiem. 

*/ 


#include <iostream>
#include <vector>
using namespace std;

#define ITER(i, x) for(int i = 0; i < (x); ++i)

// tego już nie obłkadamy komentarzem, cały opis dostępny na githubie: 
// https://github.com/kkafar/my-projects/blob/master/struktury-danych/graf-klasa.cpp
template<typename V, typename E> struct Graph
{
	struct Edge : public E
	{
		int e; 
		Edge(int end, E data) : e(end), E(data) {}		
	};

	struct Vertex : public V, public vector<Edge> {};

	vector<Vertex> g;

	Graph(int n = 0) : g(n) {}

	void addEdge(int begin, int end, E data = E())
	{ 
		g[begin].push_back(Edge(end, data));
	}


	/* ALGORYTM BFS */
	// ================================
	// s_v (starting vertex) - bierzemy wierzchołek początkowy algorytmu, względem którego określamy
	// czasy, i drogi. 
	void BFS(int s_v)
	{
		// kolejkę reprezentujemy jako zwykłą tablicę z 2 iteratorami: 
		// i - śledzi miejsce do którego wstawiamy nowy element
		// j - śledzi pierwszy element w kolejce;
		int * q = new int[g.size()];
		int i = 0, j = 0; 

		// czy wierzchołek jet odwiedzony czy nie, rozpoznajemy po wartości danych z nim skojarzonych
		// jeżeli ciągle mają wartości (-1) to oczywiście oznacza że wierzchołek jeszcze nie był odwiedzony

		// dodajemy do kolejki pierwszy wierzchołek i od razu przesuwamy iterator i o 1. 
		q[i++] = s_v; 

		// ustawiamy dane wierzchołka startowego 
		g[s_v].time = 0; 
		g[s_v].prev = s_v;

		// dopóki jakiś element jest w kolejce <==> wskaźnik na pierwszy element nie wychodzi dalej niż wskaźnik na miejsce na kolejny
		// (na pewno powino być tak, a nie przypadkiem j < i)? 
		while (j <= i)
		{
			// pobieramy pierwszy wierchołek z kolejki i od razu przesuwamy iterator j na kolejny element
			// zmienna s_v wykorzystujemy teraz jako nr bieżącego wierzchołka
			s_v = q[j++];

			// iterujemy się dla wszysktich sąsiadów aktualnie rozważanego wierzchołka
			// jeżeli jakiś nie był jeszcze odwiedzony, wstawiamy go do kolejki oraz od razu zapisujemy z jakiego wierzchołka do niego przyszliśmy
			for (auto iter = g[s_v].begin(); iter != g[s_v].end(); ++iter)
			{
				// iter wskasuje na element klasy Edge, pamiętajmy
				if (g[iter->e].time == -1) 
				{
					q[i++] = iter->e;
					// ustawiamy wierzchołek poprzedni, oraz czas dojścia
					g[iter->e].prev = s_v;
					g[iter->e].time = g[s_v].time + 1;

					/*
					    Można to zapisać w bardziej skondensowanej formie: 
						g[q[i++] = iter->e].prev = s_v;
						g[iter->e].time = g[s_v].time + 1;
					*/ 

				}
			}
		}



		// zwalniamy pamięć zarezerwowaną na kolejkę
		delete[] q; 
	}
	// ================================

	void write() const 
	{
		for (int i = 0; i < g.size(); ++i)
		{
			cout << i << ": ";
			for (auto j = g[i].begin(); j != g[i].end(); ++j)
				cout << j->e << " "; 
			cout << "\n";
		}
		cout << "\n";
		for (int i = 0; i < g.size(); ++i)
		{
			cout << "Wierzcholek " << i << ": czas: " << g[i].time << "  ojciec: " << g[i].prev << "\n";
		}
	}
};

struct V 
{

	int time, prev;
	// inicjujemy -1, oznaczamy w ten sposób wierzchołek w którym jeszcze nie byliśmy
	V() { time = -1; prev = -1; } 
};

struct E {};


int main()
{
	int l_w, l_k, b, e; 

	cin >> l_w >> l_k;

	Graph<V, E> G(l_w);

	ITER(i, l_k)
	{
		cin >> b >> e; 
		G.addEdge(b, e);
	}

	cin >> b;
	
	G.BFS(b);

	G.write();

	return 0;
}
