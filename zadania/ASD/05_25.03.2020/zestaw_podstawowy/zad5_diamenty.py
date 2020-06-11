# K. Kafara

# z5c5 - zadanie ala 'Diamenty'

def solution( A ):
    
    n = len( A )
    # obliczamy sobie najpierw poprawne wartośći dla pierwszego wiersza
    # i pierwszej kolumny
    for i in range(1, n):
        A[0][i] += A[0][i - 1]
        A[i][0] += A[i - 1][0]

    # właściwy algorytm. Uzupełniamy tablicę wiersz po wierszu
    for i in range(1, n, 1): 
        for j in range(1, n, 1):
            if A[i - 1][j] < A[i][j - 1]:
                A[i][j] = A[i - 1][j] + A[i][j]
            
            else:
                A[i][j] = A[i][j - 1] + A[i][j]
    
    return A[n - 1][n - 1]


if __name__ == '__main__':
    A = [ \
        [1, 2, 3, 4],\
        [5, 5, 6, 7],\
        [0, 0, 3, 1],\
        [1, 7, 2, 0]\
        ]
    for i in range(4):
        for j in range(4):
            print(A[i][j], end = " ")
        print("")

    print( solution( A ) )
