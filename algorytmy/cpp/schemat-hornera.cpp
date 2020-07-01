#include <iostream>
#include <math.h>
 
using namespace std;
 
double schemat_hornera_iter(double A[], double x_0, unsigned int numer_wspolczynnika)
{
	double wartosc_wielomianu = A[0];
 
	for (int i = 1; i <= numer_wspolczynnika; ++i)
		wartosc_wielomianu = wartosc_wielomianu * x_0 + A[i];
 
	return wartosc_wielomianu;
}
 
double schemat_hornera_rek(double A[], double x_0, unsigned int numer_wspolczynnika)
{
	if (numer_wspolczynnika == 0) 
		return A[0];				 // rozmiar_tablcy == 1 czyli stopien wielomianu == 0;
 
	else					  
		return (schemat_hornera_rek(A, x_0, numer_wspolczynnika - 1) * x_0 + A[numer_wspolczynnika]);
}
 
int main()
{
	int przypadki_testowe;
	unsigned int stopien_wielomianu;
	double * wspolczynniki, x_0;
 
	cin >> przypadki_testowe;
 
	for (int i = 0; i < przypadki_testowe; ++i)
	{
		cin >> stopien_wielomianu;
 
		wspolczynniki = new double[stopien_wielomianu + 1];
 
		for (int j = 0; j <= stopien_wielomianu; ++j)
			cin >> wspolczynniki[j];
 
		cin >> x_0;
 
		cout << "iteracyjnie: " << schemat_hornera_iter(wspolczynniki, x_0, stopien_wielomianu) << "  "
			<< "rekurencyjnie: " << schemat_hornera_rek(wspolczynniki, x_0, stopien_wielomianu) << endl;
 
 
 
		delete[] wspolczynniki;
	}
 
	return 0;
}
