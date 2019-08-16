#include <iostream>
using namespace std;

struct Graph
{
	int val; 
	Graph * neigh; 

	Graph() : val{-1}, neigh(NULL) {}
};

void printG(Graph ** G, int n_vertices);
void printPath(int s_v, int dfs_prev[]);

void DFS(Graph ** G, int c_v, int * dfs_prev, int * time_in, int * time_out)
{
	static int t = 0; 

	time_in[c_v] = t++;

	for (auto i = G[c_v]; i; i = i->neigh)
	{
		if (time_in[i->val] == -1)
		{
			dfs_prev[i->val] = c_v;
			DFS(G, i->val, dfs_prev, time_in, time_out);
		}
	}
	time_out[c_v] = t++;
}

int main()
{
	int n_vertices, n_edges, s_v, e_v;
	Graph * p = NULL;

	cin >> n_vertices >> n_edges;

	Graph ** G = new Graph * [n_vertices];
	int * dfs_prev = new int[n_vertices];
	int * time_in = new int[n_vertices], * time_out = new int[n_vertices];

	for (int i = 0; i < n_vertices; ++i)
	{
		G[i] = NULL;
		time_in[i] = time_out[i] = dfs_prev[i] = -1;
	}
	
	for (int i = 0; i < n_edges; ++i)
	{
		cin >> s_v >> e_v;
		p = new Graph; 
		p->val = e_v;
		p->neigh = G[s_v];
		G[s_v] = p; 
	}

	printG(G, n_vertices);

	DFS(G, 0, dfs_prev, time_in, time_out);

	for (int i = 0; i < n_vertices; ++i)
		printPath(i, dfs_prev);

	delete[] dfs_prev; delete[] time_out; delete[] time_in;
	for (int i = 0; i < n_vertices; ++i)
		delete[] G[i];
	delete[] G;

	return 0;
}


void printG(Graph ** G, int n_vertices)
{
	cout << "\n";
	for (int i = 0; i < n_vertices; ++i)
	{
		cout << i << ": ";
		for (auto j = G[i]; j; j = j->neigh)
		{
			cout << j->val << " ";
		}
		cout << "\n";
	}
}

void printPath(int s_v, int dfs_prev[])
{
	if (dfs_prev[s_v] == -1)
		cout << s_v << ": brak sciezki\n";

	else
	{	
		int v = s_v;
		// korzystamy z struct Graph jak z listy jednokierunkowej (którą de facto jest)
		Graph * stack = NULL;
		Graph * p = NULL;
		while (s_v != -1)
		{
			p = new Graph; 
			p -> val = s_v; 
			p -> neigh = stack; 
			stack = p; 
			s_v = dfs_prev[s_v];
		}
		cout << "\nSciezki:\n" << v << ": ";
		for (auto i = stack; i; i = i->neigh)
			cout << i->val << " ";
		cout << "\n";

	}
}
