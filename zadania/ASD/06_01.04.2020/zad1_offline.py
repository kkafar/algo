# K. Kafara

def tasks(A):
    # sortujemy domyślnie po czasie rozpoczęcia
    A.sort()

    counter = 0
    
    print(A)
    while len(A) > 0:
        counter += 1
        print(A[len(A) - 1], counter)
        # przeglądamy wszystkie elementy poza ostatnim
        j = 0
        while j < len(A) - 1:
            # jeżeli czas końca j-tych zajęć jest większy niż czas rozpoczęcia zajęć 
            # które wzięliśmy do rozwiązania, to usuwamy j-te zajęcia
            print(j, len(A))
            print(A)
            if A[j][1] > A[len(A) - 1][0]:
                A.pop(j)
                # skoro usunęliśmy element, to tablica skraca się o 1 ==> element następny
                # przechodzi na miejsce elementu który właśnie usunęliśmy ==> zmniejszamy j o 1
                # aby w następnej iteracji znaleźć się na tym samym indeksie 
                j -= 1
            j += 1
        # usuwamy ostatni element 
        A.pop(len(A) - 1)

    return counter

if __name__ == '__main__':
    print( tasks([ (7, 23), (0,10), (10,20), (5,15) ]) )
    #print( tasks([(0, 8), (1, 3), (2, 5), (4, 6), (3, 10), (7, 11), (9, 13), (12, 14)]))
