/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 101	//	100 chars + nullbyte


void encrypt(char* message) 
{
    char * ptrc = message;

    int leng = 0, code;
    
    while (*ptrc == ' ')
        ++ptrc;

    while 
    (
        ((*ptrc) >= 'a' && (*ptrc) <= 'z') 
        || 
        ((*ptrc) >= 'A' && (*ptrc) <= 'Z')
    )
    {
        ++ptrc;
        ++leng;
    }

    ptrc = message;

    while (ptrc < message + N)
    {
        if ((*ptrc) >= 'a' && (*ptrc) <= 'z')
        {
            code = ((int)(*ptrc) + leng - 97) % 26 + 97;
            (*ptrc) = (char)(code);
        }

        if ((*ptrc) >= 'A' && (*ptrc) <= 'Z')
        {
            code = ((int)(*ptrc) + leng - 65) % 26 + 65;
            (*ptrc) = (char)(code);
        }
        ++ptrc;
    }
}

int main(void)
{
	char message[N];

	fgets(message, N, stdin);
	
    encrypt(message);
    	
    printf("%s\n", message);

    return 0;
}   

