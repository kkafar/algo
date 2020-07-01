#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;

 
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
