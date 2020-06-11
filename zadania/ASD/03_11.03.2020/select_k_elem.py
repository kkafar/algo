# K. Kafara

from random import random 

def partition(A, p, q):
    s = A[q]
    i = p - 1

    for j in range(p, q):
        if A[j] <= s:
            i += 1
            A[j], A[i] = A[i], A[j]
        
    A[i + 1], A[q] = A[q], A[i + 1]

    return i + 1

def select(A, k, p, q):
    if p == q: return A[q]

    s = partition(A, p, q)

    i = s - p + 1

    if k == i:
        return A[q]

    elif k < i: 
        return select(A, k, p, s - 1)

    else: 
        return select(A, k - i, s + 1, q)



if __name__ == '__main__':
    A = [int(random() * 100) for i in range(10)]
    print(sorted(A))
    print(select(A, 3, 0, len(A) - 1))
