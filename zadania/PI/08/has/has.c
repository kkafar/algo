/**
 * K. Kafara
 * Pytanie 1
 * * Jak to zorganizować, żeby nie było żadnego wyniku pamięci?
 * Pytanie 2
 * * Dlaczego valgrind wypisuje błędy przy wypisywaniu stringów printf'em?
 * 
 * 
 * Odp. 1
 * Przy dodawaniu elementu do listy, zamiast przekazywa wskaźniki, będziemy kopiować wartość. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////
/// Węzeł listy
///////////////////////////////////////////////////////////////////////
typedef struct Node
{
    char * name, * number;
    int number_len, name_len;
    struct Node * next;
} Node;
///////////////////////////////////////////////////////////////////////
/// Obsługa węzła
///////////////////////////////////////////////////////////////////////
Node * get_new_node(char * name, char * number, int name_len, int number_len, Node * next)
{
    Node * new_node = (Node *) malloc(sizeof(Node));
    // printf("Rezerwuje wezel\nObszar: %p - %p\n", new_node, new_node + sizeof(Node));   
    new_node->name = (char *) malloc(sizeof(char) * name_len);
    // printf("Rezerwuje miejsce na pole name\nObszar %p - %p\n", new_node->name, new_node->name + sizeof(char) * name_len);
    new_node->number = (char *) malloc(sizeof(char) * number_len);
    // printf("Rezerwuje miejsce na pole number\nObszar %p - %p\n", new_node->number, new_node->number + sizeof(char) * number_len);
    
    for (int i = 0; i < name_len; ++i)
        *(new_node->name + i) = *(name + i);

    for (int i = 0; i < number_len; ++i)
        *(new_node->number + i) = *(number + i);
    
    new_node->next = next;
    new_node->number_len = number_len;
    new_node->name_len = name_len;
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
    list->snt = get_new_node("", "", 0, 0, NULL);
}
///////////////////////////////////////////////////////////////////////
void push_front(sl_list * list, char * name, char * number, int name_len, int number_len)
{
    Node * new_node = get_new_node(name, number, name_len, number_len, list->snt->next);
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
        free(tmp->name);
        free(tmp->number);
        free(tmp);
    }
}
///////////////////////////////////////////////////////////////////////
int str_eq(char * str1, char * str2, int len1, int len2)
{
    if (len1 == len2)
    {
        for (int i = 0; i < len1; ++i)
        {
            if (*(str1 + i) != *(str2 + i))
                return 0;
        }
        return 1;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////
int delete_node(sl_list * list, char * name, int name_len)
{
    Node * tmp = list->snt->next, * tracker = list->snt;
    while (tmp != NULL)
    {
        if (str_eq(tmp->name, name, tmp->name_len, name_len) == 1)
        {
            // printf("Found name: %s\n", name);
            tracker->next = tmp->next;
            // printf("del_node: Zwalniam pole name od %p\n", tmp->name);
            free(tmp->name);
            // printf("del_node: Zwalniam pole number od %p\n", tmp->number);
            free(tmp->number);
            // printf("del_node: Zwalniam wezel od %p\n", tmp);
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
char * get_number(sl_list * list, char * name, int name_len, int * number_len)
{
    Node * tmp = list->snt->next;
    while (tmp != NULL)
    {
        if (str_eq(tmp->name, name, tmp->name_len, name_len) == 1)
        {   
            // printf("Stwierdzilem ze %s == %s\n", tmp->name, name);
            *number_len = tmp->number_len;
            // printf("get_number: Zwracam obszar %p - %p  (number_len == %d)\n", tmp->number, tmp->number + tmp->number_len, *number_len);
            return tmp->number;
        }
        tmp = tmp->next;
    }
    return (char *)(NULL);
}
///////////////////////////////////////////////////////////////////////
void print_list(sl_list * list)
{
    // printf("List starting at %p\n", list->snt->next);
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
    // printf("getstr: rezerwuje %p - %p\n", retstr, retstr + sizeof(char) * (q - p + 1));
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
                // printf("name_end == %d, number_end == %d, number_len == %d\n", name_end, number_end, number_end - name_end - 1);
                push_front(hash_table + gethash(name, name_end - 1, n), name, number, name_end - 1, number_end - name_end -1);
                // printf("(a) Zwalniam name %p\n", name);
                free(name);
                // printf("(a) Zwalniam number %p\n", number);
                free(number);
            }
            else if (query[0] == 'r')
            {
                name_end = 1;
                while (query[name_end + 1] != ' ' && query[name_end + 1] != '\n')
                    ++name_end;
                
                name = getstr(query, 2, name_end);  
                // printf("QUERY: %c, HASH: %d\n", query[0], gethash(name, name_end - 1, n));
                if (delete_node(hash_table + gethash(name, name_end - 1, n), name, name_end - 1) == 0)
                    putchar('\n');     

                // printf("(r) Zwalniam name %p\n", name);
                free(name);    
            }
            else
            {
                name_end = 1;
                while (query[name_end + 1] != ' ' && query[name_end + 1] != '\n')
                    ++name_end;

                name = getstr(query, 2, name_end);
                number = get_number(hash_table + gethash(name, name_end - 1, n), name, name_end - 1,&number_len);
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
                // printf("(g) Zwalniam name %p\n", name);
                free(name);
            }
            
        }
        for (int j = 0; j < n; ++j)
            delete_list(hash_table + j);
        // printf("Exiting internal for\n");
    } 
    return 0;
}
