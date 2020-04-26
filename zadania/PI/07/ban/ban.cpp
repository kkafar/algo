/* K. Kafara */

#include <stdio.h>
#include <vector>
#include <queue>

// do reprezentowania nieskończoności 
const int MAX_INT_32 = 2147483647;
const int MIN_INT_32 = -2147483648;

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

    void addEdgeU(int b, int e, int l = 1)
    {
        graph[b].push_back(Edge(e, l));
        graph[e].push_back(Edge(b, l));
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

    void reset()
    {
        for (std::vector<Vertex>::iterator v = graph.begin(); v != graph.end(); ++v)
        {
            v->visited = false;
            v->distance = MAX_INT_32;
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


    /**
     * Puszczamy dijkstrę z s do t (s - bank z którego chcemy się przenieść, t - bank docelowy)
     * Jeżeli dijkstra zwróci MAX_INT_32 to znaczy że połączenia pomiędzy bankami nie ma
     * Jeżeli zwróci wartość < MAX_INT_32 to mamy wyznaczony minimalny koszt przenosin w jedną stronę, ale jeszcze musimy sprawdzić, 
     * czy nie istnieje ujemny cykl. 
     * Aby to zrobić, puszczamy dijkstrę z t do s, i sprawdzamy czy suma kosztów w obie strony jest mniejsza od 0, jeżeli tak, to wypisujemy "CYCLE", 
     * jeżeli nie to wypisujemy minimalny koszt wyznaczony podczas pierwszego przebiegu dijkstry. 
     */
    void bankster(int s, int t)
    {
        int min_cost1, min_cost2;

        min_cost1 = dijkstra(s, t);

        if (min_cost1 == MAX_INT_32)
            printf("NO\n");

        else
        {
            reset();

            min_cost2 = dijkstra(t, s);

            if (min_cost2 == MAX_INT_32 || min_cost1 + min_cost2 >= 0)
                printf("%d\n", min_cost1);
            
            else if (min_cost1 + min_cost2 < 0)
                printf("CYCLE\n");
        }        
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
        scanf("%d %d %d", &b, &e, &l);
        g.addEdgeD(b, e, l);
    }
    // g.print();
    g.bankster(s, t);

    return 0;
}
