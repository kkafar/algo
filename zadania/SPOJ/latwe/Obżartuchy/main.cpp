#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
    int doba = 86400;						        // sekund
    short t;                                        // liczba zestawow testowych
	cin >> t;
	short ileObz[t];								// liczba obzartuchow na zjezdzie
	int ileCiast[t];								// liczba ciastek w jednym pudelku
 
	for (int i = 0; i < t; ++i) {					// petla wykonujaca sie tyle razy ile jest zestawow testowych
		cin >> ileObz[i] >> ileCiast[i];
		int jakiCzas[ileObz[i]];
		double ciastka = 0.0;
 
		for (int j = 0; j < ileObz[i]; ++j) {			// zbiera czasy jedzenia dla kazdego obzartucha
			cin >> jakiCzas[j];
			ciastka =  ciastka + (doba / jakiCzas[j]);				// liczba ciastek, ktore zje obzartuch o indeksie [j] w ciagu doby
		}
		cout << ceil(ciastka / ileCiast[i]) << endl;
	}
    return 0;
}
 
