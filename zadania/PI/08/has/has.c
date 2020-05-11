#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char * name;
    char * number;
    struct Node * next;
    struct Node * prev;
} Node;

typedef struct DoublyLinkedList
{
    Node * first; //* last;
} DLL;


Node * dll_new_node()
{
    return ((Node *) malloc(sizeof(Node)));
}

void dll_init(DLL * dll)
{
    dll->first = NULL;
    // dll->last = NULL;
}

void dll_push_front(DLL * dll, char * name, char * number)
{
    Node * new_node = dll_new_node();
    new_node->name = name;
    new_node->number = number;
    if (dll->first == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        dll->first = new_node;
        // dll->last = new_node;       
    }
/*     else if (dll->first == dll->last)
    {
        new_node->next = dll->first;

    } */
    else
    {
        new_node->next = dll->first;
        new_node->prev = NULL;
        dll->first->prev = new_node;
        dll->first = new_node;
    }
}

int dll_delete_node(DLL * dll, char * name)
{
    Node * tmp = dll->first;
    while (tmp != NULL && tmp->name != name)
    {
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        return 1;
    }
    else
    {
        if (tmp == dll->first)
        {
            dll->first = dll->first->next;
            dll->first->prev = NULL;
            free(tmp);
        }
        else if (tmp->next == NULL)
        {
            tmp->prev->next = NULL;
            free(tmp);
        }
        
        else
        {
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            free(tmp);
        }
        
        return 0;
    }
    
}

void dll_delete(DLL * dll)
{
    Node * tmp = dll->first;
    while (tmp != NULL)
    {
        dll->first = dll->first->next;
        free(tmp);
        tmp = dll->first;
    }
}

void dll_print(DLL * dll)
{
    Node * tmp = dll->first;
    while (tmp != NULL)
    {
        printf("%s %s\n", tmp->name, tmp->number);
        tmp = tmp->next;
    }
}

char * get_str(char * str, int p, int q)
{
    char * ret_str = (char *) malloc(sizeof(char) * (q - p + 1));
    for (int i = p, i <= q; ++i)
        ret_str[i - p] = str[i];

    return ret_str;
}

int main(void)
{
    int n, k, z;
    char query_type, ch;
    char query[30], * name, * number
    int name_end, number_end, iter;
    scanf("%d", &z);

    for (int i = 0; i < z; ++i)
    {
        scanf("%d", &n);
        scanf("%d", &k);

        while ((getchar()) != '\n');
        DLL dictionary[n];
        for (int j = 0; j < n; ++j)
            dll_init(dictionary + j);

        for (int j = 0; j < k; ++j)
        {
            iter = 2;
            fgets(query, 30, stdin);
            query_type = query[0];
            if (query_type == 'a')
            {
                while (query[iter] != ' ')
                    ++iter;
                
                name = get_str(query, 2, iter);
                // podobnie zrobić z numerem
            }
            else if (query_type == 'r')
            {
                // TODO
            }
            else
            {
                // TODO
            }
            
        }
    }

    return 0;
}
