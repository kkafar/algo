/* K. Kafara */

#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>

// dekstrukory będą domyślne
struct Graph
{
    struct Edge
    {
        int end;
        bool used;
        // indeks pod którym znajduje się krawędź przeciwna w wektorze wierzchołka końcowego krawędzi
        int rev;

        Edge(int e) : end(e), used(false) {}
    };

    struct Vertex : public std::vector<Edge>
    {
        int idx;
        // int visited;
        // stopień wierzchołka
        int deg;

        Vertex() : idx(-1), deg(0) {}
    };

    std::vector<Vertex> graph;
    int size;
    // int is_visited_key;

    // n = liczba wierzcholkow
    Graph(int n = 0) : graph(n), size(n) {}

    //////////////////////////////////////
    // add DIRECTED edge
    void AddEdgeD(int b, int e)
    {
        graph[b].push_back(Edge(e));
        // zwiększamy stopien wchodzacy wierzcholka e;
    }   

    void AddEdgeUD(int b, int e)
    {
        Edge eg = Edge(e);

        eg.rev = graph[e].size();
        graph[b].push_back(eg);

        eg.rev = graph[b].size() - 1;
        eg.end = b;
        graph[e].push_back(eg);

        graph[b].deg++;
        graph[e].deg++;
    }



    void dfs(const int cv, int * stack, int * iter)
    {
        //printf("wywolany na %d\n", cv);
        for (std::vector<Edge>::iterator v = graph[cv].begin(); v != graph[cv].end(); ++v)
        {
            if (v->used == false)
            {
                v->used = true;
                graph[v->end][v->rev].used = true;
                dfs(v->end, stack, iter);
            }
        }
        ++(*iter);
        stack[*iter] = cv;



    }
/*     void EulerCycle(int * stack, int & iter)
    {
        
    }
 */
    void PrintGraph()
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            printf("%d    ", i);
            for (std::vector<Edge>::iterator j = graph[i].begin(); j != graph[i].end(); ++j)
            {
                printf("(%d, %d)", j->end, j->rev);
            }
            printf("\tdeg_in:%d\n", graph[i].deg);
        }
    }

    ///////////////////////////////////////////////////////////////////////////////


/*     void solution()
    {
        
    } */


    
};

// zwraca 2 jeżeli graf jest eulerowski albo  1 - półeulerowski albo 0 - wpp
int IsEuler(Graph * g)
{
    int count = 0;
    for (std::vector<Graph::Vertex>::iterator v = g->graph.begin() + 1; v != g->graph.end(); ++v)
    {
        if (v->deg % 2 != 0)
        {
            ++count;
        }
        if (count > 2) break;
    }
    if (count == 0 || count == 2) return 1;

    if (count > 2)
    {
        Graph::Edge edge(0);
        for (int v = 1; v < g->graph.size(); ++v)
        {
            if (g->graph[v].deg % 2 != 0)
            {
                edge.end = 0;
                edge.rev = g->graph[0].size();
                g->graph[v].push_back(edge);

                edge.end = v;
                edge.rev = g->graph[v].size() - 1;
                g->graph[0].push_back(edge);
                
            }
        }
    }
    return 0;
}

int main()
{
    int z, n, m, b, e, iter, count, l, res, wyw;

    scanf("%d", &z);
    
    for (int y = 0; y < z; ++y)
    {
        scanf("%d %d", &n, &m);

        Graph graph(n + 1);
        // int path[m + 1];
        // 2n żeby przypadkiem nie brakło (:D)
        int stack[2*n];
        stack[0] = 0;
        iter = -1;

        for (int u = 0; u < m; ++u)
        {
            scanf("%d %d", &b, &e);

            graph.AddEdgeUD(b, e);
        }

        // graph.PrintGraph();

        res = IsEuler(&graph);
        if (res == 1) wyw = 1;
        else wyw = 0;
        graph.dfs(wyw, stack, &iter);
        std::stack<int> s;

        for (int i = 0; i < n; ++i)
            printf("%d ", stack[i]);

        printf("\n");
        for (int i = 0; i <= iter; ++i)
        {
            if (stack[i] == 0 || i == iter)
            {
                wyw = s.size();
                printf("ROZMIAR%d ", wyw);
                
                while (!s.empty())
                {
                    printf("%d ", s.top());
                    s.pop();
                }
            }
            else
            {
                s.push(stack[i]);
            }
            
        }

        printf("\n");
    }
    
    return 0;
}
