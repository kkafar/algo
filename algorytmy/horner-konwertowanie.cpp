#include <iostream>
#include <string>
 
using namespace std;
 
 
int konwertuj_do_10(string liczba, int podstawa_systemu)
{
	int liczba_10, wspolczynnik;
 
	// przypadek gdy liczba[0] jest cyfra od 0 do 9
	if (liczba[0] > 47 && liczba[0] < 58)
		liczba_10 = (liczba[0] - 48);
 
	// skoro nie jest to cyfra to jest to litera, niepoprawnych wejsc nie sprawdzamy
	else
		liczba_10 = (liczba[0] - 55);
 
	for (int i = 1; i < liczba.length(); ++i)
	{
		if (liczba[i] > 47 && liczba[i] < 58)
			wspolczynnik = liczba[i] - 48;
 
		else
			wspolczynnik = liczba[i] - 55;
 
		liczba_10 = liczba_10 * podstawa_systemu + wspolczynnik;
	}
 
	return liczba_10;
}
 
int main()
{
	string liczba;
	int podstawa_systemu;
 
	cin >> liczba >> podstawa_systemu;
	cout << konwertuj_do_10(liczba, podstawa_systemu) << endl;
	return 0;
}
