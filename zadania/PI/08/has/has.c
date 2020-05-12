/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////
/// Węzeł listy
///////////////////////////////////////////////////////////////////////
typedef struct Node
{
    char * name, * number;
    struct Node * next;
} Node;
///////////////////////////////////////////////////////////////////////
/// Obsługa węzła
///////////////////////////////////////////////////////////////////////
Node * get_new_node(char * name, char * number, Node * next)
{
    Node * new_node = (Node *) malloc(sizeof(Node));
    new_node->name = name;
    new_node->number = number;
    new_node->next = next;
    return new_node;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
/// Lista jednokierunkowa
///////////////////////////////////////////////////////////////////////
typedef struct SinglyLinkedList
{
    // wartownik
    Node * snt;
} sl_list;
///////////////////////////////////////////////////////////////////////
/// Obsługa listy
///////////////////////////////////////////////////////////////////////
void init_list(sl_list * list)
{
    list->snt = get_new_node("SNT", "NULL", NULL);
}
///////////////////////////////////////////////////////////////////////
void push_front(sl_list * list, char * name, char * number)
{
    Node * new_node = get_new_node(name, number, list->snt->next);
    list->snt->next = new_node;
}
///////////////////////////////////////////////////////////////////////
void delete_list(sl_list * list)
{
    Node * tmp;
    while (list->snt != NULL)
    {
        tmp = list->snt;
        list->snt = list->snt->next;
        free(tmp);
    }
}
///////////////////////////////////////////////////////////////////////
int delete_node(sl_list * list, char * name)
{
    Node * tmp = list->snt->next, * tracker = list->snt;
    while (tmp != NULL)
    {
        if (*(tmp->name) == *name)
        {
            // printf("Found name: %s\n", name);
            tracker->next = tmp->next;
            free(tmp);
            return 1;
        }
        tracker = tmp;
        tmp = tmp->next;
    }
    // Nie znaleziono takiego elementu
    return 0;
}
///////////////////////////////////////////////////////////////////////
char * get_number(sl_list * list, char * name, int * number_len)
{
    Node * tmp = list->snt->next;
    while (tmp != NULL)
    {
        if (*(tmp->name) == *name)
        {
            *number_len = sizeof(tmp->number) / sizeof(char);
            return tmp->number;
        }
        tmp = tmp->next;
    }
    return (char *)(NULL);
}
///////////////////////////////////////////////////////////////////////
void print_list(sl_list * list)
{
    printf("List starting at %p\n", list->snt->next);
    Node * tmp = list->snt->next;
    while (tmp != NULL)
    {
        printf("(%s, %s) ", tmp->name, tmp->number);
        tmp = tmp->next;
    }
    printf("\n");
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
/// Funkcje pomocnicze
///////////////////////////////////////////////////////////////////////
char * getstr(char * str, int p, int q)
{
    // printf("getstr rezerwuje %ld bajtow pamieci\n", (q - p + 1) * sizeof(char));
    char * retstr = (char *) malloc(sizeof(char) * (q - p + 1));
    for (int i = p; i <= q; ++i)
        *(retstr + i - p) = *(str + i);
    
    return retstr;
}
///////////////////////////////////////////////////////////////////////
int gethash(char * name, int len, int mod)
{
    int hash = 0;
    for (int i = 0; i < len; ++i)
        hash += (int)(*(name + i));

    return (hash % mod);
}
///////////////////////////////////////////////////////////////////////
int main(void)
{
    int z, n, k, name_end, number_end, number_len;
    char query[65], * name, * number;


    scanf("%d", &z);

    for (int i = 0; i < z; ++i)
    {
        scanf("%d", &n);

        scanf("%d", &k);

        sl_list hash_table[n];  
        for (int j = 0; j < n; ++j)
            init_list(hash_table + j);

        // opróżnamy buffer (or ?) przed fgets'em;
        while ((getchar()) != '\n');

        for (int j = 0; j < k; ++j)
        {
            // printf("j: %d\n", j);
            fgets(query, 65, stdin);
            // printf("QUERY: %s", query);
            if (query[0] == 'a')
            {
                // printf("Detected query type %c\n", query[0]);
                name_end = 1;
                while (query[name_end + 1] != ' ')
                    ++name_end;
                
                name = getstr(query, 2, name_end);

                number_end = name_end + 1;
                while (query[number_end + 1] != '\n' && query[number_end + 1] != ' ')
                    ++number_end;
                
                number = getstr(query, name_end + 2, number_end);
                // printf("%d %d\n", name_end + 2, number_end);
                // printf("NAME: %s NUMBER: %s\n", name, number);

                push_front(hash_table + gethash(name, name_end - 1, n), name, number);
            }
            else if (query[0] == 'r')
            {
                name_end = 1;
                while (query[name_end + 1] != ' ' && query[name_end + 1] != '\n')
                    ++name_end;
                
                name = getstr(query, 2, name_end);  
                // printf("QUERY: %c, HASH: %d\n", query[0], gethash(name, name_end - 1, n));
                if (delete_node(hash_table + gethash(name, name_end - 1, n), name) == 0)
                    putchar('\n');     

                free(name);    
            }
            else
            {
                name_end = 1;
                while (query[name_end + 1] != ' ' && query[name_end + 1] != '\n')
                    ++name_end;

                name = getstr(query, 2, name_end);
                number = get_number(hash_table + gethash(name, name_end - 1, n), name, &number_len);
                // printf("NUMBER: %s\n", number);
                if (number == NULL) putchar('\n');
                else
                {
                    for (int t = 0; t < number_len; ++t)
                    {
                        putchar(number[t]);
                    } 
                    putchar('\n');
                }
            }
            
        }
        for (int j = 0; j < n; ++j)
            delete_list(hash_table + j);
        // printf("Exiting internal for\n");
    } 
    return 0;
}
