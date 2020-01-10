/*
    By K. Kafara
    
    zestaw 9-10, zadania dodatkowe

19. Dana jestlista, który być może zakończona jest cyklem.
Napisać funkcję, która sprawdza ten fakt.    

*/

#include <iostream>


/// ============================================
/*
    Definicja węzła
*/
struct Element
{
    int val;
    Element * next;

    Element()
    {
        next = NULL;
    }
};

/* 
    Strukrutra listy
*/
struct List
{
    
    /// ============================================
    // POLA
    Element * first;
    Element * tmp; 
    /// ============================================

    /// ============================================
    /* 
        Metoda sprawdzająca czy w liście istnieje cykl
        Return value: 
        true - jeżeli cykl istnieje
        false - wpp
        Idea działania opisana w zeszycie. 
    */
    bool test_cycle();

    List()
    {
        first = tmp = NULL;
    }
    ~List()
    {
        std::cout << "Dekonstruktor został wywołany!\n";
        while (first != NULL)
        {
            tmp = first;
            first = first->next;
            delete tmp;
        }
        first = tmp = NULL;
    }

    
    /// ============================================

};

/// ============================================
/*
    Zadanie 19 (dodatkowe)
    Sprawdzanie czy podana lista zawiera cykl
*/
/// ============================================

bool List::test_cycle()
{
    if (first == NULL) return false;

    Element * s = first, * f = first; // startujemy z tego samego miejsca
    
    do
    {
        // najpierw ruch o jeden 
        f = f->next;
        s = s->next;
        // upewniamy się że nie ma "null strzałka", jeżeli nie to wykonujemy drugi ruch wskaźnikiem f
        if (f != NULL)
            f = f->next;
        
        else
            return false;
        
    } while (s != NULL && s != f);

    // po opuszczeniu pętli, albo s == NULL albo s == f
    if (s == NULL) return false;
    else return true;
}

/// ============================================

