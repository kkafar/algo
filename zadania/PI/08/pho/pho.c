/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 35

//====================================================
typedef struct Node
{
    char * name, * number, state;
} Node;
//====================================================
// Node * new_node();
//====================================================
void set_node(Node * node, char * name, char * number);
//====================================================
void del_node(Node * node);
//====================================================
void init_node(Node * node);
//====================================================
/* Czyszczenie buffera ze znaku nowej linii, który scanf zostawia. */
void clear_buff();
//====================================================
/* Porównanie 2 stringow. (Muszą byc zakonczone znakiem nowej linii) */
int str_cmp(char * str1, char * str2);
//====================================================
int get_hash(char * str1, int mod, int i);
//====================================================
int insert(Node * hash_arr, char * name, char * number, int n);
//====================================================
int rm(Node * hash_arr, char * name, int n);
//====================================================
int str_len(char * str);
//====================================================
char * find(Node * hash_arr, char * name, int n);
//====================================================



int main(void)
{
    int z, n, k;
    char query_type, name[MAX_NAME_SIZE], number[MAX_NAME_SIZE], * aux;

    scanf("%d", &z);

    for (int t = 0; t < z; ++t)
    {
        // printf("HELLO JESTEM TUTAJ\n");
        scanf("%d", &n);
        scanf("%d", &k);
        clear_buff();
        // printf("n: %d  k: %d\n", n, k);
        Node hash_arr[n];
        for (int i = 0; i < n; ++i) 
            init_node(hash_arr + i);

        for (int j = 0; j < k; ++j)
        {
            // printf("j == %d\n", j);
            scanf("%c", &query_type);  
            if (query_type == 'a')
            {
                scanf("%s", name);   
                scanf("%s", number);
                clear_buff();
                // printf("DL: %d\n", str_len(name));
                if (insert(hash_arr, name, number, n) == 0);
                    // printf("Nie udalo sie wstawic elementu\n");
                // printf("%c %s %ld %s %ld\n", query_type, name, strlen(name), number, strlen(number));
            }
            else if (query_type == 'r')
            {
                scanf("%s", name);
                clear_buff();
                // printf("DL: %d, %s\n", str_len(name), name);
                rm(hash_arr, name, n);
            }
            else
            {
                scanf("%s", name);
                clear_buff();
                // printf("DL: %d %s\n", str_len(name), name);
                aux = find(hash_arr, name, n);
                // printf("ZNALEZIONO: %s\n", aux);
                if (aux == NULL)
                    printf("\n");

                else
                    printf("%s\n", aux);
            }
        }

        for (int i = 0; i < n; ++i)
            del_node(hash_arr + i);
            
        // clear_buff();
    }
    

    return 0;
}


//====================================================
void clear_buff()
{
    while ((getchar()) != '\n');
}
//====================================================
//====================================================
int str_cmp(char * str1, char * str2)
{
    // printf("str_cmp: %s %s\n", str1, str2);
    while (*(str1) != '\0' && *(str2) != '\0')
    {
        if (*(str1++) != *(str2++))
            return 0;
    }
    if (*(str1) == '\0' && *(str2) == '\0')
        return 1;
    
    return 0;
/* 
    int len_str1 = str_len(str1);
    if (len_str1 == str_len(str2))
    {
        for (int i = 0; i < len_str1; ++i)
            if (*(str1 + i) != *(str2 + i))
                return 0;
        
        return 1;
    }
    return 0; */
}
//====================================================
//====================================================
void set_node(Node * node, char * name, char * number)
{
    node->state = 's';

    register int i = 0;
    // printf("set_node (name): ");
    while (*(name + i) != '\0')
    {
        *(node->name + i) = *(name + i);
        // printf("%c ", *(node->name + i));
        ++i;
    }
    // printf(" dodaje null na %d\n", i);
    *(node->name + i) = '\0';
    i = 0;
    // printf("set_node (number): ");
    while (*(number + i) != '\0')
    {
        *(node->number + i) = *(number + i);
        // printf("%c ", *(node->number + i));
        ++i;
    }
    *(node->number + i) = '\0';
    // printf("\n");
}
//====================================================
//====================================================
void init_node(Node * node)
{
    node->name = (char *)(malloc(sizeof(char) * MAX_NAME_SIZE));
    node->number = (char *)(malloc(sizeof(char) * MAX_NAME_SIZE));
    node->state = 'e';
}
//====================================================
//====================================================
void del_node(Node * node)
{
    free(node->name);
    free(node->number);
    // free(node);
}
//====================================================
//====================================================
int get_hash(char * str, int mod, int i)
{
    int hash_sum = (i * i + i) / 2, j = 0; 
    while (*(str + j) != '\0')
        hash_sum += (int)(*(str + j++));
    
    return (hash_sum % mod);
}
//====================================================
//====================================================
int insert(Node * hash_arr, char * name, char * number, int n)
{
    int idx;
    for (int i = 0; i < n; ++i)
    {
        idx = get_hash(name, n, i);
        // printf("ins: Wyznaczono hash: %d\n", idx);
        if ((hash_arr + idx)->state != 's')
        {
            // printf("ins: Wstawiam na index: %d\n", idx);
            set_node(hash_arr + idx, name, number);
            return 1;
        }
    }
    return 0;
}
//====================================================
//====================================================
int rm(Node * hash_arr, char * name, int n)
{
    int idx;
    for (int i = 0; i < n; ++i)
    {
        idx = get_hash(name, n, i);
        // printf("rm: wyznaczono hash %d\n", idx);
        if ((hash_arr + idx)->state == 'e')
        {
            // printf("rm: Nie znaleziono el. do usuniecia\n");
            return 0;
        }
        else if ((hash_arr + idx)->state == 's')
        {
            // printf("rm: znaleziono zajety indeks: %d\n", idx);
            if (str_cmp((hash_arr + idx)->name, name) == 1)
            {
                // printf("rm: Usuwam element o name %s\n", (hash_arr + idx)->name);
                (hash_arr + idx)->state = 'd';
                return 1;
            }
            // printf("rm: stwierdza ze %s != %s\n", (hash_arr + idx)->name, name);
        }
    }
    // printf("rm: Nie znaleziono el. do usuniecia (poza petla)\n");
    return 0;
}
//====================================================
int str_len(char * str)
{
    int len = 0;
    while (*(str++) != '\0') ++len;
    return len;
}
//====================================================
//====================================================
char * find(Node * hash_arr, char * name, int n)
{
    int idx;
    for (int i = 0; i < n; ++i)
    {
        idx = get_hash(name, n, i);
        // printf("find: idx: %d\n", idx);
        if ((hash_arr + idx)->state == 'e')
            return ((char *)(NULL));
        
        else if ((hash_arr + idx)->state == 's')
        {
            if (str_cmp((hash_arr + idx)->name, name) == 1)
            {
                return ((hash_arr + idx)->number);
            }
        }
    }
    return ((char *)(NULL));
}
//====================================================
