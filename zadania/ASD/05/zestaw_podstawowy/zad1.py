# K. Kafara

# Problem sumy podzbioru


def solution_rec(A, i, s):
    """ Rozwiązanie rekurencyjne (czysto) """
    # print("f({},{})".format(i, s))
    if s == 0: return True
    if i < 0: return False
    elif s > 0:
        return (solution(A, i - 1, s) or solution(A, i - 1, s - A[i]))
    else: 
        return False
        

def solution_dp(A, T):
    """ Rozwiązanie dynamiczne """
    # Tworzymy dwuwymiarową tablicę i wypełniami wartościami 'None'
    f = []
    for i in range(len(A)):
        # T + 1, bo badamy sumy od 0 do T
        f.append([None] * (T + 1))
    
"""
    # DEBUG
    for i in range(len(A)):
        for j in range(T + 1):
            print(f[i][j], " ", end='')
        print("") 
"""
    """
        Ważna jest kolejność inicjalizowania tablicy. Gdyby najpierw uzupełniać
        pierwszą kolumnę, to potem najprawdopodobniej (w przypadku gdy A[0] != 0)
        wpisalibyśmy False do f[0][0] - a to nie jest prawda. Można też do tej jednej
        komórki wpisać osobno, albo zacząć uzupełniać pierwszy wiersz od kolumny
        z indeksem 1, a nie 0
    """
    for i in range(T + 1):
        if A[0] != i:
            f[0][i] = False
        else:
            f[0][i] = True

    for i in range(len(A)):
        f[i][0] = True
        
    for i in range(1, len(A)):
        for j in range(1, T + 1):
            if j - A[i] >= 0:
                f[i][j] = f[i - 1][j] or f[i - 1][j - A[i]]
            else:
                f[i][j] = f[i - 1][j]

    return f[len(A) - 1][T]
    

if __name__ == '__main__':
    A = [1, 2, 3, 4, 5]
    """ if solution(A, 4, 10) == True:
        print("TRUE")
    else:
        print("FALSE") """

    if solution_dp(A, 16) == True:
        print("TRUE")
    else:
        print("FALSE")
