/* K. Kafara */

#include <stdio.h>
#include <vector>
#include <queue>

// dekstrukory będą domyślne
struct Graph
{
    struct Edge
    {
        int end;

        Edge(int e) : end(e) {}
    };

    struct Vertex : public std::vector<Edge>
    {
        int idx;
        int visited;

        Vertex()
        {
            idx = 0; 
            visited = 0;
        }
    };

    std::vector<Vertex> graph;
    
    int is_visited_key;

    // n = number of vertices
    Graph(int n = 0) : graph(n), is_visited_key(1) {}


    //////////////////////////////////////
    // add DIRECTED edge
    void AddEdgeD(int b, int e)
    {
        graph[b].push_back(Edge(e));
    }   

    void AddEdgeUD(int b, int e)
    {
        graph[b].push_back(Edge(e));
        graph[e].push_back(Edge(b));
    }

    void PrintGraph()
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            printf("%d    ", i);
            for (std::vector<Edge>::iterator j = graph[i].begin(); j != graph[i].end(); ++j)
            {
                printf("%-3d", j->end);
            }
            printf("\n");
        }
    }

    ////////////////////////////////////////////////////////////////////////////////

    bool solution(int b, int e)
    {
        if (b == e) return true;

        // algorytm całkowicie analogiczny do bfs'a
        std::queue<int> Q;

        int cv; // current vertex
        
        Q.push(b);

        while (!Q.empty())
        {
            // pobieramy wierzchołek  z kolejki 
            cv = Q.front();
            Q.pop();
            
            // i oznaczamy go jako odwiedzonego
            graph[cv].visited = is_visited_key;

            // przeglądamy wszystkich sąsiadów cv. Jeżeli któryś jest wierzchołkiem docelowym to zwracamy true. 
            // Wpp, o ile nie był wcześniej odwiedzony, dodajemy do kolejki wszystkich jego sąsiadów. 
            for (std::vector<Edge>::iterator i = graph[cv].begin(); i != graph[cv].end(); ++i)
            {
                if (i->end == e) return true;
                else
                {
                    if (graph[i->end].visited != is_visited_key)
                        Q.push(i->end);
                }
            }
        }

        // resetujemy przed ewntualnym kolejnym zapytaniem
        ++is_visited_key; 

        return false;
    }
};




int main()
{
    int n, k, p, b, e;

    scanf("%d %d %d", &n, &k, &p);

    Graph G(n);

    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &b, &e);
        G.AddEdgeUD(b, e);
    }

    for (int i = 0; i < p; ++i)
    {
        scanf("%d %d", &b, &e);
        if (G.solution(b, e) == true)
            printf("YES\n");

        else
            printf("NO\n");
    }
    
    //G.PrintGraph();
    return 0;
}
