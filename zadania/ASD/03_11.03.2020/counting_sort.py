from random import random


def counting_sort(A, k):
    B = [0] * k
    
    # zliczanie elementow o poszczegolnych kluczach
    for i in range(0, len(A)):
        #print(A[i])
        B[A[i]] += 1

    # B[i] po tej petli: ilosc elementow o kluczu ≤ i 
    for i in range(1, k):
        B[i] += B[i - 1]
    
    C = [0] * len(A)
    for i in range(len(A) - 1, -1, -1):
        C[B[A[i]] - 1] = A[i]
        B[A[i]] -= 1

    return C 
    

if __name__ == "__main__":
    A = [int(random() * 100) for i in range(10)]
    print(A)
    print(sorted(A))
    print(max(A))
    sorted_arr = counting_sort(A, max(A) + 1)
    print(sorted_arr)

