#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uti.h"
#include "skiplist.h"
#include "skiplist_mod.h"

// #define __TEST__
#define TESTS 1

#ifndef __TEST__
int main(void)
{
    srand(time(NULL));
    int max_h, insertions, removals, searches;
    
    Timer timer1, timer2;
    double time1, time2;
    time1 = time2 = 0;

    scanf("%d\n%d\n%d\n%d", &max_h, &insertions, &removals, &searches);

    int * insert_arr, * remove_arr, * search_arr;
    insert_arr = int_get_rand_arr(insertions, insertions);
    remove_arr = int_get_rand_arr(removals, insertions);
    search_arr = int_get_rand_arr(searches, insertions);

    // int_print_arr(insert_arr, insertions);
    // int_print_arr(remove_arr, insertions);
    // int_print_arr(search_arr, insertions);
    
    for (int i = 0; i < TESTS; ++i)
    {
        ////////////////////////////////////////////////////////////////////////////////
        /// Test 1, skip lista (1)
        ////////////////////////////////////////////////////////////////////////////////
        timer_start(&timer1);

        // Stworzenie i inicjalizacja skip listy
        sl skip_list;
        sl_init(&skip_list, max_h);
         
        // printf("%d %d %d %d %d\n", max_h, insertions, removals, searches, i);

        /* Wstawianie elementow */
        for (int j = 0; j < insertions; ++j)
        {
            // scanf("%d", &aux);
            sl_insert(&skip_list, *(insert_arr + j));
            // printf("Dodano %d do listy\n", aux);
        }
        // sl_print(&skip_list);
        /* Usuwanie elementow */
        for (int j = 0; j < removals; ++j)
        {
            // scanf("%d", &aux);
            // printf("Do usuniecia %d\n", aux);
            sl_remove(&skip_list, *(remove_arr + j));
            // printf("Usunieto: %d\n", aux);
            
        }
        // sl_print(&skip_list);
        /* Zapytania dot. kluczy */
        // printf("SKIPLIST: ");
        
        for (int j = 0; j < searches; ++j)
        {
            // scanf("%d", &aux);
            if (sl_find(&skip_list, *(search_arr + j)) == 1)
                // printf("Y ");
                continue;
            else
                // printf("N ");
                continue;
        }
        sl_delete(&skip_list);

        timer_stop(&timer1);
        time1 += timer1.passed_time;
        ////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////
        /// Test 2, skip lista (2)
        ////////////////////////////////////////////////////////////////////////////////
        timer_start(&timer2);

        // Stworzenie i inicjalizacja skip listy
        slm skip_list_mod;
        slm_init(&skip_list_mod, max_h);
         
        // printf("%d %d %d %d %d\n", max_h, insertions, removals, searches, i);

        /* Wstawianie elementow */
        for (int j = 0; j < insertions; ++j)
        {
            // scanf("%d", &aux);
            slm_insert(&skip_list_mod, *(insert_arr + j));
            // printf("Dodano %d do listy\n", aux);
        }
        // sl_print(&skip_list);
        /* Usuwanie elementow */
        for (int j = 0; j < removals; ++j)
        {
            // scanf("%d", &aux);
            // printf("Do usuniecia %d\n", aux);
            slm_remove(&skip_list_mod, *(remove_arr + j));
            // printf("Usunieto: %d\n", aux);
            
        }
        // sl_print(&skip_list);
        /* Zapytania dot. kluczy */
        printf("\n");
        // printf("SKIPLIST MOD: ");
        for (int j = 0; j < searches; ++j)
        {
            // scanf("%d", &aux);
            if (slm_find(&skip_list_mod, *(search_arr + j)) == 1)
                // printf("Y ");
                continue;
            
            else
                // printf("N ");
                continue;
        }
        slm_delete(&skip_list_mod);

        timer_stop(&timer2);
        time2 += timer2.passed_time;
        ////////////////////////////////////////////////////////////////////////////////
    }

    printf("\nSKIP LIST: %lf\nSKIPLIST MOD: %lf\n", time1 / TESTS, time2 / TESTS);

    free(insert_arr);
    free(remove_arr);
    free(search_arr);

    return 0;
}
#endif


#ifdef __TEST__
int main(void)
{   
    srand(time(NULL));
    sl skiplist;
    sl_init(&skiplist, 2);

    sl_insert(&skiplist, 2);
    sl_insert(&skiplist, 3);
    sl_insert(&skiplist, 5);
    sl_insert(&skiplist, 1);
    sl_print(&skiplist);

    int a = sl_find(&skiplist, 20);
    int b = sl_find(&skiplist, 15);

    printf("%d %d\n", a, b);

    sl_remove(&skiplist, 5);
    
    sl_print(&skiplist);

    sl_delete(&skiplist);
    return 0;
}
#endif
