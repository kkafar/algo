/* K. Kafara */

#include <stdio.h>
#include <vector>
#include <queue>

/**
 * Rozwiązaniem tego zadania jest zwykly algorytm sortowania topologicznego. Jeżeli nie uda się posortować --> w grafie mamy cykl. 
 */

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
        // int visited;
        // stopień wchodzący danego wierzchołka
        int deg_in;
        // jezeli wierzcholek zostal usuniety, to deg_in == -1


        Vertex() : idx(-1), deg_in(0) {}
        
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
        graph[e].deg_in++;
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
            printf("\tdeg_in:%d\n", graph[i].deg_in);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////

    bool solution(int * installation_queue)
    {
        // czy jakis wierzcholek byl usuniety w danej iteracji
        bool del;
        // liczba usunietych wierzcholkow
        int numb = 0;

        do
        {
            // ustawiamy że w tej iteracji usuwania wierzcholka jeszcze nie było
            del = false;
            // przeglądamy wszystkie wierzcholki 

            for (int i = 0; i < size; ++i)
            {
                // jeżeli patrzymy na wierzcholek o stopniu != 0 to go pomijamy
                if (graph[i].deg_in > 0) continue;
                else
                {
                    // czyli mamy wierzcholek o stopniu wejściowym zero, musimy jeszcze sprawdzic czy aby nie jest juz usuniety
                    if (graph[i].deg_in == -1) continue;
                    else
                    {
                        // w przeciwnym wypadku usuwamy wierzcholek
                        del = true;
                        // zmiejszamy stopnie wchodzące wszystkich jego sasiadow
                        for (std::vector<Edge>::iterator j = graph[i].begin(); j != graph[i].end(); ++j)
                            --graph[j->end].deg_in;

                        // oznaczamy sam wierzcholek jako usuniety
                        graph[i].deg_in = -1;
                        // wpisujemy go do ewentualnej tablicy wyjściowej i zwiekszamy licznik usunietych wierzcholkow
                        installation_queue[numb++] = i;
                    }
                    
                }
                
            }
        } while (del);

        // jeżeli liczba usunietych wierzcholkow z grafu jest < size ==> w grafie mamy cykl ==> zwracamy false
        // wpp oczywiscie zwracamy true
        if (numb < size)    return false;
        else                return true;
    }
};



int main()
{
    int n, k, b, e;

    scanf("%d %d", &n, &k);

    Graph G(n);
    int installation_queue[n];
    for (int i = 0; i < n; ++i) { installation_queue[i] = 0; }
    
    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &b, &e);
        G.AddEdgeD(b, e);
    }

    if (G.solution(installation_queue) == true)
    {
        printf("OK\n");
        for (int i = 0; i < n; ++i)
            printf("%d ", installation_queue[i]);
        printf("\n");
    }
    else
    {
        printf("CYCLE\n");
    }
    
    // G.PrintGraph();
    
    
    return 0;
}
