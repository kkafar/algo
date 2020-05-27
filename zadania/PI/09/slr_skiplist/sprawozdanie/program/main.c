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
    
    Timer timer;
    double time1_insert = 0, time1_remove = 0, time1_search = 0, time2_insert = 0, time2_remove = 0, time2_search = 0;


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

        // Stworzenie i inicjalizacja skip listy
        sl skip_list;
        sl_init(&skip_list, max_h);
         
        ////////////////////////////////////////////////////////////////////////////////
        /* Wstawianie elementow */
        timer_start(&timer);
        for (int j = 0; j < insertions; ++j)
        {
            sl_insert(&skip_list, *(insert_arr + j));
        }
        timer_stop(&timer);
        time1_insert += timer.passed_time;
        ////////////////////////////////////////////////////////////////////////////////
        /* Usuwanie elementow */
        timer_start(&timer);
        for (int j = 0; j < removals; ++j)
        {
            sl_remove(&skip_list, *(remove_arr + j));
        }
        timer_stop(&timer);
        time1_remove += timer.passed_time;
        ////////////////////////////////////////////////////////////////////////////////
        /* Zapytania dot. kluczy */
        timer_start(&timer);
        for (int j = 0; j < searches; ++j)
        {
            if (sl_find(&skip_list, *(search_arr + j)) == 1)
                continue;
            else
                continue;
        }
        timer_stop(&timer);
        time1_search += timer.passed_time;
        ////////////////////////////////////////////////////////////////////////////////
        sl_delete(&skip_list);
        ////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////
        /// Test 2, skip lista (2)
        ////////////////////////////////////////////////////////////////////////////////
        // Stworzenie i inicjalizacja skip listy
        slm skip_list_mod;
        slm_init(&skip_list_mod, max_h);
         
        ////////////////////////////////////////////////////////////////////////////////
        /* Wstawianie elementow */
        timer_start(&timer);
        for (int j = 0; j < insertions; ++j)
        {
            slm_insert(&skip_list_mod, *(insert_arr + j));
        }
        timer_stop(&timer);
        time2_insert += timer.passed_time;
        ////////////////////////////////////////////////////////////////////////////////
        /* Usuwanie elementow */
        timer_start(&timer);
        for (int j = 0; j < removals; ++j)
        {
            slm_remove(&skip_list_mod, *(remove_arr + j));  
        }
        timer_stop(&timer);
        time2_remove += timer.passed_time;
        ////////////////////////////////////////////////////////////////////////////////
        /* Zapytania dot. kluczy */
        timer_start(&timer);
        for (int j = 0; j < searches; ++j)
        {
            if (slm_find(&skip_list_mod, *(search_arr + j)) == 1)
                continue;
            else
                continue;
        }
        timer_stop(&timer);
        time2_search += timer.passed_time;
        ////////////////////////////////////////////////////////////////////////////////
        slm_delete(&skip_list_mod);
        ////////////////////////////////////////////////////////////////////////////////
    }

    // Wyswietlanie czasow 
    printf("SL INS: %lf\n", time1_insert / TESTS);
    printf("SL RM: %lf\n", time1_remove / TESTS);
    printf("SL SRCH: %lf\n", time1_search / TESTS);
    printf("SLM INS: %lf\n", time2_insert / TESTS);
    printf("SLM RM: %lf\n", time2_remove / TESTS);
    printf("SLM SRCH: %lf\n", time2_search / TESTS);


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
