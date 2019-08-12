#include <iostream>
#include <vector>
using namespace std;

/* REPREZENTACJA GRAFU */
/// =================================
template<class V, class E> struct Graph
{
	struct Edge : public E
	{
		int end;
		Edge(int e, E data) : end(e), E(data) {}
	};

	struct Vertex : public V, public vector<Edge> {};

	vector<Vertex> g;

	Graph(int n_vertices = 0) : g(n_vertices + 1) {}

	void addEdge(int b, int e, E data = E())
	{
		g[b].push_back(Edge(e, data));
	}

	void write()
	{
		for (int i = 1; i < g.size(); ++i)
		{
			cout << i << ": ";
			for (auto j = g[i].begin(); j != g[i].end(); ++j)
				cout << j->end << " ";
			cout << "\n";
			
		}
	}
}; 
/// =================================

/* 
	Z każdym wierzchołkiem skojarzamy: 
	1. ID mrówki, która się na nim znajduje. Jeżeli na wierchołku nie ma mrówki, to 
		przypisujemy w to pole wartość -1;
	2. Poprzednika w lesie wyszukiwania BFS. Jeżeli nie został dla danego wierzchołka wyznaczowny jeszcze
		poprzednik to przypisujemy w to pole wartość -1

*/
struct Ve
{
	int ant_id, previous_v;

	Ve() : ant_id(-1), previous_v(-1)
	{}
};

struct Ed
{
	// żadnych danych nie skojarzamy z krawędziami grafu
};

int main()
{
	/* 
		
	*/
	int n_vertices, begin_v, end_v;

	cin >> n_vertices;

	Graph<Ve, Ed> G(n_vertices);

	for (int i = 0; i < n_vertices - 1; ++i)
	{
		cin >> begin_v >> end_v;
		G.addEdge(begin_v, end_v);
	}
	return 0;
}
