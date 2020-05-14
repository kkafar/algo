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
/* Czyszczenie buffera z pozostawionego przez scnaf znaku nowej linii */
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
int get_prime(int n);
//====================================================


int main(void)
{
    int z, n, k, size;
    char query_type, name[MAX_NAME_SIZE], number[MAX_NAME_SIZE], * aux;

    scanf("%d", &z);

    for (int t = 0; t < z; ++t)
    {
        scanf("%d", &n);
        scanf("%d", &k);
        clear_buff();

        size = get_prime(n);
        // printf("PRIME: %d\n", size);

        Node * hash_arr = (Node *)(malloc(sizeof(Node) * size));

        for (int i = 0; i < size; ++i) 
            init_node(hash_arr + i);

        for (int j = 0; j < k; ++j)
        {
            scanf("%c", &query_type);  
            if (query_type == 'a')
            {
                scanf("%s", name);   
                scanf("%s", number);
                clear_buff();
                insert(hash_arr, name, number, size);
            }
            else if (query_type == 'r')
            {
                scanf("%s", name);
                clear_buff();
                rm(hash_arr, name, size);
            }
            else
            {
                scanf("%s", name);
                clear_buff();
                aux = find(hash_arr, name, size);
                if (aux == NULL)
                    printf("\n");

                else
                    printf("%s\n", aux);
            }
        }

        for (int i = 0; i < size; ++i)
            del_node(hash_arr + i);
        free(hash_arr);
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
    while (*(str1) != '\0' && *(str2) != '\0')
    {
        if (*(str1++) != *(str2++))
            return 0;
    }
    if (*(str1) == '\0' && *(str2) == '\0')
        return 1;
    
    return 0;
}
//====================================================
//====================================================
void set_node(Node * node, char * name, char * number)
{
    node->state = 's';

    register int i = 0;
    while (*(name + i) != '\0')
    {
        *(node->name + i) = *(name + i);
        ++i;
    }
    *(node->name + i) = '\0';
    i = 0;
    while (*(number + i) != '\0')
    {
        *(node->number + i) = *(number + i);
        ++i;
    }
    *(node->number + i) = '\0';
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
int insert(Node * hash_arr, char * name, char * number, int n)
{
    int idx;
    for (int i = 0; i < n; ++i)
    {
        idx = get_hash(name, n, i);
        if ((hash_arr + idx)->state != 's')
        {
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
        if ((hash_arr + idx)->state == 'e')
        {
            return 0;
        }
        else if ((hash_arr + idx)->state == 's')
        {
            if (str_cmp((hash_arr + idx)->name, name) == 1)
            {
                (hash_arr + idx)->state = 'd';
                return 1;
            }
        }
    }
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
//====================================================
int get_prime(int n)
{
    n = (n % 2 == 0) ? (n + 1) : (n + 2);
    
    int flag = 1, div; 

    while (flag)
    {
        div = 3;
        while (div * div <= n)
        {
            if (n % div == 0)
            {
                flag = 0;
                break;
            }
            
            div += 2;
        }
        if (flag == 0)
        {
            flag = 1;
            n += 2;
        }
        else
        {
            return n;
        }
    }
    return -1;
}
//====================================================
//====================================================
int get_hash(char * str, int mod, int i)
{
    int hash_sum = 0, j = 0, hash_sum2;
    while (*(str + j) != '\0')
        hash_sum += (int)(*(str + j++));

    hash_sum %= mod;
    hash_sum2 = i * (1 + hash_sum % (mod - 2));


    return ((hash_sum + hash_sum2) % mod);
}
//====================================================
