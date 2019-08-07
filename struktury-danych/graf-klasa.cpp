#include <iostream>
#include <vector>
using namespace std;

template<class V, class E> struct Graph
{
	struct Edge : public E
	{
		int end;
		Edge(int end, E data) : end(end), E(data) {}
	};

	struct Vertex : public V, public vector<Edge>
	{
		
	};

	vector<Vertex> g;

	Graph(int n = 0) : g(n) {}

	void addEdgeD(int begin, int end, E data = E()) 
	{
		g[begin].push_back(Edge(end, data));
	}
};

struct Empty {};

int main()
{

	Graph<Empty, Empty> G(3);


	G.addEdgeD(0, 1);
	G.addEdgeD(1, 2);
	G.addEdgeD(2, 0);
	return 0; 
}
