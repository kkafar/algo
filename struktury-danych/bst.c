#include <stdio.h>
#include <stdlib.h>


/////////////////////////////////////////////////////////////////////////
void clear_buff(void)
{
    while ((getchar()) != '\n');
}
/////////////////////////////////////////////////////////////////////////
void str_cpy(char str1[], char * str2)
{
    while (*str2 != '\0')
    {
        *(str1) = *(str2++);
        str1++;
    }
    *str1 = '\0';
}
/////////////////////////////////////////////////////////////////////////
typedef struct BSTNode
{
    // student_id
    int key;
    // student_name
    char name[32];

    struct BSTNode * left, * right, * parent;
} bst_node;
/////////////////////////////////////////////////////////////////////////
bst_node * bst_node_getnew(void)
{
    return (bst_node *)(malloc(sizeof(bst_node)));
}
/////////////////////////////////////////////////////////////////////////
void bst_node_init(bst_node * node, const int key, char * name, bst_node * left, bst_node * right, bst_node * parent)
{
    node->key = key;
    node->left = left;
    node->right = right;
    node->parent = parent;
    // *(node->name + 31) = '\0';
    str_cpy(node->name, name);
}
/////////////////////////////////////////////////////////////////////////
void bst_node_delete(bst_node * node)
{
    // printf("%s: %d: bst_node_delete: info: %p\n", __FILE__, __LINE__, node);
    free(node);
}
/////////////////////////////////////////////////////////////////////////
typedef struct BST
{
    bst_node * root;
} bst;
/////////////////////////////////////////////////////////////////////////
void bst_init(bst * tree)
{
    tree->root = NULL;
}
/////////////////////////////////////////////////////////////////////////
char * bst_find(bst * tree, const int key)
{
    bst_node * node = tree->root;

    while (node != NULL)
    {
        if (node->key == key)
            return node->name;

        else if (key < node->key)
            node = node->left;

        else
            node = node->right;
    }

    return "NO";
}
/////////////////////////////////////////////////////////////////////////
void bst_insert(bst * tree, const int key, char * name)
{
    if (tree->root == NULL)
    {
        tree->root = bst_node_getnew();
        bst_node_init(tree->root, key, name, NULL,  NULL, NULL);
    }
    else
    {
        bst_node * tmp_root = tree->root;
        bst_node * tracker = NULL;
        while (tmp_root != NULL)
        {
            tracker = tmp_root;

            if (key < tmp_root->key)
                tmp_root = tmp_root->left;

            else if (key > tmp_root->key)
                tmp_root = tmp_root->right;

            else
            {
                str_cpy(tmp_root->name, name);
                return;
            }
        }

        if (key < tracker->key)
        {
            tracker->left = bst_node_getnew();
            bst_node_init(tracker->left, key, name, NULL, NULL, tracker);
        }
        else
        {
            tracker->right = bst_node_getnew();
            bst_node_init(tracker->right, key, name, NULL, NULL, tracker);
        }

    }
}
/////////////////////////////////////////////////////////////////////////
void __bst_remove(bst_node ** root, bst_node * node, const int key)
{
    // printf("%s: %d: __bst_remove: info: wyw. (%p, %p, %d)\n", __FILE__, __LINE__, node, *root, key);    
    // najpierw odnajdujemy węzeł przeznaczony do usunięcia
    while (node != NULL)
    {
        // printf("%s: %d: __bst_remove: info: m. %d\n", __FILE__, __LINE__,1);
        if (key < node->key)
        {
            node = node->left;
            // printf("%s: %d: __bst_remove: info: m. %d\n", __FILE__, __LINE__,2);
        }

        else if (key > node->key)
        {
            node = node->right;
            // printf("%s: %d: __bst_remove: info: m. %d\n",__FILE__, __LINE__, 3);
        }
        // jeżeli udało się znaleźć węzeł o podanym kluczu to musimy go usunąć
        else
        {
            // printf("%s: %d: __bst_remove: info: m. %d\n", __FILE__, __LINE__,4);
            // jeżeli odnaleziony węzeł nie ma dzieci
            if (node->left == NULL && node->right == NULL)
            {
                // printf("%s: %d: __bst_remove: info: m. %d\n",__FILE__, __LINE__, 5);
                // jeżeli usuwamy korzeń
                if (node == *root)
                {
                    bst_node_delete(node);
                    *root = NULL;
                    break;
                }
                // jeżeli usuwany węzeł jest lewym dzieckiem
                else if (node->parent->left == node)
                {
                    node->parent->left = NULL;
                    bst_node_delete(node);
                    break;
                }
                else
                {
                    node->parent->right = NULL;
                    bst_node_delete(node);
                    break;
                }
            }
            // jeżeli odnaleziony węzeł ma tylko lewe dziecko
            else if (node->left != NULL && node->right == NULL)
            {
                // printf("%s: %d: __bst_remove: info: m. %d\n",__FILE__, __LINE__, 6);
                // jeżeli usuwamy korzeń
                if (node == *root)
                {
                    *root = (*root)->left;
                    (*root)->parent = NULL;
                    node->left = NULL;
                    bst_node_delete(node);
                    break;

                }
                // jeżeli usuwany węzeł jest lewym dzieckiem
                else if (node->parent->left == node)
                {
                    node->left->parent = node->parent;
                    node->parent->left = node->left;
                    node->left = NULL;
                    bst_node_delete(node);
                    break;
                }
                //  jeżeli usuwany węzeł jest prawym dzieckiem
                else
                {
                    node->left->parent = node->parent;
                    node->parent->right = node->left;
                    node->left = NULL;
                    bst_node_delete(node);
                    break;
                }
            }
            // jeżei odnaleziony węzeł tylko prawe dziecko
            else if (node->left == NULL && node->right != NULL)
            {
                // printf("%s: %d: __bst_remove: info: m. %d\n", __FILE__, __LINE__, 7);
                // jeżeli usuwamy korzeń
                if (node == *root)
                {
                    *root = (*root)->right;
                    (*root)->parent = NULL;
                    node->right = NULL;
                    bst_node_delete(node);
                    break;
                }
                // jeżeli usuwany węzeł jest lewym dzieckiem
                else if (node->parent->left == node)
                {
                    node->right->parent = node->parent;
                    node->parent->left = node->right;
                    node->right = NULL;
                    bst_node_delete(node);
                    break;
                }
                // jeżeli usuwany węzeł jest prawym dzieckiem
                else
                {
                    node->right->parent = node->parent;
                    node->parent->right = node->right;
                    node->right = NULL;
                    bst_node_delete(node);
                    break;
                }
            }
            // jeżeli odnaleziony węzeł ma obydwoje dzieci
            else
            {
                // printf("%s: %d: __bst_remove: info: m. %d\n", __FILE__, __LINE__, 8);
                // musimy zacząć od odnalezienia następnika
                bst_node * succ = node->right;
                while (succ->left != NULL)
                    succ = succ->left;

                node->key = succ->key;
                str_cpy(node->name, succ->name);
                // następnik usuwamy
                __bst_remove(root, succ, succ->key);
                break;
            }

        }

    }

    // jeżeli nie udało się odnaleźć to nic się nie dzieje
}
/////////////////////////////////////////////////////////////////////////
void bst_remove(bst * tree, const int key)
{
    __bst_remove(&(tree->root), tree->root, key);
}
/////////////////////////////////////////////////////////////////////////
void __bst_delete(bst_node * node)
{
    if (node == NULL) return;
    else
    {
        __bst_delete(node->left);
        __bst_delete(node->right);
    }
    bst_node_delete(node);
}
/////////////////////////////////////////////////////////////////////////
void bst_delete(bst * tree)
{
    if (tree->root == NULL) return;
    else
        __bst_delete(tree->root);
}
/////////////////////////////////////////////////////////////////////////
void __bst_print(bst_node * node)
{
    if (node == NULL) return;
    else
    {
        printf("(addres=%p, key=%d, name=%s, parent=%p)\n", node, node->key,  node->name, node->parent);
        __bst_print(node->left);
        __bst_print(node->right);
    }
}
/////////////////////////////////////////////////////////////////////////
void bst_print(bst * tree)
{
    __bst_print(tree->root);
}
/////////////////////////////////////////////////////////////////////////





int main(void)
{
    int a, r, f;
    int student_id;
    char student_name[32];

    bst tree;
    bst_init(&tree);

    scanf("%d %d %d", &a, &r, &f);
    clear_buff();

    for (int i = 0; i < a; ++i)
    {
        // printf("%d Prosze podac (student_id, student_name): ", i);
        scanf("%d %s", &student_id, student_name);
        bst_insert(&tree, student_id, student_name);
    }

    // bst_print(&tree);

    for (int i = 0; i < r; ++i)
    {
        scanf("%d",  &student_id);
        bst_remove(&tree, student_id);
    }

    // bst_print(&tree);

    for (int i = 0; i < f; ++i)
    {
        scanf("%d", &student_id);
        printf("%s\n", bst_find(&tree, student_id));
    }
    
    bst_delete(&tree);
    return 0;
}
