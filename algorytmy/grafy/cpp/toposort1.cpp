/* SORTOWANIE TOPOLOGICZNIE ACYKLICZNEGO GRAFU SKIEROWANEGO ( DAG ) */
/* 
	Wersja 1
	Opieramy się na algorytmie DFS. Przeglądając graf odkładamy przetworzone wierzchołki na stos.
	W ten sposób, na szczycie stosu znajduje się pierwszy odiwedzony wierzchołek (wierzchołek startowy algorytmu)
	a na samym spodzie ostatni odwiedzony wierzchołek. 
	Korzystamy także z istotnego faktu: 
	Mamy graf G = (V, E) = ( V, (b, e) ); Zauważmy że jeżeli w grafie isnieje krawedź (b1, e1), to wierzchołek e1 
	znajdzie się niżej na stosie od wierzchołka b1. Z acykliczności grafu wynika także że nie istnieje krawędź prowadząca
	z e1 do b1. Zatem algorytm jest poprawny. 
*/ 


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define forall(i, g) for (vector<Edge>::iterator i = g.begin(); i != g.end(); ++i)
#define foreach(i, a, b) for (int i = a; i <= b; ++i)

struct Graph
{
	struct Edge
	{
		int e;
		Edge(int end) : e(end) {}
	};

	struct Vertex : public vector<Edge>
	{
		bool visited;
		Vertex() : visited(false) {}
	};

	vector<Vertex> g;

	Graph(int n = 0) : g(n) {}

	void addED(int b, int e)
	{
		g[b].push_back(Edge(e));
	}

	void p()
	{
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
	void topo_dfs(int s_v, stack<int> * S)
	{
		// przerabiany wierzchołek oznaczamy jako odwiedzony
		g[s_v].visited = true;
		// odwiedzamy rekurencyjnie wszystkich jego nieodwiedzonych sąsiadów
		forall(i, g[s_v])
		{
			if (g[i->e].visited == false)
			{
				topo_dfs(i->e, S);
			}
		}
		// po zakończeniu przerabiania danego wierzchołka wrzucamy go na stos
		S->push(s_v);

	}
	/* FUNKCJA REALIZUJĄCA SORTOWANIE TOPOLOGICZNE */
	/// =========================================== 
	void topo_sort()
	{
		stack<int> S;

		// odwiedzamy wszystkie wierzchołki algorytmem DFS
		foreach(i, 0, g.size() - 1)
		{
			if (g[i].visited == false)
			{
				topo_dfs(i, &S);
			}
		}

		// w tym miejscu w stosie powinniśmy mieć już wierzchołki (idąc od góry) w kolejności topologicznej
		// pozostaje jedynie je wyświetlić
		cout << "\nPorzadek topologiczny:\n";
		while (!S.empty())
		{
			cout << S.top() << " ";
			S.pop();
		}
		cout << "\n";
	}
	/// ===========================================
};


int main()
{
	int e, b;
	Graph G(6);

	foreach(i, 0, 4)
	{
		cin >> b >> e;
		G.addED(b, e);
	}

	G.p();

	G.topo_sort();
	return 0;
}
