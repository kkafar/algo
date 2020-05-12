/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////
/// Węzeł listy
///////////////////////////////////////////////////////////////////////
typedef struct Node
{
    char * name, * number;
    struct Node * next;
} Node;
///////////////////////////////////////////////////////////////////////
/// Obsługa węzła
///////////////////////////////////////////////////////////////////////
Node * get_new_node(char * name, char * number, Node * next)
{
    Node * new_node = (Node *) malloc(sizeof(Node));
    new_node->name = name;
    new_node->number = number;
    new_node->next = next;
    return new_node;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
/// Lista jednokierunkowa
///////////////////////////////////////////////////////////////////////
typedef struct SinglyLinkedList
{
    // wartownik
    Node * snt;
} sl_list;
///////////////////////////////////////////////////////////////////////
/// Obsługa listy
///////////////////////////////////////////////////////////////////////
void init_list(sl_list * list)
{
    list->snt = get_new_node("SNT", "NULL", NULL);
}
///////////////////////////////////////////////////////////////////////
void push_front(sl_list * list, char * name, char * number)
{
    Node * new_node = get_new_node(name, number, list->snt->next);
    list->snt->next = new_node;
}
///////////////////////////////////////////////////////////////////////
void delete_list(sl_list * list)
{
    Node * tmp;
    while (list->snt != NULL)
    {
        tmp = list->snt;
        list->snt = list->snt->next;
        free(tmp);
    }
}
///////////////////////////////////////////////////////////////////////
int delete_node(sl_list * list, char * name)
{
    Node * tmp = list->snt->next, * tracker = list->snt;
    while (tmp != NULL)
    {
        if (tmp->name == name)
        {
            tracker->next = tmp->next;
            free(tmp);
            return 0;
        }
        tracker = tmp;
        tmp = tmp->next;
    }
    // Nie znaleziono takiego elementu
    return 1;
}
///////////////////////////////////////////////////////////////////////
char * get_number(sl_list * list, char * name)
{
    Node * tmp = list->snt->next;
    while (tmp != NULL)
    {
        if (tmp->name == name)
        {
            return tmp->number;
        }
        tmp = tmp->next;
    }
    return (char *)(NULL);
}
///////////////////////////////////////////////////////////////////////
void print_list(sl_list * list)
{
    printf("List starting at %p\n", list->snt->next);
    Node * tmp = list->snt->next;
    while (tmp != NULL)
    {
        printf("(%s, %s) ", tmp->name, tmp->number);
        tmp = tmp->next;
    }
    printf("\n");
}
