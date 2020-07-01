/* 
	Algorytm przeszukiwania grafu w głąb - DFS
	Dla reprezentacji grafu poprzez odrębną klasę.
*/


#include <iostream>
#include <vector>

using namespace std;

template<class V, class E> struct Graph
{
	/* 
	   Ta część już jest pozbawiona komentarza, jeżeli potrzebny: 
	   https://github.com/kkafar/my-projects/blob/master/struktury-danych/graf-klasa.cpp
	*/
	struct Edge : public E
	{
		int end; 
		Edge(int e, E data) : end(e), E(data) {}
	};

	struct Vertex : public V, public vector<Edge> {};

	vector<Vertex> g;

	Graph(int n_vertices = 0) : g(n_vertices) {}

	void addEdge(int v_begin, int v_end, E data = E())
	{
		g[v_begin].push_back(Edge(v_end, data));
	}


	void writeGraph()
	{
		for (int i = 0; i < g.size(); ++i)
		{
			cout << i << ": ";

			for (auto j = g[i].begin(); j != g[i].end(); ++j)
			{
				cout << j->end << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}


	void DFS(int starting_point)
	{
		// zmienna do trzymania czasu odwiedzania
		static int t = 0; 

		// przetwarzamy wierzchołek na którym się wywołaliśmy 
		g[starting_point].time_in = t++;

		// dla wszystkich nieodwiedzonych sąsiadów naszego wierzchołka
		for (auto i = g[starting_point].begin(); i != g[starting_point].end(); ++i)
		{
			// sprawdzamy czy przeglądany sąsiad był już odwiedzony, jeśli nie:
			if (g[i->end].time_in == -1)
			{
				// ustawiamy pole prev na wierchołek z którego przyszliśmy (starting_point)
				g[i->end].prev = starting_point;
				// wywołujemy się rekurencyjnie na sąsiedzie 
				DFS(i->end);
			}
		}
		// jeżeli wyszliśmy z pętli, to znaczy że wszyscy nasi sąsiedzi zostali już przejrzeni
		// i wychodzimy z naszego wierzchołka
		g[starting_point].time_out = t++; 
	}


	void printPath()
	{
		for (int i = 0; i < g.size(); ++i)
			cout << g[i].prev << " ";
		cout << "\n";
	}

};

struct Ve 
{
	int time_in, time_out, prev;
	Ve() : time_in(-1), time_out(-1), prev(-1) {}
};
struct Ed {};


int main()
{
	int n_vertices, b, e;

	cin >> n_vertices;

	Graph<Ve, Ed> G(n_vertices);
	
	for (int i = 0; i < n_vertices; ++i)
	{
		cin >> b >> e;
		G.addEdge(b, e);
		G.writeGraph();
	}



	cout << "final V\n";
	G.writeGraph();

	G.DFS(0);
	G.printPath();



	return 0;
}
