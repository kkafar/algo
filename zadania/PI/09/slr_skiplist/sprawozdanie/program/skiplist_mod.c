#include "skiplist_mod.h"

/////////////////////////////////////////////////////////////////////////////
////* SKIPLISTA MODYFIKOWANA (2) */
/////////////////////////////////////////////////////////////////////////////
slm_node * slm_node_getnew(const int value, const int level)
{
    // sizeof ignoruje tablicę o nieustalonym rozmiarze ==> obliczamy jej rozmiar osobno, ale całość
    // rezerwujemy w jednym bloku
    slm_node * new_node = (slm_node *)(malloc(sizeof(slm_node) + level * sizeof(slm_node *)));
    new_node->value = value;
    new_node->level = level;
    return new_node;
}
/////////////////////////////////////////////////////////////////////////////
void slm_node_delete(slm_node * node)
{
    // tablicy forward nie musimy zwalniać oddzielnie, bo była rezerwowana w jednym bloku
    // free(node->forward);
    free(node);
}
/////////////////////////////////////////////////////////////////////////////
void slm_init(slm * slist, const int max_level)
{
    slist->max_level = max_level;
    slist->curr_level = 1;
    slist->head = slm_node_getnew(MINF, max_level);
    slist->tail = slm_node_getnew(INF, max_level);

    // ustawiamy wszystkie wskaźniki wartownika listy na element końca listy
    for (slm_node ** i = slist->head->forward; i < slist->head->forward + max_level; ++i)
        *i = slist->tail;
}
/////////////////////////////////////////////////////////////////////////////
void slm_delete(slm * slist)
{
    // przechodzimy po najniższym poziomie listy
    slm_node * tmp = (*(slist->head->forward)), * tmp2; 

    while (tmp != slist->tail)
    {
        tmp2 = tmp;
        tmp = *(tmp->forward);
        slm_node_delete(tmp2);
    }    
    slm_node_delete(slist->tail);
    slm_node_delete(slist->head);
}
/////////////////////////////////////////////////////////////////////////////
int slm_find(slm * slist, const int value)
{
    slm_node * x = slist->head;

    for (int i = slist->curr_level - 1; i >= 0; --i)
    {
        // jeżeli 'nie patrzymy za daleko'
        while ( (*(x->forward + i))->value < value )
            x = *(x->forward + i);
    }
    
    x = *(x->forward);
    
    if (x->value == value)  return 1;   // sukces
    else                    return 0;  
}  
/////////////////////////////////////////////////////////////////////////////
void slm_insert(slm * slist, const int value)
{
    slm_node * x = slist->head;

    slm_node * update[slist->max_level];

    for (slm_node ** i = update; i < update + slist->max_level; ++i)
        *i = NULL;
    
    for (int i = slist->curr_level - 1; i >= 0; --i)
    {
        // jeżeli 'nie patrzymy za daleko'
        while ( (*(x->forward + i))->value < value )
            x = *(x->forward + i);

        *(update + i) = x;
    }
    
    x = *(x->forward);
    
    // if (x->value == value)  return;

    // losujemy poziom nowego węzła
    int level = getlevel(slist->max_level);

    // printf("WYLOSOWANO LVL: %d\n", level); 
    if (level > slist->curr_level)
    {
        for (int i = slist->curr_level; i < level; ++i)
            (*(update + i)) = slist->head;

        slist->curr_level = level;
    }

    x = slm_node_getnew(value, level);

    for (int i = 0; i < level; ++i)
    {
        // x->forward[i] = update[i]->forward[i];
        // update[i]->forward[i] = x;
        *(x->forward + i) = *((*(update + i))->forward + i);
        *((*(update + i))->forward + i) = x;
    }        
    
}
/////////////////////////////////////////////////////////////////////////////
void slm_remove(slm * slist, const int value)
{
    slm_node * x = slist->head;
    // printf("sl_remove: %d\n", 1);
    slm_node * update[slist->max_level];

    for (slm_node ** i = update; i < update + slist->max_level; ++i)
        *i = NULL;
    
    for (int i = slist->curr_level - 1; i >= 0; --i)
    {
        // jeżeli 'nie patrzymy za daleko'
        while ( (*(x->forward + i))->value < value )
            x = *(x->forward + i);

        *(update + i) = x;
    }
    // printf("sl_remove: %d\n", 2);
    x = *(x->forward);

    if (x->value == value)
    {
        for (int i = 0; i < slist->curr_level; ++i)
        {
            if (*((*(update + i))->forward + i) != x) break;

            *((*(update + i))->forward + i) = *(x->forward + i);
        }
        // printf("sl_remove: %d\n", 3);
        // Nie ma potrzeby osobnego usuwania tablicy forward, bo była rezerwowana wraz z całym węzłem
        // free(x->forward);
        free(x);
        // printf("sl_remove: %d\n", 4);
        // jeżeli usunęliśmy element o najwięskszym poziomie, to odpowiednio obniżamy poziom listy
        while ((slist->curr_level > 1) && ((*(slist->head->forward + slist->curr_level - 1)) == slist->tail))
        {
            --(slist->curr_level);
        }
        // printf("sl_remove: %d\n", 5);
    }
}
/////////////////////////////////////////////////////////////////////////////
void slm_print(slm * slist)
{
    slm_node * iter = slist->head;
    while (iter != slist->tail)
    {
        printf("(val=%d, lvl=%d)  ", iter->value, iter->level);
        iter = *(iter->forward);
    }
    printf("\n");
}   
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/// END
/////////////////////////////////////////////////////////////////////////////