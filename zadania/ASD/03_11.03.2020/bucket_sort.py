# K. Kafara

# Przydałaby się tutaj własna lista. Jest na githubie w folderze my-projects/struktury-danych

from random import random 


def bucket_sort(A):
    n = len(A)

    buckets = [[] for i in range(n)]

    for i in range(n):
        buckets[int(A[i] * n)].append(A[i])

    for i in range(n):
        buckets[i].sort()

    res = []
    for i in range(n):
        res.extend(buckets[i])
    
    return res

if __name__ == '__main__':
    arr = [random() for i in range(10)]
    print(arr)
    sorted_arr = bucket_sort(arr)
    print(sorted_arr)
