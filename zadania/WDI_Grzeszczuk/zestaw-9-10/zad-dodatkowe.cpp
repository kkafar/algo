/* 
    By K. Kafara
    Zestaw 9-10, zadania dodatkowe
1. Proszę napisać funkcję wstawiającą na koniec listy nowy element. Do
funkcji należy przekazać wskazanie na pierwszy element listy oraz wstawianą
wartość.
2. Proszę napisać funkcję usuwającą ostatni element listy. Do funkcji
należy przekazać wskazanie na pierwszy element listy.
3. Dana jest niepusta lista, proszę napisać funkcję usuwającą co drugi
element listy. Do funkcji należy przekazać wskazanie na pierwszy element
listy.

*/

#include <iostream>
using namespace std;

struct node 
{
    int val;
    node * next;

    node()
    {
        next = NULL;
    }
};

void push_front(node * &first, const int& value)
{
    node * tmp = new node;
    tmp->val = value;
    tmp->next = first;
    first = tmp;
}

/// ==================================================
/*  
    ZADANIE 1 DODATKOWE
    
    wskaźnik na pierwszy element przekazujemy przez referencję, bo w wypadku gdy lista jest pusta
    potrzebujemy ustawić wskaźnik na pierwszy dodany element
*/
void push_back(node * &first, const int& value)
{
    // jeżeli lista jest pusta
    // to po prostu dodajemy nowy element
    if (first == NULL)
    {
        node * tmp = new node;
        tmp->val = value;
        // tmp->next zostaje NULLEM
        first = tmp;
        return;
    }
    // w innym przypadku potrzebujemy adres ostatniego elementu w liście
    node * last = first; 

    while (last->next != NULL)
        last = last->next;

    node * tmp = new node;
    tmp->val = value;
    last->next = tmp;
    last = tmp;

    return;
}
/// ==================================================

/// ==================================================
/* 
    ΖΑDANIE 2 DODATKOWE

    Usuwanie ostatniego elementu z listy. Podobnie jak w poprzednim zadaniu wskaźnik należy przekazać
    przez referencję, gdyż w przypadku usuwania z listy jednoelementowej trzeba go przestawić na NULL 
*/
void delete_last(node * & first)
{
    // jeżeli lista jest pusta to przerywamy procedurę
    if (first == NULL) return;

    // jeżeli jest jedno elementowa, to oczywiście usuwamy ten jeden element
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        return;
    }

    // tutaj wiemy już, że lista jest co najmniej 2 elementowa ==> istnieje element ostatni i przedostatni
    // wyznaczamy je:
    node * last = first, * sec_last = NULL;
    while (last->next != NULL)
    {
        sec_last = last;
        last = last->next;
    }
    // wskaźnik przedostatniego ustwawiamy na NULL, a ostatni usuwamy
    sec_last->next = NULL;
    delete last;
    return;
}
/// ==================================================

/// ==================================================
/*
    ZADANIE 3 DODATKOWE
   
    Umówmy się, że usuwanie zaczynamy od pierwszego elementu
*/
void del_every_oth(node * & first)
{
    // Treść zadania wyklucza pustą listę, ale zadbajmy o to, normlanie nie trzeba tego if'a
    if (first == NULL) return;

    // jeżeli lista jest jednoelementowa
    if (first->next == NULL)
    {
        delete first;
        first = NULL;
        return;
    }
    
    // lista ma co najmniej 2 elementy:
    node * tmp = NULL, * del = first;
    // skoro adres pierwszego mamy w del, a i tak idzie do usunięca, to przesuwamy go na drugi element
    first = first->next;
    while (del->next != NULL)
    {
        tmp = del->next;
        delete del;
        if (tmp->next == NULL) return;
        else
            del = tmp->next;

        tmp->next = del->next;
    }
}
/// ==================================================


void delete_list(node * &first)
{
    node * tmp;
    for (register node * iter = first; iter != NULL;)
    {
        tmp = iter;
        iter = iter->next;
        delete tmp;
    }
    first = NULL;
}

void print_list(node * first)
{
    for (; first != NULL; first = first->next)
        cout << first->val << " ";
    
    cout << "\n";
}

int main()
{
    // Zadanie 1 (dodatkowe)
/* 
    node * list = NULL;
    for (int i = 0; i < 5; ++i)
        push_front(list, i);

    print_list(list);
    delete_list(list);
    print_list(list);
    
    for (int i = 0; i < 5; ++i)
        push_back(list, i);

    print_list(list);
    delete_list(list);
    print_list(list);
*/

    // Zadanie 2 (dodatkowe)
/*
    node * l1 = NULL, * l2 = NULL, * l3 = NULL;
    for (int i = 0; i < 5; ++i)
        push_front(l1, i);

    push_front(l2, 1); push_front(l3, 3); push_front(l3, 4);

    print_list(l1); print_list(l2); print_list(l3);

    delete_last(l1); delete_last(l2); delete_last(l3);

    print_list(l1); print_list(l2); print_list(l3);
*/

    // Zadanie 3 (dodatkowe)
/*
    node * list = NULL;

    // parzystej długości 
    for (int i = 0; i < 10; ++i)
        push_front(list, i);
    
    print_list(list);  del_every_oth(list); print_list(list); delete_list(list); print_list(list);

    // nieparzystej długośći 
    for (int i = 0; i < 9; ++i)
        push_front(list, i);

    print_list(list);  del_every_oth(list); print_list(list); delete_list(list); print_list(list);

    // pojedynczy element
    push_back(list, 1);

    print_list(list);  del_every_oth(list); print_list(list); delete_list(list); print_list(list);

    // podwójny element
    push_back(list, 1);
    push_back(list, 2);
        
    print_list(list);  del_every_oth(list); print_list(list); delete_list(list); print_list(list);
*/
    return 0;
}
