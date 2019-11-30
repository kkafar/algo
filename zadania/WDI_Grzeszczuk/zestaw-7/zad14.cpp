// problem 8 hetmanów
/*
    T = trzymamy szachownicę 
    d1, d2 - oznaczają zajęte przeknątne (nie wystarczy jedna tablica???)
    i - liczba zaznaczonych pól
*/
/*
void hetman(int T[N], int d1[2*N -1], int d2[2*n -1], int i)
{
    if (i == N-1)
    {
        wpisz(wers;)
    }
    else
    {
        FORU(j, 0, N-1) // pętla lecąca po WIERSZACH
        {
            if (T[j] == 0 && d1[N - 1 - (i - j)] == 0 && d2[i+w] == 0) 
            {
                T[j] = i + 1;
                d1[N-1 - (i-j)]++;
                d2[i+j]++;
                hetman(T, d1, d2, i+1);
                T[j] = 0;
                d1[N-1 - (i-w)]--;
                d2[i+j]--; 
            }
        }
        // i jeszcze kupa kodu którego nie chciało mi się przepisać, zrób to sam, 
        // to z tablicy było mało przekonujące
    }

}
*/
