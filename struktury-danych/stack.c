#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    char key;
    struct Node * next;
};

struct Stack 
{
    struct Node * top;
    int size;
};

struct Node * NewNode(void)
{
    return ((struct Node *) malloc(sizeof(struct Node)));
}
void InitNode(struct Node * node)
{
    node->next = NULL;
}

void InitStack(struct Stack * stc)
{
    stc->top = NewNode();
    stc->top->next = NULL;
    stc->size = 0;
}

struct Node * GetTop(struct Stack * stc)
{
    return stc->top;
}

void AddNode(struct Stack * stc, char val)
{
    struct Node * new = NewNode();
    InitNode(new);

    new->key = val;
    new->next = stc->top;
    stc->top = new;

    ++(stc->size);
}

char PopNode(struct Stack * stc)
{
    char ret_val = stc->top->key;
    struct Node * tmp = stc->top;
    stc->top = stc->top->next;
    free(tmp);
    --(stc->size);

    return ret_val;
}

void DeleteStack(struct Stack * stc)
{
    if (stc != NULL)
    {
        struct Node * ptr = stc->top;
        struct Node * aux_ptr;
        while (ptr != NULL)
        {
            aux_ptr = ptr;
            ptr = ptr->next;
            free(aux_ptr);
        }
        // free(stc);
    }
}

int GetSize(struct Stack * stc)
{
    return stc->size;
}

void PrintStack(struct Stack * stc)
{
    if (stc->size == 0)
    {
        printf("Stack is empty!\n");
        return;
    }

    for (struct Node * ptr = stc->top; ptr != NULL; ptr = ptr->next)
        printf("%c ", ptr->key);

    printf("\n");
}

int main(void)
{
    struct Stack stc;
    InitStack(&stc);

    AddNode(&stc, 'c');

    PrintStack(&stc);
    printf("%d\n", stc.size);

    PopNode(&stc);

    PrintStack(&stc);
    printf("%d\n", stc.size);

    DeleteStack(&stc);
    return 0;
}
