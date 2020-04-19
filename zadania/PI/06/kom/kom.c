/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node * next;
};
struct Node * newNode();
void initNode(struct Node * node, int k, struct Node * nxt);
/**
 * @brief Lista odsyłaczowa na typ zdefiniowany w strukturze Node. (Aktulanie: int)
 * Dostepne metody: 
 * @see initVector(…)
 * @see addNode(…)
 * @see delVector(…)
 * @typedef Vector
  */
struct Vector
{
    // wartownik
    struct Node * snt;
};
struct Node * newNode()
{
    return ((struct Node *) malloc(sizeof(struct Node)));
}
void initNode(struct Node * node, int k, struct Node * nxt)
{
    node->next = nxt;
    node->key = k;
}
void initVector(struct Vector * vec)
{
    vec->snt = newNode();
    initNode(vec->snt, 0, NULL);
}
void addNode(struct Vector * vec, int k)
{
    struct Node * new = newNode();
    initNode(new, k, vec->snt->next);
    vec->snt->next = new;
}
void printVector(struct Vector * vec)
{
    struct Node * node = vec->snt->next;
    while (node != NULL)
    {
        printf("%3d", node->key);
        node = node->next;
    }
    printf("\n");
}
void delVector(struct Vector * vec)
{
    if (vec->snt == NULL)
        return;

    // ten else if raczej niepotrzebny, else obejmuje ten przypadek
    else if (vec->snt->next == NULL)
    {
        free(vec->snt);
        //free(vec);
    }

    else 
    {
        struct Node * tmp;
        while (vec->snt != NULL)
        {
            tmp = vec->snt;
            vec->snt = vec->snt->next;
            free(tmp);
        }
    }
}


int dfs(struct Vector * graph, int * parent, int * colors, int cv)
{
    // printf("DFS wywolany na %d\n", cv);
    colors[cv] = 1;

    // przeglądamy sąsiadów cv
    for (struct Node * node = graph[cv].snt->next; node != NULL; node = node->next)
    {
        // printf("Przegladam sasiadow %d: %d\n", cv, node->key);
        // jeżeli sąsiad ma status "przetwarzany" i jest różny od tego z którego przyszliśmy, to stwierdzamy istnienie cyklu i zwracamy 0
        if (colors[node->key] == 1) return 0;
        // jeżeli sąsiad jest jeszcze nie odwiedzony to wywołujemy sie na nim rekurencyjnie
        else if (colors[node->key] == 0)
        {
            parent[node->key] = cv;
            if(dfs(graph, parent, colors, node->key) == 0) return 0;
        }
        // patrzę na wierzchołek, który jest już odwiedzony ==> nie ma cyklu, ale trzeba uzupełnić listę zależnośći
        else
        {
            parent[node->key] = cv;
        }
        
    }
    // wierzchołek został przetworzony, więc taki status mu nadajemy i zwracamy 1, ponieważ nie udało się znaleźć cyklu
    colors[cv] = 2;
    return 1;
}

// sprawdzamy czy zadany graf posiada cykl
int solutionDfs(struct Vector * graph, int n, int * parent)
{
    // będziemy korzystać z nieco zmodyfikowanego algorytmu dfs
    // Korzystamy z trzech kolorów. Wierzchołki nieodwiedzone są np. białe, przetwarzane czarne, a te które zostały
    // już przetworzone otrzymują kolor czarny. W grafie skierowanym możemy stwierdzić istnienie cyklu wtedy gdy podczas
    // przechodzenia grafu algorytmem DFS sąsiadem przetwarzanego wierzchołka okaże się wierzchołek szary. 
    // tablica kolorów
    // 0 - nieodwiedzony
    // 1 - przetwarzany
    // 2 - odwiedzony
    int colors[n];
    for (int i = 0; i < n; ++i) { colors[i] = 0; parent[i] = -1; }

    // int ret;

    for (int i = 0; i < n; ++i)
    {
        if (colors[i] == 0)
        {
            // ret = dfs(graph, n, parent, colors, i);
            if (dfs(graph, parent, colors, i) == 0) return 0;
        }
    }
    return 1;
}

void getPath(int * parent, int n)
{
    int stack[n], installed[n], s = -1;
    int cv;
    for (int i = 0; i < n; ++i) { installed[i] = 0; }

    for (int i = 0; i < n; ++i)
    {
        if (installed[i] == 0)
        {
            cv = i;
            while (cv != -1 && installed[cv] == 0)
            {
                installed[cv] = 1;
                stack[++s] = cv;
                cv = parent[cv];
            }
            for (; s >= 0; --s)
                printf("%d ", stack[s]);
        }
    }
    printf("\n");

}



int main(void)
{
    int n, k, b, e;

    scanf("%d %d", &n, &k);


    // tablica rodzicow
    int parent[n];


    struct Vector graph[n];
    for (int i = 0; i < n; ++i)
        initVector(graph + i);

    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &b, &e);
        addNode(graph + b, e);
    }

/*     for (int i = 0; i < n; ++i)
    {
        printf("%d  ", i);
        printVector(graph + i);
    }     */

    if (solutionDfs(graph, n, parent) == 1)
    {
        printf("OK\n");
        /* for (int i = 0; i < n; ++i)
            printf("%d ", parent[i]);
        printf("\n");  */
        getPath(parent, n);
    }
    else
        printf("CYCLE\n");

    for (int i = 0; i < n; ++i)
        delVector(graph + i);
    return 0;
}
