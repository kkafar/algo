#include <iostream>
#include <stdio.h>

#include "/home/kkafara/workspace/include/my-utility.h"
using namespace std;

const int SIZE = 8;

void sumuj_wiersze(int ** arr, int size)
{
	// TO DO
	return;
}

void write_tab(int ** arr, int col, int row)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			cout <<  &arr[i][j] << " " << arr[i][j] << " ";
		cout << "\n";
	}
}


int main()
{
	int ** arr = new int * [SIZE];

	for (int i = 0; i < SIZE; ++i)
		arr[i] = new int [SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
			arr[i][j] = i + j;
	}
/*
	for (int * i = arr[0]; i < arr[0] + SIZE * SIZE; ++i)
	{
		cout << i << "  " << *i << "\n";
	}
*/
	write_tab(arr, SIZE, SIZE);

	cout << "\n\n" << &arr << "  <-- adres pod ktorym znajduje sie wskaznik na tablice 2d\n";
	cout << arr << "  <-- adres na ktory wskazuje wskaznik na tablice 2d\n";
	cout << *arr << "  <-- to powinien być adres elementu arr[0][0]\n\n";

	for (int i = 0; i < SIZE; ++i)
		cout << arr[i] << "  <-- adres pod ktorym znajduje sie 1. el. wiersza " << i << "\n" 
		<< (arr + i) << "  <-- adres pod ktorym znajduje sie wskaznik na 1. el. wiersza " << i << "\n" 
		<< &arr[i] << "  <-- adres pod ktorym znajduje sie wskaznik na 1. el. wiersza " << i << "\n\n";

	// wypisywanie tablicy 2d wskaznikami
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
			printf("%-3d ", *(*(arr + i) + j));
		printf("\n");
	}
	
	return 0; 
}
