/* K. Kafara */

#include <stdio.h>
#include <vector>
#include <queue>

// do reprezentowania nieskończoności 
const int MAX_INT_32 = 2147483647;

struct Graph
{
    struct Edge
    {
        int end;
        int len;

        Edge(int end_vertex = -1, int length = 0)
        : end(end_vertex), len(length)
        {}
    };

    struct Vertex : std::vector<Edge>   
    {
        bool visited;
        int distance;

        Vertex() 
        : visited(false), distance(MAX_INT_32)
        {}
    };
    
    int size;
    std::vector<Vertex> graph;

    Graph(int n)
    : graph(n), size(n)
    {}

    void addEdgeD(int b, int e, int l = 1)
    {
        graph[b].push_back(Edge(e, l));
    }
    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            printf("%d: ", i);
            for (std::vector<Edge>::iterator v = graph[i].begin(); v != graph[i].end(); ++v)
                printf("%d ", v->end);

            printf("\n");
        }
    }

    int dijkstra(int s, int t)
    {
        std::queue<int> q;

        q.push(s);
        graph[s].visited = true;
        graph[s].distance = 0;

        int curr_ver, dist; 
        while (!q.empty())
        {
            curr_ver = q.front();
            q.pop();

            graph[curr_ver].visited = true;

            for (std::vector<Edge>::iterator ed = graph[curr_ver].begin(); ed != graph[curr_ver].end(); ++ed)
            {
                if (graph[ed->end].visited == false)
                {
                    dist = graph[curr_ver].distance + ed->len;

                    if (dist < graph[ed->end].distance)
                        graph[ed->end].distance = dist;

                    q.push(ed->end);
                }
            }
        }
        return graph[t].distance;
    }
};

int main()
{
    int n, k, b, e, l, s, t;

    scanf("%d %d", &n, &k);
    scanf("%d %d", &s, &t);


    Graph g(n);

    for (int i = 0; i < k; ++i)
    {
        // printf("%d\n", i);
        scanf("%d %d %d", &b, &e, &l);
        g.addEdgeD(b, e, l);
    }

    printf("%d\n", g.dijkstra(s, t));

    return 0;
}
