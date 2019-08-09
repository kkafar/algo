// https://pl.spoj.com/problems/FLAMASTE/
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    int *t = new int, *counter = new int, *leng = new int;
    string line;
 
    cin >> *t;
    for (int  i = 0; i <= *t; ++i) {     // for unknown reasons the loop is executed only (*t-1) times? why?!?!?!?
      getline(cin, line);
      *counter = 1;
      *leng = line.length();
 
      for (int j = 1; j <= *leng; ++j) {
        if (j == *leng) {
            if (*counter > 2) {
                cout << line[j-1] << *counter;
                *counter = 1;
            }
            else {
                for (int k = 0; k < *counter; ++k) {
                    cout << line[j-1];
                }
                *counter = 1;
            }
            break;
        }
 
        if (line[j] == line[j-1])
            ++(*counter);
 
        else {
            if (*counter > 2) {
                cout << line[j-1] << *counter;
                *counter = 1;
            }
            else {
                for (int k = 0; k < *counter; ++k) {
                    cout << line[j-1];
                }
                *counter = 1;
            }
        }
      }
 
      cout << endl;
    }
 
    delete leng;
    delete counter;
    delete t;
    return 0;
}
