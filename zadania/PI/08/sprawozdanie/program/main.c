/**
 * K Kafara
 */
// To że trzeci algorytm zwraca więcje rekordów w przypadku gdy k > n to zrozumiałe (żadne wpisy się nie gubią w metodzie łąńcuchowej)
// Natomiast pierwszy i drugi pownny zwracać dokładnie to samo, a zdarza się inaczej :/ (ale to rzadkie przypdaki)
// Jeżeli k <= n, to algorytmy zdają się działać poprawnie.

#include <stdio.h>
#include <stdlib.h>
#include "uti.h"

#define TESTS 100

int main(void)
{
    srand(time(NULL));
    Timer timer;
    double time1 = 0, time2 = 0, time3 = 0;
    int n, k, size;
    // char query_type, name[MAX_NAME_SIZE], number[MAX_NAME_SIZE], * aux;
    char query_type, * name, * number, * aux;
    scanf("%d", &n);
    scanf("%d", &k);
    clear_buff();
    
    // Wykonujemy cały program 100 razy, końcowo bierzemy średnią.
    for (int t = 0; t < TESTS; ++t)
    {
        ////////////////////////////////////////////////////////////////////////////////
        /// GENEROWANIE WEJŚCIA
        ////////////////////////////////////////////////////////////////////////////////
        Node * queries = (Node *)(malloc(sizeof(Node) * k));
        for (int i = 0; i < k; ++i)
            get_rand_data(queries + i);
    /* 
        for (int i = 0; i < k; ++i)
            printf("%s %s\n", (queries + i)->name, (queries + i)->number); */

        char * q_type = get_rand_query_type(k);
        int * q_idx = get_idx(k);
    /*      
        for (int i = 0; i < k; ++i)
            printf("%c ", q_type[i]);
        printf("\n");

        for (int i = 0; i < k; ++i)
            printf("%d ", q_idx[i]);
        printf("\n");  */
        ////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////
        /// 1. HASZOWANIE OTWARTE (MIESZANE)
        ////////////////////////////////////////////////////////////////////////////////
        timer_start(&timer);

        size = get_power2(n);
        Node * hash_arr = (Node *)(malloc(sizeof(Node) * size));

        for (int i = 0; i < size; ++i) 
            init_node(hash_arr + i);

        for (int j = 0; j < k; ++j)
        {
            query_type = *(q_type + j);
            if (query_type == 'a')
            {
                name = (queries + *(q_idx + j))->name;
                number = (queries + *(q_idx + j))->name;
                dbh_insert(hash_arr, name, number, size);
            }
            else if (query_type == 'r')
            {
                name = (queries + *(q_idx + j))->name;
                dbh_rm(hash_arr, name, size);
            }
            else
            {
                name = (queries + *(q_idx + j))->name;
                aux = dbh_find(hash_arr, name, size);
                // if (aux == NULL);
                    // printf("\n");

                // else
                    // printf("%s\n", aux);
            }
        }

        for (int i = 0; i < size; ++i)
            del_node(hash_arr + i);
        free(hash_arr);
        
        timer_stop(&timer);

        time1 += timer.passed_time;

        // printf("PODWOJNE: %lf COLLISIONS: %d\n", time1, coll1);


        ////////////////////////////////////////////////////////////////////////////////
        /// HASZOWANIE OTWARTE (SZUKANIE KWADRATOWE)
        ////////////////////////////////////////////////////////////////////////////////
        timer_start(&timer);
        size = n;
        hash_arr = (Node *)(malloc(sizeof(Node) * size));

        for (int i = 0; i < size; ++i) 
            init_node(hash_arr + i);

        for (int j = 0; j < k; ++j)
        {
            query_type = *(q_type + j);
            if (query_type == 'a')
            {
                name = (queries + *(q_idx + j))->name;
                number = (queries + *(q_idx + j))->name;
                pho_insert(hash_arr, name, number, size);
            }
            else if (query_type == 'r')
            {
                name = (queries + *(q_idx + j))->name;
                pho_rm(hash_arr, name, size);
            }
            else
            {
                name = (queries + *(q_idx + j))->name;
                aux = pho_find(hash_arr, name, size);
                // if (aux == NULL);
                    // printf("\n");

                // else
                    // printf("%s\n", aux);
            }
        }

        for (int i = 0; i < size; ++i)
            del_node(hash_arr + i);
        free(hash_arr);
        
        timer_stop(&timer);

        time2 += timer.passed_time;

        // printf("KWADRATOWE: %lf COLLISIONS: %d\n", time2, coll2);
        ////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////
        /// ŁAŃCUCHOWE
        ////////////////////////////////////////////////////////////////////////////////
        timer_start(&timer);
        sl_list * sllhash_arr = (sl_list *)(malloc(sizeof(sl_list) * n));
        for (int i = 0; i < n; ++i) 
            sll_init(sllhash_arr + i);

        for (int j = 0; j < k; ++j)
        {
            query_type = *(q_type + j);
            if (query_type == 'a')
            {
                
                name = (queries + *(q_idx + j))->name;
                number = (queries + *(q_idx + j))->name;
                sll_push(sllhash_arr + get_hash(name, n), name, number);
            }
            else if (query_type == 'r')
            {
                name = (queries + *(q_idx + j))->name;
                has_rm(sllhash_arr + get_hash(name, n), name);
            }
            else
            {
                name = (queries + *(q_idx + j))->name;
                aux = has_find(sllhash_arr + get_hash(name, n), name);
                // if (aux == NULL);
                    // printf("\n");

                // else
                    // printf("%s\n", aux);
            }
        }

        for (int i = 0; i < n; ++i)
            sll_delete(sllhash_arr + i);
        free(sllhash_arr);    

        timer_stop(&timer);
        time3 += timer.passed_time;
        // printf("LANCUCHOWE: %lf\n", time3);
        ////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////
        /// ZWALNIANIE PAMIĘCI
        ////////////////////////////////////////////////////////////////////////////////
        for (int i = 0; i < k; ++i)
        {
            free((queries + i)->name);
            free((queries + i)->number);
        }
        free(queries);
        free(q_type);
        free(q_idx);
        ////////////////////////////////////////////////////////////////////////////////
    }
    printf("MIESZANE: %.10lf COLLISIONS: %d\n", time1 / TESTS, coll1 / TESTS);
    printf("KWADRAT: %.10lf COLLISIONS: %d\n", time2 / TESTS, coll2 / TESTS);
    printf("LANCUCHY: %.10lf\n", time3 / TESTS);
    return 0;
}