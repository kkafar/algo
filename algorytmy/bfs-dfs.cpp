#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
struct Pair
{
	int vertex, query_type;
};
 
void dfs(vector<int>G[], bool visited[], int current_vertex)
{
	visited[current_vertex] = true;
 
	cout << current_vertex << " ";
 
	for (vector<int>::iterator i = G[current_vertex].begin(); i != G[current_vertex].end(); ++i)
	{
		if (visited[*i] == false) dfs(G, visited, *i);
	}
}
 
void bfs(vector<int>G[], bool visited[], int current_vertex, queue<int> * vertices_to_process)
{
	(*vertices_to_process).push(current_vertex);
	visited[current_vertex] = true;
	while (!((*vertices_to_process).empty()))
	{
		current_vertex = (*vertices_to_process).front();
		(*vertices_to_process).pop();
 
		cout << current_vertex << " ";
 
		for (vector<int>::iterator i = G[current_vertex].begin(); i != G[current_vertex].end(); ++i)
		{
			if (visited[*i] == false)
			{
				(*vertices_to_process).push(*i);
				visited[*i] = true;
			}
		}
 
	}
 
}
 
void reset_visited_array(bool visited[], int numb_of_vertices)
{
	for (int i = 1; i <= numb_of_vertices; ++i)
		visited[i] = false;
}
 
int main()
{
	int numb_of_graphs, numb_of_vertices, numb_of_adj, current_vertex, adjacent_vertex;
	Pair query;
 
	ios_base::sync_with_stdio(false);
 
	cin >> numb_of_graphs;
 
	for (int i = 0; i < numb_of_graphs; ++i)
	{
		cin >> numb_of_vertices;
		vector<int> * graph = new vector<int>[numb_of_vertices + 1];
		bool * visited = new bool[numb_of_vertices + 1];
 
		for (int j = 1; j <= numb_of_vertices; ++j)
		{
			visited[j] = false;
			cin >> current_vertex >> numb_of_adj;
 
			if (numb_of_adj != 0)
			{
				for (int k = 0; k < numb_of_adj; ++k)
				{
					cin >> adjacent_vertex;
					graph[j].push_back(adjacent_vertex);
				}
			}
		}
 
		cout << "graph " << i + 1 << endl;
 
		while (true)
		{
			cin >> query.vertex >> query.query_type;
 
			if (query.vertex == 0 && query.query_type == 0)
				break;
 
			else if (query.query_type == 0)
			{
				dfs(graph, visited, query.vertex);
				cout << endl;
			}
 
			else
			{
				queue<int> vertices_to_process;
				bfs(graph, visited, query.vertex, &vertices_to_process);
				cout << endl;
			}
 
			reset_visited_array(visited, numb_of_vertices);
		}
 
		delete[] graph;
		delete[] visited;
	}
 
	return 0;
}
 
 
