/*
	Pomiar czasu wykonywania się algorytmu
*/

#include <iostream>
#include <time.h> // do funkcji clock(), zmiennej czasowej clock_t, CLOCKS_PER_SEC
using namespace std; 

int main()
{
	/* REZERWACJA ZMIENNYCH */
	/// =========================
	// zmienne czasowe
	clock_t t1, t2; 
	// zmienna pomocnicza a, po prostu, żeby wykonywać jakieś operacje
	// dt to "delta" czasu
	double a, dt;
	/// =========================

	/* MIERZYMY CZAS */ 
	/// =========================
	// pobieramy liczbę "clock ticks" procesora od początku działania programu
	t1 = clock();
	cout << "t1: " << t1 << "\n";

	// wykonujemy jakieś tam operacje
	for (int i = 0; i < 1000000000; ++i)
	{
		a = 3; a++;
	}

	// pobieramy liczbę "clock ticks" procesora od początku działania programu 
	t2 = clock();
	cout << "t2: " << t2 << "\n";

	// liczymy różnicę  t2 - t1, pamiętamy że jest ona wyrażona w clock_ticks, więc trzeba 
	// ją podzielić przez liczbę clock_ticks na sekundę żeby otrzymać czas w sekundach. 
	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;  
	cout << "dt: " << dt << "\n";
	/// =========================

	return 0;
}
