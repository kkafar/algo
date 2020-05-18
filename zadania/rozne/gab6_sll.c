#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int key;
    struct ListNode * next; 
} lnode;

lnode * lnode_new()
{
    return (lnode *)(malloc(sizeof(lnode)));
}

void lnode_set(lnode * node, int val, lnode * nxt)
{
    node->key = val;
    node->next = nxt;
}

typedef struct SinglyLinkedList
{
    // wartownik
    lnode * snt;
} sll;

void sll_init(sll * list)
{
    list->snt = lnode_new();
    lnode_set(list->snt, 0, NULL);
}
void sll_push(sll * list, int key)
{
    lnode * new = lnode_new();
    lnode_set(new, key, list->snt->next);
    list->snt->next = new;
}


void sll_del(sll * list)
{
    lnode * tmp = list->snt;
    while (tmp != NULL)
    {
        list->snt = list->snt->next; 
        free(tmp);
        tmp = list->snt;
    }
}

void sll_print(sll * list)
{
    lnode * tmp = list->snt->next;
    while (tmp != NULL)
    {
        printf("%d ", tmp->key);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(void)
{   
    sll list;
    // trzeba za każdym razem, zanim zaczniemy korzystać zainicjować listę
    sll_init(&list);

    for (int i = 0; i < 10; ++i)
        sll_push(&list, i);

    sll_print(&list);

    sll_del(&list);

    return 0;
}
