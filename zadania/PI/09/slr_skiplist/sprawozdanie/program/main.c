#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uti.h"
#include "skiplist.h"
#include "skiplist_mod.h"

// #define __TEST__
#define TESTS 100

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
        for (int j = 0; j < insertions; ++j)
        {
            timer_start(&timer);
            sl_insert(&skip_list, *(insert_arr + j));
            timer_stop(&timer);
            time1_insert = time1_insert + timer.passed_time;
            // printf("Czas po %d probach: %10lf, czas od ostatniej proby: %10lf\n", i + 1, time1_insert, timer.passed_time);
        }
        // printf("Czas po %d probach: %10lf, czas od ostatniej proby: %10lf\n", i + 1, time1_insert, timer.passed_time);
        ////////////////////////////////////////////////////////////////////////////////
        /* Usuwanie elementow */
        for (int j = 0; j < removals; ++j)
        {
            timer_start(&timer);
            sl_remove(&skip_list, *(remove_arr + j));
            timer_stop(&timer);
            time1_remove += timer.passed_time;
        }
        ////////////////////////////////////////////////////////////////////////////////
        /* Zapytania dot. kluczy */
        for (int j = 0; j < searches; ++j)
        {
            timer_start(&timer);
            sl_find(&skip_list, *(search_arr + j));
            timer_stop(&timer);
            time1_search += timer.passed_time;
        }
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
        for (int j = 0; j < insertions; ++j)
        {
            timer_start(&timer);
            slm_insert(&skip_list_mod, *(insert_arr + j));
            timer_stop(&timer);
            time2_insert += timer.passed_time;
        }
        
        ////////////////////////////////////////////////////////////////////////////////
        /* Usuwanie elementow */
        for (int j = 0; j < removals; ++j)
        {
            timer_start(&timer);
            slm_remove(&skip_list_mod, *(remove_arr + j)); 
            timer_stop(&timer);
            time2_remove += timer.passed_time; 
        }

        ////////////////////////////////////////////////////////////////////////////////
        /* Zapytania dot. kluczy */
        for (int j = 0; j < searches; ++j)
        {
            timer_start(&timer);
            slm_find(&skip_list_mod, *(search_arr + j));
            timer_stop(&timer);
            time2_search += timer.passed_time;
        }
        ////////////////////////////////////////////////////////////////////////////////
        slm_delete(&skip_list_mod);
        ////////////////////////////////////////////////////////////////////////////////
    }

    // Wyswietlanie czasow 
    printf("TESTS: %d\n", TESTS);
    printf("SL INS:   %8lf    %8lf\n", time1_insert, time1_insert / TESTS);
    printf("SL RM:    %8lf    %8lf\n", time1_remove, time1_remove / TESTS);
    printf("SL SRCH:  %8lf    %8lf\n", time1_search, time1_search / TESTS);
    printf("SLM INS:  %8lf    %8lf\n", time2_insert, time2_insert / TESTS);
    printf("SLM RM:   %8lf    %8lf\n", time2_remove, time2_remove / TESTS);
    printf("SLM SRCH: %8lf    %8lf\n", time2_search, time2_search / TESTS);
    


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
