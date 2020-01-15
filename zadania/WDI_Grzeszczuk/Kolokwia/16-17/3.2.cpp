/*
    By K. Kafara
    
    ad-wdi k3a, wtorek, 10 stycznia 2017

2. Dane są dwie listy cykliczne powstałe przez zapętlenie listy jednokierunkowej posortowanej
rosnąco, dla każdej listy dany jest wskaźnik wskazujący przypadkowy element w takiej liście.
Proszę napisać funkcję, która dla dwóch list cyklicznych, usuwa z obu list elementy
występujące w obu listach. Do funkcji należy przekazać wskaźniki na dwie listy, funkcja
powinna zwrócić łączną liczbę usuniętych elementów     

*/

#include <iostream>
#include "list.h"

/* 
    Zadanie ad-wdi k3a, wtorek, 10 stycznia 2017 
*/
// ==================================================
// funkcja ustawiająca wskaźnik na cykl, na najmniejszy element (lub ten sam, jeżeli lista jest 'jednowartościowa')
// zwraca adres elementu poprzedzającego najmniejszy (…)
// założenie: lista ma co najmniej 2 elementy !!!!!!!!!!!!!!!!!!!!
node * set(node *& list)
{
    node * trc = list, * stop = list;
    list = list->next;
    while ((trc->val <= list->val) && list != stop)
    {
        trc = list;
        list = list->next;
    }
    // przerywamy cykl
   // trc->next = NULL;
    return trc;
}
// usuwa z listy posortowanej rosnąco wszystkie elementy o zadanym kluczu
// jeżeli jakiś element został usunięty zwraca true
// false wpp
int delete_by_key(node *& list, const int & key, int & counter)
{
    node * stop = list, * trc = list, * iter = list->next, * tmp;
    int deleted = 0;
    // zaczynamy sprawdzanie od drugiego elementu! I kończymy na 'stop'. Tamten element trzeba obsłużyć osobno
    while (iter != NULL && iter->val <= key)
    {
        if (iter->val == key)
        {
            tmp = iter;
            iter = iter->next;
            trc->next = iter;
            delete tmp;
            ++deleted;
        }
        else
        {
            trc = iter;
            iter = iter->next;
        }
    }
    if (stop->val == key)
    {
        trc->next = stop->next;
        list = list->next;
        delete stop;
        ++deleted;
    }
    counter += deleted;
    return deleted;
}
void make_cycle(node * list)
{
    node * first = list;
    if (list == NULL) return;
    while (list->next != NULL)
        list = list->next;

    list->next = first;
}
void break_cycle(node * list)
{
    node * first = list;
    if (list == NULL) return;
    while (list->next != first)
        list = list->next;

    list->next = NULL;
}
int func(node *& list1, node *& list2)
{
    if (list1 == NULL || list2 == NULL) return 0;
    int counter = 0, key;
    node * iter = list1, * tmp, * tmp2;
    set(list1); 
    set(list2);
    break_cycle(list1);
    break_cycle(list2);
    while (iter != NULL)
    {
        if (delete_by_key(list2, iter->val, counter) != 0)
        {  
            tmp = iter;
            key = iter->val;
            while (iter != NULL && iter->val == key)
            {
                tmp2 = iter;
                if (iter == list1) list1 = list1->next;
                iter = iter->next;
                tmp2->next = NULL;
                delete tmp2;
                ++counter;
            }
            tmp->next = iter;
            
        }
        else
        {
            iter = iter->next;
        }
    }

    return counter;
}
// ==================================================

int main()
{
    node * l1 = NULL, * l2 = NULL;

    for (int i = 0; i < 10; ++i)
        push_back(l1, i);

    for (int i = 0; i < 20; ++i)
        push_back(l2, i);
    
    push_back(l1,19);
    push_back(l1, 21);
    print_list(l1); print_list(l2);
    make_cycle(l1); make_cycle(l2);
    func(l1, l2);
    std::cout << "JESTEM TUTAJ\n";
    //break_cycle(l1); break_cycle(l2);
    print_list(l1);
    print_list(l2);
    return 0;
}
