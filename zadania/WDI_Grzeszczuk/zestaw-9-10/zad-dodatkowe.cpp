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
4. Dana jest niepusta lista reprezentująca liczbę naturalną. Kolejne
elementy listy przechowują kolejne cyfry. Proszę napisać funkcję
zwiększającą taką liczbę o 1.
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

/// ==================================================
/*
    ZADANIE 4 DODATKOWE

    W zadaniu nie ma sprecyzowanego jak przechowywana jest liczba. 
    Pzyjmijmy że największą wagę ma cyfra dodana do listy jako pierwsza (ostatnia).
    Dzięki temu będziemy mogli swobodnie poruszać się po liście. 
    (Gdyby zrobić na odwrót, dużym problemem byłoby przechodzenie do kolejnych elementów listy)
*/
void add_one(node * first)
{
    // wskaźnik na pierszy element:
    node * f = first;
    // jeżeli lista jest pusta od razu kończymy działanie procedury
    // założenia zadania nie dopuszczają takiej sytuacji, no ale. 
    if (first == NULL) return;
    
    // lista jest co najmniej jednoelementowa, to zwiększamy ostatnią cyfrę
    first->val += 1;  

    // reszta to liczba dziesiątek sumy z linijki wyżej
    int overflow = (first->val) / 10;
    
    // a ostatnia cyfra to cyfra jedności first->val
    first->val %= 10;
    
    // przestawiamy się na kolejną cyfrę
    first = first->next;
    
    // dopóki nie skończą nam się cyfry, lub nie będzie już co przenosić  
    while (first != NULL && overflow != 0)
    {
        first->val += overflow; 
        overflow = (first->val) / 10;
        first->val %= 10;
        first = first->next;
    }
    
    // jeżeli skończyły nam się cyfry, a ciągle zostało coś do przenoszenia ==> musimy dodać cyfrę na koniec
    // naszej liczby. Można tu skorzystać z procedury przygotowanej w zadaniu 1 (dodatkowym). W ramach ćwiczeń
    // piszemy jeszcze raz: Wiemy że lista jest co najmniej jedno elementowa ==> nie musimy przejmować się przypadkiem gdy jest pusta.
    if (overflow != 0)
    {
        // Znajdujemy adres ostatenigo elementu w liście:
        node * last = f;
        while (last->next != NULL)
            last = last->next;
        
        // Jako że to funkcja dodająca jeden do liczby, a i tak już ją wystarczająco na około robimy, to skorzystajmy w końcu z faktu że jedyne co 
        // może być resztą to 1 i to tylko wtedy gdy przed dodaniem first->val == 9. 
        node * tmp = new node;
        tmp->val = 1;
        last->next = tmp;
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

    // Zadanie 4 (dodatkowe)
/*
    node * list = NULL, * list2 = NULL;
    for (int i = 0; i < 4; ++i)
        push_front(list, 9);

    push_front(list2, 1); push_front(list2, 9); push_front(list2, 8);

    print_list(list); print_list(list2);
    add_one(list); add_one(list2);
    print_list(list); print_list(list2);
*/
    return 0;
}
