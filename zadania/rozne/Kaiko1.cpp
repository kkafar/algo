/*
    By K. Kafara 
*/

#include <iostream> 
#include "libs/macros.h"
#include <string>
#include <vector>
using namespace std;

/* 
    Wyświetalnie tablicy dowolnego typu. 
    Wyświetla wszystkie elementy tablicy w jednej lini, następnie wypisuje znak nowej lini
*/
template<typename Type>
void PrintTab(Type * tab, const int size)
{
    foru(i, size)
        cout << tab[i] << " ";
    
    cout << "\n";
}
template<typename Type>
void InitTab(Type * tab, const int size, Type init_value = 0)
{
    foru(i, size)
        tab[i] = init_value;
}

string AddNumbers(const string & str1, const string & str2)
{
    // najpierw bym sobie wsadził te liczby to tablicyi z intami, żeby się łatwiej dodawało po prostu
    int str1_leng = str1.length(), str2_leng = str2.length();
    int numb1[str1_leng],  numb2[str2_leng];
    // przy okazji przepisywania obracamy! 
    for (int i = str1_leng - 1; i >= 0; --i)
        numb1[i] = str1[str1_leng - 1 - i] - 48;
    
    for (int i = str2_leng - 1; i >= 0; --i)
        numb2[i] = str2[str2_leng - 1 - i] - 48;
    /*
        DEBUG
    PrintTab(numb1, str1_leng);
    PrintTab(numb2, str2_leng);
    */

    // przeniesienie, tak jak w dodawaniu pisemnym. Inicjujemy zerem, bo w pierwszej iteracji przecież
    // nie ma żanego przeniesienia
    int overflow = 0, iterator = 0;
    vector<int> result;
    while (iterator < str1_leng && iterator < str2_leng)
    {
        overflow += numb1[iterator] + numb2[iterator];
        result.push_back(overflow % 10);
        overflow /= 10;
        ++iterator;
    }
    while (iterator < str1_leng)
    {
        overflow += numb1[iterator];
        result.push_back(overflow % 10);
        overflow /= 10;
        ++iterator;
    }
    while (iterator < str2_leng)
    {
        overflow += numb2[iterator];
        result.push_back(overflow % 10);
        overflow /= 10;
        ++iterator;
    }
    string return_value = "";
    for (int i = 0; i < result.size(); ++i)
    {
        return_value += (char)(result[result.size() - i - 1] + 48);
    }
    return return_value;
}

int main()
{
    string s1 = "1234", s2 = "5678";
    cout << AddNumbers(s1, s2) << "\n";
    return 0;
}
