#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

#define forall(i, a) for (vector<E>::iterator i = a.begin(); i != a.end(); ++i)
#define foreach(i, a, b) for (int i = a; i <= b; ++i)

struct Graph
{
	struct E
	{
		int e; 
		E(int end) : e{end} {}
	};

	struct V : public vector<E>
	{
		bool visited;
		V() :  visited(false) {}
	};

	vector<V> g;

	Graph(int n_vertices = 0) : g(n_vertices) {}

	void addED(int begin, int end)
	{
		g[begin].push_back(E(end));
	}

	void printGraph()
	{
		cout << "\nLISTA SASIEDZTWA:\n";
		foreach(i, 0, g.size() - 1)
		{
			cout << i << ": ";
			forall(j, g[i])
			{
				cout << j->e << " ";
			}
			cout << "\n";
		}
	}


	/* ALGORYTM KORSARAJU (?) */
	// wyznaczanie silnie spójnych składowych w grafie
	// O(n + m)
	// opis działania algorytmu: https://eduinf.waw.pl/inf/alg/001_search/0129a.php
	// lub: https://github.com/kkafar/materialy/blob/master/informatyka/algorytmika_praktyczna.pdf str. 29
	/// ===============================
	void DFS1(int s_v, stack<int> * s)
	{
		// oznaczamy przetwarzany wierzchołek jako odwiedzony
		g[s_v].visited = true;
		// wywołujemy się rerkurencyjnie na nieodwiedzonych do tej pory sąsiadach
		forall(i, g[s_v])
		{
			if (g[i->e].visited == false)
				DFS1(i->e, s);
		}
		// dodajemy przetworzony wierzchołek na stos
		s->push(s_v);
	}

	void DFS2(int s_v)
	{
		// oznaczamy przetwarzany wierzchołek jako odwiedzony
		g[s_v].visited = true;
		// wyświetlamy element spójnej składowej:
		cout << s_v << " ";
		// wywołujemy się rerkurencyjnie na nieodwiedzonych do tej pory sąsiadach
		forall(i, g[s_v])
		{
			if (g[i->e].visited == false)
				DFS2(i->e);
		}
	}
	void sccDFS()
	{
		stack<int> s;
		// licznik silnie spójnych skladowych
		int scc = 0, v;
		// dla wszystkich wierzchołków grafu
		foreach(i, 0, g.size() - 1)
		{
			// jeżeli jakiś jest nieodwiedzony to odpalamy na nim DFS
			if (g[i].visited == false)
				DFS1(i, &s);
		}

		// tworzymy graf transponowany
		Graph GT(g.size());
		foreach(i, 0, g.size() - 1)
		{
			forall(j, g[i])
				GT.addED(j->e, i);
		}

		// dopóki stos nie jest pusty
		// na samym szczycie powinien być wierzchołek startowy dfs'a, a na samym dole ostatni odwiedzony
		while(!s.empty())
		{
			v = s.top();
			s.pop();
			if (GT.g[v].visited == false)
			{
				++scc;
				cout << "\nSilnie spojna skladowa: " << scc << " : ";
				GT.DFS2(v);
			}
		}
	}
	/// ===============================



};

int main()	
{
	int e, b, n, m;

	cin >> n >> m;

	Graph G(n);

	foreach(i, 0, m - 1)
	{
		cin >> b >> e;
		G.addED(b, e);
	}

	G.printGraph();

	G.sccDFS();


	return 0;
}
