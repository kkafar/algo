#include <iostream>
#include <string>
using namespace std;
 
bool checkIfPalindrome(int number)
{
    string sNumber = to_string(number);
    if (sNumber[0] == sNumber[sNumber.length()-1])
        return true;
 
    return false;
}
 
void addReversedNumber(int *number)
{
    int reversedNumber = 0, remainder, copyOfNumber = *number;
    while (copyOfNumber != 0)
    {
        remainder = copyOfNumber % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        copyOfNumber /= 10;
    }
 
    *number += reversedNumber;
 
    return;
}
 
int main()
{
    // variable section
    short tests;
    int number, counter;
    bool palindrome;
    //---------------
 
    cin >> tests;
    for (int i = 0; i < tests; ++i)
    {
        // zeroing section
        palindrome = false;
        counter = 0;
        //------------------
 
        cin >> number;
 
        palindrome = checkIfPalindrome(number);
 
        while (palindrome == false)
        {
            addReversedNumber(&number);
            palindrome = checkIfPalindrome(number);
            ++counter;
        }
 
        cout << number << " " << counter << endl;
 
    }
    return 0;
}
