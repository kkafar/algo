#include "uti.h"
#include <stdio.h>
#include <stdlib.h>

int coll1 = 0, coll2 = 0;
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
int dbh_insert(Node * hash_arr, char * name, char * number, int n)
{
    int idx, hash = get_hash(name, n);
    for (int i = 0; i < n; ++i)
    {
        idx = (2 * hash + 1) % n;
        if (idx == 0) ++idx;
        idx *= i;
        idx = (idx + hash) % n;
        if ((hash_arr + idx)->state != 's')
        {
            set_node(hash_arr + idx, name, number);
            return 1;
        }
        else
        {
            ++coll1;
        }
    }
    return 0;
}
//====================================================
//====================================================
int dbh_rm(Node * hash_arr, char * name, int n)
{
    int idx, hash = get_hash(name, n);
    for (int i = 0; i < n; ++i)
    {
        idx = (2 * hash + 1) % n;
        if (idx == 0) ++idx;
        idx *= i;
        idx = (idx + hash) % n;
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
            else
            {
                ++coll1;
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
char * dbh_find(Node * hash_arr, char * name, int n)
{
    int hash = get_hash(name, n), idx;
    for (int i = 0; i < n; ++i)
    {
        idx = (2 * hash + 1) % n;
        if (idx == 0) ++idx;
        idx *= i;
        idx = (idx + hash) % n;
        if ((hash_arr + idx)->state == 'e')
            return ((char *)(NULL));
        
        else if ((hash_arr + idx)->state == 's')
        {
            if (str_cmp((hash_arr + idx)->name, name) == 1)
            {
                return ((hash_arr + idx)->number);
            }
            else
            {
                ++coll1;
            }
        }
    }
    return ((char *)(NULL));
}
//====================================================
int get_power2(int n)
{
    int size = 2;
    while (size < n)
        size <<= 1;
    
    return size;
}
//====================================================
int get_hash(char * str, int mod)
{
    int hash_sum = 0, j = 0;
    while (*(str + j) != '\0')
        hash_sum += (int)(*(str + j++));

    return (hash_sum % mod);
}
//====================================================

////////////////////////////////////////////////////////////////////////////////
/// HASZOWANIE Z PRZYROSTEM KWADRATOWYM
////////////////////////////////////////////////////////////////////////////////
int pho_get_hash(char * str, int mod, int i)
{
    int hash_sum = (i * i + i) / 2, j = 0; 
    while (*(str + j) != '\0')
        hash_sum += (int)(*(str + j++));
    
    return (hash_sum % mod);
}
////////////////////////////////////////////////////////////////////////////////
int pho_insert(Node * hash_arr, char * name, char * number, int n)
{
    int idx;
    for (int i = 0; i < n; ++i)
    {
        idx = pho_get_hash(name, n, i);
        // printf("ins: Wyznaczono hash: %d\n", idx);
        if ((hash_arr + idx)->state != 's')
        {
            // printf("ins: Wstawiam na index: %d\n", idx);
            set_node(hash_arr + idx, name, number);
            return 1;
        }
        else
        {
            ++coll2;
        }
        
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
int pho_rm(Node * hash_arr, char * name, int n)
{
    int idx;
    for (int i = 0; i < n; ++i)
    {
        idx = pho_get_hash(name, n, i);
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
            else
            {
                ++coll2;
            }
            // printf("rm: stwierdza ze %s != %s\n", (hash_arr + idx)->name, name);
        }
    }
    // printf("rm: Nie znaleziono el. do usuniecia (poza petla)\n");
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
char * pho_find(Node * hash_arr, char * name, int n)
{
    int idx;
    for (int i = 0; i < n; ++i)
    {
        idx = pho_get_hash(name, n, i);
        // printf("find: idx: %d\n", idx);
        if ((hash_arr + idx)->state == 'e')
            return ((char *)(NULL));
        
        else if ((hash_arr + idx)->state == 's')
        {
            if (str_cmp((hash_arr + idx)->name, name) == 1)
            {
                return ((hash_arr + idx)->number);
            }
            else
            {
                ++coll2;
            }
            
        }
    }
    return ((char *)(NULL));
}
////////////////////////////////////////////////////////////////////////////////
/// POMIAR CZASU
////////////////////////////////////////////////////////////////////////////////
void timer_start(Timer * timer)
{
    timer->start_time = clock();
}
////////////////////////////////////////////////////////////////////////////////
void timer_stop(Timer * timer)
{
    timer->stop_time = clock();
    timer->passed_time = ((double)(timer->stop_time - timer->start_time)) / CLOCKS_PER_SEC;
}
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
/// GENEROWANIE WEJŚCIA
////////////////////////////////////////////////////////////////////////////////
char * get_rand_query_type(int size)
{
    static char query_type[3] = {'a', 'g', 'r'};
    char * q_type = (char *)(malloc(sizeof(char) * (size + 1)));
    for (int i = 0; i < size; ++i)
    {
        *(q_type + i) = *(query_type + rand() % 3);
    }
    *(q_type + size) = '\0';
    return q_type;
}
////////////////////////////////////////////////////////////////////////////////
char * get_rand_str(int size)
{
    static char charset[] = "qwertyuiopasdfghjklzxcvbnm";
    char * str = (char*)(malloc( sizeof(char) * (size + 1) ));
    for (int i = 0; i < size; ++i)
        *(str + i) = *(charset + rand() % 26);

    *(str + size) = '\0';

    return str;
}
////////////////////////////////////////////////////////////////////////////////
int * get_idx(int size)
{
    int * arr = (int *)(malloc(sizeof(int) * size));
    for (int * ptr = arr; ptr < arr + size; ++ptr)
        *ptr = rand() % size;
    return arr;
}
////////////////////////////////////////////////////////////////////////////////
void get_rand_data(Node * node)
{
    node->name = get_rand_str(rand() % 20 + 1);
    node->number = get_rand_str(rand() % 20 + 1);
    // node->state = get_rand_query_type();
}
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/// Obsługa węzła
///////////////////////////////////////////////////////////////////////
SllNode * sll_get_new_node()
{
    SllNode * new_node = (SllNode *)(malloc(sizeof(SllNode)));

    new_node->name = (char *)(malloc(sizeof(char) * MAX_NAME_SIZE));
    new_node->number = (char *)(malloc(sizeof(char) * MAX_NAME_SIZE));

    return new_node;
}
///////////////////////////////////////////////////////////////////////
void sll_set_node(SllNode * node, char * name, char * number, SllNode * next)
{
    node->next = next;

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
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/// Obsługa listy
///////////////////////////////////////////////////////////////////////
void sll_init(sl_list * list)
{
    list->snt = sll_get_new_node();
    sll_set_node(list->snt, "", "", NULL);
}
///////////////////////////////////////////////////////////////////////
void sll_push(sl_list * list, char * name, char * number)
{
    SllNode * new_node = sll_get_new_node();
    sll_set_node(new_node, name, number, list->snt->next);
    list->snt->next = new_node;
}
///////////////////////////////////////////////////////////////////////
void sll_delete(sl_list * list)
{
    SllNode * tmp;
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
int has_rm(sl_list * list, char * name)
{
    SllNode * tmp = list->snt->next, * tracker = list->snt;
    while (tmp != NULL)
    {
        if (str_cmp(tmp->name, name) == 1)
        {
            // printf("Found name: %s\n", name);
            tracker->next = tmp->next;
            // printf("del_SllNode: Zwalniam pole name od %p\n", tmp->name);
            free(tmp->name);
            // printf("del_SllNode: Zwalniam pole number od %p\n", tmp->number);
            free(tmp->number);
            // printf("del_SllNode: Zwalniam wezel od %p\n", tmp);
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
char * has_find(sl_list * list, char * name)
{
    SllNode * tmp = list->snt->next;
    while (tmp != NULL)
    {
        if (str_cmp(tmp->name, name) == 1)
        {   
            return tmp->number;
        }
        tmp = tmp->next;
    }
    return (char *)(NULL);
}
///////////////////////////////////////////////////////////////////////