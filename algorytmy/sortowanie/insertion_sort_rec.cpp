/*
    By K. Kafara
*/
    
#include <iostream>
#include "/home/kkafara/workspace/include/my-utility.h"

void insertion_sort_rec(int * A, int n)
{
	if (n > 2)
		insertion_sort(A, n-1);
	// Here we assume that array A[0…n-2] is sorted
	// we make from n index of the last element in A
	--n;
	register int key = A[n];
	while (n > 0 && key < A[n-1])
	{
		A[n] = A[n-1];
		--n;
	}
	A[n] = key;
}
int main()
{
	int A[] = {7, 6, 5, 4, 3, 2, 1};
	__print_array(A, 7);
	insertion_sort(A, 7);
	__print_array(A, 7);
    return 0;
}
