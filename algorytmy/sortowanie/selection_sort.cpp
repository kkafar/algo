void selection_sort(int * A, const int size)
{
	register int min_val_idx;
	int buffer;
	for (int i = 0; i < size; ++i)
	{
		min_val_idx = i;
		
		for (int j = i + 1; j < size; ++j)
			if (A[j] < A[min_val_idx]) min_val_idx = j;

		buffer = A[i];
		A[i] = A[min_val_idx];
		A[min_val_idx] = buffer;
	}
}


int main()
{
	int A[] = {7, 6, 5, 4, 3, 2, 1};
	__print_array(A, 7);
	selection_sort(A, 7);
	__print_array(A, 7);
    return 0;
}
