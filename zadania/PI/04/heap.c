/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>

void IntSwap(int * a, int * b)
{
    int c = *b; 
    *b = *a; 
    *a = c;
}

void MaxHeapify(int * A, int root, size_t size)
{
    int left = 2 * root, right = left + 1;
    int max = root;

    if (left <= size && A[left] > A[max])
        max = left;
    
    if (right <= size && A[right] > A[max])
        max = right;

    if (max != root)
    {
        IntSwap(A + max, A + root);
        MaxHeapify(A, max, size);
    }
}

void BuildHeap(int * A, size_t size)
{
    for (int i = size / 2; i >= 1; --i)
        MaxHeapify(A, i, size);
}

void HeapSort(int * A, size_t size)
{
    for (int i = size; i >= 2; --i)
    {
        IntSwap(A + 1, A + i);
        MaxHeapify(A, 1, i - 1);
    }
}


int main(void)
{
    int z, n; 

    scanf("%d", &z);

    for (int i = 0; i < z; ++i)
    {
        scanf("%d", &n);

        int A[n + 1];

        for(int j = 1; j <= n; ++j)
            scanf("%d", A + j);

        BuildHeap(A, n);

        HeapSort(A, n);
        
        for (int i = 1; i <= n; ++i)
            printf("%d\n", A[i]);
    }

    return 0;
}
