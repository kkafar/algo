
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct snode
{
    int value;
    struct snode *next;
    struct snode *the_same;
} snode;
typedef struct skiplist
{
    int level;
    struct snode *header;
} skiplist;
int *get_rand_arr(int max_level,int num_of_num)
{
    srand(time(NULL));
    int *arr=(int*)malloc(num_of_num*sizeof(int));
    for(int i = 0; i < num_of_num; i++)
    {
        int result2 =rand()%(max_level-1);
        arr[i]=result2+1;
    }
    return arr;
}
skiplist *skiplist_init(int level)
{
 
    skiplist *nowy = (skiplist*)malloc(sizeof(skiplist));
    nowy->level=level;
    nowy->header=NULL;
 
    snode *connect;
    snode *prev=NULL;
    for(int i=0;i<level;i++)
    {
        snode *header_stock = (snode*)malloc(sizeof(snode));
        header_stock->next=NULL;
        header_stock->value=-1;
        if(prev==NULL)
        {
            connect = header_stock;
            prev = header_stock;
        }
        else
        {
            prev->the_same = header_stock;
            prev = header_stock;
        }
 
        if(i==level-1)
        {
            header_stock->the_same=NULL;
        }
    }
    nowy->header=connect;
    return nowy;
}
void skiplist_insert(skiplist *lista,int val,int general_level)
{
    int max_level = (lista->level)-1;
    int curr_level=max_level;
    snode *curr = lista->header;
    while(curr_level!=general_level)
    {
        curr=curr->the_same;
        curr_level--;
    }
    curr=curr->the_same;
    snode *prev;
    prev=NULL;
    while(curr)
    {
        if(curr->next==NULL)
        {
            snode *new_tmp = (snode*)malloc(sizeof(snode));
            new_tmp->value=val;
            new_tmp->next=NULL;
            curr->next = new_tmp;
            curr=curr->the_same;
            if(prev==NULL)
            {
                prev=new_tmp;
            }
            else
            {
                prev->the_same = new_tmp;
                prev = new_tmp;
            }
        }
        else if(curr->next->value < val)
        {
            curr = curr->next;
        }
        else if(curr->next->value > val)
        {
            snode *new_tmp1 = (snode*)malloc(sizeof(snode));
            if(prev==NULL)
            {
                prev=new_tmp1;
            }
            else
            {
                prev->the_same = new_tmp1;
                prev = new_tmp1;
            }
            new_tmp1->next=curr->next;
            new_tmp1->value=val;
            curr->next=new_tmp1;
            curr=curr->the_same;
 
        }
        else if(curr->next->value==val)
        {
            continue;
        }
    }
    return;
}
void print_skiplist(skiplist *lista)
{
    printf("=============================================\n");
    snode *tmp=lista->header;
    while(tmp->the_same)
    {
        tmp = tmp->the_same;
    }
    tmp=tmp->next;
    while(tmp)
    {
        printf("%d -> ",tmp->value);
        tmp=tmp->next;
    }
    printf("\n=============================================\n");
}
snode* skiplist_find_key(skiplist* lista,int key)
{
    snode *prev;
    prev = rek(lista->header,key,&prev);
    return prev;
}
void rek(snode* node,int key,snode *result)
{
    if(node==NULL)
    {
        result = NULL;
        return;
    }
    else if(node->next==NULL)
    {
        rek(node->the_same,key,result);
    }
    else if(node->next->value==key)
    {
        result = node;
        return;
    }
    else if(node->next->value<key)
    {
        rek(node->next,key,result);
    }
    else if(node->next->value>key)
    {
        rek(node->the_same,key,result);
    }
}
void skiplist_remove_key(skiplist *lista,int key)
{
    snode* curr = skiplist_find_key(lista,key);
    snode* to_del;
    while(curr)
    {
        to_del = curr->next;
        curr->next=curr->next->next;
        free(to_del);
        curr=curr->the_same;
        while(curr != NULL && curr->next->value!=key)
        {
            curr=curr->next;
        }
    }
}
void skiplist_print_all(skiplist *lista,int a)
{
    snode *curr = lista->header;
    snode *magiczny = lista->header;
    snode *asystant;
    snode *tmp = lista->header;
    while(magiczny->the_same!=NULL)
    {
        magiczny=magiczny->the_same;
    }
    printf("====================================================\n");
    while(curr)
    {
        tmp = curr;
        asystant = magiczny;
        while(asystant!=NULL)
        {
            if(tmp!=NULL && asystant->value==tmp->value)
            {
                printf("--%d--",tmp->value);
                tmp=tmp->next;
            }
            else
            {
                printf("-----");
            }
            asystant=asystant->next;
        }
        printf("\n");
        curr=curr->the_same;
    }
 
}
void czyszczarka(snode *node)
{
    if(node!=NULL)
    {
        snode* prawo=node->next;
        snode* dol=node->the_same;
        free(node->next);
        free(node->the_same);
        free(node);
        czyszczarka(prawo);
        czyszczarka(dol);
    }
    return;
}
void skiplist_clear(skiplist* lista)
{
    czyszczarka(lista->header);
    return;
}
int main() {
    int Z=0;
    scanf("%d",&Z);
    for(int i=0;i<Z;i++)
    {
        int h=0,a=0,r=0,f=0;
        scanf("%d%d%d%d",&h,&a,&r,&f);
        int SKIPLIST_MAX_LEVEL=h+1;
        skiplist *lista = skiplist_init(SKIPLIST_MAX_LEVEL);
        int* arr = get_rand_arr(SKIPLIST_MAX_LEVEL,a);
        for(int j=0;j<a;j++)
        {
            int number=0;
            scanf("%d",&number);
            skiplist_insert(lista,number,arr[j]);
        }
        for(int j=0;j<r;j++)
        {
            int number=0;
            scanf("%d",&number);
            skiplist_remove_key(lista,number);
        }
        for(int j=0;j<f;j++)
        {
            int number=0;
            scanf("%d",&number);
            if(skiplist_find_key(lista,number)!=NULL)
            {
                printf("Y\n");
            }
            else
            {
                printf("N\n");
            }
        }
        free(arr);
        skiplist_clear(lista);
        free(lista);
    }
    return 0;
}
