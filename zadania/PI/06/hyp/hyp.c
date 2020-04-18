/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>

// #include "utility_c.h"

struct Node
{
    int key;
    struct Node * next;
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

struct Vector
{
    // wartownik
    struct Node * snt;
};

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

typedef struct Vector Vector;



int solution(Vector * vec, int n, int b, int e)
{
    if (b == e) return 1;
    // algorytm na bazie bfs'a

    // current vertex;
    int cv;

    // tablica odwiedzin
    int visited[n];
    for (int i = 0; i < n; ++i)
        *(visited + i) = 0;

    // PrintTabInt(visited, n);
    
    

    // kolejka i zmienne do obsługi
    // wirzchołków jest n, więc większa kolejka nie jest potrzebna
    int queue[n + 1];
    int p = 0, k = 0;

    queue[k] = b;
    visited[b] = 1;

    while (p <= k)
    {
        // pobieramy wierzchołek z kolejki 
        cv = queue[p++];
        //printf("Visiting: %d\n", cv);
        if (cv == e) return 1;


        // przeglądamy sąsiadów cv,  jezeli nie byli odwiedzeni to dodajemy ich do kolejki, bądź zwracamy true (1), jeżeli 
        // szukanym wierzchołkiem jest jeden z sąsiadów
        for (struct Node * tmp = vec[cv].snt->next; tmp != NULL; tmp = tmp->next)
        {
            // if (tmp->key == e) return 1;
            if (visited[tmp->key] == 0)
            {
                queue[++k] = tmp->key;
                visited[tmp->key] = 1;
            }
        }
    }

    // jeżeli wcześniej nie zwróciliśmy 1, to znaczy że połączenia nie ma ==> zwracamy 0
    return 0;

}


int main(void)
{
    int n, k, p, b, e;

    scanf("%d %d %d", &n, &k, &p);

    Vector graph[n];
    for (int i = 0; i < n; ++i)
        initVector(graph + i);

    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &b, &e);
        // dodajemy podwójną krawędź, bo graf jest nieskierowany (jeżeli potraktujemy go jako graf skierowany,
        // to przykład wtedy nie ma sensu)
        addNode(graph + b, e);
        addNode(graph + e, b);
    }
/*  
    for (int i = 0; i < n; ++i)
    {
        printf("%d    ", i);
        printVector(graph + i);
    }
*/
    for (int i = 0; i < p; ++i)
    {
        scanf("%d %d", &b, &e);
        if (solution(graph, n, b, e) == 1)
            printf("YES\n");
        
        else 
            printf("NO\n");
    }
/*  
    for (int i = 0; i < n; ++i)
    {
        printf("%d    ", i);
        printVector(graph + i);
    }
*/
    for (int i = 0; i < n; ++i)
        delVector(graph + i);
    
    
    return 0;
}
